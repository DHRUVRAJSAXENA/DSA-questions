#include<iostream>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }

};

node* buildTree(node* root){
    cout<<"Enter the data"<<endl;
    int data;

    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter Left Data of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter right Data of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
           if(temp->left){
            q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            } 
        }

        
    }
}



void preOrderIterative(node* root){
    if(root == NULL) return;

    stack<node*> st;
    st.push(root);

    while(!st.empty()){
        node* temp = st.top();
        st.pop();
        cout<<temp->data<<"  ";

        if(temp->right){
            st.push(temp->right);
        }
        if(temp->left){
            st.push(temp->left);
        }
    }
}

void inOrderIterative(node* root){
    stack<node*> st;
    node* temp = root;

    while(temp != NULL || !st.empty()){
        if(temp != NULL){
            st.push(temp);
            temp = temp->left;
        }
        else{
            
            temp = st.top();
            st.pop();
            cout<<temp->data<<"  ";
            temp = temp->right;
        }
    }
}

void postOrderIterative(node* root){
    if(root == NULL) return;

    stack<node*> st1,st2;
    st1.push(root);

    while(!st1.empty()){
        node* temp = st1.top();
        st1.pop();
        st2.push(temp);

        if(temp->left){
            st1.push(temp->left);
        }
        if(temp->right){
            st1.push(temp->right);
        }
    }
    while(!st2.empty()){
        node* temp = st2.top();
        cout<<temp->data<<"  ";
        st2.pop();
    }
}

vector<int> morrisInorder(node* root){
    vector<int> inorder;
    node* cur = root;
    while(cur != NULL){
        if(cur->left == NULL){
            inorder.push_back(cur->data);
            cur = cur->right;
        }
        else{
            node* prev = cur->left;
            while(prev->right && prev->right != cur){
                prev = prev->right;
            }
            if(prev->right == NULL ){
                prev->right = cur;
                cur = cur->left;
            }
            else{
                prev->right = NULL;
                inorder.push_back(cur->data);
                cur =cur->right;
            }
        }
    }
    return inorder;
}

int height(node* root){
    if(root == NULL){
        return 0;
    }

    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left,right) + 1;

    return ans;
}

int diameter(node* root){

    /*
    three cases: ( O(n2) )
    1-> diamter from left side only
    2-> diamter from right side only
    3-> height of left + 1 + height of right
    */

   if(root == NULL) return 0;

   int left = diameter(root->left);
   int right = diameter(root->right);
   int both = height(root->left) + 1 + height(root->right);

   int maxi = max(both , max(left,right));

   return maxi;
}

pair<int,int> fastDiameter(node* root){
    /*
    pair<int,int> is storing diameter and height
    TC -> O(n) , SC -> O(H)
    */
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p; 
    }

    pair<int,int> left = fastDiameter(root->left);
    pair<int,int> right = fastDiameter(root->right);

    int opt1 = left.first;
    int opt2 = right.first;
    int opt3 = left.second + 1 + right.second;

    pair<int,int> ans;
    ans.first = max(opt1,max(opt2,opt3));
    ans.second = max(left.second , right.second) + 1;

    return ans;
}

bool isBalanced(node* root){
    // O(n2)
    if(root == NULL) return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool diff = abs(height(root->left) - height(root->right)) <= 1;

    if(left && right && diff) return true;
    else return false;
}

