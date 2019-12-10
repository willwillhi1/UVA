#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
	int input,a,i,j,amount = 0;
	scanf("%d", &a);
	for(i = 0;i < a;i++){
		amount = 1;
		scanf("%d",&input);
		int k = input;
		for(j = 2;j < k;j++){
			if(input%j == 0){
				if(input/j == j){
					amount += j;
					break;
				}
				else{
					k = input/j;
					amount += j + k;
				}
			}
		}
		if(input == amount){
			cout << "perfect" << endl;
		}
		else if(input > amount){
			cout << "deficient" << endl;
		}
		else{
			cout << "abundant" << endl;
		}
	}
}
