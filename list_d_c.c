#include<stdio.h>
#include<stdlib.h>

typedef struct  cellule
{
   int val;
   struct  cellule *suiv;
   struct  cellule *prec;
}cellule;
 int main(){
    int n,i,v ,choix;
    cellule *p,*l=NULL;


    printf("\nINSERTION D'UN ELEMENT DANS UNE LISTE SIMPLEMENT CHAINEE TRIEE.\n");
do{
printf("entrer le nombre d'element de notre liste:");
scanf("%d", &n);
if (n <= 0){
    printf("ERREUR: nombre invalide, veuillez reessayer.");
} 
} while (n <= 0);

    printf("\n1. Inserer en tete\n");
    printf("2. Inserer en queue\n");
    printf("0. Quitter\n");
    printf("Votre choix : ");
    scanf("%d", &choix);
    switch(choix){
        case 1:
        for(i = 0; i < n; i++){
        printf("entrez l'element numero %d de notre liste:", i+1);
        scanf("%d", &v);

        p = (cellule*) malloc(sizeof(cellule));
        p->val = v;

        // Liste vide : p pointe sur lui-même
        if(l==NULL){
            p->suiv=p;
            p->prec=p;
            l=p;
        }else{
            p->suiv=l;  //nouvelle pointe sur l'ancienne tête
            p->prec=l->prec;  //nouvelle préc pointe sur l'ancienne dernière
            l->prec->suiv=p;  // ancienne dernière pointe sur la nouvelle
            l->prec=p;  // ancienne tête pointe en arrière sur la nouvelle
            l=p;  // mise à jour de la tête mis ici pour l
        }
        }
        break;

        case 2:
        for(i = 0; i < n; i++){
        printf("entrez l'element numero %d de notre liste:", i+1);
        scanf("%d", &v);

        p = (cellule*) malloc(sizeof(cellule));
        p->val = v;

        // Liste vide : p pointe sur lui-même
        if(l==NULL){
            p->suiv=p;
            p->prec=p;
            l=p;

        }else{
            p->suiv=l; // nouvelle pointe sur la tête
            p->prec=l->prec;  // nouvelle préc pointe sur l'ancienne dernière
            l->prec->suiv=p;  // ancienne dernière pointe sur la nouvelle
            l->prec=p;  // tête pointe en arrière sur la nouvelle
            
        }
        }
        break;
        case 0:
            printf("Fin du programme\n");
            break;
        default:
             printf("Choix invalide\n");

    }
if(l != NULL) {
    p = l;
    printf("Liste apres insertion: ");
    do {
        printf("%d <-> ", p->val);
        p = p->suiv;
    } while(p != l);
    printf("\n");
}

    return 0;
 }