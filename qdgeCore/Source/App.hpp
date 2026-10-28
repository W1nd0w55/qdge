#pragma once

namespace qdge
{
	class App
	{
	public:
		App();
		virtual ~App();
		virtual void Run() = 0;
	};
}
