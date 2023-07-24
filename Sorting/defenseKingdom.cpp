#include<bits/stdc++.h>
#include<cmath>
using namespace std;

bool compare(pair<int,int> &a, pair<int,int> &b){
    return (a.second < b.second);
}

int defkin(int W, int H, vector<pair<int, int>> &position){
		
    position.push_back({W+1,H+1});
    vector<pair<int,int>> ypos = position;
    sort(position.begin(),position.end());
    sort(ypos.begin(),ypos.end(),compare);
    int xstart=0;
    int ystart=0;
    int maxblocks=INT_MIN;
    for(int i=0;i<position.size();i++){
        int xsize = position[i].first-xstart-1;
        for(int j=0;j<ypos.size();j++){
            int ysize = ypos[i].second-ystart-1;
            int blocks = xsize*ysize;
            maxblocks=max(maxblocks,blocks);
            ystart=ypos[i].second;
            
        }
        xstart=position[i].first;
    }
    return maxblocks;
    
}

int main(){
	vector<pair<int,int>> position = {{3,8},{11,2},{8,6}};
	cout<<defkin(15,8,position);
}

int defkinLong(int W, int H, vector<pair<int, int>> position)
{
    // your code goes here
    if(H>W){
        swap(H,W);
    }
    
    // for(int j=0; j<position.size(); j++){
    //     cout<<position[j].first<<" ";
    //     cout<<position[j].second<<"   ";
    // }
    // cout<<endl;
    
    int n= position.size();
    int temp1, temp2;
    vector< pair<int, int> > c_position;
    for(int i=0; i<n; i++){
         c_position.push_back(position[i]);
    }
    
    
    // sorting the positions of crossbow towers 
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(position[j].first>position[j+1].first){
                //  swap position
                temp1 = position[j].first;
                temp2 = position[j].second;
                position[j].first = position[j+1].first;
                position[j].second = position[j+1].second;
                position[j+1].first = temp1; 
                position[j+1].second = temp2;
            }
        }
    }
    
    // sorting acc to col
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(c_position[j].second > c_position[j+1].second){
                temp1 = c_position[j].first;
                temp2 = c_position[j].second;
                c_position[j].first = c_position[j+1].first;
                c_position[j].second = c_position[j+1].second;
                c_position[j+1].first = temp1; 
                c_position[j+1].second = temp2;
            }
        }
    }
    
    for(int j=0; j<n; j++){
        cout<<position[j].first<<" ";
        cout<<position[j].second<<"   ";
    }
    cout<<endl;
    
    for(int j=0; j<n; j++){
        cout<<c_position[j].first<<" ";
        cout<<c_position[j].second<<"   ";
    }
    cout<<endl;
    
    // create grid matrix
    int r=n+2, c=2*(n+2);
    int **arr= new int*[r];
    int i,j;
    for(j=0; j<n+2; j++){
        arr[j] = new int[c];
    }
    
    
    arr[0][0]=0;
    arr[0][1]=0;
    for(j=0; j<n; j++){
        arr[0][2*(j+1)] = 0;
        arr[0][2*(j+1)+1] = c_position[j].second;
    }
    arr[0][2*(j+1)]=0;
    arr[0][2*(j+1)+1]=H+1;
    
    for(i=0; i<n; i++){
        arr[i+1][0] = position[i].first;
        arr[i+1][1] = 0;
        for(j=0; j<n; j++){
            arr[i+1][2*(j+1)] = position[i].first;
            arr[i+1][2*(j+1)+1] = c_position[j].second;
        }
        arr[i+1][2*(j+1)]=position[i].first;
        arr[i+1][2*(j+1)+1]=H+1;
    }
    
    arr[i+1][0]=W+1;
    arr[i+1][1]=0;
    for(j=0; j<n; j++){
        arr[i+1][2*(j+1)] = W+1;
        arr[i+1][2*(j+1)+1] = c_position[j].second;
    }
    arr[i+1][2*(j+1)]=W+1;
    arr[i+1][2*(j+1)+1]=H+1;
    
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    
   
  // calculating area
  int curr_area, max_area = INT_MIN;
  for(i=0; i<n+1; i++){
      for(j=0; j<2*(n+1); j+=2){
          cout<<"area for pts "<<arr[i][j+3]<<" "<<arr[i][j+1]<<" "<<arr[i+1][j]<<" "<<arr[i][j];
          curr_area = abs(arr[i][j+3]-arr[i][j+1]-1) *  abs(arr[i+1][j]-arr[i][j]-1) ;
          cout<<" area: "<<curr_area<<endl;
          if(max_area<curr_area){
              max_area = curr_area;
          }
      }
  }
   
//   free each subarray
    for(i=0; i<r; i++){
        delete [] arr[i];
    }
    delete [] arr;

  return max_area;
}
