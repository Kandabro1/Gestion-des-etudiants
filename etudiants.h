#ifndef ETUDIANTS_H
#define ETUDIANTS_H
#include <stdio.h>

//Declaration des structures
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

typedef struct {
    char matricule[10];
    char nom[30];
    char prenom[30];
    Date date;
    char lieu[30];
    char departement[30];
    char filiere[30];
    char telephone[15];
} etudiant;


//Declaration des fonctions

void sauvegarderFichier(etudiant T[], int nb);

int gererNombreEtudiants();

void voirNombreEtudiants(int nb);

void enregistrerEtudiants(etudiant T[], int *nb, int N);

void modifierEtudiant(etudiant T[], int nb, int N); // Ajout de N pour la reecriture

void recherche(etudiant T[], int nb);

void supprimerEtudiant(etudiant T[], int *nb, int N); // Ajout de N pour la reecriture

void trierParNom(etudiant T[], int nb);

void trierParFiliere(etudiant T[], int nb);

void rechercheDichotomiqueParNom(etudiant T[], int nb);

void calculAge();

int chargerFichier(etudiant T[]);

void reecrireFichierComplet(etudiant T[], int nb, int N);

#endif