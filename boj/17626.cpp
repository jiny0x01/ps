#include <iostream>	
#include <cmath>
#include <type_traits>
#include <utility>
#include <climits>
#include <array>
using namespace std;


std::array<int, 50001> dp;

int solve(int n) {
	dp[0] = 0;
	for(int i = 1; i <= n; i++) {
		dp[i] = 5;
		for(int j = 1; j*j <= i; j++) {
			dp[i] = min(dp[i], dp[i-j*j] + 1);
		}
	}

	return dp[n];
}

int main() {
	int n;
	cin >> n;

	cout << solve(n);
	return 0;
}
