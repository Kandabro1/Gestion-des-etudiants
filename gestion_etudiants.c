#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Définition de la structure pour la date
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

// Définition de la structure principale pour l'etudiant
// Le nom de la structure est "Gestion_des_Etudiants" comme demandé.
typedef struct {
    char matricule[10];
    char nom[50];
    char prenom[50];
    Date date_naissance;
    char sexe[10];
    char departement[50];
    char filiere[50];
    char region_origine[50];
} Gestion_des_Etudiants;

// Constante pour la taille maximale du tableau (pour simplifier pour un novice)
#define MAX_ETUDIANTS 100

// Déclaration des fonctions
void afficher_menu();
void saisir_etudiant(Gestion_des_Etudiants *liste, int *nb_actuel);
void afficher_liste(const Gestion_des_Etudiants *liste, int nb_actuel);
int rechercher_matricule(const Gestion_des_Etudiants *liste, int nb_actuel, const char *matricule_recherche);
void modifier_etudiant(Gestion_des_Etudiants *etudiant_a_modifier); // Utilise un pointeur comme demandé
void supprimer_etudiant(Gestion_des_Etudiants *liste, int *nb_actuel, int index_a_supprimer);
void trier_alphabetique(Gestion_des_Etudiants *liste, int nb_actuel);
void trier_filiere(Gestion_des_Etudiants *liste, int nb_actuel);
int calculer_age(Date date_naissance);
int rechercher_dichotomique(const Gestion_des_Etudiants *liste, int nb_actuel, const char *nom_recherche);

