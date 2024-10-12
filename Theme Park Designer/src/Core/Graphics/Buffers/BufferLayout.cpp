#include "BufferLayout.h"

namespace TPD::Graphics
{

    BufferLayout::BufferLayout(std::vector<BufferLayoutElement> layout)
    {
        uint32_t offset = 0;
        for (auto& element : layout)
        {
            element.offset = offset;

            offset += element.count * GetShaderDataTypeSize(element.type);
        }

        m_layout = std::move(layout);
    }

    BufferLayout::~BufferLayout()
    {
    }

}