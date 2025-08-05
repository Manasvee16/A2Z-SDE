class Solution {
  public:
    int findPages(vector<int> &arr, int k) {
        int n=arr.size();
        if (n<k) //If students are more than books, it’s impossible to assign at least one book per student
            return -1;
        int start=*max_element(arr.begin(), arr.end()); //maximum number of pages in a single book. Because one student must at least take the biggest book, so no allocation can have a maximum less than this.
        int end=accumulate(arr.begin(), arr.end(), 0); //one student takes all books
        while (start<=end)
        {
            int mid=start+(end-start)/2; // value for max pages per student.
            if (minPossible(mid, k, arr))
            { //we try for even fewer pages
                 end=mid-1;
            }
            else
            {
               start=mid+1;
            }
        }
        return start;
    }
    bool minPossible(int pages, int students, vector<int> &arr)
    { //Can we allocate books to k students such that no student gets more than mid pages?
        int sum=0; //current student's page count.
        int count=1; //number of students used. Before assigning any pages, we're already starting with one student ready to receive books.
        for (int i=0;i<arr.size();i++)
        {
            sum+=arr[i]; //Keep adding pages to the current student.
            if (sum>pages)
            {
                count++; //assign to next student
                sum=arr[i];
            }
        }
        if (count<=students) //current pages value is possible.
            return true;
        return false;
    }
};
