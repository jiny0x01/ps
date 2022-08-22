#include <iostream>
#include <vector>
#include <array>
using namespace std;


bool is_same_paper(const vector<vector<int>>& v, int n, int nx, int ny)
{
	int base = v[ny][nx];
	for(int i = ny-n+1; i <= ny; i++) {
		for(int j = nx-n+1; j <= nx; j++) {
			if (base != v[i][j]) {
				return false;
			}
		}
	}
	return true;
}


int paper_type[3];

void split_paper(const vector<vector<int>>& v, int n, int nx, int ny) 
{

	/*
	 1 2 3
	 4 5 6
	 7 8 9(n)
	 */
	if (is_same_paper(v, n, nx, ny)) {
		paper_type[v[ny][nx]+1]++;
		return;
	}

	// 3 3 6 
	// 1 2 3
	// 2  6 4 5 6

	const int dx[9]{
		nx - n/3*2, nx - n/3, nx,  // 1 2 3
		nx - n/3*2, nx - n/3, nx,  // 4 5 6
		nx - n/3*2, nx - n/3, nx,  // 7 8 9 
	};
	const int dy[9]{
		ny - n/3*2, ny - n/3*2, ny - n/3*2,   // 1 2 3 
		ny - n/3,	ny - n/3, 	ny - n/3, // 4 5 6
		ny, 		ny, 		ny, 	// 7 8 9
	};

	// 3 3 6
	// 1 2 3
	// 2
	// 4
	// 6
	for(int i = 0; i < 9; i++) {
		split_paper(v, n/3, dx[i], dy[i]);
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	vector<vector<int>> v(n+1);
	for (int i = 1; i <= n; i++) {
		v[i].push_back(0);
		for(int j = 1; j <= n; j++) {
			int num;
			cin >> num;
			v[i].push_back(num);
		}
	}
	/*
	// print vector
	for (int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			cout << v[i][j] << " ";
		}
		cout << endl;
	}
	*/

	split_paper(v,n,n,n);
	for(int i = 0; i < 3; i++) {
		cout << paper_type[i] << endl;
	}
	return 0;
}
