#pragma once

// todo see if the pch is necessary here?
#include "wfpch.h"
#include "Event.h"

namespace Wolfen
{
	class KeyEvent : public Event
	{
	public:
		inline int GetKeyCode() const { return m_KeyCode; }

		EVENT_CLASS_CATEGORY( EventCategoryKeyboard | EventCategoryInput)

	protected:
		KeyEvent( int keyCode )
			:m_KeyCode(keyCode){}

		int m_KeyCode;
	};

	class KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent( int keycode, int repeatCount )
			:KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return m_RepeatCount; } //todo should profile later and see if the inline is needed 

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << m_KeyCode << " (" << m_RepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPress)
	
	private:
		int m_RepeatCount;
	};

	class KeyReleasedEvent : KeyEvent
	{
	public :
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode){}
		
		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyRelease)
	};
}
