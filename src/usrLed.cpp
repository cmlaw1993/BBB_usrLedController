/****************************************************************************
 *  Copyright (C) 2016 by Dennis Law                                        *
 *                                                                          *
 *  This file is part of usrLedController.                                  *
 *                                                                          *
 *  This program is free software: you can redistribute it and/or modify    *
 *  it under the terms of the GNU General Public License as published by    *
 *  the Free Software Foundation, either version 3 of the License, or       *
 *  (at your option) any later version.                                     *
 *                                                                          *
 *  This program is distributed in the hope that it will be useful,         *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of          *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           *
 *  GNU General Public License for more details.                            *
 *                                                                          *
 *  You should have received a copy of the GNU General Public License       *
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.   *
 ****************************************************************************/

#include <iostream>
#include <fstream>

#include "usrLed.h"

using namespace std;

usrLed::usrLed(int idx)
{
	m_idx = idx;
	m_path = USRLED_PATH + to_string(idx);
}

void usrLed::readFromUsrLedFile(string file, string &output)
{
	string filePath = m_path + file;

	ifstream ifs(filePath);
	getline(ifs, output);
	ifs.close();
}

void usrLed::writeToUsrLedFile(string file, string input)
{
	string filePath = m_path + file;

	ofstream ofs(filePath);
	ofs << input;
	ofs.close();
}

void usrLed::on(void)
{
	cout << "Turning on user led " << m_idx << " ..." << endl;
	writeToUsrLedFile("/trigger", "none");
	writeToUsrLedFile("/brightness", "1");
	cout << "... done!" << endl;
}

void usrLed::off(void)
{
	cout << "Turning off user led " << m_idx << " ..." << endl;
	writeToUsrLedFile("/trigger", "none");
	writeToUsrLedFile("/brightness", "0");
	cout << "... done!" << endl;
}

void usrLed::flash(void)
{
	cout << "Flashing  user led " << m_idx << " ..." << endl;
	writeToUsrLedFile("/trigger", "timer");
	writeToUsrLedFile("/delay_on", "50");
	writeToUsrLedFile("/delay_off", "50");
	cout << "... done!" << endl;
}

void usrLed::status(void)
{
	cout << "Reading status of user led " << m_idx << " ..." << endl;
	string status;
	readFromUsrLedFile("/trigger", status);
	cout << status << endl;
	cout << "... done!" << endl;
}

