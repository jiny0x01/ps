#include <iostream>
#include <array>
using namespace std;

int main() 
{
	array<int, 101> arr;
	int n, m;
	cin.tie(0);
	cin.sync_with_stdio(false);

	cin >> n >> m;

	for(int i=0; i<n; i++){
		cin >> arr[i];
	}
	return 0;
}
