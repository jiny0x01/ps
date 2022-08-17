#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);

	int num;
	long long int result = 0;
	long long int mul = 1;
	const long long int mod = 1234567891;
	cin >> num;
	for(int i = 0; i < num; i++)
	{
		char ch;
		cin >> ch;
		int temp = ch - ('a'-1);
		result += (temp * mul) % mod;
		mul *= 31;
		mul %= mod;
	}
	cout << result;
}
