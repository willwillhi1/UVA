#include <stdio.h>
#include <iostream>

using namespace std;

struct tree{
	int val = 0;
	tree *R = nullptr;
	tree *L = nullptr;
};

tree *insert(tree *head,int node){
	tree *N = new tree;
	N->val = node;
	if(head == nullptr) return N;
	
	tree *T = head, *next = head;
	while(next != nullptr){
		T = next;
		if(next->val > node){
			next = next->L;
		}
		else next = next->R;
	}
	
	if(T->val > node){
		T->L = N;
	}
	else T->R = N;
	
	return head;
}

void Post_Order(tree *head){
	if(head == nullptr) return;
	Post_Order(head->L);
	Post_Order(head->R);
	printf("%d\n", head->val);
}

int main(){
	int node;
	tree *head = nullptr;
	while(scanf("%d",&node) != EOF){
		head = insert(head,node);
	}
	//cout << "left value: " << head->L->val << endl;
	Post_Order(head);
	return 0;
}
