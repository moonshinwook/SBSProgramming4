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

// minDistance 구하는 방법
// n번 순회해서 제일 작은 값을 고른다.

// 데이터를 push할때도 시간이 발생.
// vector가장 큰 특징. push_back 매우 빠름 O(1)
// 최소 값 찾을려면 n번도 해야 한다 O(N)시간이 걸림.

int minDistance()
{
	vector<int> v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);

	int bestValue = INT32_MAX; // 값이 쌀수록 싸다.

	for (int i = 0; i < v.size(); i++)
	{
		if (bestValue < v[i])
			continue;

		// 아래쪽 내려왔다? 더 작은 값을 찾았구나
		bestValue = v[i];
				
	}

	cout << bestValue << endl;

	return bestValue;
}

// 우선 순위 큐
// 우선 순위가 높은 값부터 출력해주는 특별한 컨테이너.
// 값이 가장 큰 것을 위로, 값이 가장 작은 것을 위로

// 힙-트리
// 트리 << 

// priority_queue의 push O(log N)걸림, 계속 부모를 찾기 위해 /2를 실행. -> 매우 효율적
// top() O(1)걸림

template<typename T, typename Container = vector<T>> 

class Priority_queue
{
public:

	// left chilren
	// right children
	// parent

	void push(const T& value)
	{
		_heap.push_back(value);

		int now = static_cast<int>(_heap.size()) - 1;

		while (now > 0)
		{
			int parent = (now - 1) / 2;

			if (_heap[now] > _heap[parent]) // 부모한테 진 경우 무시.
				break; 

			// 부모를 이겼다. 나랑 바꿔
			::swap(_heap[parent], _heap[now]);
			now = parent;

			
		}
	}

	void pop()
	{
		_heap[0] = _heap.back();	// 왼쪽부터 채워나가기 규칙 지키기.
		_heap.pop_back();

		int now = 0;

		while (true)
		{
			int left = 2 * now + 1;
			int right = 2 * now + 2; 

			if (left >= _heap.size())
				break;

			int next = now;

			if (_heap[next] > _heap[left])
				next = left;

			if (right < _heap.size() && _heap[next] > _heap[right]) // > 작은 것부터
				next = right;

			if (next == now)
				break;


			::swap(_heap[now], _heap[next]);
			now = next;
		}

	}

	T& top()
	{
		return _heap[0];
	}

	bool empty()
	{
		return _heap.empty();
	}

private:
	Container _heap = {}; 
};

void examPQ()
{
	Priority_queue<int, vector<int>> pq;

	for (int i = 0; i < 20; i++)
	{
		int rValue = rand() % 100;
		pq.push(rValue);
	}

	while (pq.empty() == false)
	{
		int count = pq.top();
		pq.pop();

		cout << count << " ";
	}

	

}


int main()
{
	srand(time(nullptr));
	minDistance();
	examPQ();

}

// Maze 적용은 하지 않을 예정.
// BFS-> 다익스트라 모든 간선의 비용이 1인 것과 같다.
// AStar-> 다익스트라 + @ // 