#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	char jingle[7] = {'W','H','Q','E','S','T','X'};
	int length[7] = {64,32,16,8,4,2,1};
	int amount = 0,count = 0,i;
	char c;
	while(c = getchar()){
		//cout << c << endl;
		if(c == '*'){
			break;
		}
		while(c = getchar()){
			//cout << c << endl;
			if(c == '/'){
				//cout << amount << endl;
				if(amount == 64){
					//cout << "add" << endl;
					count++;
				}
				amount = 0;
				continue;
			}
			else if(c == ' '){
				continue;
			}
			else if(c == '\n'){
				cout << count << endl;
				count = 0;
				break;
			}
			for(i = 0;i < 7;i++){
				if(jingle[i] == c){
					//cout << "here" << endl;
					amount += length[i];
					break;
				}
			}
		}
	}
}
