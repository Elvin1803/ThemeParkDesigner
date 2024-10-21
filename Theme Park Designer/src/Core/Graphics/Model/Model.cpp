#include "Model.h"

#define GLM_ENABLE_EXPERIMENTAL

#ifdef TPD_DEBUG
#include <iostream>
#include <glm/gtx/string_cast.hpp>
#endif // TPD_DEBUG

namespace TPD::Graphics
{

    Model::Model(std::unique_ptr<VertexArray>& vao)
        : m_vao(std::move(vao))
    {
        #ifdef TPD_DEBUG
        std::cout << glm::to_string(m_model) << std::endl;
        #endif // TPD_DEBUG
    }

}
