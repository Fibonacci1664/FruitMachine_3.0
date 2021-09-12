/*
 * Game.cpp
 *
 * A small class to handle more of the gameplay type aspects of the game, wintables, checking for wins, spinning and stopping reels etc.
 *
 * Created on: 28 Oct 2019
 *	   Author: © D. Green.
 */

#include "Game.h"
#include "MyGraphics.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h>  
#include <conio.h> 
#include <windows.h> 
#include <time.h> 
#include <string> 
#include <iostream>

// Constructor
Game::Game()
{
	m_currBalance = 1000;
	m_spaceBarPress = 0;
	m_leftFixed = false;
	m_centerFixed = false;
	m_rightFixed = false;
	m_betAmount = 0;
	m_winAmount = 0;
	m_threeLineWin = false;
	m_twoLineWin = false;
}

Game::~Game()
{
	// Destructor.
}

//////////////////////////////////////////////////////////////////////

// FUNCTION DEFS

// This is the public interface that simply calls the subsequent private function, thus not allowing direct access from outside classes.
void Game::publicShowTitle(MyGraphics& myGame)
{
	showTitle(myGame);
}

// Displays the title of the game.
void Game::showTitle(MyGraphics& myGame)
{
	int xPos = 31;

	myGame.publicDrawString(xPos, 0, "########################################################\n");
	myGame.publicDrawString(xPos, 1, "#########                                      #########\n");
	myGame.publicDrawString(xPos, 2, "#########    WELCOME TO CASINO ROB-YA-BLIND    #########\n");
	myGame.publicDrawString(xPos, 3, "#########                                      #########\n");
	myGame.publicDrawString(xPos, 4, "########################################################\n");
}

//////////////////////////////////////////////////////////////////////

// This is the public interface that simply calls the subsequent private function, thus not allowing direct access from outside classes.
void Game::publicShowWinTable(MyGraphics& myGame)
{
	showWinTable(myGame);
}

// Displays the win table on the left of the console.
void Game::showWinTable(MyGraphics& myGame)
{
	/*
	When it comes to matching two the ANY could also apply to the first reel with reels 2 and 3 matching
	As long as at least 2 of the same symbols are next to each other its a WIN!.
	*/

	int xPos = 86;

	myGame.publicDrawString(xPos, 0,  "###############################\n");
	myGame.publicDrawString(xPos, 1,  "####       WIN TABLE       ####\n");
	myGame.publicDrawString(xPos, 2,  "###############################\n");
	myGame.publicDrawString(xPos, 3,  "####      $ $ $   = 100    ####\n");
	myGame.publicDrawString(xPos, 4,  "####      & & &   =  90    ####\n");
	myGame.publicDrawString(xPos, 5,  "####      # # #   =  80    ####\n");
	myGame.publicDrawString(xPos, 6,  "####      * * *   =  70    ####\n");
	myGame.publicDrawString(xPos, 7,  "####      % % %   =  60    ####\n");
	myGame.publicDrawString(xPos, 8,  "####      ( ( (   =  50    ####\n");
	myGame.publicDrawString(xPos, 9,  "####      ) ) )   =  40    ####\n");
	myGame.publicDrawString(xPos, 10, "####      + + +   =  30    ####\n");
	myGame.publicDrawString(xPos, 11, "####      ' ' '   =  20    ####\n");
	myGame.publicDrawString(xPos, 12, "####      , , ,   =  10    ####\n");
	myGame.publicDrawString(xPos, 13, "####      $ $ ANY =  50    ####\n");
	myGame.publicDrawString(xPos, 14, "####      & & ANY =  45    ####\n");
	myGame.publicDrawString(xPos, 15, "####      # # ANY =  40    ####\n");
	myGame.publicDrawString(xPos, 16, "####      * * ANY =  35    ####\n");
	myGame.publicDrawString(xPos, 17, "####      % % ANY =  30    ####\n");
	myGame.publicDrawString(xPos, 18, "####      ( ( ANY =  25    ####\n");
	myGame.publicDrawString(xPos, 19, "####      ) ) ANY =  20    ####\n");
	myGame.publicDrawString(xPos, 20, "####      + + ANY =  15    ####\n");
	myGame.publicDrawString(xPos, 21, "####      ' ' ANY =  10    ####\n");
	myGame.publicDrawString(xPos, 22, "####      , , ANY =   5    ####\n");
	myGame.publicDrawString(xPos, 23, "###############################\n");
	myGame.publicDrawString(xPos, 24, "####      MULTIPLIERS      ####\n");
	myGame.publicDrawString(xPos, 25, "###############################\n");
	myGame.publicDrawString(xPos, 26, "####   BET 30  = x3 WIN    ####\n");
	myGame.publicDrawString(xPos, 27, "####   BET 50  = x5 WIN    ####\n");
	myGame.publicDrawString(xPos, 28, "####   BET 100 = x10 WIN   ####\n");
	myGame.publicDrawString(xPos, 29, "###############################\n");
}
// END SHOW WIN TABLE.

