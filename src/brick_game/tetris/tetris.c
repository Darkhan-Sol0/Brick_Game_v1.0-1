/**
 * @file tetris.c
 * @brief main no main
 * @author Thucydil AKA Darkhan_Sol0
 */
#include "tetris.h"

#include "../../gui/cli/tetrisUI.h"
#include "defines.h"
#include "fsm.h"
#include "objects.h"

// int main(void) {
//   INITWIN;
//   TetGame Game;
//   GameLoop(&Game);
//   endwin();
//   return 0;
// }

/**
 * @brief Game loop
 * @arg Game
 */
void GameLoop(TetGame* Game) {
  GAME_INIT(Game);
  Game->fp = fopen("highscore.txt", "r+");
  if (Game->fp) {
    fscanf(Game->fp, "%d", &Game->highscore);
    fclose(Game->fp);
  }
  while (Game->play) {
    clear();
    StateMachine(Game);
    refresh();
  }
  GameOver(Game);
  FREE_ALL(Game);
}
/**
 * @brief GameOver function
 * @arg Game
 */
void GameOver(TetGame* Game) {
  cbreak();
  clear();
  Game->fp = fopen("highscore.txt", "w+");
  fprintf(Game->fp, "%d", Game->highscore);
  fclose(Game->fp);
  GoodByePrint(Game);
  getch();
}
/**
 * @brief StateMachine
 * @arg Game
 */
void StateMachine(TetGame* Game) {
  switch (Game->state) {
    case Start:
      WelcomePrint();
      getch();
      Game->state = Spawn;
      halfdelay(1);
      break;
    case Spawn:
      SPAWNER(Game);
      Game->state = Moveing;
      while (is_colliding(Game).ColUP > 0 && moveDown(Game))
        ;
      break;
    case Moveing:
      GUIShow(Game);
      downMoveCicle(Game);
      TetKeys key = getch();
      moveFigure(key, Game);
      break;
    case Shifting:
      int can_go = 1;
      if (!Game->pause) can_go = moveDown(Game);
      if (can_go) Game->state = Moveing;
      break;
    case Attaching:
      FigureAttaching(Game);
      break;
    case Game_Over:
      Game->play = false;
      break;
    default:
      break;
  }
}
