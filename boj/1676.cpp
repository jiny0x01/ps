#include <iostream>
using namespace std;

int main()
{
	int n;
	cin.tie(0);
	cin.sync_with_stdio(false);

	cin >> n;
	int zcnt = 0;
	while(n > 0) {
		n /= 5;
		zcnt+=n;
	}
	cout << zcnt << endl;
	return 0;
}
