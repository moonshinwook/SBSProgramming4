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

// MST
// 최소 스패닝 트리 : 그래프 BFS, DFS -> 
// Q? 정점	간선 . 정점들 사이에 최소의 간선 수로 연결을 하는 방법. 최소 비용
// 
// 도시 [회사] -도로- [빌딩] []

// 크루스칼 : 그리드 + 순회가 발생할 때 어떻게 해결 해야하나?
// Union 합치다. 
// Find  찾다.

// 2개의 서로 다른 팀 존재. 권한. 동맹 시스템.
// 10팀.

void TeamSolution()
{
	struct User
	{
		int teamId;
	};

	vector<User> users;
	users.resize(10);
	for (int i = 0; i < 10; i++)
		users[i].teamId = i;

	// Team0 <-> Team1
	// 0팀으로 합치겠다. 
	users[1].teamId = 0;

	// Find  : O(1) 
	// union : O(n)
	for (auto& user : users)
	{
		if (user.teamId == 1)
			users[1].teamId = 0;
	}
}

// 트리
// 계층이 있는(부모와 자식) 정점 간선



//  Union -> merge
//  Find  -> 

//  u, v, w 
//	O(1)

// 합치는 것을 배움. -> MST - 크루스칼, 프림 = disjoint set 방식을 써서(union find) cycle 발생했을 때 

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

int main()
{
	TeamSolution();

	Disjoint teams(1000);

	teams.Merge(0, 1);

	int teamId = teams.Find(0);
	int teamId2 = teams.Find(1);

	if (teamId == teamId2)
		cout << "0, 1 팀을 맺었다.";
}