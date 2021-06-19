#include "ArraySequence.cpp"
#include "LinkedList.h"
using namespace std;
#include "MenuVector.h"

int main() {
    Tests_DA_LL();

    constructors_AS();
    decomposition_AS();
    function_AS();
    constructors_LLS();
    decomposition_LLS();
    function_LLS();

    cout << "\nYou are going to work with vectors\n" << endl;
    menuVector();
}
