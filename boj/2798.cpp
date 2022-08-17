#include <iostream>
#include <cstdlib>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

int black_jack(vector<int>& v, int m) {
	int sum = 0;
	int max = 0;
	for(int i = 0; i < v.size()-2; i++) {
		sum += v[i];
		for(int j = i+1; j < v.size()-1; j++) {
			sum += v[j];
			for(int k = j+1; k < v.size(); k++) {
				sum += v[k];
				if(sum <= m) {
					max = std::max(max, sum);
				}
				sum -= v[k];
			}
			sum -= v[j];
		}
		sum -= v[i];
	}
	return max;
}

int main() 
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n,m;
	vector<int> v;	
	cin >> n >> m;
	for(int i = 0; i<n; i++){
		int temp; cin >> temp;
		v.push_back(temp);
	}

	sort(v.begin(), v.end(), std::greater<int>());
	 
	cout << black_jack(v, m);
	return 0;
}
