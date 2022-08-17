#include <iostream>
using namespace std;

int quadrant(int x, int y) {
	if(x>0 && y>0) return 1;
	else if(x<0 && y>0) return 2;
	else if(x<0 && y<0) return 3;
	else if(x>0 && y<0) return 4;
}

int main() 
{
	int x,y;
	cin >> x >> y;
	cout << quadrant(x, y); 
	return 0;
}
