#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct word{
	string str;
	struct word *next = NULL; 
};

int main(){
	char c;
	struct word *head = NULL;
	struct word *pre = NULL;
	while((c = getchar()) != EOF){
		string s;
		if(c == '0') break;
		else if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){
			struct word *current = NULL;
			current = (struct word*)malloc(sizeof(struct word));
			s.push_back(c);
			while(c = getchar()){
				if((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')){s.push_back(c);}
				else{
					current -> str = s;
					if(head == NULL) head = current;
					else{pre -> next = current;}
					pre = current;
					cout << current->str << c;
					break;
				}
			}
		}
		else if(c >= '0' && c <= '9'){
			s.push_back(c);
			while(c = getchar()){
				if(c >= '0' && c <= '9'){s.push_back(c);}
				else{
					int len = 0,count = 0,str_len = s.size();
					struct word *find_ptr = head,*pre_ptr,*end = pre;
					for(struct word *ptr = head;ptr != NULL;ptr = ptr->next,len++);
					for(int i = 1;i <= str_len;i++) count += (s[i-1]-'0')*pow(10, str_len-i);
					for(int i = 1;i <= len-count;i++){
						pre_ptr = find_ptr;
						find_ptr = find_ptr -> next;
					}
					cout << find_ptr->str << c;
					//move repeat element to the front
					if(count != 1){
						pre_ptr -> next = find_ptr-> next;
						find_ptr -> next = NULL;
						end -> next = find_ptr;
					}		
					pre = find_ptr;
					break;
				}
			}
		}
		else{cout << c;}
	}
	return 0;
}
