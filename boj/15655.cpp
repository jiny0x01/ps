#include <iostream>
#include <vector>
#include <algorithm>
#include <array>
using namespace std;

vector<int> num;
vector<int> ck;
bool  memo[9];

void series(int n, int m /* 남은 것*/) {
	if(m == 0) {
		for(const auto& num : ck) {
			cout << num << " ";
		}
		cout << "\n";

		return;
	}
	for(int i = 1; i <= n; i++) {
		if(ck.size() > 0 && num[i] <= ck.back()) {
			continue;	
		}

		ck.push_back(num[i]);
		series(n, m-1);
		ck.pop_back();
	}
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n,m;
	cin >> n >> m;

	num.push_back(0);
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		num.push_back(temp);
	}
	sort(num.begin(), num.end());
	series(n, m);
	return 0;
}
