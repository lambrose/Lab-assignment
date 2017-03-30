// Lab assignment.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"
#include "stdlib.h"

struct date
{
	int day, month, year;
};

struct customer
{
	char name[50];
	int accountNumber;
	double balance;
	struct date lastTrans;
};

int getDay(int month);
int getMonth();
int getYear();
double getBalance();

void printCustomer(struct customer customerX);

int main()
{
	int i;
	char names[10][50] = { "Haiden Soto","Oscar Hernandez","Heath Hickman","Reagan Mcknight","Noah Bartlett","Ross Day","Maribel Livingston","Jewel Phillips","Blake Gardner","Fernanda Ponce" };

	struct customer customers[10];

	for (i = 0; i<10; i++)
	{
		strcpy(customers[i].name, names[i]);
		customers[i].accountNumber = 10000 + i;
		customers[i].balance = getBalance();
		customers[i].lastTrans.month = getMonth();
		customers[i].lastTrans.day = getDay(customers[i].lastTrans.month);
		customers[i].lastTrans.year = getYear();
	}

	printf("%25s\t%13s\t%12s\t%s\n\n", "Name", "Account Number", "Balance", "Date of Last Transaction");

	for (i = 0; i<10; i++)
	{
		printCustomer(customers[i]);
	}

	return 0;
}

int getDay(int month)
{
	int day, max = 31;

	if ((month == 9) || (month == 4) || (month == 6) || (month == 11)) max = 30;
	if (month == 2) max = 28;

	day = rand() % max + 1;

	return day;
}

int getMonth()
{
	int month;
	month = rand() % 12 + 1;
	return month;
}

int getYear()
{
	int year;
	year = rand() % 3 + 2013;
	return year;
}

double getBalance()
{
	double balance;
	balance = rand() % 10000 - 5000;
	return balance;
}

void printCustomer(struct customer customerX)
{

	printf("%25s\t%13d\t%12.2lf\t%d/%d/%d\n\n", customerX.name, customerX.accountNumber, customerX.balance, customerX.lastTrans.day, customerX.lastTrans.month, customerX.lastTrans.year);

	return;
}