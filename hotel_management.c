#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define BUFFER_SIZE 1000

/* Function declarations */
int indexOf(FILE *fptr, const char *word, int *line);
void Date();
void Booking();
void Room_Info();
void Payment();
void Record();
void randomPasswordGeneration();
char password[5];

void homepage()
{
	while (1) //infinite loop
	{
		int i = 0;
		char choice;
		system("cls");
		for (i = 0; i < 80; i++)
			printf("-");
		printf("\n");
		printf("\t\t   ****  |MAIN MENU|  ***** \n");
		for (i = 0; i < 80; i++)
			printf("-");
		printf("\n");
		printf("\t\t Please enter your choice for menu:");
		printf("\n\n");
		printf("\n------------------------");
		printf(" \n Enter 1 -> Hotel Room_info");
		printf("\n----------------------------------");
		printf(" \n Enter 2 -> Book a Room");
		printf("\n-----------------------------------");
		printf(" \n Enter 3 -> View your Booked Record");
		printf("\n-----------------------");
		printf(" \n Enter 4 -> Exit");
		printf("\n-----------------");
		printf("\n");
		for (i = 0; i < 80; i++)
			printf("-");
		printf("\n");
		choice = getche();
		switch (choice) // SWITCH STATEMENT WITH CHOICE
		{
		case '1':
			Room_Info();
			break;
		case '2':
			Booking();
			break;
		case '3':
			Record();
			break;
		case '4':
			system("cls");
			printf("\n\n\t *THANK YOU*");
			printf("\n\t FOR TRUSTING OUR SERVICE\n");
			exit(0);
			break;
		default:
			system("cls");
			printf("Incorrect Input");
			printf("\n Press any key to continue");
			getch();
		}
	}
}

struct Room_Service
{
	char swimming_pool;
	char pets;
	char gym;
	char hospitality;
	char spa;
	char indoor_games;
};

struct CustomerDetails
{
	char roomnumber[4];
	char name[20];
	char address[25];
	char phonenumber[15];
	char nationality[15];
	char email[20];
	int period;
	char arrivaldate[10];
	int countofpersons;
	int veg;
	int non_veg;
	struct Room_Service R;
} s;

struct Payment
{
	int room;
	int swimmingpool;
	int pets;
	int gym;
	int hospitality;
	int spa;
	int indoor_games;
	int veg;
	int non_veg;
	int total;
} cash;

void Restaurant();

int main()  //	main function
{
	int i = 0;
	char choice;
	system("cls"); // FOR CLEARING SCREEN
	printf("\t\t*******\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*           WELCOME TO Taj Athulya              *\n");
	printf("\t\t*       -----------------------------           *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*                                               *\n");
	printf("\t\t*        OUR ADRESS:-Taj Athulya , Four star    *\n");
	printf("\t\t*        ADRESS:23-24, Taj East Gate Rd,        *\n");
	printf("\t\t*        Taj Nagari Phase 1, Near Shilpgram,    *\n");
	printf("\t\t*        Telipara,Tajganj, Agra,Uttar Pradesh   *\n");
	printf("\t\t*               282001, India                   *\n");
	printf("\t\t*     CONTACT US:18-87454575552,035455852       *\n");
	printf("\t\t*******\n\n\n");
	Date();
	printf(" \n Press any key to continue: \n");
	getch();
	system("cls");
	homepage();
	system("cls");

	return 0;
}

void Date()
{
	time_t t;
	time(&t);
	for (int i = 0; i < 80; i++)
		printf("-");
	printf("\nCurrent date and time : %s", ctime(&t));
	for (int i = 0; i < 80; i++)
		printf("-");
}

