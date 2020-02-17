#include <cstdio>
#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
	int a[9];
	while(cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4]
		>> a[5] >> a[6] >> a[7] >> a[8]){
		bool first = true;
		for(int i = 0;i < 9;i++){
			if(a[i] == 0) continue;
			else if(a[i] > 0){
				if(first){
					if(a[i] == 1) cout << "x^" << 8-i << ' ';
					else{ cout << a[i] << "x^" << 8-i << ' '; }
					first = false;
				}
				else if(i == 7){
					if(a[i] == 1) cout << "+ x" << ' ';
					else{ cout << "+ " << a[i] << "x" << ' '; }
				}
				else if(i == 8){
					if(a[i] == 1) cout << "+ 1";
					else{ cout << "+ " << a[i]; }
				}
				else{
					if(a[i] == 1) cout << "+ x^" << 8-i << ' ';
					else{ cout << "+ " << a[i] << "x^" << 8-i << ' '; }
				}
			}
			else if(a[i] < 0){
				if(first){
					if(a[i] == -1) cout << "-x^" << 8-i << ' ';
					else{ cout << a[i] << "x^" << 8-i << ' '; }
					first = false;
				}
				else if(i == 7){
					if(a[i] == -1) cout << "- x" << ' ';
					else{ cout << "- " << abs(a[i]) << "x" << ' '; }
				}
				else if(i == 8){
					if(a[i] == -1) cout << "- 1";
					else{ cout << "- " << abs(a[i]); }
				}
				else{
					if(a[i] == -1) cout << "- x^" << 8-i << ' ';
					else{ cout << "- " << abs(a[i]) << "x^" << 8-i << ' '; }
				}
			}
		}
		cout << endl;
	}
}
