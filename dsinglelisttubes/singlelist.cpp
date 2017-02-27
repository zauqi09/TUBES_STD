#include "singlelist.h"
#include "string.h"

void createList(List &L)
{
    first(L)=nil;

}

address alokasi (infotype x)
{
    address p;
    p=new elmList;
    info(p)=x;
    next(p)=nil;

    return p;
}

void dealokasi(address &p)
{
    delete p;
}

void insertfirst(List &L, address p)
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
    void insertlast(List &L, address p)
    {
        address q;
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
                next(q)=p;
            }

        }
    }

  address findElmById(List L, char id[3])
{
    address P;
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

    void deletefirst(List &L, address p)
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

    void deletelast(List &L, address p)
    {
        if (first(L) == nil)
        {
            cout<<"list kosong"<<endl;
        }
        else
        {
            address q;
            q=first(L);
            while (next(next(q)) != nil)
            {
                q=next(q);
            }
            p=next(q);
            q=nil;
        }
    }

    void printinfo(List L)
    {
        if (first(L)==nil)
        {
            cout<<"list kosong"<<endl;
        }
        else
        {
            infotype x;
            address p=first(L);
            do
            {
                x = info(p);
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
                p=next(p);
            }
            while (p!=nil);

            }
    }
