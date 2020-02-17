#include <iostream>
#include <cstdio>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		int segments = 0,completes = 0;
		segments = 4*(2*n - 1);
		int count = 2*n - 2;
		for(int i = 1;i < n;i++,count = count - 2){
			completes += count;
			//cout << count << ' ' << endl;
		}
		printf("In the case n = %d, %d cells contain segments of the circle.\n",n,segments);
		printf("There are %d cells completely contained in the circle.\n\n",completes*2);
	}
	return 0;
}
