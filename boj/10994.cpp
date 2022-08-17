#include <iostream>
#include <cstdlib>
using namespace std;
#define MAX_SIZE 400
char _map[MAX_SIZE][MAX_SIZE];

// 4씩 늘어남
// 1: 1
// 2: 5,5
// 3: 9,9
// 4: 13,13
// 100: 4(99)+1 397
// n: 4(n-1)+1, 4(n-1)+1

void init_map(const int alloc_size) {
	for(int i=1; i<=alloc_size; i++){
		memset(_map[i], ' ', sizeof(char)*alloc_size);	
	}
}

void print_map(const int alloc_size) {
	for(int i=1; i<=alloc_size; i++){
		for(int j=1; j<=alloc_size; j++){
			cout << _map[i][j];
		}
		cout << '\n';
	}
}

void setup(int n, const int x, const int y) {
	if(n < 1) return;
	if(n == 1) {
		_map[y][x] = '*';
		return;
	}
	int size = 4*(n-1)+1;
	for(int i = 0; i<size; i++) {
		//상단 
		_map[y][x+i] = '*';
		//하단
		_map[y+size-1][x+i] = '*';
		//죄측
		_map[y+i][x] = '*';
		//우측
		_map[y+i][x+size-1] = '*';
	}
	setup(n-1, x+2, y+2);
}

int main() 
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;

	const int alloc_size = 4*(n-1)+1;

	init_map(alloc_size);
	setup(n, 1, 1);
	print_map(alloc_size);
	return 0;
}
