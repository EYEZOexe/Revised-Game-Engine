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
        return LoadAsset(a_filename, m_mLoadedTextures);
    }

    Shared<sf::Font> AssetManager::LoadFont(const std::string& a_filename)
    {
        return LoadAsset(a_filename, m_mLoadedFonts);
    }

    void AssetManager::Clear()
    {
        ClearAssetMap(m_mLoadedTextures);
        ClearAssetMap(m_mLoadedFonts);
    }

    void AssetManager::SetAssetDirectory(const std::string& a_directory)
    {
        m_assetDirectory = a_directory;
    }

    AssetManager::AssetManager() : m_assetDirectory{}
    {

    }
}
