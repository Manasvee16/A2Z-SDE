class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        long long sum_n = 1LL * n * (n + 1) / 2;
        long long sum_n_sq = 1LL * n * (n + 1) * (2 * n + 1) / 6;
        long long sum_actual = 0, sum_sq_actual = 0;
        for (int num : arr) {
            sum_actual += num;
            sum_sq_actual += 1LL * num * num;
        }
        long long diff = sum_actual - sum_n; // A - B
        long long sq_diff = sum_sq_actual - sum_n_sq; // A^2 - B^2 = (A - B)(A + B)
        long long sum = sq_diff / diff; // A + B
        int repeating = (diff + sum) / 2; // A
        int missing = repeating - diff; // B
        return {repeating, missing};
    }
};

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& nums) {
        int n = nums.size();
        int xor1 = 0;
        // Step 1: XOR all elements of nums and 1 to n
        for (int i = 0; i < n; i++) {
            xor1 ^= nums[i];
            xor1 ^= (i + 1);
        }
        // Step 2: Find the rightmost set bit in xor1 (A ^ B)
        int set_bit_no = xor1 & ~(xor1 - 1);
        // Step 3: Divide numbers into two sets
        int x = 0, y = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] & set_bit_no)
                x ^= nums[i];
            else
                y ^= nums[i];
            if ((i + 1) & set_bit_no)
                x ^= (i + 1);
            else
                y ^= (i + 1);
        }
        // Step 4: Determine which is repeating and which is missing
        int repeating = 0, missing = 0;
        for (int num : nums) {
            if (num == x) {
                repeating = x;
                missing = y;
                break;
            } 
            else if (num == y) {
                repeating = y;
                missing = x;
                break;
            }
        }
        return {repeating, missing};
    }
};
