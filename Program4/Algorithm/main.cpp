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

// iterator : ptr 내장하고 있는 클래스. wraping
// STL container 안에서 포인터로 쓴다. 

template<typename T>
class Iterator
{
public:
	Iterator() : _ptr( nullptr ) {} // ':' 멤버 선언
	Iterator(T* ptr) : _ptr(ptr) {}        

public:
	Iterator& operator++() // 전위 연산자 (더한 뒤 return)
	{
		_ptr++;
		return *this; // this 클래스의 주소.     _ptr주소의 주소
	}

	Iterator& operator++(int) // 후위 연산자를 표현하는 방법 it++
	{
		Iterator temp = *this; // 새로운 객체 생성. 메모리 할당 대입 연산을 하고
		_ptr++;
		return temp;
	}

	Iterator& operator--()
	{
		_ptr--;
		return *this;
	}

	Iterator& operator--(int) // 후위 연산자를 표현하는 방법 it++
	{
		Iterator temp = *this; // 새로운 객체 생성. 메모리 할당 대입 연산을 하고
		_ptr--;
		return temp;
	}

	bool operator==(const Iterator & other)
	{
		return _ptr == other._ptr;
	}

	bool operator==(const Iterator& other)
	{
		return !(this* == other);
	}

	Iterator operator+(const int count)
	{
		Iterator temp = *this;
		temp._ptr += count;
		return temp;
	}

	T& Operator* () { return *_ptr; } // 연산자오버로딩

	// int* ptr; *ptr;
	//				++it;		it++;

public:
	T* _ptr;
	
};

template <typename T>
class Vector
{
public:
	Vector() : _data(nullptr), _size(0), _capacity(0) {}
	~Vector()
	{
		if (_data)
			delete[] _data;
	}
public:
	// 데이터가 없을 때 _size 0 : _capacity 0
	void push_back(const T& data)
	{
		if (_size == _capacity)
		{
			// _data 만들어주자.
			int newCapacity = _capacity * 1.5;  // 0		1 * 1.5 = 1.5 1  
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}
		_data[_size] = data;

		_size++;
	}

	void reserve(int capacity)
	{
		// capacity 크기만큼 data를 new만든다.		>> 새로운 메모리 공간을 생성한다.
		_capacity = capacity;

		T* newData = new T[_capacity];
		// 기존 데이터를 새로운 공간으로 이주시켜줘.(★★★★)

		for (int i = 0; i < _size; i++)
			newData[i] = _data[i];

		if (_data)
			delete[] _data; // 기준

		_data = newData;
	}

	T& operator[](int index) 
	{ 
		return _data[index];
	}			

	int size() { return _size; }
	int capacity() { return _capacity; }

private:
	typedef Iterator<T> iterator;

	iterator begin() { return iterator( &_data[0]); } // 첫번째 순서의 주소를 받기 위해 '&'
	iterator end() { return begin() + _size; }
private:
	T* _data;
	int _size;
	int _capacity;
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

	// reserve 최소한으로 하려면 어떻게 하면 좋은가? 미리 만들어놓는다. reserve()
	// 미리 만들어서 빠르게 사용할 수 있다. 

	Vector<int> v;
	v.reserve(100);
	for (int i = 0; i < 25; i++)
	{
		v.push_back(i);
		cout << v[i] << " " << v.size() << " " << v.capacity() << endl;
	}

	Vector<int>::iterator vStart = v.begin();
	cout << "후위 연산자, 전위 연산자" << endl;   // 전위 연산자는  1, 후위 연산자는  0이 출력된 뒤 ++ 됌.
	cout << "전위 연산자 : " << *(vStart++) << endl;

	//v.clear();
	//vector<int> temp;
	//swap(v, temp);
	//cout << v.size() << " " << v.capacity() << endl;



	// 면접 단골 질문(★★)
	// Q) 데이터 insert, 데이터 push_front 지원을 하지 않는다. 이유는? 
	// A) 느리다. n만큼 order of N -   O(N)시간만큼 걸린다.
	
	// Random Access(★★★★★)   시작 주소 + << ----> 주소가 연속적으로 배치가 되어 있기 때문에 
	// Id 45000			_data[45000] 데이터만 넣으면 O(1) 시간만큼 걸린다. 항상 일정한 시간이 걸린다. 공간을 낭비시키면 시간을 절약한다. 
	// vector와 array의 차이점을 생각하면서 정리하기


	//// iterator << 뭐지?
	//// v.push_front(); vector은 push_front지원을 안 해주네?
	//// v.insert()

	//// iterator가 뭔가요? ptr인데, 자료구조에 귀속되어 있는 ptr

	//// 결론 : STL 자료구조(컨테이너) - 반복자(iterator)를 통해서 조작할 수 있다. 

	//vector<int>::iterator itBegin = v.begin();
	//vector<int>::iterator itEnd = v.end();
	//cout << endl;


	//v.insert(v.begin() + 5, 9999);
	//v.erase(v.begin() + 5);
	//for (vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	//{
	//	cout << (*it) << " ";
	//}

	//// 99번 째 아이디를 가지고 있는 플레이어를 삭제해주세요.

	for (Vector<int>::iterator it = v.begin(); it != v.end();)
	{
		int data = (*it);

		if (data == 3)
		{
			//it = v.erase(it); // 3번째 3을 지워라
		}
		else
		{
			++it; // 기존의 반복문에서 ++대체
		}
	}
	cout << endl;
	for (Vector<int>::iterator it = v.begin(); it != v.end(); ++it)
	{
		cout << (*it) << " ";
	}
}