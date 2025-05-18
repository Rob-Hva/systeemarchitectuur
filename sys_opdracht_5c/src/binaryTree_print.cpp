/**
 * @file    binaryTree_print.cpp
 * @author  Rob Beaufort
 * @brief   In deze code wordt er een binary tree gemaakt. 
 *          In deze tree worden vervolgens 20 random waardes gezet.
 *          Tot slot is er een functie die de gehele tree in de terminal print.
 * @version 1.0
 * @date    18-5-2025
 */

#include <iostream>
#include <cstdlib>
#include <cmath>
#include <vector>

#define TREE_SYMBOL_UNDERNUMBER 1 // Dit is het symbool dat onder de node komt te staan. "|"
#define TREE_SYMBOL_SIDEWAYS 2 // Dit is het symbool dat naast het symbool onder de node komt te staan. "_"
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
        void printSortedValues();
        int longestLeaf();
        //Remove(int);
    private:
        void search(int value, Node* node);
        void printTree(Node* node, vector<vector<vector<int>>>& output, int row, int column, int offset);
        int longestLeaf(Node* node);
        void printSortedValues(Node* node);
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
void Tree::printSortedValues(){
    printSortedValues(this->root);
}

// Deze functie print alle waardes van een tree in volgorde van klein naar groot.
void Tree::printSortedValues(Node* node){

    if (node == nullptr) return;

    printSortedValues(node->left);
    cout << node->getValue() << " ";
    printSortedValues(node->right);

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

// Deze functie geeft de lengte van de langste leaf terug.
int Tree::longestLeaf(){
    return longestLeaf(root);
}

// Deze functie geeft de lengte van de langste leaf terug.
int Tree::longestLeaf(Node* node) {
    if (node == nullptr) return 0;

    int leftDepth = longestLeaf(node->left);
    int rightDepth = longestLeaf(node->right);

    return max(leftDepth, rightDepth) + 1;
}

// Deze functie print de tree in de terminal.
void Tree::printTree(){

    // Hier wordt er een 3D vector aangemaakt die de tree gaat representeren.
    // De 3de dimensie van de vector is om de takken van de tree te representeren.
    int width = pow(2, (longestLeaf()));
    int length = 2 * longestLeaf();
    vector<vector<vector<int>>> output = vector<vector<vector<int>>>(length, vector<vector<int>>(width, vector<int>(2,0)));

    // Hier worden de startwaarden van de eerste node ingesteld
    int column = width / 2;
    int initialOffset = column / 2;

    // Hier wordt de tree in de vector gezet met behulp van recursie.
    printTree(root, output, 0, column, initialOffset);

    // Hier wordt de vector met de tree geprint.
    for (int i = 0; i < length; i++){
        for (int j = 0; j < width; j++){
            if (output[i][j][0] != 0){
                cout << output[i][j][0];
            } else {
                cout << " ";
            }
        }

        cout << endl;

        for (int j = 0; j < width; j++){
            if (output [i][j][1] == TREE_SYMBOL_UNDERNUMBER){
                cout << "|";
            } else if (output [i][j][1] == TREE_SYMBOL_SIDEWAYS){
                cout << "_";
            } else{
                cout << " ";
            }
        }
        cout << endl;
    }
}

// Deze functie wordt gebruikt om alle waardes van de tree in een 3D vector te zetten.
// Hiervoor wordt er gebruik gemaakt van recursie.
void Tree::printTree(Node* node, vector<vector<vector<int>>>& output, int row, int column, int offset){
    if (node == nullptr) return;

    // Hier wordt zoekt de functie de linkerkant van de tree door.
    printTree(node->left, output, (row + 1), (column - offset), (offset / 2));

    // Hier worden alle waardes van de tree in de vector gezet.
    output[row][column][0] = node->getValue();

    // Hier worden de waardes die de takken van de tree representeren in de vector gezet.
    for (int i = (column - offset); i <= (column + offset); i++){
        output[row][i][1] = TREE_SYMBOL_SIDEWAYS;
    }
    output[row][column][1] = TREE_SYMBOL_UNDERNUMBER;

    // Hier worden ook alle rechter delen van de tree doorzocht.
    printTree(node->right, output, (row + 1), (column + offset), (offset / 2));
}

int main(){

    //Hier wordt er een Tree aangemaakt.
    Node *root = new Node(5);
    Tree *tree = new Tree(root);

    // Voert 20 random getalen in in de binairy tree.
    for(int i = 0; i < 20; i++){
    tree->Insert(rand() % 10);
    }

    // Hier wordt de tree geprint.
    tree->printTree();

    return 0;
}