#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/glm.hpp>

namespace TPD::Graphics
{

    struct Material
    {
    public:
        glm::vec3 ambiantColor; // Ka
        glm::vec3 diffuseColor; // Kd
        glm::vec3 specularColor; // Ks
        float specularExponent; // Ns
        glm::vec3 emissiveColor; // Ke
        float dissolve; // d
        float opticalDensity; // Ni
    };

}

#endif /* MATERIAL_H */