#include <iostream>
using namespace std;

int dp[102]{0,1,1,1,2,2,3,4,5,7,9,12};

int solve(int n) {
	if (dp[n]) return dp[n];
	return dp[n] = solve(n-1) + solve(n-)
}

int main(int argc, char *argv[])
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		cout << solve(n) << "\n";
	}
	return 0;
}
