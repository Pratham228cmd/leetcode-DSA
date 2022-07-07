// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Back-end complete function Template for C++
struct Node{
  int data;
  Node* left;
  Node*right;
  Node(int x){
      data=x;
      left=NULL;
      right=NULL;
  }
};

class Solution{
    public:
    Node* insert(Node*root,int key,Node* &succ){
        if(!root)return new Node(key);
        if(root->data>key){
            succ=root;
            root->left=insert(root->left,key,succ);
        }
        else if(root->data<=key){
            root->right=insert(root->right,key,succ);
        }
        return root;
        
        
    }
    vector<int> findLeastGreater(vector<int>& arr, int n) {
          Node *root=NULL;
      for(int i=n-1;i>=0;i--)
      {
          Node *succ=NULL;
          root=insert(root,arr[i],succ);
          if(succ)
          arr[i]=succ->data;
          else
          arr[i]=-1;
      }
      return arr;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    vector<int> ans = ob.findLeastGreater(arr, n);
	    for(auto it : ans){
	        cout << it << " ";
	    }
	    cout <<endl;
	}
	return 0;
}
  // } Driver Code Ends