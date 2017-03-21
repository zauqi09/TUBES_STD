#ifndef SINGLELIST_H_INCLUDED
#define SINGLELIST_H_INCLUDED
#include <iostream>
using namespace std;
#define nil NULL
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info

struct child
{
    char id[3];
    string nama;
    string kelas;
    string viatol;
    string noplat;
    string kotaasal;

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
//address findelm(List L, infotype x);
address_child findElmById(List_child L, char id[3]);
void deletefirst(List_child &L, address_child &p);
void deletelast(List_child &L, address_child &p);
void print(infotype_child x);
void printinfo(List_child L);
void sort(List_child &L);

#endif // SINGLELIST_H_INCLUDED
