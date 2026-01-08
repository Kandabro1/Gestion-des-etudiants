#include <stdio.h>
#include <stdlib.h>
#include "etudiants.h"

int main() {
    int N;      // nombre maximum d'étudiants
    int nb, choix;     // nombre déjà enregistrés
    etudiant *T;

    // Demande N ou lit depuis le fichier
    N = gererNombreEtudiants();

    // Allocation dynamique
    T = malloc(N * sizeof(etudiant));

    nb = lireNbEtudiants();
    if (T == NULL)
    {
        printf("Erreur d'allocation memoire.\n");
        return 1;
    }

    do {
        printf("\n=== MENU ===\n");
        printf("Veuillez choisir une option pour continuer:\n");
        printf("1. Enregistrer les etudiants\n");
        printf("2. Modifier un etudiant\n");
        printf("3. Supprimer un etudiant\n");
        printf("4. Recherche par nom\n");
        printf("5. Trier par odre alphabetique\n");
        printf("6. Trier par filiere\n");
        printf("7. Recherche dichotomoique\n");
        printf("8. Calculer age\n");
        printf("0. Quitter\n");

        printf("Quel est votre Choix (0-10) : ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                enregistrerEtudiants(T, &nb, N);
                break;
            case 2:
                modifierEtudiant(T, nb);
                break;
            case 3:
                supprimerEtudiant(T, &nb);
                break;
            case 4:
                recherche(T, nb);
                break;
            case 5:
                trierParNom(T, nb);
                break;
            case 6:
                trierParFiliere(T, nb);
                break;
            case 7:
                rechercheDichotomiqueParNom(T, nb);
                break;
            case 8:
                calculAge();
                break;
            case 0:
                printf("Fin du programme.\n");
                break;
            default:
                printf("Choix invalide !\n");
        }

    } while (choix != 0);

    free(T);
    return 0;
}
