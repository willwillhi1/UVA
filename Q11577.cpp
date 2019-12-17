#include <cstdio>
#include <iostream>
#include <string>
#include <ctype.h>
#include <vector>
using namespace std;

struct ans{
	char a;
	int count;
};

bool repeat(string str, char c){
	int len = str.size();
	for(int i = 0;i < len;i++){
		if(str[i] == c) return true;
	}
    return false;
}

int main(){
	int amount;
	cin >> amount;
	cin.ignore();
	while(amount){
		string s;
		getline(cin,s);
		int len = s.size();
		int num = 0,max = 0;
		//cout << s << endl;
		while(s[num]){
			s[num] = tolower(s[num]);
			num++;
		}
		vector<ans> a;
		for(int i = 0;i < len;i++){
			int count = 0;
			ans b;
			for(int j = 0;j < len;j++){
				if(s[i] == s[j]) count++;
			}
			b.a = s[i];
			b.count = count;
			if((b.a >= 97 && b.a <= 122)){
				if(count > max) max = count;
				a.push_back(b);
			}
			//cout << a[i].a << " " << a[i].count << endl;
		}
		string str;
		len = a.size();
		//cout << max << endl;
		for(int i = 0;i < len;i++){
			if(a[i].count == max && !repeat(str,a[i].a) && (a[i].a >= 97 && a[i].a <= 122))
				str.push_back(a[i].a);
		}
		cout << str << endl;
		amount--;
	}
	return 0;
}
