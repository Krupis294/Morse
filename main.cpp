#include "morse.h"

using namespace std;

int main() {
    Morse A;
    A.init();
    A.solve();
    destroy_Morse(A.root);
    return 0;
}
