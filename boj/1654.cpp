#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <climits>
using namespace std;

// 길이가 최소인 랜선으로 쪼갠다. 다른 랜선들을 만들어본다.

int get_lan(vector<int>& lan, int lan_size)
{
	int cnt = 0;
	for(const auto& l : lan)
		cnt += floor(l / lan_size);
	return cnt;
}

int slice_lan(vector<int>& lan, int n, int start, int end)
{
	int mid = (start + end) / 2;
	int cnt = get_lan(lan, mid);
//	cout << "cnt: " << cnt << endl;

	if (!(mid == start || mid == end))
	{
		if (cnt < n)
			return slice_lan(lan, n, start, mid);
		else if(cnt >= n)
			return slice_lan(lan, n, mid, end);
	}
//	cout << "start: " << start << ", end: " << end << endl;
	int i = end;
	while ((cnt = get_lan(lan, i)) < n) {
//		cout << "cnt: " << cnt << ", lan: " << i << endl;
		i--;
	}
	return i;
}

int  main() 
{
	int k, n;
	int max_lan;
	cin.tie(0);
	cin.sync_with_stdio(false);
	vector<int> lan;

	cin >> k >> n;
	max_lan = 0;
	while (k--) {
		int temp;
		cin >> temp;
		max_lan = std::max(max_lan, temp);
		lan.push_back(temp);
	}
//	cout <<"\n\n";
	cout << slice_lan(lan, n, 1, max_lan);
}
