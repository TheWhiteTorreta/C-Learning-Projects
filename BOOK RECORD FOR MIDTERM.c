#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>


/* This bookrecord structure contains the following:
		- TITLE
		- AUTHOR
		- PUBLICATION YEAR
		- PRICE
*/
	typedef struct {
		char* title;
		char* author;
		int pubyear;
		float price;
	} bookrecord;


// Global variables
	int choice;
	int c;
	bookrecord book;
	FILE *file, *tempfile;
	char filename[50];
	char temp_filename[50];


// Function prototypes
	void userinput(bookrecord* book);
	void filecontent(bookrecord* book);
	void titleauthor(bookrecord* book);
	void FILEname(bookrecord* book);
	void TEMPfilename(bookrecord* book);
	void listFiles();
	void renameFile();
	void isExist();
	void fileupdate();


int main() {
	
	dwight:
		
		printf("\tBook Record Menu\n");
		printf("[1] Create File\n");
		printf("[2] Read File\n");
		printf("[3] Update File\n");
		printf("[4] Delete File\n");
		printf("[5] List of Files\n");
		printf("[6] Rename File\n");
		printf("[7] Exit\n");
		printf("\nEnter Your Choice: ");
		scanf("%d", &choice);
		getchar();
		system("cls");
	
	
		/* Book record menu with options of;
			- Creating a file
			- Reading a file
			- Updating a file
			- Deleting a file
			- Listing files
			- Renaming a file
			- Exiting the program
		*/
			switch (choice) {
				case 1:  // Create a File
				
					userinput(&book);
					FILEname(&book);
					file = fopen(filename, "w");
					
					if (file == NULL) {
							printf("\n\tError creating File");
						} else {
							filecontent(&book);
							printf("\n\tFile Created Successfully");
							fclose(file);
						}
					goto bacalla;
				
				
				case 2:  // Read a File
				
					titleauthor(&book);
					FILEname(&book);
					file = fopen(filename, "r");
					isExist();
					goto bacalla;
					
					
				case 3:  // Update a File
					fileupdate();
					goto bacalla;
					
					
				case 4:  // Delete a File
					titleauthor(&book);
					FILEname(&book);
					if (remove(filename) == 0) {
							printf("\n\tThe file is deleted successfully");
						} else {
							printf("\n\tThe file is not deleted");
						}
					goto bacalla;
					
					
				case 5:  // List of Files
				
					listFiles();
					goto bacalla;
					
				
				case 6:  // Rename a File
				
					renameFile();
					goto bacalla;
					
				
				case 7:  // Exit
				
					exit(0);
					
				
				default:
					
					printf("Invalid Choice");
					goto bacalla;
			}
	
	
	
	bacalla:
		
		printf("\n\n[1] Go back to Book Record");
		printf("\n[2] Exit");
		printf("\nEnter another choice: ");
		scanf("%d", &choice);
		getchar();
		system("cls");
	
	
		/* Post-Action Menu with the options of;
			- Going back to Book Record Menu
			- Exit
		*/
			switch (choice) {
				case 1:  										// Go back to Menu
				
					goto dwight;
				
				case 2:  										// Exit
				
					exit(0);
				
				default:
					
					printf("Invalid Choice");
					goto bacalla;
			}
	
		return 0;
}



/* This userinput function get the input of the following:
		Enter Title 				by reference in book->title
		Enter Author 				by reference in book->author
		Enter Publication Year 		by reference in book->pubyear
		Enter Price 				by reference in book->price
*/
	void userinput(bookrecord* book) {
		
		printf("\tEnter Book Information\n");
		
		book->title = (char*)malloc(50 * sizeof(char));
		printf("Enter Title: ");
		fgets(book->title, 50, stdin);
		book->title[strcspn(book->title, "\n")] = '\0';
		
		book->author = (char*)malloc(50 * sizeof(char));
		printf("Enter Author: ");
		fgets(book->author, 50, stdin);
		book->author[strcspn(book->author, "\n")] = '\0';
		
		printf("Enter Publication Year: ");
		scanf("%d", &book->pubyear);
		
		printf("Enter Price: ");
		scanf("%f", &book->price);
		
		system("cls");
	}



