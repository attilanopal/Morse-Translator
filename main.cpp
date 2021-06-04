/*
======== Update ===================================================================
04/06/21 => Baikin input & cariKarakter 
         => cariKarakter(); diubah jadi decode();
         => Fungsi2 dipisah di binarySearchTree.h
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
#include "binarySearchTree.h"
#include "dataMorse.h"
using namespace std;



int main(){
    cout<<"Program Run!";       // Nandai program jalan

    // Inisialisasi Tree
    Tree morseTree = nullptr;
    ptr New = nullptr;
    int loop = 0;
    string morse;

    cout<<"\n\n\t\t[Isi Tree]";
    // Nyoba masukin kode morse ke tree
    cout<<"\ni = banyak char dalam morse\n\n[status\ti\tmorse\t\tchar\t]"; 
    createNode(New,'0',"start");
    insert(morseTree,New,loop);
    
    createNode(New,'E',".");
    insert(morseTree,New,loop);
    createNode(New,'T',"-");
    insert(morseTree,New,loop);
    createNode(New,'I',"..");
    insert(morseTree,New,loop);
    createNode(New,'S',"...");
    insert(morseTree,New,loop);
    createNode(New,'A',".-");
    insert(morseTree,New,loop);
    createNode(New,'R',".-.");
    insert(morseTree,New,loop);
    createNode(New,'U',"..-");
    insert(morseTree,New,loop);
    
    cout<<"\n[===================================]"
        <<"\n\n\t[Uji Search]\n";
    // Tes insert & decode
    // Tes Decode
    cout<<"\nSearch arti dari kode morse .   : "<<decode(morseTree,".",loop);      // E 
    cout<<"\nSearch arti dari kode morse .-  : "<<decode(morseTree,".-",loop);     // A
    cout<<"\nSearch arti dari kode morse ..  : "<<decode(morseTree,"..",loop);     // I
    cout<<"\nSearch arti dari kode morse ... : "<<decode(morseTree,"...",loop);    // S
    cout<<"\nSearch arti dari kode morse .-. : "<<decode(morseTree,".-.",loop);    // R
    // Tes Manual
    cout<<"\nTesting U : "<<morseTree->dot->dot->stripe->Char;   // ..- (U)
    cout<<"\nTesting R : "<<morseTree->dot->stripe->dot->Char;  // .-. (R)

    cout<<"\nMasukkan morse : ";cin>>morse;
    cout<<"Hasil : ";cout<<decode(morseTree,morse,loop);   
}
