#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<char> dungeon;
vector<int> visited;
vector<int> dis;
int size;
int L,R,C;

void BFS(int start){
    queue<int> q;
    if(visited[start] == 0){
        q.push(start);
        visited[start] = 1;
        while(!q.empty()){
            int u = q.front();
            for(int i = 0;i < 6;i++){
                switch(i){
                    case 0:                     //East
                        if(visited[u+1] == 0){
                            visited[u+1] = 1;
                            dis[u+1] = dis[u] + 1;
                            q.push(u+1);
                            break;
                        }
                    case 1:                     //West
                        if(visited[u-1] == 0){
                            visited[u-1] = 1;
                            dis[u-1] = dis[u] + 1;
                            q.push(u-1);
                            break;
                        }
                    case 2:                     //South
                        if(visited[u+C+2] == 0){
                            visited[u+C+2] = 1;
                            dis[u+C+2] = dis[u] + 1;
                            q.push(u+C+2);
                            break;
                        }
                    case 3:                     //North
                        if(visited[u-(C+2)] == 0){
                            visited[u-(C+2)] = 1;
                            dis[u-(C+2)] = dis[u] + 1;
                            q.push(u-(C+2));
                            break;
                        }
                    case 4:                     //Up
                        if(visited[u-(R+2)*(C+2)] == 0){
                            visited[u-(R+2)*(C+2)] = 1;
                            dis[u-(R+2)*(C+2)] = dis[u] + 1;
                            q.push(u-(R+2)*(C+2));
                            break;
                        }
                    case 5:                     //Down
                        if(visited[u+(R+2)*(C+2)] == 0){
                            visited[u+(R+2)*(C+2)] = 1;
                            dis[u+(R+2)*(C+2)] = dis[u] + 1;
                            q.push(u+(R+2)*(C+2));
                            break;
                        }
                }
            }
            q.pop();
        }
    }
}

void init(){
    dungeon.clear();
    dungeon.resize(size);
    fill(dungeon.begin(), dungeon.end(), '#');
    visited.clear();
    visited.resize(size);
    fill(visited.begin(), visited.end(), 1);
    dis.clear();
    dis.resize(size);
    fill(dis.begin(), dis.end(), 0);
}

int main(){
    while(cin >> L >> R >> C){
        if(L==0 && R==0 && C==0) break;
        size = (L+2)*(R+2)*(C+2);
        cin.ignore();
        init();
        int start,end;
        for(int i = 0;i < size;){
            if((i < (R+2)*(C+2)) || (i+1 > (R+2)*(C+2)*(L+1))){i++;continue;}
            else if(i%(C+2) == 0){
                i += (C+2);
                for(int j = 0;j < R;j++){
                    for(int k = 0;k < C+2;k++){
                        if(k == 0 || k == C+1){ i++;continue;}
                        else{
                            char c = getchar();
                            while(c == '\n') c = getchar(); 
                            if(c == 'S') start = i;
                            else if(c == 'E') end = i;
                            dungeon[i] = c;
                            if(c != '#') visited[i] = 0;
                            i++;
                        }
                    }
                }
                i += (C+2);   
            }
        }
        BFS(start);
        if(dis[end]!=0) cout << "Escaped in " << dis[end] << " minute(s)."  << endl;
    	else{cout << "Trapped!" << endl;}
    }
    return 0;
}
