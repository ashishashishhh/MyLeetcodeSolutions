class Solution {
public:
    int maximumLength(string s) {
        map<string,int> mpp;
        for(int i=0;i<s.size();i++){
            string sub="";
            for(int j=i;j<s.size();j++){
                if(sub.empty() || s[j]==sub.back()){
                    //special string
                    sub.push_back(s[j]);
                    mpp[sub]++;
                }
                else{
                    break;
                }
            }

        }
        int maxi=0;
        for(auto it:mpp){
            // cout<<it.first <<it.second;
            string st=it.first;
            if(it.second>=3 && maxi<st.length()){
                maxi=st.size();

            }
        }
        if(maxi==0) return -1;
        return maxi;
        
    }
};