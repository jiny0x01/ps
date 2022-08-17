#include <iostream>
#include <array>
using namespace std;

int main()
{
	int n;
	int _min = 1000001, _max = -1000001;
	cin >> n;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		_min = std::min(temp, _min);
		_max = std::max(temp, _max);
	}
	cout << "min: " << _min << endl;
	cout << "max: " << _max << endl;
	return 0;
}
