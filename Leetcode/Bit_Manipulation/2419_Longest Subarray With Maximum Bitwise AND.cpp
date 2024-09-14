class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = -1,maxi_idx = -1;
        for(int i = 0;i<n;i++){//finding maxi and index of maxi
            if(nums[i] > maxi){
                maxi = nums[i];
                maxi_idx = i;
            }
        }
        //maximum and would be the maximum element of the array
        int maxi_len = 0;
        for(int i = maxi_idx;i<n;i++){//starting thr loop from first occurance of maxi
            int len = 0;
            while(i < n && nums[i] == maxi){//while maxi is maintained increment length and index
                len++;
                i++;
            }

            maxi_len = max(maxi_len,len);//update maximum length
        }
        return maxi_len;
    }
};
