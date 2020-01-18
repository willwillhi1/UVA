#include <iostream>
#include <sstream>

using namespace std;

int main(){
	int T,W,N;
	cin >> T;
	while(T--){
		cin >> W >> N;
		bool map[100][100] = {0};
		int dp[100][100] = {0};
		cin.ignore();
		string str;
		for(int i=1,j;i <= W;i++){
			getline(cin, str);
			stringstream ss;
			ss << str;
			ss >> j;
			while(ss >> j){
				map[i][j] = true;
			}
		}
		dp[1][1] = 1;
		for(int i=1;i <= W;i++){
			for(int j=1;j <= N;j++){
				if(map[i][j] == true) continue;
				dp[i][j] += dp[i][j-1] + dp[i-1][j];
			}
		}
		/*
		for(int i = 0;i <= W;i++){
			for(int j = 0;j <= N;j++){
				cout << dp[i][j] << " ";
				
			}
			cout << endl;
		}
		*/
		cout << dp[W][N] << endl;
	}
	return 0;
}
