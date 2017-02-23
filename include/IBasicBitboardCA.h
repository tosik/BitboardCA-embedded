#pragma once

#include "bbcommon.h"

namespace BitboardCA
{
	class IBasicBitboardCA : public IViewableBitboard
	{
		public:
			virtual void Step() = 0;
			virtual void SetCellState(unsigned int x, unsigned int y, unsigned int state) = 0;
	};
}
