/**
 * @file tetris.h
 * @brief Main header file
 * @author Thucydil AKA Darkhan_Sol0
 */
#ifndef TETRIS_H
#define TETRIS_H

#include <math.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../gui/cli/tetrisUI.h"
#include "defines.h"
#include "fsm.h"
#include "objects.h"

//-----Figure-----
void createFigure(TetFigure* figure, TetBlockType type);
void freeFigure(TetFigure* figure);
void rotateFigure(TetGame* Game);
void take_collide(TetFigure* figure);
void spawnFigure(TetGame* Game);
void justRotate(TetGame* Game);
//-----Field-----
void createField(TetField* field);
void freeField(TetField* field);
void FigureAttaching(TetGame* Game);
int checkLines(TetGame* Game);
void clearLine(TetGame* Game, int line);
//-----Game-----
void GameLoop(TetGame* Game);
void moveFigure(TetKeys key, TetGame* Game);
void gameInit(TetGame* Game);
int moveDown(TetGame* Game);
void moveLeft(TetGame* Game);
void moveRight(TetGame* Game);
void moveOnDeep(TetGame* Game);
TetColl is_colliding(TetGame* Game);
void downMoveCicle(TetGame* Game);
void GameOver(TetGame* Game);
void LVLCounter(TetGame* Game, int firedLine);
void StateMachine(TetGame* Game);
//-----show-----
void GUIShow(TetGame* Game);
void showFigure(TetGame* Game);
void showGame(TetGame* Game);
void showNextFigure(TetGame* Game);
void WelcomePrint();
void showStats(TetGame* Game);
void PausePrint();
void GoodByePrint(TetGame* Game);

#endif /* TETRIS_H */