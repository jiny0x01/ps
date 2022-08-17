#include <iostream>
#include <string>
#include <set>
using namespace std;

void print_set(multiset<int>& s) {
	cout << "==set info\n";
	for(const auto& itr : s) {
		cout << itr << " ";
	}
	cout << "\n";
}

void solve(int k) {
	multiset<int> s;
	string str;
	int num;
	while(k--) {
		cin >> str >> num;
		if (str[0] ==  'I') {
			s.insert(num);
			continue;
		} 
		if (s.empty()) continue;
		else if (str[0] == 'D' && num == 1) {
			s.erase(prev(s.end()));
		} else if (str[0] == 'D' && num == -1) {
			s.erase(s.begin());
		}
//		print_set(s);
	}
//		print_set(s);
	if (s.empty()) {
		cout << "EMPTY\n";
	} else {
		cout << *prev(s.end()) << " " << *s.begin() << "\n";
	}
}

int main(int argc, char *argv[])
{
	int t,k;
	cin.tie(0);
	cin.sync_with_stdio(false);

	cin >> t;
	while (t--) {
		cin >> k;
		solve(k);
	}
	return 0;
}
