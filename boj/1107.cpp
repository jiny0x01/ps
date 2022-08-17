#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

bool broken[11]={false};

int get_channel_length(int channel) {
	string chnl = to_string(channel);
	return chnl.size();
}

bool check(int n) {
	while(n >= 10) {
		if(broken[n%10] == true) {
			return false;
		}	
		n /= 10;
	}
	if(broken[n] == true) {
		return false;
	}
	return true;
}

int top_down(int target_channel) {
	cout << "top_donw==========\n\n\n";
	int click_cnt = 1000000;
	for(int k = target_channel; k <= 1000001;k++) {
		cout << "K: " << k << endl;
		if(check(k)){
			click_cnt = k - target_channel;
			click_cnt += get_channel_length(k);
			break;
		}
	}	
	cout << "top_down: " << click_cnt << ", target_channel: " << target_channel << endl;
	return click_cnt;
}

int bottom_up(int target_channel) {
	cout << "bottom_up==========\n\n\n";
	int click_cnt = 2000000;
	for(int k = target_channel; k >= 0; k--) {
		cout << "K: " << k << endl;
		if(check(k)){
			click_cnt = target_channel - k;
			click_cnt += get_channel_length(k);
			break;
		}
	}	
	cout << "bottom_up: " << click_cnt << ", target_channel: " << target_channel << endl;
	return click_cnt;
}

int click(int cur_channel, int target_channel) {
	cout << "click only: " << abs(cur_channel - target_channel) << endl;
	return abs(cur_channel - target_channel);
}


int main(int argc, char *argv[])
{
	// 채널의 최소는 0, 기본 100
	int n;  // 목표 채널
	int m; // 고장난 채널 개수
	int channel = 100;
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> n >> m; 
	

	for(int i = 0; i < m; i++){
		int temp;
		cin >> temp;
		broken[temp] = true;
	}

	if(n == channel) {
		cout << 0;
	}
	else {
		int td = top_down(n);
		int bu = bottom_up(n);
		int c = click(channel, n);
		int ans = min(min(td, bu), c); 

		cout << ans << endl;
	}
	return 0;
}
