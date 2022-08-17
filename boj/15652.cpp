#include <iostream>
#include <vector>
using namespace std;

vector<int> ck;

void series(int n, int m /* 남은 것*/) {
	if(m == 0) {
		for(const auto& num : ck) {
			cout << num << " ";
		}
		cout << "\n";

		return;
	}
	int i = ck.size() > 0 ? ck.back() : 1;
	for(; i <= n; i++) {
		ck.push_back(i);
		series(n, m-1);
		ck.pop_back();
	}
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n,m;
	cin >> n >> m;

	series(n, m);
	return 0;
}

