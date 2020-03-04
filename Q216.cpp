#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
#include <cstdio>
using namespace std;

struct node{
	int x;
	int y;
};

vector<node> v;
int nextdecessor[8];
int nextdecessor_tmp[8];
int visted[8];
int visited_tmp[8];
double dis[8],dis_tmp[8];
double ans,ans_tmp;
int n,size;

double getdis(double x1, double y1 ,double x2, double y2){
	return sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
}

void DFS(int start, int count){
	//cout << "ans_tmp: " << ans_tmp << endl;
	if(count == size){
		//cout << "hi" << endl;
		if(ans > ans_tmp){
			ans = ans_tmp;
			for(int i = 0;i < 8;i++){
				nextdecessor[i] = nextdecessor_tmp[i];
				dis[i] = dis_tmp[i];
			}
		}
		return;
	}
	//bool flag = true;
	for(int i = 0;i < size;i++){
		//cout << "hi" << endl;
		if(i == start) continue;
		//cout << "hello" << endl;
		if(visited_tmp[i] == 0){
			double len = getdis((double)v[start].x, (double)v[start].y, 
			(double)v[i].x, (double)v[i].y)+16;
			ans_tmp += len;
			dis_tmp[start] = len;
			//cout<< start << "to" << i << " is " << len << endl;
			count++;
			nextdecessor_tmp[start] = i;
			visited_tmp[start] = 1;
			DFS(i, count);
			nextdecessor_tmp[i] = -1;
			visited_tmp[start] = 0;
			count--;
			ans_tmp -= len;
		}
	}
	
}

int main(){
	int num = 1;
	while(cin >> n){
		if(n == 0) break;
		v.clear();
		memset(nextdecessor, -1, 8);
		memset(visted, 0, 8);
		memset(nextdecessor_tmp, -1, 8);
		memset(visited_tmp, 0, 8);
		memset(dis, 0, 8);
		memset(dis_tmp, 0, 8);
		ans = 1000;
		ans_tmp = 0;
		//cout << visited_tmp[7] << endl;
		size = n;
		while(n--){
			node n1;
			cin >> n1.x >> n1.y;
			//cout << n1.x << endl;
			v.push_back(n1);
		}
		DFS(0,1);
		cout << "**********************************************************" << endl;
		cout << "Network #" << num << endl;
		for(int i = 0;i < size;i++){
			if(nextdecessor[i] == -1) continue;
			printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2lf feet.\n",
			v[i].x, v[i].y, v[nextdecessor[i]].x, v[nextdecessor[i]].y, dis[i]);
		}
		printf("Number of feet of cable required is %.2lf.\n", ans);
		//cout << ans << endl;
		//cout << getdis(5, 19, 55, 28) << endl;
		num++;
	}
}
