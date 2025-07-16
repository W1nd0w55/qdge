#pragma once

#include "Core/Core.hpp"

#include <functional>
#include <string>

#define EVENT_CLASS_TYPE(type) \
	static EventType GetStaticType() { return EventType::##type; } \
	EventType GetType() const override { return GetStaticType(); } \
	std::string GetName() const override { return #type }

#define EVENT_CLASS_CATEGORY(category) uint8_t GetCategories() const override { return category; }

QDGE_NS

namespace Events {
	enum class EventType : uint8_t {
		None = 0,
		AppTick, AppUpdate, AppRender,
		WindowClose, WindowMove, WindowResize, WindowFocus, WindowUnfocus /* peak naming */,
		KeyPress, KeyRepeat, KeyRelease,
		MouseMove, MouseClick, MouseRelease, MouseScroll
	};

	enum class EventCategory : uint8_t {
		None = 0,
		App = BITFIELD(0),
		Window = BITFIELD(1),
		Input = BITFIELD(2),
		Keyboard = BITFIELD(3),
		Mouse = BITFIELD(4)
	};

	interface QDGE_API Event{
		friend class EventDispatcher;

	public:
		virtual EventType GetType() const = 0;
		virtual std::string GetName() const = 0;
		virtual uint8_t GetCategories() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory cat /* peak naming again */) {
			return GetCategories() & (uint8_t)cat;
		}

	protected:
		bool mHandled = false;
	};

	staticclass EventDispatcher{
		template<typename T>
		using EventFunc = std::function<bool(T&)>;

	public:
		static void Init();

		template<typename T>
		static bool Dispatch(Event& event, EventFunc<T> func) {
			if (event.GetType() == T::GetStaticType()) {
				event.mHandled = func(reinterpret_cast<T>(event));
				return true;
			}
			return false;
		}
	};
}

QDGE_NS_END
