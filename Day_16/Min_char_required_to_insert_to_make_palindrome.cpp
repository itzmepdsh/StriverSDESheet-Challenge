string reverse(string s){
    int i=0,j=s.length()-1;
    while(i<j){
        swap(s[i],s[j]);
        i++;
        j--;
    }
    return s;
}
int Solution::solve(string A) {
    int m = A.length();
    string rev = reverse(A);
    string temp = A;
    temp += "$";
    temp += rev;
    int n = temp.length();
    vector<int> lps(n,0);
    for(int i=1;i<n;i++){
        int j = lps[i-1];
        while(j>0 && temp[i] != temp[j]){
            j = lps[j-1];
        }
        if(temp[i] == temp[j])
            j++;
        lps[i] = j;
    }
    return m-lps[n-1];
}
