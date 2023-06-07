class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty())return 0;
        set<int> st;
        for(int num : nums){
            st.insert(num);
        }
        int cur = *st.begin();
        auto it = st.begin()++;
        int maxseq = 1,curseq = 1;
        while(it!=st.end()){
            if(*it == cur+1){
                curseq++;
            }
            else{
                curseq = 1;
            }
            cur = *it;
            maxseq = max(maxseq,curseq);
            it++;
        }
        return maxseq;
    }
};