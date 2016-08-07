/*
    Link: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
    Solution: https://discuss.leetcode.com/topic/52865/my-solution-using-binary-search-in-c/2
    Tips: The solution is cleanning . With binary searching, We devide the matrix into the two part.
          I thoung the upper_bound is the O(log n);
          Time complexity is O(nlog^2n)
*/

class Solution
{
public:
	int kthSmallest(vector<vector<int>>& matrix, int k)
	{
		int n = matrix.size();
		int le = matrix[0][0], ri = matrix[n - 1][n - 1];
		int mid = 0;
		while (le < ri)
		{
			mid = (le + ri) >> 1;
			int num = 0;
			for (int i = 0; i < n; i++)
			{
				int pos = upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
				num += pos;
			}
			if (num < k)
			{
				le = mid + 1;
			}
			else
			{
				ri = mid;
			}
		}
		return le;
	}
};
