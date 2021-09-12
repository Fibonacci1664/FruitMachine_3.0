/*
 * Graphcis.cpp
 *
 * A small class to handle some of the more purely graphics related stuff in the game, buffers etc.
 *
 * Created on: 28 Oct 2019
 *	   Author: © D. Green.
 */

// INCLUDES
#include "MyGraphics.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>  
#include <conio.h> 
#include <windows.h> 
#include <time.h>
#include <windows.h>

#include <string> 
#include <iostream>


// GLOBALS
CONSOLE_SCREEN_BUFFER_INFO con_info;												// Holds screen info.

 // Constructor
MyGraphics::MyGraphics()
{
	hconsole = CreateFile(TEXT("CONOUT$"), GENERIC_WRITE | GENERIC_READ, FILE_SHARE_READ | FILE_SHARE_WRITE, 0L, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, 0L);		// Open i/o channel to console screen.
	initGraphics();
}

MyGraphics::~MyGraphics()
{
	// Destructor.
}

//////////////////////////////////////////////////////////////////////

// FUNCTION DEFS

// This function initializes the console graphics engine 
void MyGraphics::initGraphics()
{
	COORD console_size = { 80, 25 };												// Size of console.

	srand((unsigned)time(NULL));													// Seed the random number generator with time.

	SetConsoleScreenBufferSize(hconsole, console_size);								// Make sure we are in 80x25.

	GetConsoleScreenBufferInfo(hconsole, &con_info);								// Get details for console screen.
}

//////////////////////////////////////////////////////////////////////

// This is the public interface that simply calls the subsequent and private function, thus not allowing direct access from outside classes
void MyGraphics::publicShowConsoleCursor(bool showFlag)
{
	showConsoleCursor(showFlag);
}

/*
 *Small function to be able to show and hide the output windows blinking cursor.

 This IS NOT my code and has been provided by Captain Oblivious at:
 https://stackoverflow.com/questions/18028808/remove-blinking-underscore-on-console-cmd-prompt
 */
void MyGraphics::showConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;													// Set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

//////////////////////////////////////////////////////////////////////

// This is the public interface that simply calls the subsequent and private function, thus not allowing direct access from outside classes.
void MyGraphics::publicSetColor(int foreColor, int backColor)
{
	setColor(foreColor, backColor);
}

// This function sets the color of the console output.
void MyGraphics::setColor(int fcolor, int bcolor)
{
	SetConsoleTextAttribute(hconsole, (WORD)((bcolor << 4) | fcolor));				// Set color.
}

//////////////////////////////////////////////////////////////////////

// This is the public interface that simply calls the subsequent and private function, thus not allowing direct access from outside classes.
void MyGraphics::publicDrawString(int& x, int y, std::string str)
{
	drawString(x, y, str);
}

// This function draws a given string at the passed in coords.
void MyGraphics::drawString(int& x, int y, std::string str)
{
	COORD cursor_pos;																// Used to pass coords.

	// Set printing position.
	cursor_pos.X = x;
	cursor_pos.Y = y;

	SetConsoleCursorPosition(hconsole, cursor_pos);

	std::cout << str;
}

//////////////////////////////////////////////////////////////////////

// This is the public interface that simply calls the subsequent and private function, thus not allowing direct access from outside classes.
void MyGraphics::publicClearTitleScreen()
{
	clearTitleScreen();
}

// This function clears the title screen.
void MyGraphics::clearTitleScreen()
{
	int count = 0;

	//setColor(10, 0);																// Set color to green on black.

	while (count < 5)
	{
		for (int index = 31; index < 87; index++)									// Clear the screen with a scrolling effect.
		{
			switch (count)
			{
				case 0:
					MyGraphics::drawString(index, 0, " ");
					Sleep(20);
					break;
				case 1:
					MyGraphics::drawString(index, 1, " ");
					Sleep(20);
					break;
				case 2:
					MyGraphics::drawString(index, 2, " ");
					Sleep(20);
					break;
				case 3:
					MyGraphics::drawString(index, 3, " ");
					Sleep(20);
					break;
				case 4:
					MyGraphics::drawString(index, 4, " ");
					Sleep(20);
					break;
				default:
					std::cout << "Oops, couldn't clear title screen correctly!\n";
			}
		}

		++count;

		std::cout << '\n';
	}
}
// End clearTitleScreen.

//////////////////////////////////////////////////////////////////////

// This is the public interface that simply calls the subsequent and private function, thus not allowing direct access from outside classes.
void MyGraphics::publicClearGameOverScreen()
{
	clearGameOverScreen();
}

void MyGraphics::clearGameOverScreen()
{
	int count = 0;

	//setColor(10, 0);																// Set color to green on black.

	while (count < 3)
	{
		for (int index = 5; index < 81; index++)									// Clear the screen with a scrolling effect.
		{
			switch (count)
			{
			case 0:
				MyGraphics::drawString(index, 0, " ");
				Sleep(20);
				break;
			case 1:
				MyGraphics::drawString(index, 1, " ");
				Sleep(20);
				break;
			case 2:
				MyGraphics::drawString(index, 2, " ");
				Sleep(20);
				break;
			default:
				std::cout << "Oops, something went wrong!\n";
			}
		}

		++count;

		std::cout << '\n';
	}
}
// End clearGameOverScreen.

//////////////////////////////////////////////////////////////////////

// This is the public interface that simply calls the subsequent and private function, thus not allowing direct access from outside classes.
void MyGraphics::publicClearScreenFull()
{
	clearScreenFull();
}

// This function clears the screen.
void MyGraphics::clearScreenFull()
{
	//setColor(10, 0);																// Set green to white on black.

	int xPos = 0;

	for (int index = 0; index < 30; index++)										// Clear all of the screen as a block of blank text.
	{
		MyGraphics::drawString(xPos, index, "                                                                                      ");
	}

	std::cout << '\n';
}
// End clearScreen.

//////////////////////////////////////////////////////////////////////

// This is the public interface that simply calls the subsequent and private function, thus not allowing direct access from outside classes.
void MyGraphics::publicClearScreenHalf()
{
	clearScreenHalf();
}

void MyGraphics::clearScreenHalf()
{
	int xPos = 0;

	for (int index = 0; index < 15; index++)										// Clear the upper half of the screen as a block of blank text.
	{
		MyGraphics::drawString(xPos, index, "                                                                                      ");
	}

	std::cout << '\n';
}