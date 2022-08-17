#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int avg(vector<int>& nums){
	double _result = 0.0f;
	for(const auto& num : nums){
		_result += num;
	}

	return static_cast<int>(_result / nums.size());
}

int midian(vector<int> nums){
	sort(nums.begin(), nums.end());	
	if(nums.size() & 1){
		return nums[nums.size()/2];
	}	
	int _avg = nums[nums.size()/2-1] + nums[nums.size()/2];
	return _avg;
}

int most(vector<int>& nums){
	map<int, int> m;
	for(const auto& n : nums)
	{
		m[n]++;
	}
	auto it = m.rbegin();
	if (m.size() > 1)
	{
		auto it2 = m.rbegin();
		it2++;
		if (it->second == it2->second)
			return it2->first;
	}
	return it->first;
}
	
int max_sub_min(vector<int>& nums){
	const auto [min,max] = minmax_element(nums.begin(), nums.end());
	int result = *max - *min;
	return result;
}
int main()
{
	vector<int> nums;
	int n;
	cin >> n;
	for(int i = 0; i<n; i++){
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	cout << avg(nums) << endl;
	cout << midian(nums) << endl;
	cout << most(nums) << endl;
	cout << max_sub_min(nums) << endl;
	return 0;
}
