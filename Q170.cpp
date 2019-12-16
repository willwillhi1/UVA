#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <queue>
using namespace std;

struct card{
	char rank;
	char color;
};

int main(){
	while(1){
		int count = 0;
		card last;
		queue<card> pile[13];
		for(int i = 0;i < 4;i++){
			for(int j = 0;j < 13;j++){
				card a;
				a.rank = getchar();
				if(a.rank == '#') return 0;
				a.color = getchar();
				pile[j].push(a);
				getchar();
				//cout << a.rank << a.color << endl;
			}
		}
		int start = 0;
		while(!pile[start].empty()){
			//cout << start << endl;
			count++;
			last = pile[start].front();
			pile[start].pop();
			//cout << last.rank << last.color << endl;
			//cout << "start size: " << pile[start].size() << endl;
			if(last.rank == 'A') start = 12;
			else if(last.rank == 'T') start = 3;
			else if(last.rank == 'J') start = 2;
			else if(last.rank == 'Q') start = 1;
			else if(last.rank == 'K') start = 0;
			else start = 13 - (last.rank - '0');
			//cout << "next size: " << pile[start].size() << endl;
		}
		printf("%02d",count);
		cout << ',' << last.rank << last.color << endl;
	}
}
