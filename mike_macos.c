# include <stdio.h> // Compatible with macOS
# include <string.h> // Compatible with macOS
# include <strings.h>   // For strcasecmp (in macOS)
# include <unistd.h> // For sleep (Compatible with macOS)
# include <stdlib.h> // For system (Compatible with macOS)
# include <time.h> // For time (Compatible with macOS)
# include <termios.h> // For getch()


// Function to clear input buffer
void clear_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);  // Limpiar el búfer
}


// Function to get user name
void name() {
    char name[15] ;
    system("clear");
    printf("What's your name?\n") ;
    
    for (int i = 0; i < 3; i++) {
        fgets(name, sizeof(name), stdin);  // Read the entire line

        // Eliminate "\n" if present
        if (name[strlen(name) - 1] == '\n') {
            name[strlen(name) - 1] = '\0';
        }
        else {
        // Clear the buffer
        clear_buffer();
        }

        system("clear");
        
        if (strcasecmp(name, "Mike") == 0) {
            strcpy(name, "Mike"); // Use strcpy to copy "Mike" into the name array
            printf("Hello %s\n", name);
            sleep(2);
            break;
        }
        else if (i == 2) {
            strcpy(name, "Mike"); 
            printf("Forget it, I'll just call you %s\n", name);
            sleep(2);
            system("clear");
            break ;  
        }
        else {
            printf("Invalid name, try again\n");
            continue ;
        }
    }
    system("clear");
    printf("Let's play");
    sleep(2);
}


// Función getch() para macOS
char getch(void) {
    struct termios oldt, newt;
    char ch;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    ch = getchar();
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return ch;
}


// Functions to initialize the rooms
void initialize_room1(char room[13][28]) {
    // Define the room layout
    char room_layout[13][28] = {
        "# # # # # # # # # # # # # #",
        "#                         #",
        "#                         #",
        "#                         #",
        "#                         #",
        "#                          ",
        "#                          ",
        "#                         #",
        "#                         #",
        "#                         #",
        "#                         #",
        "# # # # # #     # # # # # #"
    };

    // Copy the room_layout into the actual room
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 28; j++) {
            room[i][j] = room_layout[i][j];
        }
    }
}

void initialize_room2(char room[13][52]) {
    // Define the room layout
    char room_layout[13][52] = {
        "# # # # # # # # # # # # # #                        ",
        "#                         #                        ",
        "#                         #                        ",
        "#                         # # # # # # # # # # # # #",
        "#                         #                       #",
        "#                                                 #",
        "#                                                 #",
        "#                         #                       #",
        "#                         #                       #",
        "#                         #                       #",
        "#                         #                       #",
        "# # # # # #     # # # # # # # # # # # # # # # # # #"
    };

    // Copy the room_layout into the actual room
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 52; j++) {
            room[i][j] = room_layout[i][j];
        }
    }
}

void initialize_room3(char room[26][28]) {
    // Define the room layout
    char room_layout[26][28] = {
        "# # # # # # # # # # # # # #",
        "#                         #",
        "#                         #",
        "#                         #",
        "#                         #",
        "#                          ",
        "#                          ",
        "#                         #",
        "#                         #",
        "#                         #",
        "#                         #",
        "# # # # # #     # # # # # #",
        "          #     #          ",
        "          #     #          ",
        "          #     #          ",
        "# # # # # #     # # # # # #",
        "#                         #",
        "#                         #",
        "#                         #",
        "#                         #",
        "#                         #",
        "#                         #",
        "#                         #",
        "#                         #",
        "#                         #",
        "# # # # # # # # # # # # # #",
    };

    // Copy the room_layout into the actual room
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 28; j++) {
            room[i][j] = room_layout[i][j];
        }
    }
}

