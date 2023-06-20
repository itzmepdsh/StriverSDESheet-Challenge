class MedianFinder {
    priority_queue<int> LmaxHeap;
    priority_queue<int,vector<int>,greater<int>> RminHeap;
    double median;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(LmaxHeap.size() == 0 && RminHeap.size() == 0){
            LmaxHeap.push(num);
            median = num;
            return;
        }
        
        if(num > median){
            if(LmaxHeap.size() > RminHeap.size()){
                RminHeap.push(num);
                median = (LmaxHeap.top()+RminHeap.top())/2.0;
            }
            else if(LmaxHeap.size() == RminHeap.size()){
                RminHeap.push(num);
                median = RminHeap.top();
            }
            else{
                LmaxHeap.push(RminHeap.top());
                RminHeap.pop();
                RminHeap.push(num);
                median = (LmaxHeap.top()+RminHeap.top())/2.0;
            }
        }
        else{
            if(RminHeap.size() > LmaxHeap.size()){
                LmaxHeap.push(num);
                median = (LmaxHeap.top()+RminHeap.top())/2.0;
            }
            else if(LmaxHeap.size() == RminHeap.size()){
                LmaxHeap.push(num);
                median = LmaxHeap.top();
            }
            else{
                RminHeap.push(LmaxHeap.top());
                LmaxHeap.pop();
                LmaxHeap.push(num);
                median = (LmaxHeap.top()+RminHeap.top())/2.0;
            }
        }
    }
    
    double findMedian() {
        return median;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */