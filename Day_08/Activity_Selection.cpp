#include<algorithm>
bool myComp(pair<int,int>& a, pair<int,int>& b){
    return a.second < b.second;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    int n = start.size();
    vector<pair<int,int>> vec;
    for(int i=0;i<n;i++){
        vec.push_back({start[i],finish[i]});
    }
    sort(vec.begin(),vec.end(),myComp);
    int y = vec[0].second;
    int cnt = 0;
    for(int i=1;i<n;i++){
        if(vec[i].first < y){
            cnt++;
        }
        else{
            y = vec[i].second;
        }
    }
    return n-cnt;
}