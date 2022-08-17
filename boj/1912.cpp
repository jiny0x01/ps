#include <iostream>
#include <vector>
using namespace std;

int continuous_sum(vector<int>& v)
{
	int m = v[0];
	int d[100001];
	for(int i=0; i<v.size(); i++)
	{
		d[i] = v[i];
		if (i == 0) continue;
		if (d[i] < d[i-1] + v[i])
			d[i] = d[i-1] + v[i];
		m = max(m, d[i]);
	}
	return m;
}

int main()
{
	int n;
	cin >> n;
	
	vector<int> v;
	while(n--)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	cout << continuous_sum(v);
	return 0;
}
