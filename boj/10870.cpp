#include <iostream>
using namespace std;

int fibos[21] = {0,1,1,2};
int fibo(int n) {
	if(fibos[n]) return fibos[n];
	fibos[n] = fibo(n-1) + fibo(n-2);
	return fibos[n];
}
int main()
{
	int n;
	cin >> n;
	if(n == 0) cout << '0';
	else cout << fibo(n);
	return 0;
}
