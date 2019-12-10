#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
using namespace std; 

bool is_possible(vector<char> str){
	int i;
	int num;
	int check = 0;
	int count_odd = 0;
	bool has_check[str.size()] = {false};
	for(num = 0; num < str.size(); num++){
		check = 0;
		if(has_check[num] == true){
			continue;
		}
		for(i = num; i < str.size(); i++){
			if(str[num] == str[i]){
				has_check[i] = true;
				++check;
			}
			if(check == 2){
				break;
			}
		}
		if(check == 1){
			count_odd++; 
		}
		has_check[num] = true;
	}
	if(count_odd > 1){
		return false;
	}
	else{
		return true;
	}
}
int count_times(vector<char> str){
	int start = 0;
	int end = str.size()-1;
	int same = -1;
	int size_mid = str.size()/2;
	char temp;
	int count = 0;
	while(start < size_mid){
		//same從後面開始找
		for(int i = end; i > start; i--){
			if(str[i] == str[start]){
				same = i;
				break;
			}
		}
		//如果是只有一個，移到中間
		if(same == -1){
			//cout << "has one" << endl;
			for(int i = start; i < size_mid; i++){
				temp = str[i];
				str[i] = str[i+1];
				str[i+1] = temp;
				count++;
			}
			//cout << "after same : " << count << endl;
			continue;
		}
		//移動到最後
		for(int i = same; i < end; i++){
			temp = str[i];
			str[i] = str[i+1];
			str[i+1] = temp;
			count++;
		}
		//cout << "after move to end : " << count << endl;
		start++;
		end--;
		same = -1;
	}
	return count;
}
int main(){
	int amount;
	int count = 0;
	cin >> amount;
	cin.ignore(); 
	while(count < amount){
		string input;
		vector<char> first;
		getline(cin, input);
		char str[input.size()];
		strcpy(str, input.c_str());
		for(int i = 0; i < sizeof(str); i++){
			first.push_back(str[i]);
		}
		vector<char>::iterator it = first.begin();
		if(!is_possible(first)){
			cout << "Impossible" << endl;
			count++;
			continue;
		}
		else{
			cout << count_times(first) << endl;
		}
		count++;
	}
}
