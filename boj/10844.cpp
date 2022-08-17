#include <iostream>
#include <array>
#define mod 1000000000;
using namespace std;
int dp[101][10];

void init() {
	for(int i=1;i<=9;i++){
		dp[1][i] = 1;
	}
}




int main()
{
	int n;
	cin >> n;
	
	init();
	for(int i=2; i<=n; i++){
		for(int j=0; j<=9; j++){
			if(j-1 >= 0) dp[i][j] += dp[i-1][j-1];
			if(j+1 <= 9) dp[i][j] += dp[i-1][j+1];
			dp[i][j] %= mod;
		}
	}

	int64_t sum = 0;
	for(int i=0; i<=9; i++){
		sum += dp[n][i];
	}
	sum %= mod;
	cout << sum << endl;  

	return 0;
}
