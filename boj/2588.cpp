#include <iostream>
using namespace std;

int main()
{
	// for easy_use
	int input1[3];
	int input2[3];

	// raw num
	int input1_raw = 0;
	int input2_raw = 0;

	int k = 1;
	for(int i = 0; i < 3; i++)
		scanf("%1d", &input1[i]);

	for(int i = 3; i > 0; i--){
		input1_raw += input1[i-1] * k;
		k *= 10;
	}

	k = 1;

	for(int i = 0; i < 3; i++)
		scanf("%1d", &input2[i]);
	for(int i = 3; i > 0; i--){
		input2_raw += input2[i-1] * k;
		k *= 10;
	}

	for(int i = 3; i > 0; i--){
		cout << input1_raw * input2[i-1] << endl; 
	}
	cout << input1_raw * input2_raw << endl;
	return 0;
}
