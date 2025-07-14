#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_USERS 100
#define MAX_INTEREST_LEN 50
#define MAX_PASSWORD_LEN 20
#define MAX_NAME_LEN 50

// Struct to represent a virtual gift
typedef struct VirtualGift {
    char name[50];
    struct VirtualGift* next;
} VirtualGift;

// Struct to represent a user profile
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
    char gender;
    int age;
    bool isRegistered;
    VirtualGift* gifts; // Linked list of virtual gifts
} UserProfile;

// Global array of user profiles and user count
UserProfile users[MAX_USERS];
int userCount = 0;

// Function to register a new user
void registerUser() {
    if (userCount >= MAX_USERS) {
        printf("User limit reached.\n");
        return;
    }

    // ... (unchanged code for registering a new user)
// Prompt user for information and register
    UserProfile newUser;
    printf("Enter name: ");
    scanf("%s", newUser.name);
    printf("Enter password: ");
    scanf("%s", newUser.password);

    // Provide a list of predefined music genres for the user to choose
    printf("Choose music genre:\n");
    printf("1. 90s Kid\n");
    printf("2. Jazz\n");
    printf("3. Pop\n");
    printf("4. Indie Rock\n");
    printf("5. Bollywood\n");
    printf("6. Electronic\n");
    printf("7. Indian Classical\n");

    int musicChoice;
    printf("Enter the number corresponding to your music choice: ");
    scanf("%d", &musicChoice);

    // Set music preference based on the user's choice
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

    // ... (similar prompts for other user details)
  // Prompt for other user details
    printf("Choose occupation:\n");
    printf("1. Engineering\n");
    printf("2. Doctor\n");
    printf("3. Student\n");
    printf("4. Business\n");
    printf("5. Government Employee\n");
    printf("6. Private Employee\n");

    int occupationChoice;
    printf("Enter the number corresponding to your occupation choice: ");
    scanf("%d", &occupationChoice);

    // Set occupation based on the user's choice
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
    printf("1. Strength\n");
    printf("2. Zumba\n");
    printf("3. Dance\n");
    printf("4. Athletics\n");
    printf("5. Calisthenics\n");

    int fitnessChoice;
    printf("Enter the number corresponding to your fitness choice: ");
    scanf("%d", &fitnessChoice);

    // Set fitness interest based on the user's choice
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
    printf("1. Kannada\n");
    printf("2. English\n");
    printf("3. Hindi\n");
    printf("4. Tamil\n");
    printf("5. Telugu\n");
    printf("6. Marathi\n");
    printf("7. Malayalam\n");

    int languageChoice;
    printf("Enter the number corresponding to your language choice: ");
    scanf("%d", &languageChoice);

    // Set language preference based on the user's choice
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
    printf("1. I stay on WhatsApp all day\n");
    printf("2. Big time texter\n");
    printf("3. Phone caller\n");
    printf("4. Video chatter\n");
    printf("5. I'm slow to answer on WhatsApp\n");
    printf("6. Bad texter\n");
    printf("7. Better in person\n");

    int communicationStyleChoice;
    printf("Enter the number corresponding to your communication style choice: ");
    scanf("%d", &communicationStyleChoice);

    // Set communication style based on the user's choice
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

    // Prompt for sleeping habits
    printf("Choose sleeping habits:\n");
    printf("1. Early bird\n");
    printf("2. Night owl\n");
    printf("3. In a spectrum\n");

    int sleepingHabitsChoice;
    printf("Enter the number corresponding to your choice: ");
    scanf("%d", &sleepingHabitsChoice);

    // Set sleeping habits based on the user's choice
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

    // Prompt for what the user is looking for
    printf("Looking for:\n");
    printf("1. Long-term partner\n");
    printf("2. Long-term, open to short\n");
    printf("3. Short-term, open to long\n");
    printf("4. New friends\n");
    printf("5. Still figuring it out\n");
    printf("6. Short-term fun\n");

    int lookingForChoice;
    printf("Enter the number corresponding to your choice: ");
    scanf("%d", &lookingForChoice);

    // Set what the user is looking for based on the choice
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

    printf("Enter gender[M/F]: ");
    scanf(" %c", &newUser.gender);  // Note the space before %c to consume newline character
    printf("Enter age: ");
    scanf("%d", &newUser.age);

    // Set registration status and add the user to the array
    newUser.isRegistered = true;
    newUser.gifts = NULL; // Initialize the virtual gifts linked list

    users[userCount++] = newUser;

    printf("User registered successfully!\n");
}

