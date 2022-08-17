#include <iostream>	
#include <string>
#include <utility>
#include <map>
#include <set>
using namespace std;


int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n,m;
	cin >> n >> m;
	map<string, int> s;

	string str;
	while (n--) {
		cin >> str;
		s.insert(make_pair(str,1));
	}
	while (m--) {
		cin >> str;
		if (s.find(str) != s.end()) {
			s[str]++;
		}
		else
			s.insert(make_pair(str, 1));
	}


	set<string> answer;
	int cnt = 0;
	for(const auto&itr : s) {
		if (itr.second == 2) {
			answer.insert(itr.first);
			cnt++;
		}
	}
	cout << cnt << "\n";
	for(const auto&itr : answer) {
		cout << itr << "\n";
	}
	return 0;
}
