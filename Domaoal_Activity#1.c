#include<stdio.h>
#include<stdlib.h>

#define NUM_ROWS 5
#define NUM_COLS 10

char **allocated_array(int rows, int cols); // function to create a dynamically allocated 2D Array
void free_up(char **arr, int rows); // function to free up space
void menu();
void available_seats(char **arr, int rows, int cols);
void reserve_seat(char **arr, int rows, int cols);
void cancel_reserve(char **arr, int rows, int cols);

int main(void) {

    int option;

    // 5 rows ; 10 colums
    char **arr = allocated_array(NUM_ROWS, NUM_COLS); // dynamic character array 

    if (!arr) {
        return 1;
    }

    for (int i = 0; i < NUM_ROWS; i++) { // initializes all characters in A (Available)
        for (int j = 0; j < NUM_COLS; j++) {
            arr[i][j] = 'A';
        }
    }

    do {
        menu();
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch(option)
        {
            case 1: available_seats(arr, NUM_ROWS, NUM_COLS); break;
            case 2: reserve_seat(arr, NUM_ROWS, NUM_COLS); break;
            case 3: cancel_reserve(arr, NUM_ROWS, NUM_COLS); break;
            case 4: printf("\nExiting Program...\n"); break;
        }

    } while (option != 4);

    free_up(arr, NUM_ROWS);
    return 0;
}

char **allocated_array(int rows, int cols)
{
    char **arr = calloc(rows, sizeof(char *)); // calloc for zero-based allocation

    if (!arr) {
        perror("Memory Allocation Failed!"); // error handling
        return NULL;
    }

    for (int i = 0; i < rows; i++) {
        arr[i] = calloc(cols, sizeof(char));
        if (!arr[i]) {
            perror("Memory Allocation Failed!");
            for (int j = 0; j < i; j++) {
                free(arr[j]);
            }
            free(arr);
            return NULL;
        }
    }
    return arr;
}

void free_up(char **arr, int rows)
{
    for (int i = 0; i < rows; i++) {
        free(arr[i]);
    }
    free(arr);
}

void menu()
{
    printf("=== Cinema Seat Reservation System ===\n");
    printf("1. Display Seating Chart\n");
    printf("2. Reserve Seat\n");
    printf("3. Cancel Reservation\n");
    printf("4. Exit Program\n");
}

void available_seats(char **arr, int rows, int cols)
{
    printf("\n=== Seating Chart ===\n\n");
    printf("         ");
    for (int k = 0; k < cols; k++) {
        printf("%d  ", k);
    }
    printf("\n");

    for (int i = 0; i < rows; i++) {
        printf("Row #%d:  ", i);
        for (int k = 0; k < cols; k++) {
            printf("%c  ", arr[i][k]);
        }
        printf("\n");
    }
    printf("\n");
}

void reserve_seat(char **arr, int rows, int cols)
{
    int r, c;

    printf("Enter a row to reserve (0 - 4): ");
    scanf("%d", &r);

    printf("Enter a column to reserve (0 - 9): ");
    scanf("%d", &c);

    if (r >= 0 && r < rows && c >= 0 && c < cols) {
        if (arr[r][c] == 'A') {
            arr[r][c] = 'R';
            printf("\nSeat at row #%d, column #%d has been reserved.\n\n", r, c);
        } else {
             printf("Sorry. The seat is already reserved.\n");
        }
    } else {
        printf("Invalid input, try again.\n");
    }
}

void cancel_reserve(char **arr, int rows, int cols)
{
    int r, c;

    printf("Enter a row to cancel reservation (0 - 4): ");
    scanf("%d", &r);

    printf("Enter a column to cancel reservation (0 - 9): ");
    scanf("%d", &c);


    if (r >= 0 && r < rows && c >= 0 && c < cols) {
        if (arr[r][c] == 'R') {
            arr[r][c] = 'A';
            printf("\nReservation at row #%d, column #%d has been cancelled.\n\n", r, c);
        } else {
            printf("Sorry. The seat is already available.\n");
        }
    } else {
        printf("Invalid input, try again.\n");
    }
}
