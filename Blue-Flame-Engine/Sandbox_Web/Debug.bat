CALL mkdir ..\Output\Sandbox\Web\Debug\
CALL emcc ^
 "Sandbox/Main.cpp" ^
 "Sandbox/_2DScene.cpp" ^
 "../Output/Core/Web/Debug/Core.bc" ^
 "../Dependency/FreeImage/Output/Web/Debug/FreeImage.bc" ^
 "../Dependency/FreeType/Output/Web/Debug/FreeType.bc" ^
 "../Dependency/TinyXML-2/Output/Web/Debug/TinyXML-2.bc" ^
 -I "../Core/" ^
 -I "../Dependency/FreeImage/Source/" ^
 -I "../Dependency/FreeType/include/" ^
 -I "../Dependency/TinyXML-2/" ^
 -D BF_PLATFORM_WEB ^
 -s FULL_ES3=1 ^
 -s USE_WEBGL2=1 ^
 -std=c++14 ^
 -O0 ^
 -o ../Output/Sandbox/Web/Debug/Sandbox.html ^