#include "../../gui/cli/tetrisUI.h"
#include "defines.h"
#include "fsm.h"
#include "objects.h"
#include "tetris.h"

void createField(TetField* field) {
  field->height = fieldHeigth;
  field->width = fieldWidth;
  field->block = (TetBlockType**)calloc(fieldHeigth, sizeof(TetBlockType*));
  for (int i = 0; i < field->height; i++)
    field->block[i] = (TetBlockType*)calloc(fieldWidth, sizeof(TetBlockType));

  for (int i = 0; i < field->height; i++) {
    for (int j = 0; j < field->width; j++) {
      if (j <= 2)
        field->block[i][j] = LB;
      else if (j >= fieldWidth - 3)
        field->block[i][j] = RB;
      else if (i <= 4)
        field->block[i][j] = UB;
      else if (i >= fieldHeigth - 4)
        field->block[i][j] = DB;
    }
  }
}

void freeField(TetField* field) {
  for (int i = 0; i < field->height; i++) free(field->block[i]);
  free(field->block);
}

int checkLines(TetGame* Game) {
  int lines = 0;
  for (int i = 0; i <= 20; i++) {
    int columns = 0;
    for (int j = 0; j < 10; j++) {
      if (Game->field.block[i + 5][j + 3] == 0) break;
      columns++;
    }
    if (columns >= 10) {
      clearLine(Game, i);
      lines++;
    }
  }
  return lines;
}

void clearLine(TetGame* Game, int line) {
  for (int i = line; i >= 0; i--)
    for (int j = 0; j < fieldWidth - 6; j++)
      if (i == 0)
        Game->field.block[i + 5][j + 3] = 0;
      else
        Game->field.block[i + 5][j + 3] = Game->field.block[i + 5 - 1][j + 3];
}
