/*
Nama & NPM   : Muhammad Attila An Naufal - 140810200048
               Rafi Alauddin - 140810200056
Nama Header  : Binary Search Tree
Tanggal Buat : 30 Mei 2021
Deskripsi    : Berisi fungsi2 seputar Binary Search Tree
*/
#include <iostream>
#include <string>

using namespace std;

// 1(start) + 26(Huruf) + 10(Angka) = 37
#define size 37 

// List Huruf & Morse yang akan dibuat node node dalam Tree
char listHuruf[]{'-','E','I','S','H','V','U','F','A','R','L','W','P','J','T','N','D','B','X','K','C','Y','M','G','Z','Q','O','9','8','7','6','5','4','3','2','1','0'};

string listMorse[]{"start",".","..","...","....","...-","..-","..-.",".-",".-.",".-..",".--",".--.",".---","-","-.","-..","-...","-..-",
                    "-.-","-.-.","-.--","--","--.","--..","--.-","---","----.","---..","--...","-....",".....","....-","...--","..---",".----","-----"};



struct Node{
    char Char;
    string Morse;
    Node *dot;
    Node *stripe;
};

using ptr = Node*;
using Tree  = ptr;


void createNode(ptr& New, char Char, string Morse){
    New = new Node;
    New->dot = nullptr;
    New->Char = Char;
    New->Morse = Morse;
    New->stripe = nullptr;
}

void insert(Tree& root,ptr New,int loop){   
    // cout<<"\nMasuk\t"<<New->Morse<<" \t= "<<New->Char; // Buat ngecek data yg diinput udah bener
    if (root == nullptr){
        root = New;
    }else if (New->Morse[loop] == '.'){
        insert(root->dot, New,++loop);
    }else if (New->Morse[loop] == '-'){
        insert(root->stripe,New,++loop);
    }
}

void inOrder(Tree& root){       
    if(root!=nullptr){
        inOrder(root->dot);
        cout<<"\nHuruf :\t"<<root->Char<<"\tMorse :\t"<<root->Morse;
        inOrder(root->stripe);
    }
}

char decode(Tree& root, string morse,int loop){
    if(root != nullptr){
        if(root->Morse == morse ){
            return root->Char;
        }
        if(morse[loop] == '-'){
            return decode(root->stripe,morse,++loop);
        }else {
            return decode(root->dot,morse,++loop);
        }
    }else{
    return '!';
    }  // Print ! apabila huruf tidak terdaftar dalam BST
}

string decodeText(string input,Tree root,int loop){
    string temp,result;
    for(int i = 0;i<input.length();i++){
        if(input[i]!='/'){
            temp+=input[i];
        }
        else{
            result+=decode(root,temp,0);
            temp="";
        }
    }
    result+=decode(root,temp,0);
    return result;
}

void createDataMorse(Tree& root){
    ptr New;
    for(int i = 0 ; i<size; i++){
        createNode(New,listHuruf[i],listMorse[i]);
        insert(root,New,0);
    }
}