1class NumMatrix {
2    private: vector<vector<long long int>> prefix;
3public:
4    NumMatrix(vector<vector<int>>& matrix) {
5        int n = matrix.size(), m = matrix[0].size();
6        prefix.resize(n+1, vector<long long>(m+1,0));
7        //saving prefix till that row col(matix)
8        for(int i=0;i<n;i++){
9            for(int j=0;j<m;j++){
10                prefix[i+1][j+1] = prefix[i][j+1]+prefix[i+1][j]-prefix[i][j] + matrix[i][j];
11            }
12        }
13    }
14    
15    
16    int sumRegion(int row1, int col1, int row2, int col2) { //getting results in O(1)
17        return prefix[row2+1][col2+1] + prefix[row1][col1] - prefix[row1][col2+1] - prefix[row2+1][col1];
18    }
19};
20
21/**
22 * Your NumMatrix object will be instantiated and called as such:
23 * NumMatrix* obj = new NumMatrix(matrix);
24 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
25 */