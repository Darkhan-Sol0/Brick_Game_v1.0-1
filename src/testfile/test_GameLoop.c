#include "test_main.h"

START_TEST(GameLoop_1) {
  TetGame Game;
  GameLoop(&Game);
}
END_TEST

Suite* test_GameLoop(void) {
  Suite* s = suite_create("GameLoop");
  TCase* tc = tcase_create("GameLoop_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, GameLoop_1);
  // tcase_add_test(tc, GameLoop_2);
  // tcase_add_test(tc, GameLoop_3);
  // tcase_add_test(tc, GameLoop_4);
  // tcase_add_test(tc, GameLoop_5);
  // tcase_add_test(tc, GameLoop_6);
  // tcase_add_test(tc, GameLoop_7);
  // tcase_add_test(tc, GameLoop_8);
  // tcase_add_test(tc, GameLoop_9);
  // tcase_add_test(tc, GameLoop_10);
  // tcase_add_test(tc, GameLoop_11);
  return s;
}
