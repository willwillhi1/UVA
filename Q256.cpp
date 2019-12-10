#include <cstdio>
#include <iostream>
#include <math.h>
using namespace std;

int main(){
	int N;
	//TLE
	/*
	int value[4] = {99,9999,999999,99999999};
	while(scanf("%d",&N) != EOF){
		int a = 0,b = 0;
		int c = 1;
		for(int i = 0;i < N/2;i++){
			c *= 10;
		}
		for(int i = 0;i < value[N/2-1];i++){
			a = i/c;
			b = i%c;
			if((a+b)*(a+b) == i){
				if(N == 2){
					printf("%2d\n",i);
				}
				else if(N == 4){
					printf("%4d\n",i);
				}
				else if(N == 6){
					printf("%6d\n",i);
				}
				else if(N == 8){
					printf("%8d\n",i);
				}
			}
		}
	}
	*/
	while(scanf("%d",&N) != EOF){
		int halfbound = pow(10,N/2);
		int real,left,right;
		for(int i = 0;i < halfbound;i++){
			real = i*i;
			left = real/halfbound;
			right = real%halfbound;
			
			if((left+right)*(left+right) == real){
				if(N == 2){
					printf("%02d\n",real);
				}
				else if(N == 4){
					printf("%04d\n",real);
				}
				else if(N == 6){
					printf("%06d\n",real);
				}
				else if(N == 8){
					printf("%08d\n",real);
				}
			}
		}
	}
} 
