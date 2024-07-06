#include "../../gui/cli/tetrisUI.h"
#include "defines.h"
#include "fsm.h"
#include "objects.h"
#include "tetris.h"

void createFigure(TetFigure* figure, TetBlockType type) {
  if (type == I) {
    figure->size = 8;
    figure->large = 4;
  } else if (type == O) {
    figure->size = 4;
    figure->large = 2;
  } else if (type >= L && type <= T) {
    figure->size = 5;
    figure->large = 3;
  }
  figure->type = type;
  figure->x_pos = 0;
  figure->y_pos = 0;
  figure->block = (TetBlockType**)calloc(figure->size, sizeof(TetBlockType*));
  for (int i = 0; i < figure->size; i++)
    figure->block[i] =
        (TetBlockType*)calloc(figure->size, sizeof(TetBlockType));

  switch (type) {
    case I:
      INIT_FIGURE_I(figure)
      break;
    case S:
      INIT_FIGURE_S(figure)
      break;
    case Z:
      INIT_FIGURE_Z(figure)
      break;
    case T:
      INIT_FIGURE_T(figure)
      break;
    case L:
      INIT_FIGURE_L(figure)
      break;
    case J:
      INIT_FIGURE_J(figure)
      break;
    case O:
      INIT_FIGURE_O(figure)
      break;
    default:
      break;
  }
  take_collide(figure);
}

void take_collide(TetFigure* figure) {
  for (int i = figure->size - 1; i >= 0; i--)
    for (int j = 0; j < figure->size; j++)
      if (figure->block[i][j] == figure->type) {
        if (figure->block[i][j + 1] != figure->type) {
          figure->block[i][j + 1] = ColR;
        }
        if (figure->block[i][j - 1] != figure->type) {
          figure->block[i][j - 1] = ColL;
        }
        if (figure->block[i + 1][j] != figure->type) {
          figure->block[i + 1][j] = ColD;
        }
        if (figure->block[i - 1][j] != figure->type) {
          figure->block[i - 1][j] = ColU;
        }
      }
}

void freeFigure(TetFigure* figure) {
  for (int i = 0; i < figure->size; i++) {
    free(figure->block[i]);
  }
  free(figure->block);
}