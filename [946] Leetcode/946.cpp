class Solution 
{
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) 
    {
        int count = 0;
        stack<int> st;

        for(int num:pushed)
        {
            st.push(num);

            while(!st.empty() && st.top() == popped[count])
            {
                ++count;
                st.pop();
            }
        }
        return count == popped.size();
    }
};