void Booking()
{
	FILE *f;
	int room;
	char test;
	f = fopen("add.txt", "a+");
	if (f == 0)
	{
		f = fopen("add.txt", "w+");
		system("cls");
		printf("Please hold on while we set our database in your computer!! \n");
		printf("\n Process completed press any key to continue!! \n");
		getch();
	}
	while (1)	//infinite loop
	{
		system("cls");
		printf("\t\t\t Enter Customer Details:");
		printf("\n****\n");
		printf("Enter Name:\n");
		gets(s.name);
		printf("Enter Address:\n");
		scanf("%[^\n]", s.address);
		printf("Enter Phone Number:\n");
		scanf("%s", s.phonenumber);
		printf("Enter Nationality:\n");
		scanf("%s", s.nationality);
		printf("Enter Email:\n");
		scanf(" %s", s.email);
		printf("Enter Period(\'x\'days):\n");
		scanf("%d",&s.period);
		person:
		printf("Enter less than 5 persons \n");
		printf("Enter the number of persons for the stay in the hotel: \n");
		scanf("%d", &s.countofpersons);
		if (s.countofpersons > 4)
		{
			goto person;
		}
		printf("Enter Arrival date(dd\\mm\\yyyy):\n");
		scanf("%s",s.arrivaldate);
		printf("\n");
		printf("Choose the Room that you want:\n");
		printf("\t\t\t\t  Types-of-Rooms     No.of Rooms   Cost/day \n");
		printf("\t\t\t\t ****************\n");
		printf("\t\t\t\t  Suite-room       \t   2 \t   $400/day\n");
		printf("\t\t\t\t  Deluxe-Rooms     \t   3 \t   $320/day\n");
		printf("\t\t\t\t  Semi-Deluxe-room \t   5 \t   $260/day\n");
		printf("\t\t\t\t  Normal-Room      \t   8 \t   $100/day\n\n\n\n");
		printf("\n");
		printf("\t\t\t\t  Room-numbers                              Types-of-Rooms \n");
		printf("\t\t\t\t ********************\n");
		printf("\t\t\t\t   101, 201                                 Suite Rooms\n");
		printf("\t\t\t\t   102, 202, 302                            Deluxe Rooms\n");
		printf("\t\t\t\t   103, 203, 303, 403, 405                  Semi-Deluxe Rooms\n");
		printf("\t\t\t\t   104, 204, 301, 304, 305, 401, 402, 404   Normal Rooms\n");
		//opening file of rooms
		FILE *fptr;

		char word[3];

		int line;

	SearchRoom:
		/* Input word to search in file */
		printf("Enter the Room to be searched: \n");
		scanf("%s", word);

		/* Try to open file */
		fptr = fopen("rooms.txt", "r");

		/* Exit if file not opened successfully */
		if (fptr == NULL)
		{
			printf("Unable to open file.\n");
			printf("Please check you have read/write previleges.\n");

			exit(1);
		}

		// Find index of word in fptr
		indexOf(fptr, word, &line);
		

		if (line != -1)
		{
			indexOf(f, word, &line);
			if (line == -1) {
			printf("'%s' room is Available\n", word);
			strcpy(s.roomnumber, word);
			} else
		{
			printf("'%s' room is not Available\n", word);
			goto SearchRoom;
		}
		}
		else
		{
			printf("'%s' room is not Available\n", word);
			goto SearchRoom;
		}
		// Close file
		fclose(fptr);
		if(strcmp(s.roomnumber,"101")==0 || strcmp(s.roomnumber,"201")==0)
		{
			cash.room=400;
		}else if(strcmp(s.roomnumber,"102")==0 || strcmp(s.roomnumber,"202")==0 || strcmp(s.roomnumber,"302")==0){
			cash.room=320;
		}else if(strcmp(s.roomnumber,"103")==0 || strcmp(s.roomnumber,"203")==0 || strcmp(s.roomnumber,"303")==0 || strcmp(s.roomnumber,"403")==0 || strcmp(s.roomnumber,"405")==0){
			cash.room=260;
		}else if(strcmp(s.roomnumber,"104")==0 || strcmp(s.roomnumber,"204")==0 || strcmp(s.roomnumber,"301")==0 || strcmp(s.roomnumber,"304")==0 || strcmp(s.roomnumber,"305")==0 || strcmp(s.roomnumber,"401")==0 || strcmp(s.roomnumber,"402")==0 || strcmp(s.roomnumber,"404")==0){
			cash.room=100;
		}
		printf("\t\t\t Facilities\n");
		printf("Enter 'Y' if you want a particular facility, if not press any key.\n");
		printf("Swimming pool:\t");
		scanf(" %c", &s.R.swimming_pool);
		if(s.R.swimming_pool=='Y' || s.R.swimming_pool=='y'){
			cash.swimmingpool=10;
		}else{
			cash.swimmingpool=0;
		}
		printf("pets:        \t");
		scanf(" %c", &s.R.pets);
		if(s.R.pets=='Y' || s.R.pets=='y'){
			cash.pets=2;
		}else{
			cash.pets=0;
		}
		printf("Gym:         \t");
		scanf(" %c", &s.R.gym);
		if(s.R.gym=='Y' || s.R.gym=='y'){
			cash.gym=2;
		}else{
			cash.gym=0;
		}
		printf("Hospitality: \t");
		scanf(" %c", &s.R.hospitality);
		if(s.R.hospitality=='Y' || s.R.hospitality=='y'){
			cash.hospitality=2;
		}else{
			cash.hospitality=0;
		}
		printf("Spa:         \t");
		scanf(" %c", &s.R.spa);
		if(s.R.spa=='Y' || s.R.spa=='y'){
			cash.spa=8;
		}else{
			cash.spa=0;
		}
		printf("Indoor Games:\t");
		scanf(" %c", &s.R.indoor_games);
		if(s.R.indoor_games=='Y' || s.R.indoor_games=='y'){
			cash.indoor_games=2;
		}else{
			cash.indoor_games=0;
		}
        Restaurant();
		fwrite(&s, sizeof(s), 1, f);
		fflush(stdin);
		printf("\n\n1 Room is successfully booked!!");
		printf("\n Press esc key to exit,  any other key to add another customer detail:");
		test = getche();
		if (test == 27)
			break;
	}
	fclose(f);
}

