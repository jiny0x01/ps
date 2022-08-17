#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

using person = struct person {
	int w, h;
};

bool compare_weight(const person& p1, const person& p2)
{
	return p1.w < p2.w ? true : false;
}

bool compare_height(const person& p1, const person& p2)
{
	return p1.h < p2.h ? true : false;
}



int main()
{
	cin.sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	vector<person> persons;
	for(int i=0; i<n; i++)
	{
		person temp;
		cin >> temp.w >> temp.h;
		persons.push_back(temp);
	}

	int last = 1;
	vector<int> v;	
	for(int i=0; i < n; i++)
	{
		v.push_back(1);
		for(int j=0; j < n; j++)
		{
			if (j == i)
				continue;
			if ((compare_weight(persons[i], persons[j]) && 
				  compare_height(persons[i], persons[j])))
			{
				v[i]++;
			}
		}
	}

	for(auto &itr : v)
	cout << itr << " ";
	cout << endl;
	return (0);
}