//////////////////////////////////////////////////////////////////////

// This function draws the players remaining balance.
void Game::drawBalance(MyGraphics& myGame, int& x, int y, int balance)
{
	COORD cursor_pos;																// Used to pass coords.

	// Set printing position.
	cursor_pos.X = x;
	cursor_pos.Y = y;

	SetConsoleCursorPosition(myGame.hconsole, cursor_pos);

	std::cout << "Your balance is " << char(156) << balance;
}

//////////////////////////////////////////////////////////////////////

// This function draws the players remaining balance.
void Game::drawWinAmount(MyGraphics myGame, int x, int y, int winnings)
{
	COORD cursor_pos;																// Used to pass coords.

	// Set printing position.
	cursor_pos.X = x;
	cursor_pos.Y = y;

	SetConsoleCursorPosition(myGame.hconsole, cursor_pos);

	std::cout << char(156) << winnings;
}

//////////////////////////////////////////////////////////////////////

// This function draws the random char that is passed at the coords given.
void Game::drawRandChar(MyGraphics& myGame, int& x, int y, char& randChar)
{
	COORD cursor_pos;																// Used to pass coords.

	// Set printing position.
	cursor_pos.X = x;
	cursor_pos.Y = y;

	SetConsoleCursorPosition(myGame.hconsole, cursor_pos);

	std::cout << randChar;
}

//////////////////////////////////////////////////////////////////////

// This is the public interface that simply calls the subsequent private function, thus not allowing direct access from outside classes.
bool Game::publicAskEnterCasino(MyGraphics& myGame)
{
	return askEnterCasino(myGame);
}

bool Game::askEnterCasino(MyGraphics& myGame)
{
	char ans;
	int xPos = 0;

	do
	{
		myGame.publicClearScreenFull();
		myGame.publicDrawString(xPos, 0, "Welcome, do you want to enter the casino, y/n: > ");
		std::cin >> ans;
	} while (std::tolower(ans) != 'y' && std::tolower(ans) != 'n');

	if (ans == 'n')
	{
		thanksForPlaying(myGame);
		myGame.publicClearGameOverScreen();
		return false;;
	}

	return true;
}

//////////////////////////////////////////////////////////////////////

// This is the public interface that simply calls the subsequent private function, thus not allowing direct access from outside classes.
bool Game::publicAskToGamble(MyGraphics& myGame, int& currBal)
{
	return askToGamble(myGame, currBal);
}

// Contiue to ask the player is they wish to gamble each time, if they say no then they exit the program.
bool Game::askToGamble(MyGraphics& myGame, int& currBalance)
{
	char ans;
	int stringXPos = 0;
	int balanceXPos = 64;

	do
	{
		myGame.publicClearScreenHalf();
		drawBalance(myGame, balanceXPos, 0, currBalance);
		myGame.publicDrawString(stringXPos, 0, "Do you want to gamble, y/n: > ");
		std::cin >> ans;
	} while (std::tolower(ans) != 'y' && std::tolower(ans) != 'n');

	if (ans == 'n')
	{
		thanksForPlaying(myGame);
		myGame.publicClearGameOverScreen();
		return false;
	}

	return true;
}


//////////////////////////////////////////////////////////////////////

// This is the public interface that simply calls the subsequent private function, thus not allowing direct access from outside classes.
int Game::publicAmountToBet(MyGraphics& myGame)
{
	return amountToBet(myGame);
}

