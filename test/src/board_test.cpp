#include <QTest>
#include <board.hpp>
#include <gmock/gmock.h>

namespace {

TEST(BoardTest, GIVEN_Board_WHEN_is_initialized_THEN_Board_is_completly_empty) {

  // setup
  uint boardsize = 10;
  boardspace::Board testboard(boardsize);

  // test
  bool allEmpty = false;
  for (uint x = 0; x < boardsize; x++) {
    for (uint y = 0; y < boardsize; y++) {
      boardspace::Boardcell toCheck{x, y};
      if (testboard.getCellTpye(toCheck) != boardspace::CellType::EMPTY) {
        allEmpty = true;
        break;
      }
    }
  }

  // verification
  EXPECT_FALSE(allEmpty);
}

TEST(BoardTest,
     GIVEN_Board_WHEN_Celltype_is_set_THEN_correct_Celltype_is_retrieved) {

  // setup
  uint boardsize = 10;
  boardspace::Board testboard(boardsize);

  // test
  boardspace::Boardcell centerCell{uint(5), uint(5)};
  testboard.setCellType(centerCell, boardspace::CellType::FRUIT);
  boardspace::Boardcell edgeCell{uint(9), uint(0)};
  testboard.setCellType(edgeCell, boardspace::CellType::SNAKE);

  // verification
  EXPECT_EQ(boardspace::CellType::FRUIT, testboard.getCellTpye(centerCell));
  EXPECT_EQ(boardspace::CellType::SNAKE, testboard.getCellTpye(edgeCell));

}

} // namespace
