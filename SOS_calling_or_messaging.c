#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_USERS 100
#define MAX_INTEREST_LEN 50
#define MAX_PASSWORD_LEN 20
#define MAX_NAME_LEN 50
#define ALPHABET_SIZE 26

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
    int userId; // Index of the user in the 'users' array
} TrieNode;

TrieNode* root = NULL;

typedef struct {
    char name[MAX_NAME_LEN];
    char password[MAX_PASSWORD_LEN];
    char music[MAX_INTEREST_LEN];
    char occupation[MAX_INTEREST_LEN];
    char fitness[MAX_INTEREST_LEN];
    char language[MAX_INTEREST_LEN];
    char communicationStyle[MAX_INTEREST_LEN];
    char sleepingHabits[MAX_INTEREST_LEN];
    char lookingFor[MAX_INTEREST_LEN];
    char sosContactName[MAX_NAME_LEN];
    char sosContactNumber[MAX_INTEREST_LEN];
    char gender;
    int age;
    bool isRegistered;
} UserProfile;

UserProfile users[MAX_USERS];
int userCount = 0;

TrieNode* createTrieNode() {
    TrieNode* newNode = (TrieNode*)malloc(sizeof(TrieNode));
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        newNode->children[i] = NULL;
    }
    newNode->isEndOfWord = false;
    newNode->userId = -1; // Initialize userId to an invalid value
    return newNode;
}

void insertUserInTrie(TrieNode* root, const char* name, int userId) {
    TrieNode* current = root;
    for (int i = 0; i < strlen(name); i++) {
        int index = name[i] - 'a';
        if (!current->children[index]) {
            current->children[index] = createTrieNode();
        }
        current = current->children[index];
    }
    current->isEndOfWord = true;
    current->userId = userId;
}

int searchUserInTrie(TrieNode* root, const char* name) {
    TrieNode* current = root;
    for (int i = 0; i < strlen(name); i++) {
        int index = name[i] - 'a';
        if (!current->children[index]) {
            return -1; // User not found
        }
        current = current->children[index];
    }
    if (current != NULL && current->isEndOfWord) {
        return current->userId;
    }
    return -1; // User not found
}

