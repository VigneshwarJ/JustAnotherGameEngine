#pragma once
#include <memory>
#ifdef JAGE_PLATFORM_WINDOWS

#ifdef BUILD_DLL
#define JAGE_API __declspec(dllexport)
#else
#define JAGE_API __declspec(dllimport)
#endif // BUILD_DLL

#define BIT(x) (1 << x)

namespace JAGE {
	template<typename T>
	using Scope = std::unique_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Scope<T> CreateScope(Args&& ... args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}
	template<typename T>
	using Ref = std::shared_ptr<T>;
	template<typename T, typename ... Args>
	constexpr Ref<T> CreateRef(Args&& ... args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

}




#endif // DEBUG
