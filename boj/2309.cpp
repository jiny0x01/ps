#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int sum(vector<int>& v){
	int result = 0;
	for(const auto& i : v){
		result+=i;
	}
	return result;
}

void sum_is_100(vector<int>& v, const int vsum){

	for(int i=0;i<v.size()-1;i++){
		for(int j=i+1; j<v.size(); j++){
			if(vsum-v[i]-v[j]==100){
				for(const auto& itr : v){
					if(itr == v[i] || itr == v[j]) continue;
					cout << itr << '\n';
				}	
				return;
			}
		}
	}	
}

int main ()
{
	cin.tie(0);
	cin.sync_with_stdio(false);

	vector<int> v;
	for(int i=1;i<=9;i++){
		int temp;
		cin >> temp;
		v.push_back(temp);
	}

	int vsum = sum(v);
	sort(v.begin(), v.end());
	sum_is_100(v, vsum);
	return 0;
}
