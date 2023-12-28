//
// Created by Tomas Tzorta on 28/12/2023.
//

#ifndef MAINMENU_H
#define MAINMENU_H

#include "LabyrinthFramework/World.h"

namespace labyrinth_engine
{
    class MainMenuHUD;

    class MainMenu : public World
    {
    public:
        /* Constructors and Destructors */
        MainMenu(Application* a_application);
        /* End of Constructors and Destructors */

        /* Class Functions */

        // Void Functions

        // Boolean Functions

        // Virtual Functions
        void BeginPlay() override;

        /* End of Class Functions */

        /* Override Functions */
        /* End of Override Functions */

        /* Setters and Getters */

        // Setters

        // Getters

        /* End of Setters and getters */

    protected:

    private:
        void StartGame(); // start game
        void QuitGame(); // quit game
        Weak<MainMenuHUD> m_mainMenuHUD;
    };
}

#endif //MAINMENU_H
