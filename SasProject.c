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
void TrierTaches();
void OrdreCroissant();
void OrdreDecroissant();
void Filtrertache();
void Filtreid();
void FiltreResponsable();
void FiltreDescription();
void FiltreDateEcheance();
void FiltrePriorite();



int i=0,nombre;
Tache tache[100];



void AjouterTache()
{   
    tache[i].idTache=tache[i-1].idTache+1;
	printf("\n\tResponsable du tache : ");
	scanf(" %[^\n]s",&tache[i].responsable);
   
	printf("\tDescription du tache : ");
	scanf(" %[^\n]s",&tache[i].description);

    printf("\tDate d echeance du tache : \n");
	printf("\t\tAnnee : ");
	scanf("%d",&tache[i].dateEcheance.annee);
	printf("\t\tMois : ");
	scanf("%d",&tache[i].dateEcheance.mois);
	printf("\t\tJour : ");
	scanf("%d",&tache[i].dateEcheance.jour);

	printf("\tLa priorite du tache : ");
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
		printf("Tache introuvable !! \n\n\n");
		AfficherMenu();	
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
			    		printf("\tResponsable du tache : ");
              	        scanf(" %[^\n]s",&tache[j].responsable);
			    		break;
			    	case 2:
			    		printf("\tDescription du tache : ");
	                    scanf(" %[^\n]s",&tache[j].description);
			    		break;
			    	case 3:
			    		printf("\tDate d' echeance du tache : \n");
	                    printf("\t\t\tAnnee : ");
	                    scanf("%d",&tache[j].dateEcheance.annee);
	                    printf("\t\t\tMois : ");
	                    scanf("%d",&tache[j].dateEcheance.mois);
	                    printf("\t\t\tJour : ");
	                    scanf("%d",&tache[j].dateEcheance.jour);
			    		break;
			    	case 4:
			    		printf("\tLa priorite du tache : ");
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

void TrierTaches(){
	int ordre;
	printf("\nDe Quelle ordre voulez- vous trier les taches ?\n");
	
	printf("\t1- Croissant .\n");
    printf("\t2- Decroissant .\n");
    
	scanf("%d",&ordre);
    
	switch(ordre)
	{
		case 1 :
			OrdreCroissant();
			break;
		case 2 :
			OrdreDecroissant();
			break;
		default :
			printf("CHOIX INVALID !! Ressayer..\n\n");
    		AfficherMenu();	
	   		break;
	}
}
	
void OrdreCroissant(){
	int j,k;
	for(j=0;j<i;j++)
	{
		for(k=j+1;k<i;k++)
		{
			Tache temp[1];
			if(tache[j].dateEcheance.annee>tache[k].dateEcheance.annee)
			{
				temp[0].idTache=tache[j].idTache;
		        strcpy(temp[0].responsable,tache[j].responsable);
		        strcpy(temp[0].description,tache[j].description);
		        temp[0].dateEcheance.jour=tache[j].dateEcheance.jour;
		        temp[0].dateEcheance.mois=tache[j].dateEcheance.mois;
		        temp[0].dateEcheance.annee=tache[j].dateEcheance.annee;
		        strcpy(temp[0].priorite,tache[j].priorite);
				
				
				tache[j].idTache=tache[k].idTache;
		        strcpy(tache[j].responsable,tache[k].responsable);
		        strcpy(tache[j].description,tache[k].description);
		        tache[j].dateEcheance.jour=tache[k].dateEcheance.jour;
		        tache[j].dateEcheance.mois=tache[k].dateEcheance.mois;
		        tache[j].dateEcheance.annee=tache[k].dateEcheance.annee;
		        strcpy(tache[j].priorite,tache[k].priorite);
		        
		        tache[k].idTache=temp[0].idTache;
		        strcpy(tache[k].responsable,temp[0].responsable);
		        strcpy(tache[k].description,temp[0].description);
		        tache[k].dateEcheance.jour=temp[0].dateEcheance.jour;
		        tache[k].dateEcheance.mois=temp[0].dateEcheance.mois;
		        tache[k].dateEcheance.annee=temp[0].dateEcheance.annee;
		        strcpy(tache[k].priorite,temp[0].priorite);
			}
			else if(tache[j].dateEcheance.annee==tache[k].dateEcheance.annee&&tache[j].dateEcheance.mois>tache[k].dateEcheance.mois)
			{
				temp[0].idTache=tache[j].idTache;
		        strcpy(temp[0].responsable,tache[j].responsable);
		        strcpy(temp[0].description,tache[j].description);
		        temp[0].dateEcheance.jour=tache[j].dateEcheance.jour;
		        temp[0].dateEcheance.mois=tache[j].dateEcheance.mois;
		        temp[0].dateEcheance.annee=tache[j].dateEcheance.annee;
		        strcpy(temp[0].priorite,tache[j].priorite);
				
				
				tache[j].idTache=tache[k].idTache;
		        strcpy(tache[j].responsable,tache[k].responsable);
		        strcpy(tache[j].description,tache[k].description);
		        tache[j].dateEcheance.jour=tache[k].dateEcheance.jour;
		        tache[j].dateEcheance.mois=tache[k].dateEcheance.mois;
		        tache[j].dateEcheance.annee=tache[k].dateEcheance.annee;
		        strcpy(tache[j].priorite,tache[k].priorite);
		        
		        tache[k].idTache=temp[0].idTache;
		        strcpy(tache[k].responsable,temp[0].responsable);
		        strcpy(tache[k].description,temp[0].description);
		        tache[k].dateEcheance.jour=temp[0].dateEcheance.jour;
		        tache[k].dateEcheance.mois=temp[0].dateEcheance.mois;
		        tache[k].dateEcheance.annee=temp[0].dateEcheance.annee;
		        strcpy(tache[k].priorite,temp[0].priorite);
			}
			else if(tache[j].dateEcheance.annee==tache[k].dateEcheance.annee&&tache[j].dateEcheance.mois==tache[k].dateEcheance.mois&&tache[j].dateEcheance.jour>tache[k].dateEcheance.jour)
			{
				temp[0].idTache=tache[j].idTache;
		        strcpy(temp[0].responsable,tache[j].responsable);
		        strcpy(temp[0].description,tache[j].description);
		        temp[0].dateEcheance.jour=tache[j].dateEcheance.jour;
		        temp[0].dateEcheance.mois=tache[j].dateEcheance.mois;
		        temp[0].dateEcheance.annee=tache[j].dateEcheance.annee;
		        strcpy(temp[0].priorite,tache[j].priorite);
				
				
				tache[j].idTache=tache[k].idTache;
		        strcpy(tache[j].responsable,tache[k].responsable);
		        strcpy(tache[j].description,tache[k].description);
		        tache[j].dateEcheance.jour=tache[k].dateEcheance.jour;
		        tache[j].dateEcheance.mois=tache[k].dateEcheance.mois;
		        tache[j].dateEcheance.annee=tache[k].dateEcheance.annee;
		        strcpy(tache[j].priorite,tache[k].priorite);
		        
		        tache[k].idTache=temp[0].idTache;
		        strcpy(tache[k].responsable,temp[0].responsable);
		        strcpy(tache[k].description,temp[0].description);
		        tache[k].dateEcheance.jour=temp[0].dateEcheance.jour;
		        tache[k].dateEcheance.mois=temp[0].dateEcheance.mois;
		        tache[k].dateEcheance.annee=temp[0].dateEcheance.annee;
		        strcpy(tache[k].priorite,temp[0].priorite);
			}
		}
	}
	AfficherTaches(tache);
	    
}

void OrdreDecroissant(){
	int j,k;
	for(j=0;j<i;j++)
	{
		for(k=j+1;k<i;k++)
		{
			Tache temp[1];
			if(tache[j].dateEcheance.annee<tache[k].dateEcheance.annee)
			{
				temp[0].idTache=tache[j].idTache;
		        strcpy(temp[0].responsable,tache[j].responsable);
		        strcpy(temp[0].description,tache[j].description);
		        temp[0].dateEcheance.jour=tache[j].dateEcheance.jour;
		        temp[0].dateEcheance.mois=tache[j].dateEcheance.mois;
		        temp[0].dateEcheance.annee=tache[j].dateEcheance.annee;
		        strcpy(temp[0].priorite,tache[j].priorite);
				
				
				tache[j].idTache=tache[k].idTache;
		        strcpy(tache[j].responsable,tache[k].responsable);
		        strcpy(tache[j].description,tache[k].description);
		        tache[j].dateEcheance.jour=tache[k].dateEcheance.jour;
		        tache[j].dateEcheance.mois=tache[k].dateEcheance.mois;
		        tache[j].dateEcheance.annee=tache[k].dateEcheance.annee;
		        strcpy(tache[j].priorite,tache[k].priorite);
		        
		        tache[k].idTache=temp[0].idTache;
		        strcpy(tache[k].responsable,temp[0].responsable);
		        strcpy(tache[k].description,temp[0].description);
		        tache[k].dateEcheance.jour=temp[0].dateEcheance.jour;
		        tache[k].dateEcheance.mois=temp[0].dateEcheance.mois;
		        tache[k].dateEcheance.annee=temp[0].dateEcheance.annee;
		        strcpy(tache[k].priorite,temp[0].priorite);
			}
			else if(tache[j].dateEcheance.annee==tache[k].dateEcheance.annee&&tache[j].dateEcheance.mois<tache[k].dateEcheance.mois)
			{
				temp[0].idTache=tache[j].idTache;
		        strcpy(temp[0].responsable,tache[j].responsable);
		        strcpy(temp[0].description,tache[j].description);
		        temp[0].dateEcheance.jour=tache[j].dateEcheance.jour;
		        temp[0].dateEcheance.mois=tache[j].dateEcheance.mois;
		        temp[0].dateEcheance.annee=tache[j].dateEcheance.annee;
		        strcpy(temp[0].priorite,tache[j].priorite);
				
				
				tache[j].idTache=tache[k].idTache;
		        strcpy(tache[j].responsable,tache[k].responsable);
		        strcpy(tache[j].description,tache[k].description);
		        tache[j].dateEcheance.jour=tache[k].dateEcheance.jour;
		        tache[j].dateEcheance.mois=tache[k].dateEcheance.mois;
		        tache[j].dateEcheance.annee=tache[k].dateEcheance.annee;
		        strcpy(tache[j].priorite,tache[k].priorite);
		        
		        tache[k].idTache=temp[0].idTache;
		        strcpy(tache[k].responsable,temp[0].responsable);
		        strcpy(tache[k].description,temp[0].description);
		        tache[k].dateEcheance.jour=temp[0].dateEcheance.jour;
		        tache[k].dateEcheance.mois=temp[0].dateEcheance.mois;
		        tache[k].dateEcheance.annee=temp[0].dateEcheance.annee;
		        strcpy(tache[k].priorite,temp[0].priorite);
			}
			else if(tache[j].dateEcheance.annee==tache[k].dateEcheance.annee&&tache[j].dateEcheance.mois==tache[k].dateEcheance.mois&&tache[j].dateEcheance.jour<tache[k].dateEcheance.jour)
			{
				temp[0].idTache=tache[j].idTache;
		        strcpy(temp[0].responsable,tache[j].responsable);
		        strcpy(temp[0].description,tache[j].description);
		        temp[0].dateEcheance.jour=tache[j].dateEcheance.jour;
		        temp[0].dateEcheance.mois=tache[j].dateEcheance.mois;
		        temp[0].dateEcheance.annee=tache[j].dateEcheance.annee;
		        strcpy(temp[0].priorite,tache[j].priorite);
				
				
				tache[j].idTache=tache[k].idTache;
		        strcpy(tache[j].responsable,tache[k].responsable);
		        strcpy(tache[j].description,tache[k].description);
		        tache[j].dateEcheance.jour=tache[k].dateEcheance.jour;
		        tache[j].dateEcheance.mois=tache[k].dateEcheance.mois;
		        tache[j].dateEcheance.annee=tache[k].dateEcheance.annee;
		        strcpy(tache[j].priorite,tache[k].priorite);
		        
		        tache[k].idTache=temp[0].idTache;
		        strcpy(tache[k].responsable,temp[0].responsable);
		        strcpy(tache[k].description,temp[0].description);
		        tache[k].dateEcheance.jour=temp[0].dateEcheance.jour;
		        tache[k].dateEcheance.mois=temp[0].dateEcheance.mois;
		        tache[k].dateEcheance.annee=temp[0].dateEcheance.annee;
		        strcpy(tache[k].priorite,temp[0].priorite);
			}
		}
	}
	AfficherTaches(tache);
}

void Filtrertache(){
	int filtre;
	printf("\nFiltrer Par :\n");
	printf("\t1- Numero .\n");
	printf("\t2- Responsable .\n");
	printf("\t3- Date d echeance .\n");
	printf("\t4- Priorite .\n");
	printf("\t5- Retourner au menu .\n");
    scanf("%d",&filtre);
	switch(filtre)
	{
		case 1: 
		    Filtreid();
		    break;
		case 2: 
		    FiltreResponsable();
		    break;
		case 3: 
		    FiltreDateEcheance();
		    break;
		case 4:
			FiltrePriorite();
			break;
		case 5:
			AfficherMenu();
			break;
		default :
			printf("CHOIX INVALID !! Ressayer..\n\n");
    		Filtrertache();
	   		break;
	}
}

void Filtreid(){
	int numtache,j,k=0;
	printf("Numero du tache : ");
	scanf("%d",&numtache);
	Tache Filtrage[i];
	for(j=0;j<i;j++)
	{
		if(tache[j].idTache==numtache)
		{
			Filtrage[k].idTache=tache[j].idTache;
		    strcpy(Filtrage[k].responsable,tache[j].responsable);
		    strcpy(Filtrage[k].description,tache[j].description);
		    Filtrage[k].dateEcheance.jour=tache[j].dateEcheance.jour;
		    Filtrage[k].dateEcheance.mois=tache[j].dateEcheance.mois;
		    Filtrage[k].dateEcheance.annee=tache[j].dateEcheance.annee;
		    strcpy(Filtrage[k].priorite,tache[j].priorite);
		    k++;
		}
	}
	if(k==0)
	{
		printf("Tache introuvable !! Ressayer.. \n\n\n");
		Filtrertache();
	}
	for(j=0;j<k;j++){
    	printf("Tache %d :\n",j+1);
    	printf("\t\tNumero du tache : ");
        printf(" %d\n",Filtrage[j].idTache);
        printf("\t\tResponsable du tache %d : ",Filtrage[j].idTache);
        printf(" %s\n",Filtrage[j].responsable);
        printf("\t\tDescription du tache %d : ",Filtrage[j].idTache);
        printf(" %s\n",Filtrage[j].description);
        printf("\t\tDate d' echeance du tache %d : ",Filtrage[j].idTache);
        printf(" %d/%d/%d\n",Filtrage[j].dateEcheance.jour,Filtrage[j].dateEcheance.mois,Filtrage[j].dateEcheance.annee);
        printf("\t\tLa priorite du tache %d : ",Filtrage[j].idTache);
	    printf(" %s\n",Filtrage[j].priorite);
	}
	printf("\n\n\n\n");
	AfficherMenu();	
}

void FiltreResponsable(){
	int j,k=0;
	char restache[30];
	printf("Responsable du tache : ");
	scanf(" %[^\n]s",&restache);
	Tache Filtrage[i];
	for(j=0;j<i;j++)
	{
		if(strcmp(restache,tache[j].responsable)==0)
		{
			Filtrage[k].idTache=tache[j].idTache;
		    strcpy(Filtrage[k].responsable,tache[j].responsable);
		    strcpy(Filtrage[k].description,tache[j].description);
		    Filtrage[k].dateEcheance.jour=tache[j].dateEcheance.jour;
		    Filtrage[k].dateEcheance.mois=tache[j].dateEcheance.mois;
		    Filtrage[k].dateEcheance.annee=tache[j].dateEcheance.annee;
		    strcpy(Filtrage[k].priorite,tache[j].priorite);
		    k++;
		}
	}
	if(k==0)
	{
		printf("Tache introuvable !! Ressayer.. \n\n\n");
		Filtrertache();
	}
	for(j=0;j<k;j++){
    	printf("\tTache %d :\n",j+1);
    	printf("\t\tNumero du tache : ");
        printf(" %d\n",Filtrage[j].idTache);
        printf("\t\tResponsable du tache %d : ",Filtrage[j].idTache);
        printf(" %s\n",Filtrage[j].responsable);
        printf("\t\tDescription du tache %d : ",Filtrage[j].idTache);
        printf(" %s\n",Filtrage[j].description);
        printf("\t\tDate d' echeance du tache %d : ",Filtrage[j].idTache);
        printf(" %d/%d/%d\n",Filtrage[j].dateEcheance.jour,Filtrage[j].dateEcheance.mois,Filtrage[j].dateEcheance.annee);
        printf("\t\tLa priorite du tache %d : ",Filtrage[j].idTache);
	    printf(" %s\n",Filtrage[j].priorite);
	}
	printf("\n\n\n\n");
	AfficherMenu();	
}

void FiltreDateEcheance(){
	int jour,mois,annee,j,k=0;
	printf("Date d echeance du tache : \n");
	printf("\tAnnee : ");
	scanf("%d",&annee);
	printf("\tMois : ");
	scanf("%d",&mois);
	printf("\tJour : ");
	scanf("%d",&jour);
	
	Tache Filtrage[i];
	
	for(j=0;j<i;j++)
	{
		if(tache[j].dateEcheance.annee>annee)
		{
			Filtrage[k].idTache=tache[j].idTache;
		    strcpy(Filtrage[k].responsable,tache[j].responsable);
		    strcpy(Filtrage[k].description,tache[j].description);
		    Filtrage[k].dateEcheance.jour=tache[j].dateEcheance.jour;
		    Filtrage[k].dateEcheance.mois=tache[j].dateEcheance.mois;
		    Filtrage[k].dateEcheance.annee=tache[j].dateEcheance.annee;
		    strcpy(Filtrage[k].priorite,tache[j].priorite);
		    k++;
		}
		else if(tache[j].dateEcheance.annee==annee&&tache[j].dateEcheance.mois>mois)
		{
			Filtrage[k].idTache=tache[j].idTache;
		    strcpy(Filtrage[k].responsable,tache[j].responsable);
		    strcpy(Filtrage[k].description,tache[j].description);
		    Filtrage[k].dateEcheance.jour=tache[j].dateEcheance.jour;
		    Filtrage[k].dateEcheance.mois=tache[j].dateEcheance.mois;
		    Filtrage[k].dateEcheance.annee=tache[j].dateEcheance.annee;
		    strcpy(Filtrage[k].priorite,tache[j].priorite);
		    k++;
		}
		else if(tache[j].dateEcheance.annee==annee&&tache[j].dateEcheance.mois==mois&&tache[j].dateEcheance.jour>jour)
		{
			Filtrage[k].idTache=tache[j].idTache;
		    strcpy(Filtrage[k].responsable,tache[j].responsable);
		    strcpy(Filtrage[k].description,tache[j].description);
		    Filtrage[k].dateEcheance.jour=tache[j].dateEcheance.jour;
		    Filtrage[k].dateEcheance.mois=tache[j].dateEcheance.mois;
		    Filtrage[k].dateEcheance.annee=tache[j].dateEcheance.annee;
		    strcpy(Filtrage[k].priorite,tache[j].priorite);
		    k++;
		}
		else if(tache[j].dateEcheance.annee==annee&&tache[j].dateEcheance.mois==mois&&tache[j].dateEcheance.jour==jour)
		{
			Filtrage[k].idTache=tache[j].idTache;
		    strcpy(Filtrage[k].responsable,tache[j].responsable);
		    strcpy(Filtrage[k].description,tache[j].description);
		    Filtrage[k].dateEcheance.jour=tache[j].dateEcheance.jour;
		    Filtrage[k].dateEcheance.mois=tache[j].dateEcheance.mois;
		    Filtrage[k].dateEcheance.annee=tache[j].dateEcheance.annee;
		    strcpy(Filtrage[k].priorite,tache[j].priorite);
		    k++;
		}
	}
	if(k==0)
	{
		printf("Aucune tache disponible !! \n\n\n");
		Filtrertache();
	}
	for(j=0;j<k;j++){
    	printf("\tTache %d :\n",j+1);
    	printf("\t\tNumero du tache : ");
        printf(" %d\n",Filtrage[j].idTache);
        printf("\t\tResponsable du tache %d : ",Filtrage[j].idTache);
        printf(" %s\n",Filtrage[j].responsable);
        printf("\t\tDescription du tache %d : ",Filtrage[j].idTache);
        printf(" %s\n",Filtrage[j].description);
        printf("\t\tDate d' echeance du tache %d : ",Filtrage[j].idTache);
        printf(" %d/%d/%d\n",Filtrage[j].dateEcheance.jour,Filtrage[j].dateEcheance.mois,Filtrage[j].dateEcheance.annee);
        printf("\t\tLa priorite du tache %d : ",Filtrage[j].idTache);
	    printf(" %s\n",Filtrage[j].priorite);
	}
	printf("\n\n\n");
	AfficherMenu();	
}

void FiltrePriorite(){
	int j,k=0;
	char priotache[40];
	printf("Priorite du tache : ");
	scanf(" %[^\n]s",&priotache);
	
	Tache Filtrage[i];
	
	for(j=0;j<i;j++)
	{
		if(strcmp(priotache,tache[j].priorite)==0)
		{
			Filtrage[k].idTache=tache[j].idTache;
		    strcpy(Filtrage[k].responsable,tache[j].responsable);
		    strcpy(Filtrage[k].description,tache[j].description);
		    Filtrage[k].dateEcheance.jour=tache[j].dateEcheance.jour;
		    Filtrage[k].dateEcheance.mois=tache[j].dateEcheance.mois;
		    Filtrage[k].dateEcheance.annee=tache[j].dateEcheance.annee;
		    strcpy(Filtrage[k].priorite,tache[j].priorite);
		    k++;
		}
	}
	if(k==0)
	{
		printf("Tache introuvable !! Ressayer.. \n\n\n");
		Filtrertache();
	}
	for(j=0;j<k;j++){
    	printf("\tTache %d :\n",j+1);
    	printf("\t\tNumero du tache : ");
        printf(" %d\n",Filtrage[j].idTache);
        printf("\t\tResponsable du tache %d : ",Filtrage[j].idTache);
        printf(" %s\n",Filtrage[j].responsable);
        printf("\t\tDescription du tache %d : ",Filtrage[j].idTache);
        printf(" %s\n",Filtrage[j].description);
        printf("\t\tDate d' echeance du tache %d : ",Filtrage[j].idTache);
        printf(" %d/%d/%d\n",Filtrage[j].dateEcheance.jour,Filtrage[j].dateEcheance.mois,Filtrage[j].dateEcheance.annee);
        printf("\t\tLa priorite du tache %d : ",Filtrage[j].idTache);
	    printf(" %s\n",Filtrage[j].priorite);
	}
	printf("\n\n\n");
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
	
	
	printf("\nVoila les taches disponible a ce moment la :\n\n");
    for(j=0;j<i;j++){
    	printf("\tTache %d :\n",j+1);
    	printf("\t\tNumero du tache : ");
        printf(" %d\n",t[j].idTache);
        printf("\t\tResponsable du tache %d : ",t[j].idTache);
        printf(" %s\n",t[j].responsable);
        printf("\t\tDescription du tache %d : ",t[j].idTache);
        printf(" %s\n",t[j].description);
        printf("\t\tDate d' echeance du tache %d : ",t[j].idTache);
        printf(" %d/%d/%d\n",t[j].dateEcheance.jour,t[j].dateEcheance.mois,t[j].dateEcheance.annee);
        printf("\t\tLa priorite du tache %d : ",t[j].idTache);
	    printf(" %s\n",t[j].priorite);
	}
	printf("\n\n\n");
	AfficherMenu();	
}


int main(){
	
	AfficherMenu();
	return 0;
}
