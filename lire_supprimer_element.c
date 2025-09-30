#include <stdio.h>
#include <stdlib.h>
typedef struct cellule{
int valeur;
struct cellule *suiv;
}cellule;

int main(){
int i,n,v,e;
cellule *p,*l = NULL, *courant;

i = 1;
  
// enregistrement du nombre total d'element de notre liste
do(
printf("entrer le nombre d'element de votre liste:");
scanf("%d", &n);
if (n <= 0) {
printf(" ERREUR:entrer un nombre entier positif");}
}while(n <= 0);

// enregistrement de l'element a supprimer les occurrences de notre liste
printf("entrer le nombre dont on veut supprimer les occurrences");
scanf("%d", &e);
while(i <= n){
printf("entrer l'element a ajouter dans notre liste:");
scanf("%d", &v);
p = (cellule*) malloc(sizeof(cellule));
p->valeur = v;
p->suiv = l;
l = p;
i++;}

// affichage de notre lisste avant suppression
printf("liste avant suppression");
p = l;
while(p != NULL){
printf("%d", &p->valeur);
p = p->suiv;
}

// supprimer les occurrences de l'element e dans notre liste
p = l;
courant = NULL;
while(p != NULL){
if (p->valeur == e){
if (courant == NULL){
l = p->suiv;
} else{
courant->suiv = p->suiv;
} 
cellule *temp =p;
if (courant =NULL){
p = l;
} else {
p = courant->suiv;
}
free(temp);
} else {
courant = p;
p = p->suiv;}}

//affichage de notre liste apres suppression
printf("affichage apres suppression");
p =l;
while(p != NULL){
printf("%d", &p->valeur);
p = p->suiv;
}
return 0; 
}



