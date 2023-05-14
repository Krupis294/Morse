/**
 * @author Jakub Lengsfeld
 * @date 04.04.2023
 */
#pragma once
#include <iostream>
#include <fstream>
#include <queue>
#include <cctype>

using namespace std;

/**
 * @param data znak
 * @param left posun do leve vetve v BT
 * @param right posun do prava vetve v BT
 */
struct node {
    char data;
    node *left;
    node *right;
};

class Morse {
public:
    Morse();
    node* root;

    /**
     *
     * @param key znak na prirazeni do Morseovy abecedy
     * @return strukturu s prirazenym znakem
     */
    node* Insert(char key);

    /**
     * Inicializace BT
     */
    void init();

    /**
     * Funkce na prochazeni kazdeho znaku zvlast z souboru
     * @param file nazev souboru pro cteni morseovky
     */
    void Solve(string file);

    /**
     *  Funkce na hledani pismene v BT
     *  @param root BT
     *  @param MorseSignals fronta znaku
     *  @param first osetreni velkeho pismene
     *  @param slash pocet lomitek
     */
    static void Find(struct node* root, queue<char>& MorseSignals, int& first, int& slash);
};

/**
 *  Uvolneni pameti
 */
void Destroy_Morse(node *root);
