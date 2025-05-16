/**
 * @file    binaryTree.cpp
 * @author  Rob Beaufort
 * @brief   In deze code wordt er een binary tree gemaakt. 
 *          In deze tree worden vervolgens 100 random waardes gezet.
 *          Deze worden tot slot in volgorde van klein naar groot geprint.
 * @version 1.0
 * @date    15-5-2025
 */

#include <iostream>
#include <cstdlib>


using namespace std;

// Deze class representeert een node in de tree.
class Node{
    public:
        Node(int value);
        int GetValue();
        void printNode();
        Node* right;
        Node* left;
    private:
        int value;
};

// Dit is de constructor van Node.
// Hier wordt de waarde aan de node toegekend en de pointers naar de kinderen meegegeven.
Node::Node(int value){
    this->value = value;
    left = nullptr;
    right = nullptr;
}

// Deze functie geeft de waarde van een node terug.
int Node::GetValue(){
    return value;
}

// Deze functie print de waarde van een node.
void Node::printNode(){
    cout << "Node: " << value <<endl;
}

// Dit is de class tree. Hier worden alle Nodes aan elkaar gekoppeld.
class Tree{
    public:
        Tree(Node* node);
        void Insert(int);
        void printTree();
        void printTree(Node* node);
        //Remove(int);
    private:
        Node* root;
};

// Dit is de constructor van Tree. Hier wordt de meegegeven node als root ingesteld.
Tree::Tree(Node* node){
    this->root = node;
}

// Deze functie voegt een waarde toe aan de tree.
// Hierbij wordt er gekeken waar de waarde in de binary tree moet komen te staan.
void Tree::Insert(int value){

    Node* currentNode = root;
    int success = 0;

    while (success == 0){
            if (root == nullptr) {
            root = new Node(value);

        } else if ( value < currentNode->GetValue()) {
            if (currentNode->left == nullptr){
                currentNode->left = new Node(value);
                success = 1;
            }
            else {
                currentNode = currentNode->left;
            }

        } else if ( value >= currentNode->GetValue()){
            if (currentNode->right == nullptr){
                currentNode->right = new Node(value);
                success = 1;
            } else {
                currentNode = currentNode->right;
            }
        }
    }
}

// Deze functie print alle waardes van een tree in volgorde van klein naar groot.
void Tree::printTree(){
    printTree(this->root);
}

// Deze functie print alle waardes van een tree in volgorde van klein naar groot.
void Tree::printTree(Node* node){

    if (node == nullptr) return;

    printTree(node->left);
    cout << node->GetValue() << " ";
    printTree(node->right);

}

int main(){

    //Hier wordt er een Tree aangemaakt.
    Node *root = new Node(10000);
    Tree *tree = new Tree(root);

    // Voert 100 random getalen in in de binairy tree.
    for(int i = 0; i < 100; i++){
    tree->Insert(rand());
    }

    // Hier worden alle waardes van de tree op volgorde geprint.
    tree->printTree();

    return 0;
}