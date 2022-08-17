#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;
char v[21][21];

int r,c;

bool check_range(int x, int y) {
//	cout << "x: " << x << ", y:" << y << "\n";
	return x < 0 || x >= c || y < 0 || y >= r;
}

int solution(array<bool,28> alpha, int x, int y) {
	if(check_range(x, y) or alpha[v[y][x]-'A']) return 0;

	alpha[v[y][x] - 'A'] = true;

	int result1 = 0, result2 = 0;
	result1 = max(solution(alpha, x+1, y), solution(alpha, x-1, y));
	result2 = max(solution(alpha, x, y+1), solution(alpha, x, y-1));
	//cout << "result: " << result1 << ", result2:" << result2 << endl;
	return max(result1, result2) + 1;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	cin >> r >> c;
	for(int i = 0; i < r; i++) {
		string temp;
		cin >> temp;
		for(int j = 0; j < temp.length(); j++){
			v[i][j] = temp[j];
		}
	}

	array<bool,28> alpha;
	alpha.fill(0);

	cout << solution(alpha,0, 0);
	return 0;
}
