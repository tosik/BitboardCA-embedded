#ifndef _INCLUDE_GUARD_UUID_FF10863E_7A7F_4BB1_907E_8E8B26E6F381_
#define _INCLUDE_GUARD_UUID_FF10863E_7A7F_4BB1_907E_8E8B26E6F381_

#include "LargeBitboard.h"

namespace BitboardCA {
// John von Neumann's neighborhood totalistic
class NeumannOuterTotalisticCA : public LargeBitboard {

public:
  NeumannOuterTotalisticCA(unsigned int size_x, unsigned int size_y);
  virtual ~NeumannOuterTotalisticCA();
  void Step();
  Bitboard StepByOuterTotalistic(Bitboard board, Bitboard board_a,
                                 Bitboard board_b, Bitboard board_c,
                                 Bitboard board_d, Bitboard board_e,
                                 Bitboard board_f, Bitboard board_g,
                                 Bitboard board_h);

protected:
  virtual Bitboard Rule(Bitboard board, Bitboard s0, Bitboard s1, Bitboard s2,
                        Bitboard s3, Bitboard s4, Bitboard s5, Bitboard s6,
                        Bitboard s7, Bitboard s8) = 0;
};

} // namespace BitboardCA

#endif
