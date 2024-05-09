class Solution {
public:
    vector<int> pascalsTriangleRow(int rowNumber) {
        vector<int> triangleRow;
        int value = 1;
        if (rowNumber >= 1)
            triangleRow.push_back(value);

        for (int i=1; i<rowNumber; i++) {
            value = value * (rowNumber - i);
            value = value / i;
            triangleRow.push_back(value);
        }

        return triangleRow;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascalsTriangle;
        for (int row = 1; row <= numRows ; row ++) {
            pascalsTriangle.push_back(pascalsTriangleRow(row));
        }
        return pascalsTriangle;
    }
};