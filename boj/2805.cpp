#include <iostream>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;

long long int  cut_tree(const vector<int>& tree, const int height)
{
	long long int sum = 0;
	for(const auto& t : tree) {
		if (t >= height)
			sum += (t - height);
	}
	return sum;
}

int search_cutting_height(const vector<int>& tree, const int m, int high, int low)
{
	long long int sum;
	int mid = (high + low) / 2;

	while (low < high) {
		sum = cut_tree(tree, mid);
		if (sum >= m) 
			low = mid;
		else
			high = mid;
		mid = (high + low) / 2;
		if (mid == low || mid == high)
			break;
	}
	int i = high;
	while (i >= low) {
		sum = cut_tree(tree, i);
		if (sum >= m)
			break;
		i--;
	}
	return i;
}

int main()
{
	int n, m;
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> n >> m;

	vector<int> v;
	int max = 0;
	while (n--) {
		int num;
		cin >> num;
		max = std::max(max, num);
		v.push_back(num);
	}

	cout << search_cutting_height(v, m, max - 1, 1);
	return 0;
}
