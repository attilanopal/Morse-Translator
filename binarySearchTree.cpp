// Header berisi binary search tree Npm-Nama
/*
Nama & NPM   : Muhammad Attila An Naufal - 140810200048
               Rafi Alauddin - 1408102000xx
Nama Header  : Binary Search Tree
Tanggal Buat : 30 Mei 2021
Deskripsi    : Berisi fungsi2 seputar Binary Search Tree
*/
#include <iostream>
#include <string>
using namespace std;

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
    cout<<"\nmasuk\t"<<loop<<"\t"<<New->Morse<<"\t"<<New->Char;              
    if (root == nullptr){
        root = New;
    }else if (New->Morse[loop]='.'){
        insert(root->dot, New,++loop);
    }else {
        insert(root->stripe,New,++loop);
    }
}

void inOrder(Tree& root){       
    if(root!=nullptr){
        inOrder(root->dot);
        cout<<"\nChar : "<<root->Char;
        inOrder(root->stripe);
    }
}


char cariKarakter(Tree& root, string morse,int loop){
    if(root != nullptr){
        if(root->Morse == morse ){
            return root->Char;
        }
        if(root->Morse[loop] = '-'){
            return cariKarakter(root->stripe,morse,++loop);
        }else {
            return cariKarakter(root->dot,morse,++loop);
        }
    }
    return '0';  // Print 0 apabila huruf tidak terdaftar dalam BST
}


int main(){
    cout<<"Program Run!";       // Nandai program jalan

    // Inisialisasi Tree
    Tree dotFirst = nullptr;
    ptr New = nullptr;
    int loop = 0;

    // Nyoba masukin kode morse ke tree
    createNode(New,'E',".");
    insert(dotFirst,New,loop);
    createNode(New,'I',"..");
    insert(dotFirst,New,loop);
    createNode(New,'A',".-");
    insert(dotFirst,New,loop);

    cout<<"\nSearch arti dari kode morse .  : "<<cariKarakter(dotFirst,".",loop);
    cout<<"\nSearch arti dari kode morse .. : "<<cariKarakter(dotFirst,"..",loop);
    cout<<"\nSearch arti dari kode morse .- : "<<cariKarakter(dotFirst,".-",loop);
}
