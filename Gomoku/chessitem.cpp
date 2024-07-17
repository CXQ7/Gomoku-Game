#include "chessitem.h"

ChessItem::ChessItem(void) {}

ChessItem::ChessItem(QPoint point, bool isBluck)
{
    _pt = point;
    _black = isBluck;
}
