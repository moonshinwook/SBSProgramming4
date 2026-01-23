#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
struct Vertex
{
	vector<Vertex> edges;
};

vector<vector<int>> adjacent;

void CreateGraph_vector()
{
	adjacent = vector<vector<int>>(8);

	vector<int> v = { 1, 2, 3 };

	adjacent[0] = { 1, 2, 3 };
	adjacent[1] = { 0, 4, 5 };
	adjacent[2] = { 0 };
	adjacent[3] = { 0 , 6 };
	adjacent[4] = { 1, 7 };
	adjacent[5] = { 1, 7 };
	adjacent[6] = { 3 };
	adjacent[7] = { 4, 5 };

	vector<int>& adj = adjacent[0];
	bool connect = (find(adj.begin(), adj.end(), 7) != adj.end());

}

vector<vector<bool>> adjacent2;

void CreateGraph_vector2()
{
	adjacent2 = vector<vector<bool>>(8, vector<bool>(8, false));

	adjacent2[0][1] = true;
	adjacent2[0][2] = true;
	adjacent2[0][3] = true;
	adjacent2[1][0] = true;
	adjacent2[1][4] = true;
	adjacent2[1][5] = true;
	adjacent2[2][0] = true;
	adjacent2[3][0] = true;
	adjacent2[3][6] = true;
	adjacent2[4][1] = true;
	adjacent2[4][7] = true;
	adjacent2[5][1] = true;
	adjacent2[5][7] = true;
	adjacent2[6][3] = true;
	adjacent2[7][4] = true;
	adjacent2[7][5] = true;

	bool connect = adjacent2[0][6];

}

vector<vector<int>> adjacent3;

void CreateGraph_Matrix()
{
	adjacent3 =
	{
		{ -1, +1, +1, +1, -1, -1, -1, -1 },
		{ +1, -1, -1, -1, +1, +1, -1, -1 },
		{ +1, -1, -1, -1, -1, -1, -1, -1 },
		{ +1, -1, -1, -1, -1, -1, +1, -1 },
		{ -1, +1, -1, -1, -1, -1, -1, +1 },
		{ -1, +1, -1, -1, -1, -1, -1, +1 },
		{ -1, -1, -1, +1, -1, -1, -1, -1 },
		{ -1, -1, -1, -1, +1, +1, -1, -1 },
	};

}

vector<bool> visited(8, false);

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

void DFS_MATRIX(int here)
{
	visited[here] = true;
	cout << "방문한 정점 :" << here + 1 << endl;

	for (int there = 0; there < adjacent3[here].size(); there++)
	{
		if (adjacent3[here][there] == -1)
			continue;

		if (visited[there] == false)
			DFS_MATRIX(there);
	}

}

int main()
{
	CreateGraph_vector();
	CreateGraph_vector2();
	CreateGraph_Matrix();
	DFS(0);
}