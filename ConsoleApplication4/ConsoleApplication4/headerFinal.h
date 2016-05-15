#ifndef HEADERFINAL_H_INCLUDED
#define HEADERFINAL_H_INCLUDED
typedef struct input
{
	char code1[20];
	char color1[20];
	char mark1[20];
	double price1;
}carIN;

typedef struct car
{
	char code[20];
	char color[20];
	char mark[20];
	double price;
	struct car *pointer;
}carMEMORY;

int menu();
carMEMORY *FILEinsertLAST(carMEMORY **head, carIN info);
carMEMORY *last(carMEMORY **head);
carMEMORY *ADDinLAST(carMEMORY **head);
void readFILE(carMEMORY **head);
void removeCAR(carMEMORY **head);
carMEMORY *PRINTcarSEARCH(carMEMORY **head,  char TEMPcolor2[20]);
void PRICEcar(carMEMORY **head, char TEMPmark1[20]);
void writeFILE(carMEMORY **head);
void MEMORYfree(carMEMORY **head);
void colorINPUT(char Tcolor[20]);
void markINPUT(char Tmark[20]);




#endif // HEADERFINAL_H_INCLUDED