// Function to log in a user
int loginUser() {
    char name[MAX_NAME_LEN], password[MAX_PASSWORD_LEN];
    printf("Enter name: ");
    scanf("%s", name);
    printf("Enter password: ");
    scanf("%s", password);

    // Check if the entered credentials match any registered user
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, name) == 0 && strcmp(users[i].password, password) == 0) {
            return i; // User index
        }
    }
    return -1; // Login failed
}



// Function to display a user's received gifts
void displayReceivedGifts(UserProfile* user) {
    printf("Gifts received by %s:\n", user->name);

    VirtualGift* current = user->gifts;
    while (current != NULL) {
        printf("- %s\n", current->name);
        current = current->next;
    }
}
// Function to send a virtual gift
void sendVirtualGift(UserProfile* sender, const char* receiverName, const char* giftName) {
    UserProfile* receiver = NULL;

    // Find the receiver by name
    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, receiverName) == 0) {
            receiver = &users[i];
            break;
        }
    }

    if (receiver != NULL) {
        // Create the virtual gift
        VirtualGift* newGift = (VirtualGift*)malloc(sizeof(VirtualGift));
        strcpy(newGift->name, giftName);
        newGift->next = NULL;

        // Add the gift to the receiver's gift list
        if (receiver->gifts == NULL) {
            receiver->gifts = newGift;
        } else {
            VirtualGift* current = receiver->gifts;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newGift;
        }

        printf("%s sent a %s to %s!\n", sender->name, giftName, receiver->name);
    } else {
        printf("User %s not found!\n", receiverName);
    }
}
// Function to send a virtual gift, prompting for the receiver's name
void sendVirtualGiftPromptReceiver(UserProfile* sender, const char* receiverName) {
    UserProfile* receiver = NULL;

    for (int i = 0; i < userCount; i++) {
        if (strcmp(users[i].name, receiverName) == 0) {
            receiver = &users[i];
            break;
        }
    }

    if (receiver != NULL) {
        char giftName[MAX_NAME_LEN];
        printf("Enter the name of the virtual gift: ");
        scanf("%s", giftName);
        sendVirtualGift(sender, receiver->name, giftName);
    } else {
        printf("User %s not found!\n", receiverName);
    }
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
    printf("\033[1;36mAlgorithmic Love: Because Compatibility Is More Than Skin Deep.\033[0m\n");
    int choice, loggedInUser = -1;
    loadUserProfilesFromFile("userss.txt");

    // Menu-driven user interface
    while (1) {
        printf("\n1. Register\n2. Login\n3. Send Virtual Gift\n4. Display Received Gifts\n5. Exit\n6. Prompt-Based Gift Sender\nEnter your choice: ");
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
        char receiverName[MAX_NAME_LEN];
        printf("Enter the name of the gift receiver: ");
        scanf("%s", receiverName);

        char giftName[MAX_NAME_LEN];
        printf("Enter the name of the virtual gift: ");
        scanf("%s", giftName);

        sendVirtualGift(&users[loggedInUser], receiverName, giftName);
    } else {
        printf("You need to log in first!\n");
    }
    break;
            case 4:
                if (loggedInUser != -1) {
                    displayReceivedGifts(&users[loggedInUser]);
                } else {
                    printf("You need to log in first!\n");
                }
                break;
            case 5:
    // Free allocated memory for gifts (cleanup)
    for (int i = 0; i < userCount; i++) {
        VirtualGift* current = users[i].gifts;
        while (current != NULL) {
            VirtualGift* next = current->next;
            free(current);
            current = next;
        }
    }
    printf("Exiting program. Goodbye!\n");
    return 0;  // ✅ properly exit the loop and program

                case 6:
                if (loggedInUser != -1) {
        char receiverName[MAX_NAME_LEN];
        printf("Enter the name of the gift receiver: ");
        scanf("%s", receiverName);
        sendVirtualGiftPromptReceiver(&users[loggedInUser], receiverName);
    } else {
        printf("You need to log in first!\n");
    }
    break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
