#include "gestion.h"

/*les fcts des admines*/


int modifier_role(Utilisateur *utilisateurs)
{
    char user_name[50];
    char new_role[10];
    int i, index = 0;
    printf("Entrer le nom d'utilisateur de l'utilisateur a modifier: ");
    fgets(user_name, 50, stdin);
    for (i = 0; i < users_count; i++)
    {
        if (strcmp(user_name, utilisateurs[i].user_name) == 0)
        {
            index = i;
            printf("User found!\n");
            printf("Entrer le nouveau role: ");
            fgets(new_role, 10, stdin);
            new_role[strcspn(new_role, "\n")] = '\0';
           if (strcmp(new_role, "admin") == 0 || strcmp(new_role, "agent") == 0 || strcmp(new_role, "user") == 0) {
                strcpy(utilisateurs[index].role, new_role);
                printf("Role updated!\n");
            } else {
                printf("Invalid role! Role not updated.\n");
            }

        }
    }

    printf("User not found!\n");
    return 1;
}


void affichage_adgent_reclamation(Reclamation *reclamations)
{

    for (int i = 0; i < reclamations_count; i++)
    {
                    printf("-------------------------------\n");
                    printf("ID: %d\n", reclamations[i].id);
                    printf("l'auteur: %s\n", reclamations[i].user.user_name);
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


void modistatut(Reclamation *Reclamations)
{
    int id, found = 0, index;
    char nv_statut[10];
    char comment[50];
    printf("Entrer le id de la reclamation a modifier: ");
    scanf("%d", &id);
    getchar();


    for (int i = 0; i < reclamations_count; i++)
    {
        if (Reclamations[i].id == id)
        {
            found = 1;
            index = i;
            break;
        }
    }
    if (found == 0)
    {
        printf("Reclamation not found\n");
        return;
    }


    do
    {
        printf("Entrer le nouveau statut ou appuyez sur Entrer pour passer:\n");
        fgets(nv_statut, sizeof(nv_statut), stdin);


        nv_statut[strcspn(nv_statut, "\n")] = '\0';


        if (strlen(nv_statut) == 0)
        {
            break;
        }
    } while ((strcmp(nv_statut, "En cours") != 0) && (strcmp(nv_statut, "Resolu") != 0) && (strcmp(nv_statut, "Rejete") != 0));


    if (strlen(nv_statut) > 0)
    {
        strcpy(Reclamations[index].statut, nv_statut);
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        Reclamations[index].treated_time = t;

        Reclamations[index].delay = difftime(t, Reclamations[index].added_time);

    }

    printf("Entrer un commentaire ou appuyez sur Entrer:\n");
    fgets(comment, sizeof(comment), stdin);


    if (strlen(comment) > 1)
    {
        comment[strcspn(comment, "\n")] = '\0'; 
        strcpy(Reclamations[index].comment, comment);
    }
}



int recherche(Reclamation *reclamations)
{
    int choice;
    int valide;
    char choice2;
    do
    {
    valide = 0;
    printf("Avec quoi voullez vous rechercher?\n");
    printf("1. ID\n");
    printf("2. username\n");
    printf("3. Categorie\n");
    printf("4. Date\n");
    printf("5. Statut\n");
    scanf("%d", &choice);
    getchar();
    switch (choice)
    {
    case 1:
    {
        int id;
        printf("Entrer l'id de la reclamation:\n");
        scanf("%d", &id);
        getchar();
        for (int i = 0; i < reclamations_count; i++)
        {
            if (reclamations[i].id == id)
            {
                    printf("-------------------------------\n");
                    printf("ID: %d\n", reclamations[i].id);
                    printf("l'auteur: %s\n", reclamations[i].user.user_name);
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
        break;
    }
    case 2:
    {
        char username[50];
        printf("Entrer le username de l'utilisateur:\n");
        scanf("%s", username);
        getchar();
        for (int i = 0; i < reclamations_count; i++)
        {
            if(strcmp(reclamations[i].user.user_name, username) == 0)
            {
                    printf("-------------------------------\n");
                    printf("ID: %d\n", reclamations[i].id);
                    printf("l'auteur: %s\n", reclamations[i].user.user_name);
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
        break;
    }
    case 3:
    {
        char category[50];
        printf("Entrer la categorie de la reclamation:\n");
        fgets(category, 50, stdin);
        for (int i = 0; i < reclamations_count; i++)
        {
            if(strcmp(reclamations[i].categorie, category) == 0)
            {
                    printf("-------------------------------\n");
                    printf("ID: %d\n", reclamations[i].id);
                    printf("l'auteur: %s\n", reclamations[i].user.user_name);
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

        break;
    }
    case 4:
    {
        
        char date[11];
        printf("Entrer la date de la reclamation en format YYYY-MM-DD:\n");
        fgets(date, 11, stdin);
        date[strcspn(date, "\n")] = '\0';
        for (int i = 0; i < reclamations_count; i++)
        {
            if (strcmp(reclamations[i].date, date) == 0)
            {
                    printf("-------------------------------\n");
                    printf("ID: %d\n", reclamations[i].id);
                    printf("l'auteur: %s\n", reclamations[i].user.user_name);
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
        

        break;
    }
    case 5:
        {
            char statut[10];
            printf("Entrer le statut a rechercher\n");
            fgets(statut, 10, stdin);
            statut[strcspn(statut, "\n")] = '\0';
            for (int i = 0; i < reclamations_count; i++)
            {
                if (strcmp(reclamations[i].statut, statut) == 0)
                {
                    printf("-------------------------------\n");
                    printf("ID: %d\n", reclamations[i].id);
                    printf("l'auteur: %s\n", reclamations[i].user.user_name);
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
            

        break;
        }
    default:
    printf("Invalid choice\n");
        break;
}
    printf("Voulez-vous faire une autre recherche?\n n pour quitter\n");
    scanf("%c", &choice2);
    } while (choice2 != 'n');
    
return 0;
    
}

void display_by_priority(Reclamation *reclamations, const char *priority) {
    for (int i = 0; i < reclamations_count; i++) {
        if (strcmp(reclamations[i].priorite, priority) == 0) {
            printf("-------------------------------\n");
            printf("ID: %d\n", reclamations[i].id);
            printf("l'auteur: %s\n", reclamations[i].user.user_name);
            printf("Titre: %s\n", reclamations[i].title);
            printf("Motif: %s\n", reclamations[i].motif);
            printf("Description: %s\n", reclamations[i].description);
            printf("Categorie: %s\n", reclamations[i].categorie);
            printf("Date: %s\n", reclamations[i].date);
            printf("Statut: %s\n", reclamations[i].statut);
            printf("Priorite: %s\n", reclamations[i].priorite);
            if (strlen(reclamations[i].comment) > 0) {
                printf("Commentaire: %s\n", reclamations[i].comment);
            }
            printf("-------------------------------\n");
        }
    }
}

void aficher_rec_parprio(Reclamation *reclamations) {
    const char *priorities[] = {"haute", "moyenne", "basse"};
    for (int i = 0; i < 3; i++) {
        display_by_priority(reclamations, priorities[i]);
    }
}

void modifier_adgent_reclamation(Reclamation *reclamations)
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

void supprimer_adgent_reclamation(Reclamation *reclamations)
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
    

    for (int i = index; i < reclamations_count - 1; i++)
    {
        reclamations[i] = reclamations[i + 1];
    }
    reclamations_count--;
    printf("Reclamation deleted!\n");
}


