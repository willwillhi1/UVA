#include <iostream>

using namespace std;

int main(){
	int N;
	cin >> N;
	cin.ignore();
	while(N--){
		int times = 4;
		int num,odd_sum = 0,even_sum = 0,sum = 0;
		while(times--){
			char odd1,odd2,even1,even2;
			int temp = 0;
			even1 = getchar();
			odd1 = getchar();
			even2 = getchar();
			odd2 = getchar();
			//cout << even1 << odd1 << even2 << odd2 << endl;
			getchar();
			temp = (even1 - '0')*2;
			even_sum += temp/10 + temp%10;
			temp = (even2 - '0')*2;
			even_sum += temp/10 + temp%10;
			temp = odd1 - '0';
			odd_sum += temp;
			temp = odd2 - '0';
			odd_sum += temp;
		}
		sum = odd_sum + even_sum;
		if(sum%10 == 0) cout << "Valid" << endl;
		else cout << "Invalid" << endl;
	}
	return 0;
}
