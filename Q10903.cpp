#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n,k;
	while(cin >> n){
		if(n == 0) break;
		else{
			double win[n] = {0},lose[n] = {0};
			cin >> k;
			int count = k*n*(n-1)/2
			for(int i = 0;i < count;i++){
				int p1,p2;
				string m1,m2;
				cin >> p1 >> m1 >> p2 >> m2;
				if((m1 == "rock" && m2 == "scissors") ||
				(m1 == "scissors" && m2 == "paper") ||
				(m1 == "paper" && m2 == "rock")){
					win[p1-1]++;
					lose[p2-1]++;
				}
				if((m1 == "rock" && m2 == "paper") ||
				(m1 == "scissors" && m2 == "rock") ||
				(m1 == "paper" && m2 == "scissors")){
					win[p2-1]++;
					lose[p1-1]++;
				}
			}
			for(int i = 0;i < n;i++){
				double session = win[i] + lose[i];
				if(session == 0) cout << "-" << endl;
				else{
					printf("%.3f\n", win[i]/session);
				}
			}
			cout << endl;
		}
	}
}
