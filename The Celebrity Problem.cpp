class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        // Assumes `mat` is non-empty and represents an adjacency matrix of a directed "knows" graph.
        // mat[i][j] == 1 means person i knows person j; mat[i][j] == 0 means i does not know j.
        // For the classical celebrity problem the matrix is square (n x n) and diagonal entries  are typically 0 (a person does not "know" themselves).
        int n = mat.size(), m = mat[0].size();   // n = number of rows, m = number of columns.
        vector<int> indegree(n, 0); // indegree[j] will count how many people know person j.
        vector<int> outdegree(m, 0); // outdegree[i] will count how many people i knows.
        // Traverse the whole matrix and compute indegree & outdegree (excluding self-edges).
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (i == j)
                    continue; // skip self relation; we don't count mat[i][i]
                else
                {
                    indegree[j] += mat[i][j];   // if mat[i][j] == 1, person i knows j -> j's indegree increases
                    outdegree[i] += mat[i][j];  // if mat[i][j] == 1, person i knows someone -> i's outdegree increases
                }
            }
        }
        // After collecting degrees, a celebrity is someone who: - knows 0 people -> outdegree == 0 - is known by everyone else -> indegree == n-1 (everyone except themselves)
        for (int i = 0; i < n; i++)
        {
            // if both conditions hold, return the celebrity index.
            if (outdegree[i] == 0 && indegree[i] == n - 1)
                return i;
        }
        // If no such person found, return -1.
        return -1;
    }
};
//TC O(m*n)
//SC O(m+n)

class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        stack<int> cand;             // stack to hold candidate indices
        int n = mat.size();          // number of people
        // Step 1: Push everyone onto the stack as a potential celebrity
        for (int i = 0; i < n; i++)
        {
            cand.push(i);
            // As soon as we have at least 2 candidates, start eliminating. in one comparison between two people, you can always eliminate at least one of them from being a celebrity. So the algorithm tries to shrink the set of candidates as fast as possible.
            while (cand.size() > 1)
            {
                int p = cand.top();  // take one candidate
                cand.pop();
                int q = cand.top();  // take another candidate
                cand.pop();
                // Check the relationship between p and q
                if (mat[p][q] == 1)
                    // p knows q → p cannot be celebrity, q might still be
                    cand.push(q);
                else
                    // p does not know q → q cannot be celebrity, p might still be
                    cand.push(p);
            }
        }
        // At the end of elimination, only one candidate remains in the stack
        int ans = cand.top();  // potential celebrity
        cand.pop();
        // Step 2: Verify the candidate
        for (int i = 0; i < n; i++)
        {
            if (i == ans)
                continue;  // skip self-check
            //Everyone should know 'ans' → mat[i][ans] must be 1 || 'ans' should know no one → mat[ans][i] must be 0
            if (mat[i][ans] == 0 || mat[ans][i] == 1)
            {
                return -1; // If either condition fails → no celebrity
            }
        }
        return ans; // If checks pass, return the celebrity index
    }
};
//TC O(N)
//SC O(N)
