#include <iostream>

using namespace std;

struct Node {
    Node* left;
    Node* right;
    int data;
    Node() {
        left = nullptr;
        right = nullptr;
    }
    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

class BST {

public:
    Node* root;
    BST() {
        root = nullptr;
    }

    //// insert ///
   /* void insertNode(int value) {
        Node* newNode = new Node(value);
        if (root == nullptr) {
            root = newNode;
        }
        else {
            Node* currentNode = root;
            while (true) {
                if (currentNode->data > newNode->data) { // go to left branch
                    if (currentNode->left == nullptr) {
                        currentNode->left = newNode;
                        break;
                    }
                    else {
                        currentNode = currentNode->left; // continue checking
                    }
                }
                else { // go to right
                    if (currentNode->right == nullptr) {
                        currentNode->right = newNode;
                        break;
                    }
                    else {
                        currentNode = currentNode->right; // continue checking
                    }
                }
            }
        }
    }
*/
Node* insertNode(Node* node ,int value){
    if (node == nullptr)
        return new Node(value);
    if(node ->data > value)
        node ->left = insertNode(node ->left,value);
    else
                node ->right = insertNode(node ->right,value);
    return node;

}
void insert(int val)
{
    root = insertNode(root,val);
}


    // delete ///

     void deleteNode(int val) {
        root = bstDelete(root, val);
    }
    Node* bstDelete(Node* node, int val) {
        if (node == nullptr) {
            return node;
        }
        if (node->data > val) {
            node->left = bstDelete(node->left, val);
            return node;
        }
        if (node->data < val) {
            node->right = bstDelete(node->right, val);
            return node;
        }

        if (node->left == nullptr) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (node->right == nullptr) {
            Node* temp = node->left;
            delete node;
            return temp;
        }
        else {
            Node* succParent = node;

            // Find successor
            Node* succ = root->right;
            while (succ->left != nullptr) {
                succParent = succ;
                succ = succ->left;
            }
            if (succParent != node)
                succParent->left = succ->right;
            else
                succParent->right = succ->right;

            // Copy Successor Data to root
            node->data = succ->data;

            // Delete Successor and return root
            delete succ;
            return node;
        }

    }


    //////

    Node* getParent(int val) {
        Node* currentNode = root;
        while (currentNode != nullptr) {
            if (currentNode->left != nullptr && currentNode->left->data == val) {
                    return currentNode;
                }
            if (currentNode->right != nullptr && currentNode->right->data == val) {
                    return currentNode;
                }
            if (currentNode->data > val) {
                currentNode = currentNode->left;
            }
            else currentNode = currentNode->right;
        }
        return NULL;
    }


    int countNodes(Node* node) {
        if (node != nullptr) {
           return 1+countNodes(node->left)+countNodes(node->right);
        }
        else return 0;
    }

    void printTree() {
        cout<<"InOrder: ";inOrder(root);cout<<endl;
        cout<<"PreOrder: ";preOrder(root);cout<<endl;
        cout<<"PostOrder: ";postOrder(root);cout<<endl;
    }

    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);
            cout<<node->data<<" ";
            inOrder(node->right);
        }
    }

    void preOrder(Node* node) {
        if (node != nullptr) {
            cout<<node->data<<" ";
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void postOrder(Node* node) {
        if (node != nullptr) {
            postOrder(node->left);
            postOrder(node->right);
            cout<<node->data<<" ";
        }
    }

};

int main()
{


    BST t;
    t.insert(50);
    t.insert(60);
    t.insert(30);
    t.insert(25);
    t.insert(40);
    t.insert(35);
    t.insert(70);
    t.insert(65);
    ////////////////////////////////////////////////////////////////
   /* t.insertNode(11);
    t.insertNode(27);
    t.insertNode(26);
    t.insertNode(29);
    t.insertNode(45);*/
    t.printTree();
    cout << "****************" << endl;
    Node *Node = t.getParent(65);

    cout << "Parent of 65=" << Node->data << endl;
    cout << "****************" << endl;
    t.deleteNode(30);
    t.printTree();
    cout << "****************" << endl;
    cout << " numbers of nodes"<<t.countNodes(t.root) << endl;
    system("pause");
    return 0;
}
