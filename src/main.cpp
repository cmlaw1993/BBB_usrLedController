/****************************************************************************
 *  Copyright (C) 2016 by Dennis Law										*
 *                                                                          *
 *  This file is part of usrLedController.                                  *
 *                                                                          *
 *	This program is free software: you can redistribute it and/or modify	*
 *  it under the terms of the GNU General Public License as published by	*
 *  the Free Software Foundation, either version 3 of the License, or		*
 *  (at your option) any later version.										*
 *																			*
 *  This program is distributed in the hope that it will be useful,			*
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of			*
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the			*
 *  GNU General Public License for more details.							*
 *																			*
 *  You should have received a copy of the GNU General Public License		*
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.	*
 ****************************************************************************/

#include <iostream>
#include <string>

#include "usrLed.h"

using namespace std;

#define MIN_ARGC								2
#define MAX_ARGC								5

#define MIN_IDXN_ARGC							0
#define MAX_IDXN_ARGC							4

#define MIN_IDXN_VAL							0
#define MAX_IDXN_VAL							3

void printHelp(void);

void printHelp(void)
{
	cout << "The usage of usrLed is as follows:" << endl;
	cout << "\t<operation> <idx0> <idx1> ... <idxn>" << endl;
	cout << "where <operation> can be either on, off, flash or status" << endl;
	cout << "and <idxn> is the index of the user led to operate on." << endl;
	cout << "The value of <idxn> can be from 0 to 3." << endl;
}

int main(int argc, char* argv[])
{
	usrLed *usrLedObj[MAX_IDXN_ARGC];
	int idxnArgv[MAX_IDXN_ARGC];
	int idxnArgc = 0;

	// Check if number of arguments is within range.
	if((argc < MIN_ARGC) || (argc > MAX_ARGC))
	{
		cout << "ERROR! Incorrect number of arguments entered!" << endl;
		printHelp();
		return 2;
	}

	// Check if the <idxn> arguments are valid.
	for(int i = 1; i < argc; i++)
	{
		if((argv[i][0] >= 48) && (argv[i][0] <= (48+MAX_IDXN_VAL)))
		{
			idxnArgv[i-1] = stoi(argv[i]);
		}
		else
		{
			cout << "ERROR! Invalid value of <idxn>!" << endl;
			printHelp();
			return 2;
		}
	}

	// Dynamically create usrLed objects.
	idxnArgc = argc - 1;
	for(int i = 0; i < idxnArgc; i++)
		usrLedObj[i] = new usrLed(idxnArgv[i]);

	// Perfrom operation selected by user.
	string op = argv[0];

	if(op == "./on")
	{
		for(int i = 0; i < idxnArgc; i++)
			usrLedObj[i]->on();
	}
	else if(op == "./off")
	{
		for(int i = 0; i < idxnArgc; i++)
			usrLedObj[i]->off();
	}
	else if(op == "./flash")
	{
		for(int i = 0; i < idxnArgc; i++)
			usrLedObj[i]->flash();
	}
	else if(op == "./status")
	{
		for(int i = 0; i < idxnArgc; i++)
			usrLedObj[i]->status();
	}
	else
	{
		cout << "ERROR! Invalid <operation>!" << endl;
		printHelp();
	}

	// Delete created usrLed objects.
	for(int i = 0; i < idxnArgc; i++)
		delete usrLedObj[i];

	return 0;
}
