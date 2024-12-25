class Solution {
public:
    int reachNumber(int target) {

    target=abs(target);

    int step=0;
    int sum=0;
    while(true)
    {
        step++;
        sum=sum+step;
        if(sum==target)
        {
            return step;
        }
        else if(sum>target && (sum-target)%2==0)
        {
            return step;
        }
    }
}
};