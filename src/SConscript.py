system_include = [r'C:\Code\c++\SFML-2.5.1-windows-vc15-64-bit\SFML-2.5.1\include', r'C:\programs\lemon\include']
libpath=[r'C:\programs\lemon\lib', r'C:\Code\c++\SFML-2.5.1-windows-vc15-64-bit\SFML-2.5.1\lib'] 
libs = ['sfml-graphics-d', 'sfml-system-d', 'sfml-window-d', 'lemon']
user_include =[  '../include']
tools = ['clang++', 'link']
ccflags = ['-D_DLL']
linkflags = ['-nostartfiles']
env = Environment(CPPPATH=system_include + user_include, LIBPATH = libpath, LIBS=libs, tools=tools, LINKFLAGS = linkflags, CCFLAGS = ccflags)
sources = Glob('**/*.cpp') + Glob('*.cpp')
env.Program('open-yorg', sources)