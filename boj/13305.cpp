#include <iostream>
#include <numeric>
#include <climits>
#include <algorithm>
#include <type_traits>
#include <vector>
using namespace std;


// roads -> 가야하는 길의 길이 
// prices[0] -> 맨 처음 주유할 가격

long long int get_cheapest_way(vector<long long int>& roads, vector<long long int>& prices) {
	long long int total_price = 0;
	long long int price = prices[0];
	for(int i = 1; i < roads.size(); i++) {
		// 다음 장소 기름값이 더 싸면
		if (price > prices[i]) {
			// 다음 장소까지 가기 위해 기름 넣고
			total_price += price * roads[i-1];
			// 앞으론 다음 장소 기름값 기준으로 셋팅
			price = prices[i];
		} else {
			// 다음 장소 기름값이 더 비싸면 젤 싼 곳 기준으로 기름 측정
			total_price += price * roads[i-1];
		}
	}
	total_price += price * roads[roads.size()-1];

	return total_price;
}

int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);

	long long int n;
	cin >> n;
	vector<long long int> roads;
	for(long long int i=0; i < n-1; i++) {
		long long int road; 
		cin >> road;
		roads.push_back(road);
	}
	vector<long long int> prices;
	for(long long int i=0; i < n-1; i++) {
		long long int price;
		cin >> price;
		prices.push_back(price);
	}
	long long int temp;
	cin >> temp;
	cout << get_cheapest_way(roads, prices);
	return 0;
}
