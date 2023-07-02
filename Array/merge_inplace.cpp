#include <bits/stdc++.h>

// will work for no extra space also

vector<int> merge_inplace(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	int m_idx = 0, n_idx = 0, c=m+n;
	while(m_idx<m && n_idx<n){
		if( arr1[m_idx] <= arr2[n_idx] ){
			m_idx++;
		}
		else{
			int temp = arr1[m_idx];
			arr1[m_idx] = arr2[n_idx];
			m_idx++;

			int insert_at = n_idx;
			while(insert_at<n-1 && arr2[insert_at+1]<temp){
				arr2[insert_at] = arr2[insert_at+1];
				insert_at++;
			}
			arr2[insert_at] = temp;
		}
	}

	while(n_idx<n){
		arr1[m_idx++] = arr2[n_idx++];
	}

	return arr1;
}

// works only if extra space is present
vector<int> ninjaAndSortedArrays(vector<int>& arr1, vector<int>& arr2, int m, int n) {
	// Write your code here.
	int m_idx = m-1, n_idx = n-1, c=m+n-1;
	while(m_idx>=0 && n_idx>=0){
		if( arr1[m_idx] >= arr2[n_idx] ){
			arr1[c--] = arr1[m_idx--];
		}
		else{
			arr1[c--] = arr2[n_idx--];
		}
	}

	while(n_idx>=0){
		arr1[c--] = arr2[n_idx--];
	}

	return arr1;
}
