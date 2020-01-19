#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

struct replace{
	char c;
	string str;
	int len;
};

int main(){
	int T;
	cin >> T;
	while(T--){
		int R,Q,times;
		vector<replace> re_vec;
		string ini_str;
		char check_c;
		cin >> R;
		while(R--){
			cin.ignore();
			replace re;
			re.c = getchar();
			getchar();
			getchar();
			cin >> re.str;
			re.len = re.str.length();
			re_vec.push_back(re);
			//cout << "c: " << re.c << " str: " << re.str << endl;
		}
		cin >> Q;
		while(Q--){
			cin >> ini_str >> check_c >> times;
			//cout << ini_str << " " << check_c << " " << times << endl;
			int len;
			int range = re_vec.size();
			int count = 0;
			while(times--){
				len = ini_str.length();
				//cout << "len: " << len << endl;
				for(int i = 0;i < len;i++){
					//cout << "i: " << ini_str[i] << endl;
					for(int j = 0;j < range;j++){
						if(ini_str[i] == re_vec[j].c){
							ini_str.replace(i, 1, re_vec[j].str);
							i += re_vec[j].len - 1;
							len += re_vec[j].len - 1;
							break;
						}
					}
				}
				//cout << ini_str << endl;
			}
			len = ini_str.length();
			for(int i = 0;i < len;i++)
				if(ini_str[i] == check_c) count++;
			cout << count << endl;
		}
	}
}
