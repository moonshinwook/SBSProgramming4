#include "pch.h"
#include "Board.h"
#include "ConsoleHelper.h"
#include "Player.h"
#include <algorithm>
#include "Disjoint.h"
#include <map>
#include <queue>


Board::Board()
{
}

Board::~Board()
{
}

void Board::Init(int32 size, Player* player)
{
	_size = size;
	_player = player;
	_level++;
	GenerateMap();
}

void Board::InitMonster() {
	_monsters.clear();
	// 스테이지가 올라갈수록 몬스터 수 증가 (기본 1마리 + 스테이지당 1마리)
	int monsterCount = _stage;

	for (int i = 0; i < monsterCount; i++) {
		while (true) {
			int randY = rand() % _size;
			int randX = rand() % _size;

			// 빈 공간이고, 플레이어 위치가 아니며, 목적지도 아닌 곳에 배치
			if (GetTileType({ randY, randX }) == TileType::EMPTY &&
				_player->GetPos() != Pos{ randY, randX } &&
				GetEndPos() != Pos{ randY, randX })
			{
				_monsters.push_back(Monster{ {randY, randX} });
				break;
			}
		}
	}
}

void Board::NextStage() {
	_stage++;
	// 맵 재생성 로직 후 
	InitMonster();
}

void Board::Render()
{
	ConsoleHelper::SetCursorPos(0, 30);
	cout << "Level : " << _level << endl;

	ConsoleHelper::SetCursorPos(0, 0);
	ConsoleHelper::ShowConsoleCursor(false);

	// 시야 범위 설정 (예: N = 5)
	int viewRange = 5;
	Pos playerPos = _player->GetPos();

	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			Pos curPos = { y, x };

			// 맨해튼 거리(Manhattan Distance) 또는 체비쇼프 거리 계산
			// 여기서는 사각형 형태의 시야를 위해 체비쇼프 거리를 사용합니다.
			int distY = abs(playerPos.y - x);
			int distX = abs(playerPos.x - y);

			ConsoleColor color;
			// 시야 범위 N을 벗어나면 무조건 INVISIBLE 색상 적용
			if (distY > viewRange || distX > viewRange)
			{
				color = ConsoleColor::BLACK;
			}
			else
			{
				color = GetColorByTileType(curPos);
			}

			ConsoleHelper::SetCursorColor(color);
			cout << "●";
		}
		cout << endl;
	}
}


// maze for programmers
// binary Tree
void Board::GenerateMap()
{
	//BinaryTree();
	//BadMap();
	//Kruskal();
	Prim();
}

TileType Board::GetTileType(Pos pos)
{
	if (pos.x >= _size || pos.x < 0)
		return TileType::NONE;
	if (pos.y >= _size || pos.y < 0)
		return TileType::NONE;

	return _tile[pos.y][pos.x];
}

ConsoleColor Board::GetColorByTileType(Pos pos)
{
	// 플레이어의 좌표와 pos가 같다면 -> Player 클래스의 필요성. _pos
	if (_player->GetPos() == pos)
		return ConsoleColor::YELLOW;

	if (GetEndPos() == pos)
		return ConsoleColor::WHITE;

	for (auto& m : _monsters) {
		if (m.pos == pos) return ConsoleColor::MAGENTA; // 보라색
	}

	TileType tiletype = GetTileType(pos);

	switch (tiletype)
	{
	case TileType::EMPTY:
		return ConsoleColor::GREEN;
	case TileType::WALL:
		return ConsoleColor::RED;
	case TileType::INVISIBLE:
		return ConsoleColor::BLACK;
	default:
		return ConsoleColor::BLACK;

	}
}

void Board::BinaryTree()
{
	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			if (y % 2 == 0 || x % 2 == 0)
				_tile[y][x] = TileType::WALL;
			else
				_tile[y][x] = TileType::EMPTY;
		}

	}
	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			if (y % 2 == 0 || x % 2 == 0)
				continue;

			if (y == _size - 2 && x == _size - 2)
				continue;

			if (y == _size - 2)
			{
				_tile[y][x + 1] = TileType::EMPTY;
				continue;
			}
			if (x == _size - 2)
			{
				_tile[y + 1][x] = TileType::EMPTY;
				continue;
			}

			int randValue = rand() % 2;
			if (randValue == 0)
			{
				_tile[y][x + 1] = TileType::EMPTY;
			}
			else
			{
				_tile[y + 1][x] = TileType::EMPTY;
			}

		}

	}
}

void Board::BadMap()
{
	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			if (y == 1 || x == 1 || y == _size - 2 || x == _size - 2)
				_tile[y][x] = TileType::EMPTY;
			else if (y == _size / 2 || x == _size / 2)
				_tile[y][x] = TileType::EMPTY;
			else
				_tile[y][x] = TileType::WALL;

		}

	}
}

