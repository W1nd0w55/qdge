#include "MouseEvents.hpp"

QDGE_NS

MouseMoveEvent::MouseMoveEvent(double x, double y)
	: mX(x), mY(y)
{
}

std::string MouseMoveEvent::ToString() const
{
	return std::format("Mouse Moved (x: {}, y: {})", mX, mY);
}

MouseScrollEvent::MouseScrollEvent(double xOffset, double yOffset)
	: mXOffset(xOffset), mYOffset(yOffset)
{
}

std::string MouseScrollEvent::ToString() const
{
	return std::format("Mouse Scrolled (X offset: {}, \
Y offset: {})", mXOffset, mYOffset);
}


MouseButtonEvent::MouseButtonEvent(uint8_t button)
	: mButton(button)
{
}


MouseButtonPressEvent::MouseButtonPressEvent(uint8_t button)
	: MouseButtonEvent(button)
{
}

std::string MouseButtonPressEvent::ToString() const
{
	return std::format("Mouse Button Pressed (Button: {})", mButton);
}


MouseButtonReleaseEvent::MouseButtonReleaseEvent(uint8_t button)
	: MouseButtonEvent(button)
{
}

std::string MouseButtonReleaseEvent::ToString() const
{
	return std::format("Mouse Button Released (Button: {})", mButton);
}

QDGE_NS_END