void initialize_room4(char room[26][52]) {
    // Define the room layout
    char room_layout[26][52] = {
        "# # # # # # # # # # # # # #                        ",
        "#                         #                        ",
        "#                         #                        ",
        "#                         # # # # # # # # # # # # #",
        "#                         #                       #",
        "#                                                 #",
        "#                                                 #",
        "#                         #                       #",
        "#                         #                       #",
        "#                         #                       #",
        "#                         #                       #",
        "# # # # # #     # # # # # # # # # # # # # # # # # #",
        "          #     #                                  ",
        "          #     #                                  ",
        "          #     #                                  ",
        "# # # # # #     # # # # # #                        ",
        "#                         #                        ",
        "#                         #                        ",
        "#                         #                        ",
        "#                         #                        ",
        "#                         #                        ",
        "#                         #                        ",
        "#                         #                        ",
        "#                         #                        ",
        "#                         #                        ",
        "# # # # # # # # # # # # # #                        "
    };

    // Copy the room_layout into the actual room
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 52; j++) {
            room[i][j] = room_layout[i][j];
        }
    }
}


// Functions to print the rooms with the player, npc and/or item
void print_room1(char room[13][28], int playerX, int playerY) {
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 28; j++) {
            if (i == playerX && j == playerY) {
                printf("\033[32m*\033[0m");  // Draw the player in green
            } else {
                printf("%c", room[i][j]);  // Draw the room
            }
        }
        printf("\n");
    }
}

void print_room2(char room[13][52], int playerX, int playerY, int npcX, int npcY) {
    for (int i = 0; i < 13; i++) {
        for (int j = 0; j < 52; j++) {
            if (i == playerX && j == playerY) {
                printf("\033[32m*\033[0m");  // Draw the player in green
            }
            else if (i == npcX && j == npcY){
                printf("\033[31m*\033[0m");  // Draw the npc in red
            }
            else {
                printf("%c", room[i][j]);  // Draw the room
            }
        }
        printf("\n");
    }
}

void print_room3(char room[26][28], int playerX, int playerY, int npcX, int npcY) {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 28; j++) {
            if (i == playerX && j == playerY) {
                printf("\033[32m*\033[0m");  // Draw the player in green
            }
            else if (i == npcX && j == npcY){
                printf("\033[31m*\033[0m");  // Draw the npc in red
            }
            else if (i == 25 && j >= 11 && j <= 15) {
                printf("\033[31m%c\033[0m", room[i][j]); // Draw a red gate
            }
            else {
                printf("%c", room[i][j]);  // Draw the room
            }
        }
        printf("\n");
    }
}

void print_room4(char room[26][52], int playerX, int playerY, int npcX, int npcY, int itemX, int itemY) {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 52; j++) {
            if (i == playerX && j == playerY) {
                printf("\033[32m*\033[0m");  // Draw the player in green
            }
            else if (i == npcX && j == npcY){
                printf("\033[31m*\033[0m");  // Draw the npc in red
            }
            else if (i == itemX && j == itemY){
                printf("\033[93m*\033[0m");   // Draw the item in yellow
            }
            else if (i == 25 && j >= 11 && j <= 15) {
                printf("\033[31m%c\033[0m", room[i][j]); // Draw a red gate
            }
            else {
                printf("%c", room[i][j]);  // Draw the room
            }
        }
        printf("\n");
    }
}

void print_room5(char room[26][52], int playerX, int playerY, int npcX, int npcY, int itemX, int itemY) {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 52; j++) {
            if (i == playerX && j == playerY) {
                printf("\033[32m*\033[0m");  // Draw the player in green
            }
            else if (i == npcX && j == npcY){
                printf("\033[31m*\033[0m");  // Draw the npc in red
            }
            else if (i == itemX && j == itemY){
                printf("\033[93m*\033[0m");   // Draw the item in yellow
            }
            else if (i == 25 && j >= 11 && j <= 15) {
                printf("\033[31m%c\033[0m", room[i][j]); // Draw a red gate
            }
            else {
                printf("%c", room[i][j]);  // Draw the room
            }
        }
        printf("\n");
    }
}