/* This filecontent function will print the following in the file:
		Title
		Author
		Publication Year
		Price with 2 decimal places
*/
	void filecontent(bookrecord* book) {
		
		fprintf(file, "\nTitle: %s\n", book->title);
		fprintf(file, "Author: %s\n", book->author);
		fprintf(file, "Publication Year: %d\n", book->pubyear);
		fprintf(file, "Price: %.2f\n", book->price);
	}



/* This titleauthor function will get the input of the following:
		Enter Title 				by reference in book->title
		Enter Author 				by reference in book->author
		
* This is the function where I ask the Title and the author of the file
	to find those existing file and read, update, rename, list, and delete the files
*/
	void titleauthor(bookrecord* book) {
		
		printf("\tEnter Book Information\n");
		
		book->title = (char*)malloc(50 * sizeof(char));
		printf("Enter Title: ");
		fgets(book->title, 50, stdin);
		book->title[strcspn(book->title, "\n")] = '\0';
		
		book->author = (char*)malloc(50 * sizeof(char));
		printf("Enter Author: ");
		fgets(book->author, 50, stdin);
		book->author[strcspn(book->author, "\n")] = '\0';
	}



/* This FILEname function is used before opening the file
	So that it will read the variable filename

	Inside the variable filename contains the following:
	*	title - author.txt
*/
	void FILEname(bookrecord* book) {
		snprintf(filename, 50, "%s - %s.txt", book->title, book->author);
	}



/* This TEMPfilename function is used before opening the file
    So that it will read the variable temp_filename

    Inside the variable filename contains the following:
    *   title - author.txt
*/
void TEMPfilename(bookrecord* book) {
	snprintf(temp_filename, 50, "%s - %s_temp.txt", book->title, book->author);
}



// This lisFiles function is responsible for listing the files in the current directory that have a ".txt" extension
void listFiles() {
	
    DIR* directory = opendir(".");  // Open the current directory

    if (directory == NULL) {
        printf("Error opening the directory.\n");
        return;
    }

    struct dirent* entry;
    printf("---- Book List ----\n");
    while ((entry = readdir(directory)) != NULL) {  							// It iterates over each entry in the directory using the readdir() function. The function returns a pointer to the next directory entry, or NULL if there are no more entries.
        if (strstr(entry->d_name, ".txt")) {  									// Check if the file has a ".txt" extension
            char temp[50];
            strncpy(temp, entry->d_name, strlen(entry->d_name) - 4); 			// Copy the filename without ".txt" extension to a temporary string

            // Find the position of " - " in the filename
            char* title = strstr(temp, " - ");
            if (title) {
                *title = '\0'; 													// Replace " - " with null character to get the title part
                char author[50];
                strcpy(author, title + 3); 										// Get the author part after " - "
                printf("%s by %s\n", temp, author);
            } else {
                printf("%s\n", temp); 											// If " - " not found, print the original filename
            }
        }
    }
    printf("--- End of the List ---\n");

    closedir(directory); // Close the directory
}



/* The renameFile function is for renaming a file
		It declares 2 char arrays
		-oldFilename & -newFilename
		(Also enter the file type)
*/
	void renameFile() {
		char oldFilename[50], newFilename[50];
		
		printf("Enter the current file name(Also the File Type): ");
		fgets(oldFilename, sizeof(oldFilename), stdin);
		oldFilename[strcspn(oldFilename, "\n")] = '\0';
		
		printf("Enter the new file name(Also the File Type): ");
		fgets(newFilename, sizeof(newFilename), stdin);
		newFilename[strcspn(newFilename, "\n")] = '\0';
		
		if (rename(oldFilename, newFilename) == 0) {
				printf("File renamed successfully.\n");
			} else {
				printf("Failed to rename the file.\n");
			}
	} 