void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached.\n");
        return;
    }

    UserProfile newUser;
    printf("Enter name: ");
    scanf("%s", newUser.name);
    printf("Enter password: ");
    scanf("%s", newUser.password);

    // Insert the user into the trie for efficient login
    insertUserInTrie(root, newUser.name, userCount);

    printf("Choose music genre:\n");
    printf("1. 90s Kid\n2. Jazz\n3. Pop\n4. Indie Rock\n5. Bollywood\n6. Electronic\n7. Indian Classical\n");

    int musicChoice;
    printf("Enter the number corresponding to your music choice: ");
    scanf("%d", &musicChoice);

    switch (musicChoice) {
        case 1:
            strcpy(newUser.music, "90s Kid");
            break;
        case 2:
            strcpy(newUser.music, "Jazz");
            break;
        case 3:
            strcpy(newUser.music, "Pop");
            break;
        case 4:
            strcpy(newUser.music, "Indie Rock");
            break;
        case 5:
            strcpy(newUser.music, "Bollywood");
            break;
        case 6:
            strcpy(newUser.music, "Electronic");
            break;
        case 7:
            strcpy(newUser.music, "Indian Classical");
            break;
        default:
            printf("Invalid choice. Setting music genre to 'Unknown'.\n");
            strcpy(newUser.music, "Unknown");
            break;
    }

    printf("Choose occupation:\n");
    printf("1. Engineering\n2. Doctor\n3. Student\n4. Business\n5. Government Employee\n6. Private Employee\n");

    int occupationChoice;
    printf("Enter the number corresponding to your occupation choice: ");
    scanf("%d", &occupationChoice);

    switch (occupationChoice) {
        case 1:
            strcpy(newUser.occupation, "Engineering");
            break;
        case 2:
            strcpy(newUser.occupation, "Doctor");
            break;
        case 3:
            strcpy(newUser.occupation, "Student");
            break;
        case 4:
            strcpy(newUser.occupation, "Business");
            break;
        case 5:
            strcpy(newUser.occupation, "Government Employee");
            break;
        case 6:
            strcpy(newUser.occupation, "Private Employee");
            break;
        default:
            printf("Invalid choice. Setting occupation to 'Unknown'.\n");
            strcpy(newUser.occupation, "Unknown");
            break;
    }

    printf("Choose fitness interest:\n");
    printf("1. Strength\n2. Zumba\n3. Dance\n4. Athletics\n5. Calisthenics\n");

    int fitnessChoice;
    printf("Enter the number corresponding to your fitness choice: ");
    scanf("%d", &fitnessChoice);

    switch (fitnessChoice) {
        case 1:
            strcpy(newUser.fitness, "Strength");
            break;
        case 2:
            strcpy(newUser.fitness, "Zumba");
            break;
        case 3:
            strcpy(newUser.fitness, "Dance");
            break;
        case 4:
            strcpy(newUser.fitness, "Athletics");
            break;
        case 5:
            strcpy(newUser.fitness, "Calisthenics");
            break;
        default:
            printf("Invalid choice. Setting fitness interest to 'Unknown'.\n");
            strcpy(newUser.fitness, "Unknown");
            break;
    }

    printf("Choose language preference:\n");
    printf("1. Kannada\n2. English\n3. Hindi\n4. Tamil\n5. Telugu\n6. Marathi\n7. Malayalam\n");

    int languageChoice;
    printf("Enter the number corresponding to your language choice: ");
    scanf("%d", &languageChoice);

    switch (languageChoice) {
        case 1:
            strcpy(newUser.language, "Kannada");
            break;
        case 2:
            strcpy(newUser.language, "English");
            break;
        case 3:
            strcpy(newUser.language, "Hindi");
            break;
        case 4:
            strcpy(newUser.language, "Tamil");
            break;
        case 5:
            strcpy(newUser.language, "Telugu");
            break;
        case 6:
            strcpy(newUser.language, "Marathi");
            break;
        case 7:
            strcpy(newUser.language, "Malayalam");
            break;
        default:
            printf("Invalid choice. Setting language preference to 'Unknown'.\n");
            strcpy(newUser.language, "Unknown");
            break;
    }

    printf("Choose communication style:\n");
    printf("1. I stay on WhatsApp all day\n2. Big time texter\n3. Phone caller\n");
    printf("4. Video chatter\n5. I'm slow to answer on WhatsApp\n6. Bad texter\n");
    printf("7. Better in person\n");

    int communicationStyleChoice;
    printf("Enter the number corresponding to your communication style choice: ");
    scanf("%d", &communicationStyleChoice);

    switch (communicationStyleChoice) {
        case 1:
            strcpy(newUser.communicationStyle, "I stay on WhatsApp all day");
            break;
        case 2:
            strcpy(newUser.communicationStyle, "Big time texter");
            break;
        case 3:
            strcpy(newUser.communicationStyle, "Phone caller");
            break;
        case 4:
            strcpy(newUser.communicationStyle, "Video chatter");
            break;
        case 5:
            strcpy(newUser.communicationStyle, "I'm slow to answer on WhatsApp");
            break;
        case 6:
            strcpy(newUser.communicationStyle, "Bad texter");
            break;
        case 7:
            strcpy(newUser.communicationStyle, "Better in person");
            break;
        default:
            printf("Invalid choice. Setting communication style to 'Unknown'.\n");
            strcpy(newUser.communicationStyle, "Unknown");
            break;
    }

    printf("Choose sleeping habits:\n");
    printf("1. Early bird\n2. Night owl\n3. In a spectrum\n");

    int sleepingHabitsChoice;
    printf("Enter the number corresponding to your choice: ");
    scanf("%d", &sleepingHabitsChoice);

    switch (sleepingHabitsChoice) {
        case 1:
            strcpy(newUser.sleepingHabits, "Early bird");
            break;
        case 2:
            strcpy(newUser.sleepingHabits, "Night owl");
            break;
        case 3:
            strcpy(newUser.sleepingHabits, "In a spectrum");
            break;
        default:
            printf("Invalid choice. Setting sleeping habits to 'Unknown'.\n");
            strcpy(newUser.sleepingHabits, "Unknown");
            break;
    }

    printf("Looking for:\n");
    printf("1. Long-term partner\n2. Long-term, open to short\n");
    printf("3. Short-term, open to long\n4. New friends\n");
    printf("5. Still figuring it out\n6. Short-term fun\n");

    int lookingForChoice;
    printf("Enter the number corresponding to your choice: ");
    scanf("%d", &lookingForChoice);

    switch (lookingForChoice) {
        case 1:
            strcpy(newUser.lookingFor, "Long-term partner");
            break;
        case 2:
            strcpy(newUser.lookingFor, "Long-term, open to short");
            break;
        case 3:
            strcpy(newUser.lookingFor, "Short-term, open to long");
            break;
        case 4:
            strcpy(newUser.lookingFor, "New friends");
            break;
        case 5:
            strcpy(newUser.lookingFor, "Still figuring it out");
            break;
        case 6:
            strcpy(newUser.lookingFor, "Short-term fun");
            break;
        default:
            printf("Invalid choice. Setting looking for to 'Still figuring it out'.\n");
            strcpy(newUser.lookingFor, "Still figuring it out");
            break;
    }

    printf("Enter SOS contact name: ");
    scanf("%s", newUser.sosContactName);

    printf("Enter SOS contact number: ");
    scanf("%s", newUser.sosContactNumber);


    printf("Enter gender[M/F]: ");
    scanf(" %c", &newUser.gender);  // Note the space before %c to consume newline character
    printf("Enter age: ");
    scanf("%d", &newUser.age);

    newUser.isRegistered = true;
    users[userCount++] = newUser;

    printf("User registered successfully!\n");
}

