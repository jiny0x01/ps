#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int d[1002];

int solution(vector<int>& s, int n) {
	int m = 1;
	for(int i = 0; i < n; i++)
	{
		d[i] = 1;
		for(int j = 0; j < i; j++)
		{
			if (s[j] < s[i] && d[i] < d[j] + 1)
			{
				d[i] = d[j] + 1; 
				m = max(m, d[i]);
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
	cout << solution(s, s.size()) << endl;
	return 0;
}
