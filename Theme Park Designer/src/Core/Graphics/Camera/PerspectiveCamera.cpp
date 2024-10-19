#include "PerspectiveCamera.h"

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/quaternion.hpp>

#ifdef TPD_DEBUG
#include <iostream>
#include <glm/gtx/string_cast.hpp>
#endif /* TPD_DEBUG */

namespace TPD::Graphics
{
    PerspectiveCamera::PerspectiveCamera(viewportRect& r)
        : Camera(r)
    {
        #ifdef TPD_DEBUG
        std::cout << "Aspect ratio: " << GetAspectRatio() << std::endl;
        #endif /* TPD_DEBUG */

        UpdateProjection();
    }

    void PerspectiveCamera::SetFOV(float fov)
    {
        m_FOV = fov;
        UpdateProjection();
    }

    void PerspectiveCamera::SetPosition(glm::vec3& position)
    {
    }

    void PerspectiveCamera::SetRotation(glm::vec3& rotation)
    {
    }

    void PerspectiveCamera::UpdateProjection()
    {
        m_projection = glm::perspective(glm::radians(m_FOV), GetAspectRatio(), m_nearPlane, m_farPlane);

        #ifdef TPD_DEBUG
        std::cout << glm::to_string(m_projection);
        #endif /* TPD_DEBUG */
    }

}