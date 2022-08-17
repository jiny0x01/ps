#include <iostream>
#include <cstring>
#include <string>

using namespace std;

bool is_palindrome(const string& str)
{
	if (str.size() & 1) { // odd
		for(int i = 0; i < str.size()/2; i++){
			if (str[i] != str[str.size()-1-i])
				return false;
		}
		return true;
	} else {
		for(int i = 0; i < str.size()/2; i++){
			if (str[i] != str[str.size()-1-i])
				return false;
		}
		return true;
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	string str;
	while(1)
	{
		cin >> str;
		if (str == "0")
			break;
		if (is_palindrome(str))
			cout << "yes\n";
		else
			cout << "no";
	}
	return 0;
}
