#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <queue>
#include <utility>
#include <chrono>
#include <thread>
#include <mutex>
#include <list>
#include <vector>
#include <string>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	string temp;
	int n;
	scanf("%d", &n);
	getchar();
	stack<char> _stack;
	for(int i = 0; i < n; i++){
		char ch;	
		do{
			scanf("%c", &ch);
			if(ch == ' '){
				while(!_stack.empty()){
					cout << _stack.top();
					_stack.pop();
				}
				cout << ' ';
			}
			else if(ch != '\n')
				_stack.push(ch);
		}while(ch != '\n');

		while(!_stack.empty()){
			cout << _stack.top();
			_stack.pop();
		}
		cout << endl;
			
	}
	return 0;
}
