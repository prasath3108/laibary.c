#include <stdio.h>
#include <string.h>

struct Book {
    char name[50];
    char author[50];
    char category[30];
    int id;
    int price;
    int issued;
};

int main() {
    struct Book books[100];
    int count = 0;
    int choice, i, id, found;

    do {
        printf("\n========== LIBRARY MANAGEMENT SYSTEM ==========\n");
        printf("1. ADD NEW BOOK\n");
        printf("2. DISPLAY ALL BOOKS\n");
        printf("3. SEARCH BOOK BY NAME\n");
        printf("4. SEARCH BOOK BY ID\n");
        printf("5. ISSUE BOOK\n");
        printf("6. RETURN BOOK\n");
        printf("7. UPDATE BOOK DETAILS\n");
        printf("8. COUNT TOTAL BOOKS\n");
        printf("9. DISPLAY AVAILABLE BOOKS\n");
        printf("0. EXIT\n");

        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                if(count >= 100) {
                    printf("LIBRARY IS FULL!\n");
                    break;
                }

                printf("\n====== ADD NEW BOOK ======\n");

                printf("ENTER BOOK NAME: ");
                scanf(" %49[^\n]", books[count].name);

                printf("ENTER BOOK ID: ");
                scanf("%d", &books[count].id);

                found = 0;

                for(i = 0; i < count; i++) {
                    if(books[i].id == books[count].id) {
                        found = 1;
                        break;
                    }
                }

                if(found) {
                    printf("BOOK ID ALREADY EXISTS!\n");
                    break;
                }

                printf("ENTER AUTHOR NAME: ");
                scanf(" %49[^\n]", books[count].author);

                printf("ENTER CATEGORY: ");
                scanf(" %29[^\n]", books[count].category);

                printf("ENTER PRICE: ");
                scanf("%d", &books[count].price);

                books[count].issued = 0;
                count++;

                printf("\nBOOK ADDED SUCCESSFULLY!\n");
                break;

            case 2:
                printf("\n====== ALL BOOKS ======\n");

                if(count == 0) {
                    printf("NO BOOKS AVAILABLE!\n");
                }

                for(i = 0; i < count; i++) {
                    printf("\nBOOK NAME: %s\n", books[i].name);
                    printf("BOOK ID: %d\n", books[i].id);
                    printf("AUTHOR: %s\n", books[i].author);
                    printf("CATEGORY: %s\n", books[i].category);
                    printf("PRICE: %d\n", books[i].price);

                    if(books[i].issued == 1)
                        printf("STATUS: ISSUED\n");
                    else
                        printf("STATUS: AVAILABLE\n");
                }
                break;

            case 3: {
                char search[50];

                printf("\nENTER BOOK NAME: ");
                scanf(" %49[^\n]", search);

                found = 0;

                for(i = 0; i < count; i++) {
                    if(strcmp(search, books[i].name) == 0) {
                        printf("\nBOOK FOUND!\n");
                        printf("BOOK ID: %d\n", books[i].id);
                        printf("AUTHOR: %s\n", books[i].author);
                        found = 1;
                        break;
                    }
                }

                if(!found)
                    printf("BOOK NOT FOUND!\n");

                break;
            }

            case 4:
                printf("\nENTER BOOK ID: ");
                scanf("%d", &id);

                found = 0;

                for(i = 0; i < count; i++) {
                    if(books[i].id == id) {
                        printf("\nBOOK FOUND!\n");
                        printf("BOOK NAME: %s\n", books[i].name);
                        printf("AUTHOR: %s\n", books[i].author);
                        printf("PRICE: %d\n", books[i].price);
                        found = 1;
                        break;
                    }
                }

                if(!found)
                    printf("BOOK NOT FOUND!\n");

                break;

            case 5:
                printf("\nENTER BOOK ID TO ISSUE: ");
                scanf("%d", &id);

                found = 0;

                for(i = 0; i < count; i++) {
                    if(books[i].id == id) {
                        found = 1;

                        if(books[i].issued == 0) {
                            books[i].issued = 1;
                            printf("BOOK ISSUED SUCCESSFULLY!\n");
                        }
                        else {
                            printf("BOOK IS ALREADY ISSUED!\n");
                        }

                        break;
                    }
                }

                if(!found)
                    printf("BOOK NOT FOUND!\n");

                break;

            case 6:
                printf("\nENTER BOOK ID TO RETURN: ");
                scanf("%d", &id);

                found = 0;

                for(i = 0; i < count; i++) {
                    if(books[i].id == id) {
                        found = 1;

                        if(books[i].issued == 1) {
                            books[i].issued = 0;
                            printf("BOOK RETURNED SUCCESSFULLY!\n");
                        }
                        else {
                            printf("BOOK WAS NOT ISSUED!\n");
                        }

                        break;
                    }
                }

                if(!found)
                    printf("BOOK NOT FOUND!\n");

                break;

            case 7:
                printf("\nENTER BOOK ID TO UPDATE: ");
                scanf("%d", &id);

                found = 0;

                for(i = 0; i < count; i++) {
                    if(books[i].id == id) {
                        found = 1;

                        printf("ENTER NEW BOOK NAME: ");
                        scanf(" %49[^\n]", books[i].name);

                        printf("ENTER NEW AUTHOR NAME: ");
                        scanf(" %49[^\n]", books[i].author);

                        printf("ENTER NEW CATEGORY: ");
                        scanf(" %29[^\n]", books[i].category);

                        printf("ENTER NEW PRICE: ");
                        scanf("%d", &books[i].price);

                        printf("\nBOOK DETAILS UPDATED!\n");
                        break;
                    }
                }

                if(!found)
                    printf("BOOK NOT FOUND!\n");

                break;

            case 8:
                printf("\nTOTAL BOOKS: %d\n", count);
                break;

            case 9:
                printf("\n====== AVAILABLE BOOKS ======\n");

                found = 0;

                for(i = 0; i < count; i++) {
                    if(books[i].issued == 0) {
                        printf("ID: %d | NAME: %s\n",
                               books[i].id, books[i].name);
                        found++;
                    }
                }

                if(found == 0)
                    printf("NO AVAILABLE BOOKS!\n");

                printf("AVAILABLE BOOK COUNT: %d\n", found);
                break;

            case 0:
                printf("\nTHANK YOU FOR USING OUR LIBRARY!\n");
                break;

            default:
                printf("\nINVALID CHOICE! TRY AGAIN.\n");
        }

    } while(choice != 0);

    return 0;
}