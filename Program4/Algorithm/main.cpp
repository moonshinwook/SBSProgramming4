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

// 자료구조. 선형 
// vector, list, deque(원리 정도 이해하기)

// 데이터 삽입, 삭제(앞, 중간, 뒤) : 시간
// 데이터 삭제
// 임의 접근

// deque - stack, queue 컨테이너로 사용된다. 
// deque는 vector, list 장점을 합쳐놓은 녀석이다.
// 시간, 공간

void BinarySearch(int n)
{
	// 1 ~ 10까지 중에 숫자 찾기 로직 만들기.

	vector<int> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int left = 0;
	int right = v.size() - 1;

	int mid = (left + right) / 2;

	while (left <= right)
	{
		if()

	}

	//vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; // 1 + 10 == 11 / 2 = 5(정수만) 
	//int left = 0;
	//int right = v.size() - 1;
	//
	//bool _flag = false;
	//while (left <= right)         // 1, 2        0 + 1 / 2 = 0
	//{
	//	cout << "탐색 Search Range " << left << " - " << right << endl; // 디버깅
	//	int mid = (left + right) / 2;
	//	if (v[mid] > n)
	//	{
	//		cout << n << " < " << v[mid] << endl;
	//		right = mid - 1;
	//	}
	//	else if (v[mid] < n)
	//	{
	//		cout << n << " > " << v[mid] << endl;
	//		left = mid + 1;
	//	}
	//	else
	//	{
	//		cout << "Find! " << endl;
	//		break;
	//	}
	//}
	//if (_flag == false)
	//	cout << "데이터를 찾을 수 없습니다." << endl;
	//
}


int main()
{
#pragma region deque
	vector<int> v;
	v.push_back(1);

	queue<int> q;
	q.push(1);

	deque<int> dq;
	dq.push_back(1);
	dq.push_back(2);
	dq.push_back(3);
	dq.push_back(4);

	dq.push_back(5);
	dq.push_back(6);

	dq.push_front(5);

	while (dq.empty() == false)
	{
		int count = dq.front();
		dq.pop_front();
		cout << count << " ";

	}
#pragma endregion

	// -----------------------------------------------------
	// Q. 

	struct Item
	{
		int id;
		string name;
	};

	{
		vector<Item> items;
		items.push_back(Item{ 1, "AAA" });
	}
	// pair type 
	{
		pair<int, string> item(make_pair(2, "DDD"));

		cout << endl;
		cout << item.first << endl;		// vector<int> 데이터 삽입, 삭제, 정렬, 검색		-> second
		cout << item.second << endl;

		// 아이템 번호가 999인 데이터를 찾아서, 그 데이터를 플레이어에게 전달해줘.

		vector<pair<int, string>> items;

		items.push_back(item);
		items.push_back(make_pair(1, "AAA")); // token
		items.push_back(make_pair(3, "BBB"));
		items.push_back(make_pair(5, "CCC"));

		// 1, 2, 3, 4, 5 아이템들이 이다. 아이템이 3인 녀석을 찾아서 코드를 출력해줘.
		// 비용 최소화 방법.
		// 빅오 표기법, 어떤 조건(정렬이 되었을 때) 아래에서 logN의 효율을 가지고 탐색할 수 있는 BS (Binary Search)
		// O(logN) - 이번 주의 목표
		for (auto it = items.begin(); it != items.end(); ++it)
		{
			if (3 == it->first)
			{
				cout << it->second << endl;
			}
			else
			{
				continue;
			}

		}

	}

	// vector - map - hash table(unordered map) 99% 사용
	// 연관 컨테이너
	{
		map<int, string> m;
		m.insert(make_pair(1, "AAA"));
		m.insert(make_pair(3, "AAA"));
		m.insert(make_pair(5, "AAA"));


		//map<int, string>::iterator 가 auto로 자동 대입시켜줌.
		auto it = m.find(3); // 얼마나 효율적인가? 
		
		if (it != m.end()) // 데이터를 찾은 경우
		{
			cout << endl;
			cout << "key 값 : " << it->first << "Value 값 : " << it->second << endl;
		}

		set<int> s;			// key가 곧 value
		multimap<int, string> mm;  // 중복을 허용.
		multiset<int> ms;

	}

	// 선형 자료구조 - 삽입 삭제 접근 효율 - vector
	// 연관 컨테이너 - 탐색 : map  find
	 
	// 숫자 맞추기 게임 (up & down) - logN
	// 1 2 3 4 ~ 10
	// n의 크기가 크면 클수록 앞에서부터 쭉찾는 방식보다는 다른 방식이 효율적이다.	
	// Binary Search (이진 탐색)

	{
		BinarySearch(7); 
	}

	// 정렬이 되어 있어야 logN 시간 처리 가능.
	// 정렬되어 있지 않은 컨테이너를 정렬하는 방법.
	// 버블, 선택, 삽입
	// 머지, 힙, 퀵

	// 정렬 + BS => 정렬 비용 ?
}
