#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
using namespace std;
#define M_NUM 100001

int solve(vector<pair<int, int>>& v) {
	if (v.empty()) return 0;
	sort(v.begin(), v.end(), [](const pair<int,int>& lhs, const pair<int,int>& rhs) {
		if (lhs.second == rhs.second)
			return lhs.first < rhs.first;
		else
			return lhs.second < rhs.second;
	});
	
	int cnt = 0;
	int s = 0;
	int e = 0;
	for(int i = 0; i < v.size(); i++) {
		if (v[i].first >= e) {
			s = v[i].first;
			e = v[i].second;
			cnt++;
		}	
	}
	return cnt;
}

int main(int argc, char *argv[])
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	vector<pair<int, int>> v;
		
	while (n--) {
		int a,b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}
	
	cout << solve(v);
	return 0;
}
