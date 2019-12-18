#include <cstdio>
#include <iostream>

using namespace std;

int main(){
	int amount;
	cin >> amount;
	for(int Case = 1;Case <= amount;Case++){
		int N;
		int high = 0,low = 0;
		cin >> N;
		int now;
		cin >> now;
		for(int i = 1;i < N;i++){
			int next;
			cin >> next;
			if(now > next) low++;
			else if(now < next) high++;
			now = next;
		}
		cout << "Case " << Case << ": " << high << " " << low << endl;
	}
	return 0;
}
