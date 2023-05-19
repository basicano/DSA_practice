#include<iostream>
#include<vector>
using namespace std;

void printvec(vector<int> v){
	for(int i=0; i<v.size(); i++){
		cout<<v[i] <<" ";
	}

//	not allowed in this c++ version 
//	for(int x : v){
//		cout<<x<<" ";
//	}
}

int main(){
	cout<<" ___BASIC VECTORS ___\n";
//	vector<int> varr;	
//	int ch=1, temp;		
//	while(ch==1){
//		cout<<"\n Enter the elements of the vector : ";
////		cin>>temp;	
//		temp = 3;	
//		varr.push_back(temp);
//		cout<<" The current vector is : ";
//		printvec(varr);
//		cout<<"\n Size of the vector is: "<<varr.size();
//		cout<<"\n Capacity of the vector is: "<<varr.capacity();
//		cout<<"\n Do you want to enter more (0/1):";
//		cin>>ch;
//	}
//	
//	cout <<" -----------------------------------------------  ";
//	ch=1;
//	while(ch==1){
//		if(varr.empty()) {
//			cout<<" Vector empty !!";
//			break;
//		}
//		cout<<"\n Popping the last element of the vector : ";	
//		varr.pop_back();
//		cout<<"\n The current vector is : ";
//		printvec(varr);
//		cout<<"\n  Size of the vector is: "<<varr.size();
//		cout<<"\n  Capacity of the vector is: "<<varr.capacity();
//		cout<<"\n Do you want to pop more (0/1):";
//		cin>>ch;
//	}
//	
	
	cout<<" Implementing 2D array :\n";
	
	vector< vector<int> > vec2d ;
	vector<int> in_vec[3];
	
	for(int i = 0; i<3; i++){
		for(int j=0; j<5; j++){
			in_vec[i].push_back((i+1)*(j+1));
		}
		vec2d.push_back(in_vec[i]);
	}
	
	for(int i = 0; i<3; i++){
		for(int j=0; j<5; j++){
			cout<<vec2d[i][j]<<" ";
		}
		cout<<endl;
		
	}
			
}
