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
#include <Windows.h>
#include <memory.h>

using namespace std;

class Disjoint
{
public:

	Disjoint(int n) : _parent(n), _rank(n, 1)
	{
		for (int i = 0; i < n; i++)
			_parent[i] = i;
	}

	int Find(int u)		// 나의 leader 찾는다. 
	{
		if (u == _parent[u])
			return u;

		Find(_parent[u]);
	}
	void Merge(int u, int v)		//
	{
		u = Find(u);
		v = Find(v);

		if (u == v)
			return;
		

		if (_rank[u] > _rank[v])
			swap(u, v);
	//		[A][A]		    [B]
	//		[a0][A]			[B0}
	//		[a1][a0]		[b1][b2]
	//		
		_parent[u] = v;
		if (_rank[u] == _rank[v])
			_rank[v]++;
	}

private:
	vector<int> _parent;
	vector<int> _rank;

};


vector<vector<int>> adjacent;

void CreateGraph()
{
	adjacent = vector<vector<int>>(7, vector<int>(7, -1));

	adjacent[0][1] = adjacent [1][0] = 67;
	adjacent[0][3] = adjacent [3][0] = 28;
	adjacent[0][4] = adjacent [4][0] = 17;
	adjacent[0][6] = adjacent [1][0] = 12;
	adjacent[1][3] = adjacent [3][1] = 24;
	adjacent[1][4] = adjacent [4][1] = 62;
	adjacent[2][4] = adjacent [4][2] = 20;
	adjacent[2][5] = adjacent [5][2] = 37;
	adjacent[3][6] = adjacent [6][3] = 13;
	adjacent[4][5] = adjacent [5][4] = 45;
	adjacent[4][6] = adjacent [6][4] = 28;
	
}

struct CostEdge
{
	int cost; 
	int u;
	int v;

	bool operator<(CostEdge& other)
	{
		return cost < other.cost;
	}
};

int Kruskal(vector<CostEdge>& select)  // 모든 간선을 최소의 갯수로 연결을 하고 그 비용이 최소가 되는 값 MST
{
	int ret = 0;

	select.clear();

	vector<CostEdge> edges;

	for (int u = 0; u < adjacent.size(); u++)
	{
		for (int v = 0; v < adjacent[u].size(); v++)
		{
			if (u > v)
				continue; // 하나만 처리 뒤집은 경우 같아서

			int cost = adjacent[u][v];
			if (cost == -1)
				continue;

			edges.push_back(CostEdge{ cost, u, v });

		}
	}

	sort(edges.begin(), edges.end());

	Disjoint sets(7);

	// u, v 어디에 저장했는가?
	// edge 타입 -> u, v 꺼내서 부모가 같냐? 아니냐? 

	for (auto& edge : edges)
	{
		if(sets.Find(edge.u) == sets.Find(edge.v)) // disjoint 덕분에 코드 개선
			continue;

		sets.Merge(edge.u, edge.v);
		select.push_back(edge);
		ret += edge.cost;	
	}

	return ret;
}


int main()
{
	CreateGraph();
	vector<CostEdge> select;
	int cost = Kruskal(select);

	cout << "MST : " << cost << endl;
}


// MST
// 싼 것들만 연결해서 그게 사이클이 안 생기면 되지 않을까?
// Greedy 탐욕법
// -> 현재 상황에서 최선의 케이스만 선택을 하면 답에 근접한다. 
// Disjoint set (서로소 집합) - 두 개의 집합을 합칠 때.. Find - Union(부모가 다르니까 합칠 수 있다)

// 프림 알고리즘
// 사이클 생기는 걸 판별 
// Cost 비용 계산.

// 도전과제
// Maze 프로젝트 적용