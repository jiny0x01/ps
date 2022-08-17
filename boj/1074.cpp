#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstdio>
#include <cmath>
#include <utility>
#define MAX_LEN 32679
using namespace std;


int arr[MAX_LEN][MAX_LEN]{};
int Size;
int N,r,c; // row column

void print_arr() {
	cout << "============\n";
	for(int i=1; i <= Size; i++) {
		for(int j=1; j <= Size; j++) {
			printf("%4d", arr[i-1][j-1]);
		}
		cout << endl;
	}
	cout << "============\n";
}

int split(int n, int sx, int sy) {
//	cout << "Call split()\n";
//	printf("\tx:%d\n\ty:%d\n\tn:%d\n", sx, sy, n);
	static int cnt = 0;

	if (n <= 2) { // 최소사이즈
		for(int i = sy; i < sy + 2; i++) {
			for(int j = sx; j < sx + 2; j++) {
//				printf("\t curx:%d, cury:%d\n", j, i);
				arr[i][j] = 1;
				if (j == c && i == r)
					return cnt;
				cnt++;
			}
		}
		// not found
		return 0;
	}
	// recursive  
	// 좌상, 우상, 좌하, 우하
	int dx[4] {sx, sx + n/2, sx		 , sx + n/2};
	int dy[4] {sy, sy	   , sy + n/2, sy + n/2};
	
	int result = 0;
	for(int i = 0; i < 4; i++) {
//		printf("cur x:%d~%d, y:%d~%d\n", dx[i], dx[i]+n/2, dy[i], dy[i]+n/2);
		if (c >= dx[i] && r >= dy[i] && 
			c <= dx[i] + n/2 && r <= dy[i] + n/2) {
			result = split(n/2, dx[i], dy[i]);
		}
		else {
			cnt += (n/2)*(n/2);
	//		printf("adding:%d\n", cnt);
		}
		if (result != 0) 
			break;
	}
	return result;	
}

int main()
{
	cin >> N >> r >> c;

	Size = pow(2, N);
	cout << split(Size, 0, 0) << endl;

	return 0;
}

