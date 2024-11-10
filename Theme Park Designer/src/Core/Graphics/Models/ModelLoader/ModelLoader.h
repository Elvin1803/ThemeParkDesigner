#ifndef MODEL_LOADER_H
#define MODEL_LOADER_H

#include "../Model.h"

namespace TPD::Graphics
{

    class ModelLoader
    {
    public:
        static void LoadFromFile(const std::string& filePath);
    };

}

#endif /* MODEL_LOADER_H */