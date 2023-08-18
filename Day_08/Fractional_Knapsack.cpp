//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        vector<pair<double,int>> perunit(n);
        for(int i=0;i<n;i++){
            perunit[i].first = 1.0*arr[i].value/arr[i].weight;
            perunit[i].second = arr[i].weight;
        }
        sort(perunit.begin(),perunit.end(),greater<pair<double,int>>());
        double res = 0;
        for(int i=0;i<n;i++){
            if(W <= 0)break;
            res += perunit[i].first*(min(W,perunit[i].second));
            W -= perunit[i].second;
        }
        return res;
    }
        
};