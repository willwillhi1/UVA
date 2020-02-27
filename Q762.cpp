#include <iostream>
#include <queue>
#include <vector>
#include <map>

using namespace std;

map<string, string> route;
map<string, int> visited;
map<string, int> dis;

int bfs(string start, string end,map<string, vector<string>> graph){
	queue<string> q;
	q.push(start);
	visited[start] = 1;
	dis[start] = 0;
	while(!q.empty()){
		start = q.front();
		int size = graph[start].size();
		if(end == start) return 1;
		for(int i = 0;i < size;i++){
			if(!visited[graph[start][i]]){
				visited[graph[start][i]] = 1;
				dis[graph[start][i]] = dis[start] + 1;
				route[graph[start][i]] = start;
				q.push(graph[start][i]);
			}
		}
		q.pop();
		visited[start] = 2;
	}
	return 0;
}

void printpath(string end,string start){
	if(start == end)return;
	else{
		printpath(route[end], start);
		cout << route[end] << ' ' << end << endl;
	}
}

int main(){
	int M;
	bool first = true;
	while(cin >> M){
		//cout << M << endl;
		route.clear();
		visited.clear();
		dis.clear();
		map<string, vector<string>> graph;
		string start,end;
		for(int i = 0;i < M;i++){
			cin >> start >> end;
			graph[start].push_back(end);
			graph[end].push_back(start);
			visited[start] = 0;
			visited[end] = 0;
		}
		cin >> start >> end;
		//cout << start << endl;
		if(!first){
			cout << endl;
			first = false;
		}
		if(bfs(start, end, graph)) printpath(end, start);
		else cout << "No route" << endl;
		cout << endl;
	}
	return 0;
}