int Game::amountToBet(MyGraphics& myGame)
{
	int bet;
	int stringXPos = 0;
	int balanceXPos = 64;

	do
	{
		// Clear any old input, redraw balance and ask again.
		myGame.publicClearScreenHalf();
		drawBalance(myGame, balanceXPos, 0, getBalance());
		myGame.publicDrawString(stringXPos, 0, "How much would you like to gamble, minimum bet is 10:> ");
		std::cin.clear();																	// Clears all error flags that may have been set by incorrect input.
		std::cin.ignore(1000, '\n');														// Ignores 1000 chars or until it finds a newline in the buffer. Both clear() and ignore() are req.
																							// to reset the IO stream to be able to keep taking input after incorrect input such as a char when
																							// an int was expected.
		std::cin >> bet;
	} while (!isdigit(bet) && (bet < 10 || bet > getBalance()));							// If the input 'bet' is not a digit, less than 10 or is greater than the current available balance then keep asking.

	setBetAmount(bet);

	int negBet = bet * -1;

	setBalance(negBet);

	if (getBalance() < 0)
	{
		int zero = 0;
		setBalance(zero);
	}

	// Clear old balance and draw new balance.
	myGame.publicClearScreenFull();
	drawBalance(myGame, balanceXPos, 0, getBalance());

	return bet;
}

//////////////////////////////////////////////////////////////////////

// This is the public interface that simply calls the subsequent private function, thus not allowing direct access from outside classes.
void Game::publicPopulateArrays()
{
	populateArrays();
}

/*
Check how many times the space bar has been pressed while looping and populating the arrays, in order that we can essesntially
save what was once populated into previous arrays, preventing overwriting on subsequent iterations.
*/
void Game::populateArrays()
{
	for (int i = 0; i < ARR_SIZE; ++i)
	{
		if (getSpaceBarPress() == 0)
		{
			char rand_1 = rand() % 10 + 35;
			char rand_2 = rand() % 10 + 35;
			char rand_3 = rand() % 10 + 35;

			setLeftReelSym(i, rand_1);
			setCenterReelSym(i, rand_2);
			setRightReelSym(i, rand_3);
		}
		else if (getSpaceBarPress() == 1)
		{
			char rand_1 = rand() % 10 + 35;
			char rand_2 = rand() % 10 + 35;

			setCenterReelSym(i, rand_1);
			setRightReelSym(i, rand_2);
		}
		else if (getSpaceBarPress() == 2)
		{
			char rand_1 = rand() % 10 + 35;

			setRightReelSym(i, rand_1);
		}	
	}
}

//////////////////////////////////////////////////////////////////////

// This is the public interface that simply calls the subsequent private function, thus not allowing direct access from outside classes.
bool Game::publicGetPlayerInput()
{
	return getPlayerInput();
}

bool Game::getPlayerInput()
{
	char key;

	if (_kbhit())
	{
		key = toupper(_getch());											// Get keyboard data, and filter it.

		if (key == ' ')
		{
			return true;
		}
	}

	return false;
}

//////////////////////////////////////////////////////////////////////

// This is the public interface that simply calls the subsequent private function, thus not allowing direct access from outside classes.
void Game::publicDrawReels(MyGraphics& myGame)
{
	drawReels(myGame);
}

void Game::drawReels(MyGraphics& myGame)
{
	drawLeftReel(myGame);
	drawCenterReel(myGame);
	drawRightReel(myGame);
}

//////////////////////////////////////////////////////////////////////

void Game::drawLeftReel(MyGraphics& myGame)
{
	int xPos = 38;

	// If the left reel has not stopped yet then redraw it.
	if (!getLeftFixed())
	{
		for (int i = 0; i < ARR_SIZE; ++i)
		{
			// Left most vertical reel.
			drawRandChar(myGame, xPos, (3 + (i * 2)), getLeftReelSym(i));
		}
	}
}

//////////////////////////////////////////////////////////////////////

void Game::drawCenterReel(MyGraphics& myGame)
{
	int xPos = 43;

	// If the center reel has not stopped yet then redraw it.
	if (!getCenterFixed())
	{
		for (int i = 0; i < ARR_SIZE; ++i)
		{
			// Center vertical reel.
			drawRandChar(myGame, xPos, (3 + (i * 2)), getCenterReelSym(i));
		}
	}
}

//////////////////////////////////////////////////////////////////////

void Game::drawRightReel(MyGraphics& myGame)
{
	int xPos = 48;

	// If the right reel has not stopped yet then redraw it.
	if (!getRightFixed())
	{
		for (int i = 0; i < ARR_SIZE; ++i)
		{
			// Right most vertical reel.
			drawRandChar(myGame, xPos, (3 + (i * 2)), getRightReelSym(i));
		}
	}
}

//////////////////////////////////////////////////////////////////////

// This is the public interface that simply calls the subsequent private function, thus not allowing direct access from outside classes.
bool Game::publicSetReels(MyGraphics& myGame)
{
	return setReels(myGame);
}

// Check against how many times the space bar has been pressed and set reels in fixed position accordingly. Once last reel is set check for win, process, reset reels and return.
bool Game::setReels(MyGraphics& myGame)
{
	int stringXPos = 23;

	myGame.publicDrawString(stringXPos, 5, "WINLINE  --> ");

	if ((getSpaceBarPress() == 1) && !getLeftFixed())
	{
		bool fixedState = true;
		int randCharXPos = 38;

		setLeftFixed(fixedState);

		for (int i = 0; i < ARR_SIZE; ++i)
		{
			if (i == 1)
			{
				myGame.publicSetColor(14, 20);											// Set the center winline symbol to be highlighted once the spacebar is pressed.
			}

			// Left most vertical reel.
			drawRandChar(myGame, randCharXPos, (3 + (i * 2)), getLeftReelSym(i));

			myGame.publicSetColor(14, 0);												// Set the colours back to normal, yellow on black.
		}
	}
	else if ((getSpaceBarPress() == 2) && !getCenterFixed())
	{
		bool fixedState = true;
		int randCharXPos = 43;

		setCenterFixed(fixedState);

		for (int i = 0; i < ARR_SIZE; ++i)
		{
			if (i == 1)
			{
				myGame.publicSetColor(14, 20);
			}

			// Center vertical reel.
			drawRandChar(myGame, randCharXPos, (3 + (i * 2)), getCenterReelSym(i));

			myGame.publicSetColor(14, 0);
		}
	}
	else if ((getSpaceBarPress() == 3) && !getRightFixed())
	{
		bool fixedState = true;
		int randCharXPos = 48;

		setRightFixed(fixedState);

		for (int i = 0; i < ARR_SIZE; ++i)
		{

			if (i == 1)
			{
				myGame.publicSetColor(14, 20);
			}

			// Right most vertical reel.
			drawRandChar(myGame, randCharXPos, (3 + (i * 2)), getRightReelSym(i));

			myGame.publicSetColor(14, 0);
		}

		int symbolIndexPos = 1;

		checkForWin(getLeftReelSym(symbolIndexPos), getCenterReelSym(symbolIndexPos), getRightReelSym(symbolIndexPos));
		processWin(myGame);

		// This is the wait time after the last reel has stopped. Alowwing player to read any win messages or otherwise.
		Sleep(4000);

		displayLastWin(myGame);
		resetReels();
		
		return false;
	}

	return true;
}
// END SET REELS.

//////////////////////////////////////////////////////////////////////

// This function checks for a win on the center winline.
bool Game::checkForWin(char& sym_1, char& sym_2, char& sym_3)
{
	if ((sym_1 == sym_2) && (sym_1 == sym_3))
	{
		bool winState = true;

		setThreeLineWin(winState);
		return true;
	}
	else if ((sym_1 == sym_2) || (sym_2 == sym_3))
	{
		bool winState = true;

		setTwoLineWin(winState);
		return true;
	}

	return false;
}

//////////////////////////////////////////////////////////////////////

// Check which symbol has won in order to correctly apply the winnings.
int Game::checkSymbol(char& symbol)
{
	int winValue = 0;

	switch (symbol)
	{
	case SYM1:
		winValue = 80;
		break;
	case SYM2:
		winValue = 100;
		break;
	case SYM3:
		winValue = 60;
		break;
	case SYM4:
		winValue = 90;
		break;
	case SYM5:
		winValue = 20;
		break;
	case SYM6:
		winValue = 50;
		break;
	case SYM7:
		winValue = 40;
		break;
	case SYM8:
		winValue = 70;
		break;
	case SYM9:
		winValue = 30;
		break;
	case SYM10:
		winValue = 10;
		break;
	default:
		std::cout << "Couldn't determine the correct win symbol.\n";
	}

	// Pass the initial win amount to the calculate multiplier function to apply any multiplier if necessary. Then return that value back to the caller of checkSymbol.
	return calculateMultiplier(winValue);
}
// END CHECK SYMBOL.

//////////////////////////////////////////////////////////////////////

// Calculate if there is a multiplier to apply to the initial win based on the placed bet.
int Game::calculateMultiplier(int& initialWin)
{
	int multiplier = 1;

	if (getBetAmount() == 30)
	{
		multiplier = 3;
	}
	else if (getBetAmount() == 50)
	{
		multiplier = 5;
	}
	else if (getBetAmount() == 100)
	{
		multiplier = 10;
	}

	if (getThreeLineWin())
	{
		return initialWin * multiplier;
	}
	else if (getTwoLineWin())
	{
		return (initialWin / 2) * multiplier;
	}

	return initialWin * multiplier;
}

