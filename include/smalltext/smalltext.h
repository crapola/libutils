#pragma once
#include "misc/backcache.hpp"
#include "gl/buffer.h"
#include "gl/shader.h"
#include "gl/program.h"
#include "gl/texture.h"
#include "gl/vao.h"
#include <functional>
#include <string>

class SmallText
{
public:
#include "../../src/smalltext/smalltext_types.h"
	SmallText();
	~SmallText();
	// Add a number of characters to the end and return offset of added chars.
	size_t Add(size_t count);
	size_t Add(const std::string& s);
	// Delete characters.
	void Delete(size_t offset,size_t length);
	// Draw everything.
	void Draw();
	// Apply function to range.
	void ForEach(size_t offset,size_t length,std::function<Character(Character)> f);
	// Arrange in a box.
	void Paragraph(size_t offset,size_t length,int x_px,int y_px,int width);
	// Set colors for range of characters.
	void SetColor(size_t offset,size_t length,uint8_t front,uint8_t back);
	// Set pixel resolution.
	void Resolution(int width,int height) const;
	// Write string at offset.
	void Write(size_t offset,const std::string& s);
private:
	void UploadWholeBuffer();

	BackCache<Character> _chars;
	gl::Buffer _charBuf;
	gl::Program _program;
	gl::Texture _texture;
	gl::VAO _vao;
};

constexpr Color2B(int r,int g,int b,int a)
{
	return ((r<<6)|(g<<4)|(b<<2)|a);
}
