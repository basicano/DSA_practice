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

Node* mid_el(Node *head){
	if(head == NULL) return head;
//	USING THE TERNARY OPERATOR GIVES THE EXACT MIDDLE POINT 
	Node *slow = head , *fast = (head->next == NULL)? head->next: head->next->next;;
	
	while(fast != NULL){
		slow = slow->next;
		fast = (fast->next == NULL)? fast->next: fast->next->next;
	}
	return slow;
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
	
	Node *ans = mid_el(head);
	if(ans) cout<<ans->val;
	
}
