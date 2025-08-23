class MedianFinder {
    vector<int> nums;
public:
    MedianFinder() {
        
    }
    void addNum(int num) {
        nums.push_back(num);
    }
    double findMedian() {
        sort(nums.begin(), nums.end());
        int n=nums.size();
        if (n%2!=0)
            return (double)nums[n/2];
        else
        {
            double median=(double)(nums[n/2]+nums[(n/2)-1]);
            median=median/2.0;
            return median;
        }
    }
};

class MedianFinder {
    priority_queue<int, vector<int>, greater<int>> minheap; // to store the larger half of numbers (ascending order)
    priority_queue<int> maxheap; // Max-heap to store the smaller half of numbers (descending order)
public:
    MedianFinder() { }  // Constructor - initializes empty heaps
    // Function to add a number into the data structure
    void addNum(int num) {
        maxheap.push(num);  // Step 1: Always push the number into maxheap first
        /*by always Pushing into maxheap and Moving maxheap.top() into minheap.
            The number automatically goes to the correct heap, without us checking.
            If it’s small → it stays in maxheap.
            If it’s big → it ends up in minheap.
            Then we rebalance sizes.
            This trick avoids “if/else” conditions by using the heap properties themselves.*/
        // Step 2: Balance - move the largest element of maxheap into minheap
        minheap.push(maxheap.top());  
        maxheap.pop(); 
        // Step 3: Ensure maxheap always has equal or more elements than minheap
        if (minheap.size() > maxheap.size()) {
            maxheap.push(minheap.top()); 
            minheap.pop();
        }
    }
    // Function to find the current median
    double findMedian() {
        double ans = 0.0;
        // Case 1: If both heaps are equal in size → median = average of tops
        if (minheap.size() == maxheap.size()) {
            ans = (minheap.top() + maxheap.top()) / 2.0;
        }
        // Case 2: If maxheap has more elements → median is top of maxheap. Never minheap having extra, otherwise the median shifts to the wrong side.
        else {
            ans = maxheap.top();
        }
        return ans;
    }
};
//TC O(logn)
//SC O(n)
