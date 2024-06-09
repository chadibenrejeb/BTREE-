#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // Include for boolean type

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* createNode(int valeur) {
    node* N;
    N = (node*)malloc(sizeof(node));
    N->data = valeur; 
    N->left = N->right = NULL; 
    return N;
}

void insertNewNode(node** racine, int val) {
    node* N, *temp;
    N = createNode(val); 
    if (*racine == NULL) { 
        *racine = N; 
        return;
    }
    temp = *racine;
    while (1) {
        if (N->data > temp->data) { 
            if (temp->right == NULL) { 
                temp->right = N; 
                break;
            } else {
                temp = temp->right; 
            }
        } else { 
            if (temp->left == NULL) { 
                temp->left = N; 
                break; 
            } else {
                temp = temp->left; 
            }
        }
    }
} 

void preOrder(node* racine) {
    if(racine == NULL) {
        return;
    }
    printf("%d ", racine->data);
    preOrder(racine->left);
    preOrder(racine->right);
}

node* minimum(node* racine) {
    if (racine == NULL) {
        return NULL;
    }
    while (racine->left != NULL) {
        racine = racine->left;
    }
    return racine;
}

node* maximum(node* racine) {
    if (racine == NULL) {
        return NULL;
    }
    while (racine->right != NULL) {
        racine = racine->right;
    }
    return racine;
}

node* Recherche(node* racine, int x) {
    if (racine == NULL) {
        return NULL;
    } 
    node* temp = racine; // Initialize temp with racine
    bool found = false; // Initialize found flag
    while (temp != NULL) {
        if (x == temp->data) {
            found = true;
            break;
        } else if (x > temp->data) {
            temp = temp->right;
        } else {
            temp = temp->left;
        }
    }
    if (found) {
        return temp;
    } else {
        return NULL;
    }
}

node* deleteNode(node* racine, int v) {
    if (racine == NULL) {
        return racine;
    }
    if (v == racine->data) {
        if (racine->left == NULL && racine->right == NULL) {
            free(racine);
            racine = NULL;
        } else if (racine->left == NULL) {
            node* temp = racine;
            racine = racine->right;
            free(temp);
        } else if (racine->right == NULL) {
            node* temp = racine;
            racine = racine->left;
            free(temp);
        } else {
            node* temp = minimum(racine->right);
            racine->data = temp->data;
            racine->right = deleteNode(racine->right, temp->data);
        }
    } else if (v < racine->data) {
        racine->left = deleteNode(racine->left, v);
    } else {
        racine->right = deleteNode(racine->right, v);
    }
    return racine;
}

int main() {
    node *arbre = NULL; 
    insertNewNode(&arbre, 70);
    insertNewNode(&arbre, 77);
    insertNewNode(&arbre, 75);
    insertNewNode(&arbre, 60);
    insertNewNode(&arbre, 45);
    insertNewNode(&arbre, 30);
    insertNewNode(&arbre, 81);
    insertNewNode(&arbre, 64);
    insertNewNode(&arbre, 52);
    insertNewNode(&arbre, 62);
    
    printf("Preorder traversal: ");
    preOrder(arbre);
    printf("\n");
    
    node *min_node = minimum(arbre);
    if (min_node != NULL) {
        printf("Minimum value in the tree: %d\n", min_node->data);
    } else {
        printf("The tree is empty!\n");
    }

    node *max_node = maximum(arbre);
    if (max_node != NULL) {
        printf("Maximum value in the tree: %d\n", max_node->data);
    } else {
        printf("The tree is empty!\n");
    }

    node *searched_node = Recherche(arbre, 77);
    if (searched_node != NULL) {
        printf("Found value: %d\n", searched_node->data);
    } else {
        printf("Value not found!\n");
    }
    
    // Delete a node (example)
    arbre = deleteNode(arbre, 75);
    printf("Preorder traversal after deleting 75: ");
    preOrder(arbre);
    printf("\n");

    return 0;
}
