#ifndef TETRIS_UI_H
#define TETRIS_UI_H

#include "../../brick_game/tetris/tetris.h"

#define windowHeigth 23
#define windowWidth 12

#define shiftX 2
#define shiftY 4

#define nextFPosX 31
#define nextFPosY 12

#define COLOR_INITED                        \
  init_pair(I, 124, COLOR_BLACK);           \
  init_pair(L, 220, COLOR_BLACK);           \
  init_pair(J, 166, COLOR_BLACK);           \
  init_pair(S, 34, COLOR_BLACK);            \
  init_pair(Z, 99, COLOR_BLACK);            \
  init_pair(T, 27, COLOR_BLACK);            \
  init_pair(O, 165, COLOR_BLACK);           \
  init_pair(LB, COLOR_WHITE, COLOR_BLACK);  \
  init_pair(RB, COLOR_WHITE, COLOR_BLACK);  \
  init_pair(UB, COLOR_WHITE, COLOR_BLACK);  \
  init_pair(DB, COLOR_WHITE, COLOR_BLACK);  \
  init_pair(101, COLOR_BLACK, 196);         \
  init_pair(102, COLOR_BLACK, COLOR_BLACK); \
  init_pair(103, COLOR_WHITE, COLOR_BLACK);

#endif /* TETRIS_UI_H */