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

int inorderSuccesor(node* temp, int element){
    node* succesor = NULL;
    while(temp != NULL){
        if(element >= temp->data){
            temp = temp->right;
        }else{
            succesor = temp;
            temp = temp->left;
        }
    }
    return succesor->data;
}

node* deleteFromBST(node* root , int val){
    //base case
    if(root == NULL) return root;

    if(root->data == val){
        // 0 child
        if(root->left == NULL && root->right == NULL){
            delete root;
            return NULL;
        }

        // 1 child
        
        // left child
        if(root->left != NULL && root->right == NULL){
            node* temp = root->left;
            delete root;
            return temp;
        }

        // right child
        if(root->left == NULL && root->right != NULL){
            node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child 
        if(root->left != NULL && root->right != NULL){
            int mini = minValue(root->right)->data;
            root->data = mini;
            root->right = deleteFromBST(root->right, mini);
            return root;
        }
    }
    else if(root->data > val){
        root->left = deleteFromBST(root->left,val);
        return root;
    }
    else{
        root->right = deleteFromBST(root->right,val);
        return root;
    }
}


// Partial BST  TC - O(n) SC - O(h)
bool isBST(node *root, int min,int max){
    if(root == NULL){
        return true;

    }

    if(root->data >= min && root->data <= max){
        bool left = isBST(root->left , min , root->data);
        bool right = isBST(root->right, root->data , max);
        return left && right;
    }
    else{
        return false;
    }
}
bool validateBST(node *root) {
    // Write your code here
    bool ans = isBST(root,INT_MIN,INT_MAX);
    return ans;
}

// kth Smallest
int solvekSmall(node* root,int &i,int k){
    if(root == NULL){
        return -1;
    }

    int left = solvekSmall(root->left,i,k);

    if(left != -1){
        return left;
    }

    i++;
    if(i==k) return root->data;

    return solvekSmall(root->right , i , k);

}

int kthSmallest(node* root,int k){
    int i = 0;
    int ans = solvekSmall(root,i,k);
    return ans;
}

/*
==================MERGE TWO BST=========================
void convertIntoSortedDLL(TreeNode<int>* root, TreeNode<int>* &head){
    if(root == NULL) return;

    convertIntoSortedDLL(root->right, head);

    root->right = head;

    if(head != NULL) {
        head->left = root;
    }

    head = root;

    convertIntoSortedDLL(root->left,head);

}

TreeNode<int>* mergeLinkedList(TreeNode<int>* head1, TreeNode<int>* head2){
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    while(head1 != NULL && head2 != NULL){
        if(head1->data < head2->data){
            if(head == NULL){
                head = head1;
                tail = head1;
                head1 = head1->right;
            }else{
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else{
             if(head == NULL){
                head = head2;
                tail = head2;
                head2 = head->right;
            }else{
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }

        }
    }

    while(head1 != NULL){
        tail->right = head1;
        head1->left= tail;
        tail = head1;
        head1 = head1->right;
    }

    while(head2 != NULL){
        tail->right = head2;
        head2->left= tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;

}

int countNodes(TreeNode<int>* head){
    int cnt = 0;
    TreeNode<int>* temp = head;
    while(temp != NULL){
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

TreeNode<int>* sortedLLToBST(TreeNode<int>* &head,int n){
    if(n <= 0 || head == NULL){
        return NULL;
    }

    TreeNode<int>* leftTree = sortedLLToBST(head, n/2);
    TreeNode<int>* newRoot = head;
    newRoot->left = leftTree;

    head = head->right;

    newRoot->right = sortedLLToBST(head, n - n/2 - 1);

    return newRoot;

}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    // Write your code here.
    TreeNode<int>* head1 = NULL;
    convertIntoSortedDLL(root1,head1);
    head1->left = NULL;

    TreeNode<int>* head2 = NULL;
    convertIntoSortedDLL(root2,head2);
    head2->left = NULL;


    TreeNode<int>* head = mergeLinkedList(head1,head2);

    return sortedLLToBST(head, countNodes(head) );
}
==================MERGE TWO BST=========================
*/

int main(){

    node* root = NULL;

    cout<<"Enter data for BST"<<endl;
    takeInput(root);


    cout<<"Printing BST"<<endl;
    levelOrderTraversal(root);

    // 7 5 10 3 6 8 15 -1
    node* temp = deleteFromBST(root , 7);
    cout<<endl;
    levelOrderTraversal(temp);

    // cout<<endl<<"Inorder success function "<<inorderSuccesor(root,9);
    
    return 0;
}