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
void modifierEtudiant(etudiant T[], int nb, int N) {
    char mat[20], temp[100];
    int i, trouve = 0, c;

    printf("Matricule de l'etudiant a modifier : ");
    scanf("%s", mat);
    
    // Nettoyage du buffer après le scanf
    while ((c = getchar()) != '\n' && c != EOF);

    for (i = 0; i < nb; i++) {
        if (strcmp(T[i].matricule, mat) == 0) {
            trouve = 1;
            printf("\n--- Modification de l'etudiant %s ---\n", mat);
            
            printf("Nouveau Nom : ");
            fgets(T[i].nom, 30, stdin);
            T[i].nom[strcspn(T[i].nom, "\n")] = '\0';

            printf("Nouveau Prenom : ");
            fgets(T[i].prenom, 30, stdin);
            T[i].prenom[strcspn(T[i].prenom, "\n")] = '\0';

            printf("Nouvelle Date de naissance (j m a) : ");
            fgets(temp, sizeof(temp), stdin);
            sscanf(temp, "%d %d %d", &T[i].date.jour, &T[i].date.mois, &T[i].date.annee);

            printf("Nouveau Lieu de naissance : ");
            fgets(T[i].lieu, 30, stdin);
            T[i].lieu[strcspn(T[i].lieu, "\n")] = '\0';

            printf("Nouveau Departement : ");
            fgets(T[i].departement, 30, stdin);
            T[i].departement[strcspn(T[i].departement, "\n")] = '\0';

            printf("Nouvelle Filiere : ");
            fgets(T[i].filiere, 30, stdin);
            T[i].filiere[strcspn(T[i].filiere, "\n")] = '\0';

            printf("Nouveau Telephone : ");
            fgets(T[i].telephone, 15, stdin);
            T[i].telephone[strcspn(T[i].telephone, "\n")] = '\0';

            reecrireFichierComplet(T, nb, N);
            printf("\nModification enregistree avec succes dans le fichier.\n");
            break;
        }
    }
    if (!trouve) printf("Aucun etudiant trouve avec le matricule %s.\n", mat);
}

// Procedure pour supprimer un étudiant par bobboy
void supprimerEtudiant(etudiant T[], int *nb, int N) {
    char mat[20];
    int i, j, trouve = 0;
    printf("Matricule de l'etudiant a supprimer : ");
    scanf("%s", mat);
    for (i = 0; i < *nb; i++) {
        if (strcmp(T[i].matricule, mat) == 0) {
            trouve = 1;
            for (j = i; j < *nb - 1; j++) T[j] = T[j+1];
            (*nb)--;
            reecrireFichierComplet(T, *nb, N);
            printf("Suppression effectuee.\n");
            break;
        }
    }
    if (!trouve) printf("Etudiant non trouve.\n");
}

//Procedure pour trier les étudiants par nom par Tedikus
void trierParNom(etudiant T[], int nb){
    etudiant temp;
    for (int i = 0; i < nb - 1; i++) {
        for (int j = i + 1; j < nb; j++) {
            if (strcmp(T[i].nom, T[j].nom) > 0) {
                temp = T[i]; T[i] = T[j]; T[j] = temp;
            }
        }
    }
    printf("Tri par nom termine.\n");
}


//Procedure pour trier les étudiants par filiere par Tedikus
void trierParFilere(etudiant T[], int nb){
     etudiant temp;
    for (int i = 0; i < nb - 1; i++) {
        for (int j = i + 1; j < nb; j++) {
            if (strcmp(T[i].filiere, T[j].filiere) > 0) {
                temp = T[i]; T[i] = T[j]; T[j] = temp;
            }
        }
    }
    printf("Tri par filiere termine.\n");
}

// Procedure pour la Recherche par matricule par Amadou
void recherche(etudiant T[], int nb) {
    char mat[30];
    int i, trouve = 0;
    
    printf ("matricule a rechercher");
    scanf("%s", mat);
    for (i=0; i<nb; i++){

        if (strcmp(T[i].matricule, mat) ==0){
            printf ("trouve: %s %s\n", T[i].nom, T[i].prenom);
            trouve=1;
        }
    }
 if(!trouve) printf("aucun resultat.\n");
}


// Procedure Recherche dichotomique par nom Amadou
void recherchedichotomiqueparnom(etudiant T[], int nb){
    char nom[30];
    int bas=0, haut=nb-1, mil, trouve=0;
    trierparnom(T, nb);
    printf("nom a rechercher (dichotomie):");
    scanf("%s", nom);
    
    while (bas <= haut){
        mil=(bas+haut)/2;

        if (strcmp(T[mil].nom, nom)==0){
            printf("trouve : %s %s\n",T[mil].nom, T[mil].prenom);
            trouve=1;
            break;
        }
        if (strcmp(T[mil].nom, nom) < 0) bas=mil+1;
        else haut=mil-1; 
    }
    if (!trouve) printf("non trouve.\n");

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
