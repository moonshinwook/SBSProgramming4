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

// DP 대표 문제 풀기 
// 조합
// 피보나치 수열 (fibo)

// 게임 코드 구현 x

vector<int> dp;

int Fibo(int n)
{
	// 기저 사항 
	// 탈출할 수 있는 조건.

	dp.resize(n + 1);

	dp[0] = 0;
	dp[1] = 1;
	
	for (int i = 2; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];	// 점화식 F(n) = F(n - 1) + F(n - 2)
	}

	return dp[n];
}



int main()
{

	cout << Fibo(7);

}