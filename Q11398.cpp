#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string count(int input1,int input2){
	string flag;
	if(input1 == 1){
		if(input2 == 1){
			flag += "1";
			return flag;
		}
		else if(input2 == 2){
			flag += "11";
			return flag;
		}
		else{
			for(int i = 0;i < input2-2;i++){
				flag += "1";
			}
			return flag;
		}
	}
	else if(input1 == 2){
		if(input2 == 1){
			flag += "0";
			return flag;
		}
		else if(input2 == 2){
			flag += "00";
			return flag;
		}
		else{
			for(int i = 0;i < input2-2;i++){
				flag += "0";
			}
			return flag;
		}
	}
}

int convert_dec(string str){
	int len = str.size(),result = 0;
	for(int i = 0;i < len;i++){
		result += (str[len-i-1]-'0')*pow(2,i);
	}
	return result;
}

int main(){
	string input1,input2;
	string result;
	while(1){
		cin >> input1;
		getchar();
		if(input1.compare("~") == 0) break;
		else if(input1.compare("#") != 0){
			cin >> input2;
			result += count(input1.size(),input2.size());
			//cout << result << endl;
		}
		else if(input1.compare("#") == 0){
			//cout << "result: " << result << endl;
			cout << convert_dec(result) << endl;
			result.clear();
		}
	}
	return 0;
}
