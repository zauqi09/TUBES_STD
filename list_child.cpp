#include "list_child.h"
#include "string.h"

void createList(List_child &L)
{
    first(L)=nil;

}

address_child alokasi (infotype_child x)
{
    address_child p;
    p=new elmList_child;
    info(p)=x;
    next(p)=nil;

    return p;
}

void dealokasi(address_child &p)
{
    delete p;
}

void insertfirst(List_child &L, address_child p)
{
    //address Q;
    if ( first(L) == nil )
    {
        first(L)=p;
        next(p)=nil;

    }
    else
    {
        next(p)=first(L);
        first(L)=p;

    }
}
    void insertlast(List_child &L, address_child p)
    {
        address_child q;
        if ( first(L) == nil )
        {
            first(L)=p;
            next(p)=nil;
        }
        else
        {
            q=first(L);
            while(next (q) !=nil)
            {
                q=next(q);
            }
            next(q)=p;
            next(p) = nil;
        }
    }

  address_child findElmById(List_child L, char id[3])
{
    address_child P;
    P = first(L);
    while(P != nil)
    {
        if (strcmpi(info(P).id,id) == 0)
        {
            return P;
        }
        P = next(P);
    }
    return NULL;
}

//    address findelm(List L, infotype x)
//    {
//        address p;
//        p=first(L);
//        while ((info(p) != x) &&(p!=nil))
//        {
//            p=next(p);
//        }

//        return p;
//    }

    void deletefirst(List_child &L, address_child p)
    {
        if (first(L) == nil)
        {
            cout<<"list kosong"<<endl;
        }
        else
        {
            p=first(L);
            first(L)=next(first(L));
            next(p)=nil;
        }
    }

    void deletelast(List_child &L, address_child p)
    {
        if (first(L) == nil)
        {
            cout<<"list kosong"<<endl;
        }
        else
        {
            address_child q;
            q=first(L);
            while (next(next(q)) != nil)
            {
                q=next(q);
            }
            p=next(q);
            q=nil;
        }
    }

    void print(infotype_child x) {

                cout << "ID :";
                cout << x.id << endl;
                cout << "Nama Bus :";
                cout << x.nama << endl;
                cout << "Kelas Bus :";
                cout << x.kelas << endl;
                cout << "Via Tol :";
                cout << x.viatol << endl;
                cout << "No Plat :";
                cout << x.noplat << endl;
                cout << "Kota Asal Bus :";
                cout << x.kotaasal << endl;
    }

    void printinfo(List_child L)
    {
        if (first(L)==nil)
        {
            cout<<"list kosong"<<endl;
        }
        else
        {
            infotype_child x;
            address_child p=first(L);
            do
            {
                print(info(p));
                p=next(p);
            }
            while (p!=nil);
            }
    }

void sort(List_child &L) {

    int swapped = 1;
    address_child P;
    infotype_child a, b;

    while (swapped == 1) {

        swapped = 0;
        P = first(L);
        while (next(P) != NULL) {
            a = info(P);
            b = info(next(P));
            if (strcmpi(a.id, b.id) > 0) {
                info(P) = b;
                info(next(P)) = a;
                swapped = 1;
            }
            P = next(P);
        }
    }
}
