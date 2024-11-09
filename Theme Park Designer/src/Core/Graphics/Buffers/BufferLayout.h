#ifndef BUFFER_LAYOUT_H
#define BUFFER_LAYOUT_H

namespace TPD::Graphics
{

    enum class ShaderDataType
    {
        None = 0,
        Float,
        Int,
        Bool
    };

    struct BufferLayoutElement
    {
    public:
        uint32_t count;
        ShaderDataType type;
        bool normalized;
        uint64_t offset = 0;
    };
 
    class BufferLayout
    {
    public:
        BufferLayout(std::vector<BufferLayoutElement> layout);
        ~BufferLayout();

        inline const std::vector<BufferLayoutElement>& GetLayout() const { return m_layout; }
        inline const uint32_t& GetStride() const { return m_stride; }

    private:
        std::vector<BufferLayoutElement> m_layout;
        uint32_t m_stride = 0;

    private:
        inline uint32_t GetShaderDataTypeSize(ShaderDataType type) const
        {
            switch (type)
            {
            case ShaderDataType::Float:
                return sizeof(float);
            case ShaderDataType::Int:
                return sizeof(int);
            case ShaderDataType::Bool:
                return sizeof(bool);
            default:
                return 0;
            }
        }
    };

}

#endif /* BUFFER_LAYOUT_H */