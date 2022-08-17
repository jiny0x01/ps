#include <vector>
#include <iostream>
using namespace std;
int parent[202];

int find_parent(int n) {
	if (parent[n] == n) return n;
	return parent[n] = find_parent(parent[n]);
}

void union_parent(int x, int y) {
	int a = find_parent(x);
	int b = find_parent(y);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

int main(int argc, char *argv[])
{
	int n,L;
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> n >> L;

	vector<int> A(L),B(L);
	for(int i = 0; i < L; i++) {
		A[i] = 0;
		B[i] = 0;
	}
	for(int i = 0; i < n; i++) {
		int a,b;
		cin >>
	}
	return 0;
}
