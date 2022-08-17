#include <iostream>
using namespace std;

int bell[1002][102] ={0};
int main() {
	int n, m;
    cin.tie(0);
    cin.sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i < n; i++) {
		for(int j = 0; j <m; j++){
			cin >> bell[i][j];
		}
	}

	for(int i = 0; i < n-1; i++){
		for(int j = 0; j < m; j++){
			if(bell[i][j] xor bell[i+1][j]){
				cout << "NO" << endl;
				return 0;
			}
		}
	}

	cout << "YES" << endl;
	return 0;
}
