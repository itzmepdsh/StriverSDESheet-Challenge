class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int i=0,j=n-1,lmax = height[0], rmax = height[n-1];
        int trapped = 0;
        while(i<=j){
            lmax = max(lmax,height[i]);
            rmax = max(rmax,height[j]);
            if(lmax<rmax){
                trapped += lmax-height[i];
                i++;
            }
            else{
                trapped += rmax-height[j];
                j--;
            }
        }
        return trapped;
        
        // int n = height.size();
        // vector<int> l(n);
        // l[0] = height[0];
        // for(int i=1;i<n;i++){
        //     l[i] = max(l[i-1],height[i]);
        // }
        // vector<int> r(n);
        // r[n-1] = height[n-1];
        // for(int i=n-2;i>=0;i--){
        //     r[i] = max(r[i+1],height[i]);
        // }
        // int trapped = 0;
        // for(int i=0;i<n;i++){
        //     trapped += min(l[i],r[i])-height[i];
        // }
        // return trapped;
    }
};