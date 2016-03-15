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

#ifndef USRLED_H
#define USRLED_H

#include <string>

#define USRLED_PATH		"/sys/class/leds/beaglebone:green:usr"

class usrLed
{
	// members
private:
	int m_idx;
	std::string m_path;

	// constructors
public:
	usrLed(int idx);

	// methods
private:
	void readFromUsrLedFile(std::string file, std::string &output);
	void writeToUsrLedFile(std::string file, std::string input);
public:
	void on(void);
	void off(void);
	void flash(void);
	void status(void);
};

#endif	// USRLED_H
