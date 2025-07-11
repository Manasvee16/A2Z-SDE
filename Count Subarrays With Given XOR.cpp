class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        long count = 0;
    for (int i = 0; i < arr.size(); ++i) {
        int xorr = 0;
        for (int j = i; j < arr.size(); ++j) {
            xorr ^= arr[j];
            if (xorr == k)
                count++;
        }
    }
    return count;
    }
};
//TC O(N^2)

/*
prefixXor[r] = arr[0] ^ arr[1] ^ ... ^ arr[l-1] ^ arr[l] ^ ... ^ arr[r]
prefixXor[l-1] = arr[0] ^ arr[1] ^ ... ^ arr[l-1]
So, prefixXor[r] ^ prefixXor[l-1]
= (arr[0] ^ ... ^ arr[l-1] ^ arr[l] ^ ... ^ arr[r]) ^ (arr[0] ^ ... ^ arr[l-1])
= (arr[l] ^ ... ^ arr[r])
If we want a subarray ending at r whose XOR is k, we are looking for some l-1 such that:
prefixXor[l-1] = prefixXor[r] ^ k
So if prefixXor[r] ^ k exists in our map, that means there's a subarray ending at r whose XOR is k
*/
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
    unordered_map<int, int> freq; //A prefix XOR value → number of times it has occurred so far. use this to check for previous subarrays
    long count = 0;
    int xorr = 0; //Keeps track of the current prefix XOR up to the current index.
    for (int i = 0; i < arr.size(); ++i) {
        xorr ^= arr[i];
        if (xorr == k)
            count++;
        int target = xorr ^ k; //target is the XOR we want to find in the map. If such a target exists, then there's a subarray ending at index i with XOR k
        if (freq.find(target) != freq.end()) {
            count += freq[target]; //Add the number of times it occurred to the count necause each of those occurrences indicates a valid subarray ending at i with XOR k
        }
        freq[xorr]++; //This helps future elements know how many times this prefix XOR has occurred
    }
    return count;
    }
};
//TC O(N)
//SC O(N)
