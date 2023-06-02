/*************************************************************************************************
This is to certify that this project is my own work, based on our personal efforts in studying and
applying the concepts learned. We have constructed the functions and their respective algorithms
and corresponding code by myself. The program was run, tested, and debugged by my own efforts. We
further certify that we have not copied in part or whole or otherwise plagiarized the work of other
students and/or persons.
									Regner Atutubo, DLSU ID#121
								Mari Salvador S. Lapuz, DLSU ID#121
*************************************************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SYMPTOMS	20
#define MAX_IMPRESSIONS	20
#define MAX_CHAR		200

typedef char string[MAX_CHAR];			
typedef int inputSign[MAX_SYMPTOMS];


typedef struct{ 
	int num1;							// Number of Symptoms				
	string sign;						// Symptom Name
	string questions;					// Question for Symptoms
}Symptoms[MAX_SYMPTOMS];				//Structure for Symptoms


typedef struct{							//Structures for Impressions
	int num2;							// Number of Impressions
	string illness;						//Name of illness
	int numSign;						//Number of symptoms present in an illness
	int numSymp[MAX_SYMPTOMS];			//Number for corresponding symptoms present
}Impressions[MAX_IMPRESSIONS];

typedef struct{
	string name;						//Patient's Name
	int numPatient;						//Patient Number
	int age;							//Patient's Age
	string  gender;						//Patient's Gender
	string list;
}Patient;								// Structure for Patient

/*
	createSymptoms store the Symptoms and Necessary Questions needed for consulting the Patient
	The function also writes Symptoms.txt file 
	
	@param symptoms - contains the list of members in typedef structure Symptoms 
	
	Pre-condition - Maximum value for number of symptoms to consider is 20
*/
void createSymptoms(Symptoms symptoms){ 	
	int i;													// integer i for tracking iterations
	FILE *fp;							
	fp= fopen("Symptoms.txt", "w");							/* creates symptoms.txt file to display details
															 for the basis of input needed in createSymptoms*/
	printf("\nHow many symptoms do you want to consider? ");
	scanf("%d", &symptoms[0].num1);						//symptoms[].num1 stores number of symptoms
	fprintf(fp, "%d\n", symptoms[0].num1);					// writes number of symptoms to symptoms.txt
	
	if(symptoms[0].num1<=20)
	for(i = 0; i < symptoms[0].num1; i++){					//loop will stop if number of symptom is reached
				printf("\nSymptoms #%d\n", i+1);			// array of structures 0+1
				fprintf(fp, "%d\n", i+1);					// writes the numbering for symptoms to symptoms.txt
				printf("What is the symptoms? ");			
				scanf(" %[^\n]s",symptoms[i].sign);			//symptoms[].sign stores the name of symptoms
				fprintf(fp, "%s\n", symptoms[i].sign);		//writes the symptom name/s to symptoms.txt
				printf("How do you want to ask the symptom?\n");
				scanf(" %[^\n]s", symptoms[i].questions);										
				fprintf(fp, "%s\n",symptoms[i].questions);	// writes the necessary question/s to symptoms.txt
	}
	else
		printf("Invalid Input");							// Input is invalid if no. of symtpoms >=20
	
	fclose(fp);												//closes symptoms.txt
}
/*
	symptomsList display the list of symptoms 
	
	@param symptoms - contains the list of members in typedef structure Symptoms  
	
*/

void symptomsList(Symptoms symptoms){			
	int j;												
	
	for(j=0;j<symptoms[0].num1; j++){
			printf(" %d. %s\n", j+1, symptoms[j].sign);		//List down ALL symptoms name input from createSymptoms
	}
	}																					
												
/*
	createImpression store the Illness, Number of Possible Symptoms and their 
	corresponding number from the symptomsList needed for consulting the Patient
	The function also writes Impressions.txt file
	
	@param symptoms - contains the list of members in typedef structure Symptoms  
	@param impressions - contains the list of members in typedef structure Impressions  
	
	Pre-condition - Maximum value for number of impressions to consider is 20
*/												
										
