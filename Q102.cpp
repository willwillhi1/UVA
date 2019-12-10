#include <stdio.h>
#include <string.h>

using namespace std;
int a[3][3];
int count[6];

int dfs(int x,int y,int z){
	int c = 0;
	c = a[1][x] + a[2][x] + a[0][y] + a[2][y] + a[0][z] + a[1][z];
	return c;
}
int smallest(){
	int i,small = count[0],num = 0;
	for(i = 0;i < 6;i++){
		if(small > count[i]){
			small = count[i];
			num = i;
		}
	}
	return num;
}
int main(){
	int i,j,k;
	int one = 0;
	int index = 0;
	char array[10][10] = {
		"BCG",
		"BGC",
		"CBG",
		"CGB",
		"GBC",
		"GCB"
	};
	
	while(1){
		for(i = 0;i < 3;i++){
			scanf("%d %d %d",&a[i][one],&a[i][one+1],&a[i][one+2]);
			one = 0;
		}
			for(j = 0;j < 3;j++){
				for(k = 0;k < 2;k++){
					if(j == 0 && k == 0){
						count[1] = dfs(0,1,2);
					}
					else if(j == 0 && k == 1){
						count[0] = dfs(0,2,1);
					}
					else if(j == 1 && k == 0){
						count[2] = dfs(2,0,1);
					}
					else if(j == 1 && k == 1){
						count[3] = dfs(2,1,0);
					}
					else if(j == 2 && k == 0){
						count[4] = dfs(1,0,2);
					}
					else if(j == 2 && k == 1){
						count[5] = dfs(1,2,0);
					}
				}
			}
		index = smallest();
		printf(array[index]);
		printf(" %d\n", count[index]);
	}
	return 0;
}
