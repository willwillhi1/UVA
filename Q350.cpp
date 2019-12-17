#include <iostream>
#include <vector>
using namespace std;

int main(){
	while(1){
		int Z,I,M,L;
		cin >> Z >> I >> M >> L;
		if(Z == 0 && I == 0 && M == 0 && L == 0) break;
		vector<int> ans;
		int last_num = L,ini = 0,count = 0;
		ans.push_back(L);
		for(int i = 0;i < 1000;i++){
			L = (Z*L+I)%M;
			ans.push_back(L);
		}
		//cout << last_num << " " << ans[501] << endl;
		for(int i = 1;i < 1000;i++){
			//cout << i << ": " << ans[i] << endl;
			if(last_num == ans[i]) {
				//cout << i << " " << ini << endl;
				count = i - ini;
				break;
			}
			else if(i == 999 && last_num != ans[i]){
				ini++;
				i = ini;
				last_num = ans[i];
				i++;
			}
		}
		cout << count << endl;
	}
	return 0;
}
