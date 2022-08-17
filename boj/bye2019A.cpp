#include <iostream>
using namespace std;

int process1(int m) {
	return ('l' - 'a') * m;	
}
int solution(int n, int m) {
	if(n < 12) return -1;
	if(m < 4) return -1;
	int result = process1(m) + 4;
	return result;
}

int main()
{
	int t,n, m;
	cin >> t;
	while(t--) {
		cin >> n >> m;
		cout << solution(n, m ) << endl;
	}

	return 0;
}