int loginUser() {
    char name[MAX_NAME_LEN], password[MAX_PASSWORD_LEN];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter password: ");
    scanf("%s", password);

    // Search for the user in the trie
    int userId = searchUserInTrie(root, name);

    if (userId != -1 && strcmp(users[userId].password, password) == 0) {
        return userId; // Login successful
    }

    return -1; // Login failed
}

void sendSOSMessage(const char* contactName, const char* contactNumber) {
    printf("Sending SOS message to %s (%s)...\n", contactName, contactNumber);
}

void makeSOSCall(const char* contactName, const char* contactNumber) {
    printf("Making SOS call to %s (%s)...\n", contactName, contactNumber);
}

void saveUserProfilesToFile(const char* userss) {
    // Implementation of saveUserProfilesToFile from the first code
    FILE* file = fopen(userss, "w");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    // Write user profiles to the file
    for (int i = 0; i < userCount; i++)
   //int i = userCount-1;
    {
        fprintf(file, "%s %s %s %s %s %s %s %s %s %c %d %d\n",
                users[i].name, users[i].password, users[i].music, users[i].occupation,
                users[i].fitness, users[i].language, users[i].communicationStyle,
                users[i].sleepingHabits, users[i].lookingFor, users[i].gender, users[i].age,
                users[i].isRegistered);


    }

    fclose(file);
}

void loadUserProfilesFromFile(const char* userss) {
    // Implementation of loadUserProfilesFromFile from the first code
     FILE* file = fopen(userss, "r");
    if (file == NULL) {
        printf("Error opening file for reading.\n");
        return;
    }

    char line[256]; // Adjust the size as needed

    // Read user profiles from the file
    while (fgets(line, sizeof(line), file) != NULL) {
        sscanf(line, "%s %s %s %s %s %s %s %s %s %c %d %d",
               users[userCount].name, users[userCount].password, users[userCount].music,
               users[userCount].occupation, users[userCount].fitness, users[userCount].language,
               users[userCount].communicationStyle, users[userCount].sleepingHabits,
               users[userCount].lookingFor, &users[userCount].gender, &users[userCount].age,
               &users[userCount].isRegistered);

        userCount++;
    }

    fclose(file);
}

int main() {

    root = createTrieNode(); // Initialize the trie root

 int choice, loggedInUser = -1;
 loadUserProfilesFromFile("userss.txt");

    while (1) {
        printf("\n1. Register\n2. Login\n3. Send SOS Message\n4. Make SOS Call\n5. Exit\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                saveUserProfilesToFile("userss.txt");
                break;
            case 2:
                loggedInUser = loginUser();
                if (loggedInUser != -1) {
                    printf("Login successful!\n");
                } else {
                    printf("Login failed!\n");
                }
                break;
            case 3:
                if (loggedInUser != -1) {
                    sendSOSMessage(users[loggedInUser].sosContactName, users[loggedInUser].sosContactNumber);
                } else {
                    printf("Please login first.\n");
                }
                break;
            case 4:
                if (loggedInUser != -1) {
                    makeSOSCall(users[loggedInUser].sosContactName, users[loggedInUser].sosContactNumber);
                } else {
                    printf("Please login first.\n");
                }
                break;
            case 5:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }


    return 0;
}

