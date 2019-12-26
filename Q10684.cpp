#include <iostream>
#include <vector>
using namespace std;

int main(){
	int N;
	while(cin >> N){
		if(N == 0) break;
		vector<int> input;
		int ans = -1,temp = 0,money,len = 0;
		for(int i = 0;i < N;i++){
			cin >> money;
			input.push_back(money);
		}
		len = input.size();
		for(int i = 0;i < len;i++){
			temp += input[i];
			//ans = temp;
			for(int j = i+1;j < len;j++){
				if(ans < temp) ans = temp;
				temp += input[j];
				if(ans < temp) ans = temp;
			}
			temp = 0;
		}
		if(ans != -1) cout << "The maximum winning streak is " << ans << "." << endl;
		else if(ans == -1) cout << "Losing streak." << endl;
	}
}
