#include <stdio.h>
#include <stdlib.h>

struct cellule {
    int data;
    struct cellule *suiv;
};

int main() {
    struct cellule *p = NULL, *l, *temp;
    int choix, valeur;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Inserer en tete\n");
        printf("2. Inserer en queue\n");
        printf("3. Afficher la liste\n");
        printf("0. Quitter\n");
        printf("Votre choix : ");
        scanf("%d", &choix);

        if (choix == 1) {
            printf("Entrez la valeur a inserer en tete : ");
            scanf("%d", &valeur);

            l = (struct cellule*)malloc(sizeof(struct cellule));
            l->data = valeur;

            if (p == NULL) {
                l->suiv = l;
                p = l;
            } else {
                l->suiv = p->suiv;
                p->suiv = l;
            }

        } else if (choix == 2) {
            printf("Entrez la valeur a inserer en queue : ");
            scanf("%d", &valeur);

            l = (struct cellule*)malloc(sizeof(struct cellule));
            l->data = valeur;

            if (p == NULL) {
                l->suiv = l;
                p = l;
            } else {
                l->suiv = p->suiv;
                p->suiv = l;
                p = l;
            }

        } else if (choix == 3) {
            if (p == NULL) {
                printf("La liste est vide.\n");
            } else {
                printf("Liste : ");
                temp = p->suiv;
                do {
                    printf("%d -> ", temp->data);
                    temp = temp->suiv;
                } while (temp != p->suiv);
                printf("(retour au debut)\n");
            }
        }

    } while (choix != 0);

    return 0;
}