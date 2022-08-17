#include <iostream>
#include <vector>
using namespace std;

bool visit[101][101];
int n;
using color = struct color {
	int red = 0;
	int blue = 0;
	int green = 0;
}; 
int solve(vector<vector<char>>& m, int x, int y, char ch) {
	if (m[y][x] != ch)
		return 0;
	if (visit[y][x]) 
		return 0;

	//cout << "y:" << y << " x:" << x << " color:" << ch << "\n";
	visit[y][x] = 1;
	int dx[4] = {x+1, x-1, x, x};		
	int dy[4] = {y, y, y+1, y-1};		


	for(int i = 0; i < 4; i++) {
		if (dx[i] >= 0 && dx[i] < n && dy[i] >= 0 && dy[i] < n) {
			solve(m, dx[i], dy[i], ch);
		}
	}
	return 1;
}

int main(int argc, char *argv[])
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	vector<vector<char>> v;

	cin >> n;
	char ch;
	for(int i = 0; i < n; i++) {
		v.emplace_back(vector<char>());
		for(int j = 0; j < n; j++) {
			cin >> ch;
			v[i].push_back(ch);
		}
	}
	color c1 {0,0,0},c2{0,0,0};
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++){ 
			c1.red += solve(v, j, i, 'R');
			c1.green += solve(v, j, i, 'G');
			c1.blue += solve(v, j, i, 'B');
		}
	}
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++){ 
			if (v[i][j] == 'G')
				v[i][j] = 'R';
		}
	}
	for(int i = 0; i < 101; i ++){
		for(int j = 0; j < 101; j++) {
			visit[i][j] = 0;
		}
	}

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++){ 
			c2.red += solve(v, j, i, 'R');
			c2.blue += solve(v, j, i, 'B');
		}
	}
	cout << c1.red + c1.blue + c1.green << " " << c2.red+c2.blue << "\n";
	return 0;
}