// Fonction principale
int main() {
    // Initialisation du tableau d'etudiants et du compteur
    Gestion_des_Etudiants liste_etudiants[MAX_ETUDIANTS];
    int nb_etudiants_actuel = 0;
    int choix;
    char matricule_recherche[10];
    int index_trouve;
    char nom_recherche[50];

    // Demander le nombre d'etudiants à la première ouverture (capacité max)
    // Nous utilisons MAX_ETUDIANTS comme capacité maximale fixe pour simplifier.
    printf("--- Programme de Gestion des Etudiants ---\n");
    printf("Capacité maximale de la liste : %d etudiants.\n", MAX_ETUDIANTS);

    do {
        afficher_menu();
        printf("Entrez votre choix : ");
        // Utilisation de scanf pour lire le choix
        if (scanf("%d", &choix) != 1) {
            // Gestion d'erreur si l'utilisateur entre autre chose qu'un nombre
            printf("Erreur de saisie. Veuillez entrer un nombre.\n");
            while (getchar() != '\n'); // Nettoyer le buffer d'entrée
            choix = 0; // Réinitialiser le choix pour continuer la boucle
            continue;
        }
        while (getchar() != '\n'); // Nettoyer le buffer d'entrée après scanf

        switch (choix) {
            case 1: // Enregistrer
                saisir_etudiant(liste_etudiants, &nb_etudiants_actuel);
                break;
            case 2: // Modifier
                if (nb_etudiants_actuel == 0) {
                    printf("La liste est vide. Veuillez enregistrer un etudiant d'abord.\n");
                    break;
                }
                printf("Entrez la matricule de l'etudiant a modifier : ");
                scanf("%s", matricule_recherche);
                while (getchar() != '\n');
                index_trouve = rechercher_matricule(liste_etudiants, nb_etudiants_actuel, matricule_recherche);
                if (index_trouve != -1) {
                    // Passage de l'adresse de la structure a modifier (pointeur)
                    modifier_etudiant(&liste_etudiants[index_trouve]);
                } else {
                    printf("Aucun etudiant trouve avec la matricule %s.\n", matricule_recherche);
                }
                break;
            case 3: // Rechercher (matricule)
                if (nb_etudiants_actuel == 0) {
                    printf("La liste est vide.\n");
                    break;
                }
                printf("Entrez la matricule de l'etudiant a rechercher : ");
                scanf("%s", matricule_recherche);
                while (getchar() != '\n');
                index_trouve = rechercher_matricule(liste_etudiants, nb_etudiants_actuel, matricule_recherche);
                if (index_trouve != -1) {
                    printf("\n--- Etudiant trouve ---\n");
                    // Afficher l'etudiant trouve
                    printf("Matricule: %s, Nom: %s, Prenom: %s, Date de Naissance: %d/%d/%d, Sexe: %s, Departement: %s, Filiere: %s, Region: %s\n",
                           liste_etudiants[index_trouve].matricule,
                           liste_etudiants[index_trouve].nom,
                           liste_etudiants[index_trouve].prenom,
                           liste_etudiants[index_trouve].date_naissance.jour,
                           liste_etudiants[index_trouve].date_naissance.mois,
                           liste_etudiants[index_trouve].date_naissance.annee,
                           liste_etudiants[index_trouve].sexe,
                           liste_etudiants[index_trouve].departement,
                           liste_etudiants[index_trouve].filiere,
                           liste_etudiants[index_trouve].region_origine);
                    printf("----------------------\n");
                } else {
                    printf("Aucun etudiant trouve avec la matricule %s.\n", matricule_recherche);
                }
                break;
            case 4: // Supprimer
                if (nb_etudiants_actuel == 0) {
                    printf("La liste est vide. Rien a supprimer.\n");
                    break;
                }
                printf("Entrez la matricule de l'etudiant a supprimer : ");
                scanf("%s", matricule_recherche);
                while (getchar() != '\n');
                index_trouve = rechercher_matricule(liste_etudiants, nb_etudiants_actuel, matricule_recherche);
                if (index_trouve != -1) {
                    supprimer_etudiant(liste_etudiants, &nb_etudiants_actuel, index_trouve);
                } else {
                    printf("Aucun etudiant trouve avec la matricule %s.\n", matricule_recherche);
                }
                break;
            case 5: // Trier par ordre Alphabétique (Nom)
                trier_alphabetique(liste_etudiants, nb_etudiants_actuel);
                printf("Liste triee par ordre alphabetique (Nom).\n");
                break;
            case 6: // Rechercher par Dichotomique (Nom)
                if (nb_etudiants_actuel == 0) {
                    printf("La liste est vide.\n");
                    break;
                }
                // La recherche dichotomique nécessite que la liste soit triee.
                trier_alphabetique(liste_etudiants, nb_etudiants_actuel);
                printf("La liste a ete triee par Nom pour la recherche dichotomique.\n");
                printf("Entrez le Nom de l'etudiant a rechercher : ");
                scanf("%s", nom_recherche);
                while (getchar() != '\n');
                index_trouve = rechercher_dichotomique(liste_etudiants, nb_etudiants_actuel, nom_recherche);
                if (index_trouve != -1) {
                    printf("\n--- Etudiant trouve par recherche dichotomique ---\n");
                    // Afficher l'etudiant trouve
                    printf("Matricule: %s, Nom: %s, Prenom: %s, Date de Naissance: %d/%d/%d, Sexe: %s, Departement: %s, Filiere: %s, Region: %s\n",
                           liste_etudiants[index_trouve].matricule,
                           liste_etudiants[index_trouve].nom,
                           liste_etudiants[index_trouve].prenom,
                           liste_etudiants[index_trouve].date_naissance.jour,
                           liste_etudiants[index_trouve].date_naissance.mois,
                           liste_etudiants[index_trouve].date_naissance.annee,
                           liste_etudiants[index_trouve].sexe,
                           liste_etudiants[index_trouve].departement,
                           liste_etudiants[index_trouve].filiere,
                           liste_etudiants[index_trouve].region_origine);
                    printf("------------------------------------------------\n");
                } else {
                    printf("Aucun etudiant trouve avec le Nom %s.\n", nom_recherche);
                }
                break;
            case 7: // Calculer Age etudiant
                if (nb_etudiants_actuel == 0) {
                    printf("La liste est vide.\n");
                    break;
                }
                printf("Entrez la matricule de l'etudiant pour calculer l'age : ");
                scanf("%s", matricule_recherche);
                while (getchar() != '\n');
                index_trouve = rechercher_matricule(liste_etudiants, nb_etudiants_actuel, matricule_recherche);
                if (index_trouve != -1) {
                    int age = calculer_age(liste_etudiants[index_trouve].date_naissance);
                    printf("L'age de l'etudiant %s %s (Matricule: %s) est de %d ans.\n",
                           liste_etudiants[index_trouve].prenom,
                           liste_etudiants[index_trouve].nom,
                           liste_etudiants[index_trouve].matricule,
                           age);
                } else {
                    printf("Aucun etudiant trouve avec la matricule %s.\n", matricule_recherche);
                }
                break;
            case 8: // Trier par Filiere
                trier_filiere(liste_etudiants, nb_etudiants_actuel);
                printf("Liste trier par Filiere.\n");
                break;
            case 9: // Afficher la liste des etudiants
                afficher_liste(liste_etudiants, nb_etudiants_actuel);
                break;
            case 0: // Quitter
                printf("Fin du programme. Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
        printf("\n"); // Ligne vide pour la lisibilité
    } while (choix != 0);

    return 0;
}

// Implémentation des fonctions

/**
 * @brief Affiche le menu des options disponibles.
 */
void afficher_menu() {
    printf("\n============================================\n");
    printf("               MENU PRINCIPAL               \n");
    printf("============================================\n");
    printf("1- Enregistrer un etudiant\n");
    printf("2- Modifier les informations d'un etudiant\n");
    printf("3- Rechercher un etudiant (par matricule)\n");
    printf("4- Supprimer un etudiant\n");
    printf("5- Trier la liste par ordre Alphabetique (Nom)\n");
    printf("6- Rechercher par Dichotomique (Nom)\n");
    printf("7- Calculer l'Age d'un etudiant\n");
    printf("8- Trier la liste par Filiere\n");
    printf("9- Afficher la liste des etudiants\n");
    printf("0- Quitter\n");
    printf("--------------------------------------------\n");
}

/**
 * @brief Saisit les informations d'un nouvel etudiant et l'ajoute à la liste.
 * @param liste Pointeur vers le tableau de structures.
 * @param nb_actuel Pointeur vers le nombre actuel d'etudiants.
 */
void saisir_etudiant(Gestion_des_Etudiants *liste, int *nb_actuel) {
    if (*nb_actuel >= MAX_ETUDIANTS) {
        printf("Erreur : La liste est pleine. Impossible d'ajouter un nouvel etudiant.\n");
        return;
    }

    printf("\n--- Saisie d'un nouvel etudiant ---\n");

    // Utilisation de scanf pour la simplicité, mais fgets est souvent préférable pour les chaînes
    printf("Matricule (max 10 caracteres) : ");
    scanf("%9s", liste[*nb_actuel].matricule);
    while (getchar() != '\n');

    printf("Nom : ");
    scanf("%49s", liste[*nb_actuel].nom);
    while (getchar() != '\n');

    printf("Prenom : ");
    scanf("%49s", liste[*nb_actuel].prenom);
    while (getchar() != '\n');

    printf("Date de naissance (Jour Mois Annee, ex: 15 03 2000) : ");
    scanf("%d %d %d", &liste[*nb_actuel].date_naissance.jour,
                      &liste[*nb_actuel].date_naissance.mois,
                      &liste[*nb_actuel].date_naissance.annee);
    while (getchar() != '\n');

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

    // Incrémenter le nombre d'etudiants
    (*nb_actuel)++;
    printf("Etudiant enregistrer avec succes a l'index %d.\n", *nb_actuel - 1);
}

/**
 * @brief Affiche la liste de tous les etudiants enregistrés.
 * @param liste Pointeur constant vers le tableau de structures.
 * @param nb_actuel Nombre actuel d'etudiants.
 */
void afficher_liste(const Gestion_des_Etudiants *liste, int nb_actuel) {
    if (nb_actuel == 0) {
        printf("La liste des etudiants est vide.\n");
        return;
    }

    printf("\n============================================\n");
    printf("          LISTE DES %d ÉTUDIANTS           \n", nb_actuel);
    printf("============================================\n");

    for (int i = 0; i < nb_actuel; i++) {
        printf("Index %d | Matricule: %s, Nom: %s, Prenom: %s, Date Naissance: %d/%d/%d, Sexe: %s, Departement: %s, Filiere: %s, Region: %s\n",
               i,
               liste[i].matricule,
               liste[i].nom,
               liste[i].prenom,
               liste[i].date_naissance.jour,
               liste[i].date_naissance.mois,
               liste[i].date_naissance.annee,
               liste[i].sexe,
               liste[i].departement,
               liste[i].filiere,
               liste[i].region_origine);
    }
    printf("============================================\n");
}

/**
 * @brief Recherche un etudiant par sa matricule.
 * @param liste Pointeur constant vers le tableau de structures.
 * @param nb_actuel Nombre actuel d'etudiants.
 * @param matricule_recherche La matricule à trouver.
 * @return L'index de l'etudiant trouve, ou -1 si non trouve.
 */
int rechercher_matricule(const Gestion_des_Etudiants *liste, int nb_actuel, const char *matricule_recherche) {
    for (int i = 0; i < nb_actuel; i++) {
        if (strcmp(liste[i].matricule, matricule_recherche) == 0) {
            return i; // Retourne l'index
        }
    }
    return -1; // Non trouve
}

/**
 * @brief Modifie les informations d'un etudiant.
 *
 * Cette fonction utilise un POINTEUR vers la structure de l'etudiant
 * pour modifier directement les données en mémoire, comme demandé.
 *
 * @param etudiant_a_modifier Pointeur vers la structure de l'etudiant a modifier.
 */
void modifier_etudiant(Gestion_des_Etudiants *etudiant_a_modifier) {
    int choix_champ;
    char nouvelle_valeur[50];

    printf("\n--- Modification de l'etudiant %s %s ---\n", etudiant_a_modifier->prenom, etudiant_a_modifier->nom);
    printf("Quel champ voulez-vous modifier ?\n");
    printf("1- Nom\n2- Prenom\n3- Date de naissance\n4- Sexe\n5- Departement\n6- Filiere\n7- Region d'origine\n0- Annuler\n");
    printf("Entrez votre choix : ");

    if (scanf("%d", &choix_champ) != 1) {
        printf("Erreur de saisie. Annulation de la modification.\n");
        while (getchar() != '\n');
        return;
    }
    while (getchar() != '\n');

    if (choix_champ == 0) {
        printf("Modification annulee.\n");
        return;
    }

    switch (choix_champ) {
        case 1:
            printf("Nouveau Nom : ");
            scanf("%49s", nouvelle_valeur);
            while (getchar() != '\n');
            strcpy(etudiant_a_modifier->nom, nouvelle_valeur);
            break;
        case 2:
            printf("Nouveau Prenom : ");
            scanf("%49s", nouvelle_valeur);
            while (getchar() != '\n');
            strcpy(etudiant_a_modifier->prenom, nouvelle_valeur);
            break;
        case 3:
            printf("Nouvelle Date de naissance (Jour Mois Annee, ex: 15 03 2000) : ");
            scanf("%d %d %d", &etudiant_a_modifier->date_naissance.jour,
                              &etudiant_a_modifier->date_naissance.mois,
                              &etudiant_a_modifier->date_naissance.annee);
            while (getchar() != '\n');
            break;
        case 4:
            printf("Nouveau Sexe : ");
            scanf("%9s", nouvelle_valeur);
            while (getchar() != '\n');
            strcpy(etudiant_a_modifier->sexe, nouvelle_valeur);
            break;
        case 5:
            printf("Nouveau Departement : ");
            scanf("%49s", nouvelle_valeur);
            while (getchar() != '\n');
            strcpy(etudiant_a_modifier->departement, nouvelle_valeur);
            break;
        case 6:
            printf("Nouvelle Filiere : ");
            scanf("%49s", nouvelle_valeur);
            while (getchar() != '\n');
            strcpy(etudiant_a_modifier->filiere, nouvelle_valeur);
            break;
        case 7:
            printf("Nouvelle Region d'origine : ");
            scanf("%49s", nouvelle_valeur);
            while (getchar() != '\n');
            strcpy(etudiant_a_modifier->region_origine, nouvelle_valeur);
            break;
        default:
            printf("Choix invalide.\n");
            return;
    }
    printf("Information modifiee avec succes.\n");
}

/**
 * @brief Supprime un etudiant de la liste à un index donné.
 * @param liste Pointeur vers le tableau de structures.
 * @param nb_actuel Pointeur vers le nombre actuel d'etudiants.
 * @param index_a_supprimer L'index de l'etudiant a supprimer.
 */
void supprimer_etudiant(Gestion_des_Etudiants *liste, int *nb_actuel, int index_a_supprimer) {
    if (index_a_supprimer < 0 || index_a_supprimer >= *nb_actuel) {
        printf("Erreur : Index de suppression invalide.\n");
        return;
    }

    // Décaler tous les éléments après l'index de suppression d'une position vers la gauche
    for (int i = index_a_supprimer; i < *nb_actuel - 1; i++) {
        liste[i] = liste[i + 1];
    }

    // Décrémenter le nombre d'etudiants
    (*nb_actuel)--;
    printf("Etudiant supprime avec succes.\n");
}

/**
 * @brief Trie la liste des etudiants par ordre alphabetique de Nom (Tri par sélection).
 * @param liste Pointeur vers le tableau de structures.
 * @param nb_actuel Nombre actuel d'etudiants.
 */
void trier_alphabetique(Gestion_des_Etudiants *liste, int nb_actuel) {
    if (nb_actuel <= 1) return;

    Gestion_des_Etudiants temp;
    for (int i = 0; i < nb_actuel - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < nb_actuel; j++) {
            // Utilisation de strcmp pour comparer les chaînes de caractères
            if (strcmp(liste[j].nom, liste[min_idx].nom) < 0) {
                min_idx = j;
            }
        }
        // Échange des structures
        if (min_idx != i) {
            temp = liste[i];
            liste[i] = liste[min_idx];
            liste[min_idx] = temp;
        }
    }
}

/**
 * @brief Trie la liste des etudiants par Filiere (Tri par sélection).
 * @param liste Pointeur vers le tableau de structures.
 * @param nb_actuel Nombre actuel d'etudiants.
 */
void trier_filiere(Gestion_des_Etudiants *liste, int nb_actuel) {
    if (nb_actuel <= 1) return;

    Gestion_des_Etudiants temp;
    for (int i = 0; i < nb_actuel - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < nb_actuel; j++) {
            // Comparaison par Filiere
            if (strcmp(liste[j].filiere, liste[min_idx].filiere) < 0) {
                min_idx = j;
            }
        }
        // Échange des structures
        if (min_idx != i) {
            temp = liste[i];
            liste[i] = liste[min_idx];
            liste[min_idx] = temp;
        }
    }
}
/**
 * @brief Calcule l'age d'un etudiant à partir de sa date de naissance.
 * @param date_naissance La date de naissance de l'etudiant.
 * @return L'age de l'etudiant en années.
 */
