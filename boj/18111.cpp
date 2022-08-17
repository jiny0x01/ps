#include <iostream>	
#include <climits>
#include <utility>
using namespace std;
#define MAX_X 502
#define MAX_Y 502


int main(int argc, char *argv[])
{
	int n,m,b;
	int high = 0;
	cin.tie(0);
	cin.sync_with_stdio(false);

	// n 가로
	// m 세로
	// b 인벤토리 블록
	int ground[MAX_Y][MAX_X]{0};

	cin >> n >> m >> b;
	for(int i = 0; i < n; i++)  {
		for(int j = 0; j < m; j++) {
			cin >> ground[i][j];
			high = max(high, ground[i][j]);
		}
	}

	int floor = high;
	int t;
	int time = INT_MAX;
	int bb;
	const int remove_delay = 2;
	const int stack_delay = 1;
	for(int k = 256; k >= 0; k--) {
		bb = b; //block
		t = 0; //소요시간
		
		for(int i = 0; i < n; i++) {
			for(int j = 0; j < m; j++) {
				if (ground[i][j] < k)  {
					t += (stack_delay * (k - ground[i][j]));
					bb -= (k - ground[i][j]);
				}
				else if (ground[i][j] > k)  {
					t += (remove_delay * (ground[i][j] - k));
					bb += (ground[i][j] - k);
				}
			}
		}

		if (bb >= 0 && t < time) {
			time = t;
			floor = k;
		}
	}
	
	cout << time << " " << floor;
	return 0;
}
