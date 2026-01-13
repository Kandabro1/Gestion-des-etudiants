#include <stdio.h>
#include <string.h>
#include "etudiants.h"


// Procedure pour gérer le nombre d'étudiants par Alhadj
int gererNombreEtudiants(){
    FILE *f;
    char ligne[100];
    int N;
    int trouve = 0;

    f = fopen("etudiants.txt", "r");

    if (f != NULL){
        while (fgets(ligne, sizeof(ligne), f) != NULL){
            if (strstr(ligne, "Nombre d'etudiants a gerer") != NULL){
                // Message trouvé
                printf("%s", ligne);
                trouve = 1;
                break;
            }
        }
        fclose(f);
    }

    // Si le message n'existe pas, on demande la taille
    if (!trouve){
        printf("Entrez le nombre d'etudiants : ");
        scanf("%d", &N);

        f = fopen("etudiants.txt", "w");

        if (f == NULL)
        {
            printf("Erreur : impossible d'ouvrir le fichier.\n");
            return;
        }

        fprintf(f, "Nombre d'etudiants a gerer : %d\n", N);

        fclose(f);
    }
}



// Procedure pour sauvegarder les etudiants dans un fichier par Alhadj
void sauvegarderFichier(etudiant T[], int nb){
    FILE *f;
    int i = nb - 1;

    f = fopen("etudiants.txt", "a");
    if (f == NULL)
    {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    fprintf(f, "========== ETUDIANT %d ==========\n", nb);
    fprintf(f, "Matricule : %s\n", T[i].matricule);
    fprintf(f, "Nom : %s\n", T[i].nom);
    fprintf(f, "Prenom : %s\n", T[i].prenom);
    fprintf(f, "Date de naissance : %d/%d/%d\n",
            T[i].date.jour,
            T[i].date.mois,
            T[i].date.annee);
    fprintf(f, "Lieu de naissance : %s\n", T[i].lieu);
    fprintf(f, "Departement : %s\n", T[i].departement);
    fprintf(f, "Filiere : %s\n", T[i].filiere);
    fprintf(f, "Telephone : %s\n", T[i].telephone);
    fprintf(f, "==============================\n");

    fclose(f);
}


// Fonction pour lire le nombre d'étudiants enregistrés dans le fichier par Alhadj
int lireNbEtudiants(){
    FILE *f;
    char ligne[100];
    int nb = 0;
    int temp;

    f = fopen("etudiants.txt", "r");
    if (f == NULL)
        return 0;

    while (fgets(ligne, sizeof(ligne), f)){
        if (sscanf(ligne, "Nombre d'etudiants enregistres : %d", &temp) == 1){
            nb = temp; 
        }
    }

    fclose(f);
    return nb;
}

// Procedure pour sauvegarder le nombre d'étudiants à la fin du fichier par Alhadj
void sauvegarderNbEtudiants(int nb){
    FILE *f = fopen("etudiants.txt", "a");
    if (f == NULL) return;

    fprintf(f, "\nNombre d'etudiants enregistres : %d\n", nb);
    fclose(f);
}

//Procedure pour Afficher le nombre d'étudiants par Alhadj
int voirNombreEtudiants(int nb){
    printf("\nNombre d'etudiants enregistres : %d\n", nb);
    return nb;
}

// Procedure pour enregistrer les étudiants par Aman
void enregistrerEtudiants(etudiant T[], int *nb, int N) {
    /* 
    Code d'Aman
    */
}

// Procedure pour modifier un étudiant par bobboy
int chercherEtudiant(Etudiant e[], int n, int matricule) {
    for (int i = 0; i < n; i++) {
        if (e[i].matricule == matricule)
            return i;
    }
    return -1;
}


void modifierEtudiant(etudiant T[], int nb) {
    int mat, pos;
    printf("\nEntrer le matricule de l'etudiant a modifier: ");
    scanf("%d", &mat);

    pos = chercherEtudiant(T, nb, mat);

    if (pos == -1) {
        printf("Etudiant non trouve !");
    } else {
        printf("Nom : ");
        scanf("%29s", T[i].nom);

        printf("Prenom : ");
        scanf("%29s", T[i].prenom);

        printf("Date de naissance (jour mois annee) : ");
        scanf("%d %d %d",
                &T[i].date.jour,
                &T[i].date.mois,
                &T[i].date.annee);

        printf("Lieu de naissance : ");
        scanf("%29s", T[i].lieu);

        printf("Departement : ");
        scanf("%29s", T[i].departement);

        printf("Filiere : ");
        scanf("%29s", T[i].filiere);

        printf("Telephone : ");
        scanf("%14s", T[i].telephone);

        sauvegarderFichier(T, nb);

        printf("Modification reussie !\n");
        break;
    }
}

// Procedure pour supprimer un étudiant par bobboy
void supprimerEtudiant(etudiant T[], int *nb) {
    int mat, pos;
    printf("\nEntrer le matricule de l'etudiant a supprimer: ");
    scanf("%d", &mat);

    pos = chercherEtudiant(T, *nb, mat);

    if (pos == -1) {
        printf("Etudiant non trouve !");
    } else {
        for (int i = pos; i < *n - 1; i++) {
            T[i] = T[i + 1];
        }
        (*nb)--;
        sauvegarderNbEtudiants(*nb);
        printf("Etudiant supprime avec succes !");
        sauvegarderFichier(T, *nb);
    }
}

//Procedure pour trier les étudiants par nom par Tedikus
void trierParNom(etudiant T[], int nb){
    /* 
    Code de Tedikus 
    */
}

//Procedure pour trier les étudiants par filiere par Tedikus
void trierParFilere(etudiant T[], int nb){
    /* 
    Code de Tedikus 
    */
}

// Procedure pour la Recherche par matricule par Movitch
void recherche(etudiant T[], int nb) {
    /* 
    Code de Movitch
    */
}

// Procedure Recherche dichotomique par nom
void rechercheDichotomiqueParNom(etudiant T[], int nb) {
    /* 
    Code de Movitch
    */
}

// Procedure pour calculer l'age par Alhadj
void calculAge() {
    int jourA, moisA, anneeA;
    int jourN, moisN, anneeN;
    int age;
    
    printf("Entrez la date actuelle (jour mois annee) : ");
    scanf("%d %d %d", &jourA, &moisA, &anneeA);
    
    printf("Entrez la date de naissance (jour mois annee) : ");
    scanf("%d %d %d", &jourN, &moisN, &anneeN);
    
    age = anneeA - anneeN;
    
    printf("Vous avez : %d ans\n", age);
}