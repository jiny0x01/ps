#include <iostream>
using namespace std;
int arr[1002];

int tile(int n){
	if(n == 0) return 0;
	if(n == 1){
		arr[n] = 1;
		return arr[n];	
	}
	if(arr[n]) return arr[n];
	else{
		arr[n] = ((tile(n-1)% 10007) +(tile(n-2) % 10007)) % 10007;

		return arr[n];
	}
}
int main(){

	int n;
	cin >> n;
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 2;
	/*
	for(int i = 3; i <= n; i++){
		arr[i] = arr[i-1] + arr[i-2];
	}
	cout<< arr[n];
	*/
	cout << tile(n) << endl;
	return 0;
}
