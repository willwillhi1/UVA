#include <iostream>
using namespace std;

int bio(int N, int M){
	int result = 1;
	int k = N-M+1;
	for(int i = k,j = 1;i <= N;i++,j++){
		result *= i;
		if(j <= M){result /= j;}
	}
	return result;
}

int main(){
	int N,M;
	while(cin >> N >> M){
		int result = 1; 
		if(N == 0 && M == 0) break;
		else{result = bio(N, M);}
		cout << result << endl;
	}
}
