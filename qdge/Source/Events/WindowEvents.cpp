#include "pch.hpp"
#include "WindowEvents.hpp"

QDGE_NS

WindowCloseEvent::WindowCloseEvent()
{
}


WindowMoveEvent::WindowMoveEvent(uint16_t x, uint16_t y)
	: mX(x), mY(y)
{
}

std::string WindowMoveEvent::ToString() const
{
	return std::format("Window Moved (X: {}, Y: {})", mX, mY);
}


WindowResizeEvent::WindowResizeEvent(uint16_t width, uint16_t height)
	: mWidth(width), mHeight(height)
{
}

std::string WindowResizeEvent::ToString() const
{
	return std::format("Window Resized (Width: {0}, Height: {1})", mWidth, mHeight);
}


WindowFocusEvent::WindowFocusEvent()
{
}


WindowUnfocusEvent::WindowUnfocusEvent()
{
}

QDGE_NS_END
