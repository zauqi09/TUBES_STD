#include "list_relasi.h"
#include "string.h"

void createList(List_relasi &L) {
    /**
     * Oleh : Fuad Zauqi Nur
     * NIM : 1301164392
     */
    first(L) = NULL;
}

address_relasi alokasi(address_parent P, address_child C) {
    /**
     * Oleh : Fuad Zauqi Nur
     * NIM : 1301164392
     */
    address_relasi Q = new elmlist_relasi;
    child(Q) = C;
    parent(Q) = P;
    next(Q) = NULL;
    return Q;
}

void insertFirst(List_relasi &L, address_relasi P) {
    /**
     * Oleh : Fuad Zauqi Nur
     * NIM : 1301164392
     */
    next(P) = first(L);
    first(L) = P;
}

void insertLast(List_relasi &L, address_relasi P)
    {
        /**
     * Oleh : Fuad Zauqi Nur
     * NIM : 1301164392
     */
        address_relasi q;
        if ( first(L) == NULL )
        {
            first(L)=P;
            next(P)=NULL;
        }
        else
        {
            q=first(L);
            while(next (q) != NULL)
            {
                q=next(q);
            }
            next(q)=P;
            next(P)=NULL;

        }
    }

void print(address_relasi P) {
    /**
     * Oleh : Fuad Zauqi Nur
     * NIM : 1301164392
     */

    cout<<"Kota"<<" <- "<<"Bus"<<endl;
    printrelasi(info(P->parent));
    cout<< " <- ";
    printrelasi(info(P->child));
    cout<< ""<<endl;
     // print info terminal
     // print info bis
}

void printInfo(List_relasi L) {
    /**
     * Oleh : Andaresta Fauzan
     * NIM : 1301164189
     */
    address_relasi P = first(L);
    if (first(L)==nil)
        {
            cout<<"list kosong"<<endl;
        }
        else
        {
        while(P !=NULL) {
            print(P);
            P = next(P);
        }
        }
}

void dealokasi(address_relasi &P){
    /**
     * Oleh : Fuad Zauqi Nur
     * NIM : 1301164392
     */
    delete P;
}

address_relasi findElm(List_relasi L, address_parent P, address_child C) {
    /**
     * Oleh : Andaresta Fauzan
     * NIM : 1301164189
     */
    address_relasi Q = first(L);
    while(Q != NULL) {
        if((parent(Q)==P) && (child(Q)== C)) {
            return Q;
        }
        Q = next(Q);
    }
    return NULL;
}

void insertAfter(address_relasi &Prec, address_relasi P) {
    /**
     * Oleh : Fuad Zauqi Nur
     * NIM : 1301164392
     */
    next(P) = next(Prec);
    next(Prec) = P;
}

  void deleteFirst(List_relasi &L, address_relasi &P)
    {
        /**
     * Oleh : Fuad Zauqi Nur
     * NIM : 1301164392
     */
        if (first(L) == NULL)
        {
            cout<<"list kosong"<<endl;
        }
        else
        {
            P=first(L);
            first(L)=next(first(L));
            next(P)=NULL;
        }
    }

void deleteLast(List_relasi &L, address_relasi &P)
    {
        /**
     * Oleh : Fuad Zauqi Nur
     * NIM : 1301164392
     */
        if (first(L) == NULL)
        {
            cout<<"list kosong"<<endl;
        }
        else
        {
            address_relasi q;
            q=first(L);
            while (next(next(q)) != NULL)
            {
                q=next(q);
            }
            P=next(q);
            q=NULL;
        }
    }

void deleteElm(List_relasi &L, address_relasi P) {
    /**
     * Oleh : Andaresta Fauzan
     * NIM : 1301164189
     */
    address_relasi Q, R;
    Q = first(L);
    if (P == Q) {
        deleteFirst(L, Q);
        dealokasi(P);
    } else {
        R = Q;
        Q = next(Q);
        while ((Q != NULL) && (Q != P)) {
            R = Q;
            Q = next(Q);
        }
        next(R) = next(P);
        next(P) = NULL;
        dealokasi(P);
    }
}

void deleteByParent(List_relasi &L, address_parent P) {
    /**
     * Oleh : Andaresta Fauzan
     * NIM : 1301164189
     */
    address_relasi Q, R, D;

    R = NULL;
    Q = first(L);
    while (Q != NULL) {

        if (Q->parent == P) {
            if (R == NULL) {
                first(L) = next(Q);
            } else {
                next(R) = next(Q);
            }
            D = Q;
            Q = next(D);
            next(D) = NULL;
            dealokasi(D);
        } else {
            R = Q;
            Q = next(Q);
        }
    }
}

void deleteByChild(List_relasi &L, address_child P) {
    /**
     * Oleh : Fuad Zauqi Nur
     * NIM : 1301164392
     */
    address_relasi Q, R, D;

    R = NULL;
    Q = first(L);
    while (Q != NULL) {

        if (Q->child == P) {
            if (R == NULL) {
                first(L) = next(Q);
            } else {
                next(R) = next(Q);
            }
            D = Q;
            Q = next(D);
            next(D) = NULL;
            dealokasi(D);
        } else {
            R = Q;
            Q = next(Q);
        }
    }
}
address_relasi findMax(List_relasi &L)
{
    /**
     * Oleh : Fuad Zauqi Nur
     * NIM : 1301164392
     */
    address_relasi P,max;
    P=NULL;
    if (first(L)==NULL)
    {
        return NULL;
    }
    else
    {
        P=first(L);
        max = P;
        if (strcmpi(info(parent(P)).id,info(parent(max)).id) > 0)
        {
            max=P;
        }
        P=max;
    }
    return P;
}

void urutdatarelasi(List_relasi &L) {
    /**
     * Oleh : Fuad Zauqi Nur
     * NIM : 1301164392
     */

    address_relasi P,Q;
    address_parent F;
    address_child B;
    List_relasi R;
    createList(R);
    while (first(L)!=NULL)
    {
        P = findMax(L);
        F = parent(P);
        B = child(P);
        deleteElm(L,P);
        Q = alokasi(F,B);
        insertFirst(R,Q);
    }
    L=R;
}