//////////////////////////////////////////////////////////////////////

// Figure out any win that has occured and inform player, or not.
void Game::processWin(MyGraphics& myGame)
{
	int symbolIndexPos = 1;
	int stringXPos = 26;

	if (getThreeLineWin())
	{
		int stringXPos_1 = 26;
		int stringXPos_2 = 28;

		setWinAmount(checkSymbol(getLeftReelSym(symbolIndexPos)));
		myGame.publicDrawString(stringXPos_1, 10, "######    MATCH THREE WIN!    ######");
		myGame.publicDrawString(stringXPos_2, 12, "####        YOU WIN!        ####");
		drawWinAmount(myGame, 43, 14, getWinAmount());
		setBalance(getWinAmount());
	}
	else if (getTwoLineWin())
	{
		int stringXPos_1 = 27;
		int stringXPos_2 = 29;

		setWinAmount(checkSymbol(getCenterReelSym(symbolIndexPos)));
		myGame.publicDrawString(stringXPos_1, 10, "######    MATCH TWO WIN!    ######");
		myGame.publicDrawString(stringXPos_2, 12, "####       YOU WIN!       ####");
		drawWinAmount(myGame, 43, 14, getWinAmount());
		setBalance(getWinAmount());
	}
	else
	{
		int stringXPos = 15;

		myGame.publicDrawString(stringXPos, 10, "#####    NO WIN THIS TIME, BETTER LUCK NEXT TIME!    #####");
	}
}

//////////////////////////////////////////////////////////////////////

void Game::displayLastWin(MyGraphics& myGame)
{
	int lastWinXPos = 15;

	myGame.publicDrawString(lastWinXPos, 15, "##################    LAST WIN BELOW    ##################");

	for (int i = 0; i < ARR_SIZE; ++i)
	{
		int stringXPos = 38;

		// Left most vertical reel.
		drawRandChar(myGame, stringXPos, (18 + (i * 2)), getLeftReelSym(i));
	}

	for (int i = 0; i < ARR_SIZE; ++i)
	{
		int stringXPos = 43;

		// Center vertical reel.
		drawRandChar(myGame, stringXPos, (18 + (i * 2)), getCenterReelSym(i));
	}

	for (int i = 0; i < ARR_SIZE; ++i)
	{
		int stringXPos = 48;

		// Right most vertical reel.
		drawRandChar(myGame, stringXPos, (18 + (i * 2)), getRightReelSym(i));
	}

	if (getThreeLineWin())
	{
		int stringXPos_1 = 26;
		int stringXPos_2 = 28;

		myGame.publicDrawString(stringXPos_1, 25, "######    MATCH THREE WIN!    ######");
		myGame.publicDrawString(stringXPos_2, 27, "####        YOU WIN!        ####");
		drawWinAmount(myGame, 43, 29, getWinAmount());
	}
	else if (getTwoLineWin())
	{
		int stringXPos_1 = 27;
		int stringXPos_2 = 29;

		myGame.publicDrawString(stringXPos_1, 25, "######    MATCH TWO WIN!    ######");
		myGame.publicDrawString(stringXPos_2, 27, "####       YOU WIN!       ####");
		drawWinAmount(myGame, 43, 29, getWinAmount());
	}
	else
	{
		int stringXPos = 15;

		myGame.publicDrawString(stringXPos, 25, "#####    NO WIN THIS TIME, BETTER LUCK NEXT TIME!    #####");
	}
}
// END DISPLAY LAST WIN.

//////////////////////////////////////////////////////////////////////

// This is the public interface that simply calls the subsequent and private function, thus not allowing direct access from outside classes
bool Game::publicCheckBalance(MyGraphics& myGame)
{
	return checkBalance(myGame);
}

bool Game::checkBalance(MyGraphics& myGame)
{
	int fundsAvailable = getBalance();

	if (fundsAvailable <= 10)
	{
		youLose(myGame);
		myGame.publicClearGameOverScreen();

		return false;
	}

	return true;
}

//////////////////////////////////////////////////////////////////////

