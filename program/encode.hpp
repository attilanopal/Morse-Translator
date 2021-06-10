#include "binarySearchTree.hpp"
using namespace std;

void insertChar(Tree& root,ptr New){  // Sama seperti insert morse namun menggunakan aturan yang berbeda
    if (root == nullptr){
        root = New;
    }else if (int(New->Char) < int(root->Char)){
        insertChar(root->dot, New);
    }else {
        insertChar(root->stripe,New);
    }
}

void createDataChar(Tree& root){
    ptr New;
    for(int i = 0 ; i<size; i++){
        createNode(New,listHuruf[i],listMorse[i]);
        insertChar(root,New);
    }
}

string encode(Tree& root, char Huruf){
    if(int(Huruf)>=97 && int(Huruf)<=122){
        Huruf = int(Huruf-32);
    }else if(int(Huruf)>=65 && int(Huruf)<=90 ){
    }else if(int(Huruf)>=48 && int(Huruf)<=57){
    }else{
        return "notChar/Number"; // Me-return 'notChar/Number' sebagai tanda char bukan Huruf Alfabet maupun angka
    }
    if(root != nullptr){
            if(root->Char == Huruf){
                return root->Morse;
            }
            if(int(root->Char) < Huruf){
                return encode(root->stripe,Huruf);
            }else {
                return encode(root->dot,Huruf);
            }
        }
        return "noMorse!";
}

string encodeText(string input,Tree root){
    string result;
    result+=encode(root,input[0]);
    for(int i = 1;i<input.length();i++){
        result+='/';
        result+=encode(root,input[i]);
    }
    
    return result;
}