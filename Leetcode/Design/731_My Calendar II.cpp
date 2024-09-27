class MyCalendarTwo {
public:
    vector<pair<int, int>> intervals;
    vector<pair<int, int>> overlapping;

    MyCalendarTwo() {
    }
    
    bool book(int start, int end) {
        for(auto &it : overlapping){
            if(it.first < end && it.second > start) return false;
        }

        for(auto &it : intervals){
            if(it.first < end && it.second > start){
                int maxi = max(it.first,start);
                int mini = min(it.second,end);
                overlapping.push_back({maxi,mini});
            }
        }
        intervals.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