// Function to check if the file exists and display its content 
	void isExist() {
		if (file == NULL) {
			printf("\n\tFailed to open the File");
			} else {
				int c;
				system("cls");
				printf("\tContent of the File\n");
				while ((c = fgetc(file)) != EOF) {
					putchar(c);
				}
				fclose(file);
			}
	}



/* This fileupdate function contains the following:
		Update Title
		Update Author
		Update Publication Year
		Update Price
*/
	void fileupdate() {
		
	    fupdate:
	    	
	    titleauthor(&book);
	    FILEname(&book);
	    file = fopen(filename, "r");
	    
	    
	    if (file == NULL) {
		        printf("Failed to open the File");
		        return;
		    } else {
		        int c;
		        system("cls");
		        printf("\tContent of the File:\n");
		        while ((c = fgetc(file)) != EOF) {
		            putchar(c);
		        }
		        fclose(file);
		    }
	
	
	    int choice;
	    printf("\nSelect what to update: ");
	    printf("\n[1] Title");
	    printf("\n[2] Author");
	    printf("\n[3] Publication Year");
	    printf("\n[4] Price");
	    printf("\n[5] Exit");
	    printf("\nEnter Choice: ");
	    scanf("%d", &choice);
	    getchar(); // Consume the newline character left by scanf
	    system("cls");
	
	
		    switch (choice) {
		        case 1: // Update Title
		            free(book.title); // Free the previous memory
		            book.title = (char*)malloc(50 * sizeof(char));
		            printf("Enter Title: ");
		            fgets(book.title, 50, stdin);
		            book.title[strcspn(book.title, "\n")] = '\0';
		            break;
		
		        case 2: // Update Author
		            free(book.author); // Free the previous memory
		            book.author = (char*)malloc(50 * sizeof(char));
		            printf("Enter Author: ");
		            fgets(book.author, 50, stdin);
		            book.author[strcspn(book.author, "\n")] = '\0';
		            break;
		
		        case 3: // Update Publication Year
		            printf("Enter Publication Year: ");
		            scanf("%d", &book.pubyear);
		            getchar(); // Consume the newline character left by scanf
		            break;
		
		        case 4: // Update Price
		            printf("Enter Price: ");
		            scanf("%f", &book.price);
		            getchar(); // Consume the newline character left by scanf
		            break;
		
		        case 5: // Exit
		            exit(0);
		
		        default: // Invalid Choice
		            printf("Invalid Choice");
		            goto fupdate;
		    }
	
	
	    TEMPfilename(&book);
	    file = fopen(filename, "r");
		    if (file == NULL) {
		        printf("Failed to open the file");
		        return;
		    }
	
	
	    tempfile = fopen(temp_filename, "w");
		    if (tempfile == NULL) {
		        printf("File Update Error");
		        return;
		    }
	
	
	    char line[100];
	    
	    while (fgets(line, sizeof(line), file) != NULL) {
		        if (strstr(line, "Title: ")) {
		            fprintf(tempfile, "Title: %s\n", book.title);
		        } else if (strstr(line, "Author: ")) {
		            fprintf(tempfile, "Author: %s\n", book.author);
		        } else if (strstr(line, "Publication Year: ")) {
		            fprintf(tempfile, "Publication Year: %d\n", book.pubyear);
		        } else if (strstr(line, "Price: ")) {
		            fprintf(tempfile, "Price: %.2f\n", book.price);
		        } else {
		            fputs(line, tempfile); // Copy the original line as it is
		        }
		    }
	
	
	    fclose(file);
	    fclose(tempfile);
	
	
	    remove(filename); // Delete the original file
	    rename(temp_filename, filename); // Rename the temporary file to have the same name as the original
		printf("\nFile Updated Successfully.\n");
	}

