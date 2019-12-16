#include <cstdio>
#include <iostream>

using namespace std;

int f91(int input){
	if(input <= 100){
		return f91(f91(input + 11));
	}
	else if(input >= 101){
		return input - 10;
	}
}

int main(){
	int input;
	while(scanf("%d",&input) && input != 0){
		cout << "f91(" << input << ") = " << f91(input) << endl;
	}
	return 0;
}
