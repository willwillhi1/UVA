#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	char c;
	while((c = getchar()) != EOF){
		vector<int> v;
		if(c != '-') v.push_back(c-'0');
		else {v.push_back(0-(getchar()-'0'));}
		while(c != '\n'){
			c = getchar();
			if(c == ' ' || c == '\n') continue;
			else{
				if(c != '-') v.push_back(c-'0');
				else {v.push_back(0-(getchar()-'0'));}
			}
		}
		c = ' ';
		int size = v.size();
		while(c != '\n'){
			int sum = 0,x;
			c = getchar();
			if(c == ' ' || c == '\n') continue;
			else{
				if(c != '-') x = c - '0';
				else{ x = 0-(getchar()-'0');}
				for(int i = 0;i < size;i++) sum += (v[i])*pow(x, size-i-1);
			}
			cout << sum << " ";
		}
		cout << endl;
	}
}
