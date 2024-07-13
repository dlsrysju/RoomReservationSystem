/****************************************************************************** 
This is to certify that this project is my own & partners work, based on 
my/our personal efforts in studying and applying the concepts learned. I/we 
have constructed the functions and their respective algorithms and 	
corresponding code by me (and my partner). The program was run, tested, and 
debugged by my own efforts. I further certify that I have not copied in 
part or whole or otherwise plagiarized the work of other students and/or

Carl Justin B. De los Reyes - 12205648 - S11
Carl Justin B. De los Reyes - 12205648 - S11
******************************************************************************/ 

#include <stdio.h>
#include <windows.h> 
#include <conio.h>
#include <string.h>

#define MAX 45

//Structures for Personal Details of User
struct PersonalDetails{	
	char idnumber [51];
	char firstname [51];
	char lastname [51];
	char year [51];
	char program [51];
} details;

//Structures for Storing Rooms per Building
struct RoomInfo {
    char mainroom[51]; //name of room
};

//Structures for Buildings
struct BuildingInfo {
    char mainbuilding[51]; //name of Building
    int nRoom;
    struct RoomInfo rooms[10]; // Assuming a maximum of 10 rooms per building
}; 

//Structures for Reservation Infos of the User
struct ReservationInfo {
	char date [51];
	char time [51];
	int nparticipants;
	char roomtype [51];
	char room [51];
	char buildingname [51];
	struct BuildingInfo buildings[5]; //Assuming a maximum of 5 for buildings
	char description [51];
} reservation;

//Function Prototypes
void red(); //
void green(); //
void reset(); //
void clrBox(); // 
void gotoxy(int x, int y); //
void box(int x1, int y1, int x2, int y2); //
void saveRooms(struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int chosenBuildingIndex); //
int loadRooms(struct PersonalDetails details[], struct ReservationInfo reservation[], int nBuilding, int chosenBuildingIndex); // 
void saveData(struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex); //
int loadBuilding(struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nRoom, int chosenBuildingIndex); //
void saveReservation (struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom,  int chosenBuildingIndex); //
int load(struct PersonalDetails details[], struct ReservationInfo reservation[], int nBuilding, int nRoom, int chosenBuildingIndex); //
int checkReservation(struct PersonalDetails details [], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom); // -- 
int checkReservationLimit(struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex); //--
void MarkedDone(struct PersonalDetails details [], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex); // 
void markreservation(struct PersonalDetails details [], struct ReservationInfo reservation[], int nReservation, int mark_choice, int nBuilding, int nRoom, int chosenBuildingIndex); //
void FilloutRoomReserve(struct PersonalDetails details [], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex); // --
void roomreserve (struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex); //--
void AskTime (struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom,  int chosenBuildingIndex); // --
void displayRR (struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom,  int chosenBuildingIndex); //
void EditPersonal (struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex); // -- 
void displayInfos (struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int nBuilding, int nRoom,  int chosenBuildingIndex); //
void EditReserve (struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int nBuilding, int nRoom,  int chosenBuildingIndex);//--
void ViewRR (struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int nBuilding, int nRoom,  int chosenBuildingIndex); //
void askRoomandBuilding(struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex); //--
void ViewDetails(struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int view_choice, int nBuilding, int nRoom,  int chosenBuildingIndex);
void addRoom(struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex); //
void addBuilding(struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex); //
void adminModule (struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex); //
void displaytieditrr(struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int edit_choice, int nBuilding, int nRoom,  int chosenBuildingIndex);
void EditRRMainPage(struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int edit_choice, int nBuilding, int nRoom,  int chosenBuildingIndex); // -- 
void cancelReservation(struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int cancel_choice, int nBuilding, int nRoom,  int chosenBuildingIndex); // -- 
void DisplayEditRRMainPage(struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex);
void retryMainPage(struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int nBuilding, int nRoom,  int chosenBuildingIndex);		// 	
void displayMainMenu(struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex);	//
void displayMainPage(struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex);	//
void displayCover(struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex);		//

/*
*	Function: red	
*	Description: red color for text
*/
void red() 
{
  	printf("\033[1;31m");
}

/*
*	Function: green	
*	Description: green color for text
*/
void green()
{
 	printf("\033[1;32m");
}

/*
*	Function: reset	
*	Description: white color for text
*/
void reset() 
{
  	printf("\033[0m");
}

/*
*	Function: clrBox
*	Description: removes box, used in UI
*/
void clrBox()
{
    gotoxy(24,6);printf("                                                                         ");
    gotoxy(24,7);printf("                                                                         ");
    gotoxy(24,8);printf("                                                                         ");
    gotoxy(24,9);printf("                                                                         ");
    gotoxy(24,10);printf("                                                                         ");
    gotoxy(24,11);printf("                                                                         ");
    gotoxy(24,12);printf("                                                                         ");
    gotoxy(24,13);printf("                                                                         ");
    gotoxy(24,14);printf("                                                                         ");
    gotoxy(24,15);printf("                                                                         ");
    gotoxy(24,16);printf("                                                                         ");
    gotoxy(24,17);printf("                                                                         ");
    gotoxy(24,18);printf("                                                                         "); 
    gotoxy(24,19);printf("                                                                         ");
    gotoxy(24,20);printf("                                                                         ");
    gotoxy(24,21);printf("                                                                         ");
}

/*
*	Function: gotoxy	
*	Description: moves cursor and was primarily used in UI
*	Parameters : @param : x - x axis for dimension
*				 @param : y - y axis for dimension
*					
*/ 
void gotoxy(int x, int y)
{
    COORD pos = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos); 
}

/*
*	Function: box
*	Description: prompts box for ui
*	Parameters : @param : x1 - dimesnion
*				 @param : y1 - dimension
*				 @param : x2 - dimension
* 				 @param : y2 - dimension
*/ 
void box(int x1, int y1, int x2, int y2)
{
    int i;
    for (i = x1; i <= x2; i++)
    {
        gotoxy(i, y1);
        printf("%c", 196);
        gotoxy(i, y2);
        printf("%c", 196);
    }
    for (i = y1; i <= y2; i++)
    {
        gotoxy(x1, i);
        printf("%c", 179);
        gotoxy(x2, i);
        printf("%c", 179);
    }
    gotoxy(x1, y1);
    printf("%c", 218);
    gotoxy(x1, y2);
    printf("%c", 192);
    gotoxy(x2, y1);
    printf("%c", 191);
    gotoxy(x2, y2);
    printf("%c", 217);
}

/*
*	Function: saveRooms	
*	Description: File handling that saves all the inputted rooms by the admin
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 

void saveRooms(struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int chosenBuildingIndex) {
    FILE *pFile;
    int j, i;

    pFile = fopen("rooms.txt", "w+");						//print all the rooms inputted by the admin in the file
    if (pFile == NULL) {
        printf("Unable to open the file...");
        return;
    }

    for (j = 0; j < nBuilding; j++) {
        fprintf(pFile, "%d\n", reservation[j].buildings[j].nRoom);
        fprintf(pFile, "%s\n", reservation[j].buildings[j].mainbuilding);
        for (i = 0; i < reservation[j].buildings[j].nRoom; i++) {
            fprintf(pFile, "%s\n", reservation[j].buildings[j].rooms[i].mainroom);
        }
    }

    fclose(pFile);
}

/*
*	Function: loadRooms
*	Description: File handling that load the value of the nRoom of the building and this populates the array
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/
int loadRooms(struct PersonalDetails details[], struct ReservationInfo reservation[], int nBuilding, int chosenBuildingIndex) {
    FILE *pFile;
    int i, j;

    pFile = fopen("rooms.txt", "r");
    if (pFile == NULL) {
        reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom = 0;
        return 0; // Return 0 to indicate no rooms were loaded.
    }
																										//get the value of number rooms, specific for a building
    for (j = 0; j < nBuilding; j++) {
        fscanf(pFile, "%d\n", &reservation[j].buildings[j].nRoom);					//populates array
        fgets(reservation[j].buildings[j].mainbuilding, sizeof(reservation[j].buildings[j].mainbuilding), pFile);
        reservation[j].buildings[j].mainbuilding[strcspn(reservation[j].buildings[j].mainbuilding, "\n")] = '\0';
        
        for (i = 0; i < reservation[j].buildings[j].nRoom; i++) {
            fgets(reservation[j].buildings[j].rooms[i].mainroom, sizeof(reservation[j].buildings[j].rooms[i].mainroom), pFile);
            reservation[j].buildings[j].rooms[i].mainroom[strcspn(reservation[j].buildings[j].rooms[i].mainroom, "\n")] = '\0';
        }
    }

    fclose(pFile);

    return reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom;
}

/*
*	Function: saveData
*	Description: File handling that saves all the Building inputted by the admin
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 
void saveData(struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex) {
    FILE *pFile;
    int i;

    pFile = fopen("data.txt", "w+");					//prints all buildings in file

    if (pFile == NULL) {
        printf("Unable to create the file...");
        return;
    }

    fprintf(pFile, "%d\n", nBuilding);
    for (i = 0; i < nBuilding; i++) {
        fprintf(pFile, "%s\n", reservation[i].buildings[i].mainbuilding);
    }

    fclose(pFile);
}

/*
*	Function: loadBuilding
*	Description: File handling that load or give value for nBuilding ad this populates array
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 
int loadBuilding(struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nRoom, int chosenBuildingIndex) {
    FILE *pFile;
    int nBuilding = 0;
    int i;

    pFile = fopen("data.txt", "r");
    if (pFile == NULL) {
        nBuilding = 0;
    }

    // Read the number of reservations from the file
    fscanf(pFile, "%d\n", &nBuilding);

    // Loop to read the details array
    for (i = 0; i < nBuilding; i++) {
        fgets(reservation[i].buildings[i].mainbuilding, sizeof(reservation[i].buildings[i].mainbuilding), pFile);
reservation[i].buildings[i].mainbuilding[strcspn(reservation[i].buildings[i].mainbuilding, "\n")] = '\0';

    }

    fclose(pFile);

    return nBuilding;
}

/*
*	Function: saveReservation	
*	Description: File handling that saves all the inputted data from the user
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 
void saveReservation (struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex)
{
	FILE *pFile;
	int i;
	
	pFile = fopen ("reservationdetails.txt", "w+");
	
    if (pFile == NULL) {
        printf("Unable to create the file...");
        return;
    }
    
    fprintf(pFile, "%d\n", nReservation);
    
    for (i=0;i<nReservation;i++)							//prints all the input from the user to file
    {
    	fprintf(pFile, "%s\n%s\n%s\n%s\n%s\n%s\n%s\n%d\n%s\n%s\n%s\n", 
						details[i].firstname, 
						details[i].lastname, 
						details[i].idnumber, 
						details[i].program, 
						details[i].year, 
						reservation[i].date, 
						reservation[i].time, 
						reservation[i].nparticipants,
						reservation[i].roomtype, 
						reservation[i].room, 
						reservation[i].description);
	}
	
	fclose(pFile);
}

/*
*	Function: load	
*	Description: get the value of the number of reservations exists in the program from the file 
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of users
*/ 
int load(struct PersonalDetails details[], struct ReservationInfo reservation[], int nBuilding, int nRoom, int chosenBuildingIndex) {
    FILE *pFile;
    int nReservation = 0;
    int i;

    pFile = fopen("reservationdetails.txt", "r");
    if (pFile == NULL) {
        nReservation = 0;
    }

    // Read the number of reservations from the file
    fscanf(pFile, "%d\n", &nReservation);

    // Loop to read the details array
    for (i = 0; i < nReservation; i++) {
        fgets(details[i].firstname, sizeof(details[i].firstname), pFile);
        details[i].firstname[strcspn(details[i].firstname, "\n")] = '\0';

        fgets(details[i].lastname, sizeof(details[i].lastname), pFile);
        details[i].lastname[strcspn(details[i].lastname, "\n")] = '\0';

        fgets(details[i].idnumber, sizeof(details[i].idnumber), pFile);
        details[i].idnumber[strcspn(details[i].idnumber, "\n")] = '\0';

        fgets(details[i].program, sizeof(details[i].program), pFile);
        details[i].program[strcspn(details[i].program, "\n")] = '\0';

        fgets(details[i].year, sizeof(details[i].year), pFile);
        details[i].year[strcspn(details[i].year, "\n")] = '\0';
    }

    // Loop to read the reservation array
    for (i = 0; i < nReservation; i++) {
        fgets(reservation[i].date, sizeof(reservation[i].date), pFile);
        reservation[i].date[strcspn(reservation[i].date, "\n")] = '\0';

        fgets(reservation[i].time, sizeof(reservation[i].time), pFile);
        reservation[i].time[strcspn(reservation[i].time, "\n")] = '\0';

        fscanf(pFile, "%d\n", &reservation[i].nparticipants);

        fgets(reservation[i].roomtype, sizeof(reservation[i].roomtype), pFile);
        reservation[i].roomtype[strcspn(reservation[i].roomtype, "\n")] = '\0';

        fgets(reservation[i].room, sizeof(reservation[i].room), pFile);
        reservation[i].room[strcspn(reservation[i].room, "\n")] = '\0';

        fgets(reservation[i].description, sizeof(reservation[i].description), pFile);
        reservation[i].description[strcspn(reservation[i].description, "\n")] = '\0';
    }

    fclose(pFile);

    return nReservation;
}

/*
*	Function: checkReservation	
*	Description: check if the reservation consit of same time, date, room
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 
int checkReservation(struct PersonalDetails details [], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom){
   
    int count = 0;
    int i;
    
	for (i=0;i<nReservation;i++)
    {
           
	        if (strcmp(reservation[i].date, reservation[nReservation].date) == 0 &&				//checks if same time, room date
            strcmp(reservation[i].room, reservation[nReservation].room) == 0 &&
			strcmp(reservation[i].time, reservation[nReservation].time)==0) {
            count++;	
			if(count==1){

				return count;
			}				      
		}		
    }
    return count;			//return count that will check later on
}

/*
*	Function: markReservation	
*	Description: aalows Mark reservation as done
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 
void markreservation(struct PersonalDetails details [], struct ReservationInfo reservation[], int nReservation, int mark_choice, int nBuilding, int nRoom, int chosenBuildingIndex)
{
	char ch;
	int choice;
	
    fflush(stdin);  // Clear the input buffer
    clrBox();  // Clear the console display in a specified box area
    box(20, 5, 100, 22);
	
	// Display personal and reservation details for the selected reservation
	gotoxy(38,6);printf("---------------------------------------------");
	gotoxy(38,7);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,8);printf("---------------------------------------------");
	gotoxy(38,9);printf("              \033[1mPersonal Details\033[0m");			
	gotoxy(38,10);printf("\033[1m  First Name:\033[0m %s", details[mark_choice].firstname);
	gotoxy(59,10);printf("\033[1m   Last Name:\033[0m %s", details[mark_choice].lastname);
	gotoxy(38,11);printf("\033[1m  ID Number:\033[0m %s", details[mark_choice].idnumber);
	gotoxy(59,11);printf("\033[1m   Year:\033[0m %s", details[mark_choice].year);
	gotoxy(38,12);printf("\033[1m  Program:\033[0m %s", details[mark_choice].program);
	gotoxy(38,13);printf("---------------------------------------------");
	gotoxy(38,14);printf("            \033[1m Reservation Details\033[0m");		
	gotoxy(38,15);printf("\033[1m  Room Type:\033[0m %s", reservation[mark_choice].roomtype);
	gotoxy(61,15);printf("\033[1m   Room:\033[0m %s", reservation[mark_choice].room);
	gotoxy(38,16);printf("\033[1m  Date:\033[0m %s", reservation[mark_choice].date);
	gotoxy(59,16);printf("\033[1m   Number of Participants:\033[0m %d", reservation[mark_choice].nparticipants);
	gotoxy(38,17);printf("\033[1m  Time:\033[0m %s", reservation[mark_choice].time);
	gotoxy(38,18);printf("\033[1m  Description of use:\033[0m %s", reservation[mark_choice].description);
	gotoxy(38,19);printf("---------------------------------------------");
	gotoxy(35,20);printf("         \033[1mMark Reservation as Done\033[0m \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
	gotoxy(76,20);scanf("%c", &ch);	// Read user confirmation for reservation cancellation
	
	if (ch == 'y' || ch == 'Y')
	{
		fflush(stdin);  // Clear the input buffer
        clrBox();  // Clear the console display in a specified box area
        box(20, 5, 100, 22);
		
		nReservation--;		// Decrease the total number of reservations
		saveReservation (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		
		// Display cancellation successful message
		gotoxy(38,7);printf("---------------------------------------------");
		gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
		gotoxy(38,9);printf("---------------------------------------------");
		gotoxy(44,12);printf(" Reservation Marked as Completed!");						/// Color
		gotoxy(38,15);printf("---------------------------------------------");
		gotoxy(38,16);printf("     [1] Main Menu         [2] Homepage");
		gotoxy(38,17);printf("---------------------------------------------");
		gotoxy(38,19);printf("            Enter Choice [1-2]: ");
		gotoxy(70,19);scanf("%d", &choice);		//CHANGE COLORRRR
		
		switch (choice)
			{
				case 1:
					displayMainMenu (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);	// Go back to the main menu
				break;
				case 2:
					displayCover(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);		// Go back to the homepage
				break;
				default:
					clrBox();
					red();
					gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
					reset();
					gotoxy(44,13);printf("Please enter correct input!");
					gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
					gotoxy(72,14);scanf(" %c", &ch);// Read user input for the next action
							
					if (ch == 'Y' || ch == 'y')
					{   
						clrBox();
				    	fflush(stdin);
				    	markreservation(details,reservation, nReservation, mark_choice,nBuilding, nRoom, chosenBuildingIndex) ;
				    }
				    else
				    {
						return;
				    }			
			}
	}
	else if (ch == 'N' || ch == 'n')
	{
			markreservation(details,reservation, nReservation, mark_choice,nBuilding, nRoom, chosenBuildingIndex) ;		
	}
	else		
		clrBox();
		red();
		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");			// Display error message for invalid input
		reset();
		gotoxy(44,13);printf("Please enter correct input!");
		gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");		 // Ask the user if they want to try again or exit
		gotoxy(72,14);scanf(" %c", &ch);
							
		if (ch == 'Y' || ch == 'y')
			{   
			clrBox();
		   	fflush(stdin);
		   	markreservation(details,reservation, nReservation, mark_choice,nBuilding, nRoom, chosenBuildingIndex) ; 		
			}
			else
			{
			exit(0);
		    }
}

/*
*	Function: MarkedDone	
*	Description: display the input of user on what reservation to mark as done
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 
void MarkedDone(struct PersonalDetails details [], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex){
	
	int mark_choice;
	int choice, i; 
	char ch;
	
	if (nReservation <= 0)	// Check if the file is empty or there are no reservations
	{
	fflush(stdin);
	clrBox();
	box(20,5,100,22);
	gotoxy(38,7);printf("---------------------------------------------");
	gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,9);printf("---------------------------------------------");
	gotoxy(38,12);printf("            \033[1mNo Reservation Exists!\033[0m");
	gotoxy(38,15);printf("---------------------------------------------");
	gotoxy(38,16);printf("     [1] Back to Homepage");
	gotoxy(59,16);printf("         [2] Back");
	gotoxy(38,17);printf("---------------------------------------------");
	gotoxy(38,19);printf("           \033[1mEnter Choice [1-3]: \033[0m");
	gotoxy(69,19);scanf("%d", &choice);
	
	switch (choice)
	{
		case 1:
			displayCover (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		break;
		case 2:
			adminModule(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		break;
		default:
			clrBox();
  			red();
    		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
   			reset();
   			gotoxy(44,13);printf("Please enter correct input!");
   			gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
			gotoxy(80,14);scanf(" %c", &ch);
		
			if (ch == 'Y' || ch == 'y')	// If the user wants to try again, clear the screen and repeat the view reservations process
    		{   
        	clrBox();
       		fflush(stdin);
        	MarkedDone(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
    		}
    		else
    		{		// If the user chooses not to try again, exit the program
				return;
    		}
		break;	
		}
	}
	else{
	fflush(stdin);
	clrBox();
	box(20,5,100,22);
	
	// Display the header for the view reservations page
	gotoxy(38,7);printf("---------------------------------------------");
	gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,9);printf("---------------------------------------------");
	gotoxy(38,10);printf("         \033[1mNumber of Reservations : %d\033[0m", nReservation);
	gotoxy(38,11);printf("     NAME       ROOM TYPE         TIME");																		//FIX FILE HANDLING
	
	// Display the list of reservations
	for(i=0;i<nReservation;i++){
		gotoxy(38,12 + i);printf("  %d. %s        %s     %s", i+1, details[i].firstname, reservation[i].roomtype, reservation[i].time);
	}
	
	gotoxy(38,18);printf("---------------------------------------------");
	gotoxy(38,19);printf("  \033[1m[1] Mark Reservation as Done     [2] Back");
	gotoxy(38,20);printf("---------------------------------------------");
	gotoxy(38,21);printf("           \033[1mEnter Choice [1-2]: \033[0m");
	gotoxy(69,21);scanf("%d", &choice);
		
	switch(choice)
	{
		case 1: 
			fflush(stdin);
			clrBox();
			box(20,5,100,22);
			
			gotoxy(38,7);printf("---------------------------------------------");
			gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,9);printf("---------------------------------------------");
			gotoxy(38,10);printf("         \033[1mNumber of Reservations : %d\033[0m", nReservation);
			gotoxy(38,11);printf("     NAME       ROOM TYPE         TIME");
			for(i=0;i<nReservation;i++){
			gotoxy(38, 12+i);printf("  %d. %s        %s     %s", i+1, details[i].firstname, reservation[i].roomtype, reservation[i].time);		//prompt all reservation
			}
			gotoxy(38,20);printf("---------------------------------------------");
			gotoxy(37,21);printf("\033[1mEnter the number to Mark Reservation as Done:\033[0m");				
			gotoxy(83,21);scanf("%d", &mark_choice);
			
			if (mark_choice>nReservation || mark_choice<=0)
			{
			clrBox();
		    red();
		    gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		    reset();
		    gotoxy(44,13);printf("Reservation does not exist");
		    gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
			gotoxy(80,14);scanf(" %c", &ch);
				
			if (ch == 'Y' || ch == 'y')
		    {   
		        clrBox();
		        fflush(stdin);
		        DisplayEditRRMainPage(details , reservation ,  nReservation, nBuilding, nRoom, chosenBuildingIndex);
		    }
		    else
		    {
				return;
		    }	
			}
				markreservation(details,reservation, nReservation, mark_choice-1,nBuilding, nRoom, chosenBuildingIndex) ;
		break;
		case 2:
			adminModule(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
			break;
		default:
				clrBox();
  			red();
    		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
   			reset();
   			gotoxy(44,13);printf("Please enter correct input!");
   			gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
			gotoxy(80,14);scanf(" %c", &ch);
		
			if (ch == 'Y' || ch == 'y')	// If the user wants to try again, clear the screen and repeat the view reservations process
    		{   
        	clrBox();
       		fflush(stdin);
        	MarkedDone(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
    		}
    		else
    		{		// If the user chooses not to try again, exit the program
				return;
    		}
			break;	
	}
	}
}

/*
*	Function: checkReservationLimit	
*	Description: checks the reservation of a particylar user that limits up to 3 reservations per person
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*				 @returns the value of reservation count for a specific user
*/ 
int checkReservationLimit(struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex) {	

    int reservationCount = 0;
    int i;

	for (i=0;i<nReservation;i++)
    {
	        if (strcmp(details[i].idnumber, details[nReservation].idnumber) == 0 &&
            strcmp(details[i].firstname, details[nReservation].firstname) == 0) {
            reservationCount++;	
			if(reservationCount>=3){			//user can only make reservations of 3
				return reservationCount;
			}				      
		}		
    }
	// return reservtaion count of user
    return reservationCount;
}

