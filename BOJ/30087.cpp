#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    while (N--) {
        char seminar[23];
        scanf("%s", seminar);

        if (strcmp(seminar, "Algorithm") == 0) {
            printf("204\n");
            continue;
        }

        if (strcmp(seminar, "DataAnalysis") == 0) {
            printf("207\n");
            continue;
        }

        if (strcmp(seminar, "ArtificialIntelligence") == 0) {
            printf("302\n");
            continue;
        }

        if (strcmp(seminar, "CyberSecurity") == 0) {
            printf("B101\n");
            continue;
        }

        if (strcmp(seminar, "Network") == 0) {
            printf("303\n");
            continue;
        }

        if (strcmp(seminar, "Startup") == 0) {
            printf("501\n");
            continue;
        }

        if (strcmp(seminar, "TestStrategy") == 0) {
            printf("105\n");
            continue;
        }
    }

    return 0;
}
