#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int start,n1,n2,n3;
	while(scanf("%d %d %d %d",&start,&n1,&n2,&n3) && 
	!(start == 0 && n1 == 0 && n2 == 0 && n3 == 0)){
		int amount = 0;
		amount += 360*2;
		if(n1 > start) amount += (40 - n1 + start)*9;
		else if(n1 < start) amount += (n1 - start)*9;
		amount += 360;
		if(n1 > n2) amount += (40 - n1 + n2)*9;
		else if(n1 < n2) amount += (n2 - n1)*9;
		if(n3 > n2) amount += (40 - n3 + n2)*9;
		else if(n3 < n2) amount += (n3 - n2)*9;
		cout << amount << endl;
	}
}
