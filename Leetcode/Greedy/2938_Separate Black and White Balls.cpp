class Solution {
public:
    long long minimumSteps(string s) {
        int n = s.size();
        long long result = 0;
        int count = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == '1')count++;
            else{
                result += count;
            }
        }

        return result;
    }
};

/* TypeScript solution
function minimumSteps(s: string): number {
    let n = s.length;
    let count = 0,result = 0;
    for(let i = 0;i<n;i++){
        if(s[i] == '1')count++;
        else result += count;
    }

    return result;
};
*/


// leetcode solution -> https://leetcode.com/problems/separate-black-and-white-balls/solutions/5914241/greedy-easy-linear-solution/
