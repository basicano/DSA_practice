#include<iostream>
using namespace std;

void print(int A[], int size){
	for(int i=0; i<size; i++){
		cout<<A[i];
	}
}

int findMedian(int *A, int size,  int first, int last){		
	if(last==first){
		return A[first];
	}
	
	int median = (size-1)/2;	
	int pivot = last, pivot_el = A[pivot];	
	int temp,tempAi;
	for(int i=first; i<pivot; ){
		if(A[i]>pivot_el){
			tempAi = A[i];
			temp =  A[pivot-1];
			A[pivot-1] = A[pivot];
			A[pivot]= tempAi;
			A[i]= temp;
			--pivot;
		}
		else{
			i++;
		}
	}
	
	A[pivot] = pivot_el;
//	cout<<" pivot "<<pivot_el<<"   ";
//	print(A,size);
//	cout<<endl;
	if(pivot==median){
		return A[pivot];
	}
	else if(pivot<median){
		return findMedian(A,size,pivot+1,last);
	}
	else{
		return findMedian(A,size,first,pivot-1);
	}
}

int main(){
	int n;
	cout<<"Enter the size of the array :";
	cin>>n;
	int *a = new int[n];
	cout<<"Enter the elements of the array :";
	for(int i=0; i<n; i++){
		cin>>a[i];
	}
	
	int median = findMedian(a,n,0,n-1);
	cout<<"The median of the array is : "<<median;
	return 0;
}
