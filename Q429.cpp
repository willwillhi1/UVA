#include<iostream>
#include<map>
#include<vector>
#include<queue>

using namespace std;

map<string, string> route;
map<string, int> visited;
map<string, int> dis;

void bfs(string start, map<string, vector<string>> graph){
	queue<string> q;
	q.push(start);
	visited[start] = 1;
	dis[start] = 0;
	while(!q.empty()){
		start = q.front();
		for(int i = 0;i < graph[start].size();i++){
			if(visited[graph[start][i]] == 0){
				visited[graph[start][i]] = 1;
				route[graph[start][i]] = start;
				q.push(graph[start][i]);
				dis[graph[start][i]] += dis[start] + 1;
			}
		}
		visited[start] = 2;
		q.pop();
	}
}

int main(){
	int n;
	cin >> n;
	while(n--){
		string str;
		map<string, vector<string>> graph;
		vector<string> s;
		while(cin >> str){
			if(str == "*") break;
			s.push_back(str);
		}
		//cin.ignore();
		int size = s.size();
		for(int i = 0;i < size;i++){
			for(int j = 0;j < size;j++){
				if(i != j && s[i].size() == s[j].size()){
					int count = 0;
					for(int k = 0;k < s[i].size();k++){
						if(s[i][k] != s[j][k]) count++;
					}
					if(count == 1)graph[s[i]].push_back(s[j]);
				}
			}
		}
		string str1,str2;
		int count = 2;
		while(count--){
			cin >> str1 >> str2;
			visited[str1] = 0;
			bfs(str1, graph);
			cout << str1 << " " << str2 << " " << dis[str2] << endl;
			route.clear();
			visited.clear();
			dis.clear();
		}
	}
	return 0;
}
