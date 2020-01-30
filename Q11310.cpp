#include <iostream>

using namespace std;

int main(){
	int t;
	cin >> t;
	long long int ans[41] = {0};
	ans[0] = 0;
	ans[1] = 1;
	ans[2] = 5;
	ans[3] = 11;
	for(int i = 4;i < 41;i++){
		ans[i] = 2*ans[i-3] + 4*ans[i-2] + 1*ans[i-1];
	}
	while(t--){
		int n;
		cin >> n;
		cout << ans[n] << endl;
	}
}
