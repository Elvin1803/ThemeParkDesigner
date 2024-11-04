#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

namespace TPD
{

    template <class T>
    class ResourceManager
    {
    public:
        ResourceManager() = default;
        ~ResourceManager() = default;

        void PushResource(const std::string& name, std::unique_ptr<T> resource)
        {
            m_pathToID[name] = m_nextResourceID;
            m_resourceMap[m_nextResourceID] = std::move(resource);
            m_nextResourceID += 1;
        }

        T* GetResourceData(uint32_t id)
        {
            return m_resourceMap.at(id).get();
        }

        uint32_t GetResouceID(const std::string& name)
        {
            return m_pathToID.at(name);
        }

    private:
        uint32_t m_nextResourceID = 0;
        std::unordered_map<uint32_t, std::unique_ptr<T>> m_resourceMap;
        std::unordered_map<std::string, uint32_t> m_pathToID;
    };

}

#endif /* RESOURCE_MANAGER_H */