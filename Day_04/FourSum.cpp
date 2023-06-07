#define ll long long 
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int a=0;a<n-3;a++){
            if(a>0 && nums[a] == nums[a-1])continue;
            for(int b=a+1;b<n-2;b++){
                if(b>a+1 && nums[b] == nums[b-1])continue;
                int c = b+1,d=n-1;
                int last_c = INT_MIN, last_d = INT_MIN;
                while(c<d){
                    ll sum = (ll)nums[a]+(ll)nums[b]+(ll)nums[c]+(ll)nums[d];
                    if(sum == (ll)target){
                        if(c>b+1 && nums[c] == last_c){
                            c++;
                            continue;
                        }
                        if(d<n-1 && nums[d] == last_d){
                            d--;
                            continue;
                        }
                        res.push_back({nums[a],nums[b],nums[c],nums[d]});
                        last_c = nums[c];
                        last_d = nums[d];
                        c++;d--;
                    }
                    else if(sum < (ll)target)c++;
                    else d--;
                }
            }
        }
        return res;
    }
};