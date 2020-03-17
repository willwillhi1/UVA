#include <iostream>
#include <stack>
using namespace std;

int main(){
	int N;
	cin >> N;
	while(N--){
		stack<char> small_P, medium_P;
		string str;
		cin >> str;
		int size = str.size();
		for(int i = 0;i < size;i++){
			if(str[i] == '(') small_P.push('(');
			else if(str[i] == '[') medium_P.push('[');
			else if(str[i] == ')'){
				if(small_P.empty()){
					cout << "No" << endl;
					break;
				}
				else{
					small_P.pop();
				}
			}
			else if(str[i] == ']'){
				if(medium_P.empty()){
					cout << "No" << endl;
					break;
				}
				else{
					medium_P.pop();
				}
			}
			if(i == size-1){
				if(small_P.empty() && medium_P.empty()) cout << "Yes" << endl;
				else{cout << "No" << endl;}
			}
		}
	}
	return 0;
}
