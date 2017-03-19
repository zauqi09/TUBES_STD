#include "list_parent.h"
#include "string.h"

void createList(List_parent &L)
{
    first(L) = NULL;
    last(L) = NULL;
}

address_parent alokasi(infotype_parent x)
{
    address_parent P;
    P = new elmlist_parent;
    info(P) = x;
    next(P) = NULL;
    prev(P) = NULL;
    return P;
}

void dealokasi(address_parent &P)
{
    delete P;
}

void insertFirst(List_parent &L, address_parent P)
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

void insertLast(List_parent &L, address_parent P)
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

address_parent findElmById(List_parent L, char id[3])
{
    address_parent P;
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

void deleteFirst(List_parent &L, address_parent &P)
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

void deleteLast(List_parent &L, address_parent &P)
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

void printInfo(List_parent L)
{
    if ((first(L) == NULL) && (last(L) == NULL))
    {
        cout << "List kosong\n";
    }
    else
    {
        address_parent P;
        infotype_parent x;
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

void insertAfter(List_parent &L, address_parent Prec, address_parent P)
{
    next(P) = next(Prec);
    prev(P) = Prec;
    prev(next(Prec)) = P;
    next(Prec) = P;
}

void deleteAfter(List_parent &L, address_parent Prec, address_parent &P)
{
    P = next(Prec);
    next(Prec) = next(P);
    prev(next(P)) = Prec;
    next(P) = NULL;
    prev(P) = NULL;
}
