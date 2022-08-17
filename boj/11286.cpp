#include <iostream>
#include <queue>
#include <cstdio>
#include <utility>
#include <cmath>
using namespace std;

typedef struct {
	int origin;
	int abs;
} num;

struct compare {
	bool operator()(const num& n1, const num& n2) {
		if (n1.abs == n2.abs) {
			return n1.origin > n2.origin;
		}
		return n1.abs > n2.abs;
	}
};

int main() {
	int n;
	scanf("%d", &n);
	priority_queue<num, vector<num>, compare> pq;
	while(n--) {
		int x;
		scanf("%d", &x);
		if (x == 0) {
			if (pq.empty()) {
				printf("0\n");
			} else {
				printf("%d\n", pq.top().origin);
				pq.pop();
			}
		}  else {
			pq.push(num{x, abs(x)});
		}
	}
	return 0;
}
