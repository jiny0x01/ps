#include <iostream>
#include <string>
using namespace std;

int divide_parts(int n){
	int sum = 0;
	string str = to_string(n);
	for(auto& s : str)
		sum += s - '0';	
	return sum;
}
int main(){
	int n;
	cin >> n;
	int result = 0;
	for(int i = n/2; i < n; i++){
		if(i+divide_parts(i) == n) {
			result = i;	
			break;
		}
	}
	cout << result ;
	return 0;
}
