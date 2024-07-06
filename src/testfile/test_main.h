#ifndef SRC_TESTS_MAIN_H
#define SRC_TESTS_MAIN_H

#include <check.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

#include "../brick_game/tetris/defines.h"
#include "../brick_game/tetris/fsm.h"
#include "../brick_game/tetris/objects.h"
#include "../brick_game/tetris/tetris.h"
#include "../gui/cli/tetrisUI.h"

//-----Figure-----
Suite *test_createFigure(void);
Suite *test_move_rot(void);
Suite *test_GameLoop(void);
Suite *test_GUI(void);

#endif  // SRC_TESTS_MAIN_H
