#pragma once

#include "Core/Core.hpp"

#include <functional>
#include <string>

#define EVENT_CLASS_TYPE(type) \
	inline static EventType GetStaticType() { return EventType::##type; } \
	inline EventType GetType() const override { return GetStaticType(); } \
	inline std::string GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) \
	inline uint8_t GetCategories() const override { return (uint8_t)(category); }

QDGE_NS

enum class EventType : uint8_t
{
	None = 0,
	AppTick, AppUpdate, AppRender,
	WindowClose, WindowMove, WindowResize, WindowFocus, WindowUnfocus,
	KeyPress, KeyRepeat, KeyRelease,
	MouseMove, MouseScroll, MouseButtonPress, MouseButtonRelease
};

enum EventCategory : uint8_t
{
	EventCategoryNone		= 0,
	EventCategoryApp		= BITFIELD(0),
	EventCategoryWindow		= BITFIELD(1),
	EventCategoryInput		= BITFIELD(2),
	EventCategoryKeyboard	= BITFIELD(3),
	EventCategoryMouse		= BITFIELD(4)
};

interface QDGE_API Event
{
	friend class EventDispatcher;

public:
	virtual EventType GetType() const = 0;
	virtual std::string GetName() const = 0;
	virtual uint8_t GetCategories() const = 0;
	virtual std::string ToString() const { return GetName(); }

	inline bool IsInCategory(EventCategory category) const
	{
		return GetCategories() & (uint8_t)category;
	}

protected:
	bool mHandled = false;
};

class QDGE_API EventDispatcher
{
	template<typename T>
	using EventCallback = std::function<bool(T&)>;

public:
	EventDispatcher(Event& e);

	template<typename T>
	static bool Dispatch(Event& event, EventCallback<T> callback)
	{
		if (event.GetType() == T::GetStaticType())
		{
			event.mHandled = callback(REINTERPRET_CAST(T, event));
			return true;
		}
		return false;
	}

private:
	Event mEvent;
};

QDGE_NS_END
