#include <iostream>
using namespace std;
long long int f[91] = {0,1,1};

long long int  fibo(int n, int& zero_cnt, int& one_cnt){
	if(f[n] == 0) {
		zero_cnt++;
		return 0;
	}
	else if(f[n] == 1){
		one_cnt++;
		return 1;
	}
	if(f[n]) {
		return f[n];
	}
	return fibo(n-1, zero_cnt, one_cnt) + fibo(n-2, zero_cnt, one_cnt);
}

int main()
{
	int n;
	int zero_cnt = 0;
	int one_cnt = 0;
	cin >> n;
	for(int i = 0; i < n; i++){
		zero_cnt = 0;
		one_cnt = 0;
		int num;
		cin >> num;
		fibo(num, zero_cnt, one_cnt);
		cout << zero_cnt << ' ' << one_cnt << endl;	
	}
	return 0;
}
