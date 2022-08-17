#include <iostream>
#include <cmath>
using namespace std;

const int param = 2;
const int div_value = pow(10, 9) + 7;

long long int derivative(int coefficient, int degree) 
{
	long long int result = coefficient * degree * pow(param,(degree-1));
	return result % div_value;
}

int main()
{
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 0; i < n; i++)
	{
		int coe, deg;
		cin >> coe >> deg;
		if (deg == 0 || coe == 0)
			continue;
		sum += derivative(coe, deg);
	}
	cout << sum;
	return 0;
}
