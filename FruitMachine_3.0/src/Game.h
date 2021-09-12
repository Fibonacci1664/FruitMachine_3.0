#pragma once

// INCLUDES
#include "MyGraphics.h"

// CONSTANTS
constexpr unsigned int ARR_SIZE = 3;
constexpr char SYM1 = '#';
constexpr char SYM2 = '$';
constexpr char SYM3 = '%';
constexpr char SYM4 = '&';
constexpr char SYM5 = '\'';
constexpr char SYM6 = '(';
constexpr char SYM7 = ')';
constexpr char SYM8 = '*';
constexpr char SYM9 = '+';
constexpr char SYM10 = ',';

class Game
{
public:
// CONSTRUCTOR / DESTRUCTOR
	Game();
	~Game();

// MEMBER FUNCTIONS
	void publicShowTitle(MyGraphics& myGame);
	void publicShowWinTable(MyGraphics& myGame);
	void drawBalance(MyGraphics& myGame, int& x, int y, int bal);
	void drawWinAmount(MyGraphics myGame, int x, int y, int bal);
	void drawRandChar(MyGraphics& myGame, int& x, int y, char& randChar);
	bool publicAskEnterCasino(MyGraphics& myGame);
	bool publicAskToGamble(MyGraphics& myGame, int& currBal);
	int publicAmountToBet(MyGraphics& myGame);
	void publicPopulateArrays();
	bool publicGetPlayerInput();
	void publicDrawReels(MyGraphics& myGame);
	void drawLeftReel(MyGraphics& myGame);
	void drawCenterReel(MyGraphics& myGame);
	void drawRightReel(MyGraphics& myGame);
	bool publicSetReels(MyGraphics& myGame);
	bool checkForWin(char& sym_1, char& sym_2, char& sym_3);
	int checkSymbol(char& symbol);
	int calculateMultiplier(int& initialWin);
	void processWin(MyGraphics& myGame);
	void displayLastWin(MyGraphics& myGame);
	bool publicCheckBalance(MyGraphics& myGame);
	void youLose(MyGraphics& myGame);
	void thanksForPlaying(MyGraphics& myGame);
	void resetReels();

	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////

	// Getters / Setters
	int& getBalance();
	void setBalance(int& amount);

	const int& getSpaceBarPress();
	void setSpaceBarPress(int& count);

	char& getLeftReelSym(int& indexPos);
	void setLeftReelSym(int& indexPos, char& symbol);

	char& getCenterReelSym(int& indexPos);
	void setCenterReelSym(int& indexPos, char& symbol);

	char& getRightReelSym(int& indexPos);
	void setRightReelSym(int& indexPos, char& symbol);

	const bool& getLeftFixed();
	void setLeftFixed(bool& state);

	const bool& getCenterFixed();
	void setCenterFixed(bool& state);

	const bool& getRightFixed();
	void setRightFixed(bool& state);

	const int& getBetAmount();
	void setBetAmount(int& betAmount);

	const bool& getTwoLineWin();
	void setTwoLineWin(bool& status);

	const bool& getThreeLineWin();
	void setThreeLineWin(bool& status);

	int& getWinAmount();
	void setWinAmount(int win);

private:
// DATA MEMBERS
	char m_leftReel[ARR_SIZE] = {};
	char m_centerReel[ARR_SIZE] = {};
	char m_rightReel[ARR_SIZE] = {};
	int m_currBalance;
	int m_spaceBarPress;
	bool m_leftFixed;
	bool m_centerFixed;
	bool m_rightFixed;
	int m_betAmount;
	bool m_twoLineWin;
	bool m_threeLineWin;
	int m_winAmount;
		
private:
// MEMBER FUNCTIONS
	void showTitle(MyGraphics& myGame);
	void showWinTable(MyGraphics& myGame);
	bool askEnterCasino(MyGraphics& myGame);
	bool askToGamble(MyGraphics& myGame, int& currBal);
	int amountToBet(MyGraphics& myGame);
	void populateArrays();
	bool getPlayerInput();
	void drawReels(MyGraphics& myGame);
	bool setReels(MyGraphics& myGame);
	bool checkBalance(MyGraphics& myGame);	
};

