class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())
            return false;
        unordered_map<int,vector<char>> m1;
        unordered_map<int,vector<char>> m2;
        unordered_map<char,int> mp1;
        unordered_map<char,int> mp2;
        for(int i=0;i<word1.size();i++){
            mp1[word1[i]]++;
        }
        for(int i=0;i<word2.size();i++){
            mp2[word2[i]]++;
        }
        bool flag1=true;
        for(auto it:mp1){
            if(mp2.find(it.first)==mp2.end())
                return false;
            if(it.second!=mp2[it.first]){
                flag1=false;
            }
        }
        if(flag1)
            return true;
        for(auto it:mp1){
            m1[it.second].push_back(it.first);
        }
        for(auto it:mp2){
            m2[it.second].push_back(it.first);
        }
        flag1=true;
        for(auto it:m1){
            if(m2.find(it.first)==m2.end())
                return false;
            else if(m2[it.first].size()!=it.second.size())
                return false;
        }
        return true;
        
        


        
        
    }
};