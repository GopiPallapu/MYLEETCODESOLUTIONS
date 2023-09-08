class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n =matrix[0].size();
        int left =0;
        int right = n-1;
        int top = 0;
        int bottom = m-1;
        vector<int> ans;
        while(left <= right  && top <=bottom){
          // first row
          for(int i = left;i<=right;i++){
            ans.push_back(matrix[top][i]);
          }
          top++;
          // last column
          for(int i = top ;i<=bottom;i++){
            ans.push_back(matrix[i][right]);
          }
          right--;
          // last row
          if(top<=bottom){
          for(int i = right;i>=left;i--){
            ans.push_back(matrix[bottom][i]);
          }
          bottom--;
          }
          // first column
          if(left<=right){
          for(int i=bottom;i>=top;i--){
            ans.push_back(matrix[i][left]);
          }
          left++;
          }
        } 
        return ans;
    }
};