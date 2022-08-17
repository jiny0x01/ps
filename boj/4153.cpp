#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int a,b,c;
	while(1){
		cin >> a >> b >> c;
		if(a == 0 || b == 0 || c == 0) break;
		int _max = a > b ? a : b;
		_max = _max > c ? _max : c;
		bool is_triangle = false;	
		if(a == _max) 
			is_triangle = pow(a,2) == (pow(b,2) + pow(c,2)) ? true : false;
		else if(b == _max) 
			is_triangle = pow(b,2) == (pow(a,2) + pow(c,2)) ? true : false;
		else if(c == _max) 
			is_triangle = pow(c,2) == (pow(a,2) + pow(b,2)) ? true : false;
		if(is_triangle)
			cout << "right\n";
		else cout << "wrong\n";
	}
	return 0;
}
