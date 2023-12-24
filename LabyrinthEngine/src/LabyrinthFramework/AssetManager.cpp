//
// Created by Tomas Tzorta on 07/12/2023.
//

#include "LabyrinthFramework/AssetManager.h"

namespace labyrinth_engine
{
    Unique<AssetManager> AssetManager::assetManager{nullptr}; // singleton

    AssetManager& AssetManager::GetInstance()
    {
        if (!assetManager)
        {
            assetManager = Unique<AssetManager>{new AssetManager};
        }
        return *assetManager;
    }

    Shared<sf::Texture> AssetManager::LoadTexture(const std::string& a_filename)
    {
        const auto pairFound = m_mLoadedTextures.find(a_filename); // check if texture is already loaded
        if (pairFound != m_mLoadedTextures.end()) // if texture is already loaded
        {
            return pairFound->second; // return texture
        }

        Shared<sf::Texture> newTexture{new sf::Texture}; // load texture
        if (newTexture->loadFromFile(m_assetDirectory + a_filename)) // if texture is loaded
        {
            m_mLoadedTextures.insert({a_filename, newTexture}); // insert texture into map
            return newTexture; // return texture
        }

        return Shared<sf::Texture> {nullptr}; // return nullptr if texture is not loaded
    }

    Shared<sf::Font> AssetManager::LoadFont(const std::string& a_filename)
    {
        const auto pairFound = m_mLoadedFonts.find(a_filename); // check if texture is already loaded
        if (pairFound != m_mLoadedFonts.end()) // if texture is already loaded
        {
            return pairFound->second; // return texture
        }

        Shared<sf::Font> newFont{new sf::Font}; // load texture
        if (newFont->loadFromFile(m_assetDirectory + a_filename)) // if texture is loaded
        {
            m_mLoadedFonts.insert({a_filename, newFont}); // insert texture into map
            return newFont; // return texture
        }

        return Shared<sf::Font> {nullptr}; // return nullptr if texture is not loaded
    }

    void AssetManager::Clear()
    {
        for (auto iterator = m_mLoadedTextures.begin(); iterator != m_mLoadedTextures.end();)
        {
            if (iterator->second.use_count() == 1)
            {
                LE_LOG("Cleaning up texture: %s", iterator->first.c_str());
                iterator = m_mLoadedTextures.erase(iterator);
            }
            else
            {
                ++iterator;
            }
        }

        for (auto iterator = m_mLoadedFonts.begin(); iterator != m_mLoadedFonts.end();)
        {
            if (iterator->second.use_count() == 1)
            {
                LE_LOG("Cleaning up font: %s", iterator->first.c_str());
                iterator = m_mLoadedFonts.erase(iterator);
            }
            else
            {
                ++iterator;
            }
        }
    }

    void AssetManager::SetAssetDirectory(const std::string& a_directory)
    {
        m_assetDirectory = a_directory;
    }

    AssetManager::AssetManager() : m_assetDirectory{}
    {

    }
}
