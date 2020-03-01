#include<iostream>

using namespace std;

int main(){
	int n;
	while(cin >> n){
		int start = 1,end = 1,num = 0,amount = 0,order = 0;
		for(int i = 1;;i++){
			start = amount+1;
			amount += i;
			end = amount;
			if(n >= start && n <= end){
				num = i;
				break;
			}
		}
		order = n - start + 1;
		//cout << num << endl;
		if(n%2==0){
			cout << "TREM " << n << " IS " << num - order + 1 << "/" << order << endl;
		}
		else{
			cout << "TREM " << n << " IS " << order << "/" << num - order + 1 << endl;
		}
	}
	return 0;
}
