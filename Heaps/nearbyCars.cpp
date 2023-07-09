#include<iostream>
#include<queue>
using namespace std;

class Cars{
	int x;
	int y;
	public: 
		Cars(int x_cord, int y_cord){
			x = x_cord;
			y = y_cord;
		}
		
		int dist(){
			return sqrt(x*x + y*y);
		}
};

int main(){
	priority_queue<int> pq;
	
}
