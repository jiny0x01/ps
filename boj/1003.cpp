#include <iostream>
#include <utility>
using namespace std;
pair<int, int>  f[41] = { {1,0}, {0, 1}};

pair<int, int> fibo(int n){
	if(n < 2) return f[n];
	else if(f[n].first && f[n].second) return f[n];
	//cout << n << ": " << f[n].first << ", " << f[n].second << endl;
	pair<int, int> num1 = fibo(n-1);
	pair<int, int> num2 = fibo(n-2);
	f[n] = make_pair(num1.first + num2.first, num1.second + num2.second);
	return f[n];
}

int main()
{
	int t,n;
	cin >> t;
	while(t--) {
		cin >> n;
		auto num = fibo(n);
		cout << num.first << ' ' << num.second << '\n';
	}
	return 0;
}
