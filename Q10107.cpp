#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int i,len,input,output = 0,index = 0,count = 0;
	vector<int> a;
	vector<int>::iterator it;
	while(scanf("%d",&input) != EOF){
		len = a.size();
		for(i = 0;i < len;i++){
			if(a[i] > input){
				count = i;
				break;
			}
			else if(i == len-1){
				count = len;
			}
		}
		cout << "count: " << count << endl;
		a.insert(a.begin()+count,input);
		len = a.size();
		index = len/2;
		if(len%2 == 0){
			output = (a[index] + a[index-1])/2;
		}
		else{
			output = a[index];
		}
		cout << "output: " << output << endl;
	}
}
