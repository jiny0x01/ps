#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

inline int front_walk(int n) {
	return n+1;
}

inline int back_walk(int n) {
	return n-1;
}

inline int teleport(int n) {
	return n*2;
}

int visit[100001] {0};

int solve(queue<int>& q, int k, int cur) {
	// q is 3
	queue<int> next;
//	cout << "cur: " << cur << endl;
	while (!q.empty()) {
		int n = q.front();
		if (n < 0 || n > 100000 || visit[n]) {
			q.pop();
			continue;
		}
		if (n == k)
			return cur;
		visit[n] = cur;
		next.push(n);
//		cout << "front:" << n << endl;
		q.pop();
	}
	while(!next.empty()) {
		int n = next.front();
		q.push(front_walk(n));
		q.push(back_walk(n));
		q.push(teleport(n));
		next.pop();
	}
	return solve(q, k, cur+1);
}

int main(int argc, char *argv[])
{
	int n,k;
	cin >> n >> k;

	if (n==k) cout << 0;
	else {
		queue<int> q;
		q.push(front_walk(n));
		q.push(back_walk(n));
		q.push(teleport(n));
		cout << solve(q, k, 1);
	}
	return 0;
}
