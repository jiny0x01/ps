#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

void cur_vector(vector<int>& v)
{
		cout << "vector\n";
	for(auto& itr : v)
	{
		cout << itr <<"  ";
	}
	cout << endl << endl;
}

void josephus(const int n, const int k)
{
	queue<int> v;

	// init
	for(int i = 1; i<=n; i++)
	{
		int num = i;
		v.push(num);
	}

	int temp;
	// kill
	cout << "<";
	while(v.size() > 0)
	{
		for(int i = 1; i < k; i++)
		{
			temp = v.front();
			v.pop();
			v.push(temp);
		}
		cout << v.front();
		v.pop();
		if (v.size() == 0)
		{
			cout << ">";
			break;
		}
		cout << ", ";
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	josephus(n, k);
	return 0;
}
