#pragma once

#include "LargeBitboard.h"
#include "OuterTotalisticCA.h"
#include "MultiStateOuterTotalisticCA.h"
#include "IViewableBitboard.h"


namespace BitboardCA
{
	/** Cellular Automata class */
	class GenerationOuterTotalisticCA
		: public MultiStateOuterTotalisticCA
	{
    private:
      OuterTotalisticCA * m_pInnerCA;

		public:
			GenerationOuterTotalisticCA(unsigned int size_x, unsigned int size_y, unsigned int states);
      void SetInnerCAInstance(OuterTotalisticCA * inner_ca);
			void Step();
	};

}
