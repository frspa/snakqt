#include <bertrand/bertrand.hpp>

#include <startup.hpp>

#include <QtMath>

namespace boardspace {

void setInitialFruit(Board *gameBoard) {

  uint center = static_cast<uint>(qFloor(gameBoard->getBoardsize() / 2));
  Boardcell cellCenter{center, center};
  gameBoard->setCellType(cellCenter, CellType::FRUIT);

  { // design by contract
    Require(gameBoard->getCellTpye(cellCenter) == CellType::FRUIT,
            "Gameboard center has a fruit");
  }
}

} // namespace boardspace
