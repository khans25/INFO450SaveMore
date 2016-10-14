// INFO450SaveMore.cpp : Define the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <stdio.h>
using namespace std;

class Account
{
protected:
	int accountid;
	double interest;
	double balance;
public:
	Account()
	{
		balance = 0;
	}
	virtual void display() = 0;
	virtual void get_info() = 0;
	virtual void deposit() = 0;
	virtual void withdraw() = 0;
};

//Add 3 Classes; Savings, Checking, and Certificate of Deposit

class Savings : public Account
{
public:
	void display()
	{
		printf("Account ID: %d\n Interest Rate: %d\n Balance: %d\n", accountid, interest, balance);
	}
	void get_info()
	{
		cout << "Insert Account #: ";
		cin >> accountid;
		cout << "Insert Interest Rate: ";
		cin >> interest;
		cout << "Insert Balance: $";
		cin >> balance;
	}
	void deposit(double amount)
	{
		if (amount <= 0)
		{
			throw "Not valid ammount";
		}
		else if (amount > 0)
		{
			balance += amount;
		}
	}
	void withdraw(double amount)
	{
		if (amount <= 0)
		{
			throw "Not valid amount";
		}
		else if (amount > balance)
		{
			throw "Too much money withdrawn";
		}
		else if (amount + 2 <= balance)
		{
			balance -= amount;
			balance -= 2;
		}
	}
};

class Checking : public Account
{
public:
	void display()
	{
		printf("Account ID: %d\n Interest Rate: %d\n Balance: %d\n", accountid, interest, balance);
	}
	void get_info()
	{
		cout << "Insert Account ID: ";
		cin >> accountid;
		cout << "Insert Interest Rate: ";
		cin >> interest;
		cout << "Insert Balance: $";
		cin >> balance;
	}
	void deposit(double amount)
	{
		if (amount <= 0)
		{
			throw "Not valid ammount";
		}
		else if (amount > 0)
		{
			balance += amount;
		}
	}
	void withdraw(double amount)
	{
		if (amount <= 0)
		{
			throw "Not valid amount";
		}
		else if (amount > balance)
		{
			throw "Too much money withdrawn";
		}
		else if (amount <= balance)
		{
			balance -= amount;
		}
	}
};

class CD : public Account
{
public:
	void display()
	{
		printf("Account ID: %d\n Interest Rate: %d\n Balance: %d\n", accountid, interest, balance);
	}
	void get_info()
	{
		cout << "Insert Account ID: ";
		cin >> accountid;
		cout << "Insert Interest Rate: ";
		cin >> interest;
		cout << "Insert Balance: $";
		cin >> balance;
	}
	void deposit(double amount)
	{
		if (amount <= 0)
		{
			throw "Not valid ammount";
		}
		else if (amount > 0)
		{
			balance += amount;
		}
	}
	void withdraw(double amount)
	{
		if (amount <= 0)
		{
			throw "Not valid amount";
		}
		else if (amount > balance)
		{
			throw "Too much money withdrawn";
		}
		else if (amount <= balance)
		{
			balance -= amount;
		}
	}
};

int main()
{
	Account **bptr;
	int numberAcc = 0;
	char answer[4];

	cout << "How many accounts? ";
	cin >> numberAcc;
	cin.clear();
	cin.ignore();

	bptr = new Account *[numberAcc];
	for (int i = 0; i < numberAcc; i++)
	{
		cout << "Savings = S, Checking = C, Certified Deposit = CD: ";
		gets_s(answer);
		if (strcmp(answer, "S") == 0)
		{
			bptr[i] = new Savings();
			bptr[i]->get_info();
			bptr[i]->deposit();
			bptr[i]->withdraw();
		}
		else if (strcmp(answer, "C") == 0)
		{
			bptr[i] = new Checking();
			bptr[i]->get_info();
			bptr[i]->deposit();
			bptr[i]->withdraw();
		}
		else if (strcmp(answer, "CD") == 0)
		{
			bptr[i] = new CD();
			bptr[i]->get_info();
			bptr[i]->deposit();
			bptr[i]->withdraw();
		}
		else
		{
			cout << "Try again" << endl;
			--i;
		}
	}

	for (int i = 0; i < numberAcc; i++)
	{
		bptr[i]->display();
	}
	return 0;
}

