#include <iostream>
#include <vector>
#include <array>
using namespace std;

array<array<int, 101>, 101> arr;

// 1 3
// 1 4
// 3 2
// 4 5
// 4 3

void print_array(int n)
{
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}

int main(int argc, char *argv[])
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	while(m--) {
		int a,b;
		cin >> a >> b;
		arr[a][b] = b;
		arr[b][a] = a;
	}

	print_array(n);
	return 0;
}
