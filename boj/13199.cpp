#include <iostream>
using namespace std;

int chicken(int p, int m, int f, int c) {
	int doyoung = m/p; // 기본
	const int coupon = m/p*c;
	int sang = doyoung;  // 단골
	doyoung += coupon / f;

	if(coupon >= f) {
		sang += (coupon - f) / (f-c) + 1;
	}
	
	cout << "sang : " << sang  << ", dnagol: " << doyoung << endl;

	return sang-doyoung;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int t;
	cin >> t;

	int p,m,f,c;
	while(t--){
		cin >> p >> m >> f >> c;
		cout << chicken(p,m,f,c) << '\n';
	}
	return 0;
}
