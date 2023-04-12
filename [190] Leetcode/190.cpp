class Solution 
{
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t mask = 1;
        uint32_t res = 0;

        for(int i = 0; i < 32; ++i)
        {
            res += ((n&mask) ? 1:0) << 31 - i;
            mask <<= 1;
        }
        return res;
    }
};
