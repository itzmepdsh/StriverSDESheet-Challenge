class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        vector<pair<int,int>> freq;
        for(int i=0;i<nums.size();i++){
            int j=0;
            for( ;j<freq.size();j++){
                if(freq[j].first==nums[i]){
                    freq[j].second++;
                    break;
                }
            }
            if(j==freq.size()){
                freq.push_back(make_pair(nums[i],1));
            }
        }
        for(int i=0;i<freq.size();i++){
            if(freq[i].second > nums.size()/3){
                res.push_back(freq[i].first);
            }
        }
        return res;
    }
};