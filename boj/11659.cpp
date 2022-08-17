#include <iostream>
#include <vector>
using namespace std;

int dp[100001] {0};

int prefix_sum(vector<int>& v, int n) {
	if (n <= 0) {
		return dp[0];
	}
	if (dp[n] != 0)
		return dp[n];
	dp[n] = prefix_sum(v, n-1) + v[n];
	return dp[n];
}

int main(int argc, char *argv[])
{
	int n,m;
	cin.tie(0);
	cin.sync_with_stdio(false);

	cin >> n >> m;
	vector<int> v;
	v.push_back(0);
	while (n--) {
		int num;
		cin >> num;	
		v.push_back(num);
	}
	while(m--) {
		int i,j;
		cin >> i >> j;
		int a = prefix_sum(v, j);
		int b = prefix_sum(v, i-1);
		cout << a-b << "\n";
	}
	return 0;
}
