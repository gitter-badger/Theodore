#include "os_types.h"

#ifdef Quark_Windows

#ifndef WindowsPlatform_h
#define WindowsPlatform_h

#include <string>
#include "Enumeration.h"

namespace Quark {
	class WindowsPlatform {
		friend class Platform;
	private:
		WindowsPlatform();
		~WindowsPlatform();

		bool CreatePlatformWindows(const std::string& title, int width, int height, bool fullscreen, int majorVersion, int minorVersion, int multisample, WindowStyle style, ContextProfile profile);
		void KillPlatformWindows();

		static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
		static bool QueryWGLExtensionSupported(const std::string& extionsion_name);
		static bool QueryExtentionSupported(const std::string& extionsion_name);

		static WindowsPlatform* instance;
		static Platform* platform;

		HINSTANCE mhInstance;
		HWND mHandle;
		HDC mHdc;
		HGLRC mContext;
	};
}

#endif /* WindowsPlatform_h */

#endif /* Quark_Windows */
