#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <map>
#include <cstdio>
using namespace std;

char ans[10];
char ans_tmp[10];
vector<char> app;
map<char, vector<int>> graph;
map<char, int> user_need;
int visited[10];
bool flag = false;
bool no_ans = true;

void DFS(int start){
	int app_size = app.size();
	if(app_size-1 == start && user_need[app[start]] == 0){
		for(int i = 0;i < 10;i++){
			ans[i] = ans_tmp[i];
		}
		flag = true;
		no_ans = false;
		return;
	}
	if(user_need[app[start]] != 0){
		int size = graph[app[start]].size();
		for(int j = 0;j < size;j++){
			if(flag) return;
			if(visited[graph[app[start]][j]] == 0){
				visited[graph[app[start]][j]] = 1;
				user_need[app[start]]--;
				ans_tmp[graph[app[start]][j]] = app[start];
				DFS(start);
				visited[graph[app[start]][j]] = 0;
				user_need[app[start]]++;
				ans_tmp[graph[app[start]][j]] = '_';
			}
		}
	}
	else {DFS(start+1);}
}

void init(){
	memset(ans, '_', 10);
	memset(ans_tmp, '_', 10);
	memset(visited, 0, 10);
	graph.clear();
	user_need.clear();
	app.clear();
	flag = false;
	no_ans = true;
}

int main(){
	char c;
	init();
	while((c = getchar()) != EOF){
		if(c == '\n'){
			DFS(0);
			if(!no_ans){
				for(int i = 0;i < 10;i++) cout << ans[i];
				cout << endl;
			}
			else{cout << '!' << endl;}
			init();
		}
		else{
			char ch;
			int need_to_run;
			scanf("%d ",&need_to_run);
			user_need[c] = need_to_run;
			app.push_back(c);
			while(ch = getchar()){
				if(ch == ';'){ 
					getchar();
					break;
				}
				else{
					graph[c].push_back(ch - '0');
				}
			}
		}
	}
	return 0;
}
