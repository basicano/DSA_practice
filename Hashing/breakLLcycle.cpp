#include<iostream>
#include<unordered_set>

using namespace std;

class node{
public:  
  int data;
  node * next;
  
  node(int data){
      this->data = data;
  }
};


 node * breakChain(node * head){
    //Complete this method
    unordered_set< node* > s;
	node *temp = head;
	s.insert(head);
	while(temp != NULL){
//		cout<<temp->data<<" ";
		if(s.find(temp->next)!=s.end()){
			temp->next = NULL;
			return head;
		}
		s.insert(temp->next);
		temp = temp->next;
	}   
     
     return head;
 }
 
 
 int main(){
 	node *head = new node(1);
 	head->next = new node(2);
 	head->next->next = new node(3);
 	head->next->next->next = new node(4);
 	head->next->next->next->next = new node(5);
 	node *h6 = head->next->next;
 	head->next->next->next->next->next = h6;
 	head = breakChain(head);
 	node *temp = head;
 	cout<<endl;
 	while(temp != NULL){
 		cout<<temp->data<<" ";
 		temp = temp->next;
	}
 }



