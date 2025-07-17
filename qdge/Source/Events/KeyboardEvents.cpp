#include "pch.hpp"
#include "KeyboardEvents.hpp"

QDGE_NS

KeyboardEvent::KeyboardEvent(uint16_t keycode)
	: mKeyCode(keycode) {}


KeyPressEvent::KeyPressEvent(uint16_t keycode)
	: KeyboardEvent(keycode) {}

std::string KeyPressEvent::ToString() const {
	return std::format("Key Pressed: Code {}", mKeyCode);
}


KeyRepeatEvent::KeyRepeatEvent(uint16_t keycode, uint32_t repeatCount)
	: KeyboardEvent(keycode), mRepeatCount(repeatCount) {}

std::string KeyRepeatEvent::ToString() const {
	return std::format("Key Repeated: Code {}, {}th time", mKeyCode, mRepeatCount);
}


KeyReleaseEvent::KeyReleaseEvent(uint16_t keycode)
	: KeyboardEvent(keycode) {
}

std::string KeyReleaseEvent::ToString() const {
	return std::format("Key Released: Code {}", mKeyCode);
}

QDGE_NS_END
