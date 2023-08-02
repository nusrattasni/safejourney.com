#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_BUSES 10
#define MAX_NAME_LENGTH 50
#define MAX_TICKETS 50

typedef struct {
    int bus_id;
    char bus_name[MAX_NAME_LENGTH];
    int total_seats;
    int available_seats;
} Bus;

typedef struct {
    int ticket_id;
    int bus_id;
    char passenger_name[MAX_NAME_LENGTH];
    int seat_number;
} Ticket;

Bus buses[MAX_BUSES];
Ticket tickets[MAX_TICKETS];
int total_buses = 0;
int total_tickets = 0;

void addBus();
void displayBuses();
void bookTicket();
void cancelTicket();
void checkBusStatus();
void displayTickets();
void displayMenu();
void exitProgram();

void Title() {
    printf("\n\n\n\t\t\t###############################################");
    printf("\n\t\t\t#\t  The Squad Bus Ticket Counter        #");
    printf("\n\t\t\t###############################################");
}

void MainMenu(void) {
    int choice;
    do {
        system("cls");
        Title();
        displayMenu();
        printf("\n\n\t\t\tEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBus();
                break;
            case 2:
                displayBuses();
                break;
            case 3:
                bookTicket();
                break;
            case 4:
                cancelTicket();
                break;
            case 5:
                checkBusStatus();
                break;
            case 6:
                displayTickets();
                break;
            case 7:
                exitProgram();
                break;
            default:
                printf("\n\t\t\tInvalid choice. Please try again.\n");
        }
        printf("\n\t\t\tPress Enter key to continue...");
        getchar();
        getchar();
    } while (choice != 7);
}

void addBus() {
    system("cls");
    Title();
    if (total_buses >= MAX_BUSES) {
        printf("\n\t\t\tCannot add more buses. The limit has been reached.\n");
        return;
    }

    Bus new_bus;
    printf("\n\n\t\t\tEnter bus ID: ");
    scanf("%d", &new_bus.bus_id);
    printf("\n\t\t\tEnter bus name: ");
    scanf(" %[^\n]", new_bus.bus_name);
    printf("\n\t\t\tEnter total seats: ");
    scanf("%d", &new_bus.total_seats);
    new_bus.available_seats = new_bus.total_seats;

    buses[total_buses] = new_bus;
    total_buses++;

    printf("\n\t\t\tBus added successfully!\n");
}

void displayBuses() {
    system("cls");
    Title();
    if (total_buses == 0) {
        printf("\n\t\t\tNo buses available.\n");
        return;
    }

    printf("\n\t\t\t--- Available Buses ---\n");
    printf("\n\t\t\tBus ID\tBus Name\tTotal Seats\tAvailable Seats\n");
    for (int i = 0; i < total_buses; i++) {
        printf("\n\t\t\t%d\t%s\t\t%d\t\t%d\n", buses[i].bus_id, buses[i].bus_name, buses[i].total_seats, buses[i].available_seats);
    }
}

void bookTicket() {
    system("cls");
    Title();
    if (total_tickets >= MAX_TICKETS) {
        printf("\n\t\t\tCannot book more tickets. The limit has been reached.\n");
        return;
    }

    displayBuses();

    int bus_id, seat_number;
    printf("\n\t\t\tEnter the bus ID for booking: ");
    scanf("%d", &bus_id);

    int bus_index = -1;
    for (int i = 0; i < total_buses; i++) {
        if (buses[i].bus_id == bus_id) {
            bus_index = i;
            break;
        }
    }

    if (bus_index == -1) {
        printf("\n\t\t\tInvalid bus ID. Please try again.\n");
        return;
    }

    printf("\n\t\t\tEnter your name: ");
    scanf(" %[^\n]", tickets[total_tickets].passenger_name);

    printf("\n\t\t\tEnter preferred seat number: ");
    scanf("%d", &seat_number);

    if (seat_number < 1 || seat_number > buses[bus_index].total_seats) {
        printf("\n\t\t\tInvalid seat number. Please try again.\n");
        return;
    }

    if (buses[bus_index].available_seats == 0) {
        printf("\n\t\t\tNo available seats on this bus.\n");
        return;
    }

    tickets[total_tickets].ticket_id = total_tickets + 1;
    tickets[total_tickets].bus_id = bus_id;
    tickets[total_tickets].seat_number = seat_number;

    buses[bus_index].available_seats--;

    printf("\n\n\n\t\t\tTicket booked successfully! Your ticket ID is: %d\n", tickets[total_tickets].ticket_id);

    total_tickets++;
}

