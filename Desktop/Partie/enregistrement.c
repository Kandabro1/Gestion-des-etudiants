
#include <stdio.h>
#define MAX_ETUDIANTS 100
// Définition de la structure pour la date
typedef struct {
    int jour;
    int mois;
    int annee;
}  Date;

// Définition de la structure principale pour l'etudiant
typedef struct {
    char matricule[10];
    char nom[50];
    char prenom[50];
    Date date_naissance; // Utilisation de la structure Date
    char sexe[10];
    char departement[50];
    char filiere[50];
    char region_origine[50];
} Gestion_des_Etudiants;

// Constante pour la taille maximale du tableau

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

    return 0;   // ← OBLIGATOIRE pour main
}