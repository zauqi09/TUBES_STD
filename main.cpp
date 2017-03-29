#include <iostream>
#include "application.h"

/**
     * Main.cpp Oleh : AAN
     * NIM : XXXXXXXX
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
