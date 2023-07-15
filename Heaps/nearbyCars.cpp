#include<iostream>
#include<queue>
using namespace std;

class Cars{
	public: 
	int x;
	int y;
		Cars(int x_cord, int y_cord){
			x = x_cord;
			y = y_cord;
		}
		
		int dist(){
			return sqrt(x*x + y*y);
		}
};

class Compare{
	public:
		bool operator()(const Cars &a, const Cars &b){
			return a.dist()<b.dist();
		}
};

vector<Cars> kNearestCar(vector<Cars> cars, int k){
	int n = cars.size();
	
	priority_queue<Cars, vector<Cars>, compare> max_heap(cars.begin(), cars.begin()+k);
	
	for(int i = k; i<n; i++){
		if(max_heap.top()>cars[i]){
			max_heap.pop();
			max_heap.push(cars[i]);
		}
	}
	
	vector<Cars> result(k);
	for(int i=0; i<k; i++){
		result.push_back(max_heap.top());
		max_heap.pop();
	}
	
	return result;
}

int main(){
	
	
}
