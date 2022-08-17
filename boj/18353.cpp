#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <utility>
#include <list>
#include <vector>
using namespace std;

int solve(vector<int>& v, int idx)
{
	if (idx == 0
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	int cnt;
	cin >> n;
	vector<int> v;
	while(n--)
	{
		int temp;
		cin >> temp;
		v.push_back(temp);
	} 
	cnt = 0; 
	int con = 0;
	for(auto it = v.begin(); it != v.end()-1;)
	{
		if (*it < *(it+1))
		{
			cnt++;
		}
		it++;
	}
	cout << cnt << endl;
	return 0;
}
