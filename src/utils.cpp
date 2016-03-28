/*
 * utils.cpp
 *
 *  Created on: Mar 23, 2016
 *      Author: Tumblr
 */

#include <string>
#include <iostream>
#include <cstdlib>
#include "utils.h"

#ifdef WINDOWS
#include <windows.h>
#else
#include <sys/ioctl.h>
#include <unistd.h>
#endif

using namespace std;

void print_center(string s) {
	string pad = "";
	int k = (get_console_width() / 2) - (s.length() / 2);

	for (int i = 0; i < k; i++)
		pad.append(" ");
	cout << pad << s;
}


#ifdef WINDOWS
void clear_console() {
  std::system ("CLS");
}

int get_console_width() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}

int get_console_height() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}
#else

void clear_console() {
  std::system ("clear");
}

int get_console_width() {
	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
	return size.ws_col;
}

int get_console_height() {
	struct winsize size;
	ioctl(STDOUT_FILENO,TIOCGWINSZ,&size);
	return size.ws_row;
}
#endif

