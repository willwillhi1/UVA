#include <iostream>
#include <map>
#include <vector>
using namespace std;

map<int, vector<int>> graph;
vector<int> visited;
vector<int> color;
void DFS(int size);
void DFSvisited(int start);
bool check(int size);
void init(int n);

void DFS(int size){
    for(int i = 0;i < size;i++){
        if(visited[i] == 0){
            visited[i] = 1;
            DFSvisited(i);
        }
    }
}  

void DFSvisited(int start){
    int size = graph[start].size();
    for(int i = 0;i < size;i++){
        if(visited[graph[start][i]] == 0){
            visited[graph[start][i]] = 1;
            color[graph[start][i]] = (color[start]+1) % 2;
            DFSvisited(graph[start][i]);
        }  
    }
}

bool check(int size){
    for(int i = 0;i < size;i++){
        for(int j = 0;j < graph[i].size();j++){
            if(color[i] == color[graph[i][j]]) return false;
        }
    }
    return true;
}

void init(int n){
    graph.clear();
    visited.clear();
    visited.resize(n);
    fill(visited.begin(), visited.end(), 0);
    color.clear();
    color.resize(n);
    fill(color.begin(), color.end(), 0);
}

int main(){
    int n,m;
    while(cin >> n){
        if(n == 0) break;
        cin >> m;
        init(n);
        for(int i = 0;i < m;i++){
            int start,end;
            cin >> start >> end;
            graph[start].push_back(end);
        }
        DFS(n);   
        if(check(n)) cout << "BICOLORABLE." << endl;
        else{cout << "NOT BICOLORABLE." << endl;}
    }
}
