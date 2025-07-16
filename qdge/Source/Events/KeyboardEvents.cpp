#include "pch.hpp"
#include "KeyboardEvents.hpp"

QDGE_NS

namespace Events {
	KeyboardEvent::KeyboardEvent(uint16_t keycode)
		: mKeyCode(keycode) {}


	KeyPressEvent::KeyPressEvent(uint16_t keycode)
		: KeyboardEvent(keycode) {}

	std::string KeyPressEvent::ToString() const {
		return std::format("Key pressed: code {}", mKeyCode);
	}


	KeyRepeatEvent::KeyRepeatEvent(uint16_t keycode, uint32_t repeatCount)
		: KeyboardEvent(keycode), mRepeatCount(repeatCount) {}

	std::string KeyRepeatEvent::ToString() const {
		return std::format("Key repeated: code {}, {}th time", mKeyCode, mRepeatCount);
	}


	KeyReleaseEvent::KeyReleaseEvent(uint16_t keycode)
		: KeyboardEvent(keycode) {
	}

	std::string KeyReleaseEvent::ToString() const {
		return std::format("Key released: code {}", mKeyCode);
	}
}

QDGE_NS_END
