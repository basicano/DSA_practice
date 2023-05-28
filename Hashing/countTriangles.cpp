#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int countTriangles(vector<pair<int,int>> points){
	unordered_map<int,int> x_cord;
	unordered_map<int, int> y_cord;
	
	for(auto i: points){
		x_cord[i.first]++;
		y_cord[i.second]++;
	}
	
	int count = 0;
	for(auto i: points){
		if(x_cord.find(i.first) != x_cord.end() && x_cord[i.first]>1 && y_cord.find(i.second)!= y_cord.end() && y_cord[i.second]>1){
			count+= x_cord[i.first] * y_cord[i.second];
		}
	}
	return count;
}

int main() {
    vector<pair<int,int> > points{{1,2},{2,1},{2,2},{2,3},{3,2}};

    cout<<countTriangles(points) <<endl;

    return 0;
}
