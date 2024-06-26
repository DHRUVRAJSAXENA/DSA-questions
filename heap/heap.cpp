#include<iostream>
using namespace std;

class heap{
    public:

    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        size = 0;
    }

    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;

        while(index > 1){
            int parent = index/2;

            if(arr[parent] < arr[index]){
                swap(arr[parent] , arr[index]);
                index = parent;
            }
            else{
                return;
            }
        }
    }

    void print(){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    void deleteFromHeap(){
        if(size == 0){
            cout<<"nothing to delete"<<endl;
            return;
        }

        
        arr[1] = arr[size];
        size--;

        int i = 1;
        while(i<size){
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && arr[i] < arr[leftIndex]){
                swap(arr[i],arr[leftIndex]);
                i = leftIndex;
            }
            else if(rightIndex < size && arr[i] < arr[rightIndex]){
                swap(arr[i],arr[rightIndex]);
                i = rightIndex;
            }
            else{
                return;
            }
        }

    }
};

void heapify(int arr[],int n,int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] < arr[left]){
        largest = left;
    }
    if(right <= n && arr[largest] < arr[right]){
        largest = right;
    }

    if(largest != i){
        swap(arr[largest] , arr[i]);
        heapify(arr,n,largest);
    }
}

void heapSort(int arr[],int n){
    int size = n;

    while(size > 1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }

    
}

// check if binary tree is complete binary tree or not -> checkCBT && checkHeap
/*
int countNode(node* root){
    if(root == NULL) return 0;

    int ans = 1 + countNode(root->left) + countNode(root->right);
    return ans;
}

bool isCBT(node* root, int index,int count){
    if(root == NULL) return true;

    if(index >= cnt) return false;
    else{
        bool left = isCBT(root->left, 2*index + 1, count);
        bool right = isCBT(root->right, 2*index + 2, count);

        return (left && right);
    }
}

bool isMaxHeap(node* root){
    if(root->left == NULL && root->right == NULL ) return true;

    if(root->right == NULL){
        return root->data > root->left->data;
    }
    else{
        bool left = isMaxHeap(root->left);
        bool right = isMaxHeap(root->right);

        return (left && right && (root->data > root->left->data && root->data > root->right->data));
    }

}

bool isHeap(node* root){
    int index = 0;
    int count = countNode(root);
    if(isCBT(root,index,count) && isMaxHeap(root)){
        return true;
    }
    else{
        return false;
    }
}
*/
// ****************************************************************************



int main(){
    heap h;
    h.insert(50);
    h.insert(54);
    h.insert(55);
    h.insert(45);
    h.insert(60);
    h.print();

    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1,54,53,55,52,50};
    int n = 5;

    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"Printing the array now"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr,n);

    cout<<"Printing sorted array now"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;


    
    return 0;
}