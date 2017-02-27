#ifndef DOUBLECIRCULAR_H_INCLUDED
#define DOUBLECIRCULAR_H_INCLUDED

#include <iostream>

using namespace std;

#define first(L) (L).first
#define last(L) (L).last
#define next(P) (P)->next
#define prev(P) (P)->prev
#define info(P) (P)->info


struct tujuan{
    char id[3];
    string kota;
    string pvsi;
    string trml;
    string almt;
    int telp;
};

//typedef int infotype;
typedef tujuan infotype;
typedef struct elmlist *address;
struct elmlist{
    infotype info;
    address next;
    address prev;
};

struct List{
    address first;
    address last;
};

void createList(List &L);
address alokasi(infotype x);
void dealokasi(address &P);
void insertFirst(List &L, address P);
void insertLast(List &L, address P);
address findElm(List L, infotype x);
address findElmById(List L, char id[3]);
void deleteFirst(List &L, address &P);
void deleteLast(List &L, address &P);
void printInfo(List L);
void insertAfter(List &L, address Prec, address P);
void deleteAfter(List &L, address Prec, address &P);

#endif // DOUBLECIRCULAR_H_INCLUDED
