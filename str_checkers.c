#include "gestion.h"

int check_email(char *email)
{
    int size = strlen(email);
    for (int i = 0; i < size; i++)
    {
        if (email[i] == '@')
        {
            for (int j = i + 2; j < size; j++)
            {
                if (email[j] == '.' && j < size - 1)
                {
                    return 1;
                }
            }
        }
    }
    return 0;

}


int mdp_check(char *mdp, char *user_name)
{
    int count = 0;
    int size = strlen(mdp);
    if (size <= 8)
    {
        return 0;
    }
    if(strstr(mdp, user_name))
    {
        return 0;
    }

    for (int i = 0; i < size; i++)
    {
        if(isupper(mdp[i])){
            count++;
            break;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if(islower(mdp[i])){
            count++;
            break;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if(isdigit(mdp[i])){
            count++;
            break;
        }
    }
    for (int i = 0; i < size; i++)
    {
        if(ispunct(mdp[i])){
            count++;
            break;
        }
    }

    if(count == 4)
        return 1;
    else
        return 0;
}

int id_generation(Reclamation *reclamations)
{
    int randnum = (rand() % 9);
    int id = 0, count = 0, valid_id = 0;
    do
    {
    valid_id = 1;
    while (count < 10)
    {
        id = id * 10 + randnum;
        count++;
    }
    for (int i = 0; i < reclamations_count; i++)
    {
        if (id == reclamations[i].id)
        {
            valid_id = 0;
        }
    }
    } while (valid_id != 1);
    
    

    return id;
}


void assign_priority(Reclamation *reclamations)
{
    for (int j = 0; j < reclamations_count; j++)
    {
        strcpy(reclamations[j].priorite, "basse");
        if (strstr(reclamations[j].priorite, "urgent") || strstr(reclamations[j].priorite, "critical") || strstr(reclamations[j].priorite, "immediate") || strstr(reclamations[j].priorite, "high"))
        {
            strcpy(reclamations[j].priorite, "haute");
        }
        else if (strstr(reclamations[j].priorite, "average") || strstr(reclamations[j].priorite, "normal") || strstr(reclamations[j].priorite, "moderate"))
        {
            strcpy(reclamations[j].priorite, "moyenne");
        }
        else
        {
            strcpy(reclamations[j].priorite, "basse");
        }
    }
}
