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
    Tree dotFirst = nullptr;
    ptr New = nullptr;
    int loop = 1;

    // Nyoba masukin kode morse ke tree
    createNode(New,'E',".");
    insert(dotFirst,New,loop);
    createNode(New,'I',"..");
    insert(dotFirst,New,loop);
    createNode(New,'S',"...");
    insert(dotFirst,New,loop);
    createNode(New,'A',".-");
    insert(dotFirst,New,loop);
    createNode(New,'R',".-.");
    insert(dotFirst,New,loop);
    createNode(New,'U',"..-");
    insert(dotFirst,New,loop);
    

    // Tes insert & decode
    cout<<"\nSearch arti dari kode morse .   : "<<decode(dotFirst,".",loop);      // E
    cout<<"\nSearch arti dari kode morse .-  : "<<decode(dotFirst,".-",loop);     // A
    cout<<"\nSearch arti dari kode morse ..  : "<<decode(dotFirst,"..",loop);     // I
    cout<<"\nSearch arti dari kode morse ... : "<<decode(dotFirst,"...",loop);    // S
    cout<<"\nSearch arti dari kode morse .-. : "<<decode(dotFirst,".-.",loop);    // R
    cout<<"\nTesting U : "<<dotFirst->dot->stripe->Char;  
    cout<<"\nTesting R : "<<dotFirst->stripe->dot->Char;
}
