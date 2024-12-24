class Solution {
public:
    
    bool blackBox(vector<int>& houses, vector<int>& heaters, int n, int m, int radius){
        int i=0, j=0; 
        while(i<n){
            if(j == m){ 
                return false;
            }
            
            int l = heaters[j] - radius; 
            int r = heaters[j] + radius; 
            if(houses[i] < l or houses[i] > r){
                j++; 
            }
            else{
                i++; 
            }
        }
        
        return true; 
    }
    
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(),houses.end());
        sort(heaters.begin(),heaters.end());
        
        int n = houses.size();
        int m = heaters.size();
        
        int low = 0;
        int high = max(*max_element(houses.begin(),houses.end()),*max_element(heaters.begin(),heaters.end())); 
        
        int ans = 0;
        while(low <= high){
            int mid = low + (high-low)/2;
            cout<<mid<<endl;
            if(blackBox(houses,heaters,n,m,mid)==true){ 
                ans = mid;
                high = mid - 1; 
            }
            else{
                low = mid + 1; 
            }
        }
        return ans;
    }
};