#include <stdio.h>
#include <string.h>
#include "etudiants.h"

// Procedure pour Charger les étudiants par Alhadj
int chargerFichier(etudiant T[]) {
    FILE *f = fopen("etudiants.txt", "r");
    int nb = 0;
    char ligne[200];

    if (f == NULL) return 0;

    if (fgets(ligne, sizeof(ligne), f) == NULL) {
        fclose(f);
        return 0;
    }

    while (fgets(ligne, sizeof(ligne), f) != NULL) {
        if (strstr(ligne, "========== ETUDIANT") != NULL) {
            fscanf(f, "Matricule : %[^\n]\n", T[nb].matricule);
            fscanf(f, "Nom : %[^\n]\n", T[nb].nom);
            fscanf(f, "Prenom : %[^\n]\n", T[nb].prenom);
            fscanf(f, "Date de naissance : %d/%d/%d\n", 
                    &T[nb].date.jour, &T[nb].date.mois, &T[nb].date.annee);
            fscanf(f, "Lieu de naissance : %[^\n]\n", T[nb].lieu);
            fscanf(f, "Departement : %[^\n]\n", T[nb].departement);
            fscanf(f, "Filiere : %[^\n]\n", T[nb].filiere);
            fscanf(f, "Telephone : %[^\n]\n", T[nb].telephone);
            fgets(ligne, sizeof(ligne), f); 
            fgets(ligne, sizeof(ligne), f);
            nb++;
        }
    }
    fclose(f);
    return nb;
}


// Procedure pour Charger les étudiants par Alhadj
void reecrireFichierComplet(etudiant T[], int nb, int N) {
    FILE *f = fopen("etudiants.txt", "w");
    if (f == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }
    fprintf(f, "Nombre d'etudiants a gerer : %d\n", N);
    for (int i = 0; i < nb; i++) {
        fprintf(f, "========== ETUDIANT %d ==========\n", i + 1);
        fprintf(f, "Matricule : %s\n", T[i].matricule);
        fprintf(f, "Nom : %s\n", T[i].nom);
        fprintf(f, "Prenom : %s\n", T[i].prenom);
        fprintf(f, "Date de naissance : %d/%d/%d\n",
                T[i].date.jour, T[i].date.mois, T[i].date.annee);
        fprintf(f, "Lieu de naissance : %s\n", T[i].lieu);
        fprintf(f, "Departement : %s\n", T[i].departement);
        fprintf(f, "Filiere : %s\n", T[i].filiere);
        fprintf(f, "Telephone : %s\n", T[i].telephone);
        fprintf(f, "==============================\n\n");
    }
    fclose(f);
}

// Procedure pour gérer le nombre d'étudiants par Alhadj
int gererNombreEtudiants(){
    FILE *f;
    char ligne[100];
    int N = 0;
    f = fopen("etudiants.txt", "r");
    if (f != NULL) {
        while (fgets(ligne, sizeof(ligne), f) != NULL) {
            if (sscanf(ligne, "Nombre d'etudiants a gerer : %d", &N) == 1) break;
        }
        fclose(f);
    }
    if (N <= 0) {
        printf("Entrez le nombre d'etudiants a gerer : ");
        scanf("%d", &N);
        f = fopen("etudiants.txt", "w");
        if (f != NULL) {
            fprintf(f, "Nombre d'etudiants a gerer : %d\n", N);
            fclose(f);
        }
    }
    return N;
}



// Procedure pour sauvegarder les etudiants dans un fichier par Alhadj
void sauvegarderFichier(etudiant T[], int nb){
    FILE *f = fopen("etudiants.txt", "a");
    if (f == NULL) return;
    int i = nb - 1;
    fprintf(f, "========== ETUDIANT %d ==========\n", nb);
    fprintf(f, "Matricule : %s\n", T[i].matricule);
    fprintf(f, "Nom : %s\n", T[i].nom);
    fprintf(f, "Prenom : %s\n", T[i].prenom);
    fprintf(f, "Date de naissance : %d/%d/%d\n",
            T[i].date.jour, T[i].date.mois, T[i].date.annee);
    fprintf(f, "Lieu de naissance : %s\n", T[i].lieu);
    fprintf(f, "Departement : %s\n", T[i].departement);
    fprintf(f, "Filiere : %s\n", T[i].filiere);
    fprintf(f, "Telephone : %s\n", T[i].telephone);
    fprintf(f, "==============================\n\n");
    fclose(f);
}

void voirNombreEtudiants(int nb) {
    printf("\n===Total des etudiants enregistres : %d===\n", nb);
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
        fgets(T[*nb].nom, 30, stdin);
        T[*nb].nom[strcspn(T[*nb].nom, "\n")] = '\0';

        printf("Prenom : ");
        fgets(T[*nb].prenom, 30, stdin);
        T[*nb].prenom[strcspn(T[*nb].prenom, "\n")] = '\0';

        printf("Date de naissance (jour mois annee) : ");
        fgets(temp, sizeof(temp), stdin);
        sscanf(temp, "%d %d %d",
            &T[*nb].date.jour,
            &T[*nb].date.mois,
            &T[*nb].date.annee);

        printf("Lieu de naissance : ");
        fgets(T[*nb].lieu, 30, stdin);
        T[*nb].lieu[strcspn(T[*nb].lieu, "\n")] = '\0';

        printf("Departement : ");
        fgets(T[*nb].departement, 30, stdin);
        T[*nb].departement[strcspn(T[*nb].departement, "\n")] = '\0';

        printf("Filiere : ");
        fgets(T[*nb].filiere, 30, stdin);
        T[*nb].filiere[strcspn(T[*nb].filiere, "\n")] = '\0';

        printf("Telephone : ");
        fgets(T[*nb].telephone, 15, stdin);
        T[*nb].telephone[strcspn(T[*nb].telephone, "\n")] = '\0';

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