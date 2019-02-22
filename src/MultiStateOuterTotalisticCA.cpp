#include "MultiStateOuterTotalisticCA.h"

using namespace BitboardCA;

MultiStateOuterTotalisticCA::MultiStateOuterTotalisticCA(unsigned int size_x,
                                                         unsigned int size_y,
                                                         unsigned int states)
    : m_States(states) {
  if (states < 2) {
    // FIXME: Embedded edition cannot throw exceptions.
    return;
  }

  m_pWeakList = new LargeBitboard *[states];
  for (unsigned int i = 0; i < states; i++)
    m_pWeakList[i] = new LargeBitboard(size_x, size_y, false);
}

MultiStateOuterTotalisticCA::~MultiStateOuterTotalisticCA() {
  for (unsigned int i = 0; i < m_States; i++)
    delete (m_pWeakList[i]);
}

void MultiStateOuterTotalisticCA::Randomize(int seed) {
  m_pWeakList[m_States - 1]->Randomize(seed);
}
