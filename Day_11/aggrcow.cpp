#include<iostream>
#include<climits>
#include<algorithm>
using namespace std;

bool canplace(int* stalls, int n, int c,int mid){
    int last_cow_pos = 0;
    int noOfCows = 1;
    for(int i=1;i<n;i++){
        if(stalls[i]-stalls[last_cow_pos] >= mid){
            last_cow_pos = i;
            noOfCows++;
            if(noOfCows == c)return true;
        }
    }
    return false;
}

int aggrcow(int* stalls, int n,int c){
    int lb = INT_MAX;
    for(int i=1;i<n;i++){
        lb = min(lb,stalls[i]-stalls[i-1]);
    }
    int ub = stalls[n-1]-stalls[0];
    int mindist = INT_MAX;
    while(lb<=ub){
        int mid = lb+(ub-lb)/2;
        if(canplace(stalls,n,c,mid)){
            mindist = mid;
            lb = mid+1;
        }
        else{
            ub = mid-1;
        }
    }
    return mindist;
}

int main(){
    int tc;
    cin>>tc;
    while(tc--){
        int n,c;
        cin>>n>>c;
        int stalls[n];
        for(int i=0;i<n;i++){
            cin>>stalls[i];
        }
        sort(stalls,stalls+n);
        cout<<aggrcow(stalls,n,c)<<endl;
    }
    return 0;
}