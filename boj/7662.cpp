#include <iostream>
#include <queue>
#include <string>
using namespace std;

void show_queue1(priority_queue<int, vector<int>, greater<int>> pq) {
	while(!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}
void show_queue2(priority_queue<int, vector<int>, less<int>> pq) {
	while(!pq.empty()) {
		cout << pq.top() << " ";
		pq.pop();
	}
	cout << endl;
}

void solve(int k) {
	priority_queue<long long, vector<long long>, greater<long long>> pq1;
	priority_queue<long long, vector<long long>, less<long long>> pq2;
	long long cnt = 0;
	string str;
	long long num;
	while (k--) {
		cin >> str >> num;
		if (str[0] == 'I') { //insert 
			cnt++;	
			pq1.push(num);
			pq2.push(num);
		} else if (cnt) {
			if (num == 1) {
				pq2.pop();
				cnt--;
			}
			else if (num == -1) {
				pq1.pop();
				cnt--;
			}
			if (cnt == 1) {
				if (pq1.size() == 1) {
					while (!pq2.empty())
						pq2.pop();
					pq2.push(pq1.top());
				} else {
					while (!pq1.empty())
						pq1.pop();
					pq1.push(pq2.top());
				}	
			}
		}
		if (cnt == 0) {
			while (!pq1.empty())
				pq1.pop();
			while (!pq2.empty())
				pq2.pop();
		}
//		show_queue1(pq1);
//		show_queue2(pq2);
	}
//	cout << "cnt:" << cnt << "\n";

	if (cnt == 0) {
		cout << "EMPTY\n";
	} else {
		cout << pq2.top() << " " << pq1.top() << "\n";
	}
}

int main(int argc, char *argv[])
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int t, k;
	cin >> t;

	while (t--) {
		cin >> k;
		solve(k);
	}
	return 0;
}
