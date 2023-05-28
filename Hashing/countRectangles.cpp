#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;

bool compare(pair<int,int> a, pair<int,int> b){
	return a.first<b.first;
}

class HashCompare{

public:
	bool operator()( pair<int,int> p1, pair<int,int> p2){
		if(p1.first==p2.first){
			return p1.second < p2.second;
		}
		return p1.first < p2.first;
	}
};

int count_rectangles(vector< pair<int,int> > points){
	set<pair<int,int>, HashCompare> s;
	for(auto i: points){
		s.insert(i);
	}
	
	sort(points.begin(), points.end(), compare);
	int x_dist, y_dist;
	int count = 0;
	for(int i=0; i<points.size(); i++){
		for(int j=i+1; j<points.size(); j++){	
//			FORGOT A BASIC CHECK if the points i and j lie on the same line
			if(points[i].first == points[j].first || points[i].second==points[j].second) 	continue;
			if( s.find( {points[i].first, points[j].second} ) !=s.end() && s.find( {points[j].first, points[i].second} ) !=s.end() ){
				count++; 
			}			
		}
	}
//	FORGOT to divide by 2
	return count/2;
}

int main() {


	vector< pair<int, int> > points{{4,1},{4,0},{0,0},{0,1},{1,1},{1,0},{2,0},{2,1}};

	cout << count_rectangles(points) << endl;
	return 0;
}
