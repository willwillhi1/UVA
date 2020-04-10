#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,x,index;
	cin >> n;
	int ans[n+1] = {0};
	for(int i = 1;i <= n;i++){
		cin >> index;
		ans[index] = i;
	}
	while(cin >> x){
		int order[n+1] = {0};
		order[x] = 1;
		for(int i = 2;i <= n;i++){
			cin >> index;
			order[index] = i; 
		}
		int length[n+1][n+1];
		for(int i = 0;i <= n;i++)
			for(int j = 0;j <= n;j++)
				length[i][j] = 0;	
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= n;j++){
				if(ans[i] == order[j])
					length[i][j] = length[i-1][j-1] + 1;
				else{
					length[i][j] = max(length[i-1][j], length[i][j-1]);
				}
			}
		cout << length[n][n] << endl;
	}
	return 0;
}
