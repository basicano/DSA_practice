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

Node* head_of_cycle(Node* head){
	if(head==NULL) return NULL;
	Node *slow = head, *fast = head;					
	
	while(fast!=NULL){
		slow = slow->next;
		fast = (fast->next == NULL)? fast->next: fast->next->next;
		
		if(slow==fast){
			Node *t_new = head;
			while( t_new != slow ){
				t_new = t_new->next;
				slow = slow->next;
			}
			return slow;
		}
	}
	
	return NULL;
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
	temp->next = head->next->next;
	
	temp = head_of_cycle(head) ;
	cout<<temp->val;
}
