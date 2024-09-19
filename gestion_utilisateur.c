#include "gestion.h"

/*fichier aver le fonction de gestion de utilisateur*/

int inscription(Utilisateur *utilisateurs)
{
    char nom[50];
    char prenom[50];
    char user_name[50];
    char email[50];
    char mdp[50];
    char conf_mdp[50];
    char role[10];

    printf("Entrer votre nom: ");
    fgets(nom, 50, stdin);
    printf("Entrer votre prenom: ");
    fgets(prenom, 50, stdin);
    printf("Entrer votre nom d'utilisateur: ");
    fgets(user_name, 50, stdin);
    do
    {
    printf("Entrer votre email: ");
    fgets(email, 50, stdin);
    } while (check_email(email) != 1);
    do
    {
    printf("Entrer votre mot de passe: ");
    fgets(mdp, 50, stdin);
    } while (mdp_check(mdp, user_name) != 1);
    
    do
    {
        printf("Confirmer votre mot de passe: ");
        fgets(conf_mdp, 50, stdin);
    } while (strcmp(mdp, conf_mdp) != 0);

    strcpy(utilisateurs[users_count].nom, nom);
    strcpy(utilisateurs[users_count].prenom, prenom);
    strcpy(utilisateurs[users_count].user_name, user_name);
    strcpy(utilisateurs[users_count].email, email);
    strcpy(utilisateurs[users_count].mdp, mdp);
    if(users_count == 0)
    {
        strcpy(utilisateurs[users_count].role, "admin");
    }
    else{
        strcpy(utilisateurs[users_count].role, "user");
    }
    
    return users_count;
}

int connexion(Utilisateur *utilisateurs)
{
    char user_name[50];
    char mdp[50];
    int i, count = 0;
    do
    {
    printf("Entrer votre nom d'utilisateur: ");
    fgets(user_name, 50, stdin);
    
    printf("Entrer votre mot de passe: ");
    fgets(mdp, 50, stdin);

    for (i = 0; i < users_count; i++)
    {
        if (strcmp(utilisateurs[i].user_name, user_name) == 0 && strcmp(utilisateurs[i].mdp, mdp) == 0)
        {
            printf("Connexion reussie!\n");
            return i;
        }
    }
    } while (count < 3);
    printf("Trop de tentatives. Connexion impossible.\n");
    return -1;
}

