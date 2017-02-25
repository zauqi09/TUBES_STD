#ifndef SINGLELIST_H_INCLUDED
#define SINGLELIST_H_INCLUDED
#include <iostream>
using namespace std;

#define nil NULL
#define next(P) P-> next
#define first(L) (L).first
#define info(P) (P)->info

struct bus {
    string
};
typedef bus infotype;
typedef struct elmlist *address;
struct elmlist {
    infotype info;
    address next;
    };

#endif // SINGLELIST_H_INCLUDED
