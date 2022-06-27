//
//  main.cpp
//  Library Management-App
//
//  Created by  Rob the deer on 25.05.2022.
//

#include <iostream>
#include <chrono>
#include <ctime>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "Library.hpp"


using namespace std;

int main(int argc, const char * argv[])
{
    
   
    
    IntroMenu intromenu;
    intromenu.Welcome();
    intromenu.Menu();
    
    return  0;
}
