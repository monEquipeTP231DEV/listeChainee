#include <stdio.h>
#include <stdlib.h>


typedef struct  cellule
{
   int val;
   struct  cellule *suiv;
   struct  cellule *prec;
}cellule;

int main(){
    int i,v,e,n,temp;
    cellule *p,*q,*l = NULL, *prec = NULL;
printf("\nINSERTION D'UN ELEMENT DANS UNE LISTE SIMPLEMENT CHAINEE TRIEE.\n");
do{
printf("entrer le nombre d'element de notre liste:");
scanf("%d", &n);
if (n <= 0){
    printf("ERREUR: nombre invalide, veuillez reessayer.");
} 
} while (n <= 0);

for(i = 0; i < n; i++){
    printf("entrez l'element numero %d de notre liste:", i+1);
    scanf("%d", &v);

    p = (cellule*) malloc(sizeof(cellule));
    p->val = v;
  p->suiv = l;
   if (l != NULL) {  
    l->prec = p;  
}
l=p;
}
         
// affichage avant triage
printf("Liste avant triage: ");
    p = l;
    while(p != NULL) {
    printf("%d ", p->val); 
    p = p->suiv; 
    }
    printf("\n");
    
    p=l;
// ordre croissant mais ca pourrait etre decroissante
while (p != NULL){
    q=p->suiv;
        while(q!=NULL){
            if(p->val > q->val){
                temp=p->val;
                p->val=q->val;
                q->val=temp;
            }
            q=q->suiv;
        }
        p=p->suiv;
} 

//liste apres triage
printf("Liste apres triage: ");
    p = l;
    while(p != NULL) { 
        printf("%d ", p->val);
        p = p->suiv; 
    }
    printf("\n");


// ajout de l'element dans la liste

printf("entrer l'element a ajouter dans la liste:");
scanf("%d", &v);
cellule *nouv=(cellule*) malloc(sizeof(cellule));
nouv->val=v;
p =l;  //  on fait pointer p a la tete de la liste
    nouv->suiv = NULL; // au debut on considere que il y'a rien avant et apres q
     nouv->prec = NULL;

     while(p != NULL && p->val < v) {
         prec = p; // prec pointe vers p
         p = p->suiv;  // p pointe vers son element suivant
     }

     if(prec == NULL) {  //lorsque l'element precedent n'existe pas encore

         // insertion en tete
         nouv->suiv = l;  // l'element suivant q c'est la list
         if(l != NULL) 
            l->prec = nouv; // l'element precedent la liste c'est q
            l = nouv;  // et on fait en sorte que q deviennent le debut de la liste ou la tete
     }else{
        // insertion entre prec et p ( au milieu ou a la fin)

         nouv->suiv =p;  //l'elemnt suivant q c'est la liste et qui est parcouru par p
         nouv->prec = prec;  
         prec->suiv = nouv;  // l'element suiv l'element prec est p donc p

         if (p != NULL){
            p->prec = nouv;
         }
        }
    
    //liste apres ajout
p = l;
printf("Liste apres ajout: ");
    while(p != NULL) { 
        printf("%d ", p->val);
        p = p->suiv; 
    }
    printf("\n");

    return 0;
}

