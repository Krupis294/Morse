//
// Created by Jakub Lengsfeld on 04.04.2023.
//

#include "morse.h"

Morse::Morse()
{
    root=NULL;
}

void destroy_Morse(node *root)
{
    if(root!=NULL)
    {
        destroy_Morse(root->left);
        destroy_Morse(root->right);
        delete root;
    }
}

node* Morse::insert(char key){
    node* Node=new node();
    Node->data=key;
    Node->left=NULL;
    Node->right=NULL;
    return (Node);
}

void Morse::init(){
    root=insert(' ');
    //level 1
    root->left = insert('e');
    root->right = insert('t');
    //level 2
    root->left->left = insert('i');
    root->left->right = insert('a');
    root->right->left = insert('n');
    root->right->right = insert('m');
    //level 3
    root->left->left->left = insert('s');
    root->left->left->right = insert('u');
    root->left->right->left = insert('r');
    root->left->right->right = insert('w');
    root->right->left->left = insert('d');
    root->right->left->right = insert('k');
    root->right->right->left = insert('g');
    root->right->right->right = insert('o');
    //level 4
    root->left->left->left->left = insert('h');
    root->left->left->left->right = insert('v');
    root->left->left->right->left = insert('f');
    root->left->right->left->left = insert('l');
    root->left->right->right->left = insert('p');
    root->left->right->right->right = insert('j');
    root->right->left->left->left = insert('b');
    root->right->left->left->right = insert('x');
    root->right->left->right->left = insert('c');
    root->right->left->right->right = insert('y');
    root->right->right->left->left = insert('z');
    root->right->right->left->right = insert('q');
}

void Morse::find(struct node* root, queue<char>& key,int& first,int& dot){
    if(key.empty() && dot==2){
        cout<<".";
        cout<<root->data;
        first=1;
    }
    if(!key.empty() && dot==2){
        cout<<root->data;
    }
    while(!key.empty()){
        if(key.front()=='.'){
            root=root->left;
            key.pop();
        }
        if(key.front()=='-'){
            root=root->right;
            key.pop();
        }
        if (key.empty() && first==0)
            cout<< root->data;
        dot=0;
        if (key.empty() && first==1){
            cout<<(char) toupper(root->data);
            first=0;
        }
    }
}

void Morse::solve(){
    queue<char> key;
    string Text;
    ifstream In("morse.txt");
    char c;
    int first=1;
    int dot=0;
    while (In>>c) {
        if(c =='/'){
            dot++;
            find(root,key,first,dot);
        }
        if(c != '/')
            key.push(c);
    }
    In.close();
}
