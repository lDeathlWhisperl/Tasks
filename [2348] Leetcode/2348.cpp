class Solution 
{
public:
    long long zeroFilledSubarray(vector<int>& nums) 
    {
        std::ios::sync_with_stdio(false);
        std::cin.tie(nullptr);
        
        long long int res = 0;
        int count = 0;
        
        for(int num : nums)
        {
            ++count;
            if(num != 0) count = 0;
            res += count;
        }
        
        return res;
    }
};
