#include<iostream>
#include<cstring>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int len = s.size();
        int int_val = 0;
        char ch;
        for (int i = 0; i<len; i++){
            ch = s[i];
            switch(ch){
                case 'I':
                    if(s[i+1]!='\0' && (s[i+1]=='X' || s[i+1]=='V' )) int_val -= 1;
                    else int_val += 1;
                    break;
                case 'V':
                    int_val += 5;
                    break;
                case 'X':
                    if(s[i+1]!='\0' && (s[i+1]=='L' || s[i+1]=='C' )) int_val -= 10;
                    else int_val += 10;
                    break;
                case 'L':
                    int_val += 50;
                    break;
                case 'C':
                    if(s[i+1]!='\0' && (s[i+1]=='D' || s[i+1]=='M' )) int_val -= 100;
                    else int_val += 100;
                    break;
                case 'D':
                    int_val += 500;
                    break;
                case 'M':
                    int_val += 1000;
                    break;
                default: 
                    cout<<"Incorrect input ";
                    return -1;
            }
        }
        return int_val;
    }
};


int main(int argc, char *argv[]){
  string str;
  cin>>str;     
  Solution s;
  s.romanToInt(str);
  return 0;
}
