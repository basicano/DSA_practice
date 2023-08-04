int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
    int n = nums.size();
    vector<int> second_prefix(n-secondLen+1,0);
    int pre_cal = 0;
    for(int i=0; i<secondLen; i++){
        second_prefix[0] += nums[i];
        pre_cal +=nums[i];
    }

    for(int i=secondLen; i<n; i++){
        second_prefix[i-secondLen+1] = second_prefix[i-secondLen] + nums[i] - nums[i-secondLen];
    }

    for(int i=n-secondLen; i>0; i--){
        if(second_prefix[i-1]<second_prefix[i]){
            second_prefix[i-1] = second_prefix[i];
        }
    }

    int max_sum;
    int second_pre_max=0, second_post_max, second_max;
    int subarr_sum = 0;
    int f_start = 0, f_end = firstLen-1;
    
    for(int i=0; i<firstLen; i++){
        subarr_sum += nums[i];
    }
    second_post_max = second_prefix[f_end+1];
    second_max = (second_pre_max>second_post_max)? second_pre_max: second_post_max;
    cout<<second_max;
    max_sum = subarr_sum + second_max;

    
    for(int i = firstLen; i<n; i++ ){

        subarr_sum += nums[i] - nums[i-firstLen];
        // CALCULATE BEFORE AND AFTER THIS ARRAY

        f_start = i-firstLen +1;
        f_end = i;
        if(n-(f_end+1) >= secondLen){
            second_post_max = second_prefix[f_end+1]; 
            second_max = second_post_max;
        }
        else{
            second_post_max = 0;
            second_max = second_post_max;
        }

        if(f_start == secondLen){ 
            second_pre_max = pre_cal;       
            second_max = (second_pre_max>second_post_max)? second_pre_max: second_post_max;
        }
        else if(f_start > secondLen){ 
            pre_cal += nums[i-firstLen] - nums[i-firstLen-secondLen];
            if(pre_cal>second_pre_max){
                second_pre_max = pre_cal;
            }
            second_max = (second_pre_max>second_post_max)? second_pre_max: second_post_max; 
        }

        if(max_sum < second_max + subarr_sum){
            max_sum = second_max + subarr_sum;
        }
    }
    return max_sum;
}
