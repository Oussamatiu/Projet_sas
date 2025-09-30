#include <stdio.h>
#include <string.h>
#define MAX 100

int id, count = 0;
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
    int idProduit;
    char nom[30];
    char categorie[30];
    float prix;
    int stock;
    char description[100];
} Produit;

void creatProfil()
{
}
int findPos()
{
}

int main()
{
    Produit produits[MAX];
    Client clients[MAX];
    int choix, countProduit, choixCatalogue, choixTri, choixTriCroissanat;
    int choixProfil;
    char newName[30], motRechercher[30];
    char newPrenom[30];
    float montantDepot;
    int choixModifie, choixSolde;
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

                    break;
                case 2:

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

            break;
        case 2:

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
                    scanf("%d", &montantDepot);
                    clients[count].solde += montantDepot;
                default:
                    printf("invalide input");
                    break;
                }

            } while (choixSolde != 3);

            break;
        case 3:
            do
            {
                printf("Catalogue des Produits\n");
                printf("1.Affichage catalogue \n");
                printf("2.Recherche produits\n");
                printf("3.Tri des produits\n");
                printf("4.Détails produit\n");
                printf("5.Détails produit\n");
                printf("voter choix : ");
                scanf("%d", &choixCatalogue);
                switch (choixCatalogue)
                {
                case 1:
                    if (!countProduit)
                    {
                        printf("pas de produits\n");
                    }
                    else
                    {
                        for (int i = 0; i < countProduit; i++)
                        {
                            printf("======================\n");
                            printf("id de produit : %d", produits[i].idProduit);
                            printf("nom de produit : %s", produits[i].nom);
                            printf("categorie de produit : %d", produits[i].categorie);
                            printf("prix de produit : %.2fDH", produits[i].prix);
                            printf("description de produit : %s", produits[i].description);
                        }
                    }
                    break;
                case 2:
                    getchar();
                    printf("donner nom ou categorie de produits : ");
                    fgets(motRechercher, sizeof(motRechercher), stdin);
                    for (int i = 0; i < countProduit; i++)
                    {
                        if (strcmp(produits[i].categorie, motRechercher) == 0 || strcmp(produits[i].nom, motRechercher) == 0)
                        {
                            printf("======================\n");
                            printf("id de produit : %d\n", produits[i].idProduit);
                            printf("nom de produit : %s\n", produits[i].nom);
                            printf("categorie de produit : %d\n", produits[i].categorie);
                            printf("prix de produit : %.2fDH\n", produits[i].prix);
                            printf("description de produit : %s\n", produits[i].description);
                        }
                        else
                        {
                            printf("pas exisit %s dans categorie ou nom de produit\n", motRechercher);
                        }
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
                                    for (int i = 0; i < countProduit; i++)
                                    {
                                        for (int j = 0; j < countProduit - i - 1; j++)
                                        {
                                            if (produits[j].prix > produits[j + 1].prix)
                                            {
                                                int idChange;
                                                char nomChange[30];
                                                char categorieChange[30];
                                                float prixChange;
                                                int stockChange;
                                                char descriptionChange[100];
                                                idChange = produits[j].idProduit;
                                                produits[j].idProduit = produits[j + 1].idProduit;
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

                                    break;
                                case 2:
                                    for (int i = 0; i < countProduit; i++)
                                    {
                                        for (int j = 0; j < countProduit - i - 1; j++)
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
                                default:
                                    break;
                                }
                            } while (choixTriCroissanat != 3);

                            break;

                        default:
                            break;
                        }
                    } while (choixTri != 3);
                case 4:
                for (int i = 0; i < countProduit; i++)
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

            break;
        case 4:
            
            break;
        case 5:
            break;
        default:
            printf("invalide input\n");
            break;
        }
    } while (choix != 0);

    return 0;
}