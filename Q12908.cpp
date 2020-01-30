#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int s;
	while(cin >> s && s != 0){
		s = s << 1;
		//cout << s << endl;
		int n = floor(sqrt(s));
		int amount = n*(n+1);
		if(amount <= s){
			amount = (n+1)*(n+2);
			n++;
		}
		cout << amount/2 - (s >> 1) << " " << n << endl;
	}
	return 0;
}
