#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;



/*
 * 짝수: 안마신다.
 * 홀수: 마신다.
 */
array<int, 10001> dp;
int drinking(int n){
	return 1;
}

int top_down(vector<int>& p) {

}

int bottom_up(vector<int>& p) {
	int n = p.size();
	dp[0] = 0;
	for(int i = 1; i <= std::min(2, n); i++){
		dp[i] = p[i] + dp[i-1];
	}
	short drink = 0;
	for(int i = 3; i <= n; i++){
		dp[i] = max(dp[i-2]+p[i], max(dp[i-3] + p[i-1] + p[i], dp[i-1]));
		//cout << i << ": " << dp[i] << endl;
	}
	return dp[n];
}


int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	vector<int> podo;

	cin >> n;
	podo.push_back(0);
	for(int i = 1; i <= n; i++){
		int temp;
		cin >> temp;
		podo.push_back(temp);
	}

	//cout << drinking(podo.size()-1, 0) << endl;
	cout <<	bottom_up(podo);
	return 0;
}
