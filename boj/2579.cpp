#include <iostream>
#include <vector>
using namespace std;

int step_stair(vector<int>& v)
{
	int dp[302];
	dp[0] = v[0];
	dp[1] = v[1];
	dp[2] = v[1] + v[2];
	for(int i = 3; i < v.size(); i++)
	{
		// dp[i]는 현재 칸
		// max(이전칸 안오르고 현재칸으로, 이전칸과 현재칸오르기);
		dp[i] = max(dp[i-2] + v[i], dp[i-3] + v[i] + v[i-1]);
	}
	return dp[v.size()-1];
}

int main()
{
	int n;
	cin >> n;
	vector<int> v;
	v.push_back(0);
	while(n--)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	cout << step_stair(v);
	return 0;
}
