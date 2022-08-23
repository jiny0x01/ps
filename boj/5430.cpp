#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <sstream>
using namespace std;

deque<int> split(string numbers, char Delimiter) {
	if (numbers.size() == 0) {
		return deque<int>();
	}
	deque<int> v;
	string buffer;

	istringstream iss(numbers);
	while(getline(iss, buffer, Delimiter)) {
		v.push_back(atoi(buffer.c_str()));
	}
	return v;
}

// vector로하면 시간 부족함
void AC(deque<int>& numbers, const string& command) {
	bool err = false;
	bool r_flag = false;	// reverse flag. false -> left to right, true -> right to left
	for(const auto& c : command) {
		switch(c) {
			case 'R': // reverse
				r_flag = !r_flag;
				break;
			case 'D': // drop
				if (numbers.empty()) {
					err = true;
				} else {
					if (r_flag) {
						numbers.pop_back();
			//			numbers.erase(numbers.end()-1);
					} else {
						numbers.pop_front();
//						numbers.erase(numbers.begin());
					}
				}
				break;
		}
		if (err) {
			break;
		}
	}
	if (err) {
		cout << "error\n";
	} else {
		cout << "[";
		if (r_flag) {
			if (!numbers.empty()) {
				for(int i = numbers.size()-1; i > 0; i--) {
					cout << numbers.back() << ",";
					numbers.pop_back();
				//	cout << numbers[i] << ",";
				}
				cout << numbers.back();
//				cout << numbers[0];
			}

		} else {
			if (!numbers.empty()) {
				int size = numbers.size();
				for(int i = 0; i < size-1; i++) {
					cout << numbers.front() << ",";
					numbers.pop_front();
					//cout << numbers[i] << ",";
				}
				cout << numbers.front();
//				cout << numbers[numbers.size()-1];
			}
		}
		cout << "]\n";
	}
}
int main() {
	cin.tie(0);
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		string command;
		cin >> command;

		int n;
		cin >> n;

		string num_arr;
		cin >> num_arr;

		num_arr = num_arr.substr(1, num_arr.size()-2);
		auto numbers = split(num_arr, ',');
		AC(numbers, command);
		numbers.clear();
	}
	return 0;
}
