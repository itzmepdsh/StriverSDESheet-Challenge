class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //using Moore's Voting Algorithm
        //Time Complexity = O(n) Spacce Complexity = O(1)
        int n = nums.size();
        int cnt1 = 0,ele1,cnt2 = 0,ele2;
        for(int i=0;i<n;i++){
            if(cnt1 == 0 && nums[i] != ele2){
                cnt1 = 1;
                ele1 = nums[i];
            }
            else if(cnt2 == 0 && nums[i] != ele1){
                cnt2 = 1;
                ele2 = nums[i];
            }
            else if(ele1 == nums[i])cnt1++;
            else if(ele2 == nums[i])cnt2++;
            else{
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0;
        cnt2 = 0;
        for(int i=0;i<n;i++){
            if(nums[i] == ele1)cnt1++;
            else if(nums[i] == ele2)cnt2++;
        }
        vector<int> res;
        if(cnt1 > (n/3))res.push_back(ele1);
        if(cnt2 > (n/3))res.push_back(ele2);
        return res;
        
        //using hashmap Time Complexity = O(nlogn) Space Complexity = O(1)
        // vector<int> res;
        // vector<pair<int,int>> freq;
        // for(int i=0;i<nums.size();i++){
        //     int j=0;
        //     for( ;j<freq.size();j++){
        //         if(freq[j].first==nums[i]){
        //             freq[j].second++;
        //             break;
        //         }
        //     }
        //     if(j==freq.size()){
        //         freq.push_back(make_pair(nums[i],1));
        //     }
        // }
        // for(int i=0;i<freq.size();i++){
        //     if(freq[i].second > nums.size()/3){
        //         res.push_back(freq[i].first);
        //     }
        // }
        // return res;
    }
};
