#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 자료구조 (선형) 

// [] [] [] [] [] [] 
// 사이클을 표현할 수 있는 자료 표현법 - Graph
// 정점(Vertex) 간선(Edges) 데이터 표현 방식을 Graph라고 부르자.

// 1정점 2정점 서로를 가리키고 있다. 무방향 그래프
//									방향 그래프
// 간선 가중치 있는가 없는가? 
// cycle이 있는가 없는가? 

// 추상적인 개념을 컴퓨터에게 알아들을 수 있도록 정의 - class

// 1. Graph Create!

// 2. Graph Traverse(순회)
// -BFS, DFS

// 응용 미로 적용

struct Vertex
{
	vector<Vertex> edges;
};

// adjacent vector 인접한 벡터
// adjacnet Matrix 인접한 행렬 


vector<vector<int>> adjacent; // 이중 벡터 구조

void CreateGraph_vector()
{
	adjacent = vector<vector<int>>(8);

	vector<int> v = { 1, 2, 7 };

	adjacent[0] = { 1, 2, 7 };
	adjacent[1] = { 0, 5, 7 };
	adjacent[2] = { 0, 3, 4 };
	adjacent[3] = { 2, 4 };
	adjacent[4] = { 2, 3 };//3 4
	adjacent[5] = { 1, 6 };//2 7
	adjacent[6] = { 5 };
	adjacent[7] = { 0, 1 };

	// Q? A정점 B정점이랑 실제로 연결되어 있나요?
	vector<int>& adj = adjacent[0]; // 1번 정점 6이랑 연결되어 있는가?
	bool connect = (find(adj.begin(), adj.end(), 7) != adj.end());

}

vector<vector<bool>> adjacent2;


void CreateGraph_vector2()
{
	// 연결이 안되어 있을 때 숫자를 무엇으로 표현할래?		true 0
	// 연결이 되어 있을 때 어떤 숫자로 표현할 것인가?		false 1
	// bool
	adjacent2 = vector<vector<bool>>(8, vector<bool>(8, false));
	// [from][to]
	adjacent2[0][1] = true; // 1에 2, 3, 8이 연결되어 있다. 
	adjacent2[0][2] = true;
	adjacent2[0][7] = true; 
	adjacent2[1][0] = true; 
	adjacent2[1][5] = true; 
	adjacent2[2][0] = true; 
	adjacent2[2][3] = true; 
	adjacent2[2][4] = true; 
	adjacent2[3][2] = true; 
	adjacent2[3][4] = true; 
	adjacent2[4][2] = true; 
	adjacent2[4][3] = true; 
	adjacent2[4][3] = true; 
	adjacent2[4][3] = true; 
	adjacent2[4][3] = true; 
	adjacent2[4][3] = true; 

	bool connet = adjacent2[0][6];
	

}

vector<vector<int>> adjacent3;

void CreateGraph_Matrix()
{
	// 연결이 되어있다 1
	// 연결 x		 -1

	adjacent3 =
	{
		{-1, +1, +1, -1, -1, -1, -1, +1 }, // 0 정점
		{+1, -1, -1, -1, +1, -1, +1, +1 },
		{+1, -1, -1, +1, +1, -1, -1, -1 },
		{-1, -1, +1, -1, +1, -1, -1, -1 },
		{-1, -1, +1, +1, -1, -1, -1, -1 },
		{-1, +1, -1, -1, -1, -1, +1, -1 },
		{-1, -1, -1, -1, -1, +1, -1, -1 },
		{+1, +1, -1, -1, -1, -1, -1, -1 }
	};
}

// 그래프 생성
// 그래프 순회

// 
// DFS : Depth   First Search (깊이 우선 탐색)
// DBS : Beneath First Search (너비 우선 탐색)

// DFS - 재귀 함수  : 자기 자신을 호출하는 함수
// BFS - Queue 사용 : FIFO(선입선출)
 
vector<bool> visited(8, false);

// 1

// [2]
	// [6]
	  // [7] 
	// [8]
	   // [1] (방문? skip) 
	   // [2] skip
// [3]
    //[4]
      //[5]
    //[5]
// [8]

// 선 연결 유무 확인용으로 활용됌.
void DFS(int here)
{
	visited[here] = true;
	cout << "방문한 정점 :" << here + 1 << endl;

	for (int i = 0; i < adjacent[here].size(); i++)
	{
		int there = adjacent[here][i];
		if (visited[there] == false)
			DFS(there);
	}
}

void DFSmatrix(int here)
{
	visited[here] = true;
	cout << "방문한 정점 : " << here + 1 << endl;

	for (int there = 0; there < adjacent3[here].size(); there++)
	{
		if (adjacent3[here][there] == -1)		// 미연결 부분은 무시
			continue;

		if (visited[there] == false)
			DFSmatrix(there); // 재귀함수
	}
}

// queue	[1]	[2]	[3]	[8]	[6] [] 
//			[2] [3] [8]
// discover 발견했다.
// here = 2 [1] [6] [8 ]
void BFS(int here)
{
	vector<bool> discovered(8, false);
	vector<int> parent(8, -1);		// 현재 정점으로 가기 위한 직전의 정점
	vector<int> distance(8, -1);	// 시작 정점에서 해당 정점까지 가는 거리.

	queue<int> q;
	q.push(here);
	discovered[here] = true;
	parent[here] = here;		//  부모를 탐색했더니 내가 나왔네? 시작점.
	distance[here] = 0;			// distance = 0 ? 시작점. -1 ? 이 정점은 이동할 수 없는 정점입니다. 

	while (q.empty() == false)
	{
		int here = q.front();
		q.pop(); // front와 pop은 거의 같이 사용
		cout << "방문한 정점 : " << here + 1 << endl;
		for (int there : adjacent[here])	// for(int there = 0; adjacent[here].size(); ther++)
		{
			if (discovered[there])
				continue;

			q.push(there);
			discovered[there] = true;
			parent[there] = here;
			distance[there] = distance[here] + 1;
		}
	}

	// 미로 찾기. 목적지.
	// Q. 1 -> 7 가는 길을 알고 싶다. << 

	int dest = 6;
	vector<int> _path;
	while (true)
	{
		_path.push_back(dest);
		if (dest == parent[dest])
			break;
		dest = parent[dest];
	}

}

int main()
{
	CreateGraph_vector();
	CreateGraph_vector2();
	CreateGraph_Matrix();
	//DFS(0);
	//DFSmatrix(0);
	BFS(0);
}

	 
