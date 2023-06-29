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

bool detect_cycle(Node* head){
	if(head==NULL) return false;
	Node *slow = head, *fast = (head->next == NULL)? head->next: head->next->next;
	
	while(fast!=NULL){
		if(slow==fast) return true;
		slow = slow->next;
		fast = (fast->next == NULL)? fast->next: fast->next->next;
	}
	
	return false;
	
	
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
	temp->next = head->next;
	
	if(detect_cycle(head) ) cout<<"true";
	else cout<<"false";
}
