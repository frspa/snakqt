#include <board.hpp>
#include <bertrand/bertrand.hpp>

namespace boardspace {

CellType Board::getCellTpye(Boardcell position) const {

  // Require
  Q_ASSERT(isPositionValid(position));

  return board_.at(position.XPosition_).at(position.YPosition_);
}

void Board::setCellType(Boardcell position, CellType newType) {

  // Require
  Q_ASSERT(isPositionValid(position));

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
