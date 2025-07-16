#include "Event.hpp"

QDGE_NS

namespace Events {
	class QDGE_API AppTickEvent : public Event {
	public:
		AppTickEvent();

		EVENT_CLASS_TYPE(AppTick)
		EVENT_CLASS_CATEGORY(CategoryApp)
	};

	class QDGE_API AppUpdateEvent : public Event {
	public:
		AppUpdateEvent();

		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(CategoryApp)
	};

	class QDGE_API AppRenderEvent : public Event {
	public:
		AppRenderEvent();

		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(CategoryApp)
	};
}

QDGE_NS_END
