CALL mkdir ..\Output\Sandbox\Web\Debug\
CALL emcc ^
 "Sandbox/Main.cpp" ^
 "../Sandbox/Sandbox/InputTests.cpp" ^
 "../Sandbox/Sandbox/_2DScene.cpp" ^
 "../Output/Core/Web/Debug/Core.bc" ^
 "../Dependency/libs/FreeImage/Web/Debug/FreeImage.bc" ^
 "../Dependency/libs/FreeType/Web/Debug/FreeType.bc" ^
 "../Dependency/libs/TinyXML-2/Web/Debug/TinyXML-2.bc" ^
 -I "../Core/" ^
 -D BF_PLATFORM_WEB ^
 -s FULL_ES3=1 ^
 -s USE_WEBGL2=1 ^
 -s TOTAL_MEMORY=268435456 ^
 -std=c++14 ^
 -O0 ^
 -o ../Output/Sandbox/Web/Debug/Sandbox.html ^
 --embed-file Assets