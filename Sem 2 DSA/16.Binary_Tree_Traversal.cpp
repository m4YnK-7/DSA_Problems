#include<iostream>
#include<queue>
using namespace std;

struct node{
    int data;
    struct node* lchild;
    struct node* rchild;
};

class tree{
    public:
    struct node *root = NULL;
    tree(int val){
        root = create_node(val);
    }
    struct node* create_node(int val){
        struct node* newnode = new struct node;
        newnode->data = val;
        newnode->lchild = NULL;
        newnode->rchild = NULL;
        return newnode;
    }
    void create_tree();
    void postorder(struct node* root);
};

void tree::create_tree(){
    queue<struct node*> queue;
    queue.push(root);
    int x;
    struct node *temp = root;

    while(!queue.empty()){
        temp = queue.front();
        queue.pop();
        cout<<"Enter the lchild of "<<temp->data<<": ";
        cin>>x;
        if(x==-1){temp->lchild = NULL;}
        else{
            temp->lchild = create_node(x);
            queue.push(temp->lchild);
        }

        cout<<"Enter the rchild of "<<temp->data<<": ";
        cin>>x;
        if(x==-1){temp->rchild = NULL;}
        else{
            temp->rchild = create_node(x);
            queue.push(temp->rchild);
        }
        
    }
}
void tree::postorder(struct node* root){
    if(root==NULL) return;
    postorder(root->lchild);
    postorder(root->rchild);
    cout<<root->data<<"->";    
}

int main(){
    tree t(1);
    t.create_tree();

    cout<<"Postorder of the tree: ";
    t.postorder(t.root);
    cout<<"End\n";

    return 0;
}