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

Node* merge(Node *l1, Node *l2){
	if(l1 == NULL) return l2;
	if(l2 == NULL) return l1;
	
	Node *m_head;
	if(l1->val < l2->val){
		m_head = l1;
		l1 = l1->next;
	}
	else{
		m_head = l2;
		l2 = l2->next;
	}
	
	Node *temp = m_head;
	while( l1 != NULL && l2 != NULL){
		
		if(l1->val < l2->val){
			temp->next = l1;
			l1 = l1->next;
		}
		else{
			temp->next = l2;
			l2 = l2->next;
		}
		
		temp = temp->next;
	}
	
	if(l1 == NULL){
		temp->next = l2;
	}
	else{
		temp->next = l1;
	}
	
	return m_head;
}

int main(){
	Node *head1, *head2;
	
	head1 = new Node(1);
	Node *temp = head1;
	temp->next = new Node(3);
	temp = temp->next;
	temp->next = new Node(5);
	temp = temp->next;
	temp->next = new Node(7);
	temp = temp->next;
	temp->next = new Node(9);
	
	head2 = new Node(2);
	temp = head2;
	temp->next = new Node(4);
	temp = temp->next;
	temp->next = new Node(6);
	temp = temp->next;
	temp->next = new Node(8);
	temp = temp->next;
	temp->next = new Node(10);
	
	Node *m_list = merge(head1, head2);
	temp = m_list;
	while( temp != NULL ){
		cout<<temp->val<<" ";
		temp = temp->next;
	}
	return;		
}
