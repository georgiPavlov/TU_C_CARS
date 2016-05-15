#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headerFinal.h"



int main()
{
	int key;
	carMEMORY *head = NULL;
	readFILE(&head);
	
	
	do
	{
		key = menu();
		switch (key)
		{
		case 1:
		{
			ADDinLAST(&head);
			break;
		}
		case 2:
		{
			char TEMPcolor[20];
			colorINPUT(TEMPcolor);
			PRINTcarSEARCH(&head,  TEMPcolor);
			break;
		}
		case 3:
		{
			removeCAR(&head);
			break;
		}
		case 4:
		{
			char TEMPmark[20];
			markINPUT(TEMPmark);
			PRICEcar(&head, TEMPmark);
			break;
		}
		case 5:
		{
			writeFILE(&head);
			MEMORYfree(&head);
			printf("\n\n           _-_-Goodbye!-_-_\n\n");
			break;
		}
		}
	} while (key != 5);
	return 0;
}

int menu()
{
	int result;
	printf("                         MENU         \n");
	printf("ENTER 1 to add new cars\n");
	printf("ENTER 2 to view the cars in the list by color \n");
	printf("ENTER 3 to delete car from the list by ID \n");
	printf("ENTER 4 to 10 percent off by mark\n");
	printf("ENTER 5 to EXIT\n");
	scanf("%d", &result);
	return result;
}


carMEMORY *ADDinLAST(carMEMORY **head)
{

	int n, i = 0;

	printf("Enter how many cars you want to enter\n");
	scanf("%d", &n);
	for (i = 0;i<n;i++)
	{
		carMEMORY *temp = (carMEMORY*)malloc(sizeof(carMEMORY));
		carMEMORY *lastp;
		if (temp == NULL)
			printf("Allocation ERROR \n");

		printf("\n");
		printf("Enter ID: ");
		scanf("%s", temp->code);
		fflush(stdin);
		printf("Enter color: ");
		fflush(stdin);
		scanf("%s", temp->color);
		fflush(stdin);
		printf("Enter mark: ");
		scanf("%s", temp->mark);
		fflush(stdin);
		printf("Enter price: ");
		scanf("%lf", &(temp->price));
		fflush(stdin);
		printf("\n");

		if (*head == NULL)
		{
			*head = temp;

			temp->pointer = NULL;
		}
		else
		{
			lastp = last(head);
			lastp->pointer = temp;
			temp->pointer = NULL;
		}
	}
	return *head;
}

carMEMORY *last(carMEMORY **head)
{
	carMEMORY *temp;

	for (temp = *head;temp->pointer != NULL;temp = temp->pointer)
		;

	return temp;
}

void readFILE(carMEMORY **head)
{
	carIN infoTEMP;
	FILE *fp;
	fp = fopen("carAuto.txt", "rb");
	if (fp != NULL)
	{
		for (;!feof(fp);)
		{
			fread(infoTEMP.code1, sizeof(char) * 20, 1, fp);
			fread(infoTEMP.color1, sizeof(char) * 20, 1, fp);
			fread(infoTEMP.mark1, sizeof(char) * 20, 1, fp);
			fread(&(infoTEMP.price1), sizeof(double), 1, fp);
			FILEinsertLAST(head, infoTEMP);
		}
	}
	if (*head != NULL)
	{
		*head = (*head)->pointer;
	}
	//fclose(fp);

}

carMEMORY *FILEinsertLAST(carMEMORY **head, carIN info)
{
	carMEMORY *temp1 = (carMEMORY*)malloc(sizeof(carMEMORY));
	carMEMORY *lastp1;
	if (temp1 == NULL)
		printf("Allocation ERROR \n");
	strcpy(temp1->code, info.code1);
	strcpy(temp1->color, info.color1);
	strcpy(temp1->mark, info.mark1);
	temp1->price = info.price1;
	if (*head == NULL)
	{
		*head = temp1;
		temp1->pointer = NULL;
	}
	else
	{
		lastp1 = last(head);
		lastp1->pointer = temp1;
		temp1->pointer = NULL;
	}

	return *head;
}