int calculer_age(Date date_naissance) {
    // Obtenir la date actuelle
    time_t t = time(NULL);
    struct tm *tm_actuel = localtime(&t);

    int annee_actuelle = tm_actuel->tm_year + 1900;
    int mois_actuel = tm_actuel->tm_mon + 1;
    int jour_actuel = tm_actuel->tm_mday;

    int age = annee_actuelle - date_naissance.annee;

    // Ajuster l'age si l'anniversaire n'est pas encore passé cette année
    if (mois_actuel < date_naissance.mois || (mois_actuel == date_naissance.mois && jour_actuel < date_naissance.jour)) {
        age--;
    }

    return age;
}

/**
 * @brief Recherche un etudiant par Nom en utilisant la recherche dichotomique.
 *
 * ATTENTION : Cette fonction suppose que la liste est déjà triee par Nom.
 *
 * @param liste Pointeur constant vers le tableau de structures.
 * @param nb_actuel Nombre actuel d'etudiants.
 * @param nom_recherche Le Nom à trouver.
 * @return L'index de l'etudiant trouve, ou -1 si non trouve.
 */
 int rechercher_dichotomique(const Gestion_des_Etudiants *liste, int nb_actuel, const char *nom_recherche) {
    int debut = 0;
    int fin = nb_actuel - 1;
    int milieu;

    while (debut <= fin) {
        milieu = debut + (fin - debut) / 2;
        int comparaison = strcmp(liste[milieu].nom, nom_recherche);

        if (comparaison == 0) {
            return milieu; // Trouvé
        } else if (comparaison < 0) {
            debut = milieu + 1; // Le nom recherché est plus grand, chercher dans la moitié supérieure
        } else {
            fin = milieu - 1; // Le nom recherché est plus petit, chercher dans la moitié inférieure
        }
    }

    return -1; // Non trouve
}
