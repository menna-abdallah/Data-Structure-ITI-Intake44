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
    void insertNode(int value) {
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
                    if (currentNode->right == NULL) {
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

    // delete ///



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
    t.insertNode(50);
    t.insertNode(60);
    t.insertNode(30);
    t.insertNode(25);
    t.insertNode(40);
    t.insertNode(35);
    t.insertNode(70);
    t.insertNode(65);
    ////////////////////////////////////////////////////////////////
    t.insertNode(11);
    t.insertNode(27);
    t.insertNode(26);
    t.insertNode(29);
    t.insertNode(45);
    t.printTree();
    cout << "****************" << endl;
    Node *Node = t.getParent(65);

    cout << "Parent of 65=" << Node->data << endl;
    cout << "****************" << endl;
   // t.Delete(30);
    t.printTree();
    cout << "****************" << endl;
    cout << " numbers of nodes"<<t.countNodes(t.root) << endl;
    system("pause");
    return 0;
}
