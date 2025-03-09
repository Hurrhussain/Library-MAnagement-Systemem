#include <stdio.h>

#define MAX_BOOKS 100


typedef struct {
    int id;
    char title[50];
    char author[50];
    int isBorrowed;
} Book;

Book library[MAX_BOOKS];
int bookCount = 0;

void addBook() {
    if (bookCount < MAX_BOOKS) {
        library[bookCount].id = bookCount + 1;
        printf("Enter book title: ");
        scanf(" %s", library[bookCount].title);
        printf("Enter author name: ");
        scanf(" %s", library[bookCount].author);
        library[bookCount].isBorrowed = 0;
        printf("Book added successfully!\n");
        bookCount++;
    } else {
        printf("Library is full!\n");
    }
}

void displayBooks() {
    if (bookCount == 0) {
        printf("No books in the library.\n");
        return;
    }
    printf("Library Books:\n");
    for (int i = 0; i < bookCount; i++) {
        printf("ID: %d | Title: %s | Author: %s | Status: %s\n", 
               library[i].id, library[i].title, library[i].author, 
               library[i].isBorrowed ? "Borrowed" : "Available");
    }
}

void borrowBook() {
    int id;
    printf("Enter Book ID to borrow: ");
    scanf("%d", &id);
    if (id > 0 && id <= bookCount && !library[id - 1].isBorrowed) {
        library[id - 1].isBorrowed = 1;
        printf("Book borrowed successfully!\n");
    } else {
        printf("Invalid book ID or book already borrowed.\n");
    }
}

void returnBook() {
    int id;
    printf("Enter Book ID to return: ");
    scanf("%d", &id);
    if (id > 0 && id <= bookCount && library[id - 1].isBorrowed) {
        library[id - 1].isBorrowed = 0;
        printf("Book returned successfully!\n");
    } else {
        printf("Invalid book ID or book wasn't borrowed.\n");
    }
}

void deleteBook() {
    int id;
    printf("Enter Book ID to delete: ");
    scanf("%d", &id);
    if (id > 0 && id <= bookCount) {
        for (int i = id - 1; i < bookCount - 1; i++) {
            library[i] = library[i + 1];
        }
        bookCount--;
        printf("Book deleted successfully!\n");
    } else {
        printf("Invalid book ID.\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nLibrary Management System\n");
        printf("1. Add Book\n2. Display Books\n3. Borrow Book\n4. Return Book\n5. Delete Book\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: addBook(); break;
            case 2: displayBooks(); break;
            case 3: borrowBook(); break;
            case 4: returnBook(); break;
            case 5: deleteBook(); break;
            case 6: printf("Exiting...\n"); break;
            default: printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);
    
    return 0;
}
