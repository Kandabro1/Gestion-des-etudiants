/* Fonction pour comparer sans majuscules */
int comparer_noms(char *nom1, char *nom2) {
    int i = 0;
    
    while (nom1[i] && nom2[i]) {
        char c1 = nom1[i];
        char c2 = nom2[i];
        
        /* Met en minuscule */
        if (c1 >= 'A' && c1 <= 'Z') c1 = c1 + 32;
        if (c2 >= 'A' && c2 <= 'Z') c2 = c2 + 32;
        
        if (c1 != c2) return c1 - c2;
        i++;
    }
    return 0;
}

/* Tri par nom */
void trier_par_nom() {
    if (nombreEtudiants == 0) {
        printf("Pas d'etudiants\n");
        return;
    }
    
    int i, j;
    for (i = 0; i < nombreEtudiants - 1; i++) {
        for (j = i + 1; j < nombreEtudiants; j++) {
            if (comparer_noms(listeEtudiants[j].nom, listeEtudiants[i].nom) < 0) {
                /* Echange */
                Etudiant temp = listeEtudiants[i];
                listeEtudiants[i] = listeEtudiants[j];
                listeEtudiants[j] = temp;
            }
        }
    }
    printf("Tri par nom fait\n");
}

/* Tri par filiere */
void trier_par_filiere() {
    if (nombreEtudiants == 0) {
        printf("Pas d'etudiants\n");
        return;
    }
    
    int i, j;
    for (i = 0; i < nombreEtudiants - 1; i++) {
        for (j = i + 1; j < nombreEtudiants; j++) {
            if (comparer_noms(listeEtudiants[j].filiere, listeEtudiants[i].filiere) < 0) {
                /* Echange */
                Etudiant temp = listeEtudiants[i];
                listeEtudiants[i] = listeEtudiants[j];
                listeEtudiants[j] = temp;
            }
        }
    }
    printf("Tri par filiere fait\n");
}

/* Tri par matricule (pour recherche dichotomique) */
void trier_par_matricule() {
    if (nombreEtudiants == 0) {
        printf("Pas d'etudiants\n");
        return;
    }
    
    int i, j, change;
    for (i = 0; i < nombreEtudiants - 1; i++) {
        change = 0;
        for (j = 0; j < nombreEtudiants - i - 1; j++) {
            if (strcmp(listeEtudiants[j].matricule, listeEtudiants[j + 1].matricule) > 0) {
                Etudiant temp = listeEtudiants[j];
                listeEtudiants[j] = listeEtudiants[j + 1];
                listeEtudiants[j + 1] = temp;
                change = 1;
            }
        }
        if (!change) break;
    }
    printf("Tri par matricule fait\n");
}