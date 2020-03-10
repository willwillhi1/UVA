#include <iostream>
using namespace std;

int HextoDec(string s){
    int size = s.size();
    int sum = 0;
    int hex_array[3] = {1,16,256};
    for(int i = 1;i <= 3;i++){
        if(size >= i){
            if(s[size-i] == 'A') sum += 10*hex_array[size-i];
            else if(s[size-i] == 'B') sum += 11*hex_array[size-i];
            else if(s[size-i] == 'C') sum += 12*hex_array[size-i];
            else if(s[size-i] == 'D') sum += 13*hex_array[size-i];
            else if(s[size-i] == 'E') sum += 14*hex_array[size-i];
            else if(s[size-i] == 'F') sum += 15*hex_array[size-i];
            else{ sum += (s[size-i] - '0')*hex_array[size-i];}
        }
    }
    return sum;
}

string DectoBin(int num){
    string Bin;
    while(num > 1){
       Bin.push_back('0' + num % 2);
       num /= 2;
    }
    Bin.push_back('0' + num);
    return Bin;
}

void print(string s){
    int size = s.size();
    for(int i = 12;i >= 0;i--){
        if(i > size-1) cout << '0';
        else{ cout << s[i]; }
    }
}

int main(){
    int N;
    cin >> N;
    while(N--){
        string s1,s2,opt;
        cin >> s1 >> opt >> s2;
        int Dec_s1,Dec_s2; 
        int sum;
        Dec_s1 = HextoDec(s1);
        Dec_s2 = HextoDec(s2);
        string Bin_s1 = DectoBin(Dec_s1);
        string Bin_s2 = DectoBin(Dec_s2);
        if(opt[0] == '+') sum = Dec_s1 + Dec_s2;
        else if(opt[0] == '-') sum = Dec_s1 - Dec_s2;
        print(Bin_s1);
        cout << " " << opt << " ";
        print(Bin_s2);
        cout << " = " << sum << endl;
    }
    return 0;
}
