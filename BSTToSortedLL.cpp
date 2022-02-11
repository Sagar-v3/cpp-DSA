#include <iostream>
#include <queue>

template <typename T>
class Node {
   public:
    T data;
    Node<T>* next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

using namespace std;

BinaryTreeNode<int>* takeInput() {
    int rootData;

    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}
class Pair
{
    public:

    Node<int>* head;
    Node<int>* tail;

};

Pair helper(BinaryTreeNode<int>* root)
{
    if(root==NULL)
    {
        Pair p;
        p.head=NULL;
        p.tail=NULL;
        return p;
    }


Pair leftnode=helper(root->left);
Pair rightnode=helper(root->right);

Pair output;

Node<int>* midnode=new Node<int>(root->data);

	if(leftnode.head!=NULL)
    {
        leftnode.tail->next = midnode;
        output.head = leftnode.head;
    }

    else
    {
        output.head = midnode;
    }


    if(rightnode.head!=NULL)
    {
        midnode->next = rightnode.head;
        output.tail = rightnode.tail;
    }

    else
        output.tail = midnode;

 return output;

}


Node<int>* constructLinkedList(BinaryTreeNode<int>* root)
{
	Pair ans=helper(root);

    return ans.head;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    Node<int>* head = constructLinkedList(root);

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}
