// This is the main DLL file.

#include "stdafx.h"



#pragma region Includes
#include "ManagedMotionCapture.h"
using namespace ManagedMotionCapture;

#include <msclr/marshal.h>
using namespace msclr::interop;
#pragma endregion


MotionCaptureWrapper::MotionCaptureWrapper(void)
{
	// Instantiate the native C++ class CSimpleObject.
	m_impl = new MotionCapture(HWv3Right,RightHand);
}

MotionCaptureWrapper::~MotionCaptureWrapper(void)
{
	if (m_impl)
	{
		delete m_impl;
		m_impl = NULL;
	}
}

MotionCaptureWrapper::!MotionCaptureWrapper(void)
{
	if (m_impl)
	{
		delete m_impl;
		m_impl = NULL;
	}
}

void MotionCaptureWrapper::onDataReceived(unsigned char* buf, int len)
{
	m_impl->onDataReceived(buf, len);
}

/*
float MotionCaptureWrapper::FloatProperty::get(void)
{
	return m_impl->get_FloatProperty();
}

void MotionCaptureWrapper::FloatProperty::set(float value)
{
	m_impl->set_FloatProperty(value);
}

String ^ MotionCaptureWrapper::ToString(void)
{
	wchar_t szStr[100];
	HRESULT hr = m_impl->ToString(szStr, ARRAYSIZE(szStr));
	if (FAILED(hr))
	{
		Marshal::ThrowExceptionForHR(hr);
	}
	// Marshal PWSTR to System::String and return it.
	return gcnew String(szStr);
}

int MotionCaptureWrapper::GetStringLength(System::String ^ str)
{
	// Marshal System::String to PCWSTR, and call the C++ function.
	marshal_context ^ context = gcnew marshal_context();
	PCWSTR pszString = context->marshal_as<const wchar_t*>(str);
	int length = CSimpleObject::GetStringLength(pszString);
	delete context;
	return length;
}
*/