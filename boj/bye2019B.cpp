#include <iostream>
using namespace std;

int bell[1002][102] ={0};
int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <m; j++){
			int temp;
			cin >> temp;
			bell[i][j] = temp;
		}
	}

	bool ck = true;
	for(int j = 0; j < m; j++){
		for(int i = 0; i < n-1; i++){
			if(bell[i][j] != bell[i+1][j]){
				ck = false;
				break;
			}
		}
		if(ck == false) break;
	}

	if(ck == false) cout << "NO" << endl;
	else cout << "YES" << endl;
	return 0;
}
