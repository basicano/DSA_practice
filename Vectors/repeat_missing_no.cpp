#include<iostream>
#include<vector>
using namespace std;

vector<int> repeat_missing(const vector<int> &arr) {
    int n1 = arr.size();
    int sum_n = n1 + (n1+1)/2;
    
    int sum_arr = 0;
    for(int i=0; i<n1; i++){
        sum_arr += arr[i];
    }
    
    int hare = arr[0];
	int tortoise = arr[0];

	do{
		hare = arr[hare-1];
		tortoise = arr[arr[hare-1]-1];
	}while(hare != tortoise);

	int start= arr[0];
	while(tortoise != start){
		tortoise = arr[tortoise-1];
		start = arr[start-1];
	}

	int repated_no = start;
    
    int missing_no = repated_no + sum_n - sum_arr; 

    vector<int> result;
	result.push_back(missing_no);
	result.push_back(repated_no);
	return result;
}

vector<int> repeatedNumber(const vector<int> &arr) {
    int n1 = arr.size();
    int sum_n = n1*(n1+1)/2;
    long long sum_nsq = (2*n1+1)*(n1+1)*n1/6;
    
    int sum_arr = 0;
    long long sum_sq_arr = 0;
    for(int i=0; i<n1; i++){
        sum_arr += arr[i];
        sum_sq_arr += arr[i]*arr[i];
    }
    
    int AminusB = abs(sum_n-sum_arr);
    int AplusBintoAminusB = abs(sum_nsq-sum_sq_arr);
    
    int AplusB = AplusBintoAminusB/AminusB;
    int A = (AplusB + AminusB)/2;
    int B = (AplusB -AminusB)/2;
    
    for(int i=0; i<n1; i++){
        if(arr[i]==B){
            swap(A,B);
            break;
        }
    }

    vector<int> result;
	result.push_back(A);
	result.push_back(B);
	return result;
}
