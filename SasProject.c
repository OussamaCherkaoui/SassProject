#include <stdio.h>
#include <string.h>
#include <stdbool.h>



typedef struct{
	int jour;
	int mois;
	int annee;
}date;

typedef struct{
	int  idTache ;
	char responsable[20];
	char description[30];
	date dateEcheance;
	char priorite[30];
}Tache;

void AfficherMenu();
void ChoixOperation(int nombre);
void AfficherTaches();
void AjouterTache();
void SupprimerTache();
void ModifierTache();



int i=0,nombre;
Tache tache[100];




void AjouterTache()
{   
    tache[i].idTache=tache[i-1].idTache+1;
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

void SupprimerTache(){
	
	int nbrtache,j;
	bool istach = false ;
	
	printf("Quelle tache voulez-vous supprimer ?\n");
	scanf("%d",&nbrtache);
	
	while(nbrtache<0)
	{
		printf("Tache introuvable !! \n\n\n");
		AfficherMenu();
	}
	
	for(j=0;j<i;j++)
	{
		    if(tache[j].idTache==nbrtache)
		    {
			    istach=true;
		    }
		    if(istach==true)
		    {
			    tache[j].idTache=tache[j+1].idTache;
		        strcpy(tache[j].responsable,tache[j+1].responsable);
		        strcpy(tache[j].description,tache[j+1].description);
		        tache[j].dateEcheance.jour=tache[j+1].dateEcheance.jour;
		        tache[j].dateEcheance.mois=tache[j+1].dateEcheance.mois;
		        tache[j].dateEcheance.annee=tache[j+1].dateEcheance.annee;
		        strcpy(tache[j].priorite,tache[j+1].priorite);
		   }	
	}
	if(istach==false)
	{
		printf("Tache introuvable !! Ressayer..\n\n\n");
		SupprimerTache();
	}
	printf("La suppression est effectue avec succes !!\n\n");
	i--;
	AfficherMenu();
}

void ModifierTache(){
	int nbrtache,j,info;
	bool istach = false ;
	printf("Quelle Tache Voulez-vous Modifier ?\n");
	scanf("%d",&nbrtache);
	
	while(nbrtache<0)
	{
		printf("Tache introuvable !! \n\n\n");
		AfficherMenu();
	}
	
	for(j=0;j<i;j++)
	{
		    if(tache[j].idTache==nbrtache)
		    {
		    	istach=true;
		    	printf("Quelle information voulez-vous modifier ?\n");
		    	printf("\t1- Responsable .\n");
             	printf("\t2- Description .\n");
	            printf("\t3- Date d echeance .\n");
	            printf("\t4- Priorite .\n");
				scanf("%d",&info);
			    
				printf("Tache %d :",tache[j].idTache);
			    switch(info)
			    {
			    	case 1:
			    		printf("\t Responsable du tache : ");
              	        scanf(" %[^\n]s",&tache[j].responsable);
			    		break;
			    	case 2:
			    		printf("\t Description du tache : ");
	                    scanf(" %[^\n]s",&tache[j].description);
			    		break;
			    	case 3:
			    		printf("\t Date d' echeance du tache : ");
	                    scanf(" %d %d %d",&tache[j].dateEcheance.jour,&tache[j].dateEcheance.mois,&tache[j].dateEcheance.annee);
			    		break;
			    	case 4:
			    		printf("\t La priorite du tache : ");
            	        scanf(" %[^\n]s",&tache[j].priorite);
			    		break;
			    	default :
			    		printf("CHOIX INVALID !! Ressayer..\n\n\n");
			    		ModifierTache();
			    		break;
				}
		   }	
	}
	if(istach==false)
	{
		printf("Tache introuvable !! \n\n\n");
		AfficherMenu();
	}
	printf("La Modification est effectue avec succes !!\n\n");
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
	        ModifierTache();
			break;
        case 4:
		    SupprimerTache();	
			break;
		case 5:
		    TrierTaches();
			break;
        case 6:
		    Filtrertache();	
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
	printf("\t5- Trier les taches (Croissant / Decroissant).\n");
	printf("\t6- Filtrer les taches .\n");
	scanf("%d",&nombre);
	ChoixOperation(nombre);
}


void AfficherTaches(Tache t[]){
	
	int j=0;
	
	
	printf("Voila les taches disponible a ce moment la :\n\n");
    for(j=0;j<i;j++){
    	printf("Tache %d :\n",j+1);
    	printf("\t Numero du tache : ");
        printf(" %d\n",t[j].idTache);
        printf("\t Responsable du tache %d : ",t[j].idTache);
        printf(" %s\n",t[j].responsable);
        printf("\t Description du tache %d : ",t[j].idTache);
        printf(" %s\n",t[j].description);
        printf("\t Date d' echeance du tache %d : ",t[j].idTache);
        printf(" %d/%d/%d\n",t[j].dateEcheance.jour,t[j].dateEcheance.mois,t[j].dateEcheance.annee);
        printf("\tLa priorite du tache %d : ",t[j].idTache);
	    printf(" %s\n",t[j].priorite);
	}
	printf("\n\n\n\n");
	AfficherMenu();	
}


int main(){
	
	AfficherMenu();
	return 0;
}
