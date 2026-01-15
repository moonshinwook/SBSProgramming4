#include <iostream>
#include <vector>
#include <array>
#include <list>
#include <deque>
#include <map>
#include <set>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 자료구조 Standard Template Library 클래스. 데이터를 특성에 맞게 저장하는 컨테이너.
// ---------------------------- 선형		: array vector list map deque stack queue
// ---------------------------- 비선형   : map set hash-table;

// sequential 절차적 컨테이너 << array 배열
// relational 관계형 컨테이너 << 

//cout << "선형 자료구조 공부 " << endl;
//cout << "vector살펴보자" << endl;
//
//
//cout << "라이브러리 제공되는 기능을 사용해본다." << endl;
//cout << "vector 어떻게 만들어 졌는가 원리?" << endl;
//
//cout << "뭐가 좋고 뭐가 나쁜가?" << endl;
//cout << "코드를 작성을 하고, 비교" << endl;
//cout << "어떻게 분석할까?" << endl;

//// 빨리 실행될수록 좋다.
//// 느낌적으로 좋은 것 같다.   -> 환경에 따라 코드 출력속도가 다름.
//// 비교를 하기 위해서 약속된 어떠한 내용을 따르자 -> big O (order of O) 빅오표기법, 알고리즘상 괜찮다.
//
//// 시간적으로 얼마나 빠른가
//
//// 공간적으로 효율적인가?
//
//// N^3
//
//cout << "빅오표기법이 무엇일까?" << endl;
//cout << "실행이 자주 될까 체크" << endl;
//
//int a = 10; // 1번 실행
//
//for (int i = 0; i < a; i++) // n번 실행했다. n을 아주 큰 수 늘린다 가정. 
//	cout << i << " ";
//
//int target = 100;
//
//while (target != a)
//{
//	target /= 2;
//
//	if (a > target)
//	{
//
//	}
//}
//// 범위를 줄이고 
//for (int x = 0; x < 6; x++)
//{
//	if (6 + x == a)
//	{
//
//	}
//}
//
//// n = 1
//// n = logn
//// n = ax + b;
//// n = n * log n;
//// n = ax^2 + bx + c;

struct Player
{
	int id;
};

// 면접에서 직접 구현 << 
// 만들기 위한 이론적인 원리

int main()
{
	// 플레이어를 최대 10명까지만 저장할 수 있다. 
	// 100000
	// array (고정 배열) <-> 가변 배열   vector, list
	// array가 vector보다 안 좋은가? 그건 아니다. 크기가 고정되어있으면 성능상 array 더 좋습니다. 


	// (맨처음) (맨끝) (중간) 삽입 삭제  
	// 임의 접근 (Random Access) 

	vector<int> v;

	for (int i = 0; i < 25; i++)
	{
		v.push_back(i);
		cout << v[i] << " " << v.size() << " " << v.capacity() << endl;
	}

	// iterator << 뭐지?
	// v.push_front(); vector은 push_front지원을 안 해주네?
	// v.insert()

	// iterator가 뭔가요? ptr인데, 자료구조에 귀속되어 있는 ptr

	// 결론 : STL 자료구조(컨테이너) - 반복자(iterator)를 통해서 조작할 수 있다. 

	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();
	cout << endl;


	v.insert(v.begin() + 5, 9999);
	v.erase(v.begin() + 5);
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it) << " ";
	}

	// 99번 째 아이디를 가지고 있는 플레이어를 삭제해주세요.

	for (vector<int>::iterator it = v.begin(); it != v.end();)
	{
		int data = (*it);

		if (data == 3)
		{
			it = v.erase(it); // 3번째 3을 지워라
		}
		else
		{
			++it; // 기존의 반복문에서 ++대체
		}
	}
	cout << endl;
	for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it) << " ";
	}
}