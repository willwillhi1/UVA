#include <iostream>
#include <vector>
using namespace std;

int sort(string str){
	int len = str.length(),count = 0;
	for(int i = 0;i < len;i++){
		for(int j = i;j < len;j++){
			if(str[i] > str[j]) count++;
		}
	}
	//cout << count << endl;
	return count;
}

int main(){
	int N;
	cin >> N;
	while(N--){
		int n,m;
		vector<string> DNA;
		cin >> n >> m;
		cin.ignore();
		for(int i = 0;i < m;i++){
			string str;
			getline(cin, str);
			//cout << str << endl;
			DNA.push_back(str);
		}
		int order_num[m] = {0};
		for(int i = 0;i < m;i++){
			order_num[i] = sort(DNA[i]);
		}
		int order[m] = {0};
		for(int i = 0;i < m;i++){
			int bigger = 0,smaller = 0;
			for(int j = 0;j < m;j++){
				if(j == i) continue;
				if(order_num[i] >= order_num[j]) bigger++;
				else if(order_num[i] < order_num[j]) smaller++;
			}
			order[i] = bigger;
		}
		for(int i = 0;i < m;i++){
			for(int j = 0;j < m;j++)
				if(order[j] == i) cout << DNA[j] << endl;
		}
	}
	return 0;
}
