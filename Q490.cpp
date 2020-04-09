#include <iostream>
#include <string>
using namespace std;

int main() {
	string s1,s2;
	getline(cin, s1);
	getline(cin, s2);
	if(s1.size()>s2.size())
		for(int i = 0;i < s1.size();i++){
			if(i >= s2.size()){
				cout << s1[i] << endl; 
			}
			else{
				cout << s2[i];
				cout << s1[i] << endl;
			}
		}
	else{
		for(int i = 0;i < s2.size();i++){
			if(i >= s1.size()){
				cout << s2[i] << endl; 
			}
			else{
				cout << s2[i];
				cout << s1[i] << endl;
			}
		}
	}	
	return 0;
}
