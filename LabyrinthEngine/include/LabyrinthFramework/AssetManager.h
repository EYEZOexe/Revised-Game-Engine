//
// Created by Tomas Tzorta on 07/12/2023.
//

#ifndef ASSETMANAGER_H
#define ASSETMANAGER_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Core.h"

namespace labyrinth_engine
{
    class AssetManager
    {
    public:
        static AssetManager& GetInstance();
        Shared<sf::Texture> LoadTexture(const std::string& a_filename);
        Shared<sf::Font> LoadFont(const std::string& a_filename);
        Shared<sf::SoundBuffer> LoadSoundBuffer(const std::string& a_filename);
        void Clear();
        void SetAssetDirectory(const std::string& a_directory);
    protected:
        AssetManager();

    private:
        template<typename T>
        Shared<T> LoadAsset(const std::string& a_filename, Dictionary<std::string, Shared<T>>& a_map);

        template<typename T>
        void ClearAssetMap(Dictionary<std::string, Shared<T>>& a_map);

        static Unique<AssetManager> assetManager;
        Dictionary<std::string, Shared<sf::Texture>> m_mLoadedTextures;
        Dictionary<std::string, Shared<sf::Font>> m_mLoadedFonts;
        Dictionary<std::string, Shared<sf::SoundBuffer>> m_mLoadedSoundBuffers;
        std::string m_assetDirectory;
    };

    template<typename T>
    Shared<T> AssetManager::LoadAsset(const std::string& a_filename, Dictionary<std::string, Shared<T>>& a_map)
    {
        const auto pairFound = a_map.find(a_filename); // check if texture is already loaded
        if (pairFound != a_map.end()) // if texture is already loaded
        {
            return pairFound->second; // return texture
        }

        Shared<T> newAsset{new T}; // load texture
        if (newAsset->loadFromFile(m_assetDirectory + a_filename)) // if texture is loaded
        {
            a_map.insert({a_filename, newAsset}); // insert texture into map
            return newAsset; // return texture
        }

        return Shared<T> {nullptr}; // return nullptr if texture is not loaded
    }

    template<typename T>
    void AssetManager::ClearAssetMap(Dictionary<std::string, Shared<T>>& a_map)
    {
        for (auto iterator = a_map.begin(); iterator != a_map.end();)
        {
            if (iterator->second.use_count() == 1)
            {
                LE_LOG("Cleaning: %s", iterator->first.c_str());
                iterator = a_map.erase(iterator);
            }
            else
            {
                ++iterator;
            }
        }
    }
}



#endif //ASSETMANAGER_H