void Game::thanksForPlaying(MyGraphics& myGame)
{
	int xPos = 5;

	myGame.publicClearScreenFull();

	myGame.publicDrawString(xPos, 0,  "############################################################################\n");
	myGame.publicDrawString(xPos, 1,  "#########################    THANKS FOR PLAYING    #########################\n");
	myGame.publicDrawString(xPos, 2,  "#########################          GOODBYE         #########################\n");
	myGame.publicDrawString(xPos, 3,  "############################################################################\n");
}

//////////////////////////////////////////////////////////////////////

void Game::youLose(MyGraphics& myGame)
{
	int xPos = 5;

	myGame.publicClearScreenFull();

	myGame.publicDrawString(xPos, 0, "############################################################################\n");
	myGame.publicDrawString(xPos, 1, "#########    YOU HAVE INSUFFICIENT FUNDS AVAILABLE TO CONTINUE!    #########\n");
	myGame.publicDrawString(xPos, 2, "#########                          GOODBYE                         #########\n");
	myGame.publicDrawString(xPos, 3, "############################################################################\n");

	Sleep(1000);
}

//////////////////////////////////////////////////////////////////////

// Reset the status of the game.
void Game::resetReels()
{
	bool reelState = false;
	bool winState = false;
	int zeroSpaceBar = 0;
	int zeroBetAmount = 0;
	int zeroWinAmount = 0;

	setLeftFixed(reelState);
	setCenterFixed(reelState);
	setRightFixed(reelState);
	setSpaceBarPress(zeroSpaceBar);
	setBetAmount(zeroBetAmount);
	setTwoLineWin(winState);
	setThreeLineWin(winState);
	setWinAmount(zeroWinAmount);
}

//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////

// GETTERS AND SETTERS.

int& Game::getBalance()
{
	return m_currBalance;
}

void Game::setBalance(int& amount)
{
	m_currBalance += amount;
}

//////////////////////////////////////////////////////////////////////

const int& Game::getSpaceBarPress()
{
	return m_spaceBarPress;
}

void Game::setSpaceBarPress(int& count)
{
	if (count == 0)
	{
		m_spaceBarPress = count;
	}
	else
	{
		m_spaceBarPress += count;
	}
}

//////////////////////////////////////////////////////////////////////

char& Game::getLeftReelSym(int& indexPos)
{
	return m_leftReel[indexPos];
}

void Game::setLeftReelSym(int& indexPos, char& symbol)
{
	m_leftReel[indexPos] = symbol;
}

//////////////////////////////////////////////////////////////////////

char& Game::getCenterReelSym(int& indexPos)
{
	return m_centerReel[indexPos];
}

void Game::setCenterReelSym(int& indexPos, char& symbol)
{
	m_centerReel[indexPos] = symbol;
}

//////////////////////////////////////////////////////////////////////

char& Game::getRightReelSym(int& indexPos)
{
	return m_rightReel[indexPos];
}

void Game::setRightReelSym(int& indexPos, char& symbol)
{
	m_rightReel[indexPos] = symbol;
}

//////////////////////////////////////////////////////////////////////

const bool& Game::getLeftFixed()
{
	return m_leftFixed;
}

void Game::setLeftFixed(bool& state)
{
	m_leftFixed = state;
}

//////////////////////////////////////////////////////////////////////

const bool& Game::getCenterFixed()
{
	return m_centerFixed;
}

void Game::setCenterFixed(bool& state)
{
	m_centerFixed = state;
}

//////////////////////////////////////////////////////////////////////

const bool& Game::getRightFixed()
{
	return m_rightFixed;
}

void Game::setRightFixed(bool& state)
{
	m_rightFixed = state;
}

//////////////////////////////////////////////////////////////////////

const int& Game::getBetAmount()
{
	return m_betAmount;
}

void Game::setBetAmount(int& betAmount)
{
	m_betAmount = betAmount;
}

//////////////////////////////////////////////////////////////////////

const bool& Game::getTwoLineWin()
{
	return m_twoLineWin;
}

void Game::setTwoLineWin(bool& status)
{
	m_twoLineWin = status;
}

//////////////////////////////////////////////////////////////////////

const bool& Game::getThreeLineWin()
{
	return m_threeLineWin;
}

void Game::setThreeLineWin(bool& status)
{
	m_threeLineWin = status;
}

//////////////////////////////////////////////////////////////////////

int& Game::getWinAmount()
{
	return m_winAmount;
}

void Game::setWinAmount(int win)
{
	m_winAmount = win;
}

//////////////////////////////////////////////////////////////////////