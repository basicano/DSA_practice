#include<iostream>

using namespace std;

class Node{
	public:
		int val;
		Node* next;
		Node(int v){
			val = v ;
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
	
//	temp = m_head;
//	while(temp!= NULL){
//		cout<<temp->val<<" ";
//		temp = temp->next;
//	}
//	cout<<endl;
	return m_head;
}

Node* merge_sort(Node *head){
	if(head == NULL || head->next==NULL) return head;
	
	Node *slow = head , *fast = (head->next == NULL)? head->next: head->next->next;;
	while(fast != NULL){
		slow = slow->next;
		fast = (fast->next == NULL)? fast->next: fast->next->next;
	}
	Node *l1 = head, *l2 = slow->next;
	slow->next = NULL;
	l1 = merge_sort(l1);
	l2 = merge_sort(l2);
	return merge(l1,l2);	
}



int main(){
	Node *head;
	
	head = new Node(4);
	Node *temp = head;
	temp->next = new Node(1);
	temp = temp->next;
	temp->next = new Node(2);
	temp = temp->next;
	temp->next = new Node(5);
	temp = temp->next;
	temp->next = new Node(6);
	temp = temp->next;
	temp->next = new Node(3);
	
	
	temp = merge_sort(head);	
	while(temp!=NULL){
		cout<<temp->val<<" ";
		temp = temp->next;
	}
}
