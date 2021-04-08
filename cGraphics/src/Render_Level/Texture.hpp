//
//  Texture.hpp
//  cGraphics
//
//  Created by Charles callahan on 4/7/21.
//  Copyright © 2021 Charles callahan. All rights reserved.
//

#ifndef Texture_hpp
#define Texture_hpp

#include "cGraphics.h"
#include <stdio.h>
#include <iostream>
#include <string>


class Texture{
public:
    Texture(std::string filename);
    void bind();
private:
    unsigned int texture;
};

#endif /* Texture_hpp */
