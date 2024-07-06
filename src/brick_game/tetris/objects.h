/**
 * @file objects.h
 * @brief Only structs
 * @author Thucydil AKA Darkhan_Sol0
 */
#ifndef OBJECTS_H
#define OBJECTS_H

#include "tetris.h"

/**
 * @brief Struct of field
 */
typedef struct {
  int height;
  int width;
  TetBlockType** block;
  TetBlockType type;
} TetField;

/**
 * @brief Struct of figure
 */
typedef struct {
  int x_pos;
  int y_pos;
  int size;
  int large;
  TetBlockType type;
  TetBlockType** block;
} TetFigure;

/**
 * @brief Struct of collision
 */
typedef struct {
  int ColL;
  int ColR;
  int ColU;
  int ColD;
  int ColIn;
  int ColUP;
  int RotCol;
  int x_col;
  int y_col;
} TetColl;

/**
 * @brief Struct main of game info
 */
typedef struct {
  bool play;
  int x_pos;
  int y_pos;
  TetField field;
  TetFigure figure;
  TetFigure nextFigure;
  int level;
  int score;
  int highscore;
  int speed;
  int moveCount;
  int ScoreLevel;
  char* exitText;
  bool pause;
  FILE* fp;
  GameStateMachine state;
} TetGame;

#endif /* OBJECTS_H */