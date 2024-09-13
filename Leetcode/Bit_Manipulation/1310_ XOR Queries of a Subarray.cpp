class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();

        vector<int> PXor(n); // to calculate prefix xor of arr
        PXor[0] = arr[0];

        for(int i = 1;i<n;i++){
            PXor[i] = PXor[i-1] ^ arr[i];
        }

        vector<int> ans;
        for(auto &it : queries){ // formula -> Pxor[right] ^ Pxor[left-1] all repeated elements would be turned into 0 and left > 0.
            int temp = PXor[it[1]];
            if(it[0] > 0){
                temp ^= PXor[it[0] - 1];
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
