class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size() ;
          if(rows == 0) return 0 ;
      int cols = matrix[0].size() ;
       int maxi = INT_MIN ;
      int sum[rows][cols] ;
      for(int i=0;i<rows;i++){
          for(int j=0;j<cols;j++){
              if(matrix[i][j]=='1'){
                  if(i-1>=0)sum[i][j]=1+sum[i-1][j];
                  else sum[i][j]=1;
              }
              else sum[i][j]=0;
          }
      }
        
        for(int i=0;i<rows;i++){
            vector<int>temp;
            for(int j=0;j<cols;j++){
                temp.push_back(sum[i][j]);
            }
            int n=temp.size();
            stack<int>st;
             int right[n],left[n];
            for(int i=0;i<n;i++){
                while(!st.empty() and temp[st.top()]>=temp[i])
                    st.pop();
                if(st.empty()==1)left[i]=-1;
                else left[i]=st.top();
                st.push(i);
            }
            while(!st.empty())
            st.pop();
            
            for(int i=n-1;i>=0;i--){
                while(!st.empty() && temp[st.top()]>=temp[i]) st.pop();
                if(st.empty()) right[i]=n;
                 else right[i]=st.top();
                st.push(i);
            }
           
        for(int i = 0 ; i< n ; i++){
            maxi=max(maxi,temp[i]*(right[i]-left[i]-1));
        }
            
            
        }
        return maxi;
        
        
    }
};