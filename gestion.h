// declarations
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_UTILISATEURS 100

typedef struct {
    char nom[50];
    char prenom[50];
    char user_name[50];
    char email[50];
    char mdp[50];
    char role[10];

}Utilisateur;
typedef struct {
    int id;
    Utilisateur user;
    char title[50];
    char motif[100];
    char description[200];
    char categorie[50];
    char statut[10];
    char date[11];
    
} Reclamation;
int users_count = 0;
int reclamations_count = 0;

//functions

int inscription(Utilisateur *utilisateurs);
int connexion(Utilisateur *utilisateurs);

//checkers
int check_email(char *email);
int mdp_check(char *mdp, char *user_name);
int id_generation(Reclamation *reclamations);

// fcts des admin
int modifier_role(Utilisateur *utilisateurs);

// fcts de client
int ajouter_reclamation(Reclamation *reclamations, Utilisateur *utilisateurs, int users_index);
void modifier_reclamation(Reclamation *reclamations, Utilisateur *utilisateurs, int userindex);
