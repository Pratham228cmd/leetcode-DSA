// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}// } Driver Code Ends


//User function Template for C++


//Function to construct the BST from its given level order traversal.
Node* constructBst(int arr[], int n)
{
    // Code here
     Node *root = NULL;
    if(n==0) return root;
   
    queue<pair<Node *,pair<int,int>>> q;
    root = new Node(arr[0]);
    q.push({root, {INT_MIN,INT_MAX}});
    int i=1;
    while(i<n and !q.empty()){
        Node*temp=q.front().first;
        int s=q.front().second.first;
        int e=q.front().second.second;
        q.pop();
        if(arr[i]>s and arr[i]<temp->data){
            temp->left=new Node(arr[i]);
            q.push({temp->left,{s,temp->data}});
            i++;
        }
        else temp->left = NULL;
         if(arr[i]>temp->data && arr[i]<e){
            temp->right = new Node(arr[i]);
            q.push({temp->right,{temp->data,e}});
            i++;
        }
        else temp->right = NULL;
        
        
    }
    return root;
    
}
