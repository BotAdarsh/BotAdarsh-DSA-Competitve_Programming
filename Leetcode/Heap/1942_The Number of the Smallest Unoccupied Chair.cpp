class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        for(int i = 0;i<n;i++){ // times[i] = {start,end,index}
            times[i].push_back(i);
        }

        sort(times.begin(),times.end());

        priority_queue<int,vector<int>,greater<int>> available;// {0,1,2,3,...,n-1}
        for(int i = 0;i<n;i++){
            available.push(i);
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> used;//(times[i][1],chair)

        for(auto it : times){
            while(!used.empty() && used.top().first <= it[0]){
                int chair = used.top().second;
                used.pop();
                available.push(chair);
            }

            int chair = available.top();
            available.pop();
            used.push({it[1],chair});

            if(it[2] == targetFriend) return chair;
        }
        return -1;
    }
};
