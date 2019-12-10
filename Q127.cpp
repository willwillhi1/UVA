#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

struct card{
	char suit = '0';
	char value = '0';
};

int main(){
	stack<card> pile[55];
	card input;
	int left1, left3, count1, count3, pilenum;
	
	while((input.value = getchar()) != EOF && input.value != '#'){
		//initialize pile
		for(int i = 0;i < 55;i++){
			while( !pile[i].empty() )
				pile[i].pop();
		}
		input.suit = getchar();
		getchar();
		pile[3].push(input);
		
		for(int i = 1;i < 52;i++){
			scanf("%c%c",&input.value,&input.suit);
			getchar();
			pile[i+3].push(input);
		}
		
		for(int i = 3;i < 55;i++){
			if( pile[i].empty() )continue;
			//find true left1,left3(not empty)
			left1 = i,left3 = i;
			count1 = 1,count3 = 3;
			while(count3){
				if(count1) left1--;
				left3--;
				if(left3 < 3) break;
				if( !pile[left3].empty() ){
					if( count1 ) count1--;
					count3--;
				}
			}
			//move
			if(!pile[left3].empty() && 
			(pile[i].top().suit == pile[left3].top().suit || 
			 pile[i].top().value == pile[left3].top().value)){
				pile[left3].push(pile[i].top());
				pile[i].pop();
				i = left3 - 1;
				continue;
			}
			else if(!pile[left1].empty() && 
			(pile[i].top().suit == pile[left1].top().suit || 
			 pile[i].top().value == pile[left1].top().value)){
				pile[left1].push(pile[i].top());
				pile[i].pop();
				i = left1 - 1;
			}
		}
		pilenum = 0;
		for( int i = 3 ; i < 55 ; i++ )
			if( !pile[i].empty() ) pilenum++;
		
		printf( "%d pile", pilenum );
		if( pilenum > 1 ) printf( "s" );
		printf( " remaining:" );
		for( int i = 3 ; i < 55 ; i++ )
			if( !pile[i].empty() ) printf( " %d", pile[i].size() );
		printf( "\n" );
	}
	return 0;
}
