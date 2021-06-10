/*
Nama & NPM   : Muhammad Attila An Naufal - 140810200048
               Rafi Alauddin - 140810200056
Nama Header  : Morse Decipher
Tanggal Buat : 30 Mei 2021
Deskripsi    : Program decrypt morse 
*/
#include "encode.hpp"
using namespace std;



int main(){
    int pilihan;
    Tree morseTree = nullptr;
    Tree charTree = nullptr;
    ptr New = nullptr;
    string inputMorse,hasil,inputString;
    char lagi,loop = 'y';

    
    createDataMorse(morseTree);
    createDataChar(charTree);
    while(loop == 'y' || loop == 'Y'){
        system("cls");
        cout<<"\n===================================================\n"
            <<"SELAMAT DATANG DI PROGRAM PENERJEMAH SANDI MORSE\n"
            <<"\nCreated by : Attila & Rafi\n"
            <<"\n===================================================\n"
            <<"\nTekan 1 Untuk Menerjemahkan Morse ke Huruf\n"
            <<"Tekan 2 Untuk Menerjemahkan Huruf ke Morse\n"
            <<"Tekan 3 Untuk Menampilkan List Huruf & Morse\n"
            <<"Tekan 4 Untuk Menampilkan Menu Bantuan\n"
            <<"\nMasukkan Pilihan : ";cin >> pilihan;

        switch (pilihan){
        case 1:
            system("cls");
            cout<<"[Decrypt Morse]\n"
                <<"*Gunakan '/' sebagai pemisah Morse\n"
                <<"\nMasukkan kata (Morse) : ";cin>>inputMorse;
            hasil = decodeText(inputMorse,morseTree,0);
        
            cout<<"\nApakah ingin menambah kata? (Y/N) : ";cin>>lagi;
            while(lagi == 'y' || lagi == 'Y'){
                hasil+=' ';
                cout<<"\nMasukkan kata (Morse) : ";cin>>inputMorse;
                hasil+=decodeText(inputMorse,morseTree,0);
                cout<<"\nApakah ingin menambah kata? (Y/N)";cin>>lagi;
            }
            cout<<"\nHasil decrypt adalah : "<<hasil;
            break;
        case 2:
            system("cls");
            cout<<"[Encrypt Morse]\n"
                <<"*Hanya gunakan huruf/angka sebagai input!\n"
                <<"\nMasukkan kata (Huruf) : ";cin>>inputString;
            hasil = encodeText(inputString,charTree);
        
            cout<<"\nApakah ingin menambah kata? (Y/N) : ";cin>>lagi;
            while(lagi == 'y' || lagi == 'Y'){
                hasil+=' ';
                cout<<"\nMasukkan kata (Huruf) : ";cin>>inputString;
                hasil+=encodeText(inputString,charTree);
                cout<<"\nApakah ingin menambah kata? (Y/N)";cin>>lagi;
            }
            cout<<"\nHasil encrypt adalah : "<<hasil;
            break;
        case 3:
            system("cls");
            cout<<"[List Huruf & Morse]\n"
                <<"*Huruf '-' Merupakan element pemulai tree sehingga bukan character yang valid\n";
            inOrder(charTree); 
            break;
        case 4:
            system("cls");
            cout<<"[Menu Bantuan]\n"
                <<"\n-Deskripsi Program-\n"
                <<"Program Kode Morse ini merupakan program yang dibuat dalam rangka menyelesaikan\n"
                <<"mata kuliah Struktur Data. Program ini memiliki fungsi untuk mengubah kode morse\n"
                <<"menjadi huruf dan juga sebaliknya. Program ini dibuat dengan mengimplementasikan\n"
                <<"Binary Search Tree sebagai struktur data penyimpanan morse & hurufnya.\n"
                <<"\n-Cara Pakai Program-\n"
                <<"Cara memakai program ini cukup mudah. Pertama, kita memilih apa yang ingin kita\n"
                <<"lakukan (Encode*/Decode*). Kemudian kita akan diarahkan ke menu sesuai pilihan.\n"
                <<"pada menu Decode kita harus menginput kode morse menggunakan dot(.) & stripe(-)\n"
                <<"dan pisahkan antar huruf morse menggunakan '/' . Isilah kode morse per kata dan\n"
                <<"tekan Enter apabila telah selesai menulis satu kata dan akan diberikan pilihan\n"
                <<"apakah ingin menambah kata atau tidak. Bila memilih tidak, maka akan mengoutput\n"
                <<"Hasil dari kalimat yang telah diubah. Begitu pula dengan Encode. Namun kita hanya\n"
                <<"mengisi input perkata (tanpa pemisah apapun)\n";
            break;
        default:
            cout<<"Pilihan Anda tidak tersedia";
            break;
        }

        cout<<"\nIngin kembali ke menu utama? (Y/N) : ";cin>>loop;
    }
    cout<<"\nSelamat Tinggal!";

}
