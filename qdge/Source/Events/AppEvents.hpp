#include "Event.hpp"

QDGE_NS

class QDGE_API AppTickEvent : public Event {
public:
	AppTickEvent();

	EVENT_CLASS_TYPE(AppTick)
	EVENT_CLASS_CATEGORY(EventCategoryApp)
};

class QDGE_API AppUpdateEvent : public Event {
public:
	AppUpdateEvent();

	EVENT_CLASS_TYPE(AppUpdate)
	EVENT_CLASS_CATEGORY(EventCategoryApp)
};

class QDGE_API AppRenderEvent : public Event {
public:
	AppRenderEvent();

	EVENT_CLASS_TYPE(AppRender)
	EVENT_CLASS_CATEGORY(EventCategoryApp)
};

QDGE_NS_END
