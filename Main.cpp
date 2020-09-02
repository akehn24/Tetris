/*****************************************************************************************
/* Desc: Tetris tutorial
/*
/* gametuto.com - Javier Lopez Lopez (javilop.com)
/*
/*****************************************************************************************
/*
/* Creative Commons - Attribution 3.0 Unported
/* You are free:
/*	to Share - to copy, distribute and transmit the work
/*	to Remix - to adapt the work
/*
/* Under the following conditions:
/* Attribution. You must attribute the work in the manner specified by the author or licensor
/* (but not in any way that suggests that they endorse you or your use of the work).
/*
/*****************************************************************************************/

#include "Game.h"

/*
* ------------------------------------------------------------------*
*								Main 							    *
* ------------------------------------------------------------------*
*/


/*
* =========================================================================
* Main Method
* 
* Everything is drawn in every frame. 
* Keyboard input moves the piece if allowed.
* The time to move the piece down is checked every n milliseconds.
* All movement is checked before executed.
* 
* If blocks occupy the uppermost row, the game is lost.
* If ESCAPE is pressed, the game ends.
* =========================================================================
*/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	// Variables
	IO mIO;
	int mScreenHeight = mIO.GetScreenHeight();
	Pieces mPieces;
	Board mBoard;
	Game mGame;
	unsigned long mTime1 = SDL_GetTicks();

	// Main Loop
	while (!mIO.IsKeyDown(SDLK_ESCAPE)) {
		// Draw
		mIO.ClearScreen();			// Clear the screen
		mGame.DrawScene();			// Draw the scene
		mIO.UpdateScreen();			// Update the graphics on the screen

		// Input
		int mKey = mIO.Pollkey();

		switch (mkey) {
			// right key
			case(SDLK_RIGHT): {
				if (mBoard.IsPossMove(mGame.mPosX + 1, mGame.mPosY, mGame.mPiece, mGame.mRotation)) {
					mGame.mPosX++;
				}
				break;
			}
			
			//left key
			case(SDLK_LEFT): {
				if (mBoard.IsPossMove(mGame.mPosX - 1, mGame.mPosY, mGame.mPiece, mGame.mRotation)) {
					mGame.mPosX--;
				}
				break;
			}

			// down key
			case(SDLK_DOWN): {
				if (mBoard.IsPossMove(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation)) {
					mGame.mPosY++;
				}
				break;
			}

			// x key - makes the piece fall
			case(SDLK_x): {
				// check collision in a line
				while (mBoard.IsPossMove(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation)) {
					mGame.mPosY++;
				}

				mBoard.StorePiece(mGame.mPosX, mGame.mPosY - 1, mGame.mPiece, mGame.mRotation);
				mBoard.DelPossLines();

				if (mBoard.IsGameOver()) {
					mIO.GetKey();
					exit(0);
				}

				mGame.CreateNewPiece();
				break;
			}

			// z key - rotates the piece
			case(SDLK_z): {
				if (mBoard.IsPossMove(mGame.mPosX, mGame.mPosY, mGame.mPiece, (mGame.mRotation + 1) % 4)) {
					mGame.mRotation = (mGame.mRotation + 1) % 4;
				}
				break;
			}
		}

		// Vertical Movement
		unsigned long mTime2 = SDL_GetTicks();

		if ((mTime2 - mTime1) > WAIT_TIME) {
			if (mBoard.IsPossMove(mGame.mPosX, mGame.mPosY + 1, mGame.mPiece, mGame.mRotation)) {
				mGame.mPosY++;
			}
			else {
				mBoard.StorePiece(mGame.mPosX, mGame.mPosY, mGame.mPiece, mGame.mRotation);
				mBoard.DelPossLines();

				if (mBoard.IsGameOver()) {
					mIO.GetKey();
					exit(0);
				}

				mGame.CreateNewPiece();
			}

			mTime1 = SDL_GetTicks();
		}
	}

	return 0;
}