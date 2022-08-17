#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(int argc, char *argv[])
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	stack<int> s;
	int i = 1;
	while(1) {
		int num;
		cin >> num;
		if (i < num) {
			s.push(i);
		}

		if (i == n) break;
		i++;
	}	
	return 0;
}

/*
 * 4 3 6 8  :8 6
 * 7 5 : 5
 * 2 1 : 1
 * */

/*
 *
+  + + + 
4 3 6 8
- -
 * */
