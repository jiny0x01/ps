#include <iostream>
#include <map>
#include <algorithm>
#include <utility>
#include <cctype>

using namespace std;

int main(int argc, char *argv[])
{
	int n,m;
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> n >> m;
	map<string, int> mp;
	map<int, string> np;
	
	string str;
	int i = 1;
	while(n--) {
		cin >> str;	
		mp.insert(make_pair(str, i));
		np.insert(make_pair(i++, str));
	}
	while (m--) {
		cin >> str;
		if (isdigit(str[0])) {
			i = stoi(str);
			cout << np[i] << "\n";
		}
		else {
			cout << mp[str] << "\n";
		}
	}
	return 0;
}