void print_room6(char room[26][52], int playerX, int playerY, int npcX, int npcY, int gate) {
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 52; j++) {
            if (i == playerX && j == playerY) {
                if (gate == 0){
                    printf("\033[32m*\033[0m");  // Draw the player in green if the gate is not opened
                }
                else {
                    printf("\033[31m*\033[0m");  // Draw the player in red if the gate is not opened
                }
            }
            else if (i == npcX && j == npcY && gate == 0){
                printf("\033[31m*\033[0m");  // Draw the npc in red if the gate is not opened
            }
            else if (i == 25 && j >= 11 && j <= 15) {  // If in the position of the gate
                if (gate == 0) {
                    printf("\033[31m%c\033[0m", room[i][j]); // If not opened, draw a red gate
                }
                else {
                    printf(" "); // If opened, draw spaces
                }
                
            }
            else {
                printf("%c", room[i][j]);  // Draw the room
            }
        }
        printf("\n");
    }
}


// Functions to reset the npc position randomly
void random_position_room2(int *npcX, int *npcY) {
    // For random generation each time
    srand(time(NULL));
    // Save previous values of the initial position of the npc
    int init_npcX = *npcX;
    int init_npcY = *npcY;
    do {
        *npcX = 4 + rand() % (10 - 4 + 1);  // random position of npcX in right room (4-10)
        *npcY = 27 + rand() % (49 - 27 + 1); // // random position of npcY in right room (27-49)
    } while (*npcX == init_npcX && *npcY == init_npcY); // Avoid repetition of position
}

void random_position_room3(int *npcX, int *npcY) {
    // For random generation each time
    srand(time(NULL));
    // Save previous values of the initial position of the npc
    int init_npcX = *npcX;
    int init_npcY = *npcY;
    do {
        *npcX = 16 + rand() % (24 - 16 + 1);  // random position of npcX in right room (16-24)
        *npcY = 1 + rand() % (25 - 1 + 1); // // random position of npcY in right room (1-25)
    } while (*npcX == init_npcX && *npcY == init_npcY); // Avoid repetition of position
}


// Functions to launch the rooms
void room1(int *playerX, int *playerY, int *npcX, int *npcY) {
    // Define the room
    char room[13][28];

    // Define the initial position of the player
    *playerX = 6;
    *playerY = 13;

    // Initialize the room
    initialize_room1(room);

    // Define the variable input for keyboard feedback
    char input;

    while (1) {
        // Clear the screen (Windows)
        system("clear");

        // Print the room with the player
        print_room1(room, *playerX, *playerY);

        // Instructions
        printf("\nUse W (up), A (left), S (down), D (right) to move. Q to quit.\n");
        
        // Read user input
        input = getch();

        // Move the player
        switch (input) {
            case 'w':  // Up
                if (room[*playerX - 1][*playerY] == ' ' && *playerX != 1) {
                    (*playerX)--;
                }
                break;
            case 's':  // Down
                // If the player is next to the bottom gate, initiate room3
                if (*playerX == 11) {
                    (*playerX)++;
                    room3(playerX, playerY, npcX, npcY);
                    return;
                }
                if (*playerX == 10 && *playerY >= 11 && *playerY <= 15) {
                    (*playerX)++;
                }
                else if (room[*playerX + 1][*playerY] == ' ' && *playerX != 10) {
                    (*playerX)++;
                }
                break;
            case 'a':  // Left
                if (room[*playerX][*playerY - 1] == ' ') {
                    (*playerY)--;
                }
                break;
            case 'd':  // Right
                // If the player is next to the right gate, initiate room2
                if ((*playerX == 5 || *playerX == 6) && *playerY == 26) {
                    (*playerY)++;
                    room2(playerX, playerY, npcX, npcY);
                    return;
                }
                else if (room[*playerX][*playerY + 1] == ' ') {
                    (*playerY)++;
                }
                break;
            case 'q':  // Quit
                printf("You cannot quit\n");
                sleep(1);
                break;
        }
    }

    return;
}

