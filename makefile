# 'make' to build release
# 'make debug' to build debug lib

# Include paths
sdl=F:\Libraries\SDL2\x86_64-w64-mingw32\include\SDL2
glew=F:\Libraries\GLEW\glew-2.0.0\include
self=include

warnings=-Wall -Weffc++ -pedantic -Wextra
CXXFLAGS=-std=c++1z $(warnings) -I$(sdl) -I$(glew) -I$(self) -DGLEW_STATIC
src_folders=src/misc src/gl src/gfx src/smalltext
src_files=$(foreach p,$(src_folders),$(wildcard $(p)/*.cpp))
objdir=temp
objs=$(addprefix $(objdir)/,$(addsuffix .o,$(notdir $(basename $(src_files)))))

all: lib/libutils.a

lib/libutils.a: CXXFLAGS+=-O3 -DNDEBUG -s
lib/libutils.a: clean $(objs) | lib
	ar rcs $@ $(objs)

debug: lib/libutils_d.a
lib/libutils_d.a: CXXFLAGS+=-g
lib/libutils_d.a: clean $(objs) | lib
	ar rcs $@ $(objs)

clean:
	del $(objdir)\*.o

$(objdir)/%.o: src/smalltext/%.cpp | $(objdir)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(objdir)/%.o: src/gfx/%.cpp | $(objdir)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(objdir)/%.o: src/gl/%.cpp | $(objdir)
	$(CXX) $(CXXFLAGS) -o $@ -c $<
$(objdir)/%.o: src/misc/%.cpp | $(objdir)
	$(CXX) $(CXXFLAGS) -o $@ -c $<

lib:
	mkdir lib
$(objdir):
	mkdir $@