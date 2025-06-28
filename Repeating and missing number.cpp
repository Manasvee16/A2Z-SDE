#include <iostream>
#include <vector>
using namespace std;
pair<int, int> findRepeatingAndMissing(const vector<int>& nums) {
    long long n = nums.size();
    long long sum_n = n * (n + 1) / 2;
    long long sum_n_sq = n * (n + 1) * (2 * n + 1) / 6;
    long long sum_actual = 0, sum_sq_actual = 0;
    for (int num : nums) 
    {
        sum_actual += num;
        sum_sq_actual += 1LL * num * num;
    }
    long long diff = sum_actual - sum_n; // A - B
    long long sq_diff = sum_sq_actual - sum_n_sq; // A^2 - B^2 = (A - B)(A + B)
    long long sum = sq_diff / diff; // A + B
    int A = (diff + sum) / 2; // (A - B + A + B)/2 = 2A/2 = A
    int B = A - diff;
    return {A, B};
}
int main() 
{
    vector<int> nums = {3, 5, 4, 1, 1};
    pair<int, int> result = findRepeatingAndMissing(nums);
    cout << "[" << result.first << ", " << result.second << "]" << endl;
    return 0;
}

#include <iostream>
#include <vector>
using namespace std;
pair<int, int> findRepeatingAndMissing(const vector<int>& nums) 
{
    int n = nums.size();
    int xor1 = 0;
    // Get the XOR of all elements and numbers from 1 to n
    for (int i = 0; i < n; i++) 
    {
        xor1 ^= nums[i];
        xor1 ^= (i + 1);
    }
    // Get rightmost set bit in xor1 (A^B)
    int set_bit_no = xor1 & ~(xor1 - 1);
    // Initialize variables to hold two distinct groups
    int x = 0, y = 0;
    for (int i = 0; i < n; i++) 
    {
        // Divide elements into two groups
        if (nums[i] & set_bit_no)
            x ^= nums[i];
        else
            y ^= nums[i];
        // Divide numbers from 1 to n
        if ((i + 1) & set_bit_no)
            x ^= (i + 1);
        else
            y ^= (i + 1);
    }
    // Check which is repeating and which is missing
    int repeat = 0, missing = 0;
    for (int num : nums) 
    {
        if (num == x) 
        {
            repeat = x;
            missing = y;
            break;
        }
        if (num == y) 
        {
            repeat = y;
            missing = x;
            break;
        }
    }
    return {repeat, missing};
}
int main() 
{
    vector<int> nums = {3, 5, 4, 1, 1};
    pair<int, int> result = findRepeatingAndMissing(nums);
    cout << "[" << result.first << ", " << result.second << "]" << endl;
    return 0;
}
