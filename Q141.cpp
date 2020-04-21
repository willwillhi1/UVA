#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;

vector<map<int, map<int,int>>> check_v;
int N;

bool check(map<int, map<int,int>> spot){
	int len = check_v.size();
	for(int k = 0;k < len;k++){
		int flag = 1;
		for(int i = 1;i <= N;i++)
			for(int j = 1;j <= N;j++)
				if(spot[i][j] != check_v[k][i][j]) flag = 0;
		if(flag) return true;
	}
	return false;
}

int main(){
	int counter = 0,flag = 0;
	while(cin >> N){
		flag = 0;
		map<int, map<int,int>> spot;
		if(N == 0) break;
		else {
			counter = 2*N;
			for(int i = 1;i <= N;i++)
				for(int j = 1;j <= N;j++)
					spot[i][j] = 0;
		}
		while(counter--){
			int x,y;
			char op;
			scanf("%d %d %c",&x,&y,&op);
			if(op == '+') spot[x][y] = 1;
			else if(op == '-') spot[x][y] = 0;	
			if(check(spot)){
				if(flag) continue;
				cout << "Player " << (counter)%2+1 << " wins on move " << 2*N-counter << endl;
				flag = 1;
			}
			else{
				check_v.push_back(spot);
				for(int k = 0;k < 4;k++){
					map<int, map<int,int>> temp;
					for(int i = 1;i <= N;i++)
						for(int j = 1;j <= N;j++)
							temp[j][N-i+1] = spot[i][j];
					spot.swap(temp);
					if(k!=3)check_v.push_back(spot);
				}
			}
		}
		if(!flag) cout << "Draw" << endl;
		check_v.clear();
	}
	return 0;
}
