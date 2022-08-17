#include <iostream>
using namespace std;

int main()
{
	int h,m;
	cin >> h >> m;
	int time = h*60 + m;

	if(time - 45 < 0) cout << "23 " << 60 - (45-m);
	else {
		cout << (time-45) / 60 << ' ' << (time-45) % 60;
	}
	return 0;
}
