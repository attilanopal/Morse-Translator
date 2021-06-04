// Header Files berisi fungsi2 Binary Search Tree

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
            // cout<<"[Stripes!]\t";                       // Buat nyari bug
            return decode(root->stripe,morse,++loop);
        }else if (morse[loop] == '.' ) {
            // cout<<"[Dots!]\t";                          // Buat nyari bug
            return decode(root->dot,morse,++loop);
        }
    }
    return '0';  // Print 0 apabila huruf tidak terdaftar dalam BST
}