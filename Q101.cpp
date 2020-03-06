#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
using namespace std; 

int main(){
	int count = 0;
	int size;
	string s; 
	while(getline(cin, s)){
		if(count = 0){
			size = atoi(s.c_str());
			cout << size << endl;
			count++;
		}
		else if(strcmp(s.c_str(), "q") == 0){
			cout << '1' << endl;
			count = 0;
		}
		else if(strcmp(s.substr(0,1).c_str(), "m")){
			
			if(strcmp(s.substr(7,1).c_str(), "o")){
				cout << '2' << endl;
			}
			
			else if(strcmp(s.substr(7,1).c_str(), "o")){
				cout << '3' << endl;
			}
			
		}
		else if(strcmp(s.substr(0,1).c_str(), "p")){
			
			if(strcmp(s.substr(7,1).c_str(), "o")){
				cout << '4' << endl;
			}
			else if(strcmp(s.substr(7,1).c_str(), "o")){
				cout << '5' << endl;
			}
			
		}
	}
}
