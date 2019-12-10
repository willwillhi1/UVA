#include <stdio.h>
#include <iostream>

using namespace std;
/* //real answer，has regular order
   //no -> yes -> yes
  if(n % 3 == 1)
      cout << "NO" << endl;
  else
      cout << "YES" << endl;	
*/
//spent more time
int main(){
	long long int i,j,Case,input,amount,temp;
	scanf("%lld",&Case);
	for(i = 0;i < Case;i++){
		amount = 0;
		input = 0;
		scanf("%lld",&input);
		for(j = 1;j <= input;j++){
			temp = j;
			while(1){
				//cout << j << endl;
				if(temp/10 < 10){
					amount += temp/10 + temp%10;
					break;
				} 
				else{
					amount += temp%10;
					temp = temp/10;
				}
			}
		}
		if(amount%3 == 0){
			cout << "Yes" << endl;
		}
		else{
			cout << "No" << endl;
		}
	}
}