void Room_Info()
{
	char test;
	while (1)  //	infinite loop
	{
		system("cls");
		printf("\n\n\n\n\n");
		printf("\t\t\t\t\t\t Room-Information \n\n");
		printf("\t\t\t\t  Types-of-Rooms     No.of Rooms   Cost/day \n");
		printf("\t\t\t\t ****************\n");
		printf("\t\t\t\t  Suite-room       \t   2 \t   $400/day\n");
		printf("\t\t\t\t  Deluxe-Rooms     \t   3 \t   $320/day\n");
		printf("\t\t\t\t  Semi-Deluxe-room \t   5 \t   $260/day\n");
		printf("\t\t\t\t  Normal-Room      \t   8 \t   $100/day\n\n\n\n");
		printf("\t\t\t\t\t     Room-Facilities \n\n");
		printf("\t\t\t\t\t Facilities    \t   Cost/day \n");
		printf("\t\t\t\t\t***********\n");
		printf("\t\t\t\t\t Swimming-pool \t   $10/day\n");
		printf("\t\t\t\t\t pet           \t   $2/day\n");
		printf("\t\t\t\t\t gym           \t   $2/day\n");
		printf("\t\t\t\t\t hospitality   \t   $2/day\n");
		printf("\t\t\t\t\t spa           \t   $8/day \n");
		printf("\t\t\t\t\t indoor-games  \t   $2/day \n\n\n\n");
		printf("\t\t\t\t\t   Restaurant-Information \n\n");
		printf("\t\t\t\t\t Type          \t   Cost/day \n");
		printf("\t\t\t\t\t***********\n");
		printf("\t\t\t\t\t veg-food      \t   $10/day \n");
		printf("\t\t\t\t\t nonveg-food   \t   $15/day\n\n");
		printf("\t Press esc key to exit :\n");
		test = getche();
		if (test == 27)
			break;	//	infinite loop will break.
	}
}

void Restaurant()
{
	int food_type;
	s.veg=0;
	s.non_veg=0;
	char test;
	printf("\t\t\t Restaurant\n");
	printf("Enter the number '1' if the person wants to eat veg food.\n");
	printf("Enter the number '2' if the person wants to eat non-veg food.\n");
	printf("Enter the number '3' if the person is not interested in any type of food to eat.\n");
	for(int i=0;i<s.countofpersons;i++)
	{
	food:
		printf("Enter the type of food for person %d: \t",i+1);
		scanf("%d",&food_type);
		switch(food_type)
		{
		case 1:
			s.veg++;
			break;
		case 2:
            s.non_veg++;
			break;
		case 3:
		    break;
		default:
		    printf("Please enter the correct numbers shown above.\n");
			goto food;
		}
	}
	cash.veg=(s.veg)*10;
	cash.non_veg=(s.non_veg)*15;
		printf("\n Press esc key to payment, any other key for exit\n");
		test = getche();
		if (test == 27)
		Payment();
		else 
		exit(0);
}

