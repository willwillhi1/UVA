#include <iostream>

using namespace std;

void print_ans(int A){
	for(int i=1;i <= A;i++){
		for(int j=0;j < i;j++){
			cout << i;
		}
		cout << endl;
	}
	for(int i=A-1;i > 0;i--){
		for(int j=0;j < i;j++){
			cout << i;
		}
		cout << endl;
	}
	cout << endl;
}

int main(){
	int n,A,F;
	cin >> n;
	while(n){
		cin >> A >> F;
		for(int i=0;i < F;i++)
			print_ans(A);
		n--;
	}
	return 0;
}
