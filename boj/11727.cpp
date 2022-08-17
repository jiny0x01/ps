#include <iostream>
using namespace std;

int dp[1002];

int	tile(int n)
{
	if (dp[n]) return dp[n];
	if (n == 1)
	{
		dp[n] = 1;
		return dp[n] % 10007;
	}
	else if(n == 2)
	{
		dp[n] = 3;
		return dp[n] % 10007;
	}
	dp[n] = tile(n-1) + tile(n-2) * 2 % 10007;
	return dp[n] % 10007; 
}

int main()
{
	int n;
	cin >> n;
	
	cout << tile(n);
	return (0);
}
