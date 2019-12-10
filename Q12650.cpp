#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int n,R,num,i,j;
	bool ndead[10000] = {false};
	while(scanf("%d %d",&n,&R) != EOF){
		//cout << n << " " << R << endl;
		for(j = 0;j < R;j++){
			scanf("%d",&num);
			//cout << num << endl;
			for(i = 1;i <= n;i++){
				if(ndead[num] == false){
					ndead[num] = true;
				}
			}
		}
		if(n == R){
			cout << '*' << endl;
		}
		else{
			for(i = 1;i <= n;i++){
				if(ndead[i] == false){
					cout << i << ' ';
				}
			}
			cout << endl;
		}
		for(i = 0;i < n;i++){
			ndead[i] = false;
		}
	}
}
