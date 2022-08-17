#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n,m;
	int min_piece = 1001;
	int min_package = 1001;

	cin >> n >> m;
	for(int i=0; i<m; i++) {
		int package, piece;
		cin >> package >> piece;
		min_piece = min(min_piece, piece);
		min_package = min(min_package, package);
	}

	// n개 사야함 제일 싸게 맞출 수 있는 것은?
	int sum = 0;
	if(min_piece * 6 <= min_package){
		cout << min_piece * n << endl;
	}
	else {
		sum += (n/6 * min_package);
		n %= 6;
		if(n*min_piece > min_package)
			sum += min_package;
		else
			sum += n*min_piece;
		cout << sum << endl;
	}
	return 0;
}