void cancelTicket() {
    system("cls");
    Title();
    if (total_tickets == 0) {
        printf("\n\t\t\tNo tickets to cancel.\n");
        return;
    }

    int ticket_id;
    printf("\n\n\t\t\tEnter the ticket ID to cancel: ");
    scanf("%d", &ticket_id);

    int ticket_index = -1;
    for (int i = 0; i < total_tickets; i++) {
        if (tickets[i].ticket_id == ticket_id) {
            ticket_index = i;
            break;
        }
    }

    if (ticket_index == -1) {
        printf("\n\n\t\t\tInvalid ticket ID. Please try again.\n");
        return;
    }

    int bus_index = -1;
    for (int i = 0; i < total_buses; i++) {
        if (buses[i].bus_id == tickets[ticket_index].bus_id) {
            bus_index = i;
            break;
        }
    }

    buses[bus_index].available_seats++;
    printf("\n\t\t\tTicket with ID %d has been canceled successfully.\n", ticket_id);
    for (int i = ticket_index; i < total_tickets - 1; i++) {
        tickets[i] = tickets[i + 1];
    }

    total_tickets--;
}

void checkBusStatus() {
    system("cls");
    Title();
    if (total_buses == 0) {
        printf("\n\t\t\tNo buses available.\n");
        return;
    }

    int bus_id;
    printf("\n\n\t\t\tEnter the bus ID to check its status: ");
    scanf("%d", &bus_id);

    int bus_index = -1;
    for (int i = 0; i < total_buses; i++) {
        if (buses[i].bus_id == bus_id) {
            bus_index = i;
            break;
        }
    }

    if (bus_index == -1) {
        printf("\n\n\t\t\tInvalid bus ID. Please try again.\n");
        return;
    }

    printf("\n\n\t\t\t--- Bus Status ---\n");
    printf("\t\t\tBus ID\tBus Name\tTotal Seats\tAvailable Seats\n");
    printf("\t\t\t%d\t%s\t\t%d\t\t%d\n", buses[bus_index].bus_id, buses[bus_index].bus_name,
           buses[bus_index].total_seats, buses[bus_index].available_seats);
}

void displayTickets() {
    system("cls");
    Title();
    if (total_tickets == 0) {
        printf("\n\t\t\tNo tickets booked.\n");
        return;
    }
    printf("\n\n\t\t\t--- Booked Tickets ---\n");
    printf("\t\t\tTicket ID\tBus ID\tPassenger Name\tSeat Number\n");
    for (int i = 0; i < total_tickets; i++) {
        printf("\n\t\t\t%d\t\t%d\t%s\t\t%d\n", tickets[i].ticket_id, tickets[i].bus_id,
               tickets[i].passenger_name, tickets[i].seat_number);
    }
}

void displayMenu() {
    printf("\n\n\t\t\t1. Add Bus\n");
    printf("\n\t\t\t2. Display Available Buses\n");
    printf("\n\t\t\t3. Book Ticket\n");
    printf("\n\t\t\t4. Cancel Ticket\n");
    printf("\n\t\t\t5. Check Bus Status\n");
    printf("\n\t\t\t6. Display Booked Tickets\n");
    printf("\n\t\t\t7. Exit\n");
}

void exitProgram() {
    printf("\n\n\n\t\t\tThank you! visiting My project.\n");
}

int main(){
    MainMenu();
    return 0;
}