void room2(int *playerX, int *playerY, int *npcX, int *npcY) {
    // Define the room
    char room[13][52];

    // Initialize the room
    initialize_room2(room);

    // Define the initial position of the npc
    *npcX = 7;
    *npcY = 38;

    // Define the variable input for keyboard feedback
    char input;

    while (1) {
        // Clear the screen (Windows)
        system("clear");

        // Print the room with the player
        print_room2(room, *playerX, *playerY, *npcX, *npcY);

        // Instructions
        printf("\nUse W (up), A (left), S (down), D (right) to move. Q to quit.\n");

        // Read user input
        input = getch();

        // Move the player
        switch (input) {
            case 'w':  // Up
                // If player was beneath the npc, new random position of npc
                if (*playerX - 1 == *npcX && *playerY == *npcY) {
                    random_position_room2(npcX, npcY);
                }

                if (room[*playerX - 1][*playerY] == ' ' && *playerX != 1 && !(*playerX == 4 && *playerY > 26 )) {
                    (*playerX)--;
                }
                break;
            case 's':  // Down
                // If player was on the npc, new random position of npc
                if (*playerX + 1 == *npcX && *playerY == *npcY) {
                    random_position_room2(npcX, npcY);
                }
                // If the player is next to the bottom gate, initiate room4
                if (*playerX == 11) {
                    (*playerX)++;
                    room4(playerX, playerY, npcX, npcY);
                    return;
                }
                if (*playerX == 10 && *playerY >= 11 && *playerY <= 15) {
                    (*playerX)++;
                }
                else if (room[*playerX + 1][*playerY] == ' ' && *playerX != 10) {
                    (*playerX)++;
                }
                break;
            case 'a':  // Left
                // If player was to the right of the npc, new random position of npc
                if (*playerX == *npcX && *playerY - 1 == *npcY) {
                    random_position_room2(npcX, npcY);
                }

                if (room[*playerX][*playerY - 1] == ' ') {
                    (*playerY)--;
                }
                break;
            case 'd':  // Right
                // If player was to the left of the npc, new random position of npc
                if (*playerX == *npcX && *playerY + 1 == *npcY) {
                    random_position_room2(npcX, npcY);
                }

                if (room[*playerX][*playerY + 1] == ' ') {
                    (*playerY)++;
                }
                break;
            case 'q':  // Quit
                printf("You cannot quit\n");
                sleep(1);
                break;
        }
    }

    return;
}

void room3(int *playerX, int *playerY, int *npcX, int *npcY) {
    // Define the room
    char room[26][28];

    // Initialize the room
    initialize_room3(room);

    // Define the initial position of the npc
    *npcX = 20;
    *npcY = 13;

    // Define the variable input for keyboard feedback
    char input;

    while (1) {
         // Clear the screen (Windows)
        system("clear");

        // Print the room with the player
        print_room3(room, *playerX, *playerY, *npcX, *npcY);

        // Instructions
        printf("\nUse W (up), A (left), S (down), D (right) to move. Q to quit.\n");

        // Read user input
        input = getch();

        // Move the player
        switch (input) {
            case 'w':  // Up
                // If player was beneath the npc, new random position of npc
                if (*playerX - 1 == *npcX && *playerY == *npcY) {
                    random_position_room3(npcX, npcY);
                }
                // Logic for moving through the corridor up
                if (*playerX == 16 && *playerY >= 11 && *playerY <= 15) {
                    (*playerX)--;
                }
                // Logic for moving elsewhere up
                else if (room[*playerX - 1][*playerY] == ' ' && *playerX != 1 && *playerX != 16) {
                    (*playerX)--;
                }
                break;
            case 's':  // Down
                // If player was on the npc, new random position of npc
                if (*playerX + 1 == *npcX && *playerY == *npcY) {
                    random_position_room3(npcX, npcY);
                }
                // Logic for moving through the corridor down
                if (*playerX == 10 && *playerY >= 11 && *playerY <= 15) {
                    (*playerX)++;
                }
                // Logic for movieng elsewhere down
                else if (room[*playerX + 1][*playerY] == ' ' && *playerX != 10 && *playerX != 24) {
                    (*playerX)++;
                }
                break;
            case 'a':  // Left
                // If player was to the right of the npc, new random position of npc
                if (*playerX == *npcX && *playerY - 1 == *npcY) {
                    random_position_room3(npcX, npcY);
                }
                // Logic for moving to the left
                if (room[*playerX][*playerY - 1] == ' ') {
                    (*playerY)--;
                }
                break;
            case 'd':  // Right
                // If player was to the left of the npc, new random position of npc
                if (*playerX == *npcX && *playerY + 1 == *npcY) {
                    random_position_room3(npcX, npcY);
                }
                // If the player is next to the right gate, initiate room5
                if ((*playerX == 5 || *playerX == 6) && *playerY == 26) {
                    (*playerY)++;
                    room5(playerX, playerY, npcX, npcY);
                    return;
                }
                // Logic for moving to the right
                else if (room[*playerX][*playerY + 1] == ' ') {
                    (*playerY)++;
                }
                break;
            case 'q':  // Quit
                printf("You cannot quit\n");
                sleep(1);
                break;
        }
    }

    return;
}

