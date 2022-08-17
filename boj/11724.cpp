#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool visit[1005] {0};



int solve(vector<vector<int> >& v, int num) {
	if (visit[num])	
		return 0;
	visit[num] = 1;
	int cnt = 1;
	for(int i = 0; i < v[num].size(); i++) 
		cnt += solve(v, v[num][i]);
	return cnt;
}

int main(int argc, char *argv[])
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n, m;
	cin >> n >> m;

	vector<vector<int> > v(n+1);
	while (m--) {
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	/*
	for(int i = 0;  i < v.size(); i++ ){
		cout << "v[" << i << "]:";
		for(int j = 0;  j < v[i].size(); j++ ){
			cout << v[i][j] << " ";	
		}	
		cout << endl;
	}
	*/
	int cnt = 0;
	for(int i=1; i <= n; i++) {
		if (solve(v, i) >= 1) cnt++;
	}
	cout << cnt;
	return 0;
}
