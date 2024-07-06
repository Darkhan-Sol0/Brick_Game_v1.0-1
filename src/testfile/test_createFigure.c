#include "test_main.h"

START_TEST(createFigute_1) {
  printf("1");
  TetGame Game;
  TetBlockType type = I;
  createFigure(&Game.figure, type);
  printf("1");
  freeFigure(&Game.figure);
  printf("1\n");
}
END_TEST

START_TEST(createFigute_2) {
  printf("2");
  TetGame Game;
  TetBlockType type = L;
  createFigure(&Game.figure, type);
  printf("2");
  freeFigure(&Game.figure);
  printf("2\n");
}
END_TEST

START_TEST(createFigute_3) {
  printf("3");
  TetGame Game;
  TetBlockType type = J;
  createFigure(&Game.figure, type);
  printf("3");
  freeFigure(&Game.figure);
  printf("3\n");
}
END_TEST

START_TEST(createFigute_4) {
  printf("4");
  TetGame Game;
  TetBlockType type = S;
  createFigure(&Game.figure, type);
  printf("4");
  freeFigure(&Game.figure);
  printf("4\n");
}
END_TEST

START_TEST(createFigute_5) {
  printf("5");
  TetGame Game;
  TetBlockType type = Z;
  createFigure(&Game.figure, type);
  printf("5");
  freeFigure(&Game.figure);
  printf("5\n");
}
END_TEST

START_TEST(createFigute_6) {
  printf("6");
  TetGame Game;
  TetBlockType type = T;
  createFigure(&Game.figure, type);
  printf("6");
  freeFigure(&Game.figure);
  printf("6\n");
}
END_TEST

START_TEST(createFigute_7) {
  printf("7");
  TetGame Game;
  TetBlockType type = O;
  createFigure(&Game.figure, type);
  printf("7");
  freeFigure(&Game.figure);
  printf("7\n");
}
END_TEST

// START_TEST(createFigute_8) {
//   printf("8");
//   TetGame Game;
//   TetBlockType type = 0;
//   createFigure(&Game.figure, type);
//   printf("8");
//   freeFigure(&Game.figure);
//   printf("8\n");
// }
// END_TEST

Suite* test_createFigure(void) {
  Suite* s = suite_create("createFigute");
  TCase* tc = tcase_create("createFigute_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, createFigute_1);
  tcase_add_test(tc, createFigute_2);
  tcase_add_test(tc, createFigute_3);
  tcase_add_test(tc, createFigute_4);
  tcase_add_test(tc, createFigute_5);
  tcase_add_test(tc, createFigute_6);
  tcase_add_test(tc, createFigute_7);
  // tcase_add_test(tc, createFigute_8);
  // tcase_add_test(tc, createFigute_9);
  // tcase_add_test(tc, createFigute_10);
  // tcase_add_test(tc, createFigute_11);
  return s;
}
