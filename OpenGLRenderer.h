#pragma once
#include "Headers.h"

namespace OpenGLBootstrap{
	class OpenGLRenderer : public IWindowRenderer
	{
	public:
		OpenGLRenderer();
		void BeforeStart(HDC WindowDeviceContext) override;
		void ClearWindow(double deltaTime) override;
		void Render(double deltaTime) override;
		virtual ~OpenGLRenderer();
	};
}