#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(int argc, char *argv[])
{
	int n,t;
	cin >> n;

	map<string, int> m;
	while(n--){
		int ans = 1;
		cin >> t;
		while(t--) {
			string name, type;
			cin >> name >> type;
			m[type]++;
		}
		for (const auto& [k, v] : m) {
			ans *= (v + 1);
		}
		ans--;
		cout << ans << "\n";
		m.clear();
	}
	return 0;
}
