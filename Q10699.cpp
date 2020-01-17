#include <iostream>

using namespace std;

int main(){
	int input,count = 0,temp = 0;
	while(cin >> input && input != 0){
		cout << input << " : ";
		for(int i = 2;i <= input;i++){
			if(input%i==0){
				if(i != temp) count++;
				temp = i;
				input /= i;
				i--;
			}
		}
		cout << count << endl;
		count = 0;
		temp = 0;
	}
	return 0;
}
