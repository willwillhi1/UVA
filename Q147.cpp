#include <cstdio>

using namespace std;

int main(){
	int coin[11] = {5,10,20,50,100,200,500,1000,2000,5000,10000};
	long long int ans[30001] = {0};
	int input1,input2;
	ans[0] = 1;
	
	for(int i = 0;i < 11;i++)
		for(int j = coin[i];j < 30001;j++)
			ans[j] += ans[j-coin[i]];
	while(scanf("%d.%d",&input1,&input2)){
		if(input1 == 0 && input2 == 0) break;
		int tran_input = input1*100+input2;
		printf("%3d.%02d%17lld\n",input1,input2,ans[tran_input]);
	}
}
