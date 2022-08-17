#include <iostream>
using namespace std;
long long dp[91][2];

int main() {
	int n;
	cin >> n;

	// 0으로 시작하지 않는다.
	// 1이 연속 2번 나타나지 않는다.
	dp[1][1] = 1;

	for(int i=2; i<=n; i++){
		dp[i][0] = dp[i-1][0] + dp[i-1][1];
		dp[i][1] = dp[i-1][0];
	}

	cout << dp[n][0] + dp[n][1] << endl;
	return 0;
}
