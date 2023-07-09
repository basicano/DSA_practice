#include<iostream>
#include<vector>
//#include<priority_queue>
	
using namespace std; 

class MinHeap{
	public:
		MinHeap(vector<int> &nums){
			int n = nums.size();
			for(int i=(n-1)/2 ; i>0 ; i--){
				heapify(nums,i);
//				print_vector(nums);
//				cout<<endl;
			}
		}
		
		void heapify(vector<int> &nums, int parent_idx){
			if(parent_idx*2>nums.size()) return;
			
			int child_idx = parent_idx*2;
			int min = nums[child_idx]; 
			if( parent_idx*2s+1<nums.size() && nums[parent_idx*2+1]< min ){
				child_idx = parent_idx*2+1;
				min = nums[parent_idx*2+1];
			}
			
			if(nums[parent_idx] > min){
				swap(nums[child_idx], nums[parent_idx]);
				print_vector(nums); cout<<" ";
				heapify(nums, child_idx);
			}
			
			return;
		}
		
		void push(vector<int> &nums, int elem){
			nums.push_back(elem);
			int child = nums.size()-1;
			int parent = child/2;
			while(parent>0){
				if(nums[child]<nums[parent]){
					swap(nums[child], nums[parent]);
					child = parent;
					parent = child/2;
				}
			}
		}
		
		void pop(vector<int> &nums){
			int n = nums.size();
			swap(nums[1], nums[n-1]);
			nums.pop_back();
			heapify(nums, 1);
		}
		
		void print_vector(vector<int> &nums){
			for(int i=0; i<nums.size(); i++){
				cout<<nums[i]<<" ";
			}
		}
};

int main(){
//					 0  1 2 3  4 5  6 7
	vector<int> vec{ 0,11,3,2,15,5,45,4};
	
	MinHeap min_heap(vec);
	min_heap.print_vector(vec);	
	cout<<endl;
	
	min_heap.push(vec,1);
	min_heap.print_vector(vec);
	cout<<endl;
	
	min_heap.pop(vec);
	min_heap.print_vector(vec);
	
	
}
