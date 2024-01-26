#include <stdio.h>

int nombre;

typedef struct{
	int jour;
	int mois;
	int annee;
}date;

typedef struct{
	char responsable[20];
	char description[30];
	date dateEcheance;
	char priorite[30];
}Tache;

void AfficherMenu();
void ChoixOperation(int nombre);
void AfficherTaches();
void AjouterTache();

int i=0;
Tache tache[100];

void AjouterTache()
{   
	printf("\t Responsable du tache : ");
	scanf(" %[^\n]s",&tache[i].responsable);
   
	printf("\t Description du tache : ");
	scanf(" %[^\n]s",&tache[i].description);

    printf("\t Date d' echeance du tache : ");
	scanf(" %d %d %d",&tache[i].dateEcheance.jour,&tache[i].dateEcheance.mois,&tache[i].dateEcheance.annee);

	printf("\t La priorite du tache : ");
	scanf(" %[^\n]s",&tache[i].priorite);	

	printf("L' ajout est effectue avec succes !!\n\n");
	i++;
	AfficherMenu();
}




void ChoixOperation(int nombre)
{
	switch(nombre){
		case 1:
			AjouterTache();
			break;
		case 2:
	        AfficherTaches(tache);
			break;
        case 3:
	        printf("Modifier");
			break;
        case 4:
		    printf("Supprimer");	
			break;
        case 5:
		    printf("Filtrer");	
			break;
		default:
			printf("CHOIX INVALID !! Ressayer ..\n\n");
		    AfficherMenu();
			break;
	}
}

void AfficherMenu()
{
	printf("Menu de l' application :\n");
	printf("\t1- Ajouter une tache .\n");
	printf("\t2- Afficher la liste des taches .\n");
	printf("\t3- Modifier une tache .\n");
	printf("\t4- Supprimer une tache .\n");
	printf("\t5- Filtrer les taches .\n");
	scanf("%d",&nombre);
	ChoixOperation(nombre);
}



void AfficherTaches(Tache t[]){
	int j=0;
	
	printf("Voila les taches disponible a ce moment la :\n\n");
    for(j=0;j<i;j++){
    	printf("Tache %d :\n",j+1);
        printf("\t Responsable du tache %d : ",j+1);
        printf(" %s\n",t[j].responsable);
        printf("\t Description du tache %d : ",j+1);
        printf(" %s\n",t[j].description);
        printf("\t Date d' echeance du tache %d : ",j+1);
        printf(" %d %d %d\n",t[j].dateEcheance.jour,t[j].dateEcheance.mois,t[j].dateEcheance.annee);
        printf("\tLa priorite du tache %d : ",j+1);
	    printf(" %s\n",t[j].priorite);
	}
	printf("\n\n\n\n");
	AfficherMenu();	
}


int main(){
	
	AfficherMenu();
	return 0;
}
