#include "morse.h"

int main() {
    Morse A;
    A.init();
    A.Solve("morse.txt");
    Destroy_Morse(A.root);
    return 0;
}
