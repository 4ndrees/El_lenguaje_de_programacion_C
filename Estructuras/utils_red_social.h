#define MAXHOBBIES 10
#define MAXNAME 50

typedef struct tUser {
    char name[MAXNAME];
    char hobbies[MAXHOBBIES][MAXNAME];
    int numHobbies;
    struct tUser *links[MAXHOBBIES];
    int numLinks;
    struct tUser *next;
} User;

typedef struct {
    User *head;
} SocialMedia;

/* Create users utils */
User *createUser(char *name, char hobbies[][MAXNAME], int numHobbies);
void addUser(SocialMedia *sm, char *name, char hobbies[][MAXNAME], int numHobbies);
/* Social media utils */
void searchByHobbie(SocialMedia *sm, char *hobbie);
void printSocialMedia(SocialMedia *sm);
void printHobbiesStats(SocialMedia *sm);
/* Parse utils */
char parseUserAcction();
void parseUserData(char *name, char hobbies[][MAXNAME], int *numHobbies);
char *parseName();
char *parseHobbie();
/* Terminal utils */
void clearTerminal(char c);
char *parseString();