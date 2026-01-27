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

// 버블 선택 삽입
// 버블
// bubble - 가장 큰 숫자를 위로 보내겠다. 
// [4][1][3][2][5] 

// O(n) - n^2
void BubbleSort(vector<int>& v)
{
	int n = v.size();

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (v[j] > v[j + 1])
			{
				::swap(v[j], v[j + 1]);
			}
		}
	}
}

//int n = v.size();
//
//for (int i = 0; i < n - 1; i++)
//{
//	for (int j = 0; j < n - 1; j++)
//	{
//		if (v[j] > v[j + 1])
//		{
//			::swap(v[j], v[j + 1]);
//		}
//	}
//}

// 선택 : 작은 것을 앞으로 보내자.
// [4][1][3][2][5] 5개 중 제일 작은 것을 어떻게 구할래. PQ(mindistance)
// [1][4][3][2][5] 1회차
// [1][2][3][4][5]

// n * n = n^2만큼 시간 걸림. -> 버블솔트보다는 효율적. swap을 조금 덜해서
void selectSort(vector<int>& v)
{
	int n = v.size();

	for (int i = 0; i < n - 1; i++)
	{
		int bestIdx = i;

		for (int j = i + 1; j < n; j++)
		{
			if (v[j] < v[bestIdx])
				bestIdx = j;
		}
		swap(v[i], v[bestIdx]);
	}
}

// 삽입
// [4] | [1] [3] [2] [5] 
// 정렬 | 비정렬
// 1 4 | 3 2 5
// 1 3 4 | 2 5
// 1 2 3 4 | 5
// 1 2 3 4 5



// n * n = n^2
// 특별한 case : 데이터가 거의 정렬이 되어 있으면 효율적이다.  
void Insertsort(vector<int>& v)
{
	int n = v.size();

	for (int i = 1; i < n; i++)
	{
		int insertData = v[i];

		int j; // 루프가 끝나더라도 사용 가능.
		for (j = i - 1; j >= 0; j--)
		{// 스택 영역 (루프를 돈 뒤 사라지는 영역)
			if (v[j] > insertData)
				v[j + 1] = v[j];
			else // [i] j 값이 작으면 내위치
				break;

			
		}
		v[j + 1] = insertData;
	}
}

// 순차 컨테이너 (vector, list, deque) - 정렬되지 않은 데이터가 들어온다. 

// 머지, 힙, 퀵 sort 
// greater - 작은 것 위, less 큰 것이 위

// 
void HeapSort(vector<int>& v)
{
	priority_queue<int, vector<int>, greater<int>> pq;

	// n * logN 
	for (int num : v)
		pq.push(num);

	v.clear();

	// N * logN
	while (pq.empty() == false)
	{
		int count = pq.top();
		pq.pop();
		v.push_back(count);
	}


}
// 2nlogN -> nlogN시간이 걸린다.  2는 무시

// 합병 (merge)

// Divide and conquer 분할 정복
// 4 3 1 9 7
void MergeResult(vector<int>& v, int left, int mid, int right)
{
	int leftIdx = left;
	int rightIdx = mid + 1;

	vector<int> temp;

	while (leftIdx <= mid && rightIdx <= right)
	{
		if (v[leftIdx] < v[rightIdx])
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
		else
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}

	}
	
	// 왼쪽이 먼저 끝났을 때
	if (leftIdx >= mid)
	{
		while (rightIdx <= right)
		{
			temp.push_back(v[rightIdx]);
			rightIdx++;
		}
	}
	else 
	{
		while (leftIdx <= mid)
		{
			temp.push_back(v[leftIdx]);
			leftIdx++;
		}
	}
		
	// temp -> vector 넣어준다
	for (int i = 0; i < temp.size(); i++)
		v[left + 1] = temp[i];

}

// n * logN
void MergeSort(vector<int>& v, int left, int right)
{
	if (left >= right)
		return;

	int mid = (left + right) / 2;
	MergeSort(v, left, mid);
	MergeSort(v, mid + 1, right);
	
	MergeResult(v, left, mid, right);
}

int main()
{
	vector<int> v{ 4,1,3,2,5 };
	srand(time(0));
	for(int i = 0; i < 10; i++)
		v.push_back(rand() % 100);
	// TODO 정렬하기 
	//BubbleSort(v);
	//selectSort(v);
	//Insertsort(v);
	// HeapSort(v);
	MergeSort(v, 0, v.size() - 1);
	for(const auto & a : v)
	{
		cout << a << " ";
	}
}
