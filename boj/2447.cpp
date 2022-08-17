#include <iostream>
using namespace std;
char star[2500][2500];

void star_template(const int sx, const int sy){
	for(int i = 0; i < 3; i++) 
		star[sy][sx+i] = '*';
	for(int i = 0; i < 3; i++) 
		star[sy+1][sx+i] = '*';
	for(int i = 0; i < 3; i++) 
		star[sy+2][sx+i] = '*';
	star[sy+1][sx+1] = ' ';	
}

void set_blank(const int n, const int sx, const int sy) {
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++){
			star[sy+i][sx+j] = ' ';
		}
	}
}	


void build_star(int n, const int sx, const int sy) {
	if(n==3){
		star_template(sx, sy);
		return;
	}	
	
	// 상단
	for(int i=0; i<3; i++) {
		build_star(n/3, sx+(i*(n/3)), sy);
	}	
	// 중단
	for(int i=0; i<3; i++) {
		if(i==1)
			set_blank(n/3, sx+(i*(n/3)), sy+(n/3));	
		else
			build_star(n/3, sx+(i*(n/3)), sy+(n/3));
	}	
	// 하단
	for(int i=0; i<3; i++) {
		build_star(n/3, sx+(i*(n/3)), sy+(n/3)*2);
	}	
}

void print_star(const int n) {
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout << star[i][j];
		}
		cout << '\n';
	}
}

int main() {
	int n;
	cin >> n;
	build_star(n, 1, 1);
	print_star(n);	
	return 0;
}
