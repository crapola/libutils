#pragma once
#include <SDL2/SDL.h>

/// SDL window.
/**
 * SDL_Init and SDL_Quit are respectively called on construction and
 * destruction.
 */
class Window
{
public:
	/**
	 * \brief Constructor.
	 * \param title The window title.
	 * \param width,height Dimensions in pixels.
	 * \param flags Flags passed to SDL_CreateWindow.
	 * \sa SDL_CreateWindow
	 */
	Window(const char* title,int width,int height,Uint32 flags=0);
	~Window();
	Window(const Window&)=delete;
	Window& operator=(const Window&)=delete;
	/// \brief Returns the associated SDL_Window pointer.
	operator SDL_Window* () const;
    /**
	 * \brief Get the client size.
     * \return SDL_Point
     */
	SDL_Point Size() const;
    /**
	 * \brief Get the surface.
     * \return SDL_Surface*
     */
	SDL_Surface* Surface() const;
private:
	SDL_Window* _window;
};
