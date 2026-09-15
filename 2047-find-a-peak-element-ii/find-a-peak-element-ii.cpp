class Solution {
public:
    int findmaxrowind(vector<vector<int>> &mat, int m, int col) {
        int maxval = INT_MIN;
        int index = -1;

        for (int i = 0; i < m; i++) {
            if (maxval < mat[i][col]) {
                maxval = mat[i][col];
                index = i;
            }
        }
        return index;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();

        int low = 0;
        int high = n - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int maxrowind = findmaxrowind(mat, m, mid);

            int left = mid - 1 >= 0 ? mat[maxrowind][mid - 1] : -1;
            int right = mid + 1 < n ? mat[maxrowind][mid + 1] : -1;

            if (left < mat[maxrowind][mid] && right < mat[maxrowind][mid]) {
                return {maxrowind, mid};
            } else if (left > mat[maxrowind][mid]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return {-1, -1};
    }
};