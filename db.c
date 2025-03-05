// db.c
// Keegan Volk
#include <stdio.h>
#include <stdlib.h>

struct record {
        int num;
        char name[20]; // up to 20 character names
        float size;
        char metric[4]; // up to 4 characters
        float cost;
};

int main() {
	int num = 0; // number of records
	int recordSize = sizeof(struct record); // size of each record: two floats (8), up to 20 char name, up to 4 char metric, and ints are 2 or 4 bytes depending on the compiler
	int input; // stores valid user input
	struct record *db = malloc(num * recordSize); // the database pointer

	void printMenu() { // prints the menu, for if user input is incorrect
                printf("1: Print all records\n2: Print number of records\n3: Print size of database\n4: Add record\n5: Delete record\n6: Exit\n");
	}

	int getInput() { // prompts for user input until valid input is entered, then is returned
		int tempInput; // temporary variable for checking if integer is valid
		printf("\ndb:input$ ");
		scanf("%d",&tempInput);
		while (tempInput < 1 || tempInput > 6) { // if integer is invalid, repeat until valid integer given
			printf("Invalid input\n");
			printMenu();
			printf("\ndb:input$ ");
			scanf("%d",&tempInput);
		}
		return tempInput;
	}

	void printAll() { // prints all records
		for (int i = 0; i < num; i++) {
			printf("%d: %d | %s | %f | %s | %f \n",i + 1, db[i].num, db[i].name, db[i].size, db[i].metric, db[i].cost);
		}
	}

	void printNum() { // prints the number of records
		printf("Number of records: %d", num);
	}

	void printSize() { // prints the size of the database
		printf("Size of database: %d bytes", num * recordSize);
	}

	void addRecord() { // adds a record, reallocates memory
		struct record newRecord;

		printf("Enter part number: "); // input for the variables
		scanf("%d", &newRecord.num);
		printf("Enter part name (up to 20 characters): ");
		scanf("%s", &newRecord.name);
		printf("Enter part size: ");
		scanf("%f", &newRecord.size);
		printf("Enter part metric (up to 4 characters): ");
		scanf("%s", &newRecord.metric);
		printf("Enter part cost: ");
		scanf("%f", &newRecord.cost);

		struct record *tempDB = malloc(++num * recordSize); // initialize new space with temporary pointer
		for (int i = 0; i < num - 1; i++) { // copy old memory to new memory
			tempDB[i] = db[i];
		}
		tempDB[num - 1] = newRecord;
		free(db);
		db = tempDB; // set db pointer to newly allocated memory
	}

	void deleteRecord() { // deletes a record, reallocates memory
		if (num > 0) {
			struct record *tempDB = malloc(--num * recordSize); // init new space
			for (int i = 0; i < num; i++) { // copy old memory
				tempDB[i] = db[i];
			}
			free(db);
			db = tempDB;
			printf("Record deleted\n");
		} else {
			printf("No records to delete\n");
		}
	}


	printMenu(); // print the menu when the program starts

	while (input != 6) {
		input = getInput();
		switch (input) {
			case 1:
				printAll();
				break;
			case 2:
				printNum();
				break;
			case 3:
				printSize();
				break;
			case 4:
				addRecord();
				break;
			case 5:
				deleteRecord();
				break;
		}
	}
	free(db);
}
