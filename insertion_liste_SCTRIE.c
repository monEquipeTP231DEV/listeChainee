#include <stdio.h>
#include <stdlib.h>

typedef struct cellule {
    int val;
    struct cellule *suiv;
} cellule;

int main() {
    int i, v, n;
    cellule *p, *q, *l = NULL, *nouveau;

    printf("\nCREATION D'UNE LISTE SIMPLEMENT CHAINEE TRIEE.\n");

    // Lecture du nombre d'éléments
    do {
        printf("Entrer le nombre d'elements de la liste: ");
        scanf("%d", &n);
        if (n <= 0) {
            printf("ERREUR: nombre invalide, veuillez reessayer.\n");
        }
    } while (n <= 0);

    // Saisie des éléments et insertion triée directement
    for (i = 0; i < n; i++) {
        printf("Entrez l'element numero %d: ", i + 1);
        scanf("%d", &v);

        // Création du nouveau nœud
        nouveau = (cellule*) malloc(sizeof(cellule));
        nouveau->val = v;
        nouveau->suiv = NULL;

        // Insertion triée
        if (l == NULL || v < l->val) {  
            // Insertion en tête
            nouveau->suiv = l;
            l = nouveau;
        } else {
            // Recherche de la bonne position
            p = l;
            while (p->suiv != NULL && p->suiv->val < v) {
                p = p->suiv;
            }
            nouveau->suiv = p->suiv;
            p->suiv = nouveau;
        }
    }

    // Affichage de la liste triée
    printf("\nListe triee: ");
    p = l;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->suiv;
    }
    printf("\n");

    // Ajout d'un nouvel élément dans la liste triée
    printf("Entrer un nouvel element a ajouter: ");
    scanf("%d", &v);

    nouveau = (cellule*) malloc(sizeof(cellule));
    nouveau->val = v;
    nouveau->suiv = NULL;

    if (l == NULL || v < l->val) {
        nouveau->suiv = l;
        l = nouveau;
    } else {
        p = l;
        while (p->suiv != NULL && p->suiv->val < v) {
            p = p->suiv;
        }
        nouveau->suiv = p->suiv;
        p->suiv = nouveau;
    }

    // Affichage après insertion
    printf("Liste apres ajout: ");
    p = l;
    while (p != NULL) {
        printf("%d ", p->val);
        p = p->suiv;
    }
    printf("\n");

    return 0;
}