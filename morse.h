//
// Created by Jakub Lengsfeld on 04.04.2023.
//
#pragma once
#include <iostream>
#include <fstream>
#include <queue>
#include <cctype>

using namespace std;

struct node{
    char data;
    node *left;
    node *right;
};


class Morse
{
public:
    Morse();
    node* root;
    node* insert(char key);
    void init();
    void solve();
    void find(struct node* root, queue<char>& key, int& first, int& dot);
};

void destroy_Morse(node *root);