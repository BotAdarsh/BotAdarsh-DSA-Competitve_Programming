class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;

        if(a > 0) pq.push({a,'a'});
        if(b > 0) pq.push({b,'b'});
        if(c > 0) pq.push({c,'c'});

        string ans;

        while(!pq.empty()){
            auto top = pq.top();
            pq.pop();
            int count = top.first;
            char ch = top.second;

            int n = ans.size();
            if(n >= 2 && ans[n-1] == ch && ans[n-2] == ch){
                if(pq.empty()){
                    break;
                }

                auto next_top = pq.top();
                pq.pop();
                int next_count = next_top.first;
                char next_ch = next_top.second;

                ans.push_back(next_ch);
                next_count--;
                if(next_count > 0) pq.push({next_count,next_ch});
            }
            else{
                ans.push_back(ch);
                count--;
            }

            if(count > 0) pq.push({count,ch});            
        }

        return ans;
    }
};
