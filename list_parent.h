#ifndef DOUBLECIRCULAR_H_INCLUDED
#define DOUBLECIRCULAR_H_INCLUDED

#include <iostream>
//#include "define.h"
using namespace std;
#define next(P) P->next
#define prev(P) P->prev
#define first(L) L.first
#define last(L) L.last
#define info(P) P->info

struct parent{
    char id[3];
    string kota;
    string pvsi;
    string trml;
    string almt;
    int telp;
};

//typedef int infotype;
typedef parent infotype_parent;
typedef struct elmlist_parent *address_parent;
struct elmlist_parent{
    infotype_parent info;
    address_parent next;
    address_parent prev;
};

struct List_parent{
    address_parent first;
    address_parent last;
};

void createList(List_parent &L);
address_parent alokasi(infotype_parent x);
void dealokasi(address_parent &P);
void insertFirst(List_parent &L, address_parent P);
void insertLast(List_parent &L, address_parent P);
address_parent findElm(List_parent L, infotype_parent x);
address_parent findElmById(List_parent L, char id[3]);
void deleteFirst(List_parent &L, address_parent &P);
void deleteLast(List_parent &L, address_parent &P);
void printInfo(List_parent L);
void insertAfter(List_parent &L, address_parent Prec, address_parent P);
void deleteAfter(List_parent &L, address_parent Prec, address_parent &P);

#endif // DOUBLECIRCULAR_H_INCLUDED
