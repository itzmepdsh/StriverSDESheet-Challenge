#define pr pair<int,int>
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl(n,-1),nsr(n,n);
        stack<pr> st;
        //finding the next smallest element to the right
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }
            if(!st.empty())nsr[i] = st.top().second;
            st.push({heights[i],i});
        }

        while(!st.empty())st.pop();
        //finding the next smallest element to the left
        for(int i=0;i<n;i++){
            while(!st.empty() && st.top().first >= heights[i]){
                st.pop();
            }
            if(!st.empty())nsl[i] = st.top().second;
            st.push({heights[i],i});
        }
        //finding out the maxarea
        int maxarea = 0;
        for(int i=0;i<n;i++){
            int area = heights[i]*(nsr[i]-nsl[i]-1);
            maxarea = max(maxarea,area);
        }
        return maxarea;
    }
};