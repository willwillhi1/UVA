#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int day,num,i,j,m,d,amount;
	scanf("%d",&num);
	for(i = 0;i < num;i++){
		amount = 0;
		scanf("%d %d",&m,&d);
		for(j = 0;j < m-1;j++){
			amount += month[j];
		}
		amount += d;
		//cout << amount << " ";
		day = amount%7;
		//cout << day << endl;
		if(day == 0){
			cout << "Friday" << endl;
		}
		if(day == 1){
			cout << "Saturday" << endl;
		}
		if(day == 2){
			cout << "Sunday" << endl;
		}
		if(day == 3){
			cout << "Monday" << endl;
		}
		if(day == 4){
			cout << "Tuesday" << endl;
		}
		if(day == 5){
			cout << "Wednesday" << endl;
		}
		if(day == 6){
			cout << "Thursday" << endl;
		}
	}
	return 0;
}
