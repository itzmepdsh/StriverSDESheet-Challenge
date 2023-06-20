#include<iostream>
#include<vector>
using namespace std;

class minHeap{
    private:
        vector<int> vec;

        void heapify(int i){
            int min_idx = i;
            int leftchild = 2*min_idx + 1;
            if(leftchild < vec.size() && vec[leftchild] < vec[min_idx]){
                min_idx = leftchild;
            }
            int rightchild = 2*i+2;
            if(rightchild < vec.size() && vec[rightchild] < vec[min_idx]){
                min_idx = rightchild;
            }
            if(min_idx != i){
                swap(vec[min_idx],vec[i]);
                heapify(min_idx);
            }
        }

    public:
        void push(int x){// Time Complexity: O(logn) i.e., height of tree in worst case
            vec.push_back(x);
            int childidx = vec.size()-1;
            int parentidx = childidx%2 == 1 ? childidx/2 : childidx/2-1;
            while(childidx != 0 && vec[parentidx] > vec[childidx]){
                swap(vec[parentidx],vec[childidx]);
                childidx = parentidx;
                parentidx = childidx%2 == 1 ? childidx/2 : childidx/2-1;
            }
        }

        void pop(){//O(logn)
            swap(vec[0],vec[vec.size()-1]);
            vec.pop_back();
            heapify(0);
        }

        int top(){
            return vec[0];
        }

        int size(){
            return vec.size();
        }
        bool empty(){
            return vec.empty();
        }
};
int main(){
    minHeap m;

	m.push(9);
	m.push(7);
	m.push(8);
	m.push(5);
	m.push(4);
	m.push(6);
	m.push(3);
	m.push(2);
	m.push(1);

	cout << m.size() << endl;

	while(!m.empty()) {
		cout << m.top() << " ";
		m.pop();
	}

	cout << endl;

	cout << m.size() << endl;
    return 0;
}