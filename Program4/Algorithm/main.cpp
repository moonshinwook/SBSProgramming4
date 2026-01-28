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
		v[left + i] = temp[i];			// + 1로 하여 정렬이 안됌. +i로 고쳐 정렬 가능

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

// 힙, Merge, quick
// quick - 
// merge -> middle
// 피벗 빠르게 선택했다. 

// pivot

// [5] | [1][3][7][9][2][4][6][8]
// P	  l                    h	pivot 어느 위치에 있으면 가장 어울릴까?
//		[1][3][4][9][2][7][6][8]
//		[1][3][4][2][9][7][6][8]
//		[2][1][3][4][5][9][7][6][8]
//   
// 1> low high low->	<-high	pivot값			<-[5]->
// //  v[low] <= p	     v[high] >= p
// 2> low indext값(2)  <  high(5)	swap
// 3> swap(v[left], v[h])

// Heap vs Merge vs Q [sort]
// nlogn			n^2, nlogn
// nlogn 시간을 갖는다. 
// 대부분 퀵솔트로 시간적으로 별로임. 대신 공간적으로 효율 시간과 공간의 반비례, 따로 메모리 사용을 하지 않는다. 
// Merge의 경우 temp를 사용하여 메모리 사용, Heap은 PQ 사용으로 메모리 사용. 시간 절약을 위해, 공간 사용.

int Partition(vector<int>& v, int left, int right) // 퀵솔트의 핵심코드
{
	int pivot = v[left];
	int low = left + 1;
	int high = right;
	
	// pivot의 수에 따라 결과가 달라짐. 최하(pivot이 제일 작거나 제일 큰 경우) (N) - logN 까지 시간경과 범위 있음.
	// 대략 n^2 ~ nlogN 시간 범위
	while (low <= high)
	{
		while (low <= right && pivot >= v[low])			// 배열 범위 && 피벗 비교
			low++;
		while (high >= left + 1 && pivot <= v[high])	// 배열 범위 && 피벗 비교
			high--;
		if (low < high)
			swap(v[low], v[high]);
	}
	
	
	swap(v[left], v[high]);
	return high;										// 피벗이 위치해야할 index값
}

void QuickSort(vector<int>& v, int left, int right)
{
	if (left > right)
		return;

	int pivot = Partition(v, left, right);
	QuickSort(v, left, pivot - 1);						// 왼쪽 파트 재귀
	QuickSort(v, pivot + 1, right);						// 오른쪽 파트 재귀

}

// 탐색. N 전수 조사는 N시간이 걸린다. 
// nlogn * logn = nlog(n제곱)
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
	//HeapSort(v);
	//MergeSort(v, 0, v.size() - 1);
	QuickSort(v, 0, v.size() - 1); // [1] 1 0 

	// 연관 컨테이너 - 탐색
	// 보통 logN 시간 걸림.
	// 추가. logN <<<< 로딩. 
	//				실제 게임에서의 렉
	// 
	// 탐색 시간이 빠르다. logN이 걸림. < nlogN

	for(const auto & a : v)
	{
		cout << a << " ";
	}
}
