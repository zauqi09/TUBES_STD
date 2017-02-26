#include "doublecircular.h"
#include "string.h"

void createList(List &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

address alokasi(infotype x)
{
    address P;
    P = new elmlist;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void dealokasi(address &P)
{
    delete P;
}

void insertFirst(List &L, address P)
{
    if ((first(L) == NULL) && (last(L) == NULL))
    {
        first(L) = P;
        next(P) = first(L);
        prev(P) = first(L);
        last(L) = P;
    }
    else
    {
        next(P) = first(L);
        prev(P) = last(L);
        next(last(L)) = P;
        prev(first(L)) = P;
        first(L) = P;
    }
}

void insertLast(List &L, address P)
{
    if ((first(L) == NULL) && (last(L) == NULL))
    {
        first(L) = P;
        next(P) = first(L);
        prev(P) = first(L);
        last(L) = P;
    }
    else
    {
        next(P) = first(L);
        prev(P) = last(L);
        next(last(L)) = P;
        prev(first(L)) = P;
        last(L) = P;
    }
}

//address findElm(List L, infotype x){
//    address P;
//    if (first(L) == last(L))
//    {
//        cout << "List kosong\n";
//    }
//    else
//    {
//        P = first(L);
//        while ((info(P).id != x) && (P != last(L)))
//        {
//            P = next(P);
//        }
//    }
//    return P;
//}

address findElmById(List L, char id[3])
{
    address P;
    P = first(L);
    while(P != last(L))
    {
        if (strcmpi(info(P).id,id) == 0)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

void deleteFirst(List &L, address &P)
{
    if (first(L) == last(L))
    {
        P = first(L);
        next(P) = NULL;
        prev(P) = NULL;
        first(L) = NULL;
        last(L) = NULL;
    }
    else
    {
        P = first(L);
        first(L) = next(P);
        next(last(L)) = first(L);
        prev(first(L)) = last(L);
        next(P) = NULL;
        prev(P) = NULL;
    }
    dealokasi(P);
}

void deleteLast(List &L, address &P)
{
    if (first(L) == last(L))
    {
        P = first(L);
        next(P) = NULL;
        prev(P) = NULL;
        first(L) = NULL;
        last(L) = NULL;
    }
    else
    {
        P = last(L);
        last(L) = prev(P);
        next(last(L)) = first(L);
        prev(first(L)) = last(L);
        next(P) = NULL;
        prev(P) = NULL;
    }
    dealokasi(P);
}

void printInfo(List L)
{
    if ((first(L) == NULL) && (last(L) == NULL))
    {
        cout << "List kosong\n";
    }
    else
    {
        address P;
        infotype x;
        P = first(L);
        while (P != last(L))
        {
            x = info(P);
            cout << "ID :";
            cout << x.id << endl;
            cout << "Kota :";
            cout << x.kota << endl;
            cout << "Provinsi :";
            cout << x.pvsi << endl;
            cout << "Alamat Terminal :";
            cout << x.almt << endl;
            cout << "No. Telepon Terminal :";
            cout << x.telp << endl;
            P = next(P);
        }
        x = info(P);
        cout << "ID :";
        cout << x.id << endl;
        cout << "Kota :";
        cout << x.kota << endl;
        cout << "Provinsi :";
        cout << x.pvsi << endl;
        cout << "Alamat Terminal :";
        cout << x.almt << endl;
        cout << "No. Telepon Terminal :";
        cout << x.telp << endl;
    }
}

void insertAfter(List &L, address Prec, address P)
{
    next(P) = next(Prec);
    prev(P) = Prec;
    prev(next(Prec)) = P;
    next(Prec) = P;
}

void deleteAfter(List &L, address Prec, address &P)
{
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
}
