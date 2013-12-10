///////////////////////////////////////////////
/* 	
	DateTime - Simple Arduino date/time library 

    Copyright (C) 2013  DesignLibre

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
//////////////////////////////////////////


#ifndef DateTime_h
#define DateTime_h

#include <Wire.h>
#include <avr/pgmspace.h>
#include <Arduino.h>

#define SECONDS_PER_DAY 86400L
#define SECONDS_FROM_1970_TO_2000 946684800



// Based on Public Domain code by JeeLabs http://jeelabs.org/
// Modified by DesignLibre and changes released under GNU GPL v3.0 [December 8th, 2013]

// Simple general-purpose date/time class (no TZ / DST / leap second handling!)
class DateTime 
{
public:
    DateTime (uint32_t t =0);
    DateTime (uint16_t year, uint8_t month, uint8_t day,
                uint8_t hour =0, uint8_t min =0, uint8_t sec =0);
    DateTime (const char* date, const char* time);
    uint16_t year() const       { return 2000 + yOff; }
    uint8_t month() const       { return m; }
    uint8_t day() const         { return d; }
    uint8_t hour() const        { return hh; }
    uint8_t minute() const      { return mm; }
    uint8_t second() const      { return ss; }
    uint8_t dayOfWeek() const;
	void AddDay(int numDays);
	void AddMonth(int numMonths);
	void AddYear(int numYears);
	void AddSecond(int numSeconds);
	void AddMinute(int numMinutes);
	void AddHour(int numHours);
    long secondstime() const;   // 32-bit times as seconds since 1/1/2000
    uint32_t unixtime(void) const;	// 32-bit times as seconds since 1/1/1970

protected:
	uint8_t DaysPerMonth();
    uint8_t yOff, m, d, hh, mm, ss;
};
#endif