void room4(int *playerX, int *playerY, int *npcX, int *npcY) {
    // Define the room
    char room[26][52];

    // Initialize the room
    initialize_room4(room);

    // Define the position of the item randomly avoiding the same position of the player
    int itemX = 0;
    int itemY = 0;
    do {
        random_position_room3(&itemX, &itemY);
    } while (*playerX == itemX && *playerY == itemY);
    
    // Define the variable input for keyboard feedback
    char input;

    while (1) {
        // If the player picks up the item, move to room6
        if (*playerX == itemX && *playerY == itemY) {
            room6(playerX, playerY, npcX, npcY);
            return;
        }
        // Clear the screen (Windows)
        system("clear");

        // Print the room with the player
        print_room4(room, *playerX, *playerY, *npcX, *npcY, itemX, itemY);

        // Instructions
        printf("\nUse W (up), A (left), S (down), D (right) to move. Q to quit.\n");

        // Read user input
        input = getch();

        // Move the player
        switch (input) {
            case 'w':  // Up
                // If player was beneath the npc, new random position of npc
                if (*playerX - 1 == *npcX && *playerY == *npcY) {
                    random_position_room2(npcX, npcY);
                }
                // Logic for moving up
                if (
                    // Logic for moving through the corridor up
                    (*playerX == 16 && *playerY >= 11 && *playerY <= 15) || //OR
                    // Logic for moving up elsewhere
                    (
                        room[*playerX - 1][*playerY] == ' ' && 
                        *playerX != 1 && 
                        *playerX != 16 &&
                        !(*playerX == 4 && *playerY > 26)
                    )
                ) {
                    (*playerX)--;
                }
                break;
            case 's':  // Down
                // If player was on the npc, new random position of npc
                if (*playerX + 1 == *npcX && *playerY == *npcY) {
                    random_position_room2(npcX, npcY);
                }
                // Logic for moving down
                if (
                    // Logic for moving through the corridor down
                    (*playerX == 10 && *playerY >= 11 && *playerY <= 15) || //OR
                    // Logic for moving down elsewhere
                    (
                        room[*playerX + 1][*playerY] == ' ' && 
                        *playerX != 10 && 
                        *playerX != 24
                    )
                ) {
                    (*playerX)++;
                }
                break;
            case 'a':  // Left
                // If player was to the right of the npc, new random position of npc
                if (*playerX == *npcX && *playerY - 1 == *npcY) {
                    random_position_room2(npcX, npcY);
                }
                // Logic for moving to the left
                if (room[*playerX][*playerY - 1] == ' ') {
                    (*playerY)--;
                }
                break;
            case 'd':  // Right
                // If player was to the left of the npc, new random position of npc
                if (*playerX == *npcX && *playerY + 1 == *npcY) {
                    random_position_room2(npcX, npcY);
                }
                // Logic for moving to the right
                if (room[*playerX][*playerY + 1] == ' ') {
                    (*playerY)++;
                }
                break;
            case 'q':  // Quit
                printf("You cannot quit\n");
                sleep(1);
                break;
        }
    }

    return;
}

