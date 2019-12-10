#include <stdio.h>
#include <iostream>

using namespace std;
int num[100] = {0};
int count = 0;

void transfer(int N){
	while(N > 0){
		num[count] = N%3;
		//cout << num[count] << endl;
		N = N/3;
		count++;
	}
}

int main(){
	int N;
	int i;
	while(1){
		count = 0;
		scanf("%d", &N);
		if(N < 0){
			break;
		}
		transfer(N);
		//cout << count << endl;
		for(i = count-1;i >= 0;i--){
			//cout << "number: " << i << endl;
			cout << num[i];
		}
		cout << endl;
	}
}
