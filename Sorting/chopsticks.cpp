#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int pairSticks(vector<int> length, int D)
{
    int count=0;
    sort(length.begin(),length.end());
	//   simple logic, sort and find closest pair that can form with a num, if cant form with just next then also cant with those after it, 
	//	if can form then always choose closest, just like interval scheduling
    for(int i=0;i<length.size()-1;i++){
        if(length[i+1]-length[i]<=D){
            count++;
            i=i+1;// jump two if pair formed so this element is not included
        }
    }
    return count;
    
}
