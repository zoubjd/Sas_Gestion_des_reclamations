#include "gestion.h"

/*les fcts de statistiques*/


int taux_reclamation(Reclamation *reclamations)
{
    int rec_resolue = 0;
    if (reclamations_count == 0)
    {
        printf("No reclamations found!\n");
        return 0;
    }
    for (int i = 0; i < reclamations_count; i++)
    {
        if (strcmp(reclamations[i].statut, "Resolu") == 0)
        {
            rec_resolue++;
        }
    }
    float taux = ((float) rec_resolue / reclamations_count) * 100;
    printf("Le nombre de reclamations est : %d\n", reclamations_count);
    printf("Le nombre de reclamations resolue est : %d\n", rec_resolue);
    printf("Le nombre de reclamations resolue est : %d\n", rec_resolue);
    printf("Le taux de resolution est : %f\n", taux);
    return 0;
}

int delay_moyen(Reclamation *Reclamation)
{
    int rec_traite = 0;
    double moy;
    if (reclamations_count == 0)
    {
        printf("No reclamations found!\n");
        return 0;
    }

    double sum = 0;
    for (int i = 0; i < reclamations_count; i++)
    {
        if (strcmp(Reclamation[i].statut, "Resolu") == 0)
        {
            sum += Reclamation[i].delay;
            rec_traite++;
        }
    }

    moy = (sum / rec_traite);
    printf("Le delay moyen de traite les reclamation est %.2f s\n", moy);

    return 0;
}


int rapport_journalier(Reclamation *reclamation)
{

    FILE *f = fopen("rapport_journalier.txt", "w");
    char date[11];
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    sprintf(date, "%04d-%02d-%02d", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday);
    if (reclamations_count == 0)
    {
        printf("No reclamations found!\n");
        return 0;
    }
    if (f == NULL)
    {
        printf("Error opening file!\n");
        return 0;
    }
    fprintf(f, "Rapport journalier des reclamations\n\n");
    for (int i = 0; i < reclamations_count; i++)
    {
        if (strcmp(reclamation[i].date, date) == 0)
        {
            fprintf(f, "-------------------------------\n");
            fprintf(f, "ID: %d\n", reclamation[i].id);
            fprintf(f, "l'auteur: %s\n", reclamation[i].user.user_name);
            fprintf(f, "Titre: %s\n", reclamation[i].title);
            fprintf(f, "Motif: %s\n", reclamation[i].motif);
            fprintf(f, "Description: %s\n", reclamation[i].description);
            fprintf(f, "Categorie: %s\n", reclamation[i].categorie);
            fprintf(f, "Date: %s\n", reclamation[i].date);
            fprintf(f, "Statut: %s\n", reclamation[i].statut);
            fprintf(f, "Priorite: %s\n", reclamation[i].priorite);
        if (strlen(reclamation[i].comment) > 0)
        {
            fprintf(f, "Commentaire: %s\n", reclamation[i].comment);
        }
        
        fprintf(f, "-------------------------------\n");
        }
    }
    fprintf(f, "les reclamations resolues: \n");

    for (int i = 0; i < reclamations_count; i++)
    {
        if (strcmp(reclamation[i].statut, "Resolu") == 0)
        {
        fprintf(f, "-------------------------------\n");
        fprintf(f, "ID: %d\n", reclamation[i].id);
        fprintf(f, "l'auteur: %s\n", reclamation[i].user.user_name);
        fprintf(f, "Titre: %s\n", reclamation[i].title);
        fprintf(f, "Motif: %s\n", reclamation[i].motif);
        fprintf(f, "Description: %s\n", reclamation[i].description);
        fprintf(f, "Categorie: %s\n", reclamation[i].categorie);
        fprintf(f, "Date: %s\n", reclamation[i].date);
        fprintf(f, "Statut: %s\n", reclamation[i].statut);
        fprintf(f, "Priorite: %s\n", reclamation[i].priorite);
        if (strlen(reclamation[i].comment) > 0)
        {
            fprintf(f, "Commentaire: %s\n", reclamation[i].comment);
        }
        fprintf(f, "-------------------------------\n");
        }
    }
    

    fclose(f);
    return 0;
}
