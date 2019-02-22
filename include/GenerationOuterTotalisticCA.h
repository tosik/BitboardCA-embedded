#ifndef _INCLUDE_GUARD_UUID_7D3EDC5C_5BEA_44AE_8E47_4DA4683E6081_
#define _INCLUDE_GUARD_UUID_7D3EDC5C_5BEA_44AE_8E47_4DA4683E6081_

#include "LargeBitboard.h"
#include "MultiStateOuterTotalisticCA.h"
#include "OuterTotalisticCA.h"

namespace BitboardCA {
class GenerationOuterTotalisticCA : public MultiStateOuterTotalisticCA {
private:
  OuterTotalisticCA *m_pInnerCA;

public:
  GenerationOuterTotalisticCA(unsigned int size_x, unsigned int size_y,
                              unsigned int states);
  void SetInnerCAInstance(OuterTotalisticCA *innerCA);
  void Step();
};
} // namespace BitboardCA

#endif
