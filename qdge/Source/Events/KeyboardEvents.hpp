#include "Event.hpp"

QDGE_NS

class QDGE_API KeyboardEvent: public Event {
public:
	inline uint16_t GetKeyCode() const { return mKeyCode; }

	EVENT_CLASS_CATEGORY(EventCategoryInput | EventCategoryKeyboard)

protected:
	KeyboardEvent(uint16_t keycode);
	uint16_t mKeyCode;
};


class QDGE_API KeyPressEvent : public KeyboardEvent {
public:
	KeyPressEvent(uint16_t keycode);

	std::string ToString() const override;

	EVENT_CLASS_TYPE(KeyPress)
};


class QDGE_API KeyRepeatEvent : public KeyboardEvent {
public:
	KeyRepeatEvent(uint16_t keycode, uint32_t repeatCount);

	std::string ToString() const override;

	EVENT_CLASS_TYPE(KeyRepeat)

private:
	uint32_t mRepeatCount;
};


class QDGE_API KeyReleaseEvent : public KeyboardEvent {
public:
	KeyReleaseEvent(uint16_t keycode);

	std::string ToString() const override;

	EVENT_CLASS_TYPE(KeyRelease)
};

QDGE_NS_END
