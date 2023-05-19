#include<iostream>
#include<vector>
using namespace std;

void print(vector<string> vec){
	for(int i=0; i<vec.size(); i++){
		cout<<vec[i]<<" ";
	}
}


void sortList(vector<int> &vec){
    int key;    
    int i,j;
    for(i=1; i<vec.size(); i++){
        key = vec[i];
        for(j=i-1; j>=0; j--){
            if(vec[j] < key){
                break;
            }
            vec[j+1] = vec[j];
        }
        vec[j+1] = key;
    }
    
}

void sortString(vector<string> &vec){
	string key;    
    int i,j,k;
    bool insert;
    for(i=1; i<vec.size(); i++){
        key = vec[i];
        insert =1;
        for(j=i-1; j>=0 && insert; j--){
            if(vec[j][0] > key[0]){
                vec[j+1] = vec[j];
            }
            else if(vec[j][0] == key[0]){
            	for( k=0; k<vec[j].length() && k<key.length(); k++ ){
            		if(vec[j][k] > key[k]){
            			vec[j+1] = key;
            			insert=0;
            			break;
					}
				}
				if(insert && k == vec[j].length()){
					vec[j+1] = key;
        			insert=0;
				}
				
			}
			else{
				insert=0;
				vec[j+1] = key;
			}
        }
        if(insert && j==-1){
        	vec[j+1] = key;
		}
//		print(vec);
//		cout<<"\n";
    }
}


int main(){	
	vector<string> vec;
//	for(int i=5; i>0; i--){
//		vec.push_back(i);
//	}
	string i = "bc";
	vec.push_back(i);
	i = "c";
	vec.push_back(i);
	i = "abc";
	vec.push_back(i);
	i = "aa";
	vec.push_back(i);
	i = "aabc";
	vec.push_back(i);
	i = "abbc";
	vec.push_back(i);
	
	for(int i=0; i<vec.size(); i++){
		cout<<vec[i]<<" ";
	}
	
	cout<<"\n";	
	sortString(vec);
		
	print(vec);
	return 0;
}
