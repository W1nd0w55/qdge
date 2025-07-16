#include "Event.hpp"

QDGE_NS

namespace Events {
	class QDGE_API MouseMoveEvent : public Event {
	public:
		MouseMoveEvent(double x, double y);

		inline double GetX() const { return mX; }
		inline double GetY() const { return mY; }

		std::string ToString() const override;

		EVENT_CLASS_TYPE(MouseMove)
		EVENT_CLASS_CATEGORY(CategoryInput | CategoryMouse)

	private:
		double mX, mY;
	};

	class QDGE_API MouseScrollEvent : public Event {
	public:
		MouseScrollEvent(double xOffset, double yOffset);

		inline double GetXOffset() const { return mXOffset; }
		inline double GetYOffset() const { return mYOffset; }

		std::string ToString() const override;

		EVENT_CLASS_TYPE(MouseScroll)
		EVENT_CLASS_CATEGORY(CategoryInput | CategoryMouse)

	private:
		double mXOffset, mYOffset;
	};


	class QDGE_API MouseButtonEvent : public Event {
	public:
		inline uint8_t GetButton() const { return mButton; }

		EVENT_CLASS_CATEGORY(CategoryInput | CategoryMouse)

	protected:
		MouseButtonEvent(uint8_t button);

		uint8_t mButton;
	};


	class QDGE_API MouseButtonPressEvent : public MouseButtonEvent {
	public:
		MouseButtonPressEvent(uint8_t button);

		std::string ToString() const override;

		EVENT_CLASS_TYPE(MouseButtonPress)
	};


	class QDGE_API MouseButtonReleaseEvent : public MouseButtonEvent {
	public:
		MouseButtonReleaseEvent(uint8_t button);

		std::string ToString() const override;

		EVENT_CLASS_TYPE(MouseButtonRelease)
	};
}

QDGE_NS_END
