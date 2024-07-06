#include "test_main.h"

START_TEST(move_rot_1) {
  TetGame Game;
  createFigure(&Game.figure, 1);
  createField(&Game.field);
  Game.figure.x_pos = startPosX + 8 - Game.figure.large;
  Game.figure.y_pos = startPosY;
  moveFigure(UP, &Game);
  moveFigure(0, &Game);
  freeFigure(&Game.figure);
  freeField(&Game.field);
}
END_TEST

START_TEST(move_rot_2) {
  TetGame Game;
  createFigure(&Game.figure, 1);
  createField(&Game.field);
  Game.figure.x_pos = startPosX + 8 - Game.figure.large;
  Game.figure.y_pos = startPosY;
  moveFigure(DOWN, &Game);
  freeFigure(&Game.figure);
  freeField(&Game.field);
}
END_TEST

START_TEST(move_rot_3) {
  TetGame Game;
  createFigure(&Game.figure, 1);
  createField(&Game.field);
  Game.figure.x_pos = startPosX + 8 - Game.figure.large;
  Game.figure.y_pos = startPosY;
  for (int i = 0; i < 6; i++) moveFigure(LEFT, &Game);
  moveFigure(UP, &Game);
  freeFigure(&Game.figure);
  freeField(&Game.field);
}
END_TEST

START_TEST(move_rot_4) {
  TetGame Game;
  createFigure(&Game.figure, 1);
  createField(&Game.field);
  Game.figure.x_pos = startPosX + 8 - Game.figure.large;
  Game.figure.y_pos = startPosY;
  for (int i = 0; i < 6; i++) moveFigure(RIGHT, &Game);
  moveFigure(UP, &Game);
  freeFigure(&Game.figure);
  freeField(&Game.field);
}
END_TEST

START_TEST(move_rot_5) {
  TetGame Game;
  createFigure(&Game.figure, 1);
  createFigure(&Game.nextFigure, 2);
  createField(&Game.field);
  justRotate(&Game);
  Game.figure.x_pos = startPosX + 8 - Game.figure.large;
  Game.figure.y_pos = startPosY;
  moveFigure(SPACE, &Game);
  freeFigure(&Game.figure);
  freeFigure(&Game.nextFigure);
  freeField(&Game.field);
}
END_TEST

START_TEST(move_rot_6) {
  TetGame Game;
  createFigure(&Game.figure, 1);
  createField(&Game.field);
  Game.figure.x_pos = startPosX + 8 - Game.figure.large;
  Game.figure.y_pos = startPosY;
  moveFigure(PAUSA, &Game);
  PausePrint();
  moveFigure(PAUSA, &Game);
  moveFigure(EXIT, &Game);
  freeFigure(&Game.figure);
  freeField(&Game.field);
}
END_TEST

START_TEST(move_rot_7) {
  TetGame Game;
  createFigure(&Game.figure, 1);
  createField(&Game.field);
  Game.figure.x_pos = startPosX + 8 - Game.figure.large;
  Game.figure.y_pos = startPosY;
  downMoveCicle(&Game);
  downMoveCicle(&Game);
  downMoveCicle(&Game);
  freeFigure(&Game.figure);
  freeField(&Game.field);
}
END_TEST

START_TEST(move_rot_8) {
  TetGame Game;
  createFigure(&Game.figure, 1);
  createField(&Game.field);
  Game.figure.x_pos = startPosX + 8 - Game.figure.large;
  Game.figure.y_pos = startPosY + 10;
  FigureAttaching(&Game);
  freeFigure(&Game.figure);
  freeField(&Game.field);
}
END_TEST

START_TEST(move_rot_9) {
  TetGame Game;
  createFigure(&Game.figure, 1);
  createField(&Game.field);
  Game.figure.x_pos = startPosX + 8 - Game.figure.large;
  Game.figure.y_pos = startPosY;
  FigureAttaching(&Game);
  freeFigure(&Game.figure);
  freeField(&Game.field);
}
END_TEST

START_TEST(move_rot_10) {
  TetGame Game;
  createField(&Game.field);
  clearLine(&Game, 10);
  freeField(&Game.field);
}
END_TEST

Suite* test_move_rot(void) {
  Suite* s = suite_create("move_rot");
  TCase* tc = tcase_create("move_rot_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, move_rot_1);
  tcase_add_test(tc, move_rot_2);
  tcase_add_test(tc, move_rot_3);
  tcase_add_test(tc, move_rot_4);
  tcase_add_test(tc, move_rot_5);
  tcase_add_test(tc, move_rot_6);
  tcase_add_test(tc, move_rot_7);
  tcase_add_test(tc, move_rot_8);
  tcase_add_test(tc, move_rot_9);
  tcase_add_test(tc, move_rot_10);
  // tcase_add_test(tc, move_rot_11);
  return s;
}
