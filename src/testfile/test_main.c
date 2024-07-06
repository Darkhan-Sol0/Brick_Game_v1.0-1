#include "test_main.h"

int main(void) {
  int failed = 0;
  Suite *s21_tetris_test[] = {test_createFigure(), test_move_rot(),
                              test_GameLoop(), NULL};

  for (int i = 0; s21_tetris_test[i] != NULL; i++) {
    SRunner *sr = srunner_create(s21_tetris_test[i]);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);
    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);
  return failed;
}
