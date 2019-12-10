#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main(){
	int i,N,A,amount = 0;
	char L1,L2,L3;
	scanf("%d", &N);
	for(i = 0;i < N;i++){
		getchar();
		scanf("%c%c%c-%d",&L1,&L2,&L3,&A);
		//cout << L1 << L2 << L3 << endl;
		amount = (L1 - 'A')*26*26 + (L2 - 'A')*26 + (L3 - 'A')*1;
		//cout << amount << endl;
		if(abs(amount - A) <= 100){
			cout << "nice" << endl;
		}
		else{
			cout << "not nice" << endl;
		}
	}
}
