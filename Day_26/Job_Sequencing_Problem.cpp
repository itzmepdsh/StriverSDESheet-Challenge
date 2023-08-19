/*
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};
*/

class Solution 
{
    static bool myComp(Job& a, Job& b){
        return a.profit > b.profit;
    }
    
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        sort(arr,arr+n,myComp);
        int mx = 0;
        for(int i=0;i<n;i++){
            mx = max(mx,arr[i].dead);
        }
        vector<int> seq(mx+1,-1);
        int profit = 0,cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=arr[i].dead;j>=1;j--){
                if(seq[j] == -1){
                    cnt++;
                    profit += arr[i].profit;
                    seq[j] = arr[i].id;
                    break;
                }
            }
        }
        return {cnt,profit};
    } 
};