#include <iostream>
#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

int maze[103][103];
bool visit[103][103] {0};
queue<pair<int, pair<int, int>>> q;

bool is_valid_maze(int sx, int sy, int n, int m) {
	if (sx >= 0 && sx <= m) {
		if (sy >= 0 && sy <= n) {
			return true;
		}
	}
	return false;
}

int BFS(int d, int sx, int sy, int n, int m) {
	//cout << "target:" << n << "," << m << endl;
	q.emplace(d, make_pair(sx, sy));
	int answer = 0;
	while(!q.empty()) {
		//cout << "q.size:" << q.size() << endl;
		auto [dd, p] = q.front();
		auto [px, py] = p;
		q.pop();
		//cout << "d:" << dd << ":\t";
		//cout << py << "," << px << endl;

		if (is_valid_maze(px, py, n, m) == false) {
			//cout << "invalid\n";
			//cout << py << "," << px << endl;
			//cout << "target:" << n << "," << m << endl;
			continue;
		}
		if (maze[py][px] == 0) {
			//cout << "BLOCK\n";
			continue;	
		}
		if(visit[py][px]) {
			//cout << "VISITED\n";
			continue;
		}
		visit[py][px] = 1;

		if (px == m && py == n)
			return dd;
		//cout << "ok\n";
		q.emplace(dd+1, make_pair(px+1, py));
		q.emplace(dd+1, make_pair(px-1, py));
		q.emplace(dd+1, make_pair(px, py+1));
		q.emplace(dd+1, make_pair(px, py-1));
	}
	return 0;
}

void print_maze(int n, int m) {
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			printf("%d", maze[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[])
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n,m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++) {
		for(int j = 0; j < m; j++) {
			scanf("%1d", &maze[i][j]);
		}
	}
//	print_maze(n,m);
	cout << BFS(1, 0, 0, n-1, m-1);
	return 0;
}
