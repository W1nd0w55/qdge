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

namespace Events {
	enum class EventType : uint8_t {
		None = 0,
		AppTick, AppUpdate, AppRender,
		WindowClose, WindowMove, WindowResize, WindowFocus, WindowUnfocus,
		KeyPress, KeyRepeat, KeyRelease,
		MouseMove, MouseClick, MouseRelease, MouseScroll
	};

	enum EventCategory : uint8_t {
		CategoryNone		= 0,
		CategoryApp			= BITFIELD(0),
		CategoryWindow		= BITFIELD(1),
		CategoryInput		= BITFIELD(2),
		CategoryKeyboard	= BITFIELD(3),
		CategoryMouse		= BITFIELD(4)
	};

	interface QDGE_API Event {
		friend class EventDispatcher;

	public:
		virtual EventType GetType() const = 0;
		virtual std::string GetName() const = 0;
		virtual uint8_t GetCategories() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) {
			return GetCategories() & (uint8_t)category;
		}

	protected:
		bool mHandled = false;
	};

	staticclass QDGE_API EventDispatcher {
		template<typename T>
		using EventCallback = std::function<bool(T&)>;

	public:
		static void Init();

		template<typename T>
		static bool Dispatch(Event& event, EventCallback<T> callback) {
			if (event.GetType() == T::GetStaticType()) {
				event.mHandled = callback(reinterpret_cast<T>(event));
				return true;
			}
			return false;
		}
	};
}

QDGE_NS_END
