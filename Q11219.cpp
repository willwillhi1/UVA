#include <stdio.h>
#include <iostream>

using namespace std;

bool is_Leap(int y){
	if((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0 && y %4000 != 0)){
		return true;
	}
	else{
		return false;
	}
}

int count_old(int ny,int nm,int nd,int by,int bm,int bd){
	int y = 0;
	y = ny - by;
	if(nm == bm){
		if(nd < bd){
			y--;
		}
	}
	else if(nm < bd){
		y--;
	}
	return y;
}

int main(){
	int c_month[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int l_month[12] = {31,29,31,30,31,30,31,31,30,31,30,31};
	int i,j,k,Case,old;
	int n_d,n_m,n_y;
	int b_d,b_m,b_y;
	int now,birth;
	int check = 365*130;
	scanf("%d",&Case);
	for(i = 1;i <= Case;i++){
		now = 0;
		birth = 0;
		old = 0;
		printf("Case #%d: ",i);
		scanf("%d/%d/%d",&n_d,&n_m,&n_y);
		scanf("%d/%d/%d",&b_d,&b_m,&b_y);
		
		for(j = 0;j < n_y;j++){
			if(is_Leap(j)){
				now += 366;
			}
			else{
				now += 365;
			}
		}
		if(is_Leap(n_y)){
			for(k = 1;k < n_m;k++){
				now += c_month[k-1];
			}
		}
		else{
			for(k = 1;k < n_m;k++){
				now += l_month[k-1];
			}
		}
		now += n_d;
		
		for(k = 0;k < b_y;k++){
			if(is_Leap(k)){
				birth += 366;
			}
			else{
				birth += 365;
			}
		}
		if(is_Leap(b_y)){
			for(k = 1;k < b_m;k++){
				birth += c_month[k-1];
			}
		}
		else{
			for(k = 1;k < b_m;k++){
				birth += l_month[k-1];
			}
		}
		birth += b_d;
		
		if(now - birth >= 0){
			if(now - birth >= check){
				cout << "Check birth date" << endl;
			}
			else{
				old = count_old(n_y,n_m,n_d,b_y,b_m,b_d);
				cout << old << endl;
			}
		}
		else if(now - birth < 0){
			cout << "Invalid birth date" << endl;
		}
	}
}
