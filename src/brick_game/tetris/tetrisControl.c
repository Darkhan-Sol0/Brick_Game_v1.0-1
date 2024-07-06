/**
 * @file tetrisControl.c
 * @brief Only enums
 * @author Thucydil AKA Darkhan_Sol0
 */
#include "../../gui/cli/tetrisUI.h"
#include "defines.h"
#include "fsm.h"
#include "objects.h"
#include "tetris.h"

/**
 * @brief Func commands from keys
 */
void moveFigure(TetKeys key, TetGame* Game) {
  switch (key) {
    case UP:
      if (!Game->pause) {
        rotateFigure(Game);
        Game->moveCount--;
      }
      break;
    case DOWN:
      if (!Game->pause) {
        moveDown(Game);
        Game->moveCount -= 2;
      }
      break;
    case LEFT:
      if (!Game->pause) {
        moveLeft(Game);
        Game->moveCount--;
      }
      break;
    case RIGHT:
      if (!Game->pause) {
        moveRight(Game);
        Game->moveCount--;
      }
      break;
    case SPACE:
      if (!Game->pause) {
        moveOnDeep(Game);
        Game->moveCount--;
      }
      break;
    case PAUSA:
      if (!Game->pause)
        Game->pause = true;
      else
        Game->pause = false;
      break;
    case EXIT:
      Game->state = Game_Over;
      break;
    default:
      break;
  }
}

/**
 * @brief Func rotate figure
 */
void rotateFigure(TetGame* Game) {
  TetColl coll = is_colliding(Game);
  if (coll.RotCol > 2) {
    ;
  } else {
    TetFigure rotFigure;
    createFigure(&rotFigure, Game->figure.type);
    for (int i = 0; i < Game->figure.size; i++)
      for (int j = 0; j < Game->figure.size; j++)
        rotFigure.block[i][Game->figure.size - j - 1] =
            Game->figure.block[j][i];
    take_collide(&rotFigure);
    for (int i = 0; i < Game->figure.size; i++)
      for (int j = 0; j < Game->figure.size; j++)
        Game->figure.block[i][j] = rotFigure.block[i][j];
    freeFigure(&rotFigure);
    while (true) {
      coll = is_colliding(Game);
      if (coll.ColIn) {
        if (coll.ColL && !coll.ColR)
          Game->figure.x_pos++;
        else if (coll.ColR && !coll.ColL)
          Game->figure.x_pos--;
        else if (coll.ColD)
          Game->figure.y_pos--;
      } else
        break;
    }
  }
}

/**
 * @brief func drop figure
 */
void moveOnDeep(TetGame* Game) {
  int can_go = 1;
  while (can_go) can_go = moveDown(Game);
}

/**
 * @brief simple rotate
 */
void justRotate(TetGame* Game) {
  TetFigure rotFigure;
  createFigure(&rotFigure, Game->nextFigure.type);
  for (int i = 0; i < Game->nextFigure.size; i++)
    for (int j = 0; j < Game->nextFigure.size; j++)
      rotFigure.block[i][Game->nextFigure.size - j - 1] =
          Game->nextFigure.block[j][i];
  take_collide(&rotFigure);
  for (int i = 0; i < Game->nextFigure.size; i++)
    for (int j = 0; j < Game->nextFigure.size; j++)
      Game->nextFigure.block[i][j] = rotFigure.block[i][j];
  freeFigure(&rotFigure);
}

/**
 * @brief Func move down
 */
int moveDown(TetGame* Game) {
  int go = 1;
  TetColl col = is_colliding(Game);
  if (col.ColD == 0)
    Game->figure.y_pos += 1;
  else {
    go = 0;
    Game->state = Attaching;
  }
  return go;
}

/**
 * @brief Func move left
 */
void moveLeft(TetGame* Game) {
  TetColl col = is_colliding(Game);
  if (col.ColL == 0) {
    Game->figure.x_pos -= 1;
    col = is_colliding(Game);
    if (col.ColIn) Game->figure.x_pos += 1;
  }
}

/**
 * @brief Func move right
 */
void moveRight(TetGame* Game) {
  TetColl col = is_colliding(Game);
  if (col.ColR == 0) {
    Game->figure.x_pos += 1;
    col = is_colliding(Game);
    if (col.ColIn) Game->figure.x_pos -= 1;
  }
}

/**
 * @brief Func get collide
 */
