# inet3101-lab2

## Database Management Program

This program creates a database and allows a user to add, delete, and view records as well as view the number of records and the size of the database. A short menu is provided that displays which number should be input corresponding with the different options.

Each record is stored as a struct with attributes for its part number, name, size, size metric, and cost.

The printMenu() function simply prints out the menu.

The getInput() function prompts the user for input, and if the integer is not between 1 and 6 it repeatedly prompts the user until a valid integer is given.

The printAll() function loops through each record struct in memory and prints the attributes.

The printNum() function prints the number of records, which is stored as a variable in the program.

The printSize() function prints the total size in bytes of all record structs.

The addRecord() function creates a record struct and prompts the user for input to set each attribute as. New memory space is allocated for all previous records and the new one, and a for loop copies the old record structs to the new memory before the new record struct is added and the old memory space is freed.

The deleteRecord() function checks to see if there are any records to begin with, and if there are, allocates new memory space for each record struct from the current memory space except for the last record struct before freeing the old memory space. It basically copies all records except the last one to a new memory location.

To manage the memory in this program, I am using malloc(). To add a record, memory is allocated using malloc() with the size of a record struct multiplied by (the number of records plus one) as the parameter. To delete a record, malloc() is used to create a new space in memory where all except for the last record struct is copied to.
