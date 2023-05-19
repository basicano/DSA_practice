#include<iostream>
#include<vector>
using namespace std;

void setZeroes(vector< vector<int> > &matrix){
	vector<int> row;
	vector<int> col;
	for(int i=0; i<matrix.size(); i++){
		for(int j=0; j<matrix[i].size(); j++){
			if(matrix[i][j] ==0){
				row.push_back(i);
				col.push_back(j);					
			}
		}
	}
	
	for(int i=0; i<row.size(); i++){
		for(int k=0; k<matrix.size(); k++){
			matrix[row[i]][k] = 0;
		}
	}
	
	for(int i=0; i<col.size(); i++){
		for(int k=0; k<matrix.size(); k++){
			matrix[k][col[i]] = 0;
		}
	}
		
}

int main(){
	vector< vector<int> > vec2d ;
	vector<int> in_vec[3];
	
	for(int i = 0; i<3; i++){
		for(int j=0; j<5; j++){
			in_vec[i].push_back((i+1)*(j+1));
		}
		vec2d.push_back(in_vec[i]);
	}
	
	vec2d[0][1]=0;
	vec2d[2][3]=0;
	vec2d[2][4]=0;
	
	cout<<" Original vector is : \n";
	
	for(int i = 0; i<3; i++){
		for(int j=0; j<5; j++){
			cout<<vec2d[i][j]<<" ";
		}
		cout<<endl;
		
	}
	
	setZeroes(vec2d);
	
	cout<<" Resultant vector is : \n";
	
	for(int i = 0; i<3; i++){
		for(int j=0; j<5; j++){
			cout<<vec2d[i][j]<<" ";
		}
		cout<<endl;		
	}
}
