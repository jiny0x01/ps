#include <iostream>
using namespace std;

struct point{
	int x,y;
};

int main()
{
	using point = struct point;
	point p[3];
	char ck_x[1001]{0}, ck_y[1001]{0};
	int answer_x, answer_y;
	for(int i = 0; i < 3; i++){
		cin >> p[i].x >> p[i].y;
		ck_x[p[i].x]++;
		ck_y[p[i].y]++;
	}
	for(int i = 0; i < 1001; i++){
		if(ck_x[i] == 1) answer_x = i;
		if(ck_y[i] == 1) answer_y = i;
	}
	cout << answer_x << ' ' << answer_y << endl;	
	return 0;
}
