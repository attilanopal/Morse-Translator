/*
======== Update ===================================================================
04/06/21 => Baikin input & cariKarakter 
         => cariKarakter(); diubah jadi decode();
         => Fungsi2 dipisah di binarySearchTree.h
05/06/21 => Nambahin fungsi decodeText
         => Decode Text udah bisa Tapi belom bisa nambahin spasi per kata
         => Decode text caranya : morse/morse (ex= ..././.-./..- [Arti : seru])
======== List Bug ================================================================
* Isi klo nemu * 


======= To-Do List ===============================================================
-> Isi dataMorse.h 
-> Buat tampilan menu
-> Sistem input & output


==================================================================================
*/

/*
Nama & NPM   : Muhammad Attila An Naufal - 140810200048
               Rafi Alauddin - 140810200056
Nama Header  : Binary Search Tree
Tanggal Buat : 30 Mei 2021
Deskripsi    : Berisi fungsi2 seputar Binary Search Tree
*/
#include <iostream>
#include <string>
#include "binarySearchTree.hpp"
using namespace std;



int main(){
    int pilihan;
    Tree morseTree = nullptr;
    ptr New = nullptr;
    string morse,hasil;
    char lagi;

    createData(morseTree);
    cout<<"\n===================================================\n";
    cout<<"SELAMAT DATANG DI PROGRAM PENERJEMAH SANDI MORSE\n";
    cout<<"\nCreated by : Attila & Rafi\n";
    cout<<"\n===================================================\n";
    cout<<"\nTekan 1 Untuk Menerjemahkan Morse ke Huruf\n";
    cout<<"Tekan 2 Untuk Menerjemahkan Huruf ke Morse\n";
    cout<<"\nMasukkan Pilihan : "; cin >> pilihan;

    switch (pilihan){
    case 1:
        cout<<"*Gunakan '/' sebagai pemisah Morse\n";
        cout<<"\nMasukkan morse : ";cin>>morse;
        hasil = decodeText(morse,morseTree,0);
    
        cout<<"\nApakah ingin menambah kata? (Y/N) : ";cin>>lagi;
        while(lagi == 'y' || lagi == 'Y'){
            hasil+=' ';
            cout<<"\nMasukkan morse : ";cin>>morse;
            hasil+=decodeText(morse,morseTree,0);
            cout<<"\nApakah ingin menambah kata? (Y/N)";cin>>lagi;
        }
        cout<<"\nHasil decrypt adalah : "<<hasil;
        break;

    case 2:
        cout<<"*Gunakan '/' sebagai pemisah huruf\n";
        //masukin codingan reverse nya til

    default:
        break;
    }

}
