#include <cstdio>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

struct v{
	vector<int> a;
};

int execute(vector<int> input){
	int result = 1,len = input.size();
	vector<int> v;
	int big = 0,small = 0;
	for(int i = 0;i < len;i++){
		if(i == 0){
			v.push_back(input[i]);
			continue;
		}
		for(int j = 0;j < v.size();j++){
			//cout << j << " " << v.size() << endl;
			if(v[j] <= input[i]){
				v.insert(v.begin()+j,input[i]);
				break;
			}
			else if(j == v.size()-1){
				v.push_back(input[i]);
				break;
			}
		}
	}
	len = v.size();
	//cout << "v.size(): " << len << endl;
	for(int i = 0;i < len;i++){
		big += v[i]*pow(10, len-i-1);
	}
	for(int i = len-1;i >= 0;i--){
		small += v[i]*pow(10, i);
		//cout << "small: " << v[i]*pow(10, len-i-1) << endl;
	}
	result = big - small;
	cout << big << " - " << small << " = " << result << endl;
	return result;
}

v convert(int input){
	//cout << "convert: " << input << endl; 
	v output;
	while(input >= 10){
		output.a.insert(output.a.begin(),input%10);
		input = input/10;
	}
	output.a.insert(output.a.begin(),input);
	/*
	for(int i = 0;i < output.a.size();i++){
		cout << output.a[i] << endl;
	}
	*/
	return output;
}

int main(){
	char digit;
	vector<int> input;
	int result1 = 0,result2 = 0,len = 0,count = 0;
	while(1){
		digit = getchar();
		if(digit == '\n'){
			len = input.size();
			for(int i = 0;i < len;i++){
				result1 += input[i]*pow(10, len-i-1);
				//cout << "add result: " << result1 << endl;
			}
			if(result1 == 0) break;
			else if(count == 0 && result1 != 0){
				cout << "Original number was " << result1 << endl;
			}
			while(result1 != result2){
				v vec;
				if(count != 0) result1 = result2;
				vec = convert(result1);
				result2 = execute(vec.a);
				count++;
				input.clear();
			}
			if(result1 == result2){
				cout << "Chain length " << count << endl;
				cout << endl;
				input.clear();
				count = 0;
				result1 = 0;
				result2 = 0;
				continue;
			}
		}
		input.push_back(digit - '0');
	}
	return 0;
}
