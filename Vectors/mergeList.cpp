#include<iostream>
#include<vector>
using namespace std;

void printvec(vector<int> v){
	for(int i=0; i<v.size(); i++){
		cout<<v[i]<<" ";
	}
}

void mergeSortedLists(vector<int> &list1,vector<int> &list2){
    int i=0,j=0;
    while( i<list1.size() && j<list2.size() ){
    	if(list1[i]<=list2[j]){
    		cout<<list1[i++]<<" ";
		}
		else{
			cout<<list2[j++]<<" ";
		}  
    }    
    while( i<list1.size() ){
    	cout<<list1[i++];
	}
    
    while( j<list2.size() ){
    	cout<<list2[j++];
	}
}

int main(){	
	vector<int> vec1;
	for(int i=11; i<20; i+=2){
		vec1.push_back(i);
	}
	printvec(vec1);	
	cout<<"\n";	
	
	vector<int> vec2;
	for(int i=12; i<=20; i+=2){
		vec2.push_back(i);
	}
	printvec(vec2);	
	cout<<"\n";
	
	cout<<" Merged list is: ";	
	mergeSortedLists(vec1, vec2);		
	return 0;
}
