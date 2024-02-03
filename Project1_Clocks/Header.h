/*************************************************************
*Project 1													 *
*															 *
*															 *
*Author: Janai Cano											 *
*July 15, 2022												 *
*															 *
*															 *
*Clock app that displays both 12 hour & 24 hour clocks		 *
*Allows users to add hours, minutes, and seconds if desired  *
*															 *
*Designed for Chada Tech									 *
*************************************************************/

#include <iostream>
#include <cstring>
#include <iomanip> //included for set precision to be used

using namespace std;

//Global variables
int hour;
int minute;
int second;
int menuSelection;
//declaring menu function first, defined later
int menu();

/*Function that gets local time off the motherboard
*Used https://www.youtube.com/watch?v=12gm2ceXrt0&list=PLZ9WBSr7mPgl3VYO00MTcE2n_B3Ys6zKU&index=3&t=14s
*As a reference for this function code*/

//I get an error message about local_time being unsafe to build, however, I'm not sure how else to start this off
//unless I just enter any values I want into hour, minute, and second, which is what I will do for the output to begin
//I'll comment out the local_time usage for now, but just wanted to show I attempted to get the correct local time

void GetTime() {

	//gets local time & stores in a variable
	//time_t ttime = time(0);
	//tm* local_time = localtime(&ttime);

	//separates the time by hours, minutes, & seconds
	//hour = local_time->tm_hour;
	//minute = local_time->tm_min;
	//second = local_time->tm_sec;

	hour = 1;
	minute = 45;
	second = 30;

}


//12-Hour Clock function

void printTwelve(int hour, int minute, int second) {

	//local variables
	bool isPM = false;
	string am = "A M";
	string pm = "P M";

	//fixed precision so leading zero prints if hour, minute, or second is one digit
	cout << fixed << setprecision(2);
	cout << "***************************" << endl;
	cout << "*     12-Hour Clock       *" << endl;

	//adjusts minutes if after user adds 1 second it goes over 60
	if (second >= 60) {
		minute = minute + (60 - second);
		second = 60 - second;
	}

	//adjusts hours if after user adds 1 it goes over 60
	if (minute >= 60) {
		hour = hour + (60 - minute);
		minute = 60 - minute;
	}

	//figures out if it is AM or PM according to hours
	//also adjusts hours if after user adds 1 it goes over 12
	if (hour >= 12) {
		isPM = true;
	}

	if (hour > 12) {
		hour = hour - 12;
	}

	if (hour == 0) {
		hour = 12;
	}

	if (isPM) {
		cout << "*     " << hour << ":" << minute << ":" << second << " " << pm << "         *" << endl;
		cout << "***************************" << endl;

	}
	else {
		cout << "*     " << hour << ":" << minute << ":" << second << " " << am << "         *" << endl;
		cout << "***************************" << endl;
	}


}

//24-Hour Clock function

void printTwentyFour(int hour, int minute, int second) {

	//local variables
	bool isAM = false;
	bool isPM = false;
	string am = "A M";
	string pm = "P M";

	//fixed precision so leading zero prints if hour, minute, or second is one digit
	cout << fixed << setprecision(2);
	cout << "***************************" << endl;
	cout << "*      24-Hour Clock      *" << endl;

	//adjusts minutes if after user adds 1 second it goes over 60
	if (second >= 60) {
		minute = minute + (60 - second);
		second = 60 - second;
	}

	//adjusts hours if after user adds 1 it goes over 60
	if (minute >= 60) {
		hour = hour + (60 - minute);
		minute = 60 - minute;
	}

	//figures out if it is AM or PM according to hours
	//also adjusts hours if after user adds 1 it goes over 24
	if (hour < 12) {
		isAM = true;
	}
	else if (hour >= 13) {
		isPM = true;
	}
	else if (hour > 24) {
		hour = hour % 24;
	}

	//prints the clock plus AM if it is AM
	if (isAM) {
		cout << "*     " << hour << ":" << minute << ":" << second << " " << am << "         *" << endl;
		cout << "***************************" << endl;
	}

	//prints the clock plus PM if it is PM
	if (isPM) {
		cout << "*     " << hour << ":" << minute << ":" << second << " " << pm << "         *" << endl;
		cout << "***************************" << endl;
	}

}

//Function that takes user selection from menu function & adds time to appropriate unit (hour, minute, or second)

void addTime(int menuSelection) {

	//first calls the get time function to get starting time
	GetTime();

	//if user exits program, loop never starts & program terminates
	if (menuSelection == 4) {
		cout << "Exiting program. Thank you for using Chada Tech." << endl;
		exit;
	}

	//if user entry is valid & doesn't exit, loop begins, adds 1 to either hour, minute, or second
	while (menuSelection != 4) {

		if (menuSelection == 1) {
			hour = 1 + hour;
		}

		else if (menuSelection == 2) {
			minute = 1 + minute;
		}

		else if (menuSelection == 3) {
			second = 1 + second;
		}
		//if user entry is invalid, gets new input from user
		else {
			cout << "Invalid selection. Enter menu choice 1-4: " << endl;
			cin >> menuSelection;
			addTime(menuSelection);
		}
		//calls functions to update the clocks according to menu selection
		printTwelve(hour, minute, second);
		printTwentyFour(hour, minute, second);

		//calls menu function to get new menu selection input from user
		menuSelection = menu();
	}
}

int menu() {

	cout << "***************************" << endl;
	cout << "*   Enter option number:  *" << endl;
	cout << "*-------------------------*" << endl;
	cout << "*     1: Add 1 hour       *" << endl;
	cout << "*     2: Add 1 minute     *" << endl;
	cout << "*     3: Add 1 second     *" << endl;
	cout << "*     4: Exit Program     *" << endl;
	cout << "***************************" << endl;

	cin >> menuSelection;

	return menuSelection;
}

