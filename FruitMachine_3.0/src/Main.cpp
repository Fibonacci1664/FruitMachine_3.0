/*
 * Main.cpp
 *
 * Main class to set up the graphics and run the main game loop.
 *
 * Created on: 28 Oct 2019
 *	   Author: © D. Green.
 */

#include<iostream>
#include "MyGraphics.h"
#include "Game.h"

bool gameRunning = false;

int main()
{
	MyGraphics graphics;
	Game game;
	
	graphics.publicShowConsoleCursor(false);															// Disable the output windows cursor from blinking.
	graphics.publicSetColor(14, 0);																		// Set colour to yellow on black.

	game.publicShowTitle(graphics);

	Sleep(1000);
	graphics.publicClearTitleScreen();
	game.publicShowWinTable(graphics);

	gameRunning = game.publicAskEnterCasino(graphics);

	bool gambling = false;	

	/////////////////////////////////////////////////////////////////////////

	// MAIN GAME LOOP
	while (gameRunning)
	{
		gambling = true;

		// If being asked to gamble returns false, exit game.
		if (!game.publicAskToGamble(graphics, game.getBalance()))
		{
			break;
		}

		// Ask how much to bet.
		game.publicAmountToBet(graphics);

		while (gambling)
		{
			// < INITIALIZE STUFF >
			// Create the reels.
			game.publicPopulateArrays();

			// < DRAW STUFF >
			game.publicDrawReels(graphics);

			// < CHECK STUFF >
			// If this return true it means the spacebar was pressed. So increment by 1.
			if (game.publicGetPlayerInput())
			{
				int plusOne = 1;

				game.setSpaceBarPress(plusOne);
			}

			// < SET / RESET STUFF >
			// This will continue to return true until ALL three reels have stopped, i.e. spaceBarPress = 3. at which point it returns false and we exit to the outer while loop.
			gambling = game.publicSetReels(graphics);

			/*
			The Sleep() function takes an integer parameterand waits that number of milliseconds.
			So 1000 in this case means sleep for 150ms or 0.15 of a second then loop again.
			*/
			// This is the speed of the reels.
			Sleep(150);	
		}

		// < CHECK STUFF AGAIN WITH NEW STATUS >
		bool fundsAvailable = game.publicCheckBalance(graphics);

		if (!fundsAvailable)
		{
			gameRunning = false;
		}
	}
	
	int xPos = 36;

	graphics.publicDrawString(xPos, 5, "G A M E  O V E R");
	std::cout << '\n';

	return 0;
}