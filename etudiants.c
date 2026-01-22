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
    char rep[10];
    char temp[100];
    
    // VIDER LE BUFFER DES LE DEBUT
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    do {
        if (*nb >= N) {
            printf("Nombre maximum d'etudiants atteint !\n");
            return;
        }

        printf("\n--- Etudiant %d ---\n", *nb + 1);
        
        printf("Matricule : ");
        fgets(T[*nb].matricule, 20, stdin);
        T[*nb].matricule[strcspn(T[*nb].matricule, "\n")] = '\0';

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

        (*nb)++;
        sauvegarderFichier(T, *nb);

        printf("\nAjouter un autre etudiant ? (o/n) : ");
        fgets(rep, sizeof(rep), stdin);
        rep[strcspn(rep, "\n")] = '\0';

    } while (rep[0] == 'o' || rep[0] == 'O');
}


// Procedure pour modifier un étudiant par bobboy
void modifierEtudiant(etudiant T[], int nb) {
    /* 
    Code de bobboy 
    */
}

// Procedure pour supprimer un étudiant par bobboy
void supprimerEtudiant(etudiant T[], int *nb) {
    /* 
    Code de bobboy 
    */
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