/*
*	Function: FiilloutRoomReserve	
*	Description: Asks for the reservation details of the user, and continuation of reservation that asks for personal details of the user
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 
void FilloutRoomReserve(struct PersonalDetails details [], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex)	
{
	char ch;
	int choice, i;
	char initialBuilding[61];
	char initialRoom[61];
	int roomIndex = -1;
	int reservationLimit;
	
		fflush(stdin);
		clrBox();
		box(20,5,100,22);																					//Asks for rooms, buildings and participants and more of reservation details
		gotoxy(38,6);printf("---------------------------------------------");
		gotoxy(38,7);printf("              \033[1mROOM RESERVATION\033[0m");
		gotoxy(38,8);printf("---------------------------------------------");
		gotoxy(34,9);printf("NOTE: Room Format (XYYYY); X-Building, Y-Room Number ");						//Pre-Condition
		gotoxy(38,11);printf("\033[1mPlease fill-out the following:");
		gotoxy(38,14);printf("Date of Reservation [dd/mm/yyyy]: ");
		fflush(stdin);														//CHECK DATE BASED SA LOADED FILE
		gotoxy(72,14);fgets(reservation[nReservation].date, sizeof(reservation[nReservation].date), stdin);
        			reservation[nReservation].date[strlen(reservation[nReservation].date) - 1] = '\0';
		fflush(stdin);
		gotoxy(38,15);printf("Number of Participants: ");
		gotoxy(62,15);scanf("%d", &reservation[nReservation].nparticipants);
		fflush(stdin);
		
		while (reservation[nReservation].nparticipants > 45) {												//Condition that limits the user not to input particiants that is beyond 45 people
        clrBox();
        box(20, 5, 100, 22);
        gotoxy(38, 6);
        printf("---------------------------------------------");
        gotoxy(38, 7);
        printf("              \033[1mROOM RESERVATION\033[0m");
        gotoxy(38, 8);
        printf("---------------------------------------------");
        gotoxy(38, 12);
        printf("\033[31mERROR!\033[0m Maximum number of participants is 45.");
        gotoxy(37, 14);
        printf("Please enter a valid number of participants: ");											//Asks for another input when user inputs is invalid
        gotoxy(82, 14);	
        scanf("%d", &reservation[nReservation].nparticipants);
        fflush(stdin);
    }
		
		clrBox();
		box(20,5,100,22);
		gotoxy(38,6);printf("---------------------------------------------");
		gotoxy(38,7);printf("              \033[1mROOM RESERVATION\033[0m");
		gotoxy(38,8);printf("---------------------------------------------");
		gotoxy(38,9);printf("            [BUILDINGS AVAILABLE]");
		
		if(nBuilding==0)
		{
			gotoxy(38,10);printf("     No Buildings Exists in the Program Yet");		
			gotoxy(38,11);printf("     Wait for the Admin to add Building first!");	
			gotoxy(38,12);printf("---------------------------------------------");
			gotoxy(38,13);printf("     [1] Back to Main Menu     [2] Retry");
			gotoxy(38,14);printf("---------------------------------------------");
			gotoxy(38,15);printf("           \033[1mEnter Choice [1-2]: \033[0m");
			gotoxy(38,15);scanf("%d", &choice);
			
			switch(choice)
			{
				case 1: 
					displayMainMenu(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					break;
				case 2: 
					FilloutRoomReserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					break;
				default:
					clrBox();
		  			red();
		    		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		   			reset();
		   			gotoxy(44,13);printf("Please enter correct input!");
		   			gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
					gotoxy(80,14);scanf(" %c", &ch);
				
					if (ch == 'Y' || ch == 'y')
		    		{   
			        	clrBox();
			       		fflush(stdin);
			        	roomreserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		    		}
		    		else
		    		{
						return;
		    		}	
				break;		
			}		
		}
		else{
			
	        for (i = 0; i < nBuilding; i++)
	        {
	            gotoxy(53, 11 + i); printf("  %s", reservation[i].buildings[i].mainbuilding);
	        }
			gotoxy(38,19);printf("---------------------------------------------");
			gotoxy(45,20);printf("  Enter the building where");
			gotoxy(45,21);printf("  you want to reserve room:");
			fflush(stdin);							
			gotoxy(73,21);fgets(initialBuilding, sizeof(initialBuilding), stdin);
	        			initialBuilding[strlen(initialBuilding) - 1] = '\0';
	        		
			int chosenBuildingIndex = -1; // Initialize chosenBuildingIndex to -1 before the loop
	
			for (i = 0; i < nBuilding; i++) {
			    if (strcmp(initialBuilding, reservation[i].buildings[i].mainbuilding) == 0) {
			        chosenBuildingIndex = i;
			        // Exit the loop once a match is found
			        break;
			    }
			}
		
			if (chosenBuildingIndex == -1)
		            {
		                clrBox();
		                box(20, 5, 100, 22);
		                gotoxy(38, 7);printf("---------------------------------------------");
		                gotoxy(38, 8);printf("              \033[1mROOM RESERVATION\033[0m");
						gotoxy(38, 9);printf("---------------------------------------------");
						gotoxy(48, 12);printf("\033[31mERROR!\033[0m Building not found!");
						gotoxy(38, 15);printf("---------------------------------------------");
		                gotoxy(38, 16);printf("     [1] Retry    [2] Back to Main Menu");
		                gotoxy(38, 17);printf("---------------------------------------------");
		                gotoxy(53, 19);printf("Choice: ");
		                gotoxy(61, 19);scanf("%d", &choice);
		
		                switch (choice)
		                {
		                    case 1:
		                        FilloutRoomReserve( details ,  reservation,  nReservation,  nBuilding,  nRoom, chosenBuildingIndex);
		                        break;
		                    case 2:
		                        displayMainMenu(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		                        break;
		                    default:	//change
		                        break;
		                }
		            }	
			
			else{
			reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom = loadRooms(details, reservation, nBuilding, chosenBuildingIndex);
			if(reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom == 0)
			{
				clrBox();
				box(20, 5, 100, 22);
		        gotoxy(38, 7);printf("---------------------------------------------");
		        gotoxy(38, 8);printf("              \033[1mROOM RESERVATION\033[0m");			//if no room building exists
				gotoxy(38, 9);printf("---------------------------------------------");
				gotoxy(38,12);printf("     No Rooms Exists in the Building Yet");		
				gotoxy(38,13);printf("    Wait for the Admin to add Room first!");	
				gotoxy(38,18);printf("---------------------------------------------");
				gotoxy(38,19);printf("  [1] Back to Main Menu       [2] Retry");
				gotoxy(38,20);printf("---------------------------------------------");
				gotoxy(38,21);printf("           \033[1mEnter Choice [1-2]: \033[0m");
				gotoxy(73,21);scanf("%d", &choice);
				
			switch(choice)
			{
				case 1: 
					displayMainMenu(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					break;
				case 2: 
					FilloutRoomReserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					break;
				default:
					clrBox();
		  			red();
		    		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		   			reset();
		   			gotoxy(44,13);printf("Please enter correct input!");
		   			gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
					gotoxy(80,14);scanf(" %c", &ch);
				
					if (ch == 'Y' || ch == 'y')
		    		{   
			        	clrBox();
			       		fflush(stdin);
			        	roomreserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		    		}
		    		else
		    		{
						return;
		    		}	
				break;
					
				}
			}
			else{
				clrBox();
				box(20, 5, 100, 22);
		        gotoxy(38, 6);printf("---------------------------------------------");
		        gotoxy(38, 7);printf("              \033[1mROOM RESERVATION\033[0m");
				gotoxy(38, 8);printf("---------------------------------------------");
				gotoxy(38, 9);printf("         [ROOMS AVAILABLE IN %s]", initialBuilding);						//prompt all the rooms for the chosen building of user
				
			    for (i = 0; i < reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom; i++)
			    {
			        gotoxy(49, 11 + i);printf("      %s", reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].rooms[i].mainroom);
			    }
			    
				gotoxy(38,20);printf("---------------------------------------------");
				gotoxy(40,21);printf("Enter the room you want to reserve: ");
				fflush(stdin);
				gotoxy(40,69);fgets(initialRoom, sizeof(initialRoom), stdin);
	        			initialRoom[strlen(initialRoom) - 1] = '\0';
			
				for (i = 0; i < reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom; i++) {
				    if (strcmp(initialRoom, reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].rooms[i].mainroom) == 0) {
				        roomIndex = i;
				        // Exit the loop once a match is found
				        break;
				    }
				}
				
				if(roomIndex == -1)
				{
		                clrBox();
		                box(20, 5, 100, 22);
		                gotoxy(38, 7);printf("---------------------------------------------");
		                gotoxy(38, 8);printf("              \033[1mROOM RESERVATION\033[0m");
						gotoxy(38, 9);printf("---------------------------------------------");				//error when room is not found in file
						gotoxy(48, 12);printf("\033[31mERROR!\033[0m Room is not Found!");
						gotoxy(38, 15);printf("---------------------------------------------");
		                gotoxy(38, 16);printf("     [1] Retry    [2] Back to Main Menu");
		                gotoxy(38, 17);printf("---------------------------------------------");
		                gotoxy(53, 19);printf("Choice: ");
		                gotoxy(61, 19);scanf("%d", &choice);
		
		                switch (choice)
		                {
		                    case 1:
		                        FilloutRoomReserve( details ,  reservation,  nReservation,  nBuilding,  nRoom, chosenBuildingIndex);
		                        break;
		                    case 2:
		                        displayMainMenu(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		                        break;
		                    default:	//change
		                        break;
		                }
		            }
					else{
						strcpy(reservation[nReservation].buildingname, initialBuilding);
						strcpy(reservation[nReservation].room, initialRoom);				
					}	
				}
				
			reservationLimit = checkReservation( details, reservation, nReservation, nBuilding, nRoom);
 	
		 	if (reservationLimit == 1)																						// if same reservation in time, date, room				
		 	{
		 	fflush(stdin);
			clrBox();
			box(20,5,100,22);
			
			gotoxy(38,7);printf("---------------------------------------------");
			gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,9);printf("---------------------------------------------");
			red();
		 	gotoxy(40,11);printf("    \033[1mERROR!\033[0m");
		 	reset();													//error message
		 	gotoxy(40,13);printf("    Sorry! Reservation already exists!");					
		 	gotoxy(38,15);printf("---------------------------------------------");
		 	gotoxy(37,16);printf(" [1] Back to Main Menu       [2] Fill-up Again");
		 	gotoxy(38,17);printf("---------------------------------------------");
		 	fflush(stdin);
		    gotoxy(38,19);printf("           \033[1mEnter Choice [1-2]: \033[0m");
		    gotoxy(69,19);scanf("%d", &choice);
		 	
			switch(choice)
			{
				case 1: displayMainMenu(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				break;
				case 2: roomreserve (details, reservation, nReservation, nBuilding, nRoom,chosenBuildingIndex);
				break;
				default:	
		        	clrBox();
		  			red();
		    		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		   			reset();
		   			gotoxy(44,13);printf("Please enter correct input!");
		   			gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
					gotoxy(80,14);scanf(" %c", &ch);
				
					if (ch == 'Y' || ch == 'y')
		    		{   
			        	clrBox();
			       		fflush(stdin);
			        	roomreserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		    		}
		    		else
		    		{
						return;
		    		}	
				break;
				}
			}
				
	        fflush(stdin);
	        clrBox();
		    box(20, 5, 100, 22);
		    gotoxy(38, 7);printf("---------------------------------------------");
		    gotoxy(38, 8);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38, 9);printf("---------------------------------------------");
			
			gotoxy(38,13);printf("Description of Activity: ");
			gotoxy(63,13);fgets(reservation[nReservation].description, sizeof(reservation[nReservation].description), stdin);
	        			reservation[nReservation].description[strlen(reservation[nReservation].description) - 1] = '\0';	
			gotoxy(38,18);printf("---------------------------------------------");
			gotoxy(38,20);printf("  Press [N] to proceed to next page: ");
		    gotoxy(75, 20);scanf("%c", &ch);
		    
	        	if (ch == 'n' || ch == 'N')
	        	{
	        		clrBox();
	            	fflush(stdin);
	            	displayInfos(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
	       		}
	       		else
	       		{
	            	clrBox();
	  				red();
	    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");																	//When Input is invalid to proceed in the next page
	   				reset();
	   				gotoxy(44,13);printf("Please enter correct input!");
	   				gotoxy(44,14);printf("Would you like to fill-up again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
					gotoxy(84,14);scanf(" %c", &ch);
			
					if (ch == 'Y' || ch == 'y')
	    			{   
	       			clrBox();
	       			fflush(stdin);
	       			FilloutRoomReserve(details, reservation,  nReservation, nBuilding, nRoom, chosenBuildingIndex);	
	    			}
	    			else
	    			{
					return;
					}
				}
			}
		}
	}

/*
*	Function: roomreserve	
*	Description: Asks user for his reservation details 
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 

void roomreserve (struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex) {
	int choice, reservationLimit;
	char ch;
	
	fflush(stdin);
	clrBox();
	box(20,5,100,22);
	
	gotoxy(38,7);printf("---------------------------------------------");
	gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,9);printf("---------------------------------------------");
	gotoxy(38,11);printf("  \033[1mPlease fill-out the following:");											//Asks the user's personal details
	gotoxy(38,13);printf("  ID Number: ");
	fflush(stdin);
	gotoxy(51,13);fgets(details[nReservation].idnumber, sizeof(details[nReservation].idnumber), stdin);
        			details[nReservation].idnumber[strlen(details[nReservation].idnumber) - 1] = '\0';
	fflush(stdin);
	gotoxy(38,14);printf("  First Name: ");
	gotoxy(52,14);fgets(details[nReservation].firstname, sizeof(details[nReservation].firstname), stdin);
        			details[nReservation].firstname[strlen(details[nReservation].firstname) - 1] = '\0';
	fflush(stdin);
    
	reservationLimit = checkReservationLimit(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
 	
 	if (reservationLimit >= 3)																					//When the maximum reservation of the user reached
 	{
 	fflush(stdin);
	clrBox();
	box(20,5,100,22);
	
	gotoxy(38,7);printf("---------------------------------------------");
	gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,9);printf("---------------------------------------------");
	red();
 	gotoxy(40,11);printf("\033[1mERROR!\033[0m");
 	reset();
 	gotoxy(40,13);printf("Sorry! Maximum reservation has been reached!");					
 	gotoxy(38,15);printf("---------------------------------------------");
 	gotoxy(37,16);printf(" [1] Back to Main Menu       [2] Fill-up Again");
 	gotoxy(38,17);printf("---------------------------------------------");
 	fflush(stdin);
    gotoxy(38,19);printf("           \033[1mEnter Choice [1-2]: \033[0m");
    gotoxy(69,19);scanf("%d", &choice);
 	
	switch(choice)
	{
		case 1: displayMainMenu(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		break;
		case 2: roomreserve (details, reservation, nReservation, nBuilding, nRoom,chosenBuildingIndex);
		break;
		default:	
        	clrBox();
  			red();
    		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
   			reset();
   			gotoxy(44,13);printf("Please enter correct input!");
   			gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
			gotoxy(80,14);scanf(" %c", &ch);
		
			if (ch == 'Y' || ch == 'y')
    		{   
	        	clrBox();
	       		fflush(stdin);
	        	roomreserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
    		}
    		else
    		{
				return;
    		}	
		break;
		}
	}
		
	fflush(stdin);
	gotoxy(38,15);printf("  Last Name: ");
	gotoxy(51,15);fgets(details[nReservation].lastname, sizeof(details[nReservation].lastname), stdin);
        			details[nReservation].lastname[strlen(details[nReservation].lastname) - 1] = '\0';
	fflush(stdin);
	gotoxy(38,16);printf("  Year in College (Ex: 1st Year):");
	gotoxy(72,16);fgets(details[nReservation].year, sizeof(details[nReservation].year), stdin);
        			details[nReservation].year[strlen(details[nReservation].year) - 1] = '\0';
	fflush(stdin);
	gotoxy(38,17);printf("  Program (Ex: BSCS):\033[0m");
	gotoxy(60,17);fgets(details[nReservation].program, sizeof(details[nReservation].program), stdin);
        			details[nReservation].program[strlen(details[nReservation].program) - 1] = '\0';
	
	fflush(stdin);
	clrBox();
	box(20,5,100,22);
	
	gotoxy(38,7);printf("---------------------------------------------");														// asks for the room reservation details of the user
	gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,9);printf("---------------------------------------------");
	gotoxy(42,10);printf("           \033[1mTYPE OF ROOM:\033[0m");
	gotoxy(42,12);printf("        [1] Classroom");
	gotoxy(42,13);printf("        [2] Seminar Room");
	gotoxy(42,14);printf("        [3] Auditorium ");
	gotoxy(42,15);printf("        [4] Training Room");
	gotoxy(42,16);printf("        [5] Back\n");
	gotoxy(38,18);printf("---------------------------------------------");
	gotoxy(38,20);printf("            \033[1mEnter Choice [1-5]: \033[0m");
	gotoxy(70,20);scanf("%d", &choice);
	
	switch (choice) {
    	case 1:
       		strcpy(reservation[nReservation].roomtype, "Classroom");
        	break;
    	case 2:
        	strcpy(reservation[nReservation].roomtype, "Seminar");
        	break;
    	case 3:
        	strcpy(reservation[nReservation].roomtype, "Auditorium");
        	break;
    	case 4:
        	strcpy(reservation[nReservation].roomtype, "Training");
        	break;
    	case 5:
        	displayMainMenu(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
        	break;
    	default:
        	clrBox();
  			red();
    		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
   			reset();
   			gotoxy(44,13);printf("Please enter correct input!");
   			gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
			gotoxy(80,14);scanf(" %c", &ch);
		
			if (ch == 'Y' || ch == 'y')
    		{   
	        	clrBox();
	       		fflush(stdin);
	        	roomreserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
    		}
    		else
    		{
				return;
    		}	
        break;
	}	
	
	fflush(stdin);
	clrBox();
	box(20,5,100,22);
	
	gotoxy(38,6);printf("---------------------------------------------");
	gotoxy(38,7);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,8);printf("---------------------------------------------");
	gotoxy(50,9);printf("\033[1mTIME SLOTS AVAILABLE\033[0m");
	gotoxy(35,11);printf("           \033[0;32m\033[1m[1]\033[0m MTHF\033[0m");	//INPUT COLOR
	gotoxy(35,12);printf("          09:15-10:45");
	gotoxy(35,13);printf("          11:00-12:30");
	gotoxy(35,14);printf("          12:45-14:15");
	gotoxy(35,15);printf("          14:30-16:00");
	gotoxy(35,16);printf("          16:15-17:45");
	gotoxy(35,17);printf("          18:00-19:00");
	gotoxy(62,11);printf("      \033[0;32m\033[1m[2]\033[0m WS\033[0m");			//INPUT COLOR
	gotoxy(62,12);printf("    09:00-12:00");
	gotoxy(62,13);printf("    13:00-16:00");
	gotoxy(62,14);printf("    16:15-19:15");
	gotoxy(38,19);printf("---------------------------------------------");
	gotoxy(38,20);printf("            \033[1mEnter Choice [1-2]: \033[0m");
	gotoxy(70,20);scanf("%d", &choice);
	
	switch (choice)																					//Asks time
	{
		case 1:
			fflush(stdin);
			clrBox();
			box(20,5,100,22);
			gotoxy(38,6);printf("---------------------------------------------");
			gotoxy(38,7);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,8);printf("---------------------------------------------");
			gotoxy(50,9);printf("\033[1mTIME SLOTS AVAILABLE\033[0m");
			gotoxy(50,11);printf("       \033[1m MTHF\033[0m");
			gotoxy(50,12);printf("  [1] 09:15-10:45");
			gotoxy(50,13);printf("  [2] 11:00-12:30");
			gotoxy(50,14);printf("  [3] 12:45-14:15");
			gotoxy(50,15);printf("  [4] 14:30-16:00");
			gotoxy(50,16);printf("  [5] 16:15-17:45");
			gotoxy(50,17);printf("  [6] 18:00-19:00");
			gotoxy(38,19);printf("---------------------------------------------");
			gotoxy(38,20);printf("            \033[1mEnter Choice [1-6]: \033[0m");
			gotoxy(70,20);scanf("%d", &choice);
			
			switch (choice){																								
				case 1:
					strcpy(reservation[nReservation].time, "09:15-10:45");
				break;
				case 2: 
					strcpy(reservation[nReservation].time, "11:00-12:30");
				break;
				case 3:
					strcpy(reservation[nReservation].time, "12:45-14:15");
				break;
				case 4:
					strcpy(reservation[nReservation].time, "14:30-16:00");
				break;
				case 5:
					strcpy(reservation[nReservation].time, "16:15-17:45");
				break;
				case 6:
					strcpy(reservation[nReservation].time, "18:00-19:00");
				break;
				default:
					clrBox();
  					red();
    				gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
   					reset();
   					gotoxy(44,13);printf("Please enter correct input!");
   					gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
					gotoxy(80,14);scanf(" %c", &ch);
		
					if (ch == 'Y' || ch == 'y')
    				{   
	       				clrBox();
	       				fflush(stdin);
	       				roomreserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
    				}
    				else
    				{
						return;
				break;
    				}	
				}
		break;
		case 2:
			fflush(stdin);
			clrBox();
			box(20,5,100,22);
			gotoxy(38,7);printf("---------------------------------------------");
			gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,9);printf("---------------------------------------------");
			gotoxy(50,10);printf("\033[1mTIME SLOTS AVAILABLE\033[0m\n");
			gotoxy(50,12);printf("         \033[1mWS\033[0m\n");
			gotoxy(50,13);printf("  [1] 09:00-12:00");
			gotoxy(50,14);printf("  [2] 13:00-16:00");
			gotoxy(50,15);printf("  [3] 16:15-19:15");
			gotoxy(38,17);printf("---------------------------------------------");
			gotoxy(38,19);printf("            \033[1mEnter Choice [1-3]: \033[0m");
			gotoxy(70,19);scanf("%d", &choice);
			
			switch (choice){																
				case 1:
					strcpy(reservation[nReservation].time, "09:00-12:00");
				break;
				case 2: 
					strcpy(reservation[nReservation].time, "13:00-16:00");
				break;
				case 3:
					strcpy(reservation[nReservation].time, "16:15-19:15");
				break;
				default:
					clrBox();
  					red();
    				gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
   					reset();
   					gotoxy(44,13);printf("Please enter correct input!");
   					gotoxy(44,14);printf("Would you like to fill-up again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
					gotoxy(84,14);scanf(" %c", &ch);
		
					if (ch == 'Y' || ch == 'y')
    				{   
	       				clrBox();
	       				fflush(stdin);
	       				roomreserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
    				}
    				else
    				{
						return;
					}
				break;
				}
		break;
		default:																										// if the user inputs invalid input
			clrBox();
  			red();
   			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
   			reset();
   			gotoxy(44,13);printf("Please enter correct input!");
   			gotoxy(44,14);printf("Would you like to fill-up again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
			gotoxy(84,14);scanf(" %c", &ch);
			
			if (ch == 'Y' || ch == 'y')
   			{   
	       		clrBox();
	       		fflush(stdin);
	       		roomreserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
    		}
    		else
    		{
				return;
			}
		break;	
	}
		
	AskTime (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);								//asks for additional time and continuation of room reserve
	}

/*
*	Function: AskTime
*	Description: Allows the user to add additional time for his/her reservation, and the next time slot will be added to his reservation
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 

void AskTime (struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex)
{
	fflush(stdin);
	clrBox();
	box(20,5,100,22);
	
	char ch, ch1, ch2, ch3, ch4, ch5, ch6, ch7;
																												//Asks the user if he/she want to add additional time
	gotoxy(38,7);printf("---------------------------------------------");
	gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,9);printf("---------------------------------------------");
	gotoxy(38,10);printf("   \033[1mNOTE: The next time slot available will");
	gotoxy(38,11);printf("         be added to your time slot\033[0m");
	gotoxy(38,14);printf("     Do you wish to add another time");
	gotoxy(38,15);printf("     for your reservation? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");
	gotoxy(72,15);scanf("  %c", &ch);

	if (ch == 'y' || ch == 'Y')
 	{																												//checks if the user's input is valid
		if (strcmp(reservation[nReservation].time,"09:15-10:45")==0)
		{
			strcat(reservation[nReservation].time, " & 11:00-12:30");
		}
		else if(strcmp(reservation[nReservation].time,"11:00-12:30")==0)
		{
			strcat(reservation[nReservation].time, " & 12:45-14:15");
		}
		else if(strcmp(reservation[nReservation].time, "12:45-14:15")==0)
		{
			strcat(reservation[nReservation].time, " & 14:30-16:00");
		}
		else if(strcmp(reservation[nReservation].time,"14:30-16:00")==0)
		{
			strcat(reservation[nReservation].time, " & 16:15-17:45");
		}
		else if(strcmp(reservation[nReservation].time,"16:15-17:45")==0)
		{
			strcat(reservation[nReservation].time, " & 18:00-19:00");
		}
		else if(strcmp(reservation[nReservation].time,"18:00-19:00")==0)
		{
			fflush(stdin);
			clrBox();
			box(20,5,100,22);
			
			gotoxy(38,7);printf("---------------------------------------------");
			gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,9);printf("---------------------------------------------");
			gotoxy(38,13);printf("   \033[0;31mSorry!\033[0m No additional time can be added! ");		//When the user choose the last available time slot, as no addtional time can be added
			gotoxy(38,16);printf("---------------------------------------------");
			gotoxy(38,18);printf("   Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
			fflush(stdin);
			gotoxy(80,18);scanf("%c", &ch2);
			
			if(ch2 == 'y' || ch2 == 'Y')
			{
				AskTime (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
			}
			else if (ch2 == 'n' || ch2 == 'N')
			{
				FilloutRoomReserve (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);	
			}
			else
			{
			clrBox();
  			red();
   			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
   			reset();
   			gotoxy(44,13);printf("Please enter correct input!");
   			gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
   			fflush(stdin);
			gotoxy(80,14);scanf("%c", &ch3);
			
			if (ch3 == 'Y' || ch3 == 'y')
   			{   
       		clrBox();
       		fflush(stdin);
       		AskTime (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
    		}
    		else
    		{
				return;	
			}
			}
		}
		else if (strcmp(reservation[nReservation].time,"09:00-12:00")==0)
		{
			strcat(reservation[nReservation].time, " & 13:00-16:00");
		}
		else if (strcmp(reservation[nReservation].time,"13:00-16:00")==0)
		{
			strcat(reservation[nReservation].time, " & 16:15-19:15");
		}
		else if (strcmp(reservation[nReservation].time, "16:15-19:15")==0)
		{
			
			fflush(stdin);
			clrBox();
			box(20,5,100,22);
			//If invalid input
			gotoxy(38,7);printf("---------------------------------------------");
			gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,9);printf("---------------------------------------------");
			gotoxy(38,12);printf("   \033[0;31mSorry!\033[0m No additional time can be added!");
			gotoxy(38,15);printf("---------------------------------------------");
			gotoxy(38,17);printf("   Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");			//Allows the user to input again
			fflush(stdin);
			gotoxy(80,17);scanf("%c", &ch4);
			
			if(ch4 == 'y' || ch4 == 'Y')
			{
				AskTime (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);				//*****PROBLEM****
			}
			else if (ch4 == 'n' || ch4 == 'N')
			{
				FilloutRoomReserve (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);	
			}
			else
			{
			clrBox();
  			red();
   			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
   			reset();
   			gotoxy(44,13);printf("Please enter correct input!");
   			gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
   			fflush(stdin);
			gotoxy(80,14);scanf("%c", &ch5);
			
			if (ch5 == 'Y' || ch5 == 'y')
   			{   
	       		clrBox();
	       		fflush(stdin);
	       		AskTime (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
    		}
    		else
    		{
			return;	
			}
			}
		}
	}
	else if (ch == 'n' || ch == 'N')
	{																															//if the user choose "No"
		FilloutRoomReserve (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);	
		}
	else
		{
			clrBox();
  			red();
   			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
   			reset();
   			gotoxy(44,13);printf("Please enter correct input!");
   			gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
   			fflush(stdin);
			gotoxy(80,14);scanf("%c", &ch7);
			
			if (ch7 == 'Y' || ch7 == 'y')
   			{   
       		clrBox();
       		fflush(stdin);
       		AskTime (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
    		}
    		else
    		{
			exit(0);	
			}
		}
		
			fflush(stdin);
			clrBox();
			box(20,5,100,22);
																															//This will save the new time of the user
			gotoxy(38,7);printf("---------------------------------------------");
			gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,9);printf("---------------------------------------------");
			gotoxy(38,12);printf("  Your new time is %s ", reservation[nReservation].time);
			gotoxy(38,15);printf("---------------------------------------------");
			gotoxy(38,17);printf("      Press [S] to save your new time:");
			fflush(stdin);
			gotoxy(77,17);scanf("%c", &ch1);
			
			if(ch1 == 's' || ch1 == 'S')
			{
				FilloutRoomReserve (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
			}
			else 
			{
				clrBox();
	  			red();
	    		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
	   			reset();
	   			gotoxy(44,13);printf("Please enter correct input!");
	   			gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
	   			fflush(stdin);
				gotoxy(72,14);scanf("%c", &ch6);
		
				if (ch6 == 'Y' || ch6 == 'y')
	    		{   
	       		clrBox();
	       		fflush(stdin);
	       		AskTime (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
	    		}
	    		else
	    		{
				exit(0);
				}
			}
	
}

/*
*	Function: displayRR	
*	Description: Displays the room reserved informations made by the user before saving it in the file
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 

void displayRR (struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex)
{
	char ch, ch1;
	int choice;
	
		fflush(stdin);
		clrBox();
		box(20,5,100,22);
		//prompts infos
		gotoxy(38,6);printf("----------------------------------------------");
		gotoxy(38,7);printf("              \033[1mROOM RESERVATION\033[0m");
		gotoxy(38,8);printf("----------------------------------------------");
		gotoxy(38,9);printf("             \033[1mRESERVATION DETAILS\033[0m");
		gotoxy(38,11);printf("  \033[1mType of Room Reserved:\033[0m %s", reservation[nReservation].roomtype);
		gotoxy(38,12);printf("  \033[1mRoom:\033[0m %s - %s", reservation[nReservation].buildingname, reservation[nReservation].room);
		gotoxy(38,13);printf("  \033[1mDate\033[0m %s", reservation[nReservation].date);
		gotoxy(38,14);printf("  \033[1mTime:\033[0m %s", reservation[nReservation].time);
		gotoxy(38,15);printf("  \033[1mNumber of Participants:\033[0m %d", reservation[nReservation].nparticipants);
		gotoxy(38,16);printf("  \033[1mDescription of Activity:\033[0m %s", reservation[nReservation].description);
		gotoxy(38,18);printf("----------------------------------------------");
		gotoxy(41,19);printf("\033[1m[1]\033[0m Save        \033[1m[2]\033[0m Edit        \033[1m[3]\033[0m Back");
		gotoxy(38,20);printf("----------------------------------------------");
		gotoxy(38,21);printf("  Choice: ");
		gotoxy(48,21);scanf("%d", &choice);
		
			switch (choice)
			{
				case 1: // If the user chooses "Save," increment the reservation count, save the reservation, and prompt for further action
					nReservation++;
					saveReservation (details, reservation, nReservation, nBuilding, nRoom,chosenBuildingIndex);
					
					fflush(stdin);
					clrBox();
					box(20,5,100,22);
					
					gotoxy(38,7);printf("----------------------------------------------");
					gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
					gotoxy(38,9);printf("----------------------------------------------");
					gotoxy(49,12);printf(" \033[1mSaved Succesfully !\033[0m");
					gotoxy(38,15);printf("----------------------------------------------");
					gotoxy(46,17);printf(" \033[1mWould you like to do");
					gotoxy(40,18);printf("       another reservation? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");
					fflush(stdin);
					gotoxy(75,18);scanf(" %c", &ch1);
					
					if(ch1 == 'Y' || ch1 == 'y')	// If the user wants to make another reservation, display the cover page
					{
						displayCover(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					}
					else if (ch1 == 'N' || ch1 == 'n')	// If the user chooses not to make another reservation, display a thank-you message and exit the program
					{
						fflush(stdin);
						clrBox();
						box(20,5,100,22);
						
						gotoxy(44,13);printf("Thank you for your reservation!");
						gotoxy(44,13);
						getch();
						return;
					}
					else	// If the user enters an invalid choice, display an error message and prompt for re-entry
					{
  					clrBox();
   	  				red();
   	    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
   	   				reset();
   	   				gotoxy(44,13);printf("Please enter correct input!");
   	   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");
   					gotoxy(72,14);scanf(" %c", &ch);
			
					if (ch == 'Y' || ch == 'y')
	    			{   
   	       			clrBox();
  	       			fflush(stdin);
 	       			displayRR(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex); 			/////TO EDIT: CHANGE THISSSS
	    			}
	    			else
	    			{
						return;
					}
				}			
				break;
				case 2:
					EditReserve (details, reservation, nReservation, nBuilding, nRoom,chosenBuildingIndex);	// If the user chooses "Edit," allow them to edit the reservation details
				break;
				case 3:
					displayInfos(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);	// If the user chooses "Back", will lead them to Main Menu
				break;
				default:
					clrBox();
	  				red();
	    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
	   				reset();
	   				gotoxy(44,13);printf("Please enter correct input!");
	   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");
					gotoxy(72,14);scanf(" %c", &ch);
			
					if (ch == 'Y' || ch == 'y')
	    			{   
   	       			clrBox();
   	       			fflush(stdin);
 	 	       			displayCover(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex); 			/////TO EDIT: CHANGE THISSSS
	    			}
	    			else
	    			{
						return;
					}
				break;
			}
}

/*
*	Function: displayInfos	
*	Description: Displays the user's personal informations before saving it in file
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/  

void displayInfos (struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex)
{
	fflush(stdin);
	clrBox();
	box(20,5,100,22);
	
	int choice;
	char ch;
	
	// Display the User's Info
	gotoxy(38,6);printf("----------------------------------------------");
	gotoxy(38,7);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,8);printf("----------------------------------------------");
	gotoxy(38,9);printf("              \033[1mPERSONAL DETAILS\033[0m");
	gotoxy(38,11);printf("  \033[1mFirst Name of Reserver:\033[0m %s", details[nReservation].firstname);
	gotoxy(38,12);printf("  \033[1mLast Name of Reserver:\033[0m %s", details[nReservation].lastname);
	gotoxy(38,13);printf("  \033[1mID Number:\033[0m %s", details[nReservation].idnumber);
	gotoxy(38,14);printf("  \033[1mYear:\033[0m %s", details[nReservation].year);
	gotoxy(38,15);printf("  \033[1mProgram:\033[0m %s", details[nReservation].program);
	gotoxy(38,17);printf("----------------------------------------------");
	gotoxy(41,18);printf("       \033[1m[1]\033[0m Next          \033[1m[2]\033[0m Edit");
	gotoxy(38,19);printf("----------------------------------------------");
	gotoxy(38,20);printf("  Choice: ");
	gotoxy(48,20);scanf("%d", &choice);

	switch (choice)
	{
		case 1: 
			displayRR(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);		// If the user chooses "Next," display the room reservation details
		break;
		case 2:
			EditPersonal (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);		// If the user chooses "Edit," allow them to edit their personal details
		break;
		default:		// If the user enters an invalid choice, display an error message and prompt for re-entry
			clrBox();
  			red();
    		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
   			reset();
   			gotoxy(44,13);printf("Please enter correct input!");
   			gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
			gotoxy(84,14);scanf(" %c", &ch);
	
			if (ch == 'Y' || ch == 'y')	// If the user wants to try again, clear the screen and repeat the process
   			{   
        		clrBox();
          		fflush(stdin);
         		displayInfos(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
    		}
    		else
    		{
				return; // If the user chooses not to try again, exit the program
			}
		break;
	}
}

/*
*	Function: Personal	
*	Description: Allows the user to edit his/her personal details after inputting all his/her details in the program, and also before saving the details in the program
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 
void EditPersonal (struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex) //No cooment yet
{
	
	int choice;
	char fname[31];
	char lname[31];
	char idno[31];
	char yr[31];
	char prog[31];
	char ch;

	fflush(stdin);
	clrBox();
	box(20,5,100,22);
	
	gotoxy(38,7);printf("---------------------------------------------");
	gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,9);printf("---------------------------------------------");
	gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
	gotoxy(38,12);printf("              [1] First Name");
	gotoxy(38,13);printf("              [2] Last Name");
	gotoxy(38,14);printf("              [3] ID Number");
	gotoxy(38,15);printf("              [4] Year");
	gotoxy(38,16);printf("              [5] Program");
	gotoxy(38,17);printf("              [6] Back");
	gotoxy(38,19);printf("---------------------------------------------");
	gotoxy(48,20);printf("  \033[1mEnter Choice [1-6]: \033[0m");
	gotoxy(70,20);scanf("%d", &choice);
																		//for editing, prompting the new updated changes
	switch (choice)
	{
		case 1:
			fflush(stdin);
			clrBox();
			box(20,5,100,22);
			gotoxy(38,7);printf("---------------------------------------------");
			gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,9);printf("---------------------------------------------");
			gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
			gotoxy(38,13);printf("           Current First Name: %s", details[nReservation].firstname);
			gotoxy(38,14);printf("           Enter New First Name: ");
			gotoxy(71,14);fgets(fname, sizeof(fname), stdin);
        				fname[strlen(fname) - 1] = '\0';
			gotoxy(38,17);printf("---------------------------------------------");
			gotoxy(38,19);printf("        \033[1mPress [S] to save your edit : \033[0m");
			gotoxy(76,19);scanf("%c", &ch);
			
			if(ch == 's' || ch == 'S')
			{
					strcpy(details[nReservation].firstname, fname);
				displayInfos (details,reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
			}		
			else
			{
            	clrBox();
  				red();
    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
   				reset();
   				gotoxy(44,13);printf("Please enter correct input! Edit didn't save!'");
   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
				gotoxy(84,14);scanf(" %c", &ch);
		
				if (ch == 'Y' || ch == 'y')
    			{   
       			clrBox();
       			fflush(stdin);
       			EditPersonal(details, reservation, nReservation, nBuilding, nRoom,chosenBuildingIndex);
    			}
    			else
    			{
				exit(0);
				}
			}
			break;
			case 2:
				fflush(stdin);
				clrBox();
				box(20,5,100,22);
				gotoxy(38,7);printf("---------------------------------------------");
				gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
				gotoxy(38,9);printf("---------------------------------------------");
				gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
				gotoxy(38,13);printf("           Current Last Name: %s", details[nReservation].lastname);
				gotoxy(38,14);printf("           Enter New Last Name:");
				gotoxy(70,14);fgets(lname, sizeof(lname), stdin);
        				lname[strlen(lname) - 1] = '\0';
				gotoxy(38,17);printf("---------------------------------------------");
				gotoxy(38,19);printf("        \033[1mPress [S] to save your edit : \033[0m");
				gotoxy(76,19);scanf("%c", &ch);
			
				if(ch == 's' || ch == 'S')
				{
						strcpy(details[nReservation].lastname, lname);
					displayInfos (details,reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				}		
				else
				{
      	      		clrBox();
  					red();
    				gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
   					reset();
   					gotoxy(44,13);printf("Please enter correct input! Edit didn't save!'");
	   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");
					gotoxy(72,14);scanf(" %c", &ch);
			
					if (ch == 'Y' || ch == 'y')
    				{   
	       				clrBox();
	       				fflush(stdin);
	       				EditPersonal(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
    				}
    				else
    				{
						return;
					}
				}
				break;
			case 3:
				fflush(stdin);
				clrBox();
				box(20,5,100,22);
				gotoxy(38,7);printf("---------------------------------------------");
				gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
				gotoxy(38,9);printf("---------------------------------------------");
				gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
				gotoxy(38,13);printf("           Current ID Number: %s", details[nReservation].idnumber);
				gotoxy(38,14);printf("           Enter New ID number: ");
				gotoxy(70,14);fgets(idno, sizeof(idno), stdin);
        				idno[strlen(idno) - 1] = '\0';
				gotoxy(38,17);printf("---------------------------------------------");
				gotoxy(38,19);printf("        \033[1mPress [S] to save your edit : \033[0m");
				gotoxy(76,19);scanf("%c", &ch);
				
				if(ch == 's' || ch == 'S')
				{
					strcpy(details[nReservation].idnumber, idno);
					displayInfos (details,reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				}		
				else
				{
	            	clrBox();
	  				red();
	    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
	   				reset();
	   				gotoxy(44,13);printf("Please enter correct input! Edit didn't save!");
	   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
					gotoxy(72,14);scanf(" %c", &ch);
			
					if (ch == 'Y' || ch == 'y')
	    			{   
		       			clrBox();
		       			fflush(stdin);
		       			EditPersonal(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
	    			}
	    			else
	    			{
						return;
					}
				}
				break;
			case 4:
				fflush(stdin);
				clrBox();
				box(20,5,100,22);
				gotoxy(38,7);printf("---------------------------------------------");
				gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
				gotoxy(38,9);printf("---------------------------------------------");
				gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
				gotoxy(38,13);printf("           Current Year: %s", details[nReservation].year);
				gotoxy(38,14);printf("           Enter New Year: ");
				gotoxy(65,14);fgets(yr, sizeof(yr), stdin);
        				yr[strlen(yr) - 1] = '\0';
				gotoxy(38,17);printf("---------------------------------------------");
				gotoxy(38,19);printf("        \033[1mPress [S] to save your edit : \033[0m");
				gotoxy(76,19);scanf("%c", &ch);
				
				if(ch == 's' || ch == 'S')
				{
					strcpy(details[nReservation].year, yr);
					displayInfos (details,reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				}		
				else
				{
	            	clrBox();
	  				red();
	    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
	   				reset();
	   				gotoxy(44,13);printf("Please enter correct input! Edit didn't save!");
	   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
					gotoxy(72,14);scanf(" %c", &ch);
			
					if (ch == 'Y' || ch == 'y')
	    			{   
		       			clrBox();
		       			fflush(stdin);
		       			EditPersonal(details,reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
	    			}
	    			else
	    			{
						return;
					}
				}
				break;
			case 5:
				fflush(stdin);
				clrBox();
				box(20,5,100,22);
				gotoxy(38,7);printf("---------------------------------------------");
				gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
				gotoxy(38,9);printf("---------------------------------------------");
				gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
				gotoxy(38,13);printf("           Current Program: %s\n", details[nReservation].program);
				gotoxy(38,14);printf("           Enter New program: ");
				gotoxy(68,14);fgets(prog, sizeof(prog), stdin);
        					prog[strlen(prog) - 1] = '\0';
				gotoxy(38,17);printf("---------------------------------------------");
				gotoxy(38,19);printf("        \033[1mPress [S] to save your edit : \033[0m");
				gotoxy(76,19);scanf("%c", &ch);
				
				if(ch == 's' || ch == 'S')
				{
					strcpy(details[nReservation].program, prog);
					displayInfos (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				}		
				else
				{
	            	clrBox();
	  				red();
	    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
	   				reset();
	   				gotoxy(44,13);printf("Please enter correct input! Edit didn't save!'");
	   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
					gotoxy(72,14);scanf(" %c", &ch);
			
					if (ch == 'Y' || ch == 'y')
	    			{   
		       			clrBox();
		       			fflush(stdin);
		       			EditPersonal(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
	    			}
	    			else
	    			{
						return;
					}
				}
				break;
			case 6:
				displayInfos (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				break;
			default:
				clrBox();
  				red();
    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
   				reset();
   				gotoxy(44,13);printf("Please enter correct input!");
   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
				gotoxy(72,14);scanf(" %c", &ch);
		
				if (ch == 'Y' || ch == 'y')
    			{   
       			clrBox();
       			fflush(stdin);
       			EditPersonal(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
    			}
    			else
    			{
					return;
				}
			break;			
	}
}

/*
*	Function: askRoomandBuilding	
*	Description: Used in edit details, used for conviniency
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 

void askRoomandBuilding(struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex) 
{
	char initialBuilding[51];
	char initialRoom [51];
	int i, choice;
	char ch;
	int roomIndex = -1;
	
	fflush(stdin);																		//USED IN EDIT FUNCTION
	clrBox();
	box(20,5,100,22);
	gotoxy(38,6);printf("---------------------------------------------");
	gotoxy(38,7);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,8);printf("---------------------------------------------");
	gotoxy(38,9);printf("            [BUILDINGS AVAILABLE]");
																										//prompts buildings available
				        for (i = 0; i < nBuilding; i++)
				        {
				            gotoxy(53, 11 + i); printf("  %s", reservation[i].buildings[i].mainbuilding);
				        }
						gotoxy(38,19);printf("---------------------------------------------");
						gotoxy(45,20);printf("  Enter the building where");
						gotoxy(45,21);printf("  you want to reserve room:");
						fflush(stdin);							
						gotoxy(73,21);fgets(initialBuilding, sizeof(initialBuilding), stdin);
				        			initialBuilding[strlen(initialBuilding) - 1] = '\0';
				        		
						chosenBuildingIndex = -1; // Initialize chosenBuildingIndex to -1 before the loop
				
						for (i = 0; i < nBuilding; i++) {
						    if (strcmp(initialBuilding, reservation[i].buildings[i].mainbuilding) == 0) {
						        chosenBuildingIndex = i;
						        // Exit the loop once a match is found
						        break;
						    }
						}
					
						if (chosenBuildingIndex == -1)
					            {
					                clrBox();
					                box(20, 5, 100, 22);
					                gotoxy(38, 7);printf("---------------------------------------------");
					                gotoxy(38, 8);printf("              \033[1mROOM RESERVATION\033[0m");
									gotoxy(38, 9);printf("---------------------------------------------");
									gotoxy(48, 12);printf("\033[31mERROR!\033[0m Building not found!");
									gotoxy(38, 15);printf("---------------------------------------------");
					                gotoxy(38, 16);printf("     [1] Retry    [2] Back to Main Menu");
					                gotoxy(38, 17);printf("---------------------------------------------");
					                gotoxy(53, 19);printf("Choice: ");
					                gotoxy(61, 19);scanf("%d", &choice);
					
					                switch (choice)
					                {
					                    case 1:
					                        askRoomandBuilding( details ,  reservation,  nReservation,  nBuilding,  nRoom, chosenBuildingIndex);
					                        break;
					                    case 2:
					                        displayMainMenu(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					                        break;
					                    default:	//change
					                        break;
					                }
					            }	
						
						else{
						reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom = loadRooms(details, reservation, nBuilding, chosenBuildingIndex);
						if(reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom == 0)
						{
							clrBox();
							box(20, 5, 100, 22);
					        gotoxy(38, 7);printf("---------------------------------------------");
					        gotoxy(38, 8);printf("              \033[1mROOM RESERVATION\033[0m");
							gotoxy(38, 9);printf("---------------------------------------------");
							gotoxy(38,12);printf("     No Rooms Exists in the Building Yet");		
							gotoxy(38,13);printf("    Wait for the Admin to add Room first!");	
							gotoxy(38,18);printf("---------------------------------------------");
							gotoxy(38,19);printf("  [1] Back to Main Menu       [2] Retry");
							gotoxy(38,20);printf("---------------------------------------------");
							gotoxy(38,21);printf("           \033[1mEnter Choice [1-2]: \033[0m");
							gotoxy(73,21);scanf("%d", &choice);
							
						switch(choice)
						{
							case 1: 
								displayMainMenu(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
								break;
							case 2: 
								askRoomandBuilding(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
								break;
							default:
								clrBox();
					  			red();
					    		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
					   			reset();
					   			gotoxy(44,13);printf("Please enter correct input!");
					   			gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
								gotoxy(80,14);scanf(" %c", &ch);
							
								if (ch == 'Y' || ch == 'y')
					    		{   
						        	clrBox();
						       		fflush(stdin);
						        	roomreserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					    		}
					    		else
					    		{
									return;
					    		}	
							break;
								
							}
						}
						else{
							clrBox();
							box(20, 5, 100, 22);
					        gotoxy(38, 6);printf("---------------------------------------------");
					        gotoxy(38, 7);printf("              \033[1mROOM RESERVATION\033[0m");
							gotoxy(38, 8);printf("---------------------------------------------");
							gotoxy(38, 9);printf("         [ROOMS AVAILABLE IN %s]", initialBuilding);				//prompts all available rooms
							
						    for (i = 0; i < reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom; i++)
						    {
						        gotoxy(49, 11 + i);printf("      %s", reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].rooms[i].mainroom);
						    }
						    
							gotoxy(38,20);printf("---------------------------------------------");
							gotoxy(40,21);printf("Enter the room you want to reserve: ");
							fflush(stdin);
							gotoxy(40,69);fgets(initialRoom, sizeof(initialRoom), stdin);
				        			initialRoom[strlen(initialRoom) - 1] = '\0';
						
							for (i = 0; i < reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom; i++) {
							    if (strcmp(initialRoom, reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].rooms[i].mainroom) == 0) {
							        roomIndex = i;
							        // Exit the loop once a match is found
							        break;
							    }
							}
							
							if(roomIndex == -1)
							{
					                clrBox();
					                box(20, 5, 100, 22);
					                gotoxy(38, 7);printf("---------------------------------------------");
					                gotoxy(38, 8);printf("              \033[1mROOM RESERVATION\033[0m");
									gotoxy(38, 9);printf("---------------------------------------------");
									gotoxy(48, 12);printf("\033[31mERROR!\033[0m Room is not Found!");
									gotoxy(38, 15);printf("---------------------------------------------");
					                gotoxy(38, 16);printf("     [1] Retry    [2] Back to Main Menu");
					                gotoxy(38, 17);printf("---------------------------------------------");
					                gotoxy(53, 19);printf("Choice: ");
					                gotoxy(61, 19);scanf("%d", &choice);
					
					                switch (choice)
					                {
					                    case 1:
					                        FilloutRoomReserve( details ,  reservation,  nReservation,  nBuilding,  nRoom, chosenBuildingIndex);
					                        break;
					                    case 2:
					                        displayMainMenu(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					                        break;
					                    default:	//change
					                        break;
					                }
			          }
					else{
			strcpy(reservation[nReservation].buildingname, initialBuilding);
		strcpy(reservation[nReservation].room, initialRoom);				
			}	
		}
}
}

/*
*	Function: EditReserve
*	Description: Allows the user to edit his reservation details after inputting all his details, and also before saving the details
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 

void EditReserve (struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex) 	//No comment Yet
{
	char petsa [21];
	int dadalo;
	char desc [51];
	int choice;
	char ch;

	fflush(stdin);
	clrBox();
	box(20,5,100,22);
	//options on what to edit
	gotoxy(38,7);printf("---------------------------------------------");
	gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,9);printf("---------------------------------------------");
	gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
	gotoxy(38,12);printf("            [1] Date");
	gotoxy(38,13);printf("            [2] Time");
	gotoxy(38,14);printf("            [3] Number of Participants");
	gotoxy(38,15);printf("            [4] Type of Room");
	gotoxy(38,16);printf("            [5] Room");
	gotoxy(38,17);printf("            [6] Description of Activity");
	gotoxy(38,18);printf("            [7] Back");
	gotoxy(38,20);printf("---------------------------------------------");
	gotoxy(48,21);printf("  \033[1mEnter Choice [1-7]: \033[0m");
	gotoxy(70,21);scanf("%d", &choice);
	
	switch (choice)
	{
		case 1:
			fflush(stdin);
			clrBox();
			box(20,5,100,22);
			gotoxy(38,7);printf("---------------------------------------------");
			gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,9);printf("---------------------------------------------");
			gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
			gotoxy(38,13);printf("           Current Date: %s", reservation[nReservation].date);
			gotoxy(38,14);printf("           Enter New Date: ");
			gotoxy(65,14);fgets(petsa, sizeof(petsa), stdin);
        				petsa[strlen(petsa) - 1] = '\0';
			gotoxy(38,17);printf("---------------------------------------------");
			gotoxy(38,19);printf("        \033[1mPress [S] to save your edit : \033[0m");
			gotoxy(76,19);scanf("%c", &ch);
			
			if(ch == 's' || ch == 'S')
			{
				strcpy(reservation[nReservation].date, petsa);
				displayRR (details,reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
			}		
			else
			{
	           	clrBox();
	  			red();
	   			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
	   			reset();
	   			gotoxy(44,13);printf("Please enter correct input! Edit didn't save!");
	   			gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
				gotoxy(72,14);scanf(" %c", &ch);
		
				if (ch == 'Y' || ch == 'y')
	   			{   
	   			clrBox();
    			fflush(stdin);
	       		EditReserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
	    		}
	   			else
	   			{
				return;
				}
			}
			break;
			case 2:
				fflush(stdin);
				clrBox();
				box(20,5,100,22);
				
				gotoxy(38,6);printf("---------------------------------------------");
				gotoxy(38,7);printf("              \033[1mROOM RESERVATION\033[0m");
				gotoxy(38,8);printf("---------------------------------------------");
				gotoxy(50,9);printf("\033[1mTIME SLOTS AVAILABLE\033[0m");
				gotoxy(35,11);printf("           \033[0;32m\033[1m[1]\033[0m MTHF\033[0m");	//INPUT COLOR
				gotoxy(35,12);printf("          9:15-10:45");
				gotoxy(35,13);printf("          11:00-12:30");
				gotoxy(35,14);printf("          12:45-14:15");
				gotoxy(35,15);printf("          14:30-16:00");
				gotoxy(35,16);printf("          16:15-17:45");
				gotoxy(35,17);printf("          18:00-19:00");
				gotoxy(62,11);printf("      \033[0;32m\033[1m[2]\033[0m WS\033[0m");			//INPUT COLOR
				gotoxy(62,12);printf("    09:00-12:00");
				gotoxy(62,13);printf("    13:00-16:00");
				gotoxy(62,14);printf("    16:15-19:15");
				gotoxy(38,19);printf("---------------------------------------------");
				gotoxy(38,20);printf("            \033[1mEnter Choice [1-2]: \033[0m\n");
				gotoxy(70,20);scanf("%d", &choice);
				
				switch (choice)
				{
					case 1:
						fflush(stdin);
						clrBox();
						box(20,5,100,22);
						gotoxy(38,6);printf("---------------------------------------------");
						gotoxy(38,7);printf("              \033[1mROOM RESERVATION\033[0m");
						gotoxy(38,8);printf("---------------------------------------------");
						gotoxy(50,9);printf("\033[1mTIME SLOTS AVAILABLE\033[0m");
						gotoxy(50,11);printf("       \033[1m MTHF\033[0m");
						gotoxy(50,12);printf("  [1] 09:15-10:45");
						gotoxy(50,13);printf("  [2] 11:00-12:30");
						gotoxy(50,14);printf("  [3] 12:45-14:15");
						gotoxy(50,15);printf("  [4] 14:30-16:00");
						gotoxy(50,16);printf("  [5] 16:15-17:45");
						gotoxy(50,17);printf("  [6] 18:00-19:00");
						gotoxy(38,19);printf("---------------------------------------------");
						gotoxy(38,20);printf("            \033[1mEnter Choice [1-6]: \033[0m");
						gotoxy(70,20);scanf("%d", &choice);
						
						switch (choice){																								//CHECK TIME BASED SA LOADED FILE
							case 1:
								strcpy(reservation[nReservation].time, "09:15-10:45");
							break;
							case 2: 
								strcpy(reservation[nReservation].time, "11:00-12:30");
							break;
							case 3:
								strcpy(reservation[nReservation].time, "12:45-14:15");
							break;
							case 4:
								strcpy(reservation[nReservation].time, "14:30-16:00");
							break;
							case 5:
								strcpy(reservation[nReservation].time, "16:15-17:45");
							break;
							case 6:
								strcpy(reservation[nReservation].time, "18:00-19:00");
							break;
							default:
								clrBox();
			  					red();
			    				gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
			   					reset();
			   					gotoxy(44,13);printf("Please enter correct input!");
			   					gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
								gotoxy(80,14);scanf(" %c", &ch);
					
								if (ch == 'Y' || ch == 'y')
			    				{   
			       				clrBox();
			       				fflush(stdin);
			       				EditReserve(details, reservation, nReservation, nBuilding, nRoom,chosenBuildingIndex);
			    				}
			    				else
			    				{
									// EDIT
							break;
		    					}	
							}
						break;
				case 2:
					fflush(stdin);
					clrBox();
					box(20,5,100,22);
					gotoxy(38,7);printf("---------------------------------------------");
					gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
					gotoxy(38,9);printf("---------------------------------------------");
					gotoxy(50,10);printf("\033[1mTIME SLOTS AVAILABLE\033[0m");
					gotoxy(50,12);printf("      \033[1mWS033[0m");
					gotoxy(50,13);printf("  [1] 09:00-12:00");
					gotoxy(50,14);printf("  [2] 13:00-16:00");
					gotoxy(50,15);printf("  [3] 16:15-19:15");
					gotoxy(38,17);printf("---------------------------------------------");
					gotoxy(38,19);printf("            \033[1mEnter Choice [1-3]: \033[0m");
					gotoxy(70,19);scanf("%d", &choice);
					
					switch (choice){																//CHECK TIME BASED SA LOADED FILE
						case 1:
							strcpy(reservation[nReservation].time, "09:00-12:00");
						break;
						case 2: 
							strcpy(reservation[nReservation].time, "13:00-16:00");
						break;
						case 3:
							strcpy(reservation[nReservation].time, "16:15-19:15");
						break;
						default:
							clrBox();
		  					red();
		    				gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		   					reset();
		   					gotoxy(44,13);printf("Please enter correct input!");
		   					gotoxy(44,14);printf("Would you like to fill-up again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
							gotoxy(72,14);scanf(" %c", &ch);
				
							if (ch == 'Y' || ch == 'y')
		    				{   
			       				clrBox();
			       				fflush(stdin);
			       				EditReserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		    				}
		    				else
		    				{
								return;
							}
						break;
							}
					}
					
					fflush(stdin);
					clrBox();
					box(20,5,100,22);
					
					gotoxy(38,7);printf("---------------------------------------------");
					gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
					gotoxy(38,9);printf("---------------------------------------------");
					gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
					gotoxy(38,13);printf("      Your new time is : %s", reservation[nReservation].time);
					gotoxy(38,16);printf("---------------------------------------------");
					gotoxy(38,18);printf("        \033[1mPress [S] to save your edit : \033[0m");
					gotoxy(76,18);scanf("%c", &ch);
					
					if(ch == 's' || ch == 'S')
					{
						displayRR (details,reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					}		
					else
					{
			           	clrBox();
			  			red();
			   			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
			   			reset();
			   			gotoxy(44,13);printf("Please enter correct input!");
			   			gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(72,14);scanf(" %c", &ch);
				
						if (ch == 'Y' || ch == 'y')
			   			{   
				   			clrBox();
			    			fflush(stdin);
				       		EditReserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
			    		}
			   			else
			   			{
							return;
						}
					}
					break;
				
				case 3:
					fflush(stdin);
					clrBox();
					box(20,5,100,22);
					int validInput = 0;
					while (!validInput) {
					gotoxy(38,7);printf("---------------------------------------------");
					gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
					gotoxy(38,9);printf("---------------------------------------------");
					gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
					gotoxy(38,13);printf("      Current Number of Participants: %d", reservation[nReservation].nparticipants);
					
				
						gotoxy(38, 14); printf("      Enter New Number of Participants: ");
						gotoxy(78, 14); scanf("%d", &dadalo);
				
						if (dadalo <= 45) {
							validInput = 1;
						} else {
							clrBox();
							red();
							gotoxy(40, 11); printf("\033[1mINVALID INPUT!\033[0m");
							reset();
							gotoxy(40, 13); printf("Room can only accommodate 45 participants!");
							gotoxy(40, 14); printf("Press any key to re-enter the value...");
							getch();
							clrBox();
						}
					}

					gotoxy(38,17);printf("---------------------------------------------");
					gotoxy(38,19);printf("        \033[1mPress [S] to save your edit : \033[0m");
					fflush(stdin);
					gotoxy(76,19);scanf("%c", &ch);
					
					if(ch == 's' || ch == 'S')
					{
						reservation[nReservation].nparticipants = dadalo;
						displayRR (details,reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					}		
					else
					{
			           	clrBox();
			  			red();
			   			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
			   			reset();
			   			gotoxy(44,13);printf("Please enter correct input! Edit didn't save!");
			   			gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(72,14);scanf(" %c", &ch);
				
						if (ch == 'Y' || ch == 'y')
			   			{   
			   			clrBox();
		    			fflush(stdin);
			       		EditReserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
			    		}
			   			else
			   			{
						exit(0);
						}
					}
					break;
				case 4:
					fflush(stdin);
					clrBox();
					box(20,5,100,22);
					
					gotoxy(38,7);printf("---------------------------------------------");
					gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
					gotoxy(38,9);printf("---------------------------------------------");
					gotoxy(42,10);printf("           \033[1mTYPE OF ROOM:\033[0m");
					gotoxy(42,12);printf("        [1] Classroom");
					gotoxy(42,13);printf("        [2] Seminar Room");
					gotoxy(42,14);printf("        [3] Auditorium ");
					gotoxy(42,15);printf("        [4] Training Room");
					gotoxy(42,16);printf("        [5] Back");
					gotoxy(38,18);printf("---------------------------------------------");
					gotoxy(38,20);printf("            \033[1mEnter Choice [1-5]: \033[0m");
					gotoxy(70,20);scanf("%d", &choice);
					
					switch (choice) {
				    	case 1:
				       		strcpy(reservation[nReservation].roomtype, "Classroom");
				        	break;
				    	case 2:
				        	strcpy(reservation[nReservation].roomtype, "Seminar");
				        	break;
				    	case 3:
				        	strcpy(reservation[nReservation].roomtype, "Auditorium");
				        	break;
				    	case 4:
				        	strcpy(reservation[nReservation].roomtype, "Training");
				        	break;
				    	case 5:
				        	EditReserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				        	break;
				    	default:
				        	clrBox();
				  			red();
				    		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
				   			reset();
				   			gotoxy(44,13);printf("Please enter correct input!");
				   			gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
							gotoxy(80,14);scanf(" %c", &ch);
						
							if (ch == 'Y' || ch == 'y')
				    		{   
				        	clrBox();
				       		fflush(stdin);
				        	roomreserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				    		}
				    		else
				    		{
								return;
				    		}	
				        break;
						}
				
					fflush(stdin);
					clrBox();
					box(20,5,100,22);
					
					gotoxy(38,7);printf("---------------------------------------------");
					gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
					gotoxy(38,9);printf("---------------------------------------------");
					gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
					
					gotoxy(38,13);printf("    Your new type of room is : %s", reservation[nReservation].roomtype);
					
					gotoxy(38,16);printf("---------------------------------------------");
					gotoxy(38,18);printf("        \033[1mPress [S] to save your edit : \033[0m");
					gotoxy(76,18);scanf("%c", &ch);
					
					if(ch == 's' || ch == 'S')
					{
						displayRR (details,reservation, nReservation, nBuilding, nRoom,chosenBuildingIndex);
					}		
					else
					{
			           	clrBox();
			  			red();
			   			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
			   			reset();
			   			gotoxy(44,13);printf("Please enter correct input!");
			   			gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(84,14);scanf(" %c", &ch);
				
						if (ch == 'Y' || ch == 'y')
			   			{   
			   			clrBox();
		    			fflush(stdin);
			       		EditReserve(details, reservation, nReservation, nBuilding, nRoom,chosenBuildingIndex);
			    		}
			   			else
			   			{
							return;
						}
					}
							
					break;
				case 5:
					askRoomandBuilding(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);	
					fflush(stdin);
					clrBox();
					box(20,5,100,22);
					gotoxy(38,7);printf("---------------------------------------------");
					gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
					gotoxy(38,9);printf("---------------------------------------------");
					gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
					gotoxy(38,13);printf("  Your new room is : %s - %s", reservation[nReservation].buildingname, reservation[nReservation].room);
					gotoxy(38,17);printf("---------------------------------------------");
					gotoxy(38,19);printf("        \033[1mPress [S] to save your edit : \033[0m");
					gotoxy(76,19);scanf("%c", &ch);
					
					if(ch == 's' || ch == 'S')
					{
						displayRR (details,reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					}		
					else
					{
			           	clrBox();
			  			red();
			   			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
			   			reset();
			   			gotoxy(44,13);printf("Please enter correct input! Edit didn't save!");
			   			gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(72,14);scanf(" %c", &ch);
				
						if (ch == 'Y' || ch == 'y')
			   			{   
			   			clrBox();
		    			fflush(stdin);
			       		EditReserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
			    		}
			   			else
			   			{
						return;
						}
					}
							break;
						case 6:
							fflush(stdin);
							clrBox();
							box(20,5,100,22);
							gotoxy(38,7);printf("---------------------------------------------");
							gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
							gotoxy(38,9);printf("---------------------------------------------");
							gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
							gotoxy(38,13);printf("           Current Description: %s", reservation[nReservation].description);
							gotoxy(38,14);printf("           Enter New Description: ");
							gotoxy(72,14);fgets(desc, sizeof(desc), stdin);
		        						desc[strlen(desc) - 1] = '\0';
							gotoxy(38,17);printf("---------------------------------------------");
							gotoxy(38,19);printf("        \033[1mPress [S] to save your edit : \033[0m");
							gotoxy(76,19);scanf("%c", &ch);
							
							if(ch == 's' || ch == 'S')
							{	
								strcpy(reservation[nReservation].description, desc);
								displayRR (details,reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
							}		
							else
							{
					           	clrBox();
					  			red();
					   			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
					   			reset();
					   			gotoxy(44,13);printf("Please enter correct input! Edit didn't save!'");
					   			gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
								gotoxy(72,14);scanf(" %c", &ch);
						
								if (ch == 'Y' || ch == 'y')
					   			{   
					   			clrBox();
				    			fflush(stdin);
					       		EditReserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					    		}
					   			else
					   			{
								exit(0);
								}
							}
					break;
				case 7:
				displayRR (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				break;
				default:
					clrBox();
	  				red();
	    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
	   				reset();
	   				gotoxy(44,13);printf("Please enter correct input!");
	   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
					gotoxy(72,14);scanf(" %c", &ch);
			
					if (ch == 'Y' || ch == 'y')
	    			{   
	       			clrBox();
	       			fflush(stdin);
	       			EditReserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
	    			}
	    			else
	    			{
					return;
					}
				break;							
		}
}

/*
*	Function: ViewRR	
*	Description: Displays the informations particular on reservation details of the user
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 

void ViewRR (struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex) {
	
	fflush(stdin);
	clrBox();
	box(20,5,100,22);
	
	int i, choice, view_choice, choice2;
	FILE *pFile;
	char ch;
	int k=11;
	
	nReservation = 0;
	// Open the file for reading reservation details
	pFile = fopen("reservationdetails.txt", "r");
	
	// Read reservation details from the file and populate the arrays
	fscanf(pFile, "%d\n", &nReservation);
	for(i=0;i<nReservation;i++)
	{
		// Read personal details
		fgets(details[i].firstname, sizeof(details[i].firstname), pFile);
        details[i].firstname[strcspn(details[i].firstname, "\n")] = '\0'; // Remove the newline character

        fgets(details[i].lastname, sizeof(details[i].lastname), pFile);
        details[i].lastname[strcspn(details[i].lastname, "\n")] = '\0';

        fgets(details[i].idnumber, sizeof(details[i].idnumber), pFile);
        details[i].idnumber[strcspn(details[i].idnumber, "\n")] = '\0';

        fgets(details[i].program, sizeof(details[i].program), pFile);
        details[i].program[strcspn(details[i].program, "\n")] = '\0';

        fgets(details[i].year, sizeof(details[i].year), pFile);
        details[i].year[strcspn(details[i].year, "\n")] = '\0';

		// Read reservation details
        fgets(reservation[i].date, sizeof(reservation[i].date), pFile);
        reservation[i].date[strcspn(reservation[i].date, "\n")] = '\0';

        fgets(reservation[i].time, sizeof(reservation[i].time), pFile);
        reservation[i].time[strcspn(reservation[i].time, "\n")] = '\0';

        fscanf(pFile, "%d", &reservation[i].nparticipants);
        fgetc(pFile); // Consume the newline character

        fgets(reservation[i].roomtype, sizeof(reservation[i].roomtype), pFile);
        reservation[i].roomtype[strcspn(reservation[i].roomtype, "\n")] = '\0';

        fgets(reservation[i].room, sizeof(reservation[i].room), pFile);
        reservation[i].room[strcspn(reservation[i].room, "\n")] = '\0';

		fgets(reservation[i].description, sizeof(reservation[i].description), pFile);
        reservation[i].description[strcspn(reservation[i].description, "\n")] = '\0';

	}
	if (pFile == NULL || nReservation <= 0)	// Check if the file is empty or there are no reservations
	{
	gotoxy(38,7);printf("---------------------------------------------");
	gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,9);printf("---------------------------------------------");
	gotoxy(38,12);printf("             \033[1mNo Reservation!\033[0m");
	gotoxy(38,15);printf("---------------------------------------------");
	gotoxy(38,16);printf("[1] Back to Homepage");
	gotoxy(59,16);printf("  [2] Make a Reservation");
	gotoxy(49,17);printf("      [3] Back");
	gotoxy(38,18);printf("---------------------------------------------");
	gotoxy(38,20);printf("           \033[1mEnter Choice [1-3]: \033[0m");
	gotoxy(69,20);scanf("%d", &choice);
	
	switch (choice)
	{
		case 1:
			displayCover (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		break;
		case 2:
			roomreserve (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		break;
		case 3:
			displayMainMenu (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		break;
		default:
			clrBox();
  			red();
    		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
   			reset();
   			gotoxy(44,13);printf("Please enter correct input!");
   			gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
			gotoxy(80,14);scanf(" %c", &ch);
		
			if (ch == 'Y' || ch == 'y')	// If the user wants to try again, clear the screen and repeat the view reservations process
    		{   
        	clrBox();
       		fflush(stdin);
        	ViewRR(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
    		}
    		else
    		{		// If the user chooses not to try again, exit the program
				return;
    		}
		break;	
		}
	}
	else{
	fflush(stdin);
	clrBox();
	box(20,5,100,22);
	
	// Display the header for the view reservations page
	gotoxy(38,7);printf("---------------------------------------------");
	gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,9);printf("---------------------------------------------");
	gotoxy(38,10);printf("         \033[1mNumber of Reservations : %d\033[0m", nReservation);
	gotoxy(38,11);printf("     NAME       ROOM TYPE         TIME");																		//FIX FILE HANDLING
	
	// Display the list of reservations
	for(i=0;i<nReservation;i++){
		k++;
		gotoxy(38,k);printf("  %d. %s        %s     %s", i+1, details[i].firstname, reservation[i].roomtype, reservation[i].time);
	}
	
	gotoxy(38,18);printf("---------------------------------------------");
	gotoxy(38,19);printf("   \033[1m[1] Back");
	gotoxy(50,19);printf("   [2] View Reservation Details\033[0m");
	gotoxy(38,20);printf("---------------------------------------------");
	gotoxy(38,21);printf("           \033[1mEnter Choice [1-2]: \033[0m");
	gotoxy(69,21);scanf("%d", &choice2);
	
	switch (choice2)
	{
		case 1:
			displayMainMenu (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		break;
		case 2:
			k=11;
			fflush(stdin);
			clrBox();
			box(20,5,100,22);
			
			gotoxy(38,7);printf("---------------------------------------------");
			gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,9);printf("---------------------------------------------");
			gotoxy(38,10);printf("         \033[1mNumber of Reservations : %d\033[0m", nReservation);
			gotoxy(38,11);printf("     NAME       ROOM TYPE         TIME");
			
			// Display the list of reservations
			for(i=0;i<nReservation;i++){
				k++;
				gotoxy(38,k);printf("  %d. %s        %s     %s", i+1, details[i].firstname, reservation[i].roomtype, reservation[i].time);
			}	
			
			gotoxy(38,20);printf("---------------------------------------------");
			gotoxy(38,21);printf("\033[1mEnter the number to view reservation details:\033[0m");
			gotoxy(84,21);scanf("%d", &view_choice);
			
			if (view_choice>nReservation || view_choice<=0)
			{
				clrBox();	// Display an error message if the selected reservation does not exist
		    	red();
		    	gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		    	reset();
		   	 	gotoxy(44,13);printf("Reservation does not exist");
		    	gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
				gotoxy(80,14);scanf(" %c", &ch);
				
				if (ch == 'Y' || ch == 'y') // If the user wants to try again, clear the screen and repeat the view reservations process
		    	{   
		       	 	clrBox();
		        	fflush(stdin);
		        	ViewRR(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		   	 	}
		    	else
		    	{
					return;	// If the user chooses not to try again, exit the program
		    	}	
			}
			else{
			ViewDetails(details, reservation, nReservation, view_choice-1, nBuilding, nRoom, chosenBuildingIndex);	// If the selected reservation is valid, view its details
		}
			
		break;
		default: 
			clrBox();
  			red();
    		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
   			reset();
   			gotoxy(44,13);printf("Please enter correct input!");
   			gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");	// If the user wants to try again, clear the screen and repeat the view reservations process
			gotoxy(80,14);scanf(" %c", &ch);
		
			if (ch == 'Y' || ch == 'y')
    		{   
        	clrBox();
       		fflush(stdin);
       		ViewRR(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
    		}
    		else
    		{
				return;	// If the user chooses not to try again, exit the program
    		} 
		}
	}
}	

/*
*	Function: ViewDetails	
*	Description: Function in Main Menu that displays the personal and reservation details from the user
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 

void ViewDetails(struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int view_choice, int nBuilding, int nRoom, int chosenBuildingIndex)
{
	int choice;
	char ch;
	
	fflush(stdin);
	clrBox();
	box(20,5,100,22);
	
	// Display the header for the room reservation view details page and details of the user and reservation
	gotoxy(38,6);printf("---------------------------------------------");
	gotoxy(38,7);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,8);printf("---------------------------------------------");
	gotoxy(38,9);printf("              \033[1mPersonal Details\033[0m");				//CHANGE COLOR
	gotoxy(38,10);printf("\033[1m  First Name:\033[0m %s", details[view_choice].firstname);
	gotoxy(59,10);printf("\033[1m   Last Name:\033[0m %s", details[view_choice].lastname);
	gotoxy(38,11);printf("\033[1m  ID Number:\033[0m %s", details[view_choice].idnumber);
	gotoxy(59,11);printf("\033[1m   Year:\033[0m %s", details[view_choice].year);
	gotoxy(38,12);printf("\033[1m  Program:\033[0m %s", details[view_choice].program);
	gotoxy(38,13);printf("---------------------------------------------");
	gotoxy(38,14);printf("            \033[1mReservation Details\033[0m");			// CHANGE COLOR
	gotoxy(38,15);printf("\033[1m  Room Type:\033[0m %s", reservation[view_choice].roomtype);
	gotoxy(61,15);printf("\033[1m Room:\033[0m%s - %s", reservation[view_choice].buildingname, reservation[view_choice].room);
	gotoxy(38,16);printf("\033[1m  Date:\033[0m %s", reservation[view_choice].date);
	gotoxy(59,16);printf("\033[1m   Number of Participants:\033[0m %d", reservation[view_choice].nparticipants);
	gotoxy(38,17);printf("\033[1m  Time:\033[0m %s", reservation[view_choice].time);
	gotoxy(38,18);printf("\033[1m  Description of use:\033[0m %s", reservation[view_choice].description);
	gotoxy(38,19);printf("---------------------------------------------");
	gotoxy(41,20);printf("       \033[1m[1]\033[0m Back          \033[1m[2]\033[0m Edit");
	gotoxy(38,21);printf("           \033[1mEnter choice [1-2]:\033[0m");
	gotoxy(69,21);scanf("%d", &choice);
	
	switch(choice)
	{
		case 1: 
			ViewRR (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);			// Go back to the main view reservations page
		break;
		case 2:
			 EditRRMainPage(details,reservation, nReservation, view_choice, nBuilding, nRoom, chosenBuildingIndex);		// Go to the edit reservation main page
		break;
		default:
		    clrBox();
		    red();
		    gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		    reset();
		    gotoxy(44,13);printf("Please enter correct input!");
		    gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
			gotoxy(80,14);scanf(" %c", &ch);
				
			if (ch == 'Y' || ch == 'y')		// If the user wants to try again, clear the screen and repeat the view details process
		    {   
		        clrBox();
		        fflush(stdin);
		        ViewDetails (details, reservation, nReservation, view_choice, nBuilding, nRoom, chosenBuildingIndex);
		    }
		    else
		    {
				return;		// If the user chooses not to try again, exit the program
		    }	
		break;
	}

}

/*
*	Function: addRoom	
*	Description: allows the admin to addrooms for the program, then it will be saved into files
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 
																												//TO DOOOOOOOO
void addRoom(struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex) //no cemment yet not yet done
{
	int i;
	int choice;
	char ch;
	char buildingname[51];
	char secondinput[51];
	
	FILE *pFile;

	if (nBuilding == 0)
	{
	clrBox();
    box(20, 5, 100, 22);
   	gotoxy(38, 7); printf("---------------------------------------------");
    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
    gotoxy(38, 9); printf("---------------------------------------------");
    gotoxy(38, 12); printf("\033[31mERROR!\033[0m] There is no available building yet!");   			//error message when no building existing
	gotoxy(38, 13); printf("Please add building first!  ");  
	gotoxy(38, 15); printf("---------------------------------------------");
	gotoxy(38, 16); printf("[1] Add Building        [2] Back to Admin Menu");  
	gotoxy(38, 17); printf("---------------------------------------------");
	gotoxy(38, 18); printf("Choice: ");
	gotoxy(38, 18); scanf("%d", &choice);  
	
	switch(choice)
	{
		case 1: addBuilding(details,reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex); break;
		case 2: adminModule(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex); break;
		default: break; 																	//change
	}  
	}
	else{
	
    if (pFile == NULL) {			//when no building existed
	clrBox();
    box(20, 5, 100, 22);
    gotoxy(38, 7); printf("---------------------------------------------");
    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
    gotoxy(38, 9); printf("---------------------------------------------");
    gotoxy(47, 10); printf("  A D D I N G   R O O M");
    gotoxy(47, 11); printf("  [BUILDINGS AVAILABLE] ");
    
    if (nBuilding == 0)
    {
        gotoxy(49, 13);
        printf("   No Building Available!");
    }
    else
    {
        for (i = 0; i < nBuilding; i++)
        {
            gotoxy(53, 13 + i);
            printf("  %s", reservation[i].buildings[i].mainbuilding);
        }
	}

	gotoxy(45,20);printf("  Enter the building where");
	gotoxy(45,21);printf("  you wish to add rooms: ");
		fflush(stdin);
	gotoxy(70,21);fgets(buildingname, sizeof(buildingname), stdin);
		    	buildingname[strcspn(buildingname, "\n")] = '\0';   
	
	printf("%s", buildingname);
	int chosenBuildingIndex = -1; // Initialize chosenBuildingIndex to -1 before the loop
	
	for (i = 0; i < nBuilding; i++) {
	    if (strcmp(secondinput, reservation[i].buildings[i].mainbuilding) == 0) {	//checks if building exits in file
	        chosenBuildingIndex = i;
	        // Exit the loop once a match is found
	        break;
	    }
	}
	
	if (chosenBuildingIndex == -1)
            {
                clrBox();
                box(20, 5, 100, 22);
                gotoxy(38, 7);printf("---------------------------------------------");
                gotoxy(38, 8);printf("              \033[1mROOM RESERVATION\033[0m");
				gotoxy(38, 9);printf("---------------------------------------------");
				gotoxy(48, 12);printf("\033[31mERROR!\033[0m Building not found!");
				gotoxy(38, 15);printf("---------------------------------------------");
                gotoxy(38, 16);printf("     [1] Retry    [2] Back to Admin Menu");
                gotoxy(38, 17);printf("---------------------------------------------");
                gotoxy(53, 19);printf("Choice: ");
                gotoxy(61, 19);scanf("%d", &choice);

                switch (choice)
                {
                    case 1:
                        addRoom(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
                        break;
                    case 2:
                        adminModule(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
                        break;
                    default:	//change
                        break;
                }
            }
        else{
        	fflush(stdin);
        	clrBox();
		    box(20, 5, 100, 22);
		    gotoxy(38, 7); printf("---------------------------------------------");
		    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
		    gotoxy(38, 9); printf("---------------------------------------------");
		    gotoxy(47, 10); printf("   A D D I N G   R O O M");
			gotoxy(34,11);printf("NOTE: Room Format (XYYYY); X-Building, Y-Room Number ");
			
			reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom = loadRooms(details, reservation, nBuilding, chosenBuildingIndex);

			if (reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom == 0)
			{
			    gotoxy(49, 13);printf("   No Room Available!");
			}
			else
			{
			    for (i = 0; i < reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom; i++)
			    {
			        gotoxy(49, 12 + i);printf("        %s", reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].rooms[i].mainroom);
			    }
			}
			
			gotoxy(38, 18); printf("---------------------------------------------");
			gotoxy(38, 19); printf("  [1] Add Room   [2] Save Changes  [3] Back");
			gotoxy(38, 20); printf("---------------------------------------------");
			gotoxy(50, 21); printf(" Enter Choice: ");
			fflush(stdin);
			gotoxy(65, 21); scanf("%d", &choice);
			
			switch (choice)
			{
			case 1:
				clrBox();
			    box(20, 5, 100, 22);
			    gotoxy(38, 7); printf("---------------------------------------------");
			    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
			    gotoxy(38, 9); printf("---------------------------------------------");
			    gotoxy(47, 10); printf("   A D D I N G   R O O M");
				gotoxy(34,11);printf("NOTE: Room Format (XYYYY); X-Building, Y-Room Number ");
				
			    if (reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom == 0)	
			    {
			        gotoxy(49, 13); printf("No Room Available!");
			    }
			    else
			    {
			        for (i = 0; i < 	reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom; i++)
			        {
			            gotoxy(53, 13 + i); printf("    %s", reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].rooms[i].mainroom);
			        }
			    }

			    gotoxy(45, 15 + nRoom); printf("  Enter Room:");
			    fflush(stdin); 
				fgets(reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].rooms[reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom].mainroom, sizeof(reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].rooms[reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom].mainroom), stdin);
				reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].rooms[reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom].mainroom[strcspn(reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].rooms[reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom].mainroom, "\n")] = '\0';
				reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom++;//increment room
				
			    clrBox();
			    box(20, 5, 100, 22);
			    gotoxy(38, 7); printf("---------------------------------------------");
			    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
			    gotoxy(38, 9); printf("---------------------------------------------");
			    gotoxy(50, 12); printf("    Room Added!");
			    gotoxy(38, 15); printf("   Do you wish to add another Room?  \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");
			    gotoxy(82, 15); scanf(" %c", &ch);
			
			    if (ch == 'Y' || ch == 'y')
			    {
			   		saveRooms(details, reservation, nReservation,nBuilding, chosenBuildingIndex);	
			        addRoom(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
			    }
			    else if (ch == 'n' || ch == 'N')
			    {
			   	saveRooms(details, reservation, nReservation,nBuilding, chosenBuildingIndex);
				fflush(stdin);
				clrBox();
				box(20,5,100,22);
				
				gotoxy(38,7);printf("---------------------------------------------");
				gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
				gotoxy(38,9);printf("---------------------------------------------");
				gotoxy(44,12);printf("    Changes Succesfully Saved!");	
				gotoxy(38,15);printf("---------------------------------------------");
				gotoxy(38,16);printf("[1] Back to Main Menu   [2] Back to Admin Module ");
				gotoxy(38,17);printf("---------------------------------------------");
				gotoxy(38,19);printf("            Enter Choice [1-2]: ");
				gotoxy(70,19);scanf("%d", &choice);
				
				switch (choice)
				{
					case 1:
						displayMainMenu(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					break;
					case 2:
						adminModule (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					break;
					default:
						clrBox();
						red();
						gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
						reset();
						gotoxy(44,13);printf("Please enter correct input!");
						gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(72,14);scanf(" %c", &ch);
								
						if (ch == 'Y' || ch == 'y')
						{   
					    clrBox();
					    fflush(stdin);
					    addRoom (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);   
					    }
					    else
					    {
							return;
					    }
					break;			
			    }
			    	addRoom(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				}
			    else{
			    		//	default value
				}
				break;
				case 2:
				saveRooms(details, reservation, nReservation,nBuilding, chosenBuildingIndex);	
				fflush(stdin);
				clrBox();
				box(20,5,100,22);
				
				gotoxy(38,7);printf("---------------------------------------------");
				gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
				gotoxy(38,9);printf("---------------------------------------------");
				gotoxy(44,12);printf("    Changes Succesfully Saved!");		/// Color
				gotoxy(38,15);printf("---------------------------------------------");
				gotoxy(36,16);printf("[1] Back to Main Menu   [2] Back to Admin Module ");
				gotoxy(38,17);printf("---------------------------------------------");
				gotoxy(38,19);printf("       Enter Choice [1-2]: ");
				gotoxy(65,19);scanf("%d", &choice);
				
				switch (choice)
				{
					case 1:
						displayMainMenu(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					break;
					case 2:
						adminModule (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					break;
					default:
						clrBox();
						red();
						gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
						reset();
						gotoxy(44,13);printf("Please enter correct input!");
						gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(72,14);scanf(" %c", &ch);
								
						if (ch == 'Y' || ch == 'y')
						{   
					    clrBox();
					    fflush(stdin);
					    addRoom (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex); 					  
					    }
					    else
					    {
							exit(0);
					    }
					break;				
				}		
				break;
				case 3:
				clrBox();
			    box(20, 5, 100, 22);
			    gotoxy(38, 7); printf("---------------------------------------------");
			    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
			    gotoxy(38, 9); printf("---------------------------------------------");
			    gotoxy(38, 12); printf("        Your changes won't be Saved!");	 
				gotoxy(38, 15); printf("---------------------------------------------"); 
				gotoxy(38, 17); printf("         Press any key to proceed: ");	 
				gotoxy(73, 17); getch();
				adminModule(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex); 	
			break;
			default:			//CHANGE
			break;
			}
		}
		fclose(pFile);
	}	
		
	else {
	clrBox();
    box(20, 5, 100, 22);
    gotoxy(38, 7); printf("---------------------------------------------");		
    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
    gotoxy(38, 9); printf("---------------------------------------------");
    gotoxy(47, 10); printf("  A D D I N G   R O O M");
    gotoxy(47, 11); printf("  [BUILDINGS AVAILABLE] ");
    
    if (nBuilding == 0)
    {
        gotoxy(49, 13);
        printf("   No Building Available!");
    }
    else
    {
        for (i = 0; i < nBuilding; i++)			//prompts all buildings
        {
            gotoxy(53, 13 + i);
            printf("  %s", reservation[i].buildings[i].mainbuilding);
        }
	}

	gotoxy(45,20);printf("  Enter the building where");
	gotoxy(45,21);printf("  you wish to add rooms: ");
	fflush(stdin);
	gotoxy(70,21);fgets(secondinput, sizeof(secondinput), stdin);
		    secondinput[strcspn(secondinput, "\n")] = '\0';   
	
	printf("%s", secondinput);
	chosenBuildingIndex = -1;							
	
	for (i = 0; i < nBuilding; i++) {
	    if (strcmp(secondinput, reservation[i].buildings[i].mainbuilding) == 0) {			//check if buildings exits in the file
	        chosenBuildingIndex = i;
	        // Exit the loop once a match is found
	        break;
	    }
	}

	if (chosenBuildingIndex == -1)
            {
                clrBox();
                box(20, 5, 100, 22);
                gotoxy(38, 7);printf("---------------------------------------------");
                gotoxy(38, 8);printf("              \033[1mROOM RESERVATION\033[0m");
				gotoxy(38, 9);printf("---------------------------------------------");
				gotoxy(48, 12);printf("\033[31mERROR!\033[0m Building not found!");				//when building is not found
				gotoxy(38, 15);printf("---------------------------------------------");
                gotoxy(38, 16);printf("     [1] Retry    [2] Back to Admin Menu");
                gotoxy(38, 17);printf("---------------------------------------------");
                fflush(stdin);
                gotoxy(53, 19);printf("Choice: ");
                gotoxy(61, 19);scanf("%d", &choice);
                
                switch (choice)
                {
                    case 1:
                        addRoom(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
                        break;
                    case 2:
                        adminModule(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
                        break;
                    default:	//change
                        break;
                }
            }
        else{
        	fflush(stdin);
        	clrBox();
		    box(20, 5, 100, 22);
		    gotoxy(38, 7); printf("---------------------------------------------");
		    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
		    gotoxy(38, 9); printf("---------------------------------------------");
		    gotoxy(47, 10); printf("   A D D I N G   R O O M");
			gotoxy(34,11);printf("NOTE: Room Format (XYYYY); X-Building, Y-Room Number ");				//prompt all rooms in the building
 			
			reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom = loadRooms(details, reservation, nBuilding, chosenBuildingIndex);
			
			if (reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom == 0)
			{
			    gotoxy(49, 13);printf("   No Room Available!");
			}
			else
			{
			    for (i = 0; i < reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom ; i++)
			    {
			        gotoxy(49, 12 + i);printf("        %s", reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].rooms[i].mainroom);
			    }
			}
			
			gotoxy(38, 18); printf("---------------------------------------------");
			gotoxy(38, 19); printf("  [1] Add Room   [2] Save Changes  [3] Back");
			gotoxy(38, 20); printf("---------------------------------------------");
			gotoxy(50, 21); printf(" Enter Choice: ");
			fflush(stdin);
			gotoxy(65, 21); scanf("%d", &choice);
			
			switch (choice)
			{
			case 1:
				clrBox();
			    box(20, 5, 100, 22);
			    gotoxy(38, 7); printf("---------------------------------------------");
			    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
			    gotoxy(38, 9); printf("---------------------------------------------");
			    gotoxy(47, 10); printf("   A D D I N G   R O O M");
				gotoxy(34,11);printf("NOTE: Room Format (XYYYY); X-Building, Y-Room Number ");
			
			    if (reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom  == 0)
			    {
			        gotoxy(49, 13); printf("No Room Available!");
			    }
			    else
			    {
			        for (i = 0; i < reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom ; i++)
			        {
			            gotoxy(53, 13 + i); printf("    %s", reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].rooms[i].mainroom);
			        }
			    }
			     gotoxy(45, 15 + reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom); printf("  Enter Room:");
			    fflush(stdin); 
				fgets(reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].rooms[reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom].mainroom, sizeof(reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].rooms[reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom].mainroom), stdin);
				reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].rooms[reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom].mainroom[strcspn(reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].rooms[reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom].mainroom, "\n")] = '\0';
				reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom++;
		
			    clrBox();
			    box(20, 5, 100, 22);
			    gotoxy(38, 7); printf("---------------------------------------------");
			    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
			    gotoxy(38, 9); printf("---------------------------------------------");
			    gotoxy(50, 12); printf("    Room Added!");
			    gotoxy(38, 15); printf("   Do you wish to add another Room?  \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");		//when room added
			    gotoxy(82, 15); scanf(" %c", &ch);
			
			    if (ch == 'Y' || ch == 'y')
			    {
			    	chosenBuildingIndex = -1;
			 		saveRooms(details, reservation, nReservation,nBuilding, chosenBuildingIndex);		
			        addRoom(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
			    }
			    else if (ch == 'n' || ch == 'N')
			    {
			   	saveRooms(details, reservation, nReservation,nBuilding, chosenBuildingIndex);
				fflush(stdin);
				clrBox();
				box(20,5,100,22);
				
				gotoxy(38,7);printf("---------------------------------------------");
				gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
				gotoxy(38,9);printf("---------------------------------------------");
				gotoxy(44,12);printf("    Changes Succesfully Saved!");		/// Color
				gotoxy(38,15);printf("---------------------------------------------");
				gotoxy(38,16);printf("[1] Back to Main Menu   [2] Back to Admin Module ");
				gotoxy(38,17);printf("---------------------------------------------");
				gotoxy(38,19);printf("            Enter Choice [1-2]: ");
				gotoxy(70,19);scanf("%d", &choice);
				
				switch (choice)
				{
					case 1:
						displayMainMenu(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					break;
					case 2:
						adminModule (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					break;
					default:
						clrBox();
						red();
						gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
						reset();
						gotoxy(44,13);printf("Please enter correct input!");
						gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(72,14);scanf(" %c", &ch);
								
						if (ch == 'Y' || ch == 'y')
						{   
					    clrBox();
					    fflush(stdin);
					    addRoom (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);   
					    }
					    else
					    {
							exit(0);
					    }
					break;			
			    }
			    	addRoom(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				}
			    else{
			    	
				}
				break;
				case 2:				// save rooms to file
			   	saveRooms(details, reservation, nReservation,nBuilding, chosenBuildingIndex);	
				fflush(stdin);
				clrBox();
				box(20,5,100,22);
				
				gotoxy(38,7);printf("---------------------------------------------");
				gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
				gotoxy(38,9);printf("---------------------------------------------");
				gotoxy(44,12);printf("    Changes Succesfully Saved!");		/// Color
				gotoxy(38,15);printf("---------------------------------------------");
				gotoxy(36,16);printf("[1] Back to Main Menu   [2] Back to Admin Module ");
				gotoxy(38,17);printf("---------------------------------------------");
				gotoxy(38,19);printf("       Enter Choice [1-2]: ");
				gotoxy(65,19);scanf("%d", &choice);
				
				switch (choice)
				{
					case 1:
						displayMainMenu(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					break;
					case 2:
						adminModule (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);		//back
					break;
					default:
						clrBox();
						red();
						gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
						reset();
						gotoxy(44,13);printf("Please enter correct input!");
						gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(72,14);scanf(" %c", &ch);
								
						if (ch == 'Y' || ch == 'y')
						{   
					    clrBox();
					    fflush(stdin);
					    addRoom (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex); 					
					    }
					    else
					    {
							exit(0);
					    }
					break;				
				}		
				break;
				case 3:
				clrBox();
			    box(20, 5, 100, 22);
			    gotoxy(38, 7); printf("---------------------------------------------");
			    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
			    gotoxy(38, 9); printf("---------------------------------------------");
			    gotoxy(38, 12); printf("        Your changes won't be Saved!");	 
				gotoxy(38, 15); printf("---------------------------------------------"); 
				gotoxy(38, 17); printf("         Press any key to proceed: ");	 
				gotoxy(73, 17); getch();
				adminModule(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex); 
			break;
			default:			//CHANGE
			break;
			}
		}
	}
	
	}
}

/*
*	Function: addBuilding	
*	Description: allows the admin to add buildings in the program, then it will be saved into file
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 

void addBuilding(struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex) //no comment yet not yet odne
{
    char ch;
	int i;
	int choice;

	FILE *pFile;
	
	pFile = fopen ("data.txt", "r+");
	
    if (pFile == NULL) {			//when file is not existing
    clrBox();
    box(20, 5, 100, 22);
    gotoxy(38, 7); printf("---------------------------------------------");
    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
    gotoxy(38, 9); printf("---------------------------------------------");
    gotoxy(45, 10); printf("A D D I N G   B U I L D I N G");

    if (nBuilding == 0)						//prompts buildings
    {
        gotoxy(49, 12); printf(" No Building Available!");
    }
    else
    {
        for (i = 0; i < nBuilding; i++)
        {
            gotoxy(49, 12 + i); printf("        %s", reservation[i].buildings[i].mainbuilding);
        }
    }

	gotoxy(38, 18); printf("---------------------------------------------");
	gotoxy(38, 19); printf("[1] Add Building  [2] Save Changes  [3] Back");
	gotoxy(38, 20); printf("---------------------------------------------");
	gotoxy(50, 21); printf(" Enter Choice: ");
	gotoxy(65, 21); scanf("%d", &choice);
	
	switch (choice)
	{
		case 1:
			clrBox();
		    box(20, 5, 100, 22);
		    gotoxy(38, 7); printf("---------------------------------------------");
		    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
		    gotoxy(38, 9); printf("---------------------------------------------");
		    gotoxy(45, 10); printf("A D D I N G  B U I L D I N G");
		
		    if (nBuilding == 0)
		    {
		        gotoxy(49, 12); printf("No Building Available!");
		    }
		    else
		    {
		        for (i = 0; i < nBuilding; i++)
		        {
		            gotoxy(49, 12 + i); printf("        %s", reservation[i].buildings[i].mainbuilding);
		        }
		    }
		    gotoxy(45, 14 + nBuilding); printf("  Enter Building:");
		    fflush(stdin); 
			gotoxy(63, 14 + nBuilding);fgets(reservation[nBuilding].buildings[nBuilding].mainbuilding, sizeof(reservation[nBuilding].buildings[nBuilding].mainbuilding), stdin);
		    reservation[nBuilding].buildings[nBuilding].mainbuilding[strcspn(reservation[nBuilding].buildings[nBuilding].mainbuilding, "\n")] = '\0';
			nBuilding++;
			
		    clrBox();
		    box(20, 5, 100, 22);
		    gotoxy(38, 7); printf("---------------------------------------------");
		    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
		    gotoxy(38, 9); printf("---------------------------------------------");
		    gotoxy(50, 12); printf("  Building Added!");
		    gotoxy(38, 15); printf(" Do you wish to add another building?  \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");  				 //FIX PROMPT ROOM
		    gotoxy(84, 15); scanf(" %c", &ch);
		
		    if (ch == 'Y' || ch == 'y')
		    {
		        saveData(details, reservation,nReservation, nBuilding, nRoom, chosenBuildingIndex);
		        addBuilding(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		    }
		    else if (ch == 'n' || ch == 'N')
		    {
		    saveData (details, reservation, nReservation,nBuilding, nRoom, chosenBuildingIndex);
			fflush(stdin);
			clrBox();
			box(20,5,100,22);
			
			gotoxy(38,7);printf("---------------------------------------------");
			gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,9);printf("---------------------------------------------");
			gotoxy(44,12);printf("    Changes Succesfully Saved!");					//notify for changes
			gotoxy(38,15);printf("---------------------------------------------");
			gotoxy(38,16);printf("     [1] Add Room          [2] Back ");
			gotoxy(38,17);printf("---------------------------------------------");
			gotoxy(38,19);printf("            Enter Choice [1-2]: ");
			gotoxy(70,19);scanf("%d", &choice);
			
			switch (choice)
			{
				case 1:
					addRoom(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				break;
				case 2:
					adminModule (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				break;
				default:
					clrBox();
					red();
					gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
					reset();
					gotoxy(44,13);printf("Please enter correct input!");
					gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
					gotoxy(72,14);scanf(" %c", &ch);
							
					if (ch == 'Y' || ch == 'y')
					{   
				    clrBox();
				    fflush(stdin);
				    addBuilding (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);   
				    }
				    else
				    {
						exit(0);
				    }
				break;			
		    }
		   	 addBuilding(details, reservation, nReservation, nBuilding, nRoom,chosenBuildingIndex);
			}
		    else{
		    	//default choice
			}
		break;
		case 2:
			saveData (details, reservation, nReservation,nBuilding, nRoom,chosenBuildingIndex);
			fflush(stdin);
			clrBox();
			box(20,5,100,22);
			
			gotoxy(38,7);printf("---------------------------------------------");
			gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,9);printf("---------------------------------------------");
			gotoxy(44,12);printf("    Changes Succesfully Saved!");							//notify for changes
			gotoxy(38,15);printf("---------------------------------------------");
			gotoxy(38,16);printf("     [1] Add Room          [2] Back ");
			gotoxy(38,17);printf("---------------------------------------------");
			gotoxy(38,19);printf("          Enter Choice [1-2]: ");
			gotoxy(68,19);scanf("%d", &choice);
			
			switch (choice)
			{
				case 1:
					addRoom(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				break;
				case 2:
					adminModule (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				break;
				default:
					clrBox();
					red();
					gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
					reset();
					gotoxy(44,13);printf("Please enter correct input!");
					gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
					gotoxy(72,14);scanf(" %c", &ch);
							
					if (ch == 'Y' || ch == 'y')
					{   
				    clrBox();
				    fflush(stdin);
				    addBuilding (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);   
				    }
				    else
				    {
						exit(0);
				    }
				break;				
			}		
		break;
		case 3:
			clrBox();
		    box(20, 5, 100, 22);
		    gotoxy(38, 7); printf("---------------------------------------------");
		    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
		    gotoxy(38, 9); printf("---------------------------------------------");
		    gotoxy(38, 12); printf("        Your changes won't be Saved!");	 
			gotoxy(38, 15); printf("---------------------------------------------"); 
			gotoxy(38, 17); printf("         Press any key to proceed: ");	 
			gotoxy(73, 17); getch();
			adminModule (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		break;
		default:			//CHANGE
		break;
	}	
    }
	//when file existing
	fflush(stdin);
    clrBox();
    box(20, 5, 100, 22);
    gotoxy(38, 7); printf("---------------------------------------------");
    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
    gotoxy(38, 9); printf("---------------------------------------------");				//prompts all buildngs
    gotoxy(46, 10); printf("A D D I N G   B U I L D I N G");

    if (nBuilding == 0)
    {
        gotoxy(49, 12); printf(" No Building Available!");
    }
    else
    {
        for (i = 0; i < nBuilding; i++)
        {
            gotoxy(49, 12 + i); printf("        %s", reservation[i].buildings[i].mainbuilding);
        }
    }

	gotoxy(38, 18); printf("---------------------------------------------");
	gotoxy(38, 19); printf("[1] Add Building  [2] Save Changes  [3] Back");
	gotoxy(38, 20); printf("---------------------------------------------");
	gotoxy(50, 21); printf(" Enter Choice: ");
	gotoxy(65, 21); scanf("%d", &choice);
	
	switch (choice)
	{
		case 1:
			clrBox();
		    box(20, 5, 100, 22);
		    gotoxy(38, 7); printf("---------------------------------------------");
		    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
		    gotoxy(38, 9); printf("---------------------------------------------");
		    gotoxy(45, 10); printf("A D D I N G  B U I L D I N G");
		
		    if (nBuilding == 0)
		    {
		        gotoxy(48, 12); printf("No Building Available!");
		    }
		    else
		    {
		        for (i = 0; i < nBuilding; i++)
		        {
		            gotoxy(49, 12 + i); printf("        %s", reservation[i].buildings[i].mainbuilding);
		        }
		    }
		    gotoxy(45, 14 + nBuilding); printf("  Enter Building:");
		    fflush(stdin); 
			gotoxy(63, 14 + nBuilding);fgets(reservation[nBuilding].buildings[nBuilding].mainbuilding, sizeof(reservation[nBuilding].buildings[nBuilding].mainbuilding), stdin);
		    reservation[nBuilding].buildings[nBuilding].mainbuilding[strcspn(reservation[nBuilding].buildings[nBuilding].mainbuilding, "\n")] = '\0';
			nBuilding++;
			
		    clrBox();
		    box(20, 5, 100, 22);
		    gotoxy(38, 7); printf("---------------------------------------------");
		    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
		    gotoxy(38, 9); printf("---------------------------------------------");
		    gotoxy(50, 12); printf("  Building Added!");
		    gotoxy(38, 15); printf(" Do you wish to add another building?  \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");  				 //FIX PROMPT ROOM
		    gotoxy(84, 15); scanf(" %c", &ch);
		
		    if (ch == 'Y' || ch == 'y')
		    {
		        saveData(details, reservation,nReservation, nBuilding, nRoom,chosenBuildingIndex);
		        addBuilding(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		    }
		    else if (ch == 'n' || ch == 'N')
		    {
		    saveData (details, reservation, nReservation,nBuilding, nRoom,chosenBuildingIndex);
			fflush(stdin);
			clrBox();
			box(20,5,100,22);
			
			gotoxy(38,7);printf("---------------------------------------------");
			gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,9);printf("---------------------------------------------");
			gotoxy(44,12);printf("    Changes Succesfully Saved!");		/// Color
			gotoxy(38,15);printf("---------------------------------------------");
			gotoxy(38,16);printf("     [1] Add Room          [2] Back ");				//add room to building
			gotoxy(38,17);printf("---------------------------------------------");
			gotoxy(38,19);printf("            Enter Choice [1-2]: ");
			gotoxy(70,19);scanf("%d", &choice);
			
			switch (choice)
			{
				case 1:
					addRoom(details, reservation, nReservation, nBuilding, nRoom,chosenBuildingIndex);
				break;
				case 2:
					adminModule (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				break;
				default:
					clrBox();
					red();
					gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
					reset();
					gotoxy(44,13);printf("Please enter correct input!");
					gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
					gotoxy(72,14);scanf(" %c", &ch);
							
					if (ch == 'Y' || ch == 'y')
					{   
				    clrBox();
				    fflush(stdin);
				    addBuilding (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);   
				    }
				    else
				    {
						return;
				    }
				break;			
		    }
		    addRoom(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
			}
		    else{
		    	
			}
		break;
		case 2: 			//save data to file
			saveData (details, reservation, nReservation,nBuilding, nRoom, chosenBuildingIndex);
			fflush(stdin);
			clrBox();
			box(20,5,100,22);
			
			gotoxy(38,7);printf("---------------------------------------------");
			gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,9);printf("---------------------------------------------");
			gotoxy(44,12);printf("    Changes Succesfully Saved!");		/// Color
			gotoxy(38,15);printf("---------------------------------------------");
			gotoxy(38,16);printf("     [1] Add Room          [2] Back ");
			gotoxy(38,17);printf("---------------------------------------------");
			gotoxy(38,19);printf("       Enter Choice [1-2]: ");
			gotoxy(59,19);scanf("%d", &choice);
			
			switch (choice)
			{
				case 1:
					addRoom(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				break;
				case 2:
					adminModule (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				break;
				default:
					clrBox();
					red();
					gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
					reset();
					gotoxy(44,13);printf("Please enter correct input!");
					gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
					gotoxy(72,14);scanf(" %c", &ch);
							
					if (ch == 'Y' || ch == 'y')
					{   
				    clrBox();
				    fflush(stdin);
				    addBuilding (details, reservation, nReservation, nBuilding, nRoom,chosenBuildingIndex);   
				    }
				    else
				    {
						exit(0);
				    }
				break;				
			}		
		break;
		case 3:			//back
			clrBox();
		    box(20, 5, 100, 22);
		    gotoxy(38, 7); printf("---------------------------------------------");
		    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
		    gotoxy(38, 9); printf("---------------------------------------------");
		    gotoxy(38, 12); printf("        Your changes won't be Saved!");	 
			gotoxy(38, 15); printf("---------------------------------------------"); 
			gotoxy(38, 17); printf("         Press any key to proceed: ");	 
			gotoxy(73, 17); getch();
			adminModule (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		break;
		default:			//CHANGE
		break;
	}
		fclose(pFile);	
}

/*
*	Function: adminModule	
*	Description: Displays the adminModule menu which contains the functionalities of the adminModule
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 

void adminModule (struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex) 
{
	int choice;
	
	fflush(stdin);
	clrBox();
	box(20,5,100,22);
	
	// Display the header for the admin module
	gotoxy(38,7);printf("---------------------------------------------");
	gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,9);printf("---------------------------------------------");
	gotoxy(42,11);printf("       [1] Add Building");
	gotoxy(42,12);printf("       [2] Add Room");
	gotoxy(42,13);printf("       [3] Edit Reservations");
	gotoxy(42,14);printf("       [4] View Reservations ");
	gotoxy(42,15);printf("       [5] Mark Reservations Done ");
	gotoxy(42,16);printf("       [6] Back");
	gotoxy(38,18);printf("---------------------------------------------");	
	gotoxy(38,20);printf("           \033[1mEnter choice [1-5]:\033[0m");	
	fflush(stdin);
	gotoxy(69,20);scanf("%d", &choice);	
	
	switch (choice)
	{
		case 1:
			addBuilding(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);		// Call the function to add a new building
		break;
		case 2:
			addRoom (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);		// Call the function to add a new room
		break;
		case 3:
			EditReserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		break;
		case 4:
			ViewRR(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		break;
		case 5:
			MarkedDone(details, reservation, nReservation, nBuilding, nRoom,chosenBuildingIndex);	
		break;
		case 6:
			displayMainMenu(details, reservation, nReservation, nBuilding, nRoom,chosenBuildingIndex);		// Go back to the main menu
		break;
		default:
			//edit			// Handle invalid input
		break;
	}
}

/*
*	Function: displaytieditrr	
*	Description: Displays the informations on reservation and personal details which allows the user to determine his informations 
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
*				 @param : int edit_choice - choice of user what details to edit
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/ 

void displaytieditrr(struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int edit_choice, int nBuilding, int nRoom, int chosenBuildingIndex)
{
	int choice;
	char ch;

	// Clear the screen and draw a box for displaying the reservation details
	fflush(stdin);
	clrBox();
	box(20,5,100,22);
	
	// Display the header for the room reservation section
	gotoxy(38,6);printf("---------------------------------------------");
	gotoxy(38,7);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,8);printf("---------------------------------------------");
	gotoxy(38,9);printf("              \033[1mPersonal Details\033[0m");				//CHANGE COLOR
	gotoxy(38,10);printf("\033[1m  First Name:\033[0m %s", details[edit_choice].firstname);
	gotoxy(59,10);printf("\033[1m   Last Name:\033[0m %s", details[edit_choice].lastname);
	gotoxy(38,11);printf("\033[1m  ID Number:\033[0m %s", details[edit_choice].idnumber);
	gotoxy(59,11);printf("\033[1m   Year:\033[0m %s", details[edit_choice].year);
	gotoxy(38,12);printf("\033[1m  Program:\033[0m %s", details[edit_choice].program);
	gotoxy(38,13);printf("---------------------------------------------");
	gotoxy(38,14);printf("            \033[1mReservation Details\033[0m");			// CHANGE COLOR
	gotoxy(38,15);printf("\033[1m  Room Type:\033[0m %s", reservation[edit_choice].roomtype);
	gotoxy(59,15);printf("\033[1m   Room:\033[0m %s", reservation[edit_choice].room);
	gotoxy(38,16);printf("\033[1m  Date:\033[0m %s", reservation[edit_choice].date);
	gotoxy(59,16);printf("\033[1m   Number of Participants:\033[0m %d", reservation[edit_choice].nparticipants);
	gotoxy(38,17);printf("\033[1m  Time:\033[0m %s", reservation[edit_choice].time);
	gotoxy(38,18);printf("\033[1m  Description of use:\033[0m %s", reservation[edit_choice].description);
	gotoxy(38,19);printf("---------------------------------------------");
	gotoxy(38,20);printf("     [1] Back           [2] Save Changes ");
	gotoxy(38,21);printf("          \033[1mEnter choice [1-2]:\033[0m");
	gotoxy(68,21);scanf("%c", &ch);
	
	switch(ch)
	{
		case 1:
			DisplayEditRRMainPage(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);	// Go back to the main edit page for all reservations
		break;
		case 2:
			saveReservation (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);		// Save the changes made and display success message
			fflush(stdin);
			clrBox();
			box(20,5,100,22);
			
			gotoxy(38,7);printf("---------------------------------------------");
			gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,9);printf("---------------------------------------------");
			gotoxy(44,12);printf("    Edit Succesfully Saved!");		/// Color			// Display a message that indicates that the inputs were saved
			gotoxy(38,15);printf("---------------------------------------------");
			gotoxy(38,16);printf("     [1] Main Menu          [2] Back ");
			gotoxy(38,17);printf("---------------------------------------------");
			gotoxy(38,19);printf("       Enter Choice [1-2]: ");
			gotoxy(59,19);scanf("%d", &choice);
			
			switch (choice)
			{
				case 1:
					displayMainMenu (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);		// Go back to the main menu
				break;
					case 2:
				displaytieditrr(details, reservation , nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);		// Return to the current reservation's edit page
				break;
				default:
					clrBox();
					red();
					gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
					reset();
					gotoxy(44,13);printf("Please enter correct input!");
					gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
					gotoxy(72,14);scanf("%c", &ch);
							
					if (ch == 'Y' || ch == 'y')
					{   
				       clrBox();
				        fflush(stdin);
				        displaytieditrr(details, reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);		// If the user wants to try again, clear the screen and repeat the editing process
				    }
				    else
				    {
						return;		// If the user chooses not to try again, exit the program
				    }
				break;				
			}
		break;
		default:
		clrBox();
		red();
		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		reset();
		gotoxy(44,13);printf("Please enter correct input!");
		gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
		gotoxy(72,14);scanf(" %c", &ch);
				
		if (ch == 'Y' || ch == 'y')		// If the user wants to try again, clear the screen and repeat the editing process
		{   
	       clrBox();
	        fflush(stdin);
	        displaytieditrr(details, reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
	    }
	    else
	    {	// If the user chooses not to try again, exit the program
			return;
	    }	
	}
}

/*
*	Function: EditRRMainPage	
*	Description: Allows user to edit his/her reservation or personal details within the program
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/

void EditRRMainPage(struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int edit_choice, int nBuilding, int nRoom, int chosenBuildingIndex)	// No comment yet
{
	int choice, choice2, choice3, choice4;
	char fname[31];
	char lname[31];
	char idno[31];
	char yr[31];
	char prog[31];
	char ch;
	char petsa [21];
	int dadalo;
	char desc [51];
	char initialBuilding [51];
	char initialRoom [51];
	int i;
	int roomIndex = -1;
	
	fflush(stdin);
	clrBox();
	box(20,5,100,22);
	//display all the details of user
	gotoxy(38,6);printf("---------------------------------------------");
	gotoxy(38,7);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,8);printf("---------------------------------------------");
	gotoxy(38,9);printf("          \033[0;32m\033[1m[1] Personal Details\033[0m");				//CHANGE COLOR
	gotoxy(38,10);printf("\033[1m  First Name:\033[0m %s", details[edit_choice].firstname);
	gotoxy(59,10);printf("\033[1m   Last Name:\033[0m %s", details[edit_choice].lastname);
	gotoxy(38,11);printf("\033[1m  ID Number:\033[0m %s", details[edit_choice].idnumber);
	gotoxy(59,11);printf("\033[1m   Year:\033[0m %s", details[edit_choice].year);
	gotoxy(38,12);printf("\033[1m  Program:\033[0m %s", details[edit_choice].program);
	gotoxy(38,13);printf("---------------------------------------------");
	gotoxy(38,14);printf("         \033[0;32m\033[1m[2] Reservation Details\033[0m");			// CHANGE COLOR
	gotoxy(38,15);printf("\033[1m  Room Type:\033[0m %s", reservation[edit_choice].roomtype);
	gotoxy(61,15);printf("\033[1m Room:\033[0m %s", reservation[edit_choice].room);
	gotoxy(38,16);printf("\033[1m  Date:\033[0m %s", reservation[edit_choice].date);
	gotoxy(59,16);printf("\033[1m   Number of Participants:\033[0m %d", reservation[edit_choice].nparticipants);
	gotoxy(38,17);printf("\033[1m  Time:\033[0m %s", reservation[edit_choice].time);
	gotoxy(38,18);printf("\033[1m  Description of use:\033[0m %s", reservation[edit_choice].description);
	gotoxy(38,19);printf("---------------------------------------------");
	gotoxy(38,20);printf("       \033[1mWhat do you wish to edit [1-4]: \033[0m ");

	gotoxy(32,21);printf("   NOTE: Enter [3] to go back & Enter [4] to Save Changes");		//CHANGE COLOR

	gotoxy(77,20);scanf("%d", &choice);
	
	switch(choice)
	{
		case 1:
			fflush(stdin);
			clrBox();
			box(20,5,100,22);
			//display personal details of user and allows them edit it
			gotoxy(38,6);printf("---------------------------------------------");
			gotoxy(38,7);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,8);printf("---------------------------------------------");
			gotoxy(38,9);printf("        \033[1mP E R S O N A L  D E T A I L S\033[0m");				//CHANGE COLOR
			gotoxy(49,11);printf("\033[1m [1] First Name:\033[0m %s", details[edit_choice].firstname);
			gotoxy(49,12);printf("\033[1m [2] Last Name:\033[0m %s", details[edit_choice].lastname);
			gotoxy(49,13);printf("\033[1m [3] ID Number:\033[0m %s", details[edit_choice].idnumber);
			gotoxy(49,14);printf("\033[1m [4] Year:\033[0m %s", details[edit_choice].year);
			gotoxy(49,15);printf("\033[1m [5] Program:\033[0m %s", details[edit_choice].program);
			gotoxy(49,16);printf("\033[1m [6] Back\033[0m");
			gotoxy(38,18);printf("---------------------------------------------");
			gotoxy(50,19);printf("\033[1mEnter Choice [1-6]: \033[0m ");
			gotoxy(70,19);scanf("%d", &choice2);	
			
			switch (choice2)
			{
				case 1:
					fflush(stdin);
					clrBox();
					box(20,5,100,22);
					gotoxy(38,7);printf("---------------------------------------------");
					gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
					gotoxy(38,9);printf("---------------------------------------------");
					gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
					gotoxy(38,13);printf("          Current First Name: %s", details[edit_choice].firstname);
					gotoxy(38,14);printf("          Enter New First Name: ");
					gotoxy(70,14);fgets(fname, sizeof(fname), stdin);
		        				fname[strlen(fname) - 1] = '\0';
					gotoxy(38,17);printf("---------------------------------------------");
					gotoxy(38,19);printf("        \033[1mPress [S] to save your edit : \033[0m");
					gotoxy(76,19);scanf("%c", &ch);
					
					if(ch == 's' || ch == 'S')
					{
						strcpy(details[edit_choice].firstname, fname);
						fflush(stdin);
						clrBox();
						box(20,5,100,22);
						gotoxy(44,12);printf("    Edit Succesfully Changed!");		/// Color
						gotoxy(33,14);printf("Do you wish to do another edit on your details? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");
						gotoxy(88,14);scanf("%c", &ch);
						
						if (ch == 'Y' || ch == 'y')
						{
							EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						}
						else if (ch == 'N' || ch == 'n')
						{
							displaytieditrr(details, reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						}
						else
						{
							clrBox();
							red();
							gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
							reset();
							gotoxy(44,13);printf("Please enter correct input! Edit changed!");											///
							gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
							gotoxy(72,14);scanf(" %c", &ch);
									
							if (ch == 'Y' || ch == 'y')
							{   
						       clrBox();
						        fflush(stdin);
						        EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						    }
						    else
						    {
								return;
						    }		
						}	
					}		
					else
					{
		            	clrBox();
		  				red();
		    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		   				reset();
		   				gotoxy(44,13);printf("Please enter correct input! Edit didn't save!");
		   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(72,14);scanf(" %c", &ch);
				
						if (ch == 'Y' || ch == 'y')
		    			{   
		       				clrBox();
		       				fflush(stdin);
		       				EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
		    			}
		    			else
		    			{
							return;
						}
					}
					break;
					case 2:
						fflush(stdin);
						clrBox();
						box(20,5,100,22);
						gotoxy(38,7);printf("---------------------------------------------");
						gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
						gotoxy(38,9);printf("---------------------------------------------");
						gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
						gotoxy(38,13);printf("          Current Last Name: %s", details[edit_choice].lastname);
						gotoxy(38,14);printf("          Enter New Last Name:");
						gotoxy(69,14);fgets(lname, sizeof(lname), stdin);
		        				lname[strlen(lname) - 1] = '\0';
						gotoxy(38,17);printf("---------------------------------------------");
						gotoxy(38,19);printf("        \033[1mPress [S] to save your edit : \033[0m");
						gotoxy(76,19);scanf("%c", &ch);
					
					if(ch == 's' || ch == 'S')
					{
						strcpy(details[edit_choice].lastname, lname);
						fflush(stdin);
						clrBox();
						box(20,5,100,22);
						gotoxy(44,12);printf("    Edit Succesfully Changed!");		/// Color
						gotoxy(33,14);printf("Do you wish to do another edit on your details? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");
						gotoxy(88,14);scanf("%c", &ch);
						
						if (ch == 'Y' || ch == 'y')
						{
							EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						}
						else if (ch == 'N' || ch == 'n')
						{
							displaytieditrr(details, reservation, nReservation, edit_choice, nBuilding,nRoom, chosenBuildingIndex);
						}
						else
						{
							clrBox();
							red();
							gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
							reset();
							gotoxy(44,13);printf("Please enter correct input! Edit changed!");											///
							gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
							gotoxy(72,14);scanf(" %c", &ch);
									
							if (ch == 'Y' || ch == 'y')
							{   
						       clrBox();
						        fflush(stdin);
						        EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						    }
						    else
						    {
								return;
						    }		
						}	
					}		
					else
					{
		            	clrBox();
		  				red();
		    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		   				reset();
		   				gotoxy(44,13);printf("Please enter correct input! Edit didn't save!");
		   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(72,14);scanf(" %c", &ch);
				
						if (ch == 'Y' || ch == 'y')
		    			{   
			       			clrBox();
			       			fflush(stdin);
			       			EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
		    			}
		    			else
		    			{
							return;
						}
					}
					break;
					case 3: 
						fflush(stdin);
						clrBox();
						box(20,5,100,22);
						gotoxy(38,7);printf("---------------------------------------------");
						gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
						gotoxy(38,9);printf("---------------------------------------------");
						gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
						gotoxy(38,13);printf("          Current ID Number: %s", details[edit_choice].idnumber);
						gotoxy(38,14);printf("          Enter New ID number: ");
						gotoxy(69,14);fgets(idno, sizeof(idno), stdin);
		        				idno[strlen(idno) - 1] = '\0';
						gotoxy(38,17);printf("---------------------------------------------");
						gotoxy(38,19);printf("        \033[1mPress [S] to save your edit : \033[0m");
						gotoxy(76,19);scanf("%c", &ch);
					
					if(ch == 's' || ch == 'S')
					{
						strcpy(details[edit_choice].idnumber, idno);
						fflush(stdin);
						clrBox();
						box(20,5,100,22);
						gotoxy(44,12);printf("    Edit Succesfully Changed!");		/// Color
						gotoxy(33,14);printf("Do you wish to do another edit on your details? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");
						gotoxy(88,14);scanf("%c", &ch);
						
						if (ch == 'Y' || ch == 'y')
						{
							EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						}
						else if (ch == 'N' || ch == 'n')
						{
							displaytieditrr(details, reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						}
						else
						{
							clrBox();
							red();
							gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
							reset();
							gotoxy(44,13);printf("Please enter correct input! Edit changed!");											///invalid input
							gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
							gotoxy(72,14);scanf(" %c", &ch);
									
							if (ch == 'Y' || ch == 'y')
							{   
						       clrBox();
						        fflush(stdin);
						        EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						    }
						    else
						    {
								return;
						    }		
						}	
					}		
					else
					{
		            	clrBox();
		  				red();
		    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		   				reset();
		   				gotoxy(44,13);printf("Please enter correct input! Edit didn't save!");
		   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(72,14);scanf(" %c", &ch);
				
						if (ch == 'Y' || ch == 'y')
		    			{   
			       			clrBox();
			       			fflush(stdin);
			       			EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
		    			}
		    			else
		    			{
							return;
						}
					}
					break;
					case 4:
						fflush(stdin);
						clrBox();
						box(20,5,100,22);
						gotoxy(38,7);printf("---------------------------------------------");
						gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
						gotoxy(38,9);printf("---------------------------------------------");
						gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
						gotoxy(38,13);printf("          Current Year: %s", details[edit_choice].year);
						gotoxy(38,14);printf("          Enter New Year: ");
						gotoxy(64,14);fgets(yr, sizeof(yr), stdin);
		        				yr[strlen(yr) - 1] = '\0';
						gotoxy(38,17);printf("---------------------------------------------");
						gotoxy(38,19);printf("        \033[1mPress [S] to save your edit : \033[0m");
						gotoxy(76,19);scanf("%c", &ch);
							
								
					if(ch == 's' || ch == 'S')
					{
						strcpy(details[edit_choice].year, yr);
						fflush(stdin);
						clrBox();
						box(20,5,100,22);
						gotoxy(44,12);printf("    Edit Succesfully Changed!");		/// Color
						gotoxy(33,14);printf("Do you wish to do another edit on your details? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");
						gotoxy(88,14);scanf("%c", &ch);
						
						if (ch == 'Y' || ch == 'y')
						{
							EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding , nRoom, chosenBuildingIndex);
						}
						else if (ch == 'N' || ch == 'n')
						{
							displaytieditrr(details, reservation, nReservation, edit_choice, nBuilding,nRoom, chosenBuildingIndex);
						}
						else
						{
							clrBox();
							red();
							gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
							reset();
							gotoxy(44,13);printf("Please enter correct input! Edit changed!");											///
							gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
							gotoxy(72,14);scanf(" %c", &ch);
									
							if (ch == 'Y' || ch == 'y')
							{   
						       clrBox();
						        fflush(stdin);
						        EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						    }
						    else
						    {
								return;
						    }		
						}	
					}		
					else
					{
		            	clrBox();
		  				red();
		    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		   				reset();
		   				gotoxy(44,13);printf("Please enter correct input! Edit didn't save!");
		   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(72,14);scanf(" %c", &ch);
				
						if (ch == 'Y' || ch == 'y')
		    			{   
			       			clrBox();
			       			fflush(stdin);
			       			EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
		    			}
		    			else
		    			{
							return;
						}
					}
					break;
					case 5:
						fflush(stdin);
						clrBox();
						box(20,5,100,22);
						gotoxy(38,7);printf("---------------------------------------------");
						gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
						gotoxy(38,9);printf("---------------------------------------------");
						gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
						gotoxy(38,13);printf("          Current Program: %s\n", details[edit_choice].program);
						gotoxy(38,14);printf("          Enter New program: ");
						gotoxy(67,14);fgets(prog, sizeof(prog), stdin);
		        					prog[strlen(prog) - 1] = '\0';
						gotoxy(38,17);printf("---------------------------------------------");
						gotoxy(38,19);printf("        \033[1mPress [S] to save your edit : \033[0m");
						gotoxy(76,19);scanf("%c", &ch);
									
					if(ch == 's' || ch == 'S')
					{
						strcpy(details[edit_choice].program, prog);
						fflush(stdin);
						clrBox();
						box(20,5,100,22);
						gotoxy(44,12);printf("    Edit Succesfully Changed!");		/// Color
						gotoxy(33,14);printf("Do you wish to do another edit on your details? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");
						gotoxy(88,14);scanf("%c", &ch);
						
						if (ch == 'Y' || ch == 'y')
						{
							EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						}
						else if (ch == 'N' || ch == 'n')
						{
							displaytieditrr(details, reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						}
						else
						{
							clrBox();
							red();
							gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
							reset();
							gotoxy(44,13);printf("Please enter correct input! Edit changed!");											///
							gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
							gotoxy(72,14);scanf(" %c", &ch);
									
							if (ch == 'Y' || ch == 'y')
							{   
						       clrBox();
						        fflush(stdin);
						        EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						    }
						    else
						    {
								return;
						    }		
						}	
					}		
					else
					{
		            	clrBox();
		  				red();
		    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		   				reset();
		   				gotoxy(44,13);printf("Please enter correct input! Edit didn't save!");
		   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(72,14);scanf(" %c", &ch);
				
						if (ch == 'Y' || ch == 'y')
		    			{   
			       			clrBox();
			       			fflush(stdin);
			       			EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
		    			}
		    			else
		    			{
							return;
						}
					}	
					break;
					case 6:
						EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
					break;
					default:
						clrBox();
		  				red();
		    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		   				reset();
		   				gotoxy(44,13);printf("Please enter correct input!");
		   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(72,14);scanf(" %c", &ch);
				
						if (ch == 'Y' || ch == 'y')
		    			{   
			       			clrBox();
			       			fflush(stdin);
			       			EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
		    			}
		    			else
		    			{
							return;
						}	
					break;		
			}
	break;
	case 2:	//editing of reservation details
		fflush(stdin);
			clrBox();
			box(20,5,100,22);
			//prompts all reservation details of user
			gotoxy(38,6);printf("---------------------------------------------");
			gotoxy(38,7);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,8);printf("---------------------------------------------");
			gotoxy(38,9);printf("     \033[1mR E S E R V A T I O N  D E T A I L S\033[0m");				//CHANGE COLOR
			gotoxy(47,11);printf("\033[1m [1] Room Type:\033[0m %s", reservation[edit_choice].roomtype);
			gotoxy(47,12);printf("\033[1m [2] Room:\033[0m %s - %s", reservation[edit_choice].buildingname, reservation[edit_choice].room);
			gotoxy(47,13);printf("\033[1m [3] Date:\033[0m %s",  reservation[edit_choice].date);
			gotoxy(47,14);printf("\033[1m [4] Number of Participants:\033[0m %d",  reservation[edit_choice].nparticipants);
			gotoxy(47,15);printf("\033[1m [5] Time:\033[0m %s",  reservation[edit_choice].time);
			gotoxy(47,16);printf("\033[1m [6] Description of use: %s \033[0m",  reservation[edit_choice].description);
			gotoxy(47,17);printf("\033[1m [7] Back\033[0m");
			gotoxy(38,19);printf("---------------------------------------------");
			gotoxy(50,20);printf("\033[1mEnter Choice [1-7]: \033[0m ");
			gotoxy(70,20);scanf("%d", &choice3);
			
			switch (choice3)
			{	//
				case 1:
					fflush(stdin);
					clrBox();
					box(20,5,100,22);
					
					gotoxy(38,7);printf("---------------------------------------------");
					gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
					gotoxy(38,9);printf("---------------------------------------------");
					gotoxy(42,10);printf("           \033[1mTYPE OF ROOM:\033[0m");
					gotoxy(42,12);printf("        [1] Classroom");
					gotoxy(42,13);printf("        [2] Seminar Room");
					gotoxy(42,14);printf("        [3] Auditorium ");
					gotoxy(42,15);printf("        [4] Training Room");
					gotoxy(42,16);printf("        [5] Back");
					gotoxy(38,18);printf("---------------------------------------------");
					gotoxy(38,20);printf("            \033[1mEnter Choice [1-5]: \033[0m");
					gotoxy(70,20);scanf("%d", &choice4);
					
					switch (choice4) {
				    	case 1:
				       		strcpy(reservation[edit_choice].roomtype, "Classroom");
				        	break;
				    	case 2:
				        	strcpy(reservation[edit_choice].roomtype, "Seminar");
				        	break;
				    	case 3:
				        	strcpy(reservation[edit_choice].roomtype, "Auditorium");
				        	break;
				    	case 4:
				        	strcpy(reservation[edit_choice].roomtype, "Training");
				        	break;
				    	case 5:
				        	EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
				        	break;
				    	default:
				        	clrBox();
				  			red();
				    		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
				   			reset();
				   			gotoxy(44,13);printf("Please enter correct input!");
				   			gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
							gotoxy(72,14);scanf(" %c", &ch);
						
							if (ch == 'Y' || ch == 'y')
				    		{   
				        	clrBox();
				       		fflush(stdin);
				        	roomreserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				    		}
				    		else
				    		{
								return;
				    		}	
				        break;
						}
				
					fflush(stdin);
					clrBox();
					box(20,5,100,22);
					
					gotoxy(38,7);printf("---------------------------------------------");
					gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
					gotoxy(38,9);printf("---------------------------------------------");
					gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
					
					gotoxy(38,13);printf("    Your new type of room is : %s", reservation[edit_choice].roomtype);
					
					gotoxy(38,16);printf("---------------------------------------------");
					gotoxy(38,18);printf("        \033[1mPress [S] to save your edit : \033[0m");
					gotoxy(76,18);scanf("%c", &ch);
					
									
					if(ch == 's' || ch == 'S')
					{
						fflush(stdin);
						clrBox();
						box(20,5,100,22);
						gotoxy(44,12);printf("    Edit Succesfully Changed!");		/// Color
						gotoxy(33,14);printf("Do you wish to do another edit on your details? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");
						gotoxy(88,14);scanf("%c", &ch);
						
						if (ch == 'Y' || ch == 'y')
						{
							EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom,chosenBuildingIndex);
						}
						else if (ch == 'N' || ch == 'n')
						{
							displaytieditrr(details, reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						}
						else
						{
							clrBox();
							red();
							gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
							reset();
							gotoxy(44,13);printf("Please enter correct input! Edit changed!");											///
							gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
							gotoxy(72,14);scanf(" %c", &ch);
									
							if (ch == 'Y' || ch == 'y')
							{   
						       clrBox();
						        fflush(stdin);
						        EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						    }
						    else
						    {
								return;
						    }		
						}	
					}		
				break;
				case 2:

						fflush(stdin);					
						clrBox();
						box(20,5,100,22);
						gotoxy(38,6);printf("---------------------------------------------");
						gotoxy(38,7);printf("              \033[1mROOM RESERVATION\033[0m");
						gotoxy(38,8);printf("---------------------------------------------");
						gotoxy(38,9);printf("            [BUILDINGS AVAILABLE]");
						
				        for (i = 0; i < nBuilding; i++)
				        {
				            gotoxy(53, 11 + i); printf("  %s", reservation[i].buildings[i].mainbuilding);
				        }
						gotoxy(38,19);printf("---------------------------------------------");
						gotoxy(45,20);printf("  Enter the building where");
						gotoxy(45,21);printf("  you want to reserve room:");
						fflush(stdin);							
						gotoxy(73,21);fgets(initialBuilding, sizeof(initialBuilding), stdin);
				        			initialBuilding[strlen(initialBuilding) - 1] = '\0';
				        		
						chosenBuildingIndex = -1; // Initialize chosenBuildingIndex to -1 before the loop
				
						for (i = 0; i < nBuilding; i++) {
						    if (strcmp(initialBuilding, reservation[i].buildings[i].mainbuilding) == 0) {
						        chosenBuildingIndex = i;
						        // Exit the loop once a match is found
						        break;
						    }
						}
					
						if (chosenBuildingIndex == -1)
					            {
					                clrBox();
					                box(20, 5, 100, 22);
					                gotoxy(38, 7);printf("---------------------------------------------");
					                gotoxy(38, 8);printf("              \033[1mROOM RESERVATION\033[0m");
									gotoxy(38, 9);printf("---------------------------------------------");
									gotoxy(48, 12);printf("\033[31mERROR!\033[0m Building not found!");
									gotoxy(38, 15);printf("---------------------------------------------");
					                gotoxy(38, 16);printf("     [1] Retry    [2] Back to Main Menu");
					                gotoxy(38, 17);printf("---------------------------------------------");
					                gotoxy(53, 19);printf("Choice: ");
					                gotoxy(61, 19);scanf("%d", &choice);
					
					                switch (choice)
					                {
					                    case 1:
					                        askRoomandBuilding( details ,  reservation,  nReservation,  nBuilding,  nRoom, chosenBuildingIndex);
					                        break;
					                    case 2:
					                        displayMainMenu(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					                        break;
					                    default:	//change
					                        break;
					                }
					            }	
						
						else{
						reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom = loadRooms(details, reservation, nBuilding, chosenBuildingIndex);
						if(reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom == 0)
						{
							clrBox();
							box(20, 5, 100, 22);
					        gotoxy(38, 7);printf("---------------------------------------------");
					        gotoxy(38, 8);printf("              \033[1mROOM RESERVATION\033[0m");
							gotoxy(38, 9);printf("---------------------------------------------");
							gotoxy(38,12);printf("     No Rooms Exists in the Building Yet");		
							gotoxy(38,13);printf("    Wait for the Admin to add Room first!");	
							gotoxy(38,18);printf("---------------------------------------------");
							gotoxy(38,19);printf("  [1] Back to Main Menu       [2] Retry");
							gotoxy(38,20);printf("---------------------------------------------");
							gotoxy(38,21);printf("           \033[1mEnter Choice [1-2]: \033[0m");
							gotoxy(73,21);scanf("%d", &choice);
							
						switch(choice)
						{
							case 1: 
								displayMainMenu(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
								break;
							case 2: 
								askRoomandBuilding(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
								break;
							default:
								clrBox();
					  			red();
					    		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
					   			reset();
					   			gotoxy(44,13);printf("Please enter correct input!");
					   			gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
								gotoxy(80,14);scanf(" %c", &ch);
							
								if (ch == 'Y' || ch == 'y')
					    		{   
						        	clrBox();
						       		fflush(stdin);
						        	roomreserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					    		}
					    		else
					    		{
									return;
					    		}	
							break;
								
							}
						}
						else{
							clrBox();
							box(20, 5, 100, 22);
					        gotoxy(38, 6);printf("---------------------------------------------");
					        gotoxy(38, 7);printf("              \033[1mROOM RESERVATION\033[0m");
							gotoxy(38, 8);printf("---------------------------------------------");
							gotoxy(38, 9);printf("         [ROOMS AVAILABLE IN %s]", initialBuilding);
							
						    for (i = 0; i < reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom; i++)
						    {
						        gotoxy(49, 11 + i);printf("      %s", reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].rooms[i].mainroom);
						    }
						    
							gotoxy(38,20);printf("---------------------------------------------");
							gotoxy(40,21);printf("Enter the room you want to reserve: ");
							fflush(stdin);
							gotoxy(40,69);fgets(initialRoom, sizeof(initialRoom), stdin);
				        			initialRoom[strlen(initialRoom) - 1] = '\0';
						
							for (i = 0; i < reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].nRoom; i++) {
							    if (strcmp(initialRoom, reservation[chosenBuildingIndex].buildings[chosenBuildingIndex].rooms[i].mainroom) == 0) {
							        roomIndex = i;
							        // Exit the loop once a match is found
							        break;
							    }
							}
							
							if(roomIndex == -1)
							{
					                clrBox();
					                box(20, 5, 100, 22);
					                gotoxy(38, 7);printf("---------------------------------------------");
					                gotoxy(38, 8);printf("              \033[1mROOM RESERVATION\033[0m");
									gotoxy(38, 9);printf("---------------------------------------------");
									gotoxy(48, 12);printf("\033[31mERROR!\033[0m Room is not Found!");
									gotoxy(38, 15);printf("---------------------------------------------");
					                gotoxy(38, 16);printf("     [1] Retry    [2] Back to Main Menu");
					                gotoxy(38, 17);printf("---------------------------------------------");
					                gotoxy(53, 19);printf("Choice: ");
					                gotoxy(61, 19);scanf("%d", &choice);
					
					                switch (choice)
					                {
					                    case 1:
					                        FilloutRoomReserve( details ,  reservation,  nReservation,  nBuilding,  nRoom, chosenBuildingIndex);
					                        break;
					                    case 2:
					                        displayMainMenu(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
					                        break;
					                    default:	//change
					                        break;
					                }
			        		  }
					else{
					strcpy(reservation[edit_choice].buildingname, initialBuilding);
					strcpy(reservation[edit_choice].room, initialRoom);	
					}	
				}
			}	//prompt changes
					fflush(stdin);
					clrBox();
					box(20,5,100,22);
					gotoxy(38,7);printf("---------------------------------------------");
					gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
					gotoxy(38,9);printf("---------------------------------------------");
					gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
					gotoxy(38,13);printf("     Your new room is : %s - %s", reservation[edit_choice].buildingname, reservation[edit_choice].room);
					gotoxy(38,17);printf("---------------------------------------------");
					gotoxy(38,19);printf("        \033[1mPress [S] to save your edit : \033[0m");
					gotoxy(76,19);scanf("%c", &ch);
									
					if(ch == 's' || ch == 'S')
					{
						fflush(stdin);
						clrBox();
						box(20,5,100,22);
						gotoxy(44,12);printf("    Edit Succesfully Changed!");		/// Color
						gotoxy(33,14);printf("Do you wish to do another edit on your details? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");
						gotoxy(88,14);scanf("%c", &ch);

						if (ch == 'Y' || ch == 'y')
						{
							EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						}
						else if (ch == 'N' || ch == 'n')
						{
							displaytieditrr(details, reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						}
						else
						{
							clrBox();
							red();
							gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
							reset();
							gotoxy(44,13);printf("Please enter correct input! Edit changed!");											///
							gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
							gotoxy(72,14);scanf(" %c", &ch);
									
							if (ch == 'Y' || ch == 'y')
							{   
						       clrBox();
						        fflush(stdin);
						        EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						    }
						    else
						    {
								return;
						    }		
						}	
					}		
					else
					{
		            	clrBox();
		  				red();
		    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		   				reset();
		   				gotoxy(44,13);printf("Please enter correct input! Edit didn't save!");
		   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(72,14);scanf(" %c", &ch);
				
						if (ch == 'Y' || ch == 'y')
		    			{   
			       			clrBox();
			       			fflush(stdin);
			       			EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
		    			}
		    			else
		    			{
							return;
						}
					}	
				break;
				case 3:
					fflush(stdin);
					clrBox();
					box(20,5,100,22);
					gotoxy(38,7);printf("---------------------------------------------");
					gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
					gotoxy(38,9);printf("---------------------------------------------");
					gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
					gotoxy(38,13);printf("          Current Date: %s", reservation[edit_choice].date);
					gotoxy(38,14);printf("          Enter New Date: ");
					gotoxy(64,14);fgets(petsa, sizeof(petsa), stdin);
		        				petsa[strlen(petsa) - 1] = '\0';
					gotoxy(38,17);printf("---------------------------------------------");
					gotoxy(38,19);printf("        \033[1mPress [S] to save your edit : \033[0m");
					gotoxy(76,19);scanf("%c", &ch);
									
					if(ch == 's' || ch == 'S')
					{
						strcpy(reservation[edit_choice].date, petsa);
						fflush(stdin);
						clrBox();
						box(20,5,100,22);
						gotoxy(44,12);printf("    Edit Succesfully Changed!");		/// Color
						gotoxy(33,14);printf("Do you wish to do another edit on your details? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");
						gotoxy(88,14);scanf("%c", &ch);
						
						if (ch == 'Y' || ch == 'y')
						{
							EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						}
						else if (ch == 'N' || ch == 'n')
						{
							displaytieditrr(details, reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						}
						else
						{
							clrBox();
							red();
							gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
							reset();
							gotoxy(44,13);printf("Please enter correct input! Edit changed!");											///
							gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
							gotoxy(72,14);scanf(" %c", &ch);
									
							if (ch == 'Y' || ch == 'y')
							{   
						       clrBox();
						        fflush(stdin);
						        EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						    }
						    else
						    {
								return;
						    }		
						}	
					}		
					else
					{
		            	clrBox();
		  				red();
		    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		   				reset();
		   				gotoxy(44,13);printf("Please enter correct input! Edit didn't save!");
		   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(72,14);scanf(" %c", &ch);
				
						if (ch == 'Y' || ch == 'y')
		    			{   
			       			clrBox();
			       			fflush(stdin);
			       			EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom,chosenBuildingIndex);
		    			}
		    			else
		    			{
							return;
						}
					}	
				break;
				case 4:
					fflush(stdin);
					clrBox();
					box(20,5,100,22);
					int validInput = 0;
					while (!validInput) {
					gotoxy(38,7);printf("---------------------------------------------");
					gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
					gotoxy(38,9);printf("---------------------------------------------");
					gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
					gotoxy(38,13);printf("     Current Number of Participants: %d", reservation[edit_choice].nparticipants);
						gotoxy(38, 14); printf("     Enter New Number of Participants: ");
						gotoxy(78, 14); scanf("%d", &dadalo);
					
						if (dadalo <= 45) {
							validInput = 1;
						} else {
							clrBox();
							red();
							gotoxy(40, 11); printf("\033[1mINVALID INPUT!\033[0m");
							reset();
							gotoxy(40, 13); printf("Room can only accommodate 45 participants!");
							gotoxy(40, 14); printf("Press any key to re-enter the value...");
							getch();
							clrBox();
						}
					}
			//save edit
					gotoxy(38,17);printf("---------------------------------------------");
					gotoxy(38,19);printf("        \033[1mPress [S] to save your edit : \033[0m");
					fflush(stdin);
					gotoxy(76,19);scanf("%c", &ch);
					
									
					if(ch == 's' || ch == 'S')
					{
						reservation[edit_choice].nparticipants=dadalo;
						fflush(stdin);
						clrBox();
						box(20,5,100,22);
						gotoxy(44,12);printf("    Edit Succesfully Changed!");		/// Color
						gotoxy(33,14);printf("Do you wish to do another edit on your details? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");
						gotoxy(88,14);scanf("%c", &ch);
						
						if (ch == 'Y' || ch == 'y')
						{
							EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						}
						else if (ch == 'N' || ch == 'n')
						{
							displaytieditrr(details, reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						}
						else
						{
							clrBox();
							red();
							gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
							reset();
							gotoxy(44,13);printf("Please enter correct input! Edit changed!");											///
							gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
							gotoxy(72,14);scanf(" %c", &ch);
									
							if (ch == 'Y' || ch == 'y')
							{   
						       clrBox();
						        fflush(stdin);
						        EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						    }
						    else
						    {
								return;
						    }		
						}	
					}		
					else
					{
		            	clrBox();
		  				red();
		    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		   				reset();
		   				gotoxy(44,13);printf("Please enter correct input! Edit didn't save!");
		   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(72,14);scanf(" %c", &ch);
				
						if (ch == 'Y' || ch == 'y')
		    			{   
			       			clrBox();
			       			fflush(stdin);
			       			EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
		    			}
		    			else
		    			{
							return;
						}
					}	
				break;
				case 5:
				fflush(stdin);
				clrBox();
				box(20,5,100,22);
				
				gotoxy(38,6);printf("---------------------------------------------");
				gotoxy(38,7);printf("              \033[1mROOM RESERVATION\033[0m");
				gotoxy(38,8);printf("---------------------------------------------");
				gotoxy(50,9);printf("\033[1mTIME SLOTS AVAILABLE\033[0m");
				gotoxy(35,11);printf("           \033[0;32m\033[1m[1]\033[0m MTHF\033[0m");	//INPUT COLOR
				gotoxy(35,12);printf("          9:15-10:45");
				gotoxy(35,13);printf("          11:00-12:30");
				gotoxy(35,14);printf("          12:45-14:15");
				gotoxy(35,15);printf("          14:30-16:00");
				gotoxy(35,16);printf("          16:15-17:45");
				gotoxy(35,17);printf("          18:00-19:00");
				gotoxy(62,11);printf("      \033[0;32m\033[1m[2]\033[0m WS\033[0m");			//INPUT COLOR
				gotoxy(62,12);printf("    09:00-12:00");
				gotoxy(62,13);printf("    13:00-16:00");
				gotoxy(62,14);printf("    16:15-19:15");
				gotoxy(38,19);printf("---------------------------------------------");
				gotoxy(38,20);printf("            \033[1mEnter Choice [1-2]: \033[0m\n");
				gotoxy(70,20);scanf("%d", &choice);
				
				switch (choice)
				{
					case 1:
						fflush(stdin);
						clrBox();
						box(20,5,100,22);
						gotoxy(38,6);printf("---------------------------------------------");
						gotoxy(38,7);printf("              \033[1mROOM RESERVATION\033[0m");
						gotoxy(38,8);printf("---------------------------------------------");
						gotoxy(50,9);printf("\033[1mTIME SLOTS AVAILABLE\033[0m");
						gotoxy(50,11);printf("       \033[1m MTHF\033[0m");
						gotoxy(50,12);printf("  [1] 09:15-10:45");
						gotoxy(50,13);printf("  [2] 11:00-12:30");
						gotoxy(50,14);printf("  [3] 12:45-14:15");
						gotoxy(50,15);printf("  [4] 14:30-16:00");
						gotoxy(50,16);printf("  [5] 16:15-17:45");
						gotoxy(50,17);printf("  [6] 18:00-19:00");
						gotoxy(38,19);printf("---------------------------------------------");
						gotoxy(38,20);printf("            \033[1mEnter Choice [1-6]: \033[0m");
						gotoxy(70,20);scanf("%d", &choice);
						
						switch (choice){																								//CHECK TIME BASED SA LOADED FILE
							case 1:
								strcpy(reservation[edit_choice].time, "09:15-10:45");
							break;
							case 2: 
								strcpy(reservation[edit_choice].time, "11:00-12:30");
							break;
							case 3:
								strcpy(reservation[edit_choice].time, "12:45-14:15");
							break;
							case 4:
								strcpy(reservation[edit_choice].time, "14:30-16:00");
							break;
							case 5:
								strcpy(reservation[edit_choice].time, "16:15-17:45");
							break;
							case 6:
								strcpy(reservation[edit_choice].time, "18:00-19:00");
							break;
							default:
								clrBox();
			  					red();
			    				gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
			   					reset();
			   					gotoxy(44,13);printf("Please enter correct input!");
			   					gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
								gotoxy(72,14);scanf(" %c", &ch);
					
								if (ch == 'Y' || ch == 'y')
			    				{   
			       				clrBox();
			       				fflush(stdin);
			       				EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);		//// Change
			    				}
			    				else
			    				{
									return;
							break;
		    					}	
							}
						break;
				case 2:
					fflush(stdin);
					clrBox();
					box(20,5,100,22);
					gotoxy(38,7);printf("---------------------------------------------");
					gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
					gotoxy(38,9);printf("---------------------------------------------");
					gotoxy(50,10);printf("\033[1mTIME SLOTS AVAILABLE\033[0m");
					gotoxy(50,12);printf("      \033[1mWS033[0m");
					gotoxy(50,13);printf("  [1] 09:00-12:00");
					gotoxy(50,14);printf("  [2] 13:00-16:00");
					gotoxy(50,15);printf("  [3] 16:15-19:15");
					gotoxy(38,17);printf("---------------------------------------------");
					gotoxy(38,19);printf("            \033[1mEnter Choice [1-3]: \033[0m");
					gotoxy(70,19);scanf("%d", &choice);
					
					switch (choice){																//CHECK TIME BASED SA LOADED FILE
						case 1:
							strcpy(reservation[edit_choice].time, "09:00-12:00");
						break;
						case 2: 
							strcpy(reservation[edit_choice].time, "13:00-16:00");
						break;
						case 3:
							strcpy(reservation[edit_choice].time, "16:15-19:15");
						break;
						default:
							clrBox();
		  					red();
		    				gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		   					reset();
		   					gotoxy(44,13);printf("Please enter correct input!");
		   					gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
							gotoxy(72,14);scanf(" %c", &ch);
				
							if (ch == 'Y' || ch == 'y')
		    				{   
		       				clrBox();
		       				fflush(stdin);
		       				EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);	
		    				}
		    				else
		    				{
							return;
							}
						break;
							}
					}
					
					fflush(stdin);
					clrBox();
					box(20,5,100,22);
					
					gotoxy(38,7);printf("---------------------------------------------");
					gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
					gotoxy(38,9);printf("---------------------------------------------");
					gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
					gotoxy(38,13);printf("      Your new time is : %s", reservation[edit_choice].time);
					gotoxy(38,16);printf("---------------------------------------------");
					gotoxy(38,18);printf("        \033[1mPress [S] to save your edit : \033[0m");
					gotoxy(76,18);scanf("%c", &ch);
									
					if(ch == 's' || ch == 'S')
					{
						strcpy(reservation[edit_choice].date, petsa);
						fflush(stdin);
						clrBox();
						box(20,5,100,22);
						gotoxy(44,14);printf("Do you wish to do another edit on your details? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");
						gotoxy(76,14);scanf("%c", &ch);
						
						if (ch == 'Y' || ch == 'y')
						{
							EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						}
						else if (ch == 'N' || ch == 'n')
						{
							displaytieditrr(details, reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						}
						else
						{
							clrBox();
							red();
							gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
							reset();
							gotoxy(44,13);printf("Please enter correct input! Edit changed!");											///
							gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
							gotoxy(72,14);scanf(" %c", &ch);
									
							if (ch == 'Y' || ch == 'y')
							{   
						       clrBox();
						        fflush(stdin);
						        EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						    }
						    else
						    {
								return;
						    }		
						}	
					}		
					else
					{
		            	clrBox();
		  				red();
		    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		   				reset();
		   				gotoxy(44,13);printf("Please enter correct input! Edit didn't save!");
		   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(72,14);scanf(" %c", &ch);
				
						if (ch == 'Y' || ch == 'y')
		    			{   
		       			clrBox();
		       			fflush(stdin);
		       			EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
		    			}
		    			else
		    			{
							return;
						}
					}	
				break;
				case 6:
					fflush(stdin);
					clrBox();
					box(20,5,100,22);
					gotoxy(38,7);printf("---------------------------------------------");
					gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
					gotoxy(38,9);printf("---------------------------------------------");
					gotoxy(38,10);printf("              \033[1mEDITING DETAILS\033[0m");
					gotoxy(38,13);printf("          Current Description: %s", reservation[edit_choice].description);
					gotoxy(38,14);printf("          Enter New Description: ");
					gotoxy(71,14);fgets(desc, sizeof(desc), stdin);
        						desc[strlen(desc) - 1] = '\0';
					gotoxy(38,17);printf("---------------------------------------------");
					gotoxy(38,19);printf("        \033[1mPress [S] to save your edit : \033[0m");
					gotoxy(76,19);scanf("%c", &ch);
									
					if(ch == 's' || ch == 'S')
					{
						strcpy(reservation[edit_choice].description, desc);
						fflush(stdin);
						clrBox();
						box(20,5,100,22);
						gotoxy(44,12);printf("    Edit Succesfully Changed!");		/// Color
						gotoxy(33,14);printf("Do you wish to do another edit on your details? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]:");
						gotoxy(88,14);scanf("%c", &ch);
						
						if (ch == 'Y' || ch == 'y')
						{
							EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						}
						else if (ch == 'N' || ch == 'n')
						{
							displaytieditrr(details, reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						}
						else
						{
							clrBox();
							red();
							gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
							reset();
							gotoxy(44,13);printf("Please enter correct input! Edit changed!");											///
							gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
							gotoxy(72,14);scanf(" %c", &ch);
									
							if (ch == 'Y' || ch == 'y')
							{   
						       clrBox();
						        fflush(stdin);
						        EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
						    }
						    else
						    {
							return;
						    }		
						}	
					}		
					else
					{
		            	clrBox();
		  				red();
		    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		   				reset();
		   				gotoxy(44,13);printf("Please enter correct input! Edit didn't save!");
		   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(72,14);scanf(" %c", &ch);
				
						if (ch == 'Y' || ch == 'y')
		    			{   
		       			clrBox();
		       			fflush(stdin);
		       			EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
		    			}
		    			else
		    			{
							return;
						}
					}	
				break;
				case 7:
						EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
				break;
				default:
					clrBox();
		  				red();
		    			gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		   				reset();
		   				gotoxy(44,13);printf("Please enter correct input!");
		   				gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
						gotoxy(72,14);scanf(" %c", &ch);
				
						if (ch == 'Y' || ch == 'y')
		    			{   
		       			clrBox();
		       			fflush(stdin);
		       			EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
		    			}
		    			else
		    			{
						exit(0);
						}	
				break;
			}
	break;
	case 3:
		DisplayEditRRMainPage( details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
	break;
	case 4:
		saveReservation (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
			fflush(stdin);
			clrBox();
			box(20,5,100,22);
			gotoxy(38,7);printf("---------------------------------------------");
			gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,9);printf("---------------------------------------------");
			gotoxy(44,12);printf("    Edit Succesfully Saved!");		/// Color
			gotoxy(38,15);printf("---------------------------------------------");
			gotoxy(38,16);printf("     [1] Main Menu          [2] Back ");
			gotoxy(38,17);printf("---------------------------------------------");
			gotoxy(38,19);printf("            Enter Choice [1-2]: ");
			gotoxy(70,19);scanf("%d", &choice);
			
			switch (choice)
			{
				case 1:
					displayMainMenu (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
				break;
				case 2:
					 EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
				break;
				default:
					clrBox();
					red();
					gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
					reset();
					gotoxy(44,13);printf("Please enter correct input!");
					gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
					gotoxy(72,14);scanf(" %c", &ch);
							
					if (ch == 'Y' || ch == 'y')
					{   
				       clrBox();
				        fflush(stdin);
				         EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
				    }
				    else
				    {
						return;
				    }
				break;				
			}
	default:
		clrBox();
		red();
		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		reset();
		gotoxy(44,13);printf("Please enter correct input!");
		gotoxy(44,14);printf("Would you try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
		gotoxy(72,14);scanf(" %c", &ch);
				
		if (ch == 'Y' || ch == 'y')
		    {   
		    clrBox();
		    fflush(stdin);
		   	EditRRMainPage(details,reservation, nReservation, edit_choice, nBuilding, nRoom, chosenBuildingIndex);
		    }
		else
		    {
			return;
			}	
	break;	
	}
}

/*
*	Function: cancelReservation
*	Description: Allows user to cancel his/her reservation by choosing his/her reservations
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
*				 @param : int cancel_choice - contains the choice of the user which reservation to cancel
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/

void cancelReservation(struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int cancel_choice, int nBuilding, int nRoom, int chosenBuildingIndex)						//TO DOOOOO
{
	char ch;
	int choice;
	
    fflush(stdin);  // Clear the input buffer
    clrBox();  // Clear the console display in a specified box area
    box(20, 5, 100, 22);
	
	// Display personal and reservation details for the selected reservation
	gotoxy(38,6);printf("---------------------------------------------");
	gotoxy(38,7);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,8);printf("---------------------------------------------");
	gotoxy(38,9);printf("              \033[1mPersonal Details\033[0m");				//CHANGE COLOR
	gotoxy(38,10);printf("\033[1m  First Name:\033[0m %s", details[cancel_choice].firstname);
	gotoxy(59,10);printf("\033[1m   Last Name:\033[0m %s", details[cancel_choice].lastname);
	gotoxy(38,11);printf("\033[1m  ID Number:\033[0m %s", details[cancel_choice].idnumber);
	gotoxy(59,11);printf("\033[1m   Year:\033[0m %s", details[cancel_choice].year);
	gotoxy(38,12);printf("\033[1m  Program:\033[0m %s", details[cancel_choice].program);
	gotoxy(38,13);printf("---------------------------------------------");
	gotoxy(38,14);printf("            \033[1m Reservation Details\033[0m");			// CHANGE COLOR
	gotoxy(38,15);printf("\033[1m  Room Type:\033[0m %s", reservation[cancel_choice].roomtype);
	gotoxy(61,15);printf("\033[1m   Room:\033[0m %s", reservation[cancel_choice].room);
	gotoxy(38,16);printf("\033[1m  Date:\033[0m %s", reservation[cancel_choice].date);
	gotoxy(59,16);printf("\033[1m   Number of Participants:\033[0m %d", reservation[cancel_choice].nparticipants);
	gotoxy(38,17);printf("\033[1m  Time:\033[0m %s", reservation[cancel_choice].time);
	gotoxy(38,18);printf("\033[1m  Description of use:\033[0m %s", reservation[cancel_choice].description);
	gotoxy(38,19);printf("---------------------------------------------");
	gotoxy(35,20);printf(" \033[1mAre you sure you want cancel your reservation?\033[0m \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
	gotoxy(90,20);scanf("%c", &ch);	// Read user confirmation for reservation cancellation
	
	if (ch == 'y' || ch == 'Y')
	{
		fflush(stdin);  // Clear the input buffer
        clrBox();  // Clear the console display in a specified box area
        box(20, 5, 100, 22);
		
		nReservation--;		// Decrease the total number of reservations
		saveReservation (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		
		// Display cancellation successful message
		gotoxy(38,7);printf("---------------------------------------------");
		gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
		gotoxy(38,9);printf("---------------------------------------------");
		gotoxy(44,12);printf("    Cancellation Succesful!");						/// Color
		gotoxy(38,15);printf("---------------------------------------------");
		gotoxy(38,16);printf("     [1] Main Menu         [2] Homepage");
		gotoxy(38,17);printf("---------------------------------------------");
		gotoxy(38,19);printf("            Enter Choice [1-2]: ");
		gotoxy(70,19);scanf("%d", &choice);		//CHANGE COLORRRR
		
		switch (choice)
			{
				case 1:
					displayMainMenu (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);	// Go back to the main menu
				break;
				case 2:
					displayCover(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);		// Go back to the homepage
				break;
				default:
					clrBox();
					red();
					gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
					reset();
					gotoxy(44,13);printf("Please enter correct input!");
					gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
					gotoxy(72,14);scanf(" %c", &ch);// Read user input for the next action
							
					if (ch == 'Y' || ch == 'y')
					{   
						clrBox();
				    	fflush(stdin);
				    	cancelReservation(details, reservation, nReservation, cancel_choice, nBuilding, nRoom, chosenBuildingIndex);   
				    }
				    else
				    {
						exit(0);
				    }			
			}
	}
	else if (ch == 'N' || ch == 'n')
	{
		DisplayEditRRMainPage( details , reservation , nReservation,nBuilding, nRoom, chosenBuildingIndex);		// Go back to the edit reservation main page
	}
	else		
		clrBox();
		red();
		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");			// Display error message for invalid input
		reset();
		gotoxy(44,13);printf("Please enter correct input!");
		gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");		 // Ask the user if they want to try again or exit
		gotoxy(72,14);scanf(" %c", &ch);
							
		if (ch == 'Y' || ch == 'y')
			{   
			clrBox();
		   	fflush(stdin);
		   	cancelReservation(details, reservation, nReservation, cancel_choice, nBuilding, nRoom, chosenBuildingIndex);   		
			}
			else
			{
			exit(0);
		    }				
}

/*
*	Function: DisplayEditRRMainPage	
*	Description: Displays the updated and edited inputs from the user
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/

void DisplayEditRRMainPage(struct PersonalDetails details [], struct ReservationInfo reservation [], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex)	//no comment yet
{

	fflush(stdin);
	clrBox();
	box(20,5,100,22);
	
	int i, choice, edit_choice, choice2, cancel_choice;
	FILE *pFile;
	char ch;
	int k=11;
	
	pFile = fopen("reservationdetails.txt", "r");
	
	
	fscanf(pFile, "%d\n", &nReservation);
	for(i=0;i<nReservation;i++)
	{
		fgets(details[i].firstname, sizeof(details[i].firstname), pFile);
        details[i].firstname[strcspn(details[i].firstname, "\n")] = '\0'; // Remove the newline character

        fgets(details[i].lastname, sizeof(details[i].lastname), pFile);
        details[i].lastname[strcspn(details[i].lastname, "\n")] = '\0';

        fgets(details[i].idnumber, sizeof(details[i].idnumber), pFile);
        details[i].idnumber[strcspn(details[i].idnumber, "\n")] = '\0';

        fgets(details[i].program, sizeof(details[i].program), pFile);
        details[i].program[strcspn(details[i].program, "\n")] = '\0';

        fgets(details[i].year, sizeof(details[i].year), pFile);
        details[i].year[strcspn(details[i].year, "\n")] = '\0';

        fgets(reservation[i].date, sizeof(reservation[i].date), pFile);
        reservation[i].date[strcspn(reservation[i].date, "\n")] = '\0';

        fgets(reservation[i].time, sizeof(reservation[i].time), pFile);
        reservation[i].time[strcspn(reservation[i].time, "\n")] = '\0';

        fscanf(pFile, "%d", &reservation[i].nparticipants);
        fgetc(pFile); // Consume the newline character

        fgets(reservation[i].roomtype, sizeof(reservation[i].roomtype), pFile);
        reservation[i].roomtype[strcspn(reservation[i].roomtype, "\n")] = '\0';

        fgets(reservation[i].room, sizeof(reservation[i].room), pFile);
        reservation[i].room[strcspn(reservation[i].room, "\n")] = '\0';

		fgets(reservation[i].description, sizeof(reservation[i].description), pFile);
        reservation[i].description[strcspn(reservation[i].description, "\n")] = '\0';

	}
	if (pFile == NULL || nReservation <= 0)
	{
	gotoxy(38,7);printf("---------------------------------------------");
	gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,9);printf("---------------------------------------------");
	gotoxy(38,12);printf("             \033[1mNo Reservation!\033[0m");
	gotoxy(38,15);printf("---------------------------------------------");
	gotoxy(38,16);printf("[1] Back to Homepage");
	gotoxy(59,16);printf("  [2] Make a Reservation");
	gotoxy(49,17);printf("      [3] Back");
	gotoxy(38,18);printf("---------------------------------------------");
	gotoxy(38,20);printf("           \033[1mEnter Choice [1-3]: \033[0m");
	gotoxy(69,20);scanf("%d", &choice);
	
	switch (choice)
	{
		case 1:
			displayCover (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		break;
		case 2:
			roomreserve (details, reservation, nReservation, nBuilding, nRoom,chosenBuildingIndex);
		break;
		case 3:
			displayMainMenu (details, reservation, nReservation,nBuilding, nRoom, chosenBuildingIndex);
		break;
		default:
			clrBox();
  			red();
    		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
   			reset();
   			gotoxy(44,13);printf("Please enter correct input!");
   			gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
			gotoxy(80,14);scanf(" %c", &ch);
		
			if (ch == 'Y' || ch == 'y')
    		{   
        	clrBox();
       		fflush(stdin);
        	DisplayEditRRMainPage( details , reservation , nReservation, nBuilding, nRoom, chosenBuildingIndex);
    		}
    		else
    		{
			exit(0);
    		}
		break;	
	}
	}
	else{
	fflush(stdin);
	clrBox();
	box(20,5,100,22);
	
	gotoxy(38,7);printf("---------------------------------------------");
	gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
	gotoxy(38,9);printf("---------------------------------------------");
	gotoxy(38,10);printf("         \033[1mNumber of Reservations : %d\033[0m", nReservation);
	gotoxy(38,11);printf("     NAME       ROOM TYPE         TIME");																		//FIX FILE HANDLING
	for(i=0;i<nReservation;i++){
	k++;
	gotoxy(38,k);printf("  %d. %s        %s     %s", i+1, details[i].firstname, reservation[i].roomtype, reservation[i].time);
	}
	gotoxy(38,18);printf("---------------------------------------------");
	gotoxy(38,19);printf("\033[1m[1] Back");
	gotoxy(49,19);printf(" [2] Edit");
    gotoxy(60,19);printf(" [3] Cancel Reservation\033[0m");
	gotoxy(38,20);printf("---------------------------------------------");
	gotoxy(38,21);printf("           \033[1mEnter Choice [1-3]: \033[0m");
	gotoxy(69,21);scanf("%d", &choice2);
	
	switch (choice2)
	{
		case 1:
			displayMainMenu (details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);
		break;
		case 2:
			k=11;
			fflush(stdin);
			clrBox();
			box(20,5,100,22);
			//prompts all reservation
			gotoxy(38,7);printf("---------------------------------------------");
			gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,9);printf("---------------------------------------------");
			gotoxy(38,10);printf("         \033[1mNumber of Reservations : %d\033[0m", nReservation);
			gotoxy(38,11);printf("     NAME       ROOM TYPE         TIME");
			for(i=0;i<nReservation;i++){
			k++;
			gotoxy(38,k);printf("  %d. %s        %s     %s", i+1, details[i].firstname, reservation[i].roomtype, reservation[i].time);
			}
			gotoxy(38,20);printf("---------------------------------------------");
			gotoxy(38,21);printf("   \033[1mEnter the number to Edit Reservation:\033[0m");
			gotoxy(79,21);scanf("%d", &edit_choice);
			
			if (edit_choice>nReservation || edit_choice<=00)
			{
			clrBox();
		    red();
		    gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		    reset();
		    gotoxy(44,13);printf("Reservation does not exist");
		    gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
			gotoxy(80,14);scanf(" %c", &ch);
				
			if (ch == 'Y' || ch == 'y')
		    {   
		        clrBox();
		        fflush(stdin);
		        DisplayEditRRMainPage(details , reservation ,  nReservation, nBuilding, nRoom, chosenBuildingIndex);
		    }
		    else
		    {
				exit(0);
		    }	
			}
			
			EditRRMainPage(details, reservation, nReservation, edit_choice-1, nBuilding, nRoom, chosenBuildingIndex);
			//allow cancel reservation
		break;
		case 3: 
			k=11;
			fflush(stdin);
			clrBox();
			box(20,5,100,22);
			
			gotoxy(38,7);printf("---------------------------------------------");
			gotoxy(38,8);printf("              \033[1mROOM RESERVATION\033[0m");
			gotoxy(38,9);printf("---------------------------------------------");
			gotoxy(38,10);printf("         \033[1mNumber of Reservations : %d\033[0m", nReservation);
			gotoxy(38,11);printf("     NAME       ROOM TYPE         TIME");
			for(i=0;i<nReservation;i++){
			k++;
			gotoxy(38,k);printf("  %d. %s        %s     %s", i+1, details[i].firstname, reservation[i].roomtype, reservation[i].time);
			}
			gotoxy(38,20);printf("---------------------------------------------");
			gotoxy(38,21);printf("   \033[1mEnter the number to Cancel Reservation:\033[0m");				///GARMMARRRRRRR
			gotoxy(81,21);scanf("%d", &cancel_choice);
			
			if (cancel_choice>nReservation || cancel_choice<=0)
			{
			clrBox();
		    red();
		    gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
		    reset();
		    gotoxy(44,13);printf("Reservation does not exist");
		    gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
			gotoxy(80,14);scanf(" %c", &ch);
				
			if (ch == 'Y' || ch == 'y')
		    {   
		        clrBox();
		        fflush(stdin);
		        DisplayEditRRMainPage(details , reservation ,  nReservation, nBuilding, nRoom, chosenBuildingIndex);
		    }
		    else
		    {
				return;
		    }	
			}
				cancelReservation( details, reservation, nReservation, cancel_choice-1, nBuilding, nRoom, chosenBuildingIndex);
		break;
		default:
			clrBox();
  			red();
    		gotoxy(44,11);printf("\033[1mINVALID INPUT!\033[0m");
   			reset();
   			gotoxy(44,13);printf("Please enter correct input!");
   			gotoxy(44,14);printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
			gotoxy(68,14);scanf(" %c", &ch);
		
			if (ch == 'Y' || ch == 'y')
    		{   
	        	clrBox();
	       		fflush(stdin);
	        	DisplayEditRRMainPage(details , reservation ,  nReservation, nBuilding, nRoom, chosenBuildingIndex);
    		}
    		else
    		{
				return;
    		} 
		}
	}

}

/*
*	Function: retryMainPage	
*	Description: If any invalid inputs are committed, this allows the user to try again 
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/

void retryMainPage(struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex)
{
    char ch;

    clrBox();  // Clear the console display in a specified box area
    red();  // Set console text color to red
    gotoxy(44, 11); printf("\033[1mINVALID INPUT!\033[0m");  // Display error message for invalid input
    reset();  // Reset console text attributes to default
    gotoxy(44, 13); printf("Please enter correct input!");
    gotoxy(44, 14); printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
    gotoxy(80, 14); scanf(" %c", &ch);  // Read user input for retry choice

    if (ch == 'Y' || ch == 'y')
    {
        clrBox();  // Clear the console display in a specified box area
        fflush(stdin);  // Clear the input buffer
        displayCover(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);  // Retry displaying the cover page
    }
    else
    {
        return;  // Exit the program if the user chooses not to retry
    }
}

/*
*	Function: displayMainMenu	
*	Description: This contains the functions that is offered by the program
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/

void displayMainMenu(struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex)
{
    int choice;
    char ch;

    fflush(stdin);  // Clear the input buffer

    clrBox();  // Clear the console display in a specified box area

    // Display the main menu elements
    box(20, 5, 100, 22);
    gotoxy(38, 7); printf("---------------------------------------------");
    gotoxy(38, 8); printf("              \033[1mROOM RESERVATION\033[0m");
    gotoxy(38, 9); printf("---------------------------------------------");
    gotoxy(38, 10); printf("              \033[1mM A I N  M E N U\033[0m");
    gotoxy(38, 12); printf("        [1] Reserve a Room");
    gotoxy(38, 13); printf("        [2] View Room Reservations");
    gotoxy(38, 14); printf("        [3] Edit Room Reservations");
    gotoxy(38, 15); printf("        [4] Admin Module");
    gotoxy(38, 16); printf("        [5] Back");
    gotoxy(38, 18); printf("---------------------------------------------");
    gotoxy(38, 20); printf("            \033[1mEnter Choice [1-5]: \033[0m");
    fflush(stdin);
    gotoxy(70, 20); scanf("%d", &choice);  // Read user input for the menu choice

    switch (choice)
    {
    case 1:
        clrBox();  // Clear the console display in a specified box area
        fflush(stdin);  // Clear the input buffer
        roomreserve(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);  // Reserve a room
        break;
    case 2:
        clrBox();  // Clear the console display in a specified box area
        fflush(stdin);  // Clear the input buffer
        ViewRR(details, reservation, nReservation, nBuilding, nRoom,chosenBuildingIndex);  // View room reservations
        break;
    case 3:
        clrBox();  // Clear the console display in a specified box area
        fflush(stdin);  // Clear the input buffer
        DisplayEditRRMainPage(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);  // Edit room reservations
        break;
    case 4:
        clrBox();  // Clear the console display in a specified box area
        fflush(stdin);  // Clear the input buffer
        adminModule(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);  // Access the admin module
        break;
    case 5:
        clrBox();  // Clear the console display in a specified box area
        fflush(stdin);  // Clear the input buffer
        displayMainPage(details, reservation, nReservation, nBuilding, nRoom,chosenBuildingIndex);  // Go back to the main page
        break;
    default:
        clrBox();  // Clear the console display in a specified box area
        red();  // Set console text color to red
        gotoxy(44, 11); printf("\033[1mINVALID INPUT!\033[0m");  // Display error message for invalid input
        reset();  // Reset console text attributes to default
        gotoxy(44, 13); printf("Please enter correct input!");
        gotoxy(44, 14); printf("Would you like to try again? \033[1m[\033[32my\033[0m/\033[31mn\033[0m]: ");
        gotoxy(80, 14); scanf(" %c", &ch);

        if (ch == 'Y' || ch == 'y')
        {
            clrBox();  // Clear the console display in a specified box area
            fflush(stdin);  // Clear the input buffer
            displayMainMenu(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);  // Retry main menu choice
        }
        else
        {
            exit(0);  // Exit the program if the user chooses not to retry
        }
        break;
    }
}

/*
*	Function: displayMainPage	
*	Description: Prompts Cover Page containing Infos about the Reservation Program
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/

void displayMainPage(struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex)
{
    char ch;

    fflush(stdin);  // Clear the input buffer

    clrBox();  // Clear the console display in a specified box area

    // Display the main page elements (Important Reminders for User)
    box(20, 5, 100, 22);
    gotoxy(38, 6); printf("---------------------------------------------");
    gotoxy(38, 7); printf("              \033[1mROOM RESERVATION\033[0m");
    gotoxy(38, 8); printf("---------------------------------------------");
    gotoxy(23, 10); printf("          \033[1mTYPE OF ROOMS OFFERED:\033[0m");
    gotoxy(23, 11); printf("          - Classroom");
    gotoxy(23, 12); printf("          - Seminar Room");
    gotoxy(23, 13); printf("          - Auditorium (Exclusively in Don Enrique T. Yuchengco Hall)");
    gotoxy(23, 14); printf("          - Training Room");
    gotoxy(23, 16); printf("               NOTE: Each Room has \033[1m40\033[0m capacity");
    gotoxy(23, 17); printf("               NOTE: Each person has a max of 3 Reservations");

    gotoxy(38, 19); printf("  \033[1mWould you like to reserve a room? \033[1m[\033[32my\033[0m/\033[31mn\033[0m] : \033[0m");
    gotoxy(82, 19); scanf(" %c", &ch);  // Read user input for room reservation

    if (ch == 'y' || ch == 'Y')
    {
        clrBox();  // Clear the console display in a specified box area
        fflush(stdin);  // Clear the input buffer
        displayMainMenu(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);  // Show the main menu for room reservation
    }
    else if (ch == 'n' || ch == 'N')
    {
        clrBox();  // Clear the console display in a specified box area
        fflush(stdin);  // Clear the input buffer
        displayCover(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);  // Show the cover page again
    }
    else
    {
        clrBox();  // Clear the console display in a specified box area
        fflush(stdin);  // Clear the input buffer
        retryMainPage(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);  // Allow the user to retry entering 'y' or 'n'
    }
}

/*
*	Function: displayCover	
*	Description: Prompts Cover Page of the program and serves as an intoduction or welcome for the program
*	Parameters : @param : struct PersonalDetails details[] - allows the storing of data and manipulation of data for personal details of User
*				 @param : struct ReservationInfo reservation[] - allows the storing of data and manipulatoion of data for reservation details of user
*				 @param : int nReservation - number of reservation exisits within the program
* 				 @param : int nBuilding - number of Buildings exists within the program
*				 @param : int nRoom - number of rooms exists within buildings
*				 @param : int chosenBuildingIndex - used in files to store rooms in specific buildings
*/

