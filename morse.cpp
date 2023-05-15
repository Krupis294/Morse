//
// Created by Jakub Lengsfeld on 04.04.2023.
//

#include "morse.h"

Morse::Morse() {
    root = nullptr;
}

void Destroy_Morse(node *root) {
    if (root != nullptr) {
        Destroy_Morse(root->left);
        Destroy_Morse(root->right);
        delete root;
    }
}

node* Morse::Insert(char key) {
    node* Node = new node();
    Node->data = key;
    Node->left = nullptr;
    Node->right = nullptr;
    return (Node);
}

void Morse::init() {
    root = Insert(' ');
    //level 1
    root->left = Insert('e');
    root->right = Insert('t');
    //level 2
    root->left->left = Insert('i');
    root->left->right = Insert('a');
    root->right->left = Insert('n');
    root->right->right = Insert('m');
    //level 3
    root->left->left->left = Insert('s');
    root->left->left->right = Insert('u');
    root->left->right->left = Insert('r');
    root->left->right->right = Insert('w');
    root->right->left->left = Insert('d');
    root->right->left->right = Insert('k');
    root->right->right->left = Insert('g');
    root->right->right->right = Insert('o');
    //level 4
    root->left->left->left->left = Insert('h');
    root->left->left->left->right = Insert('v');
    root->left->left->right->left = Insert('f');
    root->left->right->left->left = Insert('l');
    root->left->right->right->left = Insert('p');
    root->left->right->right->right = Insert('j');
    root->right->left->left->left = Insert('b');
    root->right->left->left->right = Insert('x');
    root->right->left->right->left = Insert('c');
    root->right->left->right->right = Insert('y');
    root->right->right->left->left = Insert('z');
    root->right->right->left->right = Insert('q');
}

void Morse::Find(struct node* root, queue<char>& MorseSignals, int& first, int& slash) {
    //konec vety
    if(MorseSignals.empty() && slash == 2) {
        cout << ".";
        cout << root->data;
        first = 1;
    }
    if(!MorseSignals.empty() && slash == 2) {
        cout << root->data;
    }
    //posun BT k vyhledani daneho pismene
    while(!MorseSignals.empty()) {
        if(MorseSignals.front() == '.') {
            root = root->left;
            MorseSignals.pop();
        }
        if(MorseSignals.front() == '-') {
            root = root->right;
            MorseSignals.pop();
        }
        //osetreni velkeho pismene na zacatku vety
        if (MorseSignals.empty() && first == 0)
            cout << root->data;
        if (MorseSignals.empty() && first == 1) {
            cout << (char) toupper(root->data);
            first = 0;
        }
        slash = 0;
    }
}

void Morse::Solve(string file) {
    queue<char> MorseSignals;
    ifstream In(file);
    char c;
    int first = 1, slash = 0;
    //while loop, ktery cte postupne vsechny znaky
    while (In >> c) {
        if(c =='/') {
            slash ++;
            Find(root,MorseSignals,first,slash);
        }
        //pridani . nebo - do fronty
        if(c != '/')
            MorseSignals.push(c);
    }
    In.close();
}