void room5(int *playerX, int *playerY, int *npcX, int *npcY) {
    // Define the room
    char room[26][52];

    // Initialize the room
    initialize_room4(room);

    // Define the position of the item randomly avoiding the same position of the player
    int itemX = 0;
    int itemY = 0;
    do {
        random_position_room2(&itemX, &itemY);
    } while (*playerX == itemX && *playerY == itemY);
    
    // Define the variable input for keyboard feedback
    char input;

    while (1) {
        // If the player picks up the item, move to room6
        if (*playerX == itemX && *playerY == itemY) {
            room6(playerX, playerY, npcX, npcY);
            return;
        }
        // Clear the screen (Windows)
        system("clear");

        // Print the room with the player
        print_room5(room, *playerX, *playerY, *npcX, *npcY, itemX, itemY);

        // Instructions
        printf("\nUse W (up), A (left), S (down), D (right) to move. Q to quit.\n");

        // Read user input
        input = getch();

        // Move the player
        switch (input) {
            case 'w':  // Up
                // If player was beneath the npc, new random position of npc
                if (*playerX - 1 == *npcX && *playerY == *npcY) {
                    random_position_room3(npcX, npcY);
                }
                // Logic for moving up
                if (
                    // Logic for moving through the corridor up
                    (*playerX == 16 && *playerY >= 11 && *playerY <= 15) || //OR
                    // Logic for moving up elsewhere
                    (
                        room[*playerX - 1][*playerY] == ' ' && 
                        *playerX != 1 && 
                        *playerX != 16 &&
                        !(*playerX == 4 && *playerY > 26)
                    )
                ) {
                    (*playerX)--;
                }
                break;
            case 's':  // Down
                // If player was on the npc, new random position of npc
                if (*playerX + 1 == *npcX && *playerY == *npcY) {
                    random_position_room3(npcX, npcY);
                }
                // Logic for moving down
                if (
                    // Logic for moving through the corridor down
                    (*playerX == 10 && *playerY >= 11 && *playerY <= 15) || //OR
                    // Logic for moving down elsewhere
                    (
                        room[*playerX + 1][*playerY] == ' ' && 
                        *playerX != 10 && 
                        *playerX != 24
                    )
                ) {
                    (*playerX)++;
                }
                break;
            case 'a':  // Left
                // If player was to the right of the npc, new random position of npc
                if (*playerX == *npcX && *playerY - 1 == *npcY) {
                    random_position_room3(npcX, npcY);
                }
                // Logic for moving to the left
                if (room[*playerX][*playerY - 1] == ' ') {
                    (*playerY)--;
                }
                break;
            case 'd':  // Right
                // If player was to the left of the npc, new random position of npc
                if (*playerX == *npcX && *playerY + 1 == *npcY) {
                    random_position_room3(npcX, npcY);
                }
                // Logic for moving to the right
                if (room[*playerX][*playerY + 1] == ' ') {
                    (*playerY)++;
                }
                break;
            case 'q':  // Quit
                printf("You cannot quit\n");
                sleep(1);
                break;
        }
    }

    return;
}

