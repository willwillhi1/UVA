#include <iostream>
using namespace std;

int main(){
	string x,y;
	while(cin >> x >> y){
		int ans[500] = {0};
		int y_size = y.size(),x_size = x.size();
		for(int i = y_size-1;i >= 0;i--){
			int next_ans_index = y_size-i-1;
			for(int j = x_size-1,add = 0;j >= 0;j--,add++){
				int num = (y[i]-'0')*(x[j]-'0');
				int temp = ans[next_ans_index+add] + num;
				if(temp >= 10){
					int next = 0;
					while(temp >= 10){
						ans[next_ans_index+add+next] = temp%10;
						ans[next_ans_index+add+next+1] += temp/10;
						next++;
						temp = ans[next_ans_index+add+next];
					}
				}
				else{
					ans[next_ans_index+add] = temp;
				}
			}
		}
		bool flag = false;
		for(int i = 499;i >= 0;i--){
			if(!flag && ans[i] == 0) continue;
			else{
				cout << ans[i];
				flag = true;
			}
		}
		cout << endl;
	}
	return 0;
}
