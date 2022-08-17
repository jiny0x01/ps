#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <set>

#define LOTTOT_SIZE 6
using namespace std;


void print_vector(vector<int>& v){
	cout << "current status=====\n";
	for(const auto& itr : v){
		cout << itr << ' ';
	}
	cout << "\n==================\n";
}

void lotto(vector<int>& nums, vector<int> lto){
	if(lto.size() == LOTTOT_SIZE){
		print_vector(lto);
		auto it = lto.end();
		lto.erase(it);
		
		auto it2 = find(nums.begin(), nums.end(), it);
		if(it2 == nums.end()) cout << *it << " not found\n";
		
		for(; it2 != nums.end(); it2++){
			lotto(nums, loto);
		}
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	int k;
	vector<int> nums, lto;
	cin >> k;
	for(int i = 0;i<k;i++){
		int temp;
		cin >> temp;
		nums.push_back(temp);
		// function
	}
		

	lotto(nums,lto);
	return 0;
}
