class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int mSize = matrix.size();

        for (int row = 0; row < mSize; row++) {
            for (int col = 0; col < mSize; col++) {
                if (row > col) {
                    swap(matrix[row][col], matrix[col][row]);
                }
            }
        }

        for (int row = 0; row < mSize; row++) {
            reverse(matrix[row].begin(), matrix[row].end());
        }
    }
};