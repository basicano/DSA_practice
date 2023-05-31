#include<iostream>
using namespace std;

int mySqrtOPT(int x) {
    if (x==0) return 0;
    int first = 1, last = x;
    while(first<=last){
        int mid=first + (last-first)/2;
        if (mid == x/mid) return mid;
        if (mid <= x/mid) {first = mid+1;}
        else {last = mid-1;}
    }
    return last;	// WHY RETURN LAST? If mid < x/mid then mid is a possible answer and first is changed 
    				//										if first == last and after this we exit then last and mid is at correct place
    				//					If mid> x/mid  then mid is not a possible answer 
    				//										if first == last then last = mid-1 which is the correct answer
}
    
int mySqrt(int x) {
    // search space is 0 to x
    int start = 0, end = x;
    long long mid =(start+end)/2;
    long long pos_sq;					// long long is required when x is int_max

    while( start <= end ){
        mid = (start+end)/2;
        pos_sq = mid*mid;

        if(pos_sq == x) return mid;
        else if(pos_sq < x){
            start = mid+1;
        }
        else if(pos_sq > x){
            end = mid-1;
        }
    }

    if(pos_sq > x) return mid-1;
    return mid;
}

int main(){
	
}
