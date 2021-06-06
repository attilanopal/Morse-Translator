// Header Files berisi fungsi2 Binary Search Tree

#include <iostream>
#include <string>

using namespace std;

char listHuruf[26]{'E','I','S','H','V','U','F','A','R','L','W','P','J','T','N','D','B','X','K','C','Y','M','G','Z','Q','O'};

string listMorse[26]{".","..","...","....","...-","..-","..-.",".-",".-.",".-..",".--",".--.",".---","-","-.","-..","-...","-..-",
                    "-.-","-.-.","-.--","--","--.","--..","--.-","---"};

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
        cout<<"\nChar : "<<root->Char;
        inOrder(root->stripe);
    }
}

char decode(Tree& root, string morse,int loop){
    if(root != nullptr){
        if(root->Morse == morse ){
            return root->Char;
        }
        if(morse[loop] == '-'){
            // cout<<"[Stripes!]\t";                       // buat debugging
            return decode(root->stripe,morse,++loop);
        }else if (morse[loop] == '.' ) {
            // cout<<"[Dots!]\t";                          // buat debugging
            return decode(root->dot,morse,++loop);
        }
    }else{
    return '0';
    }  // Print 0 apabila huruf tidak terdaftar dalam BST
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

void createData(Tree& root){
    ptr New;
    for(int i = 0 ; i<26; i++){
        createNode(New,listHuruf[i],listMorse[i]);
        insert(root,New,0);
    }
}