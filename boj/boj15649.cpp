#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int print_document(priority_queue<int> doc, int value){
	int cnt = 1;
	while(doc.top() != value){
		cnt++;
		doc.pop();
	}
	return cnt;
}
int main(int argc, char *argv[])
{
	int N;
	cin.tie(0);
	cin.sync_with_stdio(false);

	cin >> N;
	int temp;
	for(int i=0; i < N; i++){
		int doc_cnt, doc_pos;
		priority_queue<pair<int,int> document;
		cin >> doc_cnt >> doc_pos;
		int target;
		
		for(int j=0; j < doc_cnt; j++){
			int pri;
			cin >> pri;
			if(j == doc_pos) target = pri;
			document.push(pri);
		}
		cout << print_document(document, target) << endl;
		
	}


	return 0;
}
