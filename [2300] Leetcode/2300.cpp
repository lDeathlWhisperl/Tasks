class Solution 
{
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        vector<int> res;

        sort(potions.begin(), potions.end());

        for(int sp : spells)
            res.push_back(potions.size() - search(potions, sp, success));
            
        return res;
    }
private:
    int search(vector<int> &pot, const unsigned long long sp, const unsigned long long suc)
    {
        int left = 0;
        int right = pot.size()-1;
        int pos = right+1;

        while(left <= right)
        {
            int mid = (left + right) / 2;

            if((unsigned long long)pot[mid] * sp < suc)
                left = mid + 1;
            else
            {
                right = mid - 1;
                pos = mid;
            }
        }
        return pos;
    }
};
