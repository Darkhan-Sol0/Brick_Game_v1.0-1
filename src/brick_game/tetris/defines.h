/**
 * @file defines.h
 * @brief Only defines
 * @author Thucydil AKA Darkhan_Sol0
 */
#ifndef DEFINES_H
#define DEFINES_H

#include "tetris.h"

#define fieldHeigth 30
#define fieldWidth 16

#define fieldPosX 0
#define fieldPosY 0

#define startPosX 0
#define startPosY 0

#define INITWIN         \
  srand(time(NULL));    \
  initscr();            \
  keypad(stdscr, true); \
  noecho();             \
  curs_set(0);

#define GAME_INIT(Game)                        \
  Game->play = true;                           \
  Game->x_pos = fieldPosX;                     \
  Game->y_pos = fieldPosY;                     \
  Game->level = 1;                             \
  Game->score = 0;                             \
  Game->speed = Game->level * 2;               \
  Game->moveCount = 40;                        \
  Game->ScoreLevel = 600;                      \
  Game->exitText = "Good bye!";                \
  Game->state = Start;                         \
  Game->highscore = 0;                         \
  Game->pause = false;                         \
  createFigure(&Game->nextFigure, randFigure); \
  createField(&Game->field);

#define FREE_ALL(Game)       \
  freeField(&Game->field);   \
  freeFigure(&Game->figure); \
  freeFigure(&Game->nextFigure);

#define randFigure rand() % 7 + 1

#define SPAWNER(Game)                                      \
  Game->figure = Game->nextFigure;                         \
  Game->figure.x_pos = startPosX + 8 - Game->figure.large; \
  Game->figure.y_pos = startPosY;                          \
  createFigure(&Game->nextFigure, randFigure);             \
  if (Game->nextFigure.type == Game->figure.type)          \
    createFigure(&Game->nextFigure, randFigure);           \
  for (int i = 0; i < rand() % 4; i++) ROTATION_START(Game);

#define ROTATION_START(Game) justRotate(Game);

#define COLLISION_INIT(result) \
  result.ColL = 0;             \
  result.ColR = 0;             \
  result.ColD = 0;             \
  result.ColU = 0;             \
  result.ColIn = 0;            \
  result.ColUP = 0;            \
  result.RotCol = 0;           \
  result.x_col = 0;            \
  result.y_col = 0;

#define INIT_FIGURE_I(figure) \
  figure->block[2][3] = type; \
  figure->block[3][3] = type; \
  figure->block[4][3] = type; \
  figure->block[5][3] = type;

#define INIT_FIGURE_S(figure) \
  figure->block[1][2] = type; \
  figure->block[2][2] = type; \
  figure->block[2][3] = type; \
  figure->block[3][3] = type;

#define INIT_FIGURE_Z(figure) \
  figure->block[1][2] = type; \
  figure->block[2][2] = type; \
  figure->block[2][1] = type; \
  figure->block[3][1] = type;

#define INIT_FIGURE_T(figure) \
  figure->block[1][2] = type; \
  figure->block[2][1] = type; \
  figure->block[2][2] = type; \
  figure->block[2][3] = type;

#define INIT_FIGURE_L(figure) \
  figure->block[1][2] = type; \
  figure->block[2][2] = type; \
  figure->block[3][2] = type; \
  figure->block[3][3] = type;

#define INIT_FIGURE_J(figure) \
  figure->block[1][2] = type; \
  figure->block[2][2] = type; \
  figure->block[3][2] = type; \
  figure->block[3][1] = type;

#define INIT_FIGURE_O(figure) \
  figure->block[1][1] = type; \
  figure->block[1][2] = type; \
  figure->block[2][1] = type; \
  figure->block[2][2] = type;

#endif /* DEFINES_H */