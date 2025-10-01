#include <stdio.h>
#include <string.h>
#include <time.h>
#define MAX 5

int choix, countProduit, choixCatalogue, choixTri, choixTriCroissanat;
int choixProfil;
char newName[30], motRechercher[30];
char newPrenom[30];
float montantDepot;
int choixModifie, choixSolde;
int choixCaregorie, produitAcheter, tourver = 0, countHistorique = 0, quantiteAchat, checkProfil = 0;
int id, count = 0;
int choixSH;
float totalAchates;
int choixSatatique;
 int moisChercher ,trouveMois = 0;
 int tableauxProduit[20] , countTab=0;


typedef struct
{
    int idClient;
    char nom[30];
    char prenom[30];
    char email[200];
    float solde;
} Client;


typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;

typedef struct
{
    int id;
    char nomProduit[30];
    float prixProduit;
    int quantiter;
    Date date;
} Historique;


typedef struct
{
    int idProduit;
    char nom[30];
    char categorie[30];
    float prix;
    int stock;
    char description[100];
} Produit;


Produit produits[MAX] = {
 {1, "Ordinateur Portable", "electronic", 799.00, 5, "nadi"},
 {2, "Martphone", "food", 499.00, 10, "nadi"}, 
 {3, "Casque Audio", "cars", 89.00, 15, "nadi"},
 {4, "Souris", "food", 25, 20, "nadi"},
 {5, "Clavier", "electronic", 45, 12, "nadi"}
};
Historique historique[100];
Client clients[1];


Date getDate()
{
    Date now;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    now.jour = tm.tm_mday;
    now.mois = tm.tm_mon + 1;
    now.annee = tm.tm_year + 1900;
    return now;
}

void creationProfil()
{
    getchar();
    printf("donner votre nom : ");
    scanf("%s", clients[count].nom);
    printf("donner votre prenom : ");
    scanf("%s", clients[count].prenom);
    clients[count].idClient = count + 1;
    clients[count].solde = 0;
    strcpy(clients[count].email, clients[count].nom);
    strcat(clients[count].email, ".");
    strcat(clients[count].email, clients[count].prenom);
    strcat(clients[count].email, "@client.com");
    checkProfil = 1;
}

