#include "gestion.h"
#include <dos.h>

/*les fcts de client*/

struct date {
    int day;
    int month;
    int year;
};


int ajouter_reclamation(Reclamation *reclamations, Utilisateur *utilisateurs, int users_index)
{
    char motif[100];
    char description[200];
    char categorie[50];
    char date[11];
    char title[50];

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);

 

    printf("Entrer le titre de la reclamation: \n");
    fgets(title, 50, stdin);
    printf("Entrer le motif de la reclamation: \n");
    fgets(motif, 100, stdin);
    printf("Entrer la description de la reclamation: \n");
    fgets(description, 200, stdin);
    printf("Entrer la categorie de la reclamation: \n");
    fgets(categorie, 50, stdin);

    strcpy(reclamations[reclamations_count].title, title);
    strcpy(reclamations[reclamations_count].motif, motif);
    strcpy(reclamations[reclamations_count].description, description);
    strcpy(reclamations[reclamations_count].categorie, categorie);
    strcpy(reclamations[reclamations_count].statut, "En cours");
    strcpy(reclamations[reclamations_count].date, date);
    int id = id_generation(reclamations);
    reclamations[reclamations_count].id = id;
    reclamations[reclamations_count].user = utilisateurs[users_count];
    reclamations_count++;
    return reclamations_count;
}

void modifier_reclamation(Reclamation *reclamations, Utilisateur *utilisateurs, int userindex)
{
    char motif[100];
    char description[200];
    char categorie[50];
    char date[11];
    char title[50];
    int found = 0;
    int index;
    printf("Entrer le titre de la reclamation: ");
    fgets(title, 50, stdin);
    for (int i = 0; i < reclamations_count; i++)
    {
        if ((strcmp(title, reclamations[i].title) == 0) && (reclamations[i].user.user_name == utilisateurs[userindex].user_name))
        {
            found = 1;
            index = i;
            break;
        }
    }
    if(found == 0)
    {
        printf("Reclamation not found!\n");
        return;
    }

    printf("modifier le titre ou enter pour skiper: ");
    fgets(title, 50, stdin);
    if(strlen(title) > 1)
    {
        strcpy(reclamations[index].title, title);
    }
    printf("modifier le motif ou enter pour skiper: ");
    fgets(motif, 100, stdin);
    if(strlen(motif) > 1)
    {
        strcpy(reclamations[index].motif, motif);
    }
    printf("modifier la description ou Entrer: ");
    fgets(description, 200, stdin);
    if(strlen(description) > 1)
    {
        strcpy(reclamations[index].description, description);
    }
    printf("modifier la categorie ou Entrer: ");
    fgets(categorie, 50, stdin);
    if(strlen(categorie) > 1)
    {
        strcpy(reclamations[index].categorie, categorie);
    }
    printf("Modifier la date ou Entrer: ");
    fgets(date, 11, stdin);
    if(strlen(date) > 1)
    {
        strcpy(reclamations[index].date, date);
    }
    printf("Reclamation updated!\n");

}

void supprimer_reclamation(Reclamation *reclamations, Utilisateur *utilisateurs, int userindex)
{
    char title[50];
    int found = 0;
    int index;
    printf("Entrer le titre de la reclamation: ");
    fgets(title, 50, stdin);
    for (int i = 0; i < reclamations_count; i++)
    {
        if ((strcmp(title, reclamations[i].title) == 0) && (reclamations[i].user.user_name == utilisateurs[userindex].user_name))
        {
            found = 1;
            index = i;
            break;
        }
    }
    if(found == 0)
    {
        printf("Reclamation not found!\n");
        return;
    }

    for (int i = index; i < reclamations_count - 1; i++)
    {
        reclamations[i] = reclamations[i + 1];
    }
    reclamations_count--;
    printf("Reclamation deleted!\n");
}


void affichage_reclamation(Reclamation *reclamations, Utilisateur *utilisateurs, int userindex)
{

    for (int i = 0; i < reclamations_count; i++)
    {
        if (reclamations[i].user.user_name == utilisateurs[userindex].user_name)
        {
            printf("ID: %d\n", reclamations[i].id);
            printf("Titre: %s\n", reclamations[i].title);
            printf("Motif: %s\n", reclamations[i].motif);
            printf("Description: %s\n", reclamations[i].description);
            printf("Categorie: %s\n", reclamations[i].categorie);
            printf("Date: %s\n", reclamations[i].date);
            printf("Statut: %s\n", reclamations[i].statut);
        }
    }
}
