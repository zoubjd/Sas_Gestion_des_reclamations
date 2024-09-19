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
            do
            {
               strcpy(utilisateurs[index].role, new_role);
                printf("Role updated!\n");
                return 0;
            } while (strcmp(new_role, "admin") != 0 && strcmp(new_role, "agent") != 0 && strcmp(new_role, "user") != 0);

            break;
        }
    }

    printf("User not found!\n");
    return 1;
}
