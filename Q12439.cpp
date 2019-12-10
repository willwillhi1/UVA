#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

bool is_Leap(int year){
	if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0 && year % 4000 != 0)){
		return true;
	}
	else{
		return false;
	}
}

int main(){
	int i,j,T;
	string month[12] = {
	"January", "February", "March",
	"April","May", "June",
	"July", "August", "September",
	"October", "November" , "December"
	};
	int month_val[12] = {
	1, 2, 3, 4,
	5, 6, 7, 8,
	9, 10, 11, 12
	};
	scanf("%d",&T);
	for(i = 0;i < T;i++){
		string s_month,e_month;
		int count = 0,s_d,s_m = 0,s_y,e_d,e_m = 0,e_y;
		cin >> s_month;
		scanf(" %d, %d",&s_d,&s_y);
		cin >> e_month;
		scanf(" %d, %d",&e_d,&e_y);
				
		for(j = 0;j < 12;j++){
			if(s_month == month[j]){
				s_m = month_val[j];
			}
			if(e_month == month[j]){
				e_m = month_val[j];
			}
		}
		//cout << s_m << s_d << s_y << endl;
		if(s_m <= 2){
			if(e_m < 2 || (e_m == 2 && e_d <= 28)){
				for(j = s_y;j < e_y;j++){
					if(is_Leap(j)){ 
						cout << j << endl;
						count++;
					}
				}
			}
			else if(e_m >= 2){
				if(e_m == 2 && e_d == 29){
					for(j = s_y;j < e_y;j++){
						if(is_Leap(j)){ 
							cout << j << endl;
							count++;
						}
					}
					cout << e_y << endl;
					count++;
				}
				else if(e_m > 2){
					for(j = s_y;j <= e_y;j++){
						if(is_Leap(j)){ 
							cout << j << endl;
							count++;
						}
					}
				}
			}
		}
		else if(s_m > 2){
			if(e_m < 2 || (e_m == 2 && e_d <= 28)){
				for(j = s_y+1;j < e_y;j++){
					if(is_Leap(j)){ 
						cout << j << endl;
						count++;
					}
				}
			}
			else if(e_m >= 2){
				if(e_m == 2 && e_d == 29){
					for(j = s_y+1;j < e_y;j++){
						if(is_Leap(j)){ 
							cout << j << endl;
							count++;
						}
					}
					cout << e_y << endl;
					count++;
				}
				else if(e_m > 2){
					for(j = s_y+1;j <= e_y;j++){
						if(is_Leap(j)){ 
							cout << j << endl;
							count++;
						}
					}
				}
			}
		}
		cout << "Case " << i+1 << ": " << count << endl;
	}
}
