#include <iostream>
#define mod 10007
using namespace std;
int dp[1001][10];

int main() {
	int n;
	cin >> n;

	for(int i=0; i<=9; i++)
		dp[1][i] = 1;

	for(int i=2; i<=n; i++){
		for(int j=0; j<=9; j++){
			for(int k=j; k<=9; k++){
				dp[i][j] += dp[i-1][k];
				dp[i][j] %= mod;
			}	
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
