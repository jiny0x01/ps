#include <iostream>
#include <utility>
#include <vector>
using namespace std;
int board[9][9];

int check_x(int y, int data)
{
	for(int j = 0; j < 9; j++)
	{
		if (board[y][j] == data) return (0);
	}
	return (1);
}

int check_y(int x, int data) { 
	for(int i = 0; i < 9; i++)
	{
		if (board[i][x] == data)
			return (0);
	}
	return (1);
}

pair<int, int> get_area(int y, int x)
{
	return  make_pair(y / 3 * 3, x / 3 * 3);
}

vector<int> get_area_empty_num(int y, int x)
{
	vector<int> v;
	bool arr[10];
	auto p = get_area(y, x);
//	cout << "find area===\n";
//	cout << "x: " << p.second << ", y: " << p.first << endl;
	for(int i = 1; i <= 9; i++)
		arr[i] = 1;
	for(int i = p.first; i < p.first + 3; i++)
	{
		for(int j = p.second; j < p.second + 3; j++)
		{
			if (board[i][j])
			{
				arr[board[i][j]] = 0;
			}
		}
	}
	for(int i = 1; i <= 9; i++)
		if (arr[i])
			v.push_back(i);
	return v;
}

// pair<i, j>
int sdoku(vector<pair<int, int> > v)
{
	if (v.size() == 0)
		return (1);
//	cout << "남은 좌표======\n";
//	for(const auto& i : v)
//		cout << "[y: " << i.first << ", x: " << i.second << "]\n";
//	cout << "===============\n";
	// v = detph
	int i = v[0].first; 
	int j = v[0].second;
	v.erase(v.begin());
//	cout << "현재 x: " << j << ", y: :" << i << endl;

	// board[i][j] 에 들어갈 수 잇는 벡터
	vector<int> num = get_area_empty_num(i, j);

//	cout << "board[" << i << "][" << j << "] can nums:";
//	for(const auto& i : num)
//		cout << i << " ";
//	cout << "\n";

	for(int idx = 0; idx < num.size(); idx++)
	{
		if (!check_x(i, num[idx]) || !check_y(j, num[idx]))
			continue;
		board[i][j] = num[idx];
//		cout << "board[" << i << "][" << j << "] = " << num[idx] << endl;
		if (sdoku(v))
			return (1);
		board[i][j] = 0;
//		cout << "fail board[" << i << "][" << j << "] = " << num[idx] << endl;
	}
//	cout << "========상위 depth로 올라갑니다.=========\n\n";
	return (0);
}

void print_board()
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << "\n";
	}
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(false);
	vector<pair<int, int> > v;
	for(int i = 0; i < 9; i++) {
		for(int j = 0; j < 9; j++) {
			cin >> board[i][j];
			if(board[i][j] == 0)
			{
				v.push_back(make_pair(i, j));
			}
		}
	}	

//	cout << "0 위치 ===========\n";
//	for(const auto& i : v)
//		cout << "[x: " << i.second << ", y: " << i.first << "]\n";
//	cout << endl << endl;

	sdoku(v);
	print_board();
	return 0;
}
