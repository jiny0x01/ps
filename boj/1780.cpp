#include <iostream>
#include <vector>
#include <array>
using namespace std;


void divide(const vector<vector<int>>& v, array<int, 3>&  r, int n, int x, int y)
{
	bool equal = true;
	int t = v[y][x];

	for (int i = y; i > y-n; i--) {
		for(int j = x; j > x-n; j--) {
			if (t != v[i][j]) {
				equal = false;
				break;
			}	
		}
		if (!equal)
			break;
	}

	if (equal) { // 다 똑같으면
		r[t+1]++;
//		cout << "n:" << n << "entry x:" << x << ", y:" << y << ", value:" << t <<  endl;
	} else { // 종이 쪼개기 
		for (int i = 1; i <= 3; i++)  {
			for(int j = 1; j <= 3; j++) {
				if (n>=9) {
					// y값 수정필요
					divide(v, r, n/3, x/3 * i, y*j/3);	
				} else {
					int t = v[y-i+1][x-j+1];	
					r[t+1]++;
				}
			}
		}
	}
}

void split_paper(const vector<vector<int>>& v, int n) 
{
	array<int, 3> r{0,0,0};
	divide(v, r,  n, n, n);
	for(const auto& itr : r)
		cout << itr << "\n";
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

	split_paper(v, n);
	return 0;
}
