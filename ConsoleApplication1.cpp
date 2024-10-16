#include <stdio.h>
#include <stdlib.h>


float Calcul_Moyenne(float somme, int nombre) {
    return somme / nombre;
}

void tri(float tab[], char noms[][10], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (tab[j] > tab[j + 1]) {
                float temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;

                for (int k = 0; k < 10; k++) {
                    char tempChar = noms[j][k];
                    noms[j][k] = noms[j + 1][k];
                    noms[j + 1][k] = tempChar;
                }
            }
        }
    }
}

int main() {
    int size;
    float somme = 0;
    char noms[30][10];
    char choice;

    do{

        printf("========================================\n");
        printf("          Pronote version wish          \n");
        printf("========================================\n\n");

        // Récupère le nombre d'élèves

        do
        {
            printf("Nombre d'eleves (Min : 2 ; Max : 30) : ");
            scanf_s("%d", &size);
            if (size <= 0 || size > 30) {
                printf("Taille invalide, veuillez entrer un nombre entre 2 et 30.\n");
            }

        } while (size < 1);



        float* tab = (float*)malloc(size * sizeof(float));

        if (tab == NULL) {
            printf("Erreur d'allocation mémoire !\n");
            return 1;
        }

        // Récupère les noms

        for (int i = 0; i < size; i++) {
            printf("#%d Nom : ", i + 1);
            scanf_s("%9s", noms[i], (unsigned)_countof(noms[i]));
        }

        // Récupère les notes

        for (int i = 0; i < size; i++) {
            printf("#%d %s : ", i + 1, noms[i]);
            scanf_s("%f", &tab[i]);
            while (tab[i] < 0.0f) {
                printf("Erreur, la note ne peut se etre en dessou de 0\n");
                printf("#%d %s : ", i + 1, noms[i]);
                scanf_s("%f", &tab[i]);
            }
            somme += tab[i];
        }

        printf("\n========================================\n");
        printf("                Resultats                 \n");
        printf("========================================\n\n");

        printf("-----------------------\n");
        printf("| %-10s | %6s |\n", "Nom", "Note");
        printf("|------------|--------|\n");

        // Affiche les noms

        for (int i = 0; i < size; i++) {
            printf("| %-10s | %6.2f |\n", noms[i], tab[i]);
            printf("|------------|--------|\n");
        }
        printf("\nMoyenne de la classe : %.2f\n", Calcul_Moyenne(somme, size));

        printf("\n----------------------------------------\n");

        printf("\nNotes dans l'ordre croissant :\n\n");

        tri(tab, noms, size);

        printf("-----------------------\n");
        printf("| %-10s | %6s |\n", "Nom", "Note");
        printf("|------------|--------|\n");

        // Affiche les notes avec les noms

        for (int i = 0; i < size; i++) {
            printf("| %-10s | %6.2f |\n", noms[i], tab[i]);
            printf("-----------------------\n");
        }

        printf("\n----------------------------------------\n");

        // Affiche les notes dans l'ordre croissant

        if (size > 0) {
            printf("\nNote la plus basse : \n");
            printf("\n-----------------------\n");
            printf("| %-10s | %6.2f |\n", noms[0], tab[0]);
            printf("-----------------------\n");
            printf("\nNote la plus haute : \n");
            printf("\n-----------------------\n");
            printf("| %-10s | %6.2f |\n", noms[size - 1], tab[size - 1]);
            printf("-----------------------\n");
        }
        else {
            printf("Aucune note disponible.\n");
        }

        // Libère la mémoire

        free(tab);

        printf("\nAppuyer sur 'c' pour continuer ou 'q' pour quitter : ");

        while (getchar() != '\n');
        choice = getchar();

    } while (choice != 'q');

    printf_s("========================================\n");
    printf_s("                  Bye                   \n");
    printf_s("========================================\n");

    return 0;
}
