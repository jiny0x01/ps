#include <iostream>	
#include <bitset>
using namespace std;

constexpr int get_int_size() {
	return sizeof(int) * 8;
}

void print_bin(int num)
{
	bool arr[32]{0,};
	int i = 0;
	while (num > 1) {
		if (num % 2 == 1)
			arr[i] = 1;
		else 
			arr[i] = 0;
		num /= 2;
		i++;
	}

	if (num % 2)
		arr[i] = 1;
	else
		i--;
	
	while(i >= 0) {
		if (arr[i] == 1)
			cout << 1;
		else
			cout << 0;
		i--;
	}
		
}

int main()
{
	int n;
	cin >> oct >> n;
	if (n == 0)
		cout << 0 << endl;
	else
		print_bin(n);
	return 0;
}