void Board::Kruskal()
{
	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			if (y % 2 == 0 || x % 2 == 0)
				_tile[y][x] = TileType::WALL;
			else
				_tile[y][x] = TileType::EMPTY;
		}
	}
	// TODO : 점과 점을 연결하는 (WALL) 간선. 비용. 랜덤 설정하겠다. 
	struct CostEdge
	{
		bool operator<(const CostEdge& other) { return cost < other.cost; }

		int cost;
		Pos u;
		Pos v;

	};

	vector<CostEdge> edges;

	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			if (y % 2 == 0 || x % 2 == 0)
				continue;

			// 오른쪽
			if (x < _size - 2)
			{
				int randValue = rand() % 100; // 코스트

				edges.push_back(CostEdge{ randValue, Pos{y, x}, Pos{y,x + 2} });
			}

			// 왼쪽(각각 따로 만들기 때문에 if)
			if (y < _size - 2)
			{
				int randValue = rand() % 100; // 코스트

				edges.push_back(CostEdge{ randValue, Pos{y + 2, x}, Pos{y,x} });
			}
		}
	}

	sort(edges.begin(), edges.end());

	Disjoint sets(_size * _size);

	// u, v => Pos데이터 파싱. disjoint int Pos => int 변환한다 Parse
	// 5, 5 => int ?
	// y의 값 곱하기 x 더하기 

	for (auto& edge : edges)
	{
		int u = edge.u.y * _size + edge.u.x;
		int v = edge.v.y * _size + edge.v.x;

		if (sets.Find(u) == sets.Find(v))
			continue;

		sets.Merge(u, v);
		// [u][walls][v]
		int y = (edge.u.y + edge.v.y) / 2;
		int x = (edge.u.x + edge.v.x) / 2;
		_tile[y][x] = TileType::EMPTY;
	}
}

void Board::Prim()
{
	struct CostEdge
	{
		bool operator<(const CostEdge& other) const
		{ 
			return cost < other.cost; 
		}

		int cost;
		Pos vertex;

	};

	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			if (y % 2 == 0 || x % 2 == 0)
				_tile[y][x] = TileType::WALL;
			else
				_tile[y][x] = TileType::EMPTY;
		}
	}

	// 다익스트라 비슷. 비용을 길마다 최적의 방법을 Best 저장.
	// map - 이진트리 균형잡힌 (레드블랙트리) 루트를 기준으로 왼쪽 오른쪽 비교

	map<Pos, vector<CostEdge>> edges;
	
	// Maze 랜덤하게 가중치를 만들어 준다. 
	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			if (y % 2 == 0 || x % 2 == 0)
				continue;

			// 오른쪽
			if (x < _size - 2)
			{
				int randValue = rand() % 100; // 코스트
				
				Pos u = Pos{ y, x };
				Pos v = Pos{ y, x + 2 };

				edges[u].push_back(CostEdge{ randValue, v });
				edges[v].push_back(CostEdge{ randValue, u });
			}

			// 왼쪽
			if (y < _size - 2)
			{
				int randValue = rand() % 100; // 코스트

				Pos u = Pos{ y, x };
				Pos v = Pos{ y + 2, x };

				edges[u].push_back(CostEdge{ randValue, v });
				edges[v].push_back(CostEdge{ randValue, u });
			}
		}
	}

	// Best

	map<Pos, bool> closed;
	map<Pos, Pos> parent;
	map<Pos, int> best;

	for (int y = 0; y < _size; y++)
	{
		for (int x = 0; x < _size; x++)
		{
			best[Pos{ y, x }] = INT32_MAX;
			closed[Pos{ y, x }] = false;
		}
	}

	priority_queue<CostEdge> pq;
	Pos startPos = Pos{ 1,1 };
	pq.push(CostEdge{ 0, startPos });
	parent[startPos] = startPos;
	best[startPos] = 0;

	while (pq.empty() == false)
	{
		CostEdge bestEdge = pq.top();
		pq.pop();

		Pos v = bestEdge.vertex;

		if (closed[v])
			continue;

		closed[v] = true;

		{
			int y = (parent[v].y + v.y) / 2;
			int x = (parent[v].x + v.x) / 2;
			_tile[y][x] = TileType::EMPTY;
		}

		for (CostEdge& edge : edges[v])
		{
			if (closed[edge.vertex])
				continue;

			if (edge.cost > best[edge.vertex])
				continue;

			//------------------------best 아니다. best 갱신
			best[edge.vertex] = edge.cost;
			parent[edge.vertex] = v;
			pq.push(edge);
		}
	}

}





// 미로 생성1) 테두리가 벽이고 안에는 전부 길인 맵.