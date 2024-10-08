class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int n = s.size();
        if(n == 0) return 0;

        for(int i = 0;i<n;i++){// to remove already balanced char
            if(s[i] == ']' && !st.empty() && st.top() == '['){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }

        if(st.empty()) return 0;// already balanced

        int unbalanced = st.size()/2;// no. of pairs

        return ceil(unbalanced / 2.0);
    }
};

// 2nd Approach :

class Solution {
public:
    int minSwaps(string s) {
        int n = s.size();
        if(n == 0) return 0;

        int unbalanced = 0;
        for(int i = 0;i<n;i++){
            if(s[i] == '[')unbalanced++;
            else unbalanced--;
            if(unbalanced < 0) unbalanced = 0;
        }

        return ceil(unbalanced/2.0);
    }
};
