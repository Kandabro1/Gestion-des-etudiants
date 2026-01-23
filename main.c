#include <stdio.h>
#include <stdlib.h>
#include "etudiants.h"

int main() {
    etudiant *T = NULL;
    int N = 0, nb = 0, choix;

    // 1. Récupérer la taille N (soit dans le fichier, soit par saisie)
    N = gererNombreEtudiants();

    // 2. Allouer la mémoire dynamiquement pour le tableau T
    T = (etudiant*) malloc(N * sizeof(etudiant));
    if (T == NULL) {
        printf("Erreur critique : Impossible d'allouer la memoire !\n");
        return 1;
    }

    // 3. Charger les données existantes depuis le fichier vers la RAM
    nb = chargerFichier(T);
    if (nb > 0) {
        printf("[%d etudiants charges avec succes depuis le fichier]\n", nb);
    } else {
        printf("[Aucun etudiant precedent trouve, base de donnee vide]\n");
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
