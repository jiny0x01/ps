#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
using namespace std;
#define lld long long int

lld histogram(vector<lld>& v) {
	lld n = v.size();
	lld left[100003];
	lld right[100003];

	stack<pair<lld, lld>> s;
	s.emplace(-1, 0); // v[i] 보다 작은 최초의 위치 
	for(lld i = 1; i <= n; i++) {
		while (s.top().first >= v[i-1])
			s.pop();
		left[i] = s.top().second+1;
		s.emplace(v[i-1], i);
	}

	while(!s.empty()) {
		s.pop();
	}

	s.emplace(-1, n+1); // v[i] 보다 작은 최초의 위치 
	for(lld i = n; i >= 1; i--) {
		while (s.top().first >= v[i-1])
			s.pop();
		right[i] = s.top().second -1;
		s.emplace(v[i-1], i);
	}
	
	lld ans = 0;
	for(lld i = 1 ; i<= n; i++) {
		ans = max(ans, v[i-1] * (right[i] - left[i] + 1));
	}
	return ans;
}

int main(int argc, char *argv[])
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	vector<lld> v;
	lld num = 1;
	char ch;
	while (num != 0) {
		ch = 0;
		while (ch != '\n') {
			scanf("%lld%c",&num, &ch);
			v.emplace_back(num);
		}
		if (num == 0)
			break;
		cout << histogram(v) << "\n";
		v.clear();
	}
	return 0;
}
