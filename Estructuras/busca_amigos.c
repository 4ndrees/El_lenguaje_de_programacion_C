#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils_red_social.h"

int main() {
    SocialMedia sm = {NULL};
    char hobbies1[][MAXNAME] = {"cocinar", "leer", "viajar"};
    char hobbies2[][MAXNAME] = {"deportes", "cocinar", "musica"};
    char hobbies3[][MAXNAME] = {"viajar", "fotografia", "musica"};

    addUser(&sm, "Marta", hobbies1, 3);
    addUser(&sm, "Juan", hobbies2, 3);
    addUser(&sm, "Carlos", hobbies3, 3);


    char opt;
    while ((opt = parseUserAcction()) != 's'){
        switch (opt)
        {
        case 'a':
            printf("\nDar de alta usuario:\n");
            char *name;
            char hobbies[MAXHOBBIES][MAXNAME];
            int numHobbies;
            parseUserData(name, hobbies, &numHobbies);
            addUser(&sm, name, hobbies, numHobbies);
            break;
        case 'm':
            printf("\nRed Social:\n");
            printSocialMedia(&sm);
            break;
        case 'e':
            printf("\nEstadisticas de los hobbies:\n");
            printHobbiesStats(&sm);
            break;
        case 'b':
            printf("\nBuscar usuarios por hobbie:\n");
            char *hobbie;
            hobbie = parseHobbie();
            searchByHobbie(&sm, hobbie);
            break;
        }
        printf("\n");
    }

    return 0;
}