void createImpressions(Symptoms symptoms, Impressions impressions){ // function for creating impressions
	int i,j;
	FILE *fp;
	fp = fopen("Impressions.txt", "w");						/* creates Impressions.txt file to display details
															 for the basis of input needed in createImpressions*/
	
	printf("\nHow many impressions do you want to enter? ");	
	scanf("%d", &impressions[0].num2);						//impressions[].num2 stores number of impressions
	fprintf(fp, "%d", impressions[0].num2);				// writes number of impressions to Impressions.txt
	
	if(impressions[0].num2<=20){
		for(i = 0; i < impressions[0].num2; i++){			//loop will stop if number of impression is reached
			printf("\nImpression # %d\n", i+1);
			
			fprintf(fp, "\n%d\n", i+1);						//writes the numbering for symptoms to impressions.txt
			printf("What is the Illness? ");				
			scanf(" %[^\n]s", impressions[i].illness);		//impressions[].illness stores the name of impressions
			fprintf(fp, "%s\n", impressions[i].illness);	// writes the possible illness name/s to Impressions.txt
			printf("Below is a list of symptoms.\n");		
				symptomsList(symptoms);						// calls symptomsList to display list of all symptoms
			printf("\n");
			
			printf("How many of the symptoms above are present in a %s case?", impressions[i].illness );
				scanf("%d", &impressions[i].numSign); 		/* impressions[].numSign stores the number of symptoms
																present in a possible illness*/
			printf("Enter the corresponding number of each symptom:\n");
				for(j=0;j<impressions[i].numSign;j++){
					scanf("%d", &impressions[i].numSymp[j]);		/*impressions[].numSymp[] stores corresponding 
																		symptom numbers from the list of symptoms*/
					fprintf(fp, "%d ", impressions[i].numSymp[j]); /*write coresponding number of symptoms of an 
																	illness to Impressions.txt*/	
			}
		}	
	}
	else 
		printf("Invalid Input");								// Input is invalid if no. of symtpoms >=20
		
	fclose(fp);													// closes Impressions.txt file
}
/*
	tokenize store each words in s to aWords, excluding the spaces as
	not part of any content in aWords.
	
	@param aWords is the destination that stores words in s (2d array)
	@param s is assumed to contain at least one word.
*/
void tokenize(string aWords[], string s)
{    
    int i, j = 0, nElem = 0;
    
    //if there is a leading spaces
    i = 0; 
    while (i < strlen(s) && (s[i] == ' '))
       i++;
       
   	//included the index where the '\0' is to include the last word
    for (; i <= strlen(s); i++)
       if (s[i] != ' ' && s[i] != '\0')
       {
          aWords[nElem][j] = s[i];
          j++;
       }
       else 
       {
           aWords[nElem][j] = '\0';
           j = 0;
           nElem++;
           
           //in case there are multiple spaces
           while (i < strlen(s) && (s[i] == ' '))
             i++;
           if (i < strlen(s) )
             i--;//to go back to the last space because the loop will increment i      
       }    
}
/*
	currentList is a function that reads input from an existing .txt file and copy its content 
	back to data structures
	
	@param *fp1 - is the FILE pointer which will hold the reference to the opened symptoms.txt file
	@param *fp2 - is the FILE pointer which will hold the reference to the opened Impressions.txt file
	@param symptoms - contains the list of members in typedef structure Symptoms 
	@param impressions - contains the list of members in typedef structure Impressions 
	
	Pre-condition - There is an existing file of symptoms and impressions created by the doctor
*/	
void currentList(FILE *fp1, FILE *fp2, Symptoms symptoms, Impressions impressions){
	string aWords[0];
	string buffer[0];
	string s;
	int i, j;							// variable for iterations
   	fp1 = fopen("Symptoms.txt", "r");	//opens and reads symptoms.txt file
 	fp2 = fopen("Impressions.txt", "r");	//opens and reads Impressions.txt file
 	
 	if(fp1!= NULL){							// as long as fp1 has data, it will continue copying data structures
 		fscanf(fp1, "%d", &symptoms[0].num1);
		for(i = 0; i < symptoms[0].num1; i++){
				fscanf(fp1, "%d\n", &i+1);
				fscanf(fp1, " %[^\n]s", symptoms[i].sign);
				fscanf(fp1, " %[^\n]s", symptoms[i].questions);
		}
		
		
		fclose(fp1);	// closes fp1 
		
	 }
	 
	if(fp2!= NULL){						// as long as fp2 has data, it will continue copying data structures
		fscanf(fp2, "%d\n", &impressions[0].num2);
		for(i = 0; i < impressions[0].num2; i++){
			fscanf(fp2, "\n%d\n", &i+1);
			fscanf(fp2, " %[^\n]s", impressions[i].illness);
			fscanf(fp2, " %[^\n]s", s);
		printf("%d\n %d\n %s\n", impressions[i].num2, i+1, impressions[i].illness);

		tokenize(aWords, s);	// stores each number in string form into array aWords

		impressions[i].numSymp[j] = atoi(aWords[i]); // converts string to integer

		}
		fclose(fp2); //closes fp2
		
	}
}

