#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;


//  LastInFirstOUT : LIFO 마지막에 넣은 게 젤 먼저 나온다.
//
//
//

// stack, queue - adopter (스스로 자료구조 성격 x , 다른 자료구조(container) 이용해서 사용하는 형태)
// 개념적으로 사용하는 자료구조.
// stack 성질을 가진 코드로 구현하자 -> ctrl + z
// vector의 push_back
// iterator사용해서 첫번째 중간 원소에 접근하는 것을 정책적으로 막자.

// vector, list, deque Stack 성능차이가 있겠다.
// Deque -- stack의 성능이 좋겠구나.
// vector?
// list?

template <typename T, typename Container = vector<T>>
class Stack // LIFO
{
public:
	void push(const T& value)
	{
		_container.push_back(value);
	}

	void pop()
	{
		_container.pop_back();
	}

	int top()
	{
		return _container.back();
	}

	int size()
	{
		return _container.size();
	}

	bool empty()
	{
		return _container.empty();
	}

private:
	Container _container;


};

// FIFO - Queue 먼저 들어온 녀석이 먼저 나온다.



int main()
{

	Stack<int, vector<int>> s;
	s.push(1);
	s.push(2);
	s.push(3);

	cout << "Stack 자료 구조" << endl;
	while (s.empty() == false)
	{
		int count = s.top();
		s.pop();
		cout << count << " ";
	}
	cout << endl;

	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	cout << "Queue 자료 구조" << endl;
	while (q.empty() == false)
	{
		int count = q.front();
		q.pop();
		cout << count << " ";
	}
	cout << endl;
}

	 
