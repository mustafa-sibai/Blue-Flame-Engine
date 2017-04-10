CALL mkdir ..\Output\Sandbox\WebGL\Release\
CALL emcc ^
 -I "../Dependency/FreeImage/Source" ^
 "Sandbox/Main.cpp" ^
 "../Output/Core/WebGL/Release/Core.bc" ^
 -D BF_PLATFORM_WEB ^
 -s FULL_ES3=1 ^
 -s USE_WEBGL2=1 ^
 -std=c++11 ^
 -O3 ^
 -o ../Output/Sandbox/WebGL/Release/Sandbox.html ^
 --embed-file ./Sandbox/FragmentShader.glsl ^
 --embed-file ./Sandbox/VertexShader.glsl ^
 --embed-file ./Sandbox/test.png