#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main(int argc, char *argv[])
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;

	vector<int> origin;

	for(int i = 0; i < n; i++) {
		int num;
		cin >> num;
		origin.push_back(num);
	}

	vector<int> v = origin;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	// v에는 중복없는 값만 남음.
	for(const auto& itr : origin) {
		cout << lower_bound(v.begin(), v.end(), itr) - v.end() << ' ';
	}
	return 0;
}
