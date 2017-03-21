#include "application.h"
#include <iostream>

using namespace std;

void mainmenu(List_parent LP, List_child LC, List_relasi LR)
{
    int inputmenu;
    address_parent P1 = NULL;
    address_child P2 = NULL;
    address_relasi P3 = NULL;
    infotype_parent x;
    infotype_child y;
    do
    {
        cout << "1. insert data parent." <<endl;
        cout << "2. insert data child." <<endl;
        cout << "3. view data parent." <<endl;
        cout << "4. view data child." <<endl;
        cout << "5. search data parent." <<endl;
        cout << "6. search data child." <<endl;
        cout << "7. insert data relasi." <<endl;
        cout << "8. view data relasi." <<endl;
        cout << "9. search data relasi." <<endl;
        cout << "10. delete data relasi." <<endl;
        cout << "11. delete data parent." <<endl;
        cout << "12. delete data child." <<endl;
        cout << "13. urutkan data relasi." <<endl;
        cout << "0. keluar" <<endl;
        cout << "Masukkan pilihan: "<<endl;
        cin >> inputmenu;
        switch (inputmenu)
        {
        case 1:
            cout << "Masukkan id :" << endl;
            cin >> x.id;
            cout << "Masukkan Nama Kota :" <<endl;
            cin >> x.kota;
            cout << "Masukkan Nama Provinsi :" <<endl;
            cin >> x.pvsi;
            cout << "Nama Terminal :" << endl;
            cin >> x.trml;
            cout << "Masukkan Alamat Terminal :" <<endl;
            cin >> x.almt;
            cout << "Masukkan Nomor Telpon Terminal :" <<endl;
            cin >> x.telp;
            if (findElmById(LP, x.id) == NULL)
            {
                P1 = alokasi(x);
                insertFirst(LP, P1);
                sort(LP);
            }
            else
            {
                cout <<"id sudah ada.";
            }

            break;
        case 2:
            cout << "Masukkan id :" << endl;
            cin >> y.id;
            cout << "Masukkan Nama Bus :" <<endl;
            cin >> y.nama;
            cout << "Masukkan Kelas Bus :" <<endl;
            cin >> y.kelas;
            cout << "Masukkan Kota Asal Bus:" << endl;
            cin >> y.kotaasal;
            cout << "No. Plat Bus:" <<endl;
            cin >> y.noplat;
            cout << "Via Tol (Y/N):" <<endl;
            cin >> y.viatol;
            if (findElmById(LC, y.id) == NULL)
            {
                P2 = alokasi(y);
                insertfirst(LC, P2);
                sort(LC);
            }
            else
            {
                cout <<"id sudah ada.";
            }

            break;
        case 3:
            printInfo(LP);
            break;
        case 4:
            printinfo(LC);
            break;
        case 5:
            cout << "Masukkan ID :" <<endl;
            cin >> x.id;
            P1 = findElmById(LP, x.id);
            if (P1 == NULL){
                cout << "ID tidak ditemukan.";
            }
            else {
                print(info(P1));
            }
            break;
        case 6:
            cout << "Masukkan ID :" <<endl;
            cin >> y.id;
            P2 = findElmById(LC, y.id);
            if (P2 == NULL){
                cout << "ID tidak ditemukan.";
            }
            else {
                print(info(P2));
            }
            break;
        case 7:
            cout << "Masukkan ID parent :" <<endl;
            cin >> x.id;
            cout << "Masukkan ID child :" <<endl;
            cin >> y.id;
            P1 = findElmById(LP, x.id);
            P2 = findElmById(LC, y.id);
            if (P1 == NULL){
                cout << "ID Terminal tidak ditermukan." <<endl;
            }
            else if (P2 == NULL){
                cout << "ID Bus tidak ditemukan." <<endl;
            }
            else {
                if (findElm(LR, P1, P2) == NULL){
                    P3 = alokasi(P1, P2);
                    insertLast(LR, P3);
                }
                else{
                    cout << "Relasi sudah ada.";
                }

            }
            break;
        case 8:
            printInfo(LR);
            break;
        case 9:
            cout << "Masukkan ID Tujuan :" <<endl;
            cin >> x.id;
            cout << "Masukkan ID Bus :" <<endl;
            cin >> y.id;
            P1 = findElmById(LP, x.id);
            P2 = findElmById(LC, y.id);
            if (P1 == NULL){
                cout << "ID Terminal tidak ditermukan." <<endl;
            }
            else if (P2 == NULL){
                cout << "ID Bus tidak ditemukan." <<endl;
            }
            else {
                if (findElm(LR, P1, P2) != NULL){
                    print(P3);
                }
                else{
                    cout << "Relasi tidak ada.";
                }
            }
            break;
        case 10:
            cout << "Masukkan ID Tujuan :" <<endl;
            cin >> x.id;
            cout << "Masukkan ID Bus :" <<endl;
            cin >> y.id;
            P1 = findElmById(LP, x.id);
            P2 = findElmById(LC, y.id);
            if (P1 == NULL){
                cout << "ID Terminal tidak ditermukan." <<endl;
            }
            else if (P2 == NULL){
                cout << "ID Bus tidak ditemukan." <<endl;
            }
            else {
                if (findElm(LR, P1, P2) != NULL){
                    deleteElm(LR, P3);
                }
                else{
                    cout << "Relasi tidak ada.";
                }
            }
            break;
        case 11:
            cout << "Masukkan ID parent :" <<endl;
            cin >> x.id;
            P1 = findElmById(LP, x.id);
            if (P1 != NULL){
                deleteByParent(LR, P1);
                deleteElm(LP, P1);
            }
            break;
        case 0:
            break;

        }
    }
    while (inputmenu != 0);

}
