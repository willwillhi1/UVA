#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>

using namespace std;

struct combine{
	int num1 = 0;
	int num2 = 0;
};

bool test_prime(int num1, int num2){
	int gcd = 0;
	while(num2 != 0){
		num1 = num1%num2;
		if(num1 == 0) break;
		num2 = num2%num1;
	}
	if((num1 == 0 && num2 == 1) || (num1 == 1 && num2 == 0)) return true;
	else return false;
}

int main(){
	int N;
	while(cin >> N){
		if(N == 0) break;
		vector<int> input;
		vector<combine> ans;
		int count = 0;
		for(int i = 0;i < N;i++){
			int num;
			cin >> num;
			input.push_back(num);
			//cout << num << endl;
		}
		for(int i = 0;i < N;i++){
			for(int j = i+1;j < N;j++){
				combine com;
				com.num1 = input[i];
				com.num2 = input[j];
				ans.push_back(com);
			}
		}
		int len = ans.size();
		for(int i = 0;i < len;i++) 
			if(test_prime(ans[i].num1, ans[i].num2)) count++;
		if(count != 0) printf("%.6f\n", sqrt(6*len/count));
		else printf("No estimate for this data set.\n");
	}
}