pair<bool,int> fastIsBalanced(node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> left = fastIsBalanced(root->left);
    pair<bool,int> right = fastIsBalanced(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool,int>ans;
    ans.second = max(left.second , right.second) + 1;

    if(leftAns && rightAns && diff) {
        ans.first = true;
        
    }
    else{
        ans.first = false;
        
    }
    return ans;
}


pair<bool,int> isSumTreeFast(node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> left = isSumTreeFast(root->left);
    pair<bool,int> right = isSumTreeFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    
    bool cond = root->data == left.second + right.second;

    pair<bool,int> ans;
    if(leftAns && rightAns && cond){
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else{
        ans.first = false;
        
    }
    return ans;
}

vector<int> zigzag(node* root){
    vector<int> result;
    if(root==NULL) return result;

    queue<node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> ans(size);

        for(int i=0;i<size;i++){
            node* frontNode = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->data;

            if(frontNode->left){
                q.push(frontNode->left);
            }
            if(frontNode->right){
                q.push(frontNode->right);
            }
        }
        leftToRight = !leftToRight;
        for(auto i :ans){
            result.push_back(i);
        }

    }
    return result;
}

void leftTraversalBoundery(node* root, vector<int> &ans){
    if((root == NULL ) || (root->left == NULL && root->right == NULL)){
        return;
    }

    ans.push_back(root->data);

    if(root->left) leftTraversalBoundery(root->left,ans);
    else leftTraversalBoundery(root->right,ans);
}

void leafTraversalBoundery(node* root,vector<int> &ans){
    if(root == NULL) return;

    if(root->left == NULL && root->right == NULL){
        ans.push_back(root->data);
        return;
    }

    leafTraversalBoundery(root->left,ans);
    leafTraversalBoundery(root->right,ans);
}

void rightTraversalBoundery(node* root, vector<int> &ans){
    if((root == NULL ) || (root->left == NULL && root->right == NULL)){
        return;
    }

    if(root->right) rightTraversalBoundery(root->right,ans);
    else rightTraversalBoundery(root->left,ans);

    ans.push_back(root->data);
}

void boundery(node* root){
    vector<int> ans;
    if(root == NULL){
        return;
    }

    ans.push_back(root->data);

    //traverse left part
    leftTraversalBoundery(root->left, ans);

    // traverse leaf node

    // left subtree leaf node
    leafTraversalBoundery(root->left,ans);
    // right subtree leaf node
    leafTraversalBoundery(root->right,ans);

    // traverse right part
    rightTraversalBoundery(root->right,ans);

    cout<<endl<<"Boundery traversal"<<endl;
    for(auto i: ans){
        cout<<i<<" ";
    }

}

vector<int> verticalOrder(node* root){
    map<int,map<int,vector<int>>> nodes;
    queue<pair<node*,pair<int,int>>> q;
    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    q.push(make_pair(root, make_pair(0,0)));

    while(!q.empty()){
        pair<node*, pair<int,int>> temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left, make_pair(hd -1 ,lvl+1)));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, make_pair(hd+1 , lvl+1)));
        }
    }
    for(auto i:nodes){
        for(auto j:i.second){
            for(auto k:j.second){
                ans.push_back(k);
                }
            }
        }
    return ans;
}

vector<int> topView(node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    map<int,int> topNode;
    queue<pair<node* , int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node* ,int> temp = q.front();
        q.pop();
        node* frontNode = temp.first;
        int hd = temp.second;

        // if no value is present for HD, then only insert
        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        } 

        if(frontNode->left){
            q.push(make_pair(frontNode->left,hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }
    for(auto i:topNode){
        ans.push_back(i.second);
    }
    return ans;
}


vector<int> bottomView(node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    map<int,int> bottomNode;
    queue<pair<node*,int>> q;
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<node* ,int> temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second;

        bottomNode[hd] = frontNode->data;

        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        } 
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }
    for(auto i:bottomNode){
        ans.push_back(i.second);
    }
    return ans;
}

void solveLeft(node* root,vector<int> &ans, int lvl){
    if(root == NULL) return;

    if(lvl == ans.size()){
        ans.push_back(root->data);
    }

    if(root->left) solveLeft(root->left,ans,lvl+1);
    if(root->right) solveLeft(root->right,ans,lvl+1);
}

vector<int> leftView(node* root){
    vector<int> ans;
    solveLeft(root,ans,0);
    return ans;
}

void solveRight(node* root,vector<int> &ans,int lvl){
    if(root == NULL){
        return;
    }

    if(lvl == ans.size()){
        ans.push_back(root->data);
    }

    if(root->right) solveRight(root->right,ans,lvl+1);
    if(root->left) solveRight(root->left,ans,lvl+1);
}

