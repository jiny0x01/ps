#include <iostream>
using namespace std;


int dalpang(int a, int b, int v){
	int day;
	v -= a;
	day = v / (a-b);
	if(v % (a-b) == 0) day++;
	else day+=2;
	return day; 
}
int main()
{
	int a ,b, v;
	cin >> a >> b >> v;
	
	cout << dalpang(a,b,v) << endl;
	return 0;
}
