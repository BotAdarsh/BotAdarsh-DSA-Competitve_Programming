//Approach 1
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();
        sort(timePoints.begin(),timePoints.end()); // to maintain consistency

        int ans = INT_MAX;
        for(int i = 1;i<n;i++){
            int minute = (timePoints[i][3] - '0')*10 + (timePoints[i][4] - '0');//convert into integer
            int minute2 = (timePoints[i-1][3] - '0')*10 + (timePoints[i-1][4] - '0');

            int hour = (timePoints[i][0] - '0')*10 + (timePoints[i][1] - '0');//convert into hour
            int hour2 = (timePoints[i-1][0] - '0')*10 + (timePoints[i-1][1] - '0');

            ans = min(ans,(hour - hour2)*60 + (minute - minute2));
        }

        int minute = (timePoints[n-1][3] - '0')*10 + (timePoints[n-1][4] - '0');//convert into integer
        int minute2 = (timePoints[0][3] - '0')*10 + (timePoints[0][4] - '0');

        int hour = (timePoints[n-1][0] - '0')*10 + (timePoints[n-1][1] - '0');//convert into hour
        int hour2 = (timePoints[0][0] - '0')*10 + (timePoints[0][1] - '0');

        ans = min(ans,(hour2 + 24 - hour)*60 + (minute2 - minute));

        return ans;
    }
};
//Approach 2
class Solution {
public:
    int convert_to_minutes(string time){//funtion to convert a HH:MM to total minutes
        int hour = stoi(time.substr(0,2));
        int minute = stoi(time.substr(3,2));

        return hour * 60 + minute;
    }

    int findMinDifference(vector<string>& timePoints) {
        int n = timePoints.size();

        sort(timePoints.begin(),timePoints.end());//to get adjacent time values 

        int ans = INT_MAX;
        for(int i = 1;i<n;i++){
            int curr = convert_to_minutes(timePoints[i]);//convert current time to minutes
            int prev = convert_to_minutes(timePoints[i-1]);//previous time
            ans = min(ans,curr - prev);
        }

        int last = convert_to_minutes(timePoints[n-1]);//compare last and first as the time is cyclic
        int first = convert_to_minutes(timePoints[0]);
        ans = min(ans,first + 1440 - last);
        return ans;
    }
};
// leetcode solution -> https://leetcode.com/problems/minimum-time-difference/solutions/5792674/minimum-time-difference-sorting-and-cyclic-check/
