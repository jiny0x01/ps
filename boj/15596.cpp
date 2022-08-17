#include <iostream>
#include <vector>
using namespace std;

long long sum(std::vector<int>& a){
	long long s = 0;
	for(const auto& num : a){
		s += num;
	}
	return s;
}
