#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


using pos = struct pos {
	int x = 0, y = 0;
};

bool compare(const pos& p1, const pos& p2)
{
	if (p1.y == p2.y)
		return p1.x < p2.x;
	return p1.y < p2.y;
}

int main(int argc, char *argv[])
{
	int n;
	cin >> n;
	vector<pos> ps;

	for(int i = 0; i < n; i++)
	{
		pos p;
		cin >> p.x >> p.y;
		ps.push_back(p);
	}

	sort(ps.begin(), ps.end(), compare);
	for(const auto& p : ps)
	{
		cout << p.x << " " << p.y << "\n";
	}
	return 0;
}
