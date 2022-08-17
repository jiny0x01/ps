#include <iostream>
using namespace std;

int dp[12] = {0,1,2,4,0,};
int solution(int n) {
	if(dp[n]) return dp[n]; 
	dp[n] = solution(n-1) + solution(n-2) + solution(n-3);
	return dp[n];
}

int main() {
	int t;
	cin.tie(0);
	cin.sync_with_stdio(false);

	cin >> t;
	int n;
	while(t--){
		cin >> n;
		cout << solution(n) << endl;
	}
	return 0;
}
