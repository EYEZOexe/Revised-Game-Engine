//
// Created by Tomas Tzorta on 10/12/2023.
//

#ifndef DELEGATE_H
#define DELEGATE_H
#include "Core.h"
#include "LabyrinthEngine/Object.h"

namespace labyrinth_engine
{
    template <typename ... Arguments> // variadic template
    class EventCallback
    {
    public:
        template<typename ClassName>
        void Bind(Wptr<Object> a_object, void (ClassName::*a_function)(Arguments...))
        {

        }
    };
}




#endif //DELEGATE_H
