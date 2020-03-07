#include <iostream>
#include <cstdio>
using namespace std;

struct date{
	int month;
	int day;
	int year;
};

int month_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

void constellation(date birth){
	if((birth.month == 1 && birth.day >= 21) || (birth.month == 2 && birth.day <= 19))
		cout << "Aquarius";
	else if((birth.month == 2 && birth.day >= 20) || (birth.month == 3 && birth.day <= 20))
		cout << "Pisces";
	else if((birth.month == 3 && birth.day >= 21) || (birth.month == 4 && birth.day <= 20))
		cout << "Aries";
	else if((birth.month == 4 && birth.day >= 21) || (birth.month == 5 && birth.day <= 21))
		cout << "Gemini";
	else if((birth.month == 6 && birth.day >= 22) || (birth.month == 7 && birth.day <= 22))
		cout << "Cancer";
	else if((birth.month == 7 && birth.day >= 23) || (birth.month == 8 && birth.day <= 21))
		cout << "Leo";
	else if((birth.month == 8 && birth.day >= 22) || (birth.month == 9 && birth.day <= 23))
		cout << "Virgo";
	else if((birth.month == 9 && birth.day >= 24) || (birth.month == 10 && birth.day <= 23))
		cout << "Libra";
	else if((birth.month == 10 && birth.day >= 24) || (birth.month == 11 && birth.day <= 22))
		cout << "Scorpio";
	else if((birth.month == 11 && birth.day >= 23) || (birth.month == 12 && birth.day <= 22))
		cout << "Sagittarius";
	else if((birth.month == 12 && birth.day >= 23) || (birth.month == 1 && birth.day <= 20))
		cout << "Capricorn";
	return;
}

bool isleap(int year){
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return true;
	else{ return false;}
}

date getBirth(date d){
	int remain = 280;
	while(remain--){
		d.day++;
		if(isleap(d.year)) month_day[1] = 29; 
		else {month_day[1] = 28;}
		if(d.day > month_day[(d.month)-1]){
			d.day = 1;
			d.month++;
		}
		if(d.month > 12) d.year++;
		d.month = d.month%12;
	}
	return d;
}

int main(){
	int n,num = 1;
	cin >> n;
	while(num <= n){
		date d,birth;
		scanf("%2d%2d%4d",&d.month,&d.day,&d.year);
		birth = getBirth(d);
		printf("%d %02d/%02d/%d ",num,birth.month,birth.day,birth.year);
		constellation(birth);
		cout << endl;
		num++;
	}
	return 0;
}
