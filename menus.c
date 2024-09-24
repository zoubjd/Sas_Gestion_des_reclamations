#include "gestion.h"

/*gestion de menues*/

int admin_menu(Utilisateur *utilisateurs, Reclamation *Reclamation)
{

    int choice = 0;
    while (1)
    {
        printf("Role: admin\n");
        printf("---------------------------------------\n");
        printf("Entrer votre choix:\n");
        printf("1. Changer le role d'un utilisateur\n");
        printf("2. Ajouter une reclamation\n");
        printf("3. modifiyer une reclamations\n");
        printf("4. Supprimer une reclamations\n");
        printf("5. Afficher les reclamation\n");
        printf("6. Modifer le statut d'une reclamation\n");
        printf("7. Rechercher une reclamation:\n");
        printf("Statistic et rapports---\n");
        printf("8. Afficher le nombre total de reclamation\n");
        printf("9. Afficher le taux de résolution des reclamations\n");
        printf("10. Calculer le délai moyen de traitement des reclamations\n");
        printf("11. Afficher les rapports triee par priorite\n");
        printf("12. Generer le rapport quotidien!\n");
        printf("13. Deconexion\n");
        printf("---------------------------------------\n");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            modifier_role(utilisateurs);
            break;
        
        case 2:
            ajouter_reclamation(Reclamation, utilisateurs, 0);
            break;
        
        case 3:
            modifier_adgent_reclamation(Reclamation);
            break;
        
        case 4:
            supprimer_adgent_reclamation(Reclamation);
            break;
        
        case 5:
            affichage_adgent_reclamation(Reclamation);
            break;
        
        case 6:
            modistatut(Reclamation);
            break;
        
        case 7:
            recherche(Reclamation);
            break;

        case 8:
            printf("Nombre total de reclamation: %d\n", reclamations_count);
            break;
        
        case 9:
            taux_reclamation(Reclamation);
            break;
        
        case 10:
            delay_moyen(Reclamation);
            break;
        
        case 11:
            aficher_rec_parprio(Reclamation);
            break;
        
        case 12:
            rapport_journalier(Reclamation);
            break;

        case 13:
            printf("Au revoir!\n");
            return 0;
            break;
 
        default:
        printf("Choix incorrecte\n");
            break;
        }


    }
    
}

int user_menu(int userindex, Utilisateur *utilisateurs, Reclamation *reclamations)
{
int choice;
while (1)
{
printf("Role: user\n");
printf("-------------------------\n");
printf("Entrer votre choix:\n");
printf("1. Ajouter une reclamation\n");
printf("2. modifiyer une reclamations\n");
printf("3. Supprimer une reclamations\n");
printf("4. Afficher les reclamation\n");
printf("5. Deconnexion\n");
printf("--------------------------------\n");
scanf("%d", &choice);
getchar();
switch (choice)
{
case 1:
    ajouter_reclamation(reclamations, utilisateurs, userindex);
    printf("Reclamation ajouter avec succes!\n");
    break;

case 2:
    modifier_reclamation(reclamations, utilisateurs, userindex);
    break;

case 3:
    supprimer_reclamation(reclamations);
    break;

case 4:
    affichage_reclamation(reclamations, utilisateurs, userindex);
    break;

case 5:
    return 0;
    break;

default:
    printf("Choix incorrecte\n");
    break;
}    
}
}

int agent_menu(int userindex, Utilisateur *utilisateurs, Reclamation *reclamations)
{
int choice;
while (1)
{
printf("Role: agent\n");
printf("-------------------------\n");
printf("Entrer votre choix:\n");
printf("1. Ajouter une reclamation\n");
printf("2. modifiyer une reclamations\n");
printf("3. Supprimer une reclamations\n");
printf("4. Afficher les reclamation\n");
printf("5. Modifer le statut d'une reclamation\n");
printf("6. Rechercher une reclamation:\n");
printf("7. Deconnexion\n");
printf("--------------------------------\n");
scanf("%d", &choice);
getchar();
switch (choice)
{
case 1:
    ajouter_reclamation(reclamations, utilisateurs, userindex);
    printf("Reclamation ajouter avec succes!\n");
    break;

case 2:
    modifier_adgent_reclamation(reclamations);
    break;

case 3:
    supprimer_adgent_reclamation(reclamations);
    break;

case 4:
    affichage_adgent_reclamation(reclamations);
    break;

case 5:
    modistatut(reclamations);
    break;

case 6:
    recherche(reclamations);
    break;
    
case 7:
    printf("Deconnexion...\n");
    return 0;

default:
    printf("Choix Invalide!!\n");
    break;
}
}
}

