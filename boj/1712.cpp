#include <iostream>
using namespace std;

int main()
{
	int a,b,c;
	cin >> a >> b >> c;
	int stat = a;
	int cnt = 0;
	if(b >= c) cnt = -1;
	else{
		cnt = a / (c-b) + 1;
	}
	cout << cnt;
	return 0;
	
	// (a + b*x) / c >= 0, x ? 
}
