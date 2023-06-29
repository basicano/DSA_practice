#include<iostream>

using namespace std;

class Node{
	public:
		int val;
		Node *next;
		Node(int v){
			val = v;
			next = NULL;
		}
};

Node* reverse(Node *head){
	if(head==NULL || head->next==NULL) return head;
	
	Node *prev=NULL , *cur=head, *next_n;	
	while(cur!=NULL){
		next_n = cur->next;
		cur->next = prev;
		prev = cur;
		cur = next_n;
	}
	Node *temp = prev;
	
	while(temp!=NULL){
		cout<<temp->val<<" ";
		temp = temp->next;
	}
		
	return prev;
}

int main(){
	Node *head;
	
	head = new Node(1);
	Node *temp = head;
	temp->next = new Node(2);
	temp = temp->next;
	temp->next = new Node(3);
	temp = temp->next;
	temp->next = new Node(4);
	temp = temp->next;
	temp->next = new Node(5);
	
	reverse(head);
		
}
