#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int n,h,i,j,add,count,average,amount;
	int a[100];
	while(scanf("%d",&n) != EOF){
		amount = 0;
		average = 0;
		count = 0;
		if(n == 0) break;
		for(i = 0;i < n;i++){
			scanf("%d",&h);
			amount += h;
			a[i] = h;
		}
		average = amount/n;
		for(i = 0;i < n;i++){
			add = 1;
			while(a[i] > average){
				if(a[i+add] < average){
					a[i]--;
					a[i+add]++;
					count++;
					//cout << count << endl;
				}
				if(a[i+add] >= average)add++;
			}
			while(a[i] < average){
				if(a[i+add] > average){
					a[i]++;
					a[i+add]--;
					count++;
					//cout << count << endl;
				}
				if(a[i+add] <= average)add++;
			}
		}
		cout << count << endl; 
	}
}
