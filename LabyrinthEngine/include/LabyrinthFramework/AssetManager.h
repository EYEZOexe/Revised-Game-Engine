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
        static AssetManager& GetInstance(); //Making a singleton
        Shared<sf::Texture> LoadTexture(const std::string& a_filename); //Load a texture
        Shared<sf::Font> LoadFont(const std::string& a_filename); //Load a font
        Shared<sf::SoundBuffer> LoadSoundBuffer(const std::string& a_filename); //Load a sound buffer
        void Clear(); //Clear the asset manager
        void SetAssetDirectory(const std::string& a_directory); //Set the asset directory
    protected:
        AssetManager(); //Constructor

    private:
        template<typename T>
        Shared<T> LoadAsset(const std::string& a_filename, Dictionary<std::string, Shared<T>>& a_map); //Load an asset

        template<typename T>
        void ClearAssetMap(Dictionary<std::string, Shared<T>>& a_map); //Clear an asset map

        static Unique<AssetManager> assetManager; //The asset manager
        Dictionary<std::string, Shared<sf::Texture>> m_mLoadedTextures; //The loaded textures
        Dictionary<std::string, Shared<sf::Font>> m_mLoadedFonts; //The loaded fonts
        Dictionary<std::string, Shared<sf::SoundBuffer>> m_mLoadedSoundBuffers; //The loaded sound buffers
        std::string m_assetDirectory; //The asset directory
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
    void AssetManager::ClearAssetMap(Dictionary<std::string, Shared<T>>& a_map) //Clear an asset map
    {
        for (auto iterator = a_map.begin(); iterator != a_map.end();) // iterate through map
        {
            if (iterator->second.use_count() == 1) // if texture is only referenced by map
            {
                LE_LOG("Cleaning: %s", iterator->first.c_str()); // log cleaning
                iterator = a_map.erase(iterator); // erase texture from map
            }
            else
            {
                ++iterator; // increment iterator
            }
        }
    }
}



#endif //ASSETMANAGER_H
