#pragma once

#include <QMap>
#include <QString>
#include <QObject>

namespace boardspace {

inline namespace celltype {
Q_NAMESPACE
enum class CellType { FRUIT, SNAKE, EMPTY };
Q_ENUM_NS(CellType)
} // namespace celltype

struct Boardcell {
  //Origin is on upper left corner of board
  int XPosition_{0};
  int YPosition_{0};
};

struct Boardmap {
  QMap<Boardcell, CellType> boardMap;
};

class Board final {
public:
  Board();
  ~Board() = default;

  CellType getCellTpye(Boardcell position) const;

  Boardmap getBoard() const;


private:
  Boardmap board_;

};

} // namespace boardspace
