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
void saisir_etudiant(Gestion_des_Etudiants *liste, int *nb_actuel) {
    // Validation 1 : Vérification de la capacité maximale du tableau
    if (*nb_actuel >= MAX_ETUDIANTS) {
        printf("Erreur : La liste est pleine. Impossible d'ajouter un nouvel etudiant.\n");
        return;
        }

    printf("\n--- Saisie d'un nouvel etudiant ---\n");

    // Saisie du Matricule avec validation de taille (max 10 caracteres pour un tableau de 10)
    printf("Matricule (max 10 caracteres) : ");
    scanf("%9s", liste[*nb_actuel].matricule);
    while (getchar() != '\n'); // Nettoyage du buffer

    // Saisie du Nom avec validation de taille (max 49 caracteres pour un tableau de 50)
    printf("Nom : ");
    scanf("%49s", liste[*nb_actuel].nom);
    while (getchar() != '\n'); // Nettoyage du buffer

    printf("Prenom : ");
    scanf("%49s", liste[*nb_actuel].prenom);
    while (getchar() != '\n');

    // Saisie de la Date de naissance (validation de type implicite avec %d)
    printf("Date de naissance (Jour/Mois/Annee, ex: 15/03/2000) : ");
    scanf("%d/%d/%d", &liste[*nb_actuel].date_naissance.jour,
                      &liste[*nb_actuel].date_naissance.mois,
                      &liste[*nb_actuel].date_naissance.annee);
                      while (getchar() != '\n');

    // ... (saisie des autres champs avec la même logique de validation de taille)

    printf("Sexe : ");
    scanf("%9s", liste[*nb_actuel].sexe);
    while (getchar() != '\n');

    printf("Departement : ");
    scanf("%49s", liste[*nb_actuel].departement);
    while (getchar() != '\n');

    printf("Filiere : ");
    scanf("%49s", liste[*nb_actuel].filiere);
    while (getchar() != '\n');

    printf("Region d'origine : ");
    scanf("%49s", liste[*nb_actuel].region_origine);
    while (getchar() != '\n');

    // Mise à jour du compteur d'etudiants
    (*nb_actuel)++;
    printf("Etudiant enregistrer avec succes a l'index %d.\n", *nb_actuel - 1);
}
// Fonction principale
int main(void) {
    Gestion_des_Etudiants etudiants[MAX_ETUDIANTS];
    int nb_actuel = 0;

    saisir_etudiant(etudiants, &nb_actuel);

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