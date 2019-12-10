#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main(){
	int i,j,k,T;
	scanf("%d",&T);
	for(i = 0;i < T;i++){
		int N,len = 0;
		vector<int> a;
		scanf("%d",&N);
		for(j = 0;j < N;j++){
			int input;
			len = a.size();
			scanf("%d",&input);
			if(len == 0){ 
				a.push_back(input);
				continue;
			}
			for(k = 0;k < len;k++){
				if(a[k] > input){
					a.insert(a.begin(),input);
					break;
				}
				else if(k == len - 1) a.push_back(input);
			}
		}
		printf("Case %d: %d\n",i+1,a[(len+1)/2]);
	}
}
