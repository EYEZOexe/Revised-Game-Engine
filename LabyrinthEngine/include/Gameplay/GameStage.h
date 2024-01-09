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
        EventCallback<> onEndStageEvent; // Event called when the stage is finished

        // Void Functions

        // Boolean Functions
        bool IsStageFinished() const {return m_bIsStageFinished;} // Returns true if the stage is finished

        // Virtual Functions
        virtual void StartStage(); // Called when the stage starts
        virtual void UpdateStage(float a_deltaTime); // Called every frame
        virtual void EndStage(); // Called when the stage ends

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters

        // Getters
        const World* GetWorld() const {return m_world;} // Returns the world
        World* GetWorld() {return m_world;}        // Returns the world

        /* End of Setters and getters */

    protected:

    private:
        virtual void StageEnded(); // Called when the stage is finished
        World* m_world;
        bool m_bIsStageFinished;
    };
}

#endif //GAMESTAGE_H
