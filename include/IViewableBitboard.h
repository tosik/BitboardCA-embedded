#ifndef _INCLUDE_GUARD_UUID_72DEF3EC_EA23_4B91_863C_C2F8C8D499D1_
#define _INCLUDE_GUARD_UUID_72DEF3EC_EA23_4B91_863C_C2F8C8D499D1_

#include "bbcommon.h"

namespace BitboardCA {
/** Viewable Bitboard interface */
class IViewableBitboard {
public:
  /** get board size of x */
  virtual unsigned int GetSizeX() const = 0;

  /** get board size of y */
  virtual unsigned int GetSizeY() const = 0;

  /** get a state of cell */
  virtual unsigned int GetCellState(unsigned int x, unsigned int y) const = 0;
};

class IBitboard : public IViewableBitboard {
public:
  virtual void SetCellState(bool cell, unsigned int x, unsigned int y) = 0;
};

} // namespace BitboardCA

#endif
