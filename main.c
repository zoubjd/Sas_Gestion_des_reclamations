#include <stdio.h>
#include "gestion.h"

/*
Projet SAS : Gestion des réclamations
*/



    int users_count = 0;
    int reclamations_count = 0;
int main()
{
    int choice = 0;
    int index;
    Utilisateur utilisateurs[MAX_UTILISATEURS];
    Reclamation reclamations[MAX_UTILISATEURS];
    while (1)
    {
        do
    {
    printf("Bonjour, et bienvenue au Gestion des Reclamations!\n");
    printf("Que voulez-vous faire ?\n");
    printf("1. Inscription\n");
    printf("2. Connexion\n");
    printf("3. Quitter\n");
    printf("4. display users\n");
    scanf("%d", &choice);
    getchar();
    } while (choice > 4 || choice < 1);
    

    switch (choice)
    {
    case 1:
    {

        printf("Inscription\n");
        index = inscription(utilisateurs);
        users_count++;
        printf("Utilisateur inscrit avec succes\n");
        break;
    }
    case 2:
    {

        printf("Connexion\n");
        index = connexion(utilisateurs);
        if (index >= 0 && strcmp(utilisateurs[index].role, "admin") == 0)
            {
                admin_menu(utilisateurs, reclamations);
            }
            else if (index && strcmp(utilisateurs[index].role, "agent") == 0)
            {
                printf("Vous etes un agent!\n");
            }
            else if (index && strcmp(utilisateurs[index].role, "user") == 0)
            {
                user_menu(index, utilisateurs, reclamations);
            }
        break;
    }
    case 3:
        printf("Au revoir!\n");
        return 0;
        break;

    case 4:
        printf("Liste des utilisateurs:\n");
        for (int i = 0; i < users_count; i++)
        {
            printf("%s\n", utilisateurs[i].user_name);
            printf("%s\n", utilisateurs[i].email);
            printf("%s\n", utilisateurs[i].role);
        }
        break;
        

    default:
        printf("Choix invalide\n");
        break;
    }
    }
    

    return 0;
}


