#include "doublecircular.h"
#include <iostream>

using namespace std;

void mainMenu();
List L;
address P1 = NULL;
address P2 = NULL;
infotype x;
int id;
char id2[3];
char id1[3];

int main()
{
    createList(L);

    mainMenu();

    return 0;
}

void mainMenu()
{
    int inputmenu;
    id = 0;
    do
    {
        cout << "1. insert first" <<endl;
        cout << "2. insert after" <<endl;
        cout << "3. insert last" <<endl;
        cout << "4. delete first" <<endl;
        cout << "5. delete after" <<endl;
        cout << "6. delete last" <<endl;
        cout << "7. view list" <<endl;
        cout << "0. keluar" <<endl;
        cout << "Masukkan pilihan: "<<endl;
        cin >> inputmenu;
        switch (inputmenu)
        {
        case 1:
            cout << "Masukkan ID :" << endl;
            cin >> x.id;
            cout << "Masukkan Nama Kota :" <<endl;
            cin >> x.kota;
            cout << "Masukkan Nama Provinsi :" <<endl;
            cin >> x.pvsi;
            cout << "Masukkan Alamat Terminal :" <<endl;
            cin >> x.trml;
            cout << "Masukkan Nomor Telpon Terminal :" <<endl;
            cin >> x.telp;
            if (findElmById(L, x.id) == NULL)
            {
                P1 = alokasi(x);
                insertFirst(L, P1);
            }
            else
            {
                cout <<"ID sudah ada.";
            }
            break;

        case 2:
            cout << "Masukkan ID :" << endl;
            cin >> x.id;
            cout << "Masukkan Nama Kota :" <<endl;
            cin >> x.kota;
            cout << "Masukkan Nama Provinsi :" <<endl;
            cin >> x.pvsi;
            cout << "Masukkan Alamat Terminal :" <<endl;
            cin >> x.trml;
            cout << "Masukkan Nomor Telpon Terminal :" <<endl;
            cin >> x.telp;
            if (findElmById(L, x.id) == NULL)
            {
                P1 = alokasi(x);
                cout << "Masukkan id elemen sebelumnya:" <<endl;
                cin >> id2;
                P2 = findElmById(L, id2);
                insertAfter(L, P2, P1);
            }
            else
            {
                cout << "ID sudah ada.";
            }
            break;

        case 3:
            cout << "Masukkan ID :" << endl;
            cin >> x.id;
            cout << "Masukkan Nama Kota :" <<endl;
            cin >> x.kota;
            cout << "Masukkan Nama Provinsi :" <<endl;
            cin >> x.pvsi;
            cout << "Masukkan Alamat Terminal :" <<endl;
            cin >> x.trml;
            cout << "Masukkan Nomor Telpon Terminal :" <<endl;
            cin >> x.telp;
            if (findElmById(L, x.id) == NULL)
            {
                P1 = alokasi(x);
                insertLast(L, P1);
            }
            else
            {
                cout <<"ID sudah ada.";
            }
            break;

        case 4:
            deleteFirst(L, P1);
            break;

        case 5:
            cout << "Masukkan id yg ingin dihapus:" << endl;
            cin >> id1 ;
            cout << "Hapus id sebelumnya :" << endl;
            cin >> id2;
            P1 = findElmById(L, id1);
            P2 = findElmById(L, id2);
            deleteAfter(L, P2, P1);
            break;

        case 6:
            deleteLast(L, P1);
            break;

        case 7:
            printInfo(L);
            break;

        case 0:
            break;
        }
    }
    while (inputmenu != 0);

}