/*
	displaySymptoms is a function that displays the stored Illness and its list of symptoms
	
	@param symptoms - contains the list of members in typedef structure Symptoms
	@param impressions - contains the list of members in typedef structure Impressions
*/	

void displaySymptoms(Symptoms symptoms, Impressions impressions){
	int i, nAddress, nNum;								
	string tempImp;										    //tempImp is a temporary placeholder for Impressions
	
	printf("What is the Impression? ");
	scanf(" %[^\n]s", tempImp);							   // stores impression to tempImp
	for(i=0; i<impressions[0].num2; i++){	              //loop will stop once maximum number of impressions is reached
		if(strcmp(tempImp, impressions[i].illness)==0){  /*if tempImp matches input from impressions[].illness, 
															index of its array will be extracted as an integer*/
			nAddress = i;								 // nAddress holds the index of the array in integer form
		}
	}
	printf("Symptoms of a %s are:\n", tempImp);			
	for(i=0; i<impressions[nAddress].numSign; i++){		
		nNum = impressions[nAddress].numSymp[i];		    //impressions together with its corresponding symptom number
		printf("\t%s\n", symptoms[nNum-1].sign);			// Display list of symptoms depends on the input impressions
	}
}
/*
	modifySymptoms is a function that modifies the possible impressions together with its corresponding symptoms
	
	@param symptoms - contains the list of members in typedef structure Symptoms 
	@param impressions - contains the list of members in typedef structure Impressions 
*/	
	
void modifySymptoms(Symptoms symptoms, Impressions impressions){
	int i,j, nAddress, nNum;
	string tempImp;

	         									 /* creates Impressions.txt file to display modified details
												        									 for the basis of input needed in createImpressions*/
	
        									 //writes number of Impressions in impressions.txt file
	printf("What is the Impression? ");
	scanf(" %[^\n]s", tempImp);							
	for(i=0; i<impressions[0].num2; i++){							
		if(strcmp(tempImp, impressions[i].illness)==0){  
				nAddress = i;														// nAddress holds the index of the array in integer form
		}
	}
	printf("symptoms of a %s are:\n", tempImp);
	for(i=0; i<impressions[nAddress].numSign; i++){
		nNum = impressions[nAddress].numSymp[i];
		printf(" %s\n", symptoms[nNum-1].sign);
	}
	
	// above has same function as displaySymptoms
	
	printf("\nYou can modify the symptoms of %s\n", tempImp);
	printf("\nBelow is a list of symptoms.\n");
				symptomsList(symptoms);													//display list of symptoms
				

	
	printf("\n");
	printf( "How many of the symptoms above are present in a %s case? ", tempImp);
		scanf("%d", &impressions[nAddress].numSign); 									//stores new set 
		
		printf("Enter the corresponding number of each symptom:\n");
				for(i=0;i<impressions[nAddress].numSign;i++){
					scanf("%d", &impressions[nAddress].numSymp[i]);
		}

	printf("\nHere are the NEW symptoms of %s:\n", tempImp);
		for(i=0; i<impressions[nAddress].numSign; i++){								
			nNum = impressions[nAddress].numSymp[i];
			printf(" %s\n", symptoms[nNum-1].sign);								// Display list of NEW symptoms depends on the input impressions	
		}
		
	FILE *fp;
	fp = fopen("Impressions.txt", "w");											/* creates Impressions.txt file to display details
															 					for the basis of input needed in createImpressions*/		
																				
																				//impressions[].num2 stores number of impressions
	fprintf(fp, "%d", impressions[0].num2);										// writes number of impressions to Impressions.txt
	
	if(impressions[0].num2<=20){
		for(i = 0; i < impressions[0].num2; i++){								//loop will stop if number of impression is reached
			
			fprintf(fp, "\n%d\n", i+1);											//writes the numbering for symptoms to impressions.txt//impressions[].illness stores the name of impressions
			fprintf(fp, "%s\n", impressions[i].illness);						// writes the possible illness name/s to Impressions.txt
				for(j=0;j<impressions[i].numSign;j++){
					fprintf(fp, "%d ", impressions[i].numSymp[j]); 				//writes the NEW coresponding number of symptoms of an illness to Impressions.txt
			}
		}	
	}							
		
	fclose(fp);																	// closes Impressions.txt file
						
}

