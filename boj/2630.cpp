#include <iostream>
#include <cstdio>
#include <utility>
#include <vector>
#define WHITE_TILE 0
#define BLUE_TILE 1
using namespace std;

void print(const vector<vector<bool>> &v) { 
	for(const auto& i : v) {
		for (const auto& j : i) {
			cout << j << " ";
		}
		cout << "\n";
	}
}

bool same_tile(vector<vector<bool>>& t, int sx, int sy, int n) {
	bool type = t[sy][sx]; 				// 현재 타일 값
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if (t[sy+i][sx+j] != type)	// 해당 사각형 구역에서 타일이 다르면 false
				return false;
		}
	}
	return true;
} 

pair<int, int> get_tile_area(vector<vector<bool> >& t, int sx, int sy, int n) {
	//printf("CALL get_tile_area()\n");
	//printf("\tx:%d\n\ty:%d\n\tn:%d\n", sx, sy, n);

	int area = 0;
	bool type = t[sy][sx];
	bool flag = true;
	for(int i = sy; i < sy+n; i++) {
		for(int j = sx; j < sx+n; j++) {
			if (type != t[i][j]) {
				flag = false;
				break;
			}
		}
		if (flag == false)
			break;
	}
	if (flag) {
	//	cout << "\tequal tile:" << type << endl;
		if (type == WHITE_TILE) 
			return make_pair<int, int>(1, 0);
		else // blue tile
			return make_pair<int, int>(0, 1);
	}

	auto tile = make_pair<int, int>(0, 0);
	if (flag == false) {
	//	printf("\tnot equal all\n");
		// 좌상, 우상, 좌하, 우하
		int dx[4] {sx, sx + n/2, sx		 , sx + n/2};
		int dy[4] {sy, sy	   , sy + n/2, sy + n/2};
		
		for(int i = 0; i < 4; i++) {
	//		cout << "\tsplit\n";
			auto p = get_tile_area(t, dx[i], dy[i], n/2);
			// first is white
			// second is blue
		 	tile.first += p.first;
			tile.second += p.second;
		}
	}
	return tile;
}

int main(int argc, char *argv[])
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	vector<vector<bool> > v;

	int n;
	cin >> n;
	if (n & 1)
		return 0;

	for(int i=0; i<n; i++) {
		bool temp;
		v.push_back(vector<bool>());
		for(int j=0; j<n; j++) {
			cin >> temp;
			v[i].push_back(temp);
		}
	}

//	cout << "map info\n";
//	print(v);
	auto [w, b] = get_tile_area(v, 0, 0, n);

//	cout << endl << "result===\n";
	cout << w << "\n" << b;
	
//	print(v);
	return 0;
}
