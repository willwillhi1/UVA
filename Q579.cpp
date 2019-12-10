#include <iostream>
#include <stdio.h>
using namespace std;
int main()
{
   double h,m,a;
   char i,j;
   while(scanf("%lf:%lf",&h,&m) != EOF)
   {
		h = h*30 + m*30/60;
		m = m*6;
		if(h >= m){
			//cout << h << m;
			if(h-m >= 180){
				printf("%.3lf",360-(h-m));
			}
			else{
				printf("%.3lf",h-m);
			}
		}
		else if(m > h){
			//cout << h << m;
			if(h-m >= 180){
				printf("%.3lf",360-(m-h));
			}
			else{
				printf("%.3lf",m-h);
			}
		}
   }
    return 0;
}      
