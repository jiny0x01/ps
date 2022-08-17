#include <iostream>
using namespace std;

long long int factorial(int num)
{
	long long int result = 1;
	for(int i = 1; i <= num; i++)
		result *= i;
	return result;
}

int main()
{
	int n,k;
	cin >> n >> k;

	cout << factorial(n) / (factorial(n-k) * factorial(k));
	return 0;
}
