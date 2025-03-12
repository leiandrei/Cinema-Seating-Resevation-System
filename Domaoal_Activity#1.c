#include <stdio.h>
#define seat_row 5
#define seat_column 10

void available_seats(char seats[seat_row][seat_column]);
void book_seats(char seats[seat_row][seat_column]);
void cancel_seats(char seats[seat_row][seat_column]);

int main()
{
    char seats[seat_row][seat_column];
    int option;

    for (int i = 0; i < seat_row; i++) {
        for (int k = 0; k < seat_column; k++) {
            seats[i][k] = 'A';
        }
    }

    do {
        printf("Cinema Seat Reservation System:\n");
        printf("1. Display seating chart\n2. Reserve a seat\n3. Cancel a reservation\n4. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &option);

        switch(option) {
            case 1: available_seats(seats); break;
            case 2: book_seats(seats); break;
            case 3: cancel_seats(seats); break;
            case 4: printf("\nExiting Program...\n"); break;
        }

    } while (option != 4);

    return 0;
}

void available_seats(char seats[seat_row][seat_column])
{
    printf("\nSeating Chart:\n\n");
    printf("         ");
    for (int k = 0; k < seat_column; k++) {
        printf("%d  ", k);
    }
    printf("\n");

    for (int i = 0; i < seat_row; i++) {
        printf("Row #%d:  ", i);
        for (int k = 0; k < seat_column; k++) {
            printf("%c  ", seats[i][k]);
        }
        printf("\n");
    }
    printf("\n");
}

void book_seats(char seats[seat_row][seat_column])
{
    int row, column;

    printf("Enter row (0 - 4) to reserve: ");
    scanf("%d", &row);

    printf("Enter column (0 - 9) to reserve: ");
    scanf("%d", &column);

    if (row >= 0 && row < seat_row && column >= 0 && column < seat_column) {
        if (seats[row][column] == 'A') {
            seats[row][column] = 'R';
            printf("\nSeat at row #%d, column #%d has been reserved.\n\n", row, column);
        } else {
            printf("Sorry. The seat is already reserved.\n");
        }
    } else {
        printf("Invalid input, try again.\n");
    }

}

void cancel_seats(char seats[seat_row][seat_column])
{
    int row, column;

    printf("Enter row (0 - 4) to cancel reservation: ");
    scanf("%d", &row);

    printf("Enter column (0 - 9) to cancel reservation: ");
    scanf("%d", &column);

    if (row >= 0 && row < seat_row && column >= 0 && column < seat_column) {
        if (seats[row][column] == 'R') {
            seats[row][column] = 'A';
            printf("\nReservation at row #%d, column #%d has been cancelled.\n\n", row, column);
        } else {
            printf("Sorry. The seat is already available.\n");
        }
    } else {
        printf("Invalid input, try again.\n");
    }

}
