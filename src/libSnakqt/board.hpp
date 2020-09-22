#pragma once

#include <QMap>
#include <QObject>
#include <QString>

#include <vector>

namespace boardspace {

inline namespace celltype {
Q_NAMESPACE
enum class CellType { FRUIT, SNAKE, EMPTY };
Q_ENUM_NS(CellType)
} // namespace celltype

struct Boardcell {
  // Origin is on upper left corner of board
  uint XPosition_{0};
  uint YPosition_{0};
};

class Board final {
public:
  Board(uint boardsize)
      : board_(boardsize, std::vector<CellType>(boardsize, CellType::EMPTY)),
        boardsize_(boardsize) {}
  ~Board() = default;

  CellType getCellTpye(Boardcell position) const;
  void setCellType(Boardcell position, CellType newType);
  uint getBoardsize() const {return boardsize_;}

private:
  bool isPositionValid(Boardcell toCheck) const;
  std::vector<std::vector<CellType>> board_;
  uint boardsize_;
};

} // namespace boardspace
