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

Node* kReverse(Node *head, int k){	
	if(head==NULL) return NULL;
	
	Node *temp = head;
	Node *prev_n = NULL, *cur_n = head , *next_n;
	int counter = 0;
//	set head
	Node *save_past_link = head;
	while(cur_n!= NULL && counter<k){
		next_n = cur_n->next;
		cur_n->next = prev_n;
		prev_n = cur_n;
		cur_n = next_n;		
		counter++;
	}
	head = prev_n;
	save_past_link->next = kReverse(cur_n, 3);
	return head;
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
	temp = temp->next;
	temp->next = new Node(6);
	temp = temp->next;
	temp->next = new Node(7);
	temp = temp->next;
	temp->next = new Node(8);
//	temp->next = NULL;
	temp = head;
	while(temp!=NULL){
		cout<<temp->val<<" ";
		temp = temp->next;
	}
	cout<<endl;
	temp = kReverse(head,3);
	while(temp!=NULL){
		cout<<temp->val<<" ";
		temp = temp->next;
	}
		
}
