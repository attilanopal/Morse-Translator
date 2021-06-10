/*
Nama & NPM   : Muhammad Attila An Naufal - 140810200048
               Rafi Alauddin - 140810200056
Nama Header  : Morse Decipher
Tanggal Buat : 30 Mei 2021
Deskripsi    : Program decrypt morse 
*/
#include <iostream>
#include <string>
#include "binarySearchTree.hpp" 
using namespace std;



int main(){
    Tree morseTree = nullptr;
    ptr New = nullptr;
    string morse,hasil;
    char lagi;
    
    createData(morseTree);

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
}
