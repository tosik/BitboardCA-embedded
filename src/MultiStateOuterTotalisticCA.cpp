#include "MultiStateOuterTotalisticCA.h"

using namespace BitboardCA;


MultiStateOuterTotalisticCA::MultiStateOuterTotalisticCA(unsigned int size_x, unsigned int size_y, unsigned int states)
  : m_States(states)
  , m_pInnerCA(0)
{
  if ( states < 2 )
  {
    // FIXME: Embedded edition cannot throw exceptions.
    return;
  }

  m_pWeakList = new LargeBitboard*[states];
  for ( unsigned int i = 0 ; i < states ; i ++ )
    m_pWeakList[i] = new LargeBitboard(size_x, size_y, false);
}

MultiStateOuterTotalisticCA::~MultiStateOuterTotalisticCA()
{
  for ( unsigned int i = 0 ; i < m_States ; i ++ )
    delete (m_pWeakList[i]);
}

void MultiStateOuterTotalisticCA::Step()
{
}

void MultiStateOuterTotalisticCA::Randomize()
{
  m_pWeakList[m_States - 1]->Randomize();
}

void MultiStateOuterTotalisticCA::SetInnerCAInstance(OuterTotalisticCA * inner_ca)
{
  m_pInnerCA = inner_ca;
}

