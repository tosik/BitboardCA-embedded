#include "GenerationOuterTotalisticCA.h"

using namespace BitboardCA;

GenerationOuterTotalisticCA::GenerationOuterTotalisticCA(unsigned int size_x,
                                                         unsigned int size_y,
                                                         unsigned int states)
    : MultiStateOuterTotalisticCA(size_x, size_y, states), m_pInnerCA(0) {}

void GenerationOuterTotalisticCA::Step() {
  unsigned int size_x = m_pInnerCA->GetSizeX();
  unsigned int size_y = m_pInnerCA->GetSizeY();

  // step(m_States - 1) => A
  LargeBitboard A(size_x, size_y);
  m_pInnerCA->Copy(m_pWeakList[m_States - 1]);
  m_pInnerCA->Step();
  A.Copy(&(*m_pInnerCA));

  // or(m_States - 1 .. 0) => B
  LargeBitboard B(size_x, size_y);
  B.Copy(m_pWeakList[m_States - 2]);
  for (unsigned int i = 0; i <= m_States - 3; i++) {
    B.Or(m_pWeakList[i]);
  }

  // A - B => C
  LargeBitboard C(size_x, size_y);
  C.Copy(&A);
  C.Or(&B);
  C.Xor(&B);

  // m_States - 1 - C => D
  LargeBitboard D(size_x, size_y);
  D.Copy(m_pWeakList[m_States - 1]);
  D.Or(&C);
  D.Xor(&C);

  // copy back
  for (unsigned int i = 0; i <= m_States - 3; i++)
    m_pWeakList[i]->Copy(m_pWeakList[i + 1]);
  m_pWeakList[m_States - 2]->Copy(&D);
  m_pWeakList[m_States - 1]->Copy(&C);
}

void GenerationOuterTotalisticCA::SetInnerCAInstance(
    OuterTotalisticCA *innerCA) {
  m_pInnerCA = innerCA;
}
