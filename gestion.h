// declarations
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>
#include <unistd.h>

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
    char comment[50];
    char priorite[10];
    time_t added_time;
    time_t treated_time;
    double delay;
} Reclamation;
extern int users_count;
extern int reclamations_count;

//functions

int inscription(Utilisateur *utilisateurs);
int connexion(Utilisateur *utilisateurs);

//checkers
int check_email(char *email);
int mdp_check(char *mdp, char *user_name);
int id_generation(Reclamation *reclamations);
void assign_priority(Reclamation *reclamations);

//menues
int admin_menu(Utilisateur *utilisateurs, Reclamation *Reclamation);
int user_menu(int userindex, Utilisateur *utilisateurs, Reclamation *reclamations);
int agent_menu(int userindex, Utilisateur *utilisateurs, Reclamation *reclamations);

// fcts des admin
int modifier_role(Utilisateur *utilisateurs);
void affichage_adgent_reclamation(Reclamation *reclamations);
void modistatut(Reclamation *Reclamations);
int recherche(Reclamation *reclamations);
int taux_reclamation(Reclamation *reclamations);
int delay_moyen(Reclamation *Reclamation);
int rapport_journalier(Reclamation *reclamation);
void aficher_rec_parprio(Reclamation * reclamations);


// fcts de client
int ajouter_reclamation(Reclamation *reclamations, Utilisateur *utilisateurs, int userindex);
void modifier_reclamation(Reclamation *reclamations, Utilisateur *utilisateurs, int userindex);
void affichage_reclamation(Reclamation *reclamations, Utilisateur *utilisateurs, int userindex);
void supprimer_reclamation(Reclamation *reclamations);

