#include <iostream>
#include <cstdio>
using namespace std;


int matrix[65][65];
// @return
// -1: 압축 실패
// 0: 0으로 압축가능
// 1: 1로 압축가능

int compress(int n, int nx, int ny) {
	// 4 4 4
	// 2 2 2
		// 1 1 1
		// 1 2 1 {1}
		// 1 1 2 {2}
		// 1 2 2 {3}
	// 2 4 2
		// 1 2 1 {1} //3 1 
		// 1 4 1    // 4 1
		// 1 2 2 {3} //3 2
		// 1 4 2 {4} //4 2
	// 2 2 4
		// 1 1 2 {2} // 1 3
		// 1 2 2 {3} // 2 3
		// 1 1 4 	// 1 4
		// 1 2 4 {5} // 2 4
	// 2 4 4
		// 1 2 2 {3} // 3 3
		// 1 4 2 {4} // 3 4
		// 1 2 4 {5} // 4 3 
		// 1 4 4  
	int flag = matrix[ny][nx];
	for(int y = ny; y > ny-n; y--) {
		for(int x = nx; x > nx-n; x--) {
			if (matrix[y][x] != flag) {
				return -1;
			}	
		}		
	}
	return flag;
}

void divide(int n, int x, int y) {
	// 4등분이 안될 때 까지 쪼갠다.
	if (n < 1) {
		return;
	}

	// 쪼개기 전에 압축이 가능한지 판별
	int compressed = compress(n, x, y);
	if (compressed == -1) {
		cout << "(";

		// 제 1사분면
		divide(n/2, x-n/2, y-n/2);
		// 제 2사분면
		divide(n/2, x, y-n/2);
		// 제 3사분면
		divide(n/2, x-n/2, y);
		// 제 4사분면
		divide(n/2, x, y);

		cout << ")";
	} else {
		cout << compressed;
	}

}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;

	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) {
			scanf("%1d", &matrix[i][j]);
		}
	}	

	divide(n, n, n);
	
	return 0;
}
