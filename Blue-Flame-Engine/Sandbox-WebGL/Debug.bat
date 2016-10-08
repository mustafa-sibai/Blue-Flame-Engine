CALL mkdir ..\Output\Sandbox\WebGL\Debug\
CALL emcc ^
 -I "../Dependency/FreeImage/Source" ^
 "Sandbox/Main.cpp" ^
 "../Output/Core/WebGL/Debug/Core.bc" ^
 -D BF_PLATFORM_WEBGL ^
 -s FULL_ES3=1 ^
 -s USE_WEBGL2=1 ^
 -std=c++11 ^
 -O0 ^
 -o ../Output/Sandbox/WebGL/Debug/Sandbox.html ^
 --embed-file ./Sandbox/FragmentShader.glsl ^
 --embed-file ./Sandbox/VertexShader.glsl ^
 --embed-file ./Sandbox/test.png