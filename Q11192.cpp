#include <stdio.h>
#include <string.h>

using namespace std;
char b[100];
void reverse(){
	int len = strlen(b),i;
	for(i = len-1;i >= 0;i--){
		printf("%c", b[i]);
	}
}

int main(){
	int group_num,groups,i,j,len;
	char a[100];
	while(1){
		scanf("%d", &group_num);
		if(group_num == 0){
			break;
		}
		scanf("%s", &a);
		groups = strlen(a)/group_num;
		for(i = 0;i < group_num;i++){
			for(j = 0;j < groups;j++){
				b[j] = a[i*group_num + j];
			}
			reverse();
		}
		printf("\n");
	}
}
