#include<iostream>
#include<vector>
using namespace std;

int findDuplicate(vector<int>& nums) 
{
    int tortoise = nums[0];
    int hare = nums[0];

    // Move tortoise one step and hare two steps until they meet
    do 
    {
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
    }
    while (tortoise != hare);

    // Find the entrance to the cycle
    int ptr1 = nums[0];
    int ptr2 = tortoise;
    while (ptr1 != ptr2) 
    {
        ptr1 = nums[ptr1];
        ptr2 = nums[ptr2];
    }

    return ptr1; // or ptr2, they both point to the repeated number
    
}
