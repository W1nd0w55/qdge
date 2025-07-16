#include "Event.hpp"

QDGE_NS

namespace Events {
	class QDGE_API WindowCloseEvent: public Event {
	public:
		WindowCloseEvent(); // TODO: take in a window as argument

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(Window)
	};


	class QDGE_API WindowMoveEvent: public Event {
	public:
		WindowMoveEvent(uint16_t x, uint16_t y);

		inline const uint16_t GetX() const { return mX; }
		inline const uint16_t GetY() const { return mY; }

		std::string ToString() const override;

		EVENT_CLASS_TYPE(WindowMove)
		EVENT_CLASS_CATEGORY(Window)

	private:
		uint16_t mX, mY;
	};


	class QDGE_API WindowResizeEvent: public Event {
	public:
		WindowResizeEvent(uint16_t width, uint16_t height);

		inline const uint16_t GetX() const { return mWidth; }
		inline const uint16_t GetY() const { return mHeight; }

		std::string ToString() const override;

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(Window)

	private:
		uint16_t mWidth, mHeight;
	};


	class QDGE_API WindowFocusEvent : public Event {
	public:
		WindowFocusEvent(); // TODO: take in a window as argument

		EVENT_CLASS_TYPE(WindowFocus)
		EVENT_CLASS_CATEGORY(Window)
	};


	class QDGE_API WindowUnfocusEvent : public Event {
	public:
		WindowUnfocusEvent(); // TODO: take in a window as argument

		EVENT_CLASS_TYPE(WindowUnfocus)
		EVENT_CLASS_CATEGORY(Window)
	};
}

QDGE_NS_END
