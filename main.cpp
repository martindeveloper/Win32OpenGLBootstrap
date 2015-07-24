#include "Headers.h"

struct WindowProperties
{
	// Win32
	HINSTANCE hInstance;
	HINSTANCE hPrevInstance;
	LPSTR lpCmdLine;
	int nShowCmd;

	// Custom
	unsigned __int32 Width;
	unsigned __int32 Height;
	const wchar_t* Title;
	bool IsFullscreen;
	Renderer::IWindowRenderer* Renderer;
};

// Prototypes
int CreateWindowWithRenderer(WindowProperties properties, Renderer::IWindowRenderer* renderer);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	WindowProperties windowProperties;
	ZeroMemory(&windowProperties, sizeof(windowProperties));

	windowProperties.hInstance = hInstance;
	windowProperties.hPrevInstance = hPrevInstance;
	windowProperties.lpCmdLine = lpCmdLine;
	windowProperties.nShowCmd = nShowCmd;

	windowProperties.Width = 1024;
	windowProperties.Height = 768;
	windowProperties.Title = L"OpenGL Window";
	windowProperties.IsFullscreen = false;
	windowProperties.Renderer = new Renderer::D3D11Renderer();

	int result = CreateWindowWithRenderer(windowProperties, windowProperties.Renderer);

	return result;
}

int CreateWindowWithRenderer(WindowProperties properties, Renderer::IWindowRenderer* renderer)
{
	WindowBootstrap::Window* Window = new WindowBootstrap::Window(properties.hInstance, properties.hPrevInstance, properties.lpCmdLine, properties.nShowCmd);
	Window->SetRenderer(renderer);

	int result = Window->Create(properties.Width, properties.Height, properties.Title, properties.IsFullscreen);

	delete Window;

	return result;
}