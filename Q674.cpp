#include <iostream>

using namespace std;

int main(){
	int ans[7490] = {0};
	int coin[5] = {1,5,10,25,50};
	int input;
	ans[0] = 1;
	for(int i = 0;i < 5;i++)
		for(int j = coin[i];j < 7490;j++)
			ans[j] += ans[j-coin[i]];
	while(cin >> input){
		cout << ans[input] << endl;	
	}
}