vector<int> rightView(node* root){
    vector<int> ans;
    solveRight(root,ans,0);
    return ans;
}

void solveSum(node* root,int sum,int &maxSum, int len,int maxLen){
    if(root == NULL){
        if(len > maxLen){
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen){
            maxSum = max(sum,maxSum);
        }
        return;
    }    

    sum = sum + root->data;

    solveSum(root->left,sum,maxSum,len+1,maxLen);
    solveSum(root->right,sum,maxSum,len+1,maxLen);
}

int sumOfLongestRootToLeaf(node* root){
    int sum = 0;
    int maxSum = INT_MIN;

    int len = 0;
    int maxLen = 0;

    solveSum(root , sum, maxSum , len , maxLen);

    return maxSum;
}

// Lowest comman ansistors in binary tree
node* loc(node* root, int n1,int n2){
    if(root == NULL) return NULL;

    if(root->data == n1 || root->data == n2){
        return root;
    }

    node* left = loc(root->left,n1,n2);
    node* right = loc(root->right,n1,n2);

    if(left != NULL && right != NULL){
        return root;
    }
    else if(left != NULL && right == NULL){
        return left;
    }
    else if(left == NULL && right != NULL){
        return right;
    }
    else{
        return NULL;
    }
}

void solveKSum(node* root,vector<int> path,int &count,int k){
    if(root == NULL) return;

    path.push_back(root->data);

    solveKSum(root->left,path,count,k);
    solveKSum(root->right,path,count,k);

    int size = path.size();
    int sum = 0;
    for(int i= size - 1; i>=0; i--){
        sum += path[i];
        if(sum == k) count++;

    }
    path.pop_back();
}

int kSumPath(node* root,int k){
    vector<int> path;
    int count = 0;
    solveKSum(root,path,count,k);
    return count;
}

node* solvekthAncestor(node* root,int &k,int nod){
    if(root == NULL){
        return NULL;
    }
    if(root->data == nod){
        return root;
    }

    node* leftans = solvekthAncestor(root->left,k,nod);
    node* rightans = solvekthAncestor(root->right,k,nod);

    if(leftans != NULL && rightans == NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return leftans;
    }
    if(leftans == NULL && rightans != NULL){
        k--;
        if(k<=0){
            k = INT_MAX;
            return root;
        }
        return rightans;
    }

    return NULL;
}

int kthAncestor(node* root,int k,int nod){
    node* ans = solvekthAncestor(root,k,nod);
    if(ans == NULL || ans->data == nod){
        return -1;
    }
    else{
        return ans->data;
    }
}



node* solveBuildTreeInPre(int in[],int pre[], int &index , int inorderStart, int inorderEnds, int n, map<int,int> &nodeToIndex){
    if(index >= n || inorderStart > inorderEnds){
        return NULL;
    }

    int element = pre[index++];
    node* root = new node(element);
    // int postion = findPosition(in,element,n);
    int position = nodeToIndex[element];

    root->left = solveBuildTreeInPre(in,pre,index,inorderStart,position - 1,n,nodeToIndex);
    root->right = solveBuildTreeInPre(in,pre,index,position + 1,inorderEnds,n,nodeToIndex);

    return root;
}

void createMapping(int in[], map<int,int> &nodeToIndex, int n ){
    for(int i=0;i<n;i++){
        nodeToIndex[in[i]] = i;
    }
}

node* buildTreeInPre(int in[], int pre[],int n){
    int preOrderIndex = 0;
    map<int,int> nodeToIndex;
    createMapping(in,nodeToIndex,n);
    node* root = solveBuildTreeInPre(in,pre,preOrderIndex,0,n-1,n,nodeToIndex);
    return root;
}


// BURN A BINARY TREE

node* createParentMapping(node* root,int target,map<node*,node*> &nodeToParent){
    node* res = NULL;
    
    queue<node*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(!q.empty()){
        node* front = q.front();
        q.pop();

        if(front->data == target){
            res = front;
        }
        if(front->left){
            nodeToParent[front->left] = front;
            q.push(front->left);
        }
        if(front->right){
            nodeToParent[front->right] =front;
            q.push(front->right);
        }
    }
    return res;
}

