#include <bits/stdc++.h>

void solve(string s, int n, unordered_set<string>& st, vector<string>& res, string& out, int i){
    //base case
    if(i==n){
        res.push_back(out);
        return;
    }
    //recursive case
    for(int k=i;k<n;k++){
        string str = s.substr(i,k-i+1);
        if(st.find(str) != st.end()){
            out += str;
            out += " ";
            solve(s,n,st,res,out,k+1);
            int len = str.length()+1;
            while(len--){
                out.pop_back();
            }
        }
    }
}

vector<string> wordBreak(string &s, vector<string> &dictionary)
{
    // Write your code here
    int n = s.length();
    unordered_set<string> st;
    for(string str : dictionary){
        st.insert(str);
    }
    vector<string> res;
    string out = "";
    solve(s,n,st,res,out,0);
    return res;
}