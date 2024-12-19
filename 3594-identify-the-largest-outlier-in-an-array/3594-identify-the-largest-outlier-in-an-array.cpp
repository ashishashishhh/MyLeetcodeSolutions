class Solution
{
public:
    int getLargestOutlier(vector<int>& nums)
    {
        // Step 1: Calculate the total sum of the array
        int sum = 0;
        for (int k : nums)
        {
            sum += k;
        }

        // Step 2: Use a multiset to track occurrences of elements
        multiset<int> st(nums.begin(), nums.end());

        // Step 3: Initialize the answer as the smallest possible value
        int ans = INT_MIN;

        // Step 4: Iterate through each number in the array
        for (int k : nums)
        {
            // Check if the sum excluding the current number is even
            if ((sum - k) % 2 == 0)
            {
                // Temporarily remove the current number from the multiset
                st.erase(st.find(k));

                // Calculate the target number
                int p = (sum - k) / 2;

                // Check if the target exists in the multiset
                if (st.find(p) != st.end())
                {
                    // Update the maximum outlier found so far
                    ans = max(ans, k);
                }

                // Step 5 : Restore the current number back into the multiset
                st.insert(k);
            }
        }

        // Step 6: Return the largest outlier, or a default value if none found
        return ans;
    }
};