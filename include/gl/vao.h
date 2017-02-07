#pragma once
#include "../../src/gl/glid.hpp"
namespace gl
{
class VAO: public Identifiable
{
public:
	VAO();
	~VAO();
	void Bind() const;
	static void Unbind();
};
}
