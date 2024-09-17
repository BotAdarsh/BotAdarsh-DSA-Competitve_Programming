class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> sentence1,sentence2; // to store frequency of words in sentence

        int i = 0;
        while(i < s1.size()){
            string temp;
            while(i < s1.size() && s1[i] != ' '){
                temp += s1[i];
                i++;
            }
            sentence1[temp]++;
            i++;
        }

        i = 0;
        while(i < s2.size()){
            string temp;
            while(i < s2.size() && s2[i] != ' '){
                temp += s2[i];
                i++;
            }
            sentence2[temp]++;
            i++;
        }

        vector<string> ans;
        i = 0;
        while(i< s1.size()){
            string temp;
            while(i < s1.size() && s1[i] != ' '){
                temp += s1[i];
                i++;
            }
            if(!sentence2[temp] && sentence1[temp] == 1)ans.push_back(temp);
            i++;
        }

        i = 0;
        while(i< s2.size()){
            string temp;
            while(i < s2.size() && s2[i] != ' '){
                temp += s2[i];
                i++;
            }
            if(!sentence1[temp] && sentence2[temp] == 1)ans.push_back(temp);
            i++;
        }

        return ans;
    }
};
