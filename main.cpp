#include <iostream>
#include "application.h"

/**
     * Oleh : Andaresta Fauzan
     * NIM : 1301164189
*/

using namespace std;
List_child LC;
List_parent LP;
List_relasi LR;
int main()
{

    createList(LP);
    createList(LR);
    createList(LC);

    mainmenu(LP, LC, LR);
    return 0;
}
