#ifndef SINGLELIST_H_INCLUDED
#define SINGLELIST_H_INCLUDED
#include <iostream>
using namespace std;
#define nil NULL
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

/**
     * ADT Oleh : Fuad Zauqi Nur
     * NIM : 1301164392
     */

struct child
{
    char id[32];
    char nama[32];
    char kelas[32];
    char viatol[32];
    char noplat[32];
    char kotaasal[32];

};
//typedef struct child *id;
typedef child infotype_child;
typedef struct elmList_child *address_child;
struct elmList_child
{
    infotype_child info;
    address_child next;
};

struct List_child
{
    address_child first;
};


void createList(List_child &L);
address_child alokasi(infotype_child x);
void dealokasi (address_child &p);
void insertfirst (List_child &L, address_child p);
void insertlast (List_child &L, address_child p);
void deleteafter(List_child &L, address_child q, address_child p);
void insertafter(List_child &L, address_child prec, address_child p);
//address findelm(List L, infotype x);
address_child findElmById(List_child L, char id[32]);
void deletefirst(List_child &L, address_child &p);
void deletelast(List_child &L, address_child &p);
void print(infotype_child x);
void printinfo(List_child L);
void sort(List_child &L);
void deleteElm(List_child &L, address_child P);
void printrelasi(infotype_child x);

#endif // SINGLELIST_H_INCLUDED
