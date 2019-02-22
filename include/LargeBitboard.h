#ifndef _INCLUDE_GUARD_UUID_DDF88100_C0C9_45C7_A597_ABB0A3EAF1FF_
#define _INCLUDE_GUARD_UUID_DDF88100_C0C9_45C7_A597_ABB0A3EAF1FF_

#include "IViewableBitboard.h"
#include "bbcommon.h"

namespace BitboardCA {

/** Large Bitboard class */
class LargeBitboard : public IBitboard {
protected:
  /** size of board */
  unsigned int m_SizeX, m_SizeY;

  /** number of bitboard */
  unsigned int m_BitboardSizeX, m_BitboardSizeY;

  /** bitboard array */
  Bitboard *m_BitboardList;

public:
  /** constructor */
  LargeBitboard(unsigned int size_x, unsigned int size_y,
                bool direct_size_mode = false);

  /** destructor */
  virtual ~LargeBitboard();

  /** get board size of x */
  unsigned int GetSizeX() const;

  /** get board size of y */
  unsigned int GetSizeY() const;

  /** randomize board */
  void Randomize(int seed);

  /** all cells die */
  void Clear();
  void Clear(Bitboard *bitboards, unsigned int size);

  /** get a state of cell */
  unsigned int GetCellState(unsigned int x, unsigned int y) const;

  /** set a state of cell */
  void SetCellState(bool cell, unsigned int x, unsigned int y);

  /** get a bitboard */
  Bitboard GetBitboard(unsigned int x, unsigned int y) const;
  Bitboard GetBitboard(unsigned int i) const;

  /** set a bitboard */
  void SetBitboard(Bitboard bitboard, unsigned int x, unsigned int y);
  void SetBitboard(Bitboard bitboard, unsigned int i);

  /** get size of bitboard list */
  unsigned int GetBitboardListSize() const;

  /** get size x of bitboard list */
  unsigned int GetBitboardListSizeX() const;

  /** get size y of bitboard list */
  unsigned int GetBitboardListSizeY() const;

  /** get biboard list*/
  Bitboard *GetBitboardList() const;

  void Copy(LargeBitboard *large);
  void Or(LargeBitboard *large);
  void And(LargeBitboard *large);
  void Xor(LargeBitboard *large);

protected:
  /** get bitboard from board array */
  Bitboard GetBoard(unsigned int x, unsigned int y) const;

  /** get shift size used when set/get cells */
  inline unsigned int GetBitboardShiftSize(unsigned int x,
                                           unsigned int y) const;

  /** get biboard index used when set/get cells */
  inline unsigned int GetBitboardIndex(unsigned int x, unsigned int y) const;
};

} // namespace BitboardCA

#endif