/*
	DetermineImpressions checks if the list of symptoms felt by the Patient matched the
	list of symptoms from impressions created by the Doctor
	
	@param impressions - contains the list of members in typedef structure Impressions 
	@param symptoms	   - contains the list of members in typedef structure Symptoms  
	@param n		   - contains number of symptoms
	@param list[]	   - contains the list of symptoms felt by the patient
*/

void DetermineImpressions(Impressions impressions, Symptoms symptoms, int n, string list[]){
	
	int i, j, k;
	string ImpList[MAX_IMPRESSIONS];
	int nMatch = 0, nCounter = 0;
	FILE *fp;
	
	for(i=0; i<impressions[0].num2; i++ ) {
		for(j=0; j<impressions[i].numSign; j++) {
			for(k=0;k<n;k++) {
				if(strcmp(list[k], symptoms[j].sign)==0){	
					nMatch++;								//nMatch increments when symptoms felt by patient matched the current list of symptoms
				}
			}
			if(nMatch==impressions[i].numSign){				// if nMatch matches the number of Symptoms present in doctor's list
				strcpy(ImpList[i], impressions[i].illness); // the matched illness will be stored in ImpList[]
				nCounter++;
			}				
		}
	}

	if(nCounter>1){
		printf("Impressions are ");
		fprintf(fp,"Impressions are ");
	}
	else{
		printf("Impression is ");
		fprintf(fp,"Impression is ");
	}
	
	for(i=0;i<nCounter;i++){															
		printf("%s", ImpList[i]);
		fprintf(fp, "%s", ImpList[i]);									
		if(i==nCounter-1){							//If the matched Impressions is at the end of the ImpList, it will append period 
			printf(". ");
			fprintf(fp, ". ");
		}
		else if(i==nCounter-2){						//If the matched Impressions is at the second to the last of the ImpList, it will insert "and"
			printf(" and ");
			fprintf(fp, " and ");
		}
		else{										//else, it will insert comma
			printf(", "   );						
			fprintf(fp, ", "   );
		}
	}
	
}

/*
	patientMenu displays the History of Present Illness and stores the necessary
	details in <PatientNumber>.txt file
	
	@param symptoms - typedef of structure Symptoms 
	@param patient - typedef of structure patient
	
*/

