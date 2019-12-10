#include <stdio.h>
#include <string.h>

bool is_prime(int a){
	int i;
	if(a == 0 || a == 1){
		return false;
	}
	for(i = 2;i < a;i++){
		if(a%i == 0){
			return false;
		}
	}
	return true;
}

int main(){
	int i,j,k,Case,count;
	char a[2001];
	int b[62] = {0};
	char c[62] = {
		'0','1','2','3','4','5','6','7','8','9',
		'A','B','C','D','E','F','G','H','I','J','K','L','M',
		'N','O','P','Q','R','S','T','U','V','W','X','Y','Z',
		'a','b','c','d','e','f','g','h','i','j','k','l','m',
		'n','o','p','q','r','s','t','u','v','w','x','y','z'
	};
	int len;
	scanf("%d",&Case);
	
	for(i = 0;i < Case;i++){
		for(j = 0;j < 62;j++){
			b[j] = 0;	
		}
		count = 0;
		scanf("%s", &a);
		len = strlen(a);
		for(j = 0;j < len;j++){
			for(k = 0;k < 62;k++){
				if(a[j] == c[k]){
					b[k]++;
				}
			}
		}
		printf("Case %d: ",i+1);
		for(j = 0;j < 62;j++){
			if(is_prime(b[j])){
				printf("%c",c[j]);
				count++;
			}
		}
		if(count == 0){
			printf("empty");
		}
		if(i == Case-1){
			printf("\n");
		}
	}
	return 0;
}
