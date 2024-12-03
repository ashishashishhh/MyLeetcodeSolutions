class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        int j=0;
        string ans = "";
        for(int i=0;i<s.length();){
            if(j<spaces.size()){
                if(i==spaces[j]){
                    ans+=" ";
                    j++;
                }else{
                    ans+=s[i];
                    i++;
                }
            }else{
                ans+=s[i];
                i++;
            }
        }
    return ans;
    }
};