void displayCover(struct PersonalDetails details[], struct ReservationInfo reservation[], int nReservation, int nBuilding, int nRoom, int chosenBuildingIndex)
{
    char ch;

    fflush(stdin);  // Clear the input buffer

    clrBox();  // Clear the console display in a specified box area

    // Display the cover page elements
    box(20, 5, 100, 22);
    gotoxy(38, 8); printf("---------------------------------------------");
    gotoxy(38, 10); printf("                 WELCOME!\n");
    reset();  // Reset console text attributes to default
    gotoxy(38, 12); printf("          ROOM RESERVATION FOR\n");
    green();  // Set console text color to green
    gotoxy(38, 13); printf("       \033[1mCOLLEGE OF COMPUTER STUDIES\033[0m");
    reset();  // Reset console text attributes to default
    gotoxy(38, 15); printf("---------------------------------------------");
    gotoxy(38, 18); printf("    \033[1mPress [N] to Proceed to Menu Page : \033[0m");

    gotoxy(78, 18); scanf("%c", &ch);  // Read user input for proceeding to the main menu

    // Loop until the user enters 'N' or 'n' to proceed to the main menu
    do
    {
        if (ch == 'n' || ch == 'N')
        {
            clrBox();  // Clear the console display in a specified box area
            fflush(stdin);  // Clear the input buffer
            displayMainPage(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);  // Show the main menu
        }
        else
        {
            clrBox();  // Clear the console display in a specified box area
            fflush(stdin);  // Clear the input buffer
            retryMainPage(details, reservation, nReservation, nBuilding, nRoom,chosenBuildingIndex);  // Allow the user to retry entering 'N'
        }
    } while (ch != 'n' && ch != 'N');
}

/*
*	Function: main()	
*	Description: Main Function of the Program
*	
*	return 0 - End of Program;
*/

int main()
{
    int nReservation;           // Number of reservations loaded
    int nBuilding = 0;              // Number of buildings loaded
    int nRoom = 0;              // Number of rooms (initialized to 0)
    int chosenBuildingIndex = -1; // Index of the chosen building (initialized to -1)

    // Pointers to structures for storing personal details and reservation information
    struct PersonalDetails *details;
    struct ReservationInfo *reservation;

    // Allocate memory for arrays to store details and reservation information
    details = malloc(100 * sizeof(struct PersonalDetails));
    reservation = malloc(100 * sizeof(struct ReservationInfo));

    // Load reservation data from a function and store the number of reservations loaded
    nReservation = load( details,reservation, nBuilding, nRoom, chosenBuildingIndex);
	
    // Load building data from a function and store the number of buildings loaded
    nBuilding = loadBuilding(details,  reservation, nReservation, nRoom, chosenBuildingIndex);

    // Display the cover using the loaded data
    displayCover(details, reservation, nReservation, nBuilding, nRoom, chosenBuildingIndex);

    // Free the dynamically allocated memory to prevent memory leaks
    free(details);
    free(reservation);

    return 0;
}