int burnTree(node* root, map<node*,node*> &nodeToParent){
    map<node*, bool> visited;
    queue<node*> q;

    q.push(root);
    visited[root] = true;

    int ans = 0;

    while(!q.empty()){
        bool flag = 0;
        int size = q.size();
        for(int i=0;i<size;i++){
            node* front = q.front();
            q.pop();

            if(front->left && !visited[front->left]){
                flag = 1;
                q.push(front->left);
                visited[front->left] = 1;
            }
            if(front->right && !visited[front->right]){
                flag = 1;
                q.push(front->right);
                visited[front->right] = 1;
            }
            if(nodeToParent[front] && !visited[nodeToParent[front]]){
                flag = 1;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = 1;
            }
        }
        if(flag == 1){
            ans++;
        }
    }
    return ans;
}



int minTime(Node* root,int target){

    // algo;
    // step 1: create nodeToParent mapping
    // step 2: find target node
    // step 3: burn the tree in min time

    map<node*,node*> nodeToParent;
    node* targetNode = createParentMapping(root,target,nodeToParent);

    int ans = burnTree(targetNode, nodeToParent);

    return ans;
}

int main(){

    node* root = NULL;
    root = buildTree(root);

    levelOrderTraversal(root);

    // 1 2 4 -1 -1 5 -1 -1 3 -1 -1
    // 1 2 4 6 -1 -1 -1 5 -1 -1 3 -1 -1
    // cout<<endl;
    // preOrderIterative(root);
    // cout<<endl;
    // inOrderIterative(root);
    // cout<<endl;
    // postOrderIterative(root);

    // cout<<endl<<"Height of Tree is :"<<height(root)<<endl;

    // cout<<endl<<"diameter of Tree is :"<<diameter(root)<<endl;

    // pair<int,int> ans = fastDiameter(root);
    // cout<<endl<<"diameter of Tree is :"<< ans.first <<endl;

    // bool isBal = isBalanced(root);
    // if(isBal) cout<<"Tree is Balanced"<<endl;
    // else cout<<"Tree is not Balanced"<<endl;

    // pair<bool,int> isBalFast = fastIsBalanced(root);
    // if(isBalFast.first) cout<<"Tree is Balanced"<<endl;
    // else cout<<"Tree is not Balanced"<<endl;

    // 28 3 1 -1 -1 2 -1 -1 11 5 -1 -1 6 -1 -1
    // pair<bool,int> ans = isSumTreeFast(root);
    // if(ans.first) cout<<endl<<"Sum of tree is True"<<endl;
    // else cout<<endl<<"Sum of tree is False"<<endl;


    // vector<int> ans1 = zigzag(root);
    // cout<<endl;
    // for(auto i :ans1){
    //     cout<<i<<" ";
    // }

    // 1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 8 -1 -1 9 10 -1 -1 11 -1 -1 
    // boundery(root);

    // 1 2 3 -1 -1 4 -1 -1 5 6 -1 -1 7 -1 -1
    // vector<int> vertical = verticalOrder(root);
    // cout<<"Vertical order traversal"<<endl;
    // for(auto i:vertical){
    //     cout<<i<<" ";
    // }

    // vector<int> top = topView(root);
    // cout<<endl<<"Top order traversal"<<endl;
    // for(auto i:top){
    //     cout<<i<<" ";
    // }

    // vector<int> left = rightView(root);
    // for(auto i:left){
    //     cout<<i<<" ";
    // }

    // cout<<endl<<sumOfLongestRootToLeaf(root)<<endl;

    // node* lowerstAnsistor = loc(root,4,7);
    // cout<<"Lowest ansistor of 4 and 7 is: "<<lowerstAnsistor->data;

    // 1 3 2 -1 -1 1 -1 -1 4 5 -1 -1 1 -1 -1
    cout<<endl<<kSumPath(root, 5 );

    cout<<endl<<kthAncestor(root,2,5)<<endl;;

    
    return 0;
}