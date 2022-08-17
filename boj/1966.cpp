#include <queue>
#include <iostream>
#include <vector>
using namespace std;

void print_queue(queue<int> q) {
	while (!q.empty()) {
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}

void clear(queue<int>& q, priority_queue<int>& pq) {
	while (!q.empty()) {
		q.pop();
	}
	while (!pq.empty()) {
		pq.pop();
	}
}

int	solve(queue<int>& q, priority_queue<int>& pq, int priority) {
	int pop_doc = 0;
	while (!q.empty()) {
		if (q.front() == pq.top()) {
			q.pop();
			pq.pop();
			pop_doc++;
			if (priority == 0)
				break;
			priority--;
		}
		else {
			int num;
			num = q.front();
			q.pop();
			q.push(num);
			if (priority == 0)
				priority = q.size();
			priority--;
		}
	}	
	return pop_doc;
}

int main()
{
	int n;
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> n;

	queue<int> q;
	priority_queue<int> pq;
	vector<int> v;
	while (n--) {
		int doc_cnt, priority, num;
		cin >> doc_cnt >> priority;
		for (int i = 0; i < doc_cnt; i++) {
			cin >> num;
			q.push(num);
			pq.push(num);
		}
		cout << solve(q, pq, priority) << endl;
		clear(q, pq);
	}
}
