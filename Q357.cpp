#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int coin[5] = {1,5,10,25,50};
	int ans[30001] = {0},n;
	ans[0] = 1;
	for(int i = 0;i < 5;i++){
		for(int j = coin[i];j < 30001;j++){
			ans[j] += ans[j-coin[i]];
		}
	}
	while(cin >> n){
		if(ans[n] == 1)
			cout << "There is only 1 ways to produce " << n << " cents change." << endl;
		else
			cout << "There are " << ans[n] << " ways to produce " << n << " cents change." << endl;
	}

