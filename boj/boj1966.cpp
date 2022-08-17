#include <iostream>
#include <list>
#include <vector>
#include <queue>
using namespace std;


struct compare  
{  
	bool operator()(const pair<int, int>& l, const pair<int, int>& r)  
	{  
	   return l.first < r.first;  
	}  
};  

priority_queue<pair<int, int>, vector<pair<int, int>>, compare> printer;


int main(void){
	int N;
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> N;
	int arr[11]{0};
	int num, pos, target;
	for(int i = 0; i < N; i++){
		// doc 개수, 위치
		cin >> num >> pos;

		for(int j = 0; j < num; j++){
			int pri;
			// 우선순위 삽입
			cin >> pri;	
			printer.push(make_pair(pri, -j));
		}

		cout << "printer ---\n";
		while(!printer.empty()){
			cout << '[' << printer.top().first<< ',' << printer.top().second << "] ";
			printer.pop();
		}
		cout << endl;
	}


	return 0;
}
