#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "utils_red_social.h"

/* Create users utils */
User *createUser(char *name, char hobbies[][MAXNAME], int numHobbies){
    User *newUser = (User *)malloc(sizeof(User));
    strcpy(newUser->name, name);
    strcpy(newUser->name, name);
    newUser->numHobbies = numHobbies;
    newUser->numLinks = 0;
    newUser->next = NULL;
    for (int i = 0; i < numHobbies; i++) {
        strcpy(newUser->hobbies[i], hobbies[i]);
    }
    return newUser;
}

void addUser(SocialMedia *sm, char *name, char hobbies[][MAXNAME], int numHobbies){
    User *newUser = createUser(name, hobbies, numHobbies);
    newUser->next = sm->head;
    sm->head = newUser;

    // Conectar con otros perfiles con aficiones en común
    User *currentUser = sm->head->next;
    while (currentUser) {
        for (int i = 0; i < numHobbies; i++) {
            for (int j = 0; j < currentUser->numHobbies; j++) {
                if (strcmp(newUser->hobbies[i], currentUser->hobbies[j]) == 0) {
                    newUser->links[newUser->numLinks++] = currentUser;
                    currentUser->links[currentUser->numLinks++] = newUser;
                    break;
                }
            }
        }
        currentUser = currentUser->next;
    }
}

/* Social media utils */
void searchByHobbie(SocialMedia *sm, char *hobbie){
    User *currentUser = sm->head;
    printf("Perfiles que comparten '%s':\n", hobbie);
    while (currentUser) {
        for (int i = 0; i < currentUser->numHobbies; i++) {
            if (strcmp(currentUser->hobbies[i], hobbie) == 0) {
                printf("%s\n", currentUser->name);
                break;
            }
        }
        currentUser = currentUser->next;
    }
}

void printSocialMedia(SocialMedia *sm){
    User *currentUser = sm->head;
    while (currentUser) {
        printf("%s -> [", currentUser->name);
        for (int i = 0; i < currentUser->numLinks; i++) {
            printf("%s%s", currentUser->links[i]->name, i == currentUser->numLinks - 1 ? "" : ", ");
        }
        printf("]\n");
        currentUser = currentUser->next;
    }
}

void printHobbiesStats(SocialMedia *sm){
    char hobbies[MAXHOBBIES][MAXNAME];
    int count[MAXHOBBIES] = {0};
    int numHobbies = 0;

    User *currentUser = sm->head;
    while (currentUser) {
        for (int i = 0; i < currentUser->numHobbies; i++) {
            int found = 0;
            for (int j = 0; j < numHobbies; j++) {
                if (strcmp(hobbies[j], currentUser->hobbies[i]) == 0) {
                    count[j]++;
                    found = 1;
                    break;
                }
            }
            if (!found && numHobbies < MAXHOBBIES) {
                strcpy(hobbies[numHobbies], currentUser->hobbies[i]);
                count[numHobbies] = 1;
                numHobbies++;
            }
        }
        currentUser = currentUser->next;
    }

    for (int i = 0; i < numHobbies; i++) {
        printf("%s: %d usuarios\n", hobbies[i], count[i]);
    }
}

/* Parse utils */
char parseUserAcction(){
    char opt, c;
    while(1){
        printf("Que quieres hacer (a: incluir usuario, m: mostrar red social, e: estadisticas hobbies, b: buscar por aficion, s: salir)");
        opt = getchar(); c = getchar();
        if ((opt == 'a' || opt == 'm'  || opt == 'e' || opt == 'b' || opt == 's') && c == '\n')
            break;
        else{
            clearTerminal(c);
            printf("No existe la accion que has introducido\n");
        }
    }
    return opt;
}

void parseUserData(char *name, char hobbies[][MAXNAME], int *numHobbies){
    strcpy(name, parseName());
    *numHobbies = 0;
    char opt;
    while(*numHobbies < 3){
        printf("Introduce un hobbie: ");
        char *hobbie = parseString();  
        strcpy(hobbies[*numHobbies], hobbie);
        *numHobbies = *numHobbies + 1;
    }
}

char *parseName(){
    printf("Introduce el nombre de usuario: ");
    return parseString();
}

char *parseHobbie(){
    printf("Introduce la el hobbie que quieres buscar: ");
    return parseString();
}

/* Terminal utils */
void clearTerminal(char c){
    while(c!='\n')c=getchar();
}

char *parseString(){
    int len = 0;
    char c;
    char *str = malloc(MAXNAME);

    while((c = getchar()) != '\n' && len++ < MAXNAME)
        str[len - 1] = c;
    str[len] = '\0';

    return str;
}