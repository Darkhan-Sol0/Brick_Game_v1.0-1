/**
 * @file fsm.h
 * @brief Only enums
 * @author Thucydil AKA Darkhan_Sol0
 */
#ifndef FSM_H
#define FSM_H

#include "tetris.h"
/**
 * @brief Enum types blocks
 */
typedef enum {
  I = 1,
  L = 2,
  J = 3,
  S = 4,
  Z = 5,
  T = 6,
  O = 7,

  LB = 8,
  RB = 9,
  UB = 10,
  DB = 11,

  ColL = 12,
  ColR = 13,
  ColU = 14,
  ColD = 15,
} TetBlockType;
/**
 * @brief Enum keys command
 */
typedef enum {
  UP = KEY_UP,
  DOWN = KEY_DOWN,
  LEFT = KEY_LEFT,
  RIGHT = KEY_RIGHT,
  SPACE = ' ',
  PAUSA = 'p',
  EXIT = 'q',
} TetKeys;
/**
 * @brief Enum state of game
 */
typedef enum {
  Start = 0,
  Spawn = 1,
  Moveing = 2,
  Shifting = 3,
  Attaching = 4,
  Pause = 5,
  Game_Over = 6,
} GameStateMachine;

#endif /* FSM_H */