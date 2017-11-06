// ManagedMotionCapture.h

#pragma once

#include "MotionCapture.h"

//using namespace System;

namespace ManagedMotionCapture {

	public ref class MotionCaptureWrapper
	{
	public:
		MotionCaptureWrapper(void);
		virtual ~MotionCaptureWrapper(void);

		// Property
		/*property float FloatProperty
		{
			float get(void);
			void set(float value);
		}*/

		// Method
		//virtual String ^ ToString(void) override;
		void onDataReceived(unsigned char* buf, int len);

		// Static method
		//static int GetStringLength(String ^ str);

	protected:
		!MotionCaptureWrapper(void);

	private:
		MotionCapture *m_impl;
	};
}
