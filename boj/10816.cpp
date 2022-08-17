#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);

	unordered_map<int, int> card;	
	int n;

	cin >> n;

	for(int i=0; i<n; i++)
	{
		int num;
		cin >> num;
		card[num]++;
	}

	int m;

	cin >> m;
	for(int i=0;i<m;i++)
	{
		int num;
		cin >> num;
		cout << card[num] << " ";
	}


	return 0;
}
