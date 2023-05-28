#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Trie;

class Node{
	int i;
	Node **bi_node;
	bool is_terminal;
	public:
		Node(int i){
			this->i = i;
			this->bi_node = new Node*[2];
			for(int i=0;i<2; i++){
				bi_node[i] = NULL;
			}
			this->is_terminal = false;
		}
		
	friend class Trie;
};

class Trie{
	Node *root;
	public:
		Trie(){
			root = new Node(-1);
		}
		
		void add_bi_num(int num){
			Node *temp = root;
			int all_digits = 6;
			while(all_digits--){
				int digit = num&1;
//				cout<<digit;
				if(temp->bi_node[digit] == NULL) 
					temp->bi_node[digit] = new Node(digit);
				temp = temp->bi_node[digit];
				num = num>>1;
			}
			temp->is_terminal = true;
		}
		
		bool search(int num){
			Node *temp = root;
			int digits = 6;
			while(digits--){
				int digit = num&1;
//				cout<<digit;
				if(temp->bi_node[digit] == NULL) 
					return false;
				temp = temp->bi_node[digit];
				num = num>>1;
			}
			temp->is_terminal = true;
			return true;
		}
		
		int max_xor(vector<int> nums){
			int max_xor = INT_MIN;
			for(int i=0; i<nums.size(); i++){
				int temp = nums[i];
				cout<<temp<<" ";
				Node *t_node = root;
				int xor_res = 0;
				int digit = 0;
				while(digit<6){
					int t_digit = temp & 1;
					cout<<t_digit;
					if(t_digit == 1){
						if(t_node->bi_node[0] != NULL){
							xor_res = xor_res| 1<<digit;							
							cout<<":"<<xor_res<<"  ";
							t_node = t_node->bi_node[0];
						}
						else if(t_node->bi_node[1] != NULL){						
							cout<<":"<<xor_res<<"  ";
							t_node = t_node->bi_node[1];
						}
						else{
							break;
						}
					}
					else{
						if(t_node->bi_node[1] != NULL){
							xor_res = xor_res| 1<<digit;					
							cout<<":"<<xor_res<<"  ";
							t_node = t_node->bi_node[1];
						}
						else if(t_node->bi_node[0] != NULL){						
							cout<<":"<<xor_res<<"  ";
							t_node = t_node->bi_node[0];
						}
						else{
							break;
						}
					}
					temp = temp>>1;
					digit++;
				}
				cout<<endl;
				if(xor_res>max_xor){
					max_xor  = xor_res;
				}
			}
			return max_xor;
		}	
};

int main(){
	vector<int> nums{3,10,5,25,8,2};
	Trie t;
	for(int i=0; i<nums.size(); i++){
		t.add_bi_num(nums[i]);
//		cout<<endl;
	}
	for(int i=0; i<nums.size(); i++){
		t.search(nums[i]); 
//		cout<<endl;
	}
	
	cout<<t.max_xor(nums);
}
