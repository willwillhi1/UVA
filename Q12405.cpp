#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int i,j = 0,T,N;
	scanf("%d",&T);
	while(j < T){
		scanf("%d",&N);
		int count = 0;
		char input;
		getchar();
		vector<int> project;
		for(i = 0;i < N;i++){
			scanf("%c",&input);
			if(input == '.'){
				project.push_back(0);
			}
			else if(input == '#'){
				project.push_back(1);
			}
		}
		getchar();
		for(i = 0;i < N;i++){
			if(project[i] == 0){
				if(i == N-1){
					count++;
					project[i] = 1;
				}
				else if(i == N-2){
					count++;
					project[i] = 1;
					project[i+1] = 1;
				}
				else{
					count++;
					project[i+1] = 1;
					project[i] = 1;
					project[i+2] = 1;
				}
			}
		}
		j++;
		cout << "Case" << j << ": " << count << endl;
	}
}
