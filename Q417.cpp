#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<string> v;
    int start = 0,end = 26;
    string str;
    for(string c = "a";c <= "z";c[0]++){
    	v.push_back(c);
    }
    
    for(int i = 0;i < 4;i++){
    	for(int j = start;j < end;j++){
    		for(char c = v[j][i]+1;c <= 'z';c++){
    			v.push_back(v[j]+c);
    		}
    	}
    	start = end;
    	end = v.size();
    }
    int len = v.size();
    while(cin >> str){
    	int i;
    	for(i = 0;i < len;i++){
			if(str==v[i]){
				cout << i+1 << endl;
				break;
			}
    	}
		if(i == len && str != "vwxyz"){
			cout << "0" << endl;
		}
	}
	return 0;
}
