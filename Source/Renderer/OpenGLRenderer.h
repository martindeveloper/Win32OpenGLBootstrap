#pragma once
#include "../Headers.h"

// Libraries
#pragma comment(lib, "glu32")
#pragma comment(lib, "../External/glew/lib/glew32")
#pragma comment(lib, "opengl32")

namespace Renderer{
	class OpenGLRenderer : public IWindowRenderer
	{
	public:
		OpenGLRenderer();
		void BeforeStart(HDC WindowDeviceContext, const bool isWindowed) override;
		void ClearWindow(const double deltaTime) override;
		void Update(const double deltaTime) override;
		void Render(const double deltaTime) override;
		virtual ~OpenGLRenderer();

	private:
		GLuint VBO;
		GLuint VAO;
		GLuint ShaderProgramID;

		GLint CompileShader(const char* path, GLenum type);
		GLint CreateShaderProgram(GLint vertexShader, GLint fragmentShader);

		void PrepareBuffers();
		void CreateShaders();

		// TODO: Delete this temp stuff
		Graphic::Primitive::TrianglePrimitive* Triangle;
		Graphic::Primitive::CubePrimitive* Cube;
	};
}