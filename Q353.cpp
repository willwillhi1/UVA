#include <iostream>
#include <stack>
#include <vector>
using namespace std;

bool isPalindromes(string str){
	stack<char> s;
	int size = str.size(),i;
	for(i = 0;i < size/2;i++){
		s.push(str[i]);
	}
	if(size%2==1) i++;
	for(;i < size;i++){
		char c = s.top();
		s.pop();
		if(c != str[i]) return false;
	}
	return true;
}

int main(){
	string str;
	while(cin >> str){
		int size = str.size();
		vector<string> ans;
		for(int i = 0;i < size;i++){
			for(int j = i;j < size;j++){
				string test_str;
				bool flag = false;
				for(int k = i;k <= j;k++) test_str.push_back(str[k]);
				if(isPalindromes(test_str)){
					for(int n = 0;n < ans.size();n++) 
						if(test_str == ans[n]) flag = true;
					if(!flag) ans.push_back(test_str);
				}
			}
		}
		cout << "The string '" << str << "' contains " << ans.size() << " palindromes." << endl;
	}
	return 0;
}