void room6(int *playerX, int *playerY, int *npcX, int *npcY) {
    // Define the room
    char room[26][52];

    // Initialize the room
    initialize_room4(room);

    // Define the variable of gate opened (false)
    int gate = 0;

    // Define the variable input for keyboard feedback
    char input;

    while (1) {
        // Clear the screen (Windows)
        system("clear");

        // If the player picks up the npc, the gate opens
        if (*playerX == *npcX && *playerY == *npcY){
            gate = 1;
        }

        // Print the room with the player
        print_room6(room, *playerX, *playerY, *npcX, *npcY, gate);

        // Instructions
        printf("\nUse W (up), A (left), S (down), D (right) to move. Q to quit.\n");

        // Read user input
        input = getch();

        // Move the player
        switch (input) {
            case 'w':  // Up
                // Logic for moving up
                if (
                    // Logic for moving through the corridor up
                    (*playerX == 16 && *playerY >= 11 && *playerY <= 15) || //OR
                    // Logic for moving up elsewhere
                    (
                        room[*playerX - 1][*playerY] == ' ' && 
                        *playerX != 1 && 
                        *playerX != 16 &&
                        !(*playerX == 4 && *playerY > 26)
                    )
                ) {
                    (*playerX)--;
                }
                break;
            case 's':  // Down
                // Logic for moving down
                // If the player is next to the opened gate, continue to next level
                if (*playerX == 25) {
                    return;
                }
                if (
                    // Logic for moving through the corridor down
                    (*playerX == 10 && *playerY >= 11 && *playerY <= 15) || // OR
                    // Logic for moving to the gate if it's opened
                    (gate == 1 && *playerX == 24 && *playerY >= 11 && *playerY <= 15) || // OR
                    // Logic for moving down elsewhere
                    (
                        room[*playerX + 1][*playerY] == ' ' && 
                        *playerX != 10 && 
                        *playerX != 24
                    )
                ) {
                    (*playerX)++;
                }
                break;
            case 'a':  // Left
                // Logic for moving to the left
                if (room[*playerX][*playerY - 1] == ' ') {
                    (*playerY)--;
                }
                break;
            case 'd':  // Right
                // Logic for moving to the right
                if (room[*playerX][*playerY + 1] == ' ') {
                    (*playerY)++;
                }
                break;
            case 'q':  // Quit
                printf("You cannot quit\n");
                sleep(1);
                break;
        }
    }

    return;
}


// Function to print mask
void mask() {
    char mask[15][43] = {      
        "##########################################",
        " ######################################## ",
        " ###################  ################### ",
        "  ######## #########  ######### ########  ",
        "  #######       ##########       #######  ",
        "  ######## #########  ######### ########  ",
        "   #################  #################   ",
        "    ################  ################    ",
        "    #################################     ",
        "     ###############################      ",
        "     ###############################      ",
        "        ########################          ",
        "          #####################           ",
        "           ###################            ",
        "            #################             "
    };

    // Print the mask
    for (int i = 0; i < 15; i++) {
        printf("%s\n", mask[i]);
    }
}

// Function to print happy birthday and mask
void bday() {
    char name[15] ;

    system("clear");

    printf("What's your name?\n") ;
    
    while (1) {
        fgets(name, sizeof(name), stdin);  // Read the entire line

        // Eliminate "\n" if present
        if (name[strlen(name) - 1] == '\n') {
            name[strlen(name) - 1] = '\0';
        }
        else {
        // Clear the buffer
        clear_buffer();
        }

        system("clear");
        
        if (strcasecmp(name, "Mike") == 0) {
            strcpy(name, "Mike"); // Use strcpy to copy "Mike" into the name array
            printf("Happy birthday %s\n", name);
            sleep(3);
            system("clear");

            // Print mask
            mask();
            usleep(300000);
            system("clear");
            return;
        }
        else {
            printf("That's not your name, try again\n");
            continue ;
        }
    }
}

int main() {

    // Start the asking for name process
    name();

    // Define the pointers to the position of the player
    int *playerX, *playerY;

    // Define the pointers to the position of the npc
    int *npcX, *npcY;

    // Initiate room1
    room1(&playerX, &playerY, &npcX, &npcY);

    // Happy birthday
    bday();

    return 0;
}
