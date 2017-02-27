#ifndef SINGLELIST_H_INCLUDED
#define SINGLELIST_H_INCLUDED
#include <iostream>
using namespace std;

#define nil NULL
#define next(P) P-> next
#define first(L) (L).first
#define info(P) (P)->info

struct bus
{
    char id[3];
    string nama;
    string kelas;
    string viatol;
    string noplat;
    string kotaasal;

};
typedef struct bus *id;
typedef bus infotype;
typedef struct elmList *address;
struct elmList
{
    infotype info;
    address next;
};

struct List
{
    address first;
};


void createlist(List &L);
address alokasi(infotype x);
void dealokasi (address &p);
void insertfirst (List &L, address p);
void insertlast (List &L, address p);
//address findelm(List L, infotype x);
address findElmById(List L, char id[3]);
void deletefirst(List &L, address &p);
void deletelast(List &L, address &p);
void printinfo(List L);
#endif // SINGLELIST_H_INCLUDED
