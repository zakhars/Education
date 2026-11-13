#pragma once

#if defined(_MSC_VER)
	#if defined(BUILD_BBAPI)
		#define BBAPI __declspec(dllexport)
	#else
		#define BBAPI __declspec(dllimport)
		#pragma comment(lib, "blackbox.lib")
	#endif
#else
	#define BBAPI
#endif