void removeCAR(carMEMORY **head)
{
	int g = 0, nn;
	char buffer[20];
	carMEMORY *temp3 = *head;
	carMEMORY *p;

	if (*head != NULL)
	{
		printf("How many cars you want to remove: \n");
		scanf("%d", &nn);
		for (g = 0;g<nn; g++)
		{
			printf("Enter car ID: \n");
			scanf("%s", buffer);

			do
			{
				if (!strcmp(buffer, temp3->code))
				{

					if (temp3 == *head)
					{

						if ((*head)->pointer != NULL)
						{
							*head = (*head)->pointer;
							free(temp3);
							printf("list deleted \n");
							break;
						}
						else
						{
							*head = NULL;
							free(temp3);
							printf("list deleted \n");
							break;
						}

					}

					else if (temp3->pointer == NULL)
					{
						p->pointer = NULL;
						free(temp3);
						temp3 = *head;
						printf("list deleted \n");
						break;
					}

					else
					{
						p->pointer = temp3->pointer;
						free(temp3);
						temp3 = *head;
						printf("list deleted \n");
						break;
					}


				}
				if (temp3->pointer == NULL)
					printf("NO CAR WITH THAT ID \n");

				p = temp3;
				temp3 = temp3->pointer;



			} while (temp3 != NULL);
			buffer[0] = '\0';

		}

	}
	else
		printf("LIST EMPTY \n");

}

void colorINPUT(char Tcolor[20])
{
	printf("Enter car color  \n");
	scanf("%s", Tcolor);

}

void markINPUT(char Tmark[20])
{
	printf("Enter car mark  \n");
	scanf("%s", Tmark);

}

carMEMORY *PRINTcarSEARCH(carMEMORY **head, char TEMPcolor2[20])
{
	carMEMORY *temp3;

	int true = 0;
	if (*head != NULL)
	{

		for (temp3 = *head;temp3 != NULL;temp3 = temp3->pointer)
		{

			if (!strcmp(TEMPcolor2, temp3->color ))
			{
				
					printf(" %s  %s  %s  %.2lf \n\n", temp3->code, temp3->color,  temp3->mark, temp3->price);
					true = 1;
				
			}

		}
		if (true == 0)
		{
			printf("There is not such a car with that mark! \n ");
		}
	}
	else
		printf("list in empty!");
	return NULL;
}

void PRICEcar(carMEMORY **head, char TEMPmark1[20])
{
	carMEMORY *temp4;
	int true = 0;
	double tempOffPrice = 0;
	

	if (*head != NULL)
	{
		for (temp4 = *head;temp4 != NULL;temp4 = temp4->pointer)
		{
			if (!strcmp(TEMPmark1, temp4->mark))
			{
				tempOffPrice = temp4->price / 10;
				temp4->price = temp4->price - tempOffPrice;
				true = 1;
			}

		}
		if (true == 0)
		{
			printf("There is not such a car with that mark! \n ");
		}
	}
	else
		printf("list in empty!");
	printf("\n");
	
}

void writeFILE(carMEMORY **head)
{
	FILE *fp1;
	fp1 = fopen("carAuto.txt", "wb");
	carMEMORY *temp4;
	if (*head != NULL)
	{
		for (temp4 = *head;temp4 != NULL;temp4 = temp4->pointer)
		{

			fwrite(temp4->code, sizeof(char) * 20, 1, fp1);
			fwrite(temp4->color, sizeof(char) * 20, 1, fp1);
			fwrite(temp4->mark, sizeof(char) * 20, 1, fp1);
			fwrite(&(temp4->price), sizeof(double), 1, fp1);

		}
		fclose(fp1);
		printf("list saved!! \n\n");
	}
	else
		printf("Error with the list \n");
}


void MEMORYfree(carMEMORY **head)
{
	carMEMORY *temp7 = NULL;
	for (;temp7 != NULL; temp7 = *head)
	{
		*head = temp7->pointer;
		free(temp7);
	}
	*head = NULL;
}
