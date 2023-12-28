//
// Created by Tomas Tzorta on 28/12/2023.
//

#include "Enemy/MadMaxGameStage.h"
#include "Enemy/RookieEnemy.h"
#include "Enemy/CopyCatEnemy.h"
#include "Enemy/EnforcerEnemy.h"
#include "Enemy/DancerEnemy.h"
#include "LabyrinthFramework/World.h"
#include "LabyrinthFramework/MathUtility.h"

namespace labyrinth_engine
{
    MadMaxGameStage::MadMaxGameStage(World* a_world)
        : GameStage{a_world}
        , m_enemySpawnInterval{4.0f}
        , m_enemyMinimumSpawnInterval{0.8f}
        , m_enemySpawnDecreaseFactor{0.5f}
        , m_enemySpawnDecreaseRate{5.0f}
        , m_madMaxStageDuration{60.0f}
    {

    }

    void MadMaxGameStage::StartStage()
    {
        // Spawn the first enemy
        m_enemySpawnTimerHandler = TimeManager::GetInstance().SetTimer(GetWeakReference(), &MadMaxGameStage::SpawnRookie, m_enemySpawnInterval);
        m_difficultyIncreaseTimerHandler = TimeManager::GetInstance().SetTimer(GetWeakReference(), &MadMaxGameStage::IncreaseStageDifficulty, m_enemySpawnDecreaseRate, true); // Increase the difficulty of the stage
        TimeManager::GetInstance().SetTimer(GetWeakReference(), &MadMaxGameStage::StageDurationEnded, m_madMaxStageDuration); // Set the timer for the stage duration
    }

    void MadMaxGameStage::StageEnded()
    {
        // Remove the timers
        TimeManager::GetInstance().RemoveTimer(m_enemySpawnTimerHandler); // Remove the enemy spawn timer
        TimeManager::GetInstance().RemoveTimer(m_difficultyIncreaseTimerHandler); // Remove the difficulty increase timer
    }

    void MadMaxGameStage::SpawnRookie()
    {
        // Spawn a rookie enemy
        Weak<RookieEnemy> rookie = GetWorld()->SpawnActor<RookieEnemy>(); // Spawn the rookie enemy
        rookie.lock()->SetActorLocation(GetEnemyRandomSpawnPosition()); // Set the spawn position
        m_enemySpawnTimerHandler = TimeManager::GetInstance().SetTimer(GetWeakReference(), &MadMaxGameStage::SpawnCopyCat, m_enemySpawnInterval); // Spawn a copy cat enemy
    }

    void MadMaxGameStage::SpawnCopyCat()
    {
        // Spawn a copy cat enemy
        Weak<CopyCatEnemy> copyCat = GetWorld()->SpawnActor<CopyCatEnemy>();
        copyCat.lock()->SetActorLocation(GetEnemyRandomSpawnPosition()); // Set the spawn position
        m_enemySpawnTimerHandler = TimeManager::GetInstance().SetTimer(GetWeakReference(), &MadMaxGameStage::SpawnEnforcer, m_enemySpawnInterval); // Spawn an enforcer enemy
    }

    void MadMaxGameStage::SpawnEnforcer()
    {
        // Spawn an enforcer enemy
        Weak<EnforcerEnemy> enforcer = GetWorld()->SpawnActor<EnforcerEnemy>();
        enforcer.lock()->SetActorLocation(GetEnemyRandomSpawnPosition()); // Set the spawn position
        m_enemySpawnTimerHandler = TimeManager::GetInstance().SetTimer(GetWeakReference(), &MadMaxGameStage::SpawnDancer, m_enemySpawnInterval); // Spawn a dancer enemy
    }

    void MadMaxGameStage::SpawnDancer()
    {
        sf::Vector2f spawnPosition = GetEnemyRandomSpawnPositionEdge();

        auto windowSize = GetWorld()->GetWindowSize();
        sf::Vector2f center{windowSize.x/2.0f , windowSize.y/2.0f}; // Center of the screen
        sf::Vector2f direction = center - spawnPosition; // Direction from the center to the spawn position
        NormalizeVector(direction); // Normalize the direction

        Weak<DancerEnemy> dancer = GetWorld()->SpawnActor<DancerEnemy>(direction * 200.0f); // Spawn the dancer enemy and set the velocity
        dancer.lock()->SetActorLocation(spawnPosition); // Set the spawn position

        m_enemySpawnTimerHandler = TimeManager::GetInstance().SetTimer(GetWeakReference(), &MadMaxGameStage::SpawnRookie, m_enemySpawnInterval); // Spawn a rookie enemy
    }

    void MadMaxGameStage::IncreaseStageDifficulty()
    {
        // Increase the difficulty of the stage
        m_enemySpawnInterval -= m_enemySpawnDecreaseFactor; // Decrease the spawn interval
        if (m_enemySpawnInterval < m_enemyMinimumSpawnInterval)
        {
            m_enemySpawnInterval = m_enemyMinimumSpawnInterval;
        }
    }

    void MadMaxGameStage::StageDurationEnded()
    {
        EndStage();
    }

    sf::Vector2f MadMaxGameStage::GetEnemyRandomSpawnPosition() const
    {
        auto windowSize = GetWorld()->GetWindowSize();
        float enemySpawnLeft = RandomFloat(100.0f, windowSize.x - 100.0f);
        float enemySpawnTop = -100.0f;
        return {enemySpawnLeft, enemySpawnTop};
    }

    sf::Vector2f MadMaxGameStage::GetEnemyRandomSpawnPositionEdge() const
    {
        auto windowSize = GetWorld()->GetWindowSize();
        float enemySpawnLeft = RandomFloat(-1, 1);
        float enemySpawnX = 0;

        if (enemySpawnLeft < 0)
        {
            enemySpawnX = windowSize.x + 100;
        }
        else
        {
            enemySpawnX = -100.0f;
        }

        float enemySpawnTop = RandomFloat(0, windowSize.y);
        return {enemySpawnX, enemySpawnTop};
    }
}