TetColl is_colliding(TetGame* Game) {
  TetColl result;
  COLLISION_INIT(result);
  for (int i = 0; i < Game->figure.size; i++) {
    for (int j = 0; j < Game->figure.size; j++) {
      if (Game->figure.block[i][j] == ColL &&
          (Game->field.block[Game->figure.y_pos + i][Game->figure.x_pos + j] !=
               0 &&
           Game->field.block[Game->figure.y_pos + i][Game->figure.x_pos + j] !=
               UB)) {
        result.ColL += 1;
        result.x_col = j;
        result.y_col = i;
      }
      if (Game->figure.block[i][j] == ColR &&
          (Game->field.block[Game->figure.y_pos + i][Game->figure.x_pos + j] !=
               0 &&
           Game->field.block[Game->figure.y_pos + i][Game->figure.x_pos + j] !=
               UB)) {
        result.ColR += 1;
        result.x_col = j;
        result.y_col = i;
      }
      if (Game->figure.block[i][j] == ColU &&
          (Game->field.block[Game->figure.y_pos + i][Game->figure.x_pos + j] !=
               0 &&
           Game->field.block[Game->figure.y_pos + i][Game->figure.x_pos + j] !=
               UB)) {
        result.ColU += 1;
        result.x_col = j;
        result.y_col = i;
      }
      if (Game->figure.block[i][j] == ColD &&
          (Game->field.block[Game->figure.y_pos + i][Game->figure.x_pos + j] !=
               0 &&
           Game->field.block[Game->figure.y_pos + i][Game->figure.x_pos + j] !=
               UB)) {
        result.ColD += 1;
        result.x_col = j;
        result.y_col = i;
      }
      if (Game->figure.block[i][j] == Game->figure.type &&
          (Game->field.block[Game->figure.y_pos + i][Game->figure.x_pos + j] !=
               0 &&
           Game->field.block[Game->figure.y_pos + i][Game->figure.x_pos + j] !=
               UB)) {
        result.ColIn += 1;
        result.x_col = j;
        result.y_col = i;
      }
      if (Game->figure.block[i][j] == Game->figure.type &&
          (Game->field.block[Game->figure.y_pos + i][Game->figure.x_pos + j] ==
           UB)) {
        result.ColUP += 1;
        result.x_col = j;
        result.y_col = i;
      }
    }
    if (i >= Game->figure.size / 2 - 1 && i <= Game->figure.size / 2 + 1)
      for (int j = 0; j < Game->figure.size / 2; j++)
        if ((Game->field.block[Game->figure.y_pos + i]
                              [Game->figure.x_pos + j] != 0 &&
             Game->field.block[Game->figure.y_pos + i]
                              [Game->figure.x_pos + j] != UB))
          for (int k = Game->figure.size / 2; k <= j + Game->figure.large; k++)
            if ((Game->field.block[Game->figure.y_pos + i]
                                  [Game->figure.x_pos + k] != 0 &&
                 Game->field.block[Game->figure.y_pos + i]
                                  [Game->figure.x_pos + k] != UB)) {
              result.RotCol += 1;
              j = Game->figure.size;
              break;
            }
  }
  return result;
}

/**
 * @brief Func attaching figure
 */
void FigureAttaching(TetGame* Game) {
  TetColl col = is_colliding(Game);
  int firedLine = 0;
  if (col.ColUP) {
    Game->state = Game_Over;
    Game->exitText = "Game Over";
  } else {
    for (int i = 0; i < Game->figure.size; i++)
      for (int j = 0; j < Game->figure.size; j++)
        if (Game->figure.block[i][j] == Game->figure.type &&
            Game->field.block[Game->figure.y_pos + i][Game->figure.x_pos + j] !=
                UB)
          Game->field.block[Game->figure.y_pos + i][Game->figure.x_pos + j] =
              Game->figure.type;
    firedLine = checkLines(Game);

    LVLCounter(Game, firedLine);
    Game->state = Spawn;
    Game->moveCount = 40;
  }
}

/**
 * @brief Func level counter
 */
void LVLCounter(TetGame* Game, int firedLine) {
  Game->score += 100 * (pow(2, firedLine) - 1);
  if (Game->highscore <= Game->score) Game->highscore = Game->score;
  if (Game->level < 10)
    Game->level = Game->score / Game->ScoreLevel + 1;
  else
    Game->level = 10;
  Game->speed = Game->level * 2;
}

/**
 * @brief Func shift down figure
 */
void downMoveCicle(TetGame* Game) {
  Game->moveCount -= Game->speed;
  if (Game->moveCount <= 0) {
    Game->state = Shifting;
    Game->moveCount = 40;
  }
}
