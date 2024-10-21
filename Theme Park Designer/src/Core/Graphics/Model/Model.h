#ifndef MODEL_H
#define MODEL_H

#include <memory>

#include <Core/Graphics/Buffers/VertexArray.h>
#include <glm/glm.hpp>

namespace TPD::Graphics
{

    class Model
    {
    public:
        Model(std::unique_ptr<VertexArray>& vao);

        inline VertexArray* GetVAO() const { return m_vao.get(); }

    private:
        std::unique_ptr<VertexArray> m_vao;
        glm::mat4 m_model = glm::mat4(1.0f);
    };

}

#endif /* MODEL_H */