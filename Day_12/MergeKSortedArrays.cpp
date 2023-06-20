#include <bits/stdc++.h>
typedef pair<int,pair<int,int>> pr; 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> res;
    priority_queue<pr,vector<pr>,greater<pr>> minpq;
    for(int i=0;i<k;i++){
      minpq.push({kArrays[i][0],{i, 0}});
    }
    while(!minpq.empty()){
        pr tp = minpq.top();
        minpq.pop();
        res.push_back(tp.first);
        int row = tp.second.first;
        int col = tp.second.second;
        if(++col < kArrays[row].size())
          minpq.push({kArrays[row][col], {row, col}});
    }
    return res;
}
