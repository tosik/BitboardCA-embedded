#ifndef _INCLUDE_GUARD_UUID_01ABD4F0_1D34_497E_A9DE_FA3B9AED534F_
#define _INCLUDE_GUARD_UUID_01ABD4F0_1D34_497E_A9DE_FA3B9AED534F_

#include "IBasicBitboardCA.h"
#include "LargeBitboard.h"
#include "OuterTotalisticCA.h"

namespace BitboardCA {
class MultiStateOuterTotalisticCA : public IBasicBitboardCA {
protected:
  unsigned int m_States;
  LargeBitboard **m_pWeakList;

public:
  MultiStateOuterTotalisticCA(unsigned int size_x, unsigned int size_y,
                              unsigned int states);
  virtual ~MultiStateOuterTotalisticCA();
  virtual void Step() = 0;
  void Randomize(int seed);

  unsigned int GetSizeX() const { return m_pWeakList[0]->GetSizeX(); }

  unsigned int GetSizeY() const { return m_pWeakList[0]->GetSizeY(); }

  unsigned int GetCellState(unsigned int x, unsigned int y) const {
    for (unsigned int i = m_States; i > 1; i--) {
      unsigned int state = i - (unsigned int)1;
      if (m_pWeakList[state]->GetCellState(x, y) == 1)
        return state;
    }
    return 0;
  }

  void SetCellState(unsigned int x, unsigned int y, unsigned int state) {
    for (unsigned int i = 0; i < m_States; i++)
      m_pWeakList[i]->SetCellState((i == state), x, y);
  }

protected:
};

} // namespace BitboardCA

#endif
