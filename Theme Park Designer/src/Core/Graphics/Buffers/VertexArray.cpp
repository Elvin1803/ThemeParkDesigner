#include "pch.h"
#include "VertexArray.h"

namespace TPD::Graphics
{
    static GLenum ShaderDataTypeToOpenGLBaseType(ShaderDataType type)
    {
        switch (type)
        {
        case ShaderDataType::Float:
            return GL_FLOAT;
        case ShaderDataType::Int:
            return GL_INT;
        case ShaderDataType::Bool:
            return GL_BOOL;
        default:
            return 0;
        }
    }
    
    VertexArray::VertexArray()
    {
        glCreateVertexArrays(1, &m_VAOid);
        glBindVertexArray(m_VAOid);
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &m_VAOid);
    }

    void VertexArray::SetLayout(std::shared_ptr<BufferLayout> layout)
    {
        glBindVertexArray(m_VAOid);
        m_layout = layout;
    }

    void VertexArray::AddVertexBuffer(std::unique_ptr<VertexBuffer> vbo)
    {
        if (m_layout == nullptr)
        {
            TPD_LOG_ERROR("No layout set for this vertex array !");
            return;
        }

        glBindVertexArray(m_VAOid);
        vbo->Bind();

        uint32_t attribIndex = 0;
        for (const auto& element : m_layout->GetLayout())
        {
            switch (element.type)
            {
            case ShaderDataType::Float:
                {
                    glVertexAttribPointer(attribIndex,
                        element.count,
                        ShaderDataTypeToOpenGLBaseType(element.type),
                        element.normalized ? GL_TRUE : GL_FALSE,
                        m_layout->GetStride(),
                        reinterpret_cast<const void*>(element.offset));
                    break;
                }
            case ShaderDataType::Int:
            case ShaderDataType::Bool:
                {
                    glVertexAttribIPointer(attribIndex,
                        element.count,
                        ShaderDataTypeToOpenGLBaseType(element.type),
                        m_layout->GetStride(),
                        reinterpret_cast<const void*>(element.offset));
                    break;
                }
            default:
                {
                    TPD_LOG_WARN("Did not recognize the shader data type");
                    return;
                }
            }

            glEnableVertexAttribArray(attribIndex);
            attribIndex++;
        }

        m_vbo = std::move(vbo);
    }

    void VertexArray::AddIndexBuffer(std::unique_ptr<IndexBuffer> ibo)
    {
        glBindVertexArray(m_VAOid);
        ibo->Bind();
        m_ibo = std::move(ibo);
    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(m_VAOid);
    }
}