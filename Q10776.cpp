#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<string> ansv;
string ans_tmp;
string s;
int check_array[26];

bool check(string ans_tmp,string ans){
	for(int i = 0;i < ans_tmp.size();i++){
		for(int j = 0;j < 26;j++){
			if(ans_tmp[i] == 'a'+j)
				check_array[j]++;
		}
	}
	for(int i = 0;i < ans.size();i++){
		for(int j = 0;j < 26;j++){
			if(ans[i] == 'a'+j)
				check_array[j]--;
		}
	}
	for(int i = 0;i < 26;i++)
		if(check_array[i] != 0) return false;
	return true;
}

void DFSvisit(int start, int limit, int count){
	int size = s.size();
	if(limit == count){
		for(int i = 0;i < ansv.size();i++)
			if(check(ans_tmp, ansv[i])) return;
		ansv.push_back(ans_tmp);
		return;
	}
	for(int i = start+1;i < size;i++){
		ans_tmp.push_back(s[i]);
		count++;
		DFSvisit(i, limit, count);
		count--;
		ans_tmp.pop_back();
	}
}

void DFS(int start, int limit){
	int size = s.size();
	int count = 0;
	for(int i = start;i < size;i++){
		ans_tmp.push_back(s[i]);
		count++;
		DFSvisit(i, limit, 1);
		ans_tmp.pop_back();
		count--;
	}
}

void init(){
	ansv.clear();
	ans_tmp = "";
	s = "";
	memset(check_array, 0, 26);
}

void sort(){
	int size = ansv.size();
	for(int i = 0;i < size;i++){
		for(int j = i+1;j < size;j++){
			if(strcmp(ansv[i].c_str(), ansv[j].c_str()) > 0){
				string temp = ansv[i];
				ansv[i] = ansv[j];
				ansv[j] = temp;
			}
		}
	}
}

int main(){
	int r;
	while(cin >> s){
		cin >> r;
		DFS(0, r);
		sort();
		for(int i = 0;i < ansv.size();i++) cout << ansv[i] << ' ';
		cout << endl;
		init();
	}
}
