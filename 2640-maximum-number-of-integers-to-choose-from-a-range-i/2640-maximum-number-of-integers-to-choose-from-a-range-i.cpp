class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int curr = 1,ans=0;
        int sum = 0;
        int total = banned.size();
        unordered_set<int>st;
        for(auto x:banned)
        st.insert(x);

        while(sum<maxSum && curr<=n){
            if(curr>maxSum)
            return 0;
            if(st.find(curr)==st.end()){
                cout<<curr<<endl;
                sum+=curr;
                curr++;
                if(sum<=maxSum)
                ans++;
            }else{
                curr++;
            }
        }
        return ans;
    }
};