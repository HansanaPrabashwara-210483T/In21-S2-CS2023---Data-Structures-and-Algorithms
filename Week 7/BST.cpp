#include <iostream>
using namespace std;

struct node {
    int key;
    struct node *left, *right;
};

// Inorder traversal
/*
 * Takes the root node as the parameter
 * First print left node then the parent node and then the right node
 */
void traverseInOrder(struct node *root) {
    if(root == nullptr){
        return;
    }
    traverseInOrder(root->left);
    cout << root->key << " ";
    traverseInOrder(root->right);
}

// Insert a node
/*
 * Takes root node and the key value as parameters
 * Return the root of the BST
 */
struct node *insertNode(struct node *root, int key) {

    // If root is null create a node instance with given key and bind it with the root.
    if(root == nullptr){
        root = new node;
        root->key = key;
        root->right = nullptr;
        root->left = nullptr;

        return root;
    }

    // If key is smaller than the root key find the insert place in left side of the tree.
    if(key < root->key){
        root->left = insertNode(root->left, key);
    }

    // If key is larger than the root key find the insert place in right side of the tree.
    else if(key > root->key){
        root->right = insertNode(root->right, key);
    }

    // When the key is already existing insertion of the new key is ignored.
    else{}

    // Return the root of the BST
    return root;
}

/*
 * Takes the node to be deleted that has both children
 * Find and return the node that has the smallest key in right subtree of the given node
 */
struct node *MinInRightTree(struct node *rootNode) {
    // New node instance to store the right node of the given node
    struct node *current = rootNode->right;
    // Since the smallest key is the most leftward node and since it does not have any left child
    while (current && current->left != nullptr) {
        current = current->left;
    }
    return current;
}


// Deleting a node
/*
 * Takes the root node and the key to be deleted as parameters
 * Return the root after the deletion
 */
struct node *deleteNode(struct node *root, int key) {
    // If root in null then return null or the root
    if (root == nullptr) {
        return root;
    }

    // If key is smaller than find the node to be deleted in the left subtree
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
    }
    // If key is larger than find the node to be deleted in the right subtree
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
    }
    // If key is found proceed with the deletion process
    else {
        // If the node to be deleted is a leaf node simply remove the node.
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            root = nullptr;
        }

        // If the node to be deleted has only a right child replace the child with the node.
        else if (root->left == nullptr) {
            struct node *temp = root;
            root = root->right;
            delete temp;
        }
        // If the node to be deleted has only a left child replace the child with the node.
        else if (root->right == nullptr) {
            struct node *temp = root;
            root = root->left;
            delete temp;
        }

        // If child has the both child proceed  with the following instructions
        else {
            // find the node that has minimum key value in the right subtree. We can find the node with the maximum key value in left subtree as well
            struct node *nextReplacingSuccessor = MinInRightTree(root);
            // Replace the root with the minimum root
            root->key = nextReplacingSuccessor->key;
            // Delete the duplicate minimum value in the bst
            root->right = deleteNode(root->right, nextReplacingSuccessor->key);
        }
    }
    // return the root
    return root;
}

// Driver code
int main() {
    struct node *root = nullptr;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch(operation) {
            case 1: // insert
                cin >> operand;
                root = insertNode(root, operand);
                cin >> operation;
                break;
            case 2: // delete
                cin >> operand;
                root = deleteNode(root, operand);
                cin >> operation;
                break;
            default:
                cout << "Invalid Operator!\n";
                return 0;
        }

    }
    traverseInOrder(root);
}