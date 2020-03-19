#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

int main(){
	string str;
	vector<stack<char>> v;
	while(cin >> str){
		stack<char> s;
		int size = str.size();
		for(int i = 0;i < size;i++) s.push(str[i]);
		v.push_back(s);
		if(s.top() == '.'){
			size = v.size();
			for(int i = 0;i < size;i++){
				while(!v[i].empty()){
					cout << v[i].top();
					v[i].pop();
				}
				if(i < size-1) cout << " ";
				else{cout << endl;}
			}
			v.clear();
		}
	}
	return 0;
}
