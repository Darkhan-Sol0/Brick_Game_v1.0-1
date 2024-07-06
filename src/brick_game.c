#include "brick_game/tetris/tetris.h"
#include "gui/cli/tetrisUI.h"

/**  
 * @brief Main function
*/

int main(void) {
  INITWIN;
  TetGame Game;
  GameLoop(&Game);
  endwin();
  return 0;
}