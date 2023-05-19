#include<iostream>
#include<cstring>
using namespace std;

int main(){
	int n;
	cout<<"Enter the value of n: ";
	cin>>n;
	char cur_str[50], max_str[50];
	int cur, max=0;
	
	for(int i=0; i<n; i++){
		cin.getline(cur_str,50);
		cur = strlen(cur_str);
		if(cur>max){
			max = cur;
			strcpy(max_str, cur_str);
		}
	}
	
	cout<<"String with max length is : "<<max_str;
	return 0;
}
