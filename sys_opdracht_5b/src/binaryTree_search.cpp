/**
 * @file    binaryTree_search.cpp
 * @author  Rob Beaufort
 * @brief   In deze code wordt er een binary tree gemaakt. 
 *          In deze tree worden vervolgens 100 random waardes gezet.
 *          Tot slot is er een functie die de locatie van de meegegeven waarde geeft.
 * @version 1.0
 * @date    16-5-2025
 */

#include <iostream>
#include <cstdlib>


using namespace std;

// Deze class representeert een node in de tree.
class Node{
    public:
        Node(int value);
        int getValue();
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
int Node::getValue(){
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
        void search(int value);
        //Remove(int);
    private:
        void printTree(Node* node);
        void search(int value, Node* node);
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

        } else if ( value < currentNode->getValue()) {
            if (currentNode->left == nullptr){
                currentNode->left = new Node(value);
                success = 1;
            }
            else {
                currentNode = currentNode->left;
            }

        } else if ( value >= currentNode->getValue()){
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
    cout << node->getValue() << " ";
    printTree(node->right);

}

// Hier wordt er gekeken of de waarde geleik is aan de root.
// Als dat niet zo is dan wordt er verder gezocht vanuit de root.
void Tree::search(int value){
    if (this->root->getValue() == value){
        cout << "root: " << this->root->getValue() << endl;
    } else {
        cout << "|root| ";
        search(value, this->root);
    }
}

// Deze functie doorzoekt de tree voor de meegegeven waarde.
// Ook print deze functie daarna de route naar de waarde.
void Tree::search(int value, Node* node){
    if (node == nullptr){
        cout << "Value is not in tree" << endl;
        return;

    } else if (value == node->getValue()){
        cout << "|" << node->getValue() << "|" << endl;

    } else if (value < node->getValue()){
        cout << "|left| ";
        search(value, node->left);

    } else if (value > node->getValue()){
        cout << "|right| ";
        search(value, node->right);
        
    }
}

int main(){

    //Hier wordt er een Tree aangemaakt.
    Node *root = new Node(50);
    Tree *tree = new Tree(root);

    // Voert 100 random getalen in in de binairy tree.
    for(int i = 0; i < 100; i++){
    tree->Insert(i);
    }

    // Hier geeft de gebruiker een waarde die gezocht moet worden.
    int value;
    cout << "Welke waarde wil je zoeken?" << endl;
    cin >> value;

    // Hier wordt er een waarde in de tree gezocht.
    tree->search(value);

    return 0;
}