#include "gestion.h"

/*les fcts de client*/

struct date {
    int day;
    int month;
    int year;
};


int ajouter_reclamation(Reclamation *reclamations, Utilisateur *utilisateurs, int userindex)
{
    char motif[100];
    char description[200];
    char categorie[50];
    char date[11];
    char title[50];

    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    reclamations[reclamations_count].added_time = t; 

 

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
    reclamations[reclamations_count].user = utilisateurs[userindex];
    //strcpy(reclamations[reclamations_count].priorite, "basse");

    if(strstr(reclamations[reclamations_count].description, "help") || strstr(reclamations[reclamations_count].description, "urgent") || strstr(reclamations[reclamations_count].description, "sos"))
    {
        strcpy(reclamations[reclamations_count].priorite, "haute");
    }
    else if (strstr(reclamations[reclamations_count].description, "aide") || strstr(reclamations[reclamations_count].description, "problem") || strstr(reclamations[reclamations_count].description, "casse"))
    {
        strcpy(reclamations[reclamations_count].priorite, "moyenne");
    }
    else{

        strcpy(reclamations[reclamations_count].priorite, "basse");
    }
    reclamations_count++;
    printf("Reclamation ajoutee avec success!!!\n");
    
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
    int id;
    char n_date[11];
    printf("Entrer le id de la reclamation: ");
    scanf("%d", &id);
    getchar();
    for (int i = 0; i < reclamations_count; i++)
    {
        if (reclamations[i].id == id)
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
    time_t now = time(NULL);
    
    double diff_in_seconds = difftime(now, reclamations[index].added_time);

    if (diff_in_seconds > 86400 || strcmp(reclamations[index].statut, "En cours") != 0)
    {

        printf("La reclamation a plus de 24 heures et ne peut pas etre modifiee!\n");
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
    if(strstr(reclamations[index].description, "help") || strstr(reclamations[index].description, "urgent") || strstr(reclamations[index].description, "sos"))
    {
        strcpy(reclamations[index].priorite, "haute");
    }
    else if (strstr(reclamations[index].description, "aide") || strstr(reclamations[index].description, "problem") || strstr(reclamations[index].description, "casse"))
    {
        strcpy(reclamations[index].priorite, "moyenne");
    }
    else{

        strcpy(reclamations[index].priorite, "basse");
    }
    printf("Reclamation a ete modifier avec success!\n");

}

void supprimer_reclamation(Reclamation *reclamations)
{
    char title[50];
    int found = 0;
    int index;
    int id;
    printf("Entrer le id de la reclamation: ");
    scanf("%d", &id);
    getchar();
    if(reclamations_count == 0)
    {
        printf("no reclamation found!\n");
        return;
    }
    for (int i = 0; i < reclamations_count; i++)
    {
        if (reclamations[i].id == id)
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
    time_t now = time(NULL);
    
    double diff_in_seconds = difftime(now, reclamations[index].added_time);

    if (diff_in_seconds > 86400 || strcmp(reclamations[index].statut, "En cours") != 0)
    {

        printf("La reclamation a plus de 24 heures et ne peut pas être suprime!\n");
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
        if (strcmp(reclamations[i].user.user_name, utilisateurs[userindex].user_name) == 0)
        {
            printf("-------------------------------\n");
            printf("ID: %d\n", reclamations[i].id);
            printf("Titre: %s\n", reclamations[i].title);
            printf("Motif: %s\n", reclamations[i].motif);
            printf("Description: %s\n", reclamations[i].description);
            printf("Categorie: %s\n", reclamations[i].categorie);
            printf("Date: %s\n", reclamations[i].date);
            printf("Statut: %s\n", reclamations[i].statut);
            printf("Priorite: %s\n", reclamations[i].priorite);
            if (strlen(reclamations[i].comment) > 0)
            {
                printf("Commentaire: %s\n", reclamations[i].comment);
            }
            printf("-------------------------------\n");
        }
    }
}


/*
void assign_priority(Reclamation *reclamations) {
        for (int j = 0; j < reclamations_count; j++) {
            strcpy(reclamations[j].priorite, "basse");

            if (strstr(reclamations[j].priorite, "urgent") ||
                strstr(reclamations[j].priorite, "critical") ||
                strstr(reclamations[j].priorite, "immediate") ||
                strstr(reclamations[j].priorite, "high")) {
                    strcpy(reclamations[j].priorite, "haute");
                }

            else if (strstr(reclamations[j].priorite, "average") ||
                strstr(reclamations[j].priorite, "normal") ||
                strstr(reclamations[j].priorite, "moderate")) {
                    strcpy(reclamations[j].priorite, "moyenne");
                }
            else if (strstr(reclamations[j].priorite, "simple") ||
                strstr(reclamations[j].priorite, "low") ||
                strstr(reclamations[j].priorite, "easy")) {
                    strcpy(reclamations[j].priorite, "basse");
                }
        }
    }
    */

