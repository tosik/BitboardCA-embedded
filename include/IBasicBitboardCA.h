#ifndef _INCLUDE_GUARD_UUID_8D710460_41F7_40BE_B749_89D43F312BD6_
#define _INCLUDE_GUARD_UUID_8D710460_41F7_40BE_B749_89D43F312BD6_

#include "IViewableBitboard.h"
#include "bbcommon.h"

namespace BitboardCA {
class IBasicBitboardCA : public IViewableBitboard {
public:
  virtual void Step() = 0;
  virtual void SetCellState(unsigned int x, unsigned int y,
                            unsigned int state) = 0;
};
} // namespace BitboardCA

#endif
