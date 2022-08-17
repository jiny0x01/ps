#include <iostream>
using namespace std;


bool dp[10000002];

bool is_prime(int n) {
	int i = 2;
	if (dp[n]) return true;
	for(;i*i <= n; i++) {
		if (n % i == 0) {
			return false;
		}
	}
	dp[n] = true;
	return true;
}

void prime(int n) {
	if (n < 2) return;

	for(int i = 2; i <= n; i++) {
		if (n % i == 0) {
			if (!is_prime(i)) {
				continue;
			}
			cout << i << "\n";
			prime(n/i);
			break;
		}
	}
}

int main(int argc, char *argv[])
{
	cin.tie(0);
	cin.sync_with_stdio(false);

	int n;
	cin >> n;
	prime(n);
	return 0;
}
