#pragma once
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
				return; // 부모가 합쳐져있어서 무시


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

