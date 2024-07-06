#include "tetrisUI.h"

void GUIShow(TetGame *Game) {
  start_color();
  COLOR_INITED;
  bkgd(COLOR_PAIR(102));
  showFigure(Game);
  showGame(Game);
  showStats(Game);
  showNextFigure(Game);
  if (Game->pause) PausePrint();
}

void WelcomePrint() {
  mvprintw(5, 11, "TETRIS by thucydil");
  mvprintw(10, 10, "Press 'F' for the START");
  mvprintw(11, 9, "________________________");
  mvaddch(12, 14, ACS_LARROW);
  mvprintw(12, 15, " - move left");
  mvaddch(13, 14, ACS_RARROW);
  mvprintw(13, 15, " - move right");
  mvaddch(14, 14, ACS_UARROW);
  mvprintw(14, 15, " - rotate");
  mvaddch(15, 14, ACS_DARROW);
  mvprintw(15, 15, " - move down");
  mvprintw(16, 10, "SPACE - drop down");
  mvprintw(17, 14, "P - pause");
  mvprintw(18, 14, "Q - quit");
}

void PausePrint() {
  attron(COLOR_PAIR(101));
  mvprintw(9, 10, "%s", "         ");
  mvprintw(10, 10, "%s", "  PAUSE  ");
  mvprintw(11, 10, "%s", "         ");
  attroff(COLOR_PAIR(101));
}

void showStats(TetGame *Game) {
  attron(COLOR_PAIR(103));
  mvprintw(0, 10, "TETRIS by thucydil");
  mvprintw(2, 30, "High Score: %d", Game->highscore);
  mvprintw(4, 30, "Your Score: %d", Game->score);
  mvprintw(6, 30, "Level: %d", Game->level);
  mvprintw(8, 30, "Speed: %d", Game->speed);
  attroff(COLOR_PAIR(103));
}

void GoodByePrint(TetGame *Game) {
  attron(COLOR_PAIR(103));
  mvprintw(10, 10, "%s \n\tYour Score: %d", Game->exitText, Game->score);
  attroff(COLOR_PAIR(103));
}

void showFigure(TetGame *Game) {
  int k = 0;
  attron(COLOR_PAIR(Game->figure.type));
  for (int i = 0; i < Game->figure.size; i++) {
    for (int j = 0; j < Game->figure.size; j++) {
      if (Game->figure.block[i][j] == Game->figure.type) {
        mvaddch(i + Game->figure.y_pos - shiftY + 1,
                j + Game->figure.x_pos * 2 + k - shiftX, '[');
        mvaddch(i + Game->figure.y_pos - shiftY + 1,
                j + Game->figure.x_pos * 2 + k + 1 - shiftX, ']');
      }
      k++;
    }
    k = 0;
  }
  attroff(COLOR_PAIR(Game->figure.type));
}

void showNextFigure(TetGame *Game) {
  int k = 0;
  int shift = (Game->nextFigure.size - Game->nextFigure.large) / 2;
  mvprintw(10, 30, "Next: ");
  attron(COLOR_PAIR(Game->nextFigure.type));
  for (int i = 0; i <= Game->nextFigure.large; i++) {
    for (int j = 0; j <= Game->nextFigure.large; j++) {
      if (Game->nextFigure.block[i + shift][j + shift] ==
          Game->nextFigure.type) {
        mvaddch(i + nextFPosY, j + nextFPosX + k, '[');
        mvaddch(i + nextFPosY, j + nextFPosX + k + 1, ']');
      }
      k++;
    }
    k = 0;
  }
  attroff(COLOR_PAIR(Game->nextFigure.type));
}

void showGame(TetGame *Game) {
  int k = 0;
  chtype fl1, fl2;

  for (int i = 0; i < windowHeigth; i++) {
    for (int j = 0; j < windowWidth; j++) {
      if (Game->field.block[i + shiftY][j + shiftX] == 0) {
        fl1 = ' ';
        fl2 = ' ';
      } else if (Game->field.block[i + shiftY][j + shiftX] == LB) {
        fl1 = ' ';
        fl2 = ACS_VLINE;
      } else if (Game->field.block[i + shiftY][j + shiftX] == RB) {
        fl1 = ACS_VLINE;
        fl2 = ' ';
      } else if (Game->field.block[i + shiftY][j + shiftX] == DB) {
        fl1 = ACS_HLINE;
        fl2 = ACS_HLINE;
      } else if (Game->field.block[i + shiftY][j + shiftX] == UB) {
        fl1 = ACS_HLINE;
        fl2 = ACS_HLINE;
      } else {
        fl1 = '[';
        fl2 = ']';
      }
      if (i == 0 && j == 0) {
        fl1 = ' ';
        fl2 = ACS_ULCORNER;
      }
      if (i == windowHeigth - 1 && j == 0) {
        fl1 = ' ';
        fl2 = ACS_LLCORNER;
      }
      if (i == 0 && j == windowWidth - 1) {
        fl1 = ACS_URCORNER;
        fl2 = ' ';
      }
      if (i == windowHeigth - 1 && j == windowWidth - 1) {
        fl1 = ACS_LRCORNER;
        fl2 = ' ';
      }
      if (Game->field.block[i + shiftY][j + shiftX] != 0) {
        attron(COLOR_PAIR(Game->field.block[i + shiftY][j + shiftX]));
        mvaddch(i + Game->y_pos + 1, j + Game->x_pos * 2 + shiftX + k, fl1);
        mvaddch(i + Game->y_pos + 1, j + Game->x_pos * 2 + shiftX + k + 1, fl2);
        attroff(COLOR_PAIR(Game->field.block[i + shiftY][j + shiftX]));
      }
      k++;
    }
    k = 0;
  }
}