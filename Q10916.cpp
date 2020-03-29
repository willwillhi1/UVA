#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int y;
	while(cin >> y){
		if(y == 0) break;
		double n = 4 << ((y-1960)/10);
		//cout << n << endl;
		double i;
		for(i = 1;n > 0;i++){
			n -= log10(i)/log10(2);
		}
		cout << i-2 << endl;
	}
}
