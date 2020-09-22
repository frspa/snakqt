#include <bertrand/bertrand.hpp>
#include <board.hpp>

namespace boardspace {

CellType Board::getCellTpye(Boardcell position) const {

  { // design by contract
    Require(isPositionValid(position) == true, "Position is on the board");
  }
  return board_.at(position.XPosition_).at(position.YPosition_);
}

void Board::setCellType(Boardcell position, CellType newType) {

  { // design by contract
    Require(isPositionValid(position) == true, "Position is on the board");
  }

  board_.at(position.XPosition_).at(position.YPosition_) = newType;
}

bool Board::isPositionValid(Boardcell toCheck) const {

  if (toCheck.XPosition_ > boardsize_ || toCheck.YPosition_ > boardsize_) {
    return false;
  } else {
    return true;
  }
}

} // namespace boardspace
