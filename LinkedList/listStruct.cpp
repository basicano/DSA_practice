#include<iostream>

using namespace std;

class LList;

class Node{
	int val;
	Node *next;
	public:
		Node(){
			next = NULL;
		}
		
		Node(int v){
			val = v;
			next = NULL;
		}
		
		friend class LList;
};

class LList{
	Node *head;
	Node *tail;
	
	public:
		LList(){
			head = NULL;
		}
		
		void insert(int key){
			if(head == NULL){
				Node *n = new Node(key);
				head = tail = n;
				return;
			}
			
			Node *n = new Node(key);
			tail->next = n;
			tail = n;
		}
		
		void insert_at_head(int key){
			Node *n = new Node(key);
			n->next = head;
			if(head==NULL) tail = n;
			head = n;
			return;
		}
		
		void remove(int key){
			if(head== NULL) return;
			
			if(head->val == key){
				Node *temp = head;
				head = head->next;
				delete temp;
				return;
			}
			
			Node *temp = head->next, *prev = head;
			while(temp!=NULL){
				if(temp->val == key){
					prev->next = temp->next;
					delete temp;
					return;
				}
				temp = temp->next;
				prev = prev->next;
			}
		}
		
		void search(int key){
			Node *temp = head;
			while(temp!= NULL){
				if(temp->val == key){
					cout<<"key found"<<endl;
					return;
				}
				temp = temp->next;
			}
			cout<<"key not found"<<endl;
		}
		
		void print(){
			Node *temp = head;
			while(temp != NULL){
				cout<<temp->val<<" ";
				temp = temp->next;
			}
			cout<<endl;
			return;
		}
};

int main(){
	LList l;
	l.insert(1);
	l.insert(2);
	l.insert(3);
	l.print();	
	l.search(2);
	l.remove(2);
	l.print();
}
