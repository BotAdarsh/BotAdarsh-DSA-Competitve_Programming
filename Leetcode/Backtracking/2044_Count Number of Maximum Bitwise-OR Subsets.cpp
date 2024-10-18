class Solution {
public:
    void solve(int ind,vector<int> &nums,int n,vector<int> &ans,int bit_or){
        if(ind == n){
            ans.push_back(bit_or);
            return;
        }

        solve(ind+1,nums,n,ans,bit_or);//skip
        solve(ind+1,nums,n,ans,bit_or | nums[ind]);//take
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        solve(0,nums,n,ans,0);
        int maxi = -1;
        int count = 0;

        for(int i = 0;i<ans.size();i++){
            if(ans[i] > maxi){
                maxi = ans[i];
                count = 1;
            }
            else if(ans[i] == maxi)count++;
        }

        return count;
    }
};

/*
const solve = (ind: number,nums: number[],ans: number[],n: number,bit_or:number) => {
    if(ind == n){
        ans.push(bit_or);
        return;
    }

    solve(ind+1,nums,ans,n,bit_or);
    solve(ind+1,nums,ans,n,bit_or | nums[ind]);
}
function countMaxOrSubsets(nums: number[]): number {
    const n = nums.length;
    const ans: number[] = new Array();

    solve(0,nums,ans,n,0);
    let count = 0,maxi = -1;

    for(let i = 0;i<ans.length;i++){
        if(ans[i] > maxi){
            maxi = ans[i];
            count = 1;
        }
        else if(ans[i] == maxi){
            count++;
        }
    }

    return count;
};
*/

//Leetcode Solution -> https://leetcode.com/problems/count-number-of-maximum-bitwise-or-subsets/solutions/5929321/backtracking-dynamic-programming/
