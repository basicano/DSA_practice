#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void printSubsets(char *input, char *output, int i, int j, vector<string> &list){
    //  Base Case
    if(input[i] == '\0'){
        // print the output
        output[j] = '\0';
        if(output[0]=='\0'){
            string temp="NULL";
            list.push_back(temp);
            return;
        }
        string temp(output);
        list.push_back(temp);
        return;
    }

    // Recursive Calls
    output[j] = input[i];
    // include input[i]
    printSubsets(input, output, i+1, j+1,list);
    // exclude input[i]
    printSubsets(input,output,i+1,j,list);
}

bool comparator(string s1, string s2){
    if(s1.length()<s2.length()){
        return true;
    }
    else if(s1.length() > s2.length()){
        return false;
    }
    else{
        for(int i=0; i<s1.length(); i++){
            if(s2[i] < s1[i]){
                return false;
            }
        }
        return true;
    }
}

int main(){
    char input[4]="abc";
    char output[4] = "";
    vector<string> list;
    printSubsets(input, output, 0,0, list);
    sort(list.begin(), list.end(), comparator);
    for(int i=0; i<list.size(); i++) cout<<list[i]<<" ";
}