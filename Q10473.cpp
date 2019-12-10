#include <stdio.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;

int convert_hex(int input){
	int output = 1,i;
	if(input == 0){
		return output;
	}
	for(i = 1;i <= input;i++){
		output *= 16;
	}
	return output;
}

int convert_dec(int input){
	int output = 1,i;
	if(input == 0){
		return output;
	}
	for(i = 1;i <= input;i++){
		output *= 10;
	}
	return output;
}
vector<char> convert_dec_to_hex(int input){
	vector<char> output;
	char temp;
	int i,count = 0,len,j;
	while(input != 0){
		//cout << input <<endl;
		i = input%16;
		//cout << i << endl;
		if(i == 10){
			output.push_back('A');
		}
		else if(i == 11){
			output.push_back('B');
		}
		else if(i == 12){
			output.push_back('C');
		}
		else if(i == 13){
			output.push_back('D');
		}
		else if(i == 14){
			output.push_back('E');
		}
		else if(i == 15){
			output.push_back('F');
		}
		else{
			output.push_back('0' + i);
		}
		//cout << output[count] << endl;
		input = input/16;
		count++;
	}
	reverse(output.begin(),output.end());
	/*
	for(i = 0;i < output.size();i++){
		cout << output.at(i);
	}
	cout << endl;
	*/
	return output;
}

int main(){
	string input;
	int i,len,count,hex,dec,amount;
	while(cin >> input){
		if(input == "-1"){
			break;
		}
		if(input[0] == '0' && input[1] == 'x'){
			//cout << "get in" << endl;
			len = input.size();
			count = 0;
			hex = 0;
			amount = 0;
			for(i = len-1;i >= 2;i--){
				hex = convert_hex(count);
				amount += hex*(input[i] - '0');
				count++;
			}
			cout << amount << endl;
		}
		else{
			len = input.size();
			amount = 0;
			dec = 0;
			count = 0;
			for(i = len-1;i >= 0;i--){
				//cout << input[i] << endl;
				dec = convert_dec(count);
				amount += dec*(input[i] - '0');
				count++;
			}
			//cout << amount << endl;
			vector<char> output = convert_dec_to_hex(amount);
			cout << "0x";
			for(i = 0;i < output.size();i++){
				cout << output.at(i);
			}
			cout << endl;
		}
	}
	return 0;
}
