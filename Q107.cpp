#include <iostream>

using namespace std;

int main(){
	int height,num;
	while((cin >> height >> num) && (height != 0 && num != 0)){
		if(height == 1){
			cout << "0 1" << endl;
			continue;
		}
		int no_work = 0,all_high = 0;
		int N = 2,m = 0;
		int i = num,j = height;
		if(num == 1){
			N = 1;
			while(j / (N+1) != 1){
				j /= (N+1);
				m++;
			}
			m++;
			//cout << m << endl;
		}
		else if(num == height - 1){
			N = num;
			m = 1;
		}
		else{ 
			while(i / N != 1 && j / (N+1) != 1){
				cout << "in" << endl;
				if(i % N != 0 || j % (N+1) != 0){
					N++;
					i = num;
					j = height;
					m = 0;
					continue;
				}
				i /= N;
				j /= (N+1);
				m++;
			}
			m++;
		}
		//cout << N << " " << m << endl;
		for(int i = 1;m > -1;m--){
			if(height != 1){
				no_work += i;
			}
			all_high += height*i;
			height /= (N+1);
			i *= N;
		}
		cout << no_work << " " << all_high << endl;
	}
}
