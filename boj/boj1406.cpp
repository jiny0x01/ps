#include <iostream>
#include <string>
#include <stack>
using namespace std;

void left2right(stack<char>& ls, stack<char>& rs){
	while(!ls.empty()){
		char temp = ls.top();
		rs.push(temp);
		ls.pop();
	}
}

void print_all(stack<char>& s){
	while(!s.empty()){
		cout << s.top();
		s.pop();
	}
}

void init(stack<char>& ls){
	string str;
	cin >> str;
	for(auto& s : str){
		ls.push(s);
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);

	stack<char> left_stack, right_stack;
	init(left_stack);

	int N;
	cin >> N;
	char instruct, temp;
	while(N--){
		cin	>> instruct;
		switch(instruct){
			case 'L':
				if(!left_stack.empty()){
					temp = left_stack.top();
					right_stack.push(temp);
					left_stack.pop();
				}
				break;
			case 'D':
				if(!right_stack.empty()){
					temp = right_stack.top();
					left_stack.push(temp);
					right_stack.pop();
				}
				break;
			case 'B':
				if(!left_stack.empty()){
					left_stack.pop();	
				}	
				break;
			case 'P':
				cin >> temp;
				left_stack.push(temp);
				break;
		}
	}

	left2right(left_stack, right_stack);
	print_all(right_stack);
	return 0;
}
