#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int d1[1002];
int d2[1002];

int increase(vector<int>& s, int n)
{
	int m = 1;
	for(int i = 0; i < n; i++)
	{
		d1[i] = 1;
		for(int j = 0; j < i; j++)
		{
			if (s[j] < s[i] && d1[i] < d1[j] + 1)
			{
				d1[i] = d1[j] + 1; 
				m = max(m, d1[i]);
			}
		}
	}
	return m;
}

int decrease(vector<int> s, int n) {
	reverse(s.begin(), s.end());
	int m = 1;
	for(int i = 0; i < n; i++)
	{
		d2[i] = 1;
		for(int j = 0; j < i; j++)
		{
			if (s[j] < s[i] && d2[i] < d2[j] + 1)
			{
				d2[i] = d2[j] + 1; 
				m = max(m, d2[i]);
			}
		}
	}
	return m;
}

int main()
{
	vector<int> s;
	int n;
	cin >> n;
	while(n--){
		int num;
		cin >> num;
		s.push_back(num);
	}
	increase(s, s.size());
	decrease(s, s.size());
	int result = 1;
	for(int i = 0; i < s.size(); i++)
		result = max(result, d1[i] + d2[s.size()-i-1]-1);
	cout << result;
	return 0;
}
