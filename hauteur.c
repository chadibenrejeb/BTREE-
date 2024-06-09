#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Added to use boolean data type

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

int height(Node* A) {
    int Hg, Hd;
    
    if (A == NULL || (A->left == NULL && A->right == NULL))
        return 0;
    
    Hg = 0;
    Hd = 0;
    
    if (A->left != NULL)
        Hg = height(A->left);
    
    if (A->right != NULL)
        Hd = height(A->right);
    
    return 1 + (Hg > Hd ? Hg : Hd);
}

bool isLeaf(Node* A) { 
    if (A != NULL && A->left == NULL && A->right == NULL){
        return true; 
    }
    else{ 
        return false;
    }
}

int nbrFeuilles(Node* A){ 
    if(A == NULL){
        return 0 ;
    }
    else if(isLeaf(A)){ 
        return 1 ;
    }
    else{
        return nbrFeuilles(A->left) + nbrFeuilles(A->right); 
    }
    Node* maximum(Node* A) {
        if (A == NULL) {
            return NULL; 
        }
        while (A->right != NULL) {
            A = A->right;
        }
        return A;
    }
    
}

int main() {
    Node* A = (Node*)malloc(sizeof(Node));
    Node* B = (Node*)malloc(sizeof(Node));
    Node* C = (Node*)malloc(sizeof(Node));
    Node* D = (Node*)malloc(sizeof(Node));
    Node* E = (Node*)malloc(sizeof(Node));
    Node* F = (Node*)malloc(sizeof(Node));

    A->data = 1;
    B->data = 2;
    C->data = 3;
    D->data = 4;
    E->data = 5;
    F->data = 6;

    A->left = B;
    A->right = C;
    B->left = D;
    B->right = NULL;
    C->left = NULL;
    C->right = E;
    D->left = D->right = NULL;
    E->left = F;
    E->right = NULL;
    F->left = F->right = NULL;

    printf("Height of the tree: %d\n", height(A));

    printf("Number of leaves in the tree: %d\n", nbrFeuilles(A));

    free(A);
    free(B);
    free(C);
    free(D);
    free(E);
    free(F);

    return 0;
}
