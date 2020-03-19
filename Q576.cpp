#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string str,end = "e/o/i";
    while(getline(cin, str)){
        if(str == end) break;
        int size = str.size(),count = 0,order = 1;
        bool flag = false;
        for(int i = 0;i < size;i++){
            if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i'
            || str[i] == 'o' || str[i] == 'u' || str[i] == 'y'){
                if(i > 0 && flag){continue;}
                flag = true;
                count++;
            }
            else{flag = false;}
            if(str[i] == '/' || i == size-1){
                if(order == 1 || order == 3){
                    if(count != 5){
                        cout << order << endl;
                        break;
                    }
                    else if(i == size-1){
                        cout << "Y" << endl;
                    }
                }
                else{
                    if(count != 7){
                        cout << order << endl;
                        break;
                    }
                }
                order++;
                count = 0;
                continue;
            }
        }
    }
    return 0;
}
