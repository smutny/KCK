
#pragma once

#ifdef SFML_STATIC
#pragma comment(lib, "glew.lib")
#pragma comment(lib, "freetype.lib")
#pragma comment(lib, "jpeg.lib")
#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")
#pragma comment(lib, "gdi32.lib")  
#endif // SFML_STATIC

//SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

//biblioteka standardowa
#include <iostream>
#include <sstream>

#include <locale>
#include <chrono>
#include <random>
#include <algorithm>

#include <string>
#include <vector>
#include <map>
#include <iterator>

#include <memory>


//windows
#include <Windows.h>
#include <stringapiset.h>



using namespace std;