void gestionProfil()
{
    do
    {
        printf("=== Gestion du Profil Client ===\n");
        printf("1.Création de profil\n");
        printf("2.Modification du profil\n");
        printf("3.Consultation du profil\n");
        printf("4.reture meun principal\n");
        printf("voter choix : ");
        scanf("%d", &choixProfil);
        switch (choixProfil)
        {
        case 1:
            creationProfil();
            break;
        case 2:
            if (!checkProfil)
            {
                printf("creation de profil\n");
            }
            else
                do
                {
                    printf("Modification du profil\n");
                    printf("1.Mise à jour nom\n");
                    printf("2.Mise à jour prenom\n");
                    printf("3.reture menu principal\n");
                    printf("voter choix : ");
                    scanf("%d", &choixModifie);
                    switch (choixModifie)
                    {
                    case 1:

                        printf("donner nouvaux nom : ");
                        scanf("%s", newName);
                        strcpy(clients[count].nom, newName);
                        break;
                    case 2:

                        printf("donner nouvaux prenom : ");
                        scanf("%s", newPrenom);
                        strcpy(clients[count].prenom, newPrenom);
                        break;
                    default:
                        printf("invalide input\n");
                        break;
                    }

                } while (choixModifie != 3);

            break;
        case 3:
            if (!checkProfil)
            {
                printf("creation de profil\n");
            }
            else
                printf("informations client\n");
            printf("nom : %s\n", clients[count].nom);
            printf("prenom : %s\n", clients[count].prenom);
            printf("email : %s\n", clients[count].email);
            printf("solde : %.2fDH\n", clients[count].solde);
            break;

        default:
            printf("invalide input\n");
            break;
        }
    } while (choixProfil != 4);
}
void gestionSolde()
{
    if (!checkProfil)
    {
        printf("creation de profil\n");
    }
    else
        do
        {
            printf("Gestion du Solde Virtuel\n");
            printf("1.Consultation du solde\n");
            printf("2.Dépôt d'argent\n");
            printf("3.reture menu principal\n");
            printf("voter choix : ");
            scanf("%d", &choixSolde);

            switch (choixSolde)
            {
            case 1:
                printf("solde : %.2fDH\n", clients[count].solde);
                break;
            case 2:
                printf("montant qui depot : ");
                scanf("%f", &montantDepot);
                clients[count].solde += montantDepot;
                break;
            default:
                printf("invalide input");
                break;
            }

        } while (choixSolde != 3);
}
void consultationProduit()
{
    do
    {
        printf("Catalogue des Produits\n");
        printf("1.Affichage catalogue \n");
        printf("2.Recherche produits\n");
        printf("3.Tri des produits\n");
        printf("4.Détails produit\n");
        printf("5.quitter\n");
        printf("voter choix : ");
        scanf("%d", &choixCatalogue);
        switch (choixCatalogue)
        {
        case 1:

            for (int i = 0; i < 5; i++)
            {
                printf("======================\n");
                printf("id de produit : %d\n", produits[i].idProduit);
                printf("nom de produit : %s\n", produits[i].nom);
                printf("categorie de produit : %s\n", produits[i].categorie);
                printf("prix de produit : %.2fDH\n", produits[i].prix);
                printf("stock de produit : %dDH\n", produits[i].stock);
                printf("description de produit : %s\n", produits[i].description);
            }

            break;
        case 2:
            getchar();
            printf("donner nom ou categorie de produits : ");
            fgets(motRechercher, sizeof(motRechercher), stdin);
            motRechercher[strcspn(motRechercher, "\n")] = 0;
            for (int i = 0; i < 5; i++)
            {
                if (strcmp(produits[i].categorie, motRechercher) == 0 || strcmp(produits[i].nom, motRechercher) == 0)
                {
                    printf("======================\n");
                    printf("id de produit : %d\n", produits[i].idProduit);
                    printf("nom de produit : %s\n", produits[i].nom);
                    printf("categorie de produit : %s\n", produits[i].categorie);
                    printf("prix de produit : %.2fDH\n", produits[i].prix);
                    printf("stock de produit : %dDH\n", produits[i].stock);
                    printf("description de produit : %s\n", produits[i].description);
                    tourver = 1;
                }
            }
            if (!tourver)
            {
                printf("pas exisit %s dans categorie ou nom de produit\n", motRechercher);
            }

            break;
        case 3:
            do
            {
                printf("Tri des produits \n");
                printf("1.tri par prix\n");
                printf("2.tri par nom alphabetique\n");
                printf("3.reture menu principal\n");
                printf("voter choix : ");
                scanf("%d", &choixTri);
                switch (choixTri)
                {
                case 1:
                    do
                    {
                        printf("1.croissant\n");
                        printf("2.décroissant\n");
                        printf("3.annuler\n");
                        printf("voter choix : ");
                        scanf("%d", &choixTriCroissanat);
                        switch (choixTriCroissanat)
                        {
                        case 1:
                            for (int i = 0; i < 5; i++)
                            {
                                for (int j = 0; j < 5 - i - 1; j++)
                                {
                                    if (produits[j].prix < produits[j + 1].prix)
                                    {
                                        int idChange;
                                        char nomChange[30];
                                        char categorieChange[30];
                                        float prixChange;
                                        int stockChange;
                                        char descriptionChange[100];
                                        idChange = produits[j].idProduit;
                                        produits[j].idProduit = produits[j + 1].idProduit;
                                        produits[j + 1].idProduit = idChange;
                                        strcpy(nomChange, produits[j].nom);
                                        strcpy(produits[j].nom, produits[j + 1].nom);
                                        strcpy(produits[j + 1].nom, nomChange);
                                        strcpy(categorieChange, produits[j].categorie);
                                        strcpy(produits[j].categorie, produits[j + 1].categorie);
                                        strcpy(produits[j + 1].categorie, categorieChange);
                                        strcpy(descriptionChange, produits[j].description);
                                        strcpy(produits[j].description, produits[j + 1].description);
                                        strcpy(produits[j + 1].description, descriptionChange);
                                        prixChange = produits[j].prix;
                                        produits[j].prix = produits[j + 1].prix;
                                        produits[j + 1].prix = prixChange;

                                        stockChange = produits[j].stock;
                                        produits[j].stock = produits[j + 1].stock;
                                        produits[j + 1].stock = stockChange;
                                    }
                                }
                            }
                            for (int i = 0; i < 5; i++)
                            {
                                printf("======================\n");
                                printf("id de produit : %d\n", produits[i].idProduit);
                                printf("nom de produit : %s\n", produits[i].nom);
                                printf("categorie de produit : %s\n", produits[i].categorie);
                                printf("prix de produit : %.2fDH\n", produits[i].prix);
                                printf("description de produit : %s\n", produits[i].description);
                            }

                            break;
                        case 2:
                            for (int i = 0; i < 5; i++)
                            {
                                for (int j = 0; j < 5 - i - 1; j++)
                                {
                                    if (produits[j].nom > produits[j + 1].nom)
                                    {
                                        int idChange;
                                        char nomChange[30];
                                        char categorieChange[30];
                                        float prixChange;
                                        int stockChange;
                                        char descriptionChange[100];

                                        idChange = produits[j].idProduit;
                                        produits[j].idProduit = produits[j + 1].idProduit;
                                        produits[j + 1].idProduit = idChange;
                                        strcpy(nomChange, produits[j].nom);
                                        strcpy(produits[j].nom, produits[j + 1].nom);
                                        strcpy(produits[j + 1].nom, nomChange);

                                        strcpy(categorieChange, produits[j].categorie);
                                        strcpy(produits[j].categorie, produits[j + 1].categorie);
                                        strcpy(produits[j + 1].categorie, categorieChange);

                                        strcpy(descriptionChange, produits[j].description);
                                        strcpy(produits[j].description, produits[j + 1].description);
                                        strcpy(produits[j + 1].description, descriptionChange);
                                        prixChange = produits[j].prix;
                                        produits[j].prix = produits[j + 1].prix;
                                        produits[j + 1].prix = prixChange;

                                        stockChange = produits[j].stock;
                                        produits[j].stock = produits[j + 1].stock;
                                        produits[j + 1].stock = stockChange;
                                    }
                                }
                            }
                            for (int i = 0; i < 5; i++)
                            {
                                printf("======================\n");
                                printf("id de produit : %d\n", produits[i].idProduit);
                                printf("nom de produit : %s\n", produits[i].nom);
                                printf("categorie de produit : %s\n", produits[i].categorie);
                                printf("prix de produit : %.2fDH\n", produits[i].prix);
                                printf("description de produit : %s\n", produits[i].description);
                            }

                        default:
                            break;
                        }
                    } while (choixTriCroissanat != 3);
                    break;
                case 2:
                    for (int i = 0; i < 5; i++)
                    {
                        for (int j = 0; j < 5 - i - 1; j++)
                        {
                            if ((int)produits[j].nom > (int)produits[j + 1].nom)
                            {
                                int idChange;
                                char nomChange[30];
                                char categorieChange[30];
                                float prixChange;
                                int stockChange;
                                char descriptionChange[100];
                                idChange = produits[j].idProduit;
                                produits[j].idProduit = produits[j + 1].idProduit;
                                produits[j + 1].idProduit = idChange;
                                strcpy(nomChange, produits[j].nom);
                                strcpy(produits[j].nom, produits[j + 1].nom);
                                strcpy(produits[j + 1].nom, nomChange);
                                strcpy(categorieChange, produits[j].categorie);
                                strcpy(produits[j].categorie, produits[j + 1].categorie);
                                strcpy(produits[j + 1].categorie, categorieChange);
                                strcpy(descriptionChange, produits[j].description);
                                strcpy(produits[j].description, produits[j + 1].description);
                                strcpy(produits[j + 1].description, descriptionChange);
                                prixChange = produits[j].prix;
                                produits[j].prix = produits[j + 1].prix;
                                produits[j + 1].prix = prixChange;

                                stockChange = produits[j].stock;
                                produits[j].stock = produits[j + 1].stock;
                                produits[j + 1].stock = stockChange;
                            }
                        }
                    }
                    for (int i = 0; i < 5; i++)
                    {
                        printf("======================\n");
                        printf("id de produit : %d\n", produits[i].idProduit);
                        printf("nom de produit : %s\n", produits[i].nom);
                        printf("categorie de produit : %s\n", produits[i].categorie);
                        printf("prix de produit : %.2fDH\n", produits[i].prix);
                        printf("description de produit : %s\n", produits[i].description);
                    }
                    break;

                default:
                    printf("invalide input\n");
                    break;
                }
            } while (choixTri != 3);
        case 4:

            for (int i = 0; i < 5; i++)
            {
                printf("produit %d:\n", i + 1);
                printf("id de produit : %d\n", produits[i].idProduit);
                printf("nom de produit : %s\n", produits[i].nom);
                printf("categorie de produit : %s\n", produits[i].categorie);
                printf("prix de produit : %.2f\n", produits[i].prix);
                printf("prix de produit : %d\n", produits[i].stock);
                printf("description de produit : %s\n", produits[i].description);
            }
            break;
        default:
            printf("invalide input");
            break;
        }

    } while (choixCatalogue != 5);
}
void effectuerAchat()
{
    
    if (!checkProfil)
    {
        printf("creation de profil\n");
    }
    else
        for (int i = 0; i < 5; i++)
        {
            printf("%d.%s\n", i + 1, produits[i].categorie);
        }
    getchar();
    printf("votre choix : ");
    scanf("%d", &choixCatalogue);
    for (int i = 0; i < 5; i++)
    {
        if (strcmp(produits[i].categorie, produits[choixCatalogue - 1].categorie) == 0)
        {

            
            printf("id de produit : %d\n", produits[i].idProduit);
            printf("nom de produit : %s\n", produits[i].nom);
            printf("categorie de produit : %s\n", produits[i].categorie);
            printf("prix de produit : %.2f\n", produits[i].prix);
            printf("stock de produit : %d\n", produits[i].stock);
            printf("description de produit : %s\n", produits[i].description);
            

        }
    }
  
   
    printf("quel id de produit qui veux acheter : ");
    scanf("%d", &produitAcheter);
    for (int i = 0; i < 5; i++)
    {  
        if
    }
    
    printf("donner quantite tu veux acheter : ");
    scanf("%d", &quantiteAchat);
    if (clients[count].solde < produits[produitAcheter - 1].prix * quantiteAchat)
    {
        printf("pas de l argent\n");
    }
    else if (quantiteAchat > produits[produitAcheter - 1].stock)
    {
        printf("quantite de stock Non compétent\n");
    }

    else
    {

        clients[count].solde -= produits[produitAcheter - 1].prix * quantiteAchat;
        produits[produitAcheter - 1].stock -= quantiteAchat;
        historique[countHistorique].id = countHistorique + 1;
        strcpy(historique[countHistorique].nomProduit, produits[produitAcheter - 1].nom);
        historique[countHistorique].date = getDate();
        historique[countHistorique].prixProduit = produits[produitAcheter - 1].prix * quantiteAchat;
        historique[countHistorique].quantiter = quantiteAchat;
        countHistorique++;
        printf("achat succes\n");
    }
}
void historiqueAfficher()


