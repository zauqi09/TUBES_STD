#include "application.h"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

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
        system("cls");
        cout << "PENDATAAN BUS DAN KOTA TUJUAN" <<endl;
        cout << "Tugas Besar Struktur Data" <<endl;
        cout << "Oleh : Andaresta Fauzan & Fuad Zauqi Nur" <<endl;
        cout << "" <<endl;
        cout << "ket : parent = kota, child = bus" <<endl;
        cout << "1. insert data parent. " <<endl;
        cout << "2. insert data child. " <<endl;
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
        cout << "13. urutkan data relasi.(disabled)" <<endl;
        cout << "0. keluar" <<endl;
        cout << "Masukkan pilihan: "<<endl;
        cin >> inputmenu;
        switch (inputmenu)
        {
        case 1:
            system("cls");
            cout << "Insert data Kota" <<endl;
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
            getch();
            break;
        case 2:
            system("cls");
            cout << "Insert data Bus" <<endl;
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
            getch();
            break;
        case 3:
            cout<<"Data Kota (Parent)"<<endl;
            system("cls");
            printInfo(LP);
            getch();
            break;
        case 4:
            cout<<"Data Bus (Child)"<<endl;
            system("cls");
            printinfo(LC);
            getch();
            break;
        case 5:
            system("cls");
            cout<<"Search Data Kota (Parent)"<<endl;
            cout << "Masukkan ID :" <<endl;
            cin >> x.id;
            P1 = findElmById(LP, x.id);
            if (P1 == NULL){
                cout << "ID tidak ditemukan.";
            }
            else {
                print(info(P1));
            }
            getch();
            break;
        case 6:
            system("cls");
            cout<<"Search Data Bus (Child)"<<endl;
            cout << "Masukkan ID :" <<endl;
            cin >> y.id;
            P2 = findElmById(LC, y.id);
            if (P2 == NULL){
                cout << "ID tidak ditemukan.";
            }
            else {
                print(info(P2));
            }
            getch();
            break;
        case 7:
            system("cls");
            cout<<"Insert Data Relasi"<<endl;
            cout << "Masukkan ID Kota :" <<endl;
            cin >> x.id;
            cout << "Masukkan ID Bus :" <<endl;
            cin >> y.id;
            P1 = findElmById(LP, x.id);
            P2 = findElmById(LC, y.id);
            if (P1 == NULL){
                cout << "ID Kota tidak ditermukan." <<endl;
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
            getch();
            break;
        case 8:
            cout<<"Data Relasi"<<endl;
            system("cls");
            printInfo(LR);
            getch();
            break;
        case 9:
            system("cls");
            cout<<"Search Data Relasi"<<endl;
            cout << "Masukkan ID Kota :" <<endl;
            cin >> x.id;
            cout << "Masukkan ID Bus :" <<endl;
            cin >> y.id;
            P1 = findElmById(LP, x.id);
            P2 = findElmById(LC, y.id);
            P3 = findElm(LR, P1, P2);
            if (P1 == NULL){
                cout << "ID Kota tidak ditermukan." <<endl;
            }
            else if (P2 == NULL){
                cout << "ID Bus tidak ditemukan." <<endl;
            }
            else {
                if (P3!= NULL){
                    print(P3);
                }
                else{
                    cout << "Relasi tidak ada.";
                }
            }
            getch();
            break;
        case 10:
            system("cls");
            cout<<"Delete Data Relasi"<<endl;
            cout << "Masukkan ID Kota :" <<endl;
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
            getch();
            break;
        case 11:
            system("cls");
            cout<<"Delete Data Kota (Parent)"<<endl;
            cout << "Masukkan ID parent :" <<endl;
            cin >> x.id;
            P1 = findElmById(LP, x.id);
            if (P1 != NULL){
                deleteByParent(LR, P1);
                deleteElm(LP, P1);
            }
            getch();
            break;
        case 12:
            system("cls");
            cout<<"Delete Data Bus (Child)"<<endl;
            cout << "Masukkan ID child :" <<endl;
            cin >> x.id;
            P2 = findElmById(LC, x.id);
            if (P2 != NULL){
                deleteByChild(LR, P2);
                deleteElm(LC, P2);
            }
            getch();
            break;
        case 13:
            system("cls");
            cout<<"Disabled"<<endl;
            //sort(LP);
            //urutdatarelasi(LR);
            //printInfo(LS);
            getch();
        case 0:
            break;

        }
    }
    while (inputmenu != 0);

}
