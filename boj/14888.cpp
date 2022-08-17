#include <iostream>
#include <queue>
#include <array>
#include <tuple>
using namespace std;

using Operator = struct Operator{
	int plus = 0;
	int minus = 0;
	int multiple = 0;
	int divide = 0;
};

int g_min = INT_MAX, g_max = INT_MIN;

void print_queue(queue<int> a) {
	cout << "queue:<";
	while (!a.empty()) {
		cout << a.front() << " ";
		a.pop();
	}
	cout << ">\n\n";
}

void DFS(queue<int>& a, Operator& op, int v) {
	//print_queue(a);
	//cout << "v:" << v << endl;
	if (a.empty()) {
		g_max = std::max(g_max, v);
		g_min = std::min(g_min, v);
		return;
	}
	queue<int> next_a = a;
	int num = next_a.front();
	next_a.pop();
	if (op.plus) {
		//cout << "plus\n";
		int next_v = v;
		Operator next_op = op;
		next_op.plus--;
		next_v += num;
		DFS(next_a, next_op, next_v);
	}
	if (op.minus) {
		//cout << "minus\n";
		int next_v = v;
		Operator next_op = op;
		next_op.minus--;
		next_v -= num;
		DFS(next_a, next_op, next_v);
	}
	if (op.multiple) {
		//cout << "multiple\n";
		int next_v = v;
		Operator next_op = op;
		next_op.multiple--;
		next_v *= num;
		DFS(next_a, next_op, next_v);
	}
	if (op.divide) {
		//cout << "divide\n";
		int next_v = v;
		Operator next_op = op;
		next_op.divide--;
		next_v /= num;
		DFS(next_a, next_op, next_v);
	}
}


int main(int argc, char *argv[])
{
	cin.tie(0);
	cin.sync_with_stdio(false);

	int n;
	queue<int> a;
	Operator oper;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		a.push(temp);
	}
	cin >> oper.plus >> oper.minus >> oper.multiple >> oper.divide;
	int num = a.front();
	a.pop();
	DFS(a, oper, num);
	cout << g_max << "\n" << g_min;
	return 0;
}
