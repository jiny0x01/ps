#include <iostream>
using namespace std;
char star[3100][6200];

// 삼각형은 좌하단부터 찍기
// 역삼각형은 좌상단부터 찍기

void init_blank(const int n) {
	for(int i=0; i<n; i++){
		for(int j=0; j<n*2; j++) {
			star[i+1][j+1] = ' ';
		}
	}
}

void star_template(const int sx, const int sy){
	for(int i=0; i<5; i++)
		star[sy][sx+i] = '*';
	for(int i=0; i<3; i++)
		star[sy-1][sx+1+i] = '*';
	star[sy-2][sx+2] = '*';
	star[sy-1][sx+2] = ' ';
}

void set_inverted_triangle_blank(const int n, const int sx, const int sy) {
	for(int i=0; i<n; i++) {
		for(int j=i; j<n*2-i-1; j++){
			star[sy+i][sx+j] = ' ';
		}
	}
}

void build_star(int n, const int sx, const int sy) {
	if(n==3){
		star_template(sx, sy);
		return;
	}

	// 좌삼각형
	build_star(n/2, sx, sy);
	// 빈 역삼각형
	set_inverted_triangle_blank(n/2, sx+n/2, sy-n/2+1);
	// 우삼각형
	build_star(n/2, sx+n, sy);
	// 윗삼각형
	build_star(n/2, sx+n/2, sy-n/2);
}

void print_star(const int n) {
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n*2-1; j++){
			cout << star[i][j];
		}
		cout << '\n';
	}
}

int main() {
	int n;
	cin >> n;
    
	init_blank(n);
	build_star(n, 1, n);
	print_star(n);
	return 0;
