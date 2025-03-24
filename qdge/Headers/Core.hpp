#pragma once

#ifdef QDGE_WINDOWS
	#ifdef QDGE_BUILD
		#define QDGE_API __declspec(dllexport)
	#else
		#define QDGE_API __declspec(dllimport)
	#endif
#else
	#define QDGE_API
#endif
