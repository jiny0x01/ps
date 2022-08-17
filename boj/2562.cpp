#include <iostream>
using namespace std;

int main()
{
	int idx = 0;
	int _max = 0;	
	int temp = 0;
	for(int i = 0; i < 9; i++){
		int input;
		cin >> input;
		
		temp = _max;
		_max = max(input, _max);

		if(temp != _max) idx = i+1;
	}
	cout << _max << endl;
	cout << idx << endl;
	return 0;
}