void patientMenu(Patient patient, Symptoms symptoms, Impressions impressions){

	int i, n=0;
	char cInput, cGender;
	string filename;
	string list[MAX_SYMPTOMS];
	FILE *fp;									
		
	
	printf("What is your name? ");
	scanf(" %[^\n]s", patient.name);			//patient.name stores the name of the patient
	printf("What is your Patient Number? ");	
	scanf("%d", &patient.numPatient);			//patient.numPatient stores the patient number	
	sprintf(filename, "%d", patient.numPatient); //stores integer output on string filename
	strcat(filename,".txt");					//appends .txt to create .txt file
	fp= fopen(filename, "w");					//writes the filename of patient by its patient number
							
	printf("Enter your age: ");
	scanf("%d", &patient.age);					//patient.age stores the age of the patient
	printf("Gender (M/F):");
	scanf(" %c", &cGender);						//cGender stores the gender of the patient
		if(cGender=='m'||cGender=='M')
		strcpy(patient.gender , "male");		//patient.gender is based on M and F 
		
		else if(cGender=='f'||cGender=='F')
		strcpy(patient.gender, "female");
	
	for(i=0;i<symptoms[0].num1; i++){
		printf(" %s\t", symptoms[i].questions);	//displays the list of questions
		scanf(" %c", &cInput);
		
		if(cInput=='Y'||cInput=='y'){
			strcpy(list[i], symptoms[i].sign);		//If Y copy all the symptoms felt by patient
			n++;
		}
		else if (cInput=='N'||cInput=='n'){
		}
	}
	
	printf("\n History of Present Illness\n\n");	
	fprintf(fp, "\n History of Present Illness\n\n");
	printf(" %s, ", patient.name);								// prints patient's name
	fprintf(fp, " %s, ", patient.name);							
	printf("patient # %d ", patient.numPatient);				//prints patient's number
	fprintf(fp, "patient # %d ", patient.numPatient);
	printf("is a %d-year old %s. ",patient.age,patient.gender);		//prints patient's age and gender
	fprintf(fp, "is a %d-year old %s. ",patient.age, patient.gender);
	
	if(strcmp(patient.gender, "male")==0){						
		printf("He has ");										// identifies patient's pronouns
		fprintf(fp, "He has ");
	}
	else if(strcmp(patient.gender, "female")==0){
		printf("She has ");
		fprintf(fp, "She has ");
	}
	for(i=0;i<n;i++){												
		printf("%s", list[i]);									//If the felt symptom of the patient is at the end of the ImpList, it will append period 
		fprintf(fp,"%s", list[i]);								
		if(i==n-1){												
			printf(". ");
			fprintf(fp, ". ");
		}
		else if(i==n-2){
			printf(" and ");
			fprintf(fp, " and ");								//If the felt symptom of the patient is at the end of the ImpList, it will insert "and"
		}
		else{													//else, it will insert comma
			printf(", ");
			fprintf(fp,", ");
		}
	}
	
	DetermineImpressions(impressions, symptoms, n, list);
	fclose(fp);													// closes the filename file
}
/*
	main () function is responsible for the looping of the menu interface 
*/	
	
int main(){
FILE *fp1, *fp2;																	//FILE pointers
int temp;																			// temporary placeholder
char cInput;																		//cInput gets the input of the choices
Symptoms symptoms;																	//typedef of structure Symptoms 
Impressions impressions;															//typedef of structure Impressions 
Patient patient;																	//typedef of structure Patient 

while(temp != -1){																	//Loop will end if the value returned is zero
	printf("\nMENU # 1 User Type\nD for Doctor\nP for Patient\nE for Exit\n");
	printf("\nEnter your choice: ");
	scanf(" %c", &cInput);
	
	if(cInput== 'D' || cInput=='d'){											// Proceeds to Doctor's Menu
		printf("\nMENU # 2 Doctor\n");
	printf("C to Create a new list of symptoms and impressions\n");
	printf("U to Use the existing list of symptoms and impresions\n");
	printf("D to Display Symptoms\n");
	printf("M to Modify Symptoms\n");
	printf("E to Exit\n");

	printf("\nEnter your choice: ");
	scanf(" %c", &cInput);
	
		if(cInput== 'C' || cInput=='c'){										//Creates new list of symptoms and impressions
			createSymptoms(symptoms);
			createImpressions(symptoms, impressions);
		}
		else if(cInput== 'U' || cInput=='u'){									//Uses the existing list of symptoms and impresions
			currentList(fp1, fp2, symptoms, impressions);
		}
		else if(cInput== 'D' || cInput=='d'){									//Display Symptoms
			displaySymptoms(symptoms,impressions);
		}
		else if(cInput== 'M' || cInput=='m'){									//Modify Symptoms
			modifySymptoms(symptoms,impressions);
		}
		}
	else if(cInput== 'P' || cInput=='p')										// Proceeds to Patient's Details and Possible Impressions
		patientMenu(patient, symptoms, impressions);
	else if(cInput== 'E' || cInput=='e')										//Ends the program
		return 0;
	
		
	}
}

