#include "gestion.h"

/*gestion de menues*/

int admin_menu()
{

    int choice = 0;
    while (1)
    {
        printf("Role: admin\n");
        printf("-------------------------\n");
        printf("Entrer votre choix:\n");
        printf("1. modifier le role d'un utilisateurs\n");
        printf("2. Ajouter une reclamation\n");
        printf("3. modifyer une reclamations\n");
        printf("4. Supprimer une reclamations\n");
        printf("Statistic et rapports---\n");
        printf("5. Afficher le nombre total de réclamation\n");
        printf("6. Afficher le taux de résolution des réclamations\n");
        printf("7. Calculer le délai moyen de traitement des réclamations\n");
        printf("8. Rapport journalier\n");
        printf("9. Deconexion\n");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            /* code */
            break;
        
        case 8:
            printf("Au revoir!\n");
            return 0;
            break;
        
        default:
        printf("Choix incorrecte\n");
            break;
        }


    }
    
}

int user_menu(int userindex, Utilisateur utilisateurs[MAX_UTILISATEURS], Reclamation reclamations[MAX_UTILISATEURS], int reclamations_count){
int choice;
printf("Role: user\n");
printf("-------------------------\n");
printf("Entrer votre choix:\n");
printf("1. Ajouter une reclamation\n");
printf("2. modifiyer une reclamations\n");
printf("3. Supprimer une reclamations\n");
printf("4. Afficher les réclamation\n");
printf("5. Deconnexion\n");
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
    supprimer_reclamation(reclamations, utilisateurs, userindex);
    break;
default:
    break;
}
return 0;
}

