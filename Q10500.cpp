#include <iostream>
#include <vector>

using namespace std;

void print(int n){
	cout << "|";
	for(int i = 0;i < n;i++){
		cout << "---|";
	}
	cout << endl;
}

int main(){
	int N,M;
	while(cin >> N >> M && N != 0 && M != 0){
		int ini_x,ini_y;
		cin >> ini_x >> ini_y;
		char real_map[N+2][M+2];
		char ans_map[N+2][M+2];
		int route[N+2][M+2] = {0};
		int count_move = 0;
		for(int i = 0;i <= N+1;i++){
			for(int j = 0;j <= M+1;j++){
				if(i == 0 || j == 0 || i == N+1 || j == M+1){
					ans_map[i][j] = 'X';
					continue;
				}
				ans_map[i][j] = '?';
			}
		}
		//bool end = false;
		for(int i = 0;i <= N+1;i++){
			for(int j = 0;j <= M+1;j++){
				if(i == 0 || j == 0 || i == N+1 || j == M+1){
					real_map[i][j] = 'X';
					continue;
				}
				cin >> real_map[i][j];
			}
		}
		ans_map[ini_x][ini_y] = '0';
		route[ini_x][ini_y] = 1;
		while(1){
			if(ans_map[ini_x-1][ini_y] != '?' && 
			   ans_map[ini_x][ini_y+1] != '?' &&
			   ans_map[ini_x+1][ini_y] != '?' &&
			   ans_map[ini_x][ini_y-1] != '?') break;
			ans_map[ini_x-1][ini_y] = real_map[ini_x-1][ini_y];
			ans_map[ini_x][ini_y+1] = real_map[ini_x][ini_y+1];
			ans_map[ini_x+1][ini_y] = real_map[ini_x+1][ini_y];
			ans_map[ini_x][ini_y-1] = real_map[ini_x][ini_y-1];
			if(ans_map[ini_x-1][ini_y] == 'X' && 
			   ans_map[ini_x][ini_y+1] == 'X' &&
			   ans_map[ini_x+1][ini_y] == 'X' &&
			   ans_map[ini_x][ini_y-1] == 'X') break;
			if(ans_map[ini_x-1][ini_y] == '0' && !route[ini_x-1][ini_y]){
				ini_x--;
			}
			else if(ans_map[ini_x][ini_y+1] == '0' && !route[ini_x][ini_y+1]){
				ini_y++;
			}
			else if(ans_map[ini_x+1][ini_y] == '0' && !route[ini_x+1][ini_y]){
				ini_x++;
			}
			else if(ans_map[ini_x][ini_y-1] == '0' && !route[ini_x][ini_y-1]){
				ini_y--;
			}
			route[ini_x][ini_y] = 1;
			count_move++;
		}
		print(M);
		for(int i = 1;i <= N;i++){
			for(int j = 1;j <= M;j++){
				cout << "| " << ans_map[i][j] << ' ';
			}
			cout << "| " << endl;
			print(M);
		}
		cout << endl;
		cout << "NUMBER OF MOVEMENTS: " << count_move-1 << endl;
		cout << endl;
	}
	return 0;
}
