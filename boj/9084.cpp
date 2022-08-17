#include <iostream>
#include <algorithm>
#include <array>
#include <cstdlib>
#include <vector>
using namespace std;

//int dp[20][10002] = { 0, };
array<array<int, 10002>, 20> dp;

void init_array(vector<int>& coin){
	for(auto& d : dp)
		d.fill(0);

	reverse(coin.begin(), coin.end());
}

int solution(vector<int>& coin, int m, int d/*depth*/) {
	if(m == 0) {
		dp[d][m] = 1;
	}
	if(dp[d][m]) return dp[d][m];

	if(d < coin.size()) {
		for(int i = 0; coin[d] * i <= m; i++) {
			int next_m = m - coin[d] * i;
			//cout << "coin: " << coin[d] << ", divide: " << coin[d]*i << ", next_m: " << next_m << endl;
			dp[d][m] += solution(coin, next_m, d+1);	
		}
	}
	return dp[d][m];
}

int main()
{
	int t, n, m;
	cin.tie(0);
	cin.sync_with_stdio(false);
	vector<int> coin;

	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 0; i < n; i++){
			int num;
			cin >> num;
			coin.push_back(num);
		}
		init_array(coin);
		cin >> m; // 만들어야 하는 금액
		// solusion
		cout << solution(coin, m, 0) << endl;		
		coin.clear();
	}
	return 0;
}
