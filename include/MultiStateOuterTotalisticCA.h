#pragma once

#include "LargeBitboard.h"
#include "OuterTotalisticCA.h"
#include "IViewableBitboard.h"


namespace BitboardCA
{
  class MultiStateOuterTotalisticCA
    : public IViewableBitboard
  {
    protected:
      unsigned int m_States;
      OuterTotalisticCA * m_pInnerCA;
      LargeBitboard ** m_pWeakList;

    public:
      MultiStateOuterTotalisticCA(unsigned int size_x, unsigned int size_y, unsigned int states);
      virtual ~MultiStateOuterTotalisticCA();
      virtual void Step() = 0;
      void Randomize();
      void SetInnerCAInstance(OuterTotalisticCA * inner_ca);

      unsigned int GetSizeX()
      {
        return m_pWeakList[0]->GetSizeX();
      }

      unsigned int GetSizeY()
      {
        return m_pWeakList[0]->GetSizeY();
      }

      unsigned int GetCellState(unsigned int x, unsigned int y)
      {
        for ( unsigned int i = m_States ; i > 1 ; i -- )
        {
          unsigned int state = i - (unsigned int)1;
          if ( m_pWeakList[state]->GetCellState(x, y) == 1 )
            return state;
        }
        return 0;
      }

      void SetCellState(unsigned int x, unsigned int y, unsigned int state)
      {
        for ( unsigned int i = 0 ; i < m_States ; i ++ )
          m_pWeakList[i]->SetCellState((i == state), x, y);
      }

    protected:

  };

}

