#include <iostream>
#include <vector>
#include <map>
#include <bits/stdc++.h>

using namespace std;

vector<int> ansv,tmpv;
map<int, vector<int>> graph;
bool B[101];
int ans,n;

void dfs(int start){
	//for(int i = 0;i < tmpv.size();i++) cout << tmpv[i] << ' ';
	//cout << endl;
	if(start == n+1){
		int size = tmpv.size();
		if(ans < size){
			ans = tmpv.size();
			ansv.clear();
			for(int i = 0;i < ans;i++)
				ansv.push_back(tmpv[i]);
		}
		return;
	}
	int size = graph[start].size();
	bool flag = true;
	for(int i = 0;i < size;i++){
		if(B[graph[start][i]]) flag = false;
	}
	if(flag){
		tmpv.push_back(start);
		B[start] = true;
		dfs(start+1);
		tmpv.pop_back();
		B[start] = false;
	}
	dfs(start+1);
}

int main(){
	int count;
	cin >> count;
	while(count--){
		int k;
		graph.clear();
		ansv.clear();
		tmpv.clear();
		ans = -1;
		memset(B,0,101);
		cin >> n >> k;
		int n1,n2;
		for(int i = 0;i < k;i++){
			cin >> n1 >> n2;
			graph[n1].push_back(n2);
			graph[n2].push_back(n1);
		}
		dfs(1);
		cout << ans << endl;
		for(int i = 0;i < ans;i++) cout << ansv[i] << ' ';
		cout << endl;
	}
	return 0;
}