void Payment()
{
	int c;
	int c1;
	int c2;
	int mon;
	int yr;
	char card_name[10];
	int card_no;
	int turn;
	char cvv[5];
	char inputOTP[5];
	start:
	turn=0;
	cash.total=(cash.room+cash.swimmingpool+cash.pets+cash.gym+cash.hospitality+cash.spa+cash.indoor_games+cash.veg+cash.non_veg)*(s.period);
    printf("\n Total payment till now is: %d \n",cash.total);
	printf("Please select your payment method: 1.net banking, 2.debit card\n");
	scanf("%d", &c);
	if (c == 1)
	{
		printf("Select the bank type to proceed the transaction: 1.SBI, 2.ICICI\n");
		scanf("%d", &c1);
		printf("Please enter your login details.\n");
		scanf("%d", &c2);
		logDetails:
		if(turn>4){
			printf("Sorry, you have entered the wrong OTP five times. Please try again the process from payment.\n");
			goto start;
		}
		printf("Please enter the OTP which has sent to your mobile.\n");
		randomPasswordGeneration();
		scanf("%s",inputOTP);
		if(strcmp(password,inputOTP) == 0)
		{
			printf("Your payment is successfull.\n");
		}else{
			turn++;
			goto logDetails;
		}
	} else if(c == 2){
		printf("Enter the card number: \n");
		scanf("%d",&card_no);
		printf("Enter the card name: \n");
		scanf("%s",card_name);
		printf("Please enter the expiry month and year of card respectively: \n");
		scanf("%d %d",&mon,&yr);
		printf("Please enter the CVV pin: \n");
		int i=0;
		while(i<5)
	{
	    cvv[i]=getch();
	    c=cvv[i];
	    if(c==13) break;
	    else printf("*");
	    i++;
	}
	cvv[i]='\0';
	
	card:
		if(turn>4){
			printf("Sorry, you have entered the wrong OTP five times. Please try again the process from payment.\n");
			goto start;
		}
		printf("\nPlease enter the OTP which has sent to your mobile.\n");
		randomPasswordGeneration();
		scanf("%s",inputOTP);
		if(strcmp(password,inputOTP) == 0)
		{
			printf("Your payment is successfull.\n");
		}else{
			turn++;
			goto card;
		}
	}
}

void Record()
{
	FILE *f;
	char test;
	char roomnumber[20];
	while (1)
	{
	int flag=1;
	system("cls");
	f=fopen("add.txt","r");
	if(f==0)
		exit(0);
	fflush(stdin);
	printf("Enter Room number of the customer: \n");
	scanf("%s", roomnumber);
	while(fread(&s,sizeof(s),1,f)==1)
	{
		if(strcmp(s.roomnumber,roomnumber)==0){
			flag=0;
			printf("\n\tRecord Found\n ");
			printf("\nRoom Number: \t%s",s.roomnumber);
			printf("\nName:        \t %s",s.name);
			printf("\nAddress:     \t%s",s.address);
			printf("\nPhone number:\t%s",s.phonenumber);
			printf("\nNationality: \t%s",s.nationality);
			printf("\nEmail:       \t%s",s.email);
			printf("\nPeriod:      \t%d",s.period);
			printf("\nArrival date:\t%s",s.arrivaldate);
			break;
		}
	}
	if(flag==1){	
		printf("\n\tRequested Customer could not be found!\n");
	}

	printf("\n\t Press esc key to exit,  any other key to find another Room detail:\n");
	test = getche();
	fclose(f);
	system("cls");
	if (test == 27)
			break;
	}
}

int indexOf(FILE *fptr, const char *word, int *line)
{
	char str[BUFFER_SIZE];
	char *pos;

	*line = -1;

	while ((fgets(str, BUFFER_SIZE, fptr)) != NULL)
	{

		// compare the room number in the file.
		pos = strstr(str, word);

		if (pos != NULL)
		{
			*line += 1;
			break;
		}
	}

	return 0;
}

//Generating the random OTP
void randomPasswordGeneration()
{

	// Send the random-number generator
	// with current time so that the
	// numbers will be different every time
	srand((unsigned int)(time(NULL)));

	// Array of numbers
	char numbers[] = "0123456789";

	// Stores the random password

	// Iterate over the range [0, N]
	for (int i = 0; i < 5; i++)
	{
		password[i] = numbers[rand() % 10];
		printf("%c", password[i]);
	}
	printf("\n");
}
