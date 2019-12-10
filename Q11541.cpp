#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main(){
	int i,j,times,num;
	char c;
	while(scanf("%d",&num) != EOF){
		//ignore '\n'
		getchar();
		for(i = 0;i < num;i++){
			while(1){
				scanf("%c",&c);
				if(c == '\n'){
					cout << endl;
					break;
				}
				scanf("%d",&times);
				for(j = 0;j < times;j++){
					cout << c;
				}
			}
		}
	}
	return 0;
}
