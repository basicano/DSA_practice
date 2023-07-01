#include<iostream>
#include<vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    
    int max_profit = 0;
    int bought_stock = prices[0];
    
    for(int i=1; i<n; i++){
        if(prices[i]<=bought_stock){
            bought_stock = prices[i];
        }
        else{
            int profit = prices[i] - bought_stock;
            if(profit > max_profit){
                max_profit = profit;
            }
        }
    }

    return max_profit;
}

int main(){
	vector<int> prices{7,1,5,3,6,4};
	cout<<maxProfit(prices);
}
