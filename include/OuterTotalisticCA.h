#ifndef _INCLUDE_GUARD_UUID_D794AED5_1999_44C8_BE86_AA753508232D_
#define _INCLUDE_GUARD_UUID_D794AED5_1999_44C8_BE86_AA753508232D_

#include "LargeBitboard.h"

namespace BitboardCA {
/** Cellular Automata class */
class OuterTotalisticCA : public LargeBitboard {

public:
  /** constructor */
  OuterTotalisticCA(unsigned int size_x, unsigned int size_y);

  /** destructor */
  virtual ~OuterTotalisticCA();

  /** step one */
  void Step();

  /** Update Bitboard by Outer Totalistic */
  Bitboard StepByOuterTotalistic(Bitboard board, Bitboard board_a,
                                 Bitboard board_b, Bitboard board_c,
                                 Bitboard board_d, Bitboard board_e,
                                 Bitboard board_f, Bitboard board_g,
                                 Bitboard board_h);

protected:
  // you should code automata rule you like.
  // like this:
  //
  //   Bitboard Rule(Bitboard board, Bitboard s0, Bitboard s1, Bitboard s2,
  //   Bitboard s3,
  //                 Bitboard s4, Bitboard s5, Bitboard s6, Bitboard s7,
  //                 Bitboard s8 )
  //   {
  //     // Conway's game of life
  //     return ( ~board & s3 ) | ( board & ( s2 | s3 ) );
  //   }
  //
  virtual Bitboard Rule(Bitboard board, Bitboard s0, Bitboard s1, Bitboard s2,
                        Bitboard s3, Bitboard s4, Bitboard s5, Bitboard s6,
                        Bitboard s7, Bitboard s8) = 0;
};

} // namespace BitboardCA

#endif
