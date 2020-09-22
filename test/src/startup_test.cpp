#include <QTest>
#include <QtMath>

#include <board.hpp>
#include <startup.hpp>

#include <gmock/gmock.h>

namespace {

TEST(
    StartupTest,
    GIVEN_Startup_process_WHEN_after_gameboard_is_initialized_THEN_only_one_fruit_is_available) {

  // setup
  uint boardsize = 10;
  boardspace::Board testboard(boardsize);

  // test
  boardspace::setInitialFruit(&testboard);

  // verification

  uint fruitCounter = 0;
  for (uint x = 0; x < boardsize; x++) {
    for (uint y = 0; y < boardsize; y++) {
      boardspace::Boardcell toCheck{x, y};
      if (testboard.getCellTpye(toCheck) == boardspace::CellType::FRUIT) {
        ++fruitCounter;
      }
    }
  }

  EXPECT_EQ(fruitCounter, 1);
}

TEST(
    StartupTest,
    GIVEN_Startup_process_WHEN_after_gameboard_is_initialized_THEN_at_floored_center_is_a_fruit) {

  // setup
  uint boardsize = 10;
  boardspace::Board testboard(boardsize);

  // test
  boardspace::setInitialFruit(&testboard);

  // verification
  uint center = static_cast<uint>(qFloor(testboard.getBoardsize() / 2));
  boardspace::Boardcell centerCell{center, center};

  EXPECT_EQ(testboard.getCellTpye(centerCell), boardspace::CellType::FRUIT);
}

} // namespace
