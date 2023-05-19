#include<iostream>
#include<vector>
using namespace std;

void printPermutation(vector<int> v){
    for(int i=0; i<v.size(); i++)
        cout<<v[i];
    cout<<" ";
    return;
}

void permutations(vector<int> v, int n){
    if(n==v.size()){
        printPermutation(v);
        return;
    }

    for(int c=n; c<v.size(); c++){
        swap(v[n],v[c]);
        permutations(v, n+1);
        swap(v[c],v[n]);
    }
}

void permutations(char *arr, int len, int n){
    if(n==len){
        cout<<arr<<" ";
        return;
    }
    for(int c=n; c<len ; c++){
        swap(arr[n],arr[c]);
        permutations(arr,len, n+1);
        swap(arr[c],arr[n]);
    }
}

int main(){
    // vector<int> v;
    // v.push_back(1);
    // v.push_back(2);
    // v.push_back(3);
    // v.push_back(4);
    // permutations(v,0);
    char arr[] = {'a','b','c'};
    permutations(arr,3,0);
}