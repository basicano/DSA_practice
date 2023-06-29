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

class TNode{
	public:
		int val;
		TNode *left;
		TNode *right;
		TNode(int v){
			val = v ;
			left = right = NULL;
		}
};

TNode* LL_to_BST(Node *head){
	if(head == NULL) return NULL; 
	Node *slow = head , *fast = (head->next == NULL)? head->next: head->next->next;;
	
	while(fast != NULL){
		slow = slow->next;
		fast = (fast->next == NULL)? fast->next: fast->next->next;
	}
	
	TNode *t = new TNode(slow->val);
	t->left = LL_to_BST(slow->next);
	
	Node *temp = slow->next;
	slow->next = NULL;
	
	t->right = LL_to_BST(head);
	slow->next = temp;
	return t;
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
	
	LL_to_BST(head);
	
}