{
    if (!countHistorique)
    {
        printf("===============\n");
        printf("pas de historique\n");
    }
    else
    {
        printf("===============\n");
        printf("historique :\n");
        for (int i = 0; i < countHistorique; i++)
        {
            printf("id : %d\n", historique[i].id);
            printf("nom de produit : %s\n", historique[i].nomProduit);
            printf("quantite de produit : %d\n", historique[i].quantiter);
            printf("date : %02d/%02d/%d\n", historique[i].date.jour, historique[i].date.mois, historique[i].date.annee);
        }
    }
}
void statistiques() {
    
     do
     { 
        printf("==================\n");
        printf("statistiques : \n");
        printf("1.prix total des produits achates\n");
        printf("2.liste de nom des produits achates\n");
        printf("3.historique de produit par mois\n");
        printf("4.quitter\n");
        printf("votre choix : ");
        scanf("%d",&choixSatatique);
     
        switch (choixSatatique)
        {
        case 1:
          
            for (int i = 0; i < countHistorique; i++)
            {

                totalAchates+= historique[i].prixProduit;
            }
            printf("================\n");
            printf("prix total des achates : %.2fDH\n", totalAchates);
            break;
        case 2:
            for (int i = 0; i < countHistorique; i++)
            {
                printf("==================\n");
                printf("nom de produit : %s\n",historique[i].nomProduit);
            }
            break;
        case 3:
          
           printf("donner le mois tu veux : ");
           scanf("%d",&moisChercher);
           for (int i = 0; i < countHistorique; i++)
           {
            if (historique[i].date.mois == moisChercher)
            {
                printf("==================\n");
                printf("id : %d\n", historique[i].id);
                printf("nom de produit : %s\n", historique[i].nomProduit);
                printf("quantite de produit : %d\n", historique[i].quantiter);
                trouveMois = 1;
            }
            
           }
           if (!trouveMois)
           {
            printf("pas de achat dans cette mois\n");
           }
           
           
           break;
        default:
            printf("invalide inpute\n");
            break;
        }
     } while (choixSatatique != 4);
     
}
int main()

{

    do
    {
        printf("=== SYSTÈME D'ACHAT CLIENT ===\n");
        printf("1.Gestion du profil client\n");
        printf("2.Gestion du solde virtuel\n");
        printf("3.Consultation des produits\n");
        printf("4.Effectuer un achat\n");
        printf("5.Mes statistiques\n");
        printf("0.Quitter l'application\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            gestionProfil();
            break;
        case 2:
            gestionSolde();
            break;
        case 3:
            consultationProduit();
            break;
        case 4:
            effectuerAchat();
            break;
        case 5:
        
            do
            {
                printf("1.historique\n");
                printf("2.statistique\n");
                printf("3.quitter\n");
                printf("votre choix : ");
                scanf("%d", &choixSH);
                switch (choixSH)
                {
                case 1:
                    historiqueAfficher();
                    break;
                case 2:
                  statistiques();
                  break;
                default:
                    printf("input invalide\n");
                    break;
                }
            } while (choixSH != 3);
            
           
            break;
        case 0:
            printf("tu quitter le system\n");
            break;
        default:
            printf("invalide input\n");
            break;
        }
    } while (choix != 0);

    return 0;
}