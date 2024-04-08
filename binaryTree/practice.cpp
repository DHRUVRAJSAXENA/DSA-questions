#include<iostream>
#include<queue>
#include<stack>
#include<bits/stdc++.h>
using namespace std;

class node{
    int data;
    node* left;
    node* right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
}

node* buildTree(node* &root){
    int data;
    cout<<"Enter Data: "<<endl;
    cin>>data;
    root = new node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter data for left child of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter data for right child of "<<data<<endl;
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
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
    }
}

void preOrder(node* root){
    if(root == NULL) return;
    stack<node*> s;
    s.push(root);

    while(!s.empty()){
        node* temp = s.top();
        s.pop();

        cout<<temp->data<< " ";

        if(temp->right) s.push(temp->right);
        if(temp->left) s.push(temp->left);
    }
}

void inOrder(node* root){
    if(root == NULL) return;

    stack<int> s;
    node temp = root;

    while(temp != NULL || !s.empty()){
        if(temp != NULL){
            s.push(temp);
            temp = temp->left;
        }
        else{
            temp = s.top();
            s.pop();
            cout<<temp->data<< " ";
            temp = temp->right;
        }
    }
}

void postorder(node* root){
    if(root == NULL) return;

    stack<node*> st1 , st2;
    st1.push(root);

    while(!st1.empty()){
        node* temp = st1.top();
        st1.pop();
        st2.push(temp);

        if(temp->left) st1.push(temp->left);
        if(temp->right) st1.push(temp->right);
    }

    while(!st2.empty()){
        node* temp = st2.top();
        cout<<temp->data<< " ";
        st2.pop();
    }
}

int height(node* root){
    if(root == NULL) return 0;

    int left = height(root->left);
    int right = height(root->right);

    int maxi = max(left,right) + 1;

    return maxi;
}

int diameter(node* root){
    if(root == NULL) return 0;

    int left = diameter(root->left);
    int right = diameter(root->right);
    int both = height(root->left) + 1 + height(root->right);

    int maxi = max(both, max(left,right));

    return maxi;
}

pair<int,int> diameterFast(node* root){
    pair<int,int> ans;
    if(root == NULL){
        ans = make_pair(0,0);
        return ans;
    }

    pair<int,int> leftAns = diameterFast(root->left);
    pair<int,int> rightAns = diameterFast(root->right);

    int left = leftAns.first;
    int right = rightAns.first;
    int both = leftAns.second + 1 + rightAns.second;

    ans.first = max(both , max(left,right));
    ans.second = max(leftAns.second,rightAns.second) + 1;

    return ans;

}

bool isBalanced(node* root){
    if(root == NULL) return true;

    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);

    bool hei = abs(height(root->left) - height(root->right)) <= 1;

    if(left && right && hei) return true;
    else return false;

}


pair<bool,int> fastIsBalanced(node* root){
    pair<bool,int> ans;
    if(root == NULL){
        ans = make_pair(true,0);
        return ans;
    }

    pair<bool,int> leftAns = fastIsBalanced(root->left);
    pair<bool,int> rightAns = fastIsBalanced(root->right);

    bool left = leftAns.first;
    bool right = rightAns.first;
    bool hei = abs(leftAns.second - rightAns.second) <= 1;

    ans.second = max(leftAns.second , rightAns.second) + 1;

    if(left , right , hei){
        ans.first = true;
    }
    else{
        ans.first = false;
    }

    return ans;
}


int main(){

    node* root = NULL;
    buildTree(root);
    
    return 0;
}