#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
     int data;
     node* left;
     node* right;

     node(int d){
        data = d;
        left = NULL;
        right = NULL;
     }
};

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

node* buildBST(node* root, int d){
    if(root == NULL){
        root = new node(d);
        return root;
    }

    if(d > root->data){
        root->right = buildBST(root->right , d);
    }
    else{
        root->left = buildBST(root->left,d);
    }
    return root;
}

void takeInput(node* &root){
    int data;
    cin>>data;

    while(data != -1){
        root = buildBST(root, data);
        cin>>data;
    }
}

bool searchInBST(node *root, int x) {
    // Write your code here.
    node* temp = root;

    while(temp != NULL){
        if(temp->data == x){
            return true;
        }
        else if(temp->data < x){
            temp = temp->right;
        }
        else{
            temp = temp->left;
        }
    }
    return false;
}

node* minValue(node* root){
    node* temp = root;

    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

node* maxValue(node* root){
    node* temp = root;

    while(temp->right != NULL){
        temp = temp->right;

    }

    return temp;
}

int main(){

    node* root = NULL;

    cout<<"Enter data for BST"<<endl;
    takeInput(root);


    cout<<"Printing BST"<<endl;
    levelOrderTraversal(root);
    
    return 0;
}