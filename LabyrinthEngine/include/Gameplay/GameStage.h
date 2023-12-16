//
// Created by Tomas Tzorta on 16/12/2023.
//

#ifndef GAMESTAGE_H
#define GAMESTAGE_H

#include "LabyrinthFramework/Object.h"
#include "LabyrinthFramework/EventCallback.h"

namespace labyrinth_engine
{
    class World;
    class GameStage : public Object
    {
    public:
        /* Constructors and Destructors */
        GameStage(World* a_world);
        /* End of Constructors and Destructors */

        /* Class Functions */
        EventCallback<> onEndStageEvent;

        // Void Functions

        // Boolean Functions
        bool IsStageFinished() const {return m_bIsStageFinished;}

        // Virtual Functions
        virtual void StartStage();
        virtual void UpdateStage(float a_deltaTime);
        virtual void EndStage();

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters

        // Getters
        const World* GetWorld() const {return m_world;}
        World* GetWorld() {return m_world;}

        /* End of Setters and getters */

    protected:

    private:
        virtual void OnEndStage();
        World* m_world;
        bool m_bIsStageFinished;
    };
}

#endif //GAMESTAGE_H
