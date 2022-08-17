#include <iostream>
#include <array>
using namespace std;

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	pair<int, int> arr[3];
	int n;
	cin >> n;

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < 3; j++) {
			int num;
			cin >> num;

			arr[j].first += num;
			arr[j].second += num * num;
		}
	}


	int winner = 0;
	bool same = false;
	if(arr[0].second < arr[1].second) winner = 1;
	else if(arr[0].second == arr[1].second) same = true;
	if(arr[winner].second < arr[2].second) winner = 2, same = false;
	else if(arr[winner].second == arr[2].second) same = true;

	cout << (same ? 0 : winner+1) << " " << arr[winner].first << endl;
	return 0;
}
