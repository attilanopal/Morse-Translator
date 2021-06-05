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
    cout<<"Program Run!";       // Nandai program jalan

    // Inisialisasi Tree
    Tree morseTree = nullptr;
    ptr New = nullptr;
    string morse,hasil;

    cout<<"\n\n\t\t[Isi Tree]";
    // Nyoba masukin kode morse ke tree
    cout<<"\ni = banyak char dalam morse\n\n[status\ti\tmorse\t\tchar\t]"; 
    createNode(New,'0',"start");
    insert(morseTree,New,0);

    createData(morseTree);
    
    cout<<"\n[=======================================]"
        <<"\n\n\t[Uji Search]\n";
    // Tes insert & decode
    // Tes Decode
    cout<<"\nSearch arti dari kode morse .   : "<<decode(morseTree,".",0);      // E 
    cout<<"\nSearch arti dari kode morse .-  : "<<decode(morseTree,".-",0);     // A
    cout<<"\nSearch arti dari kode morse ..  : "<<decode(morseTree,"..",0);     // I
    cout<<"\nSearch arti dari kode morse ... : "<<decode(morseTree,"...",0);    // S
    cout<<"\nSearch arti dari kode morse .-. : "<<decode(morseTree,".-.",0);    // R
    // Tes Manual
    cout<<"\nTesting U : "<<morseTree->dot->dot->stripe->Char;   // ..- (U)
    cout<<"\nTesting R : "<<morseTree->dot->stripe->dot->Char;  // .-. (R)

    cout<<"\nMasukkan morse : ";cin>>morse;
    hasil = decodeText(morse,morseTree,0);
    char lagi;
    cout<<"\nApakah ingin menambah kata? (Y/N)";cin>>lagi;
    while(lagi == 'y' || lagi == 'Y'){
        hasil+=' ';
        cout<<"\nMasukkan morse : ";cin>>morse;
        hasil+=decodeText(morse,morseTree,0);
        cout<<"\nApakah ingin menambah kata? (Y/N)";cin>>lagi;
    }
    cout<<"\nHasil decrypt adalah : "<<hasil;
}
