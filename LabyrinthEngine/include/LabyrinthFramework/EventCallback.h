//
// Created by Tomas Tzorta on 10/12/2023.
//

#ifndef DELEGATE_H
#define DELEGATE_H
#include <functional>

#include "Core.h"

namespace labyrinth_engine
{
    class Object;
    template <typename ... Arguments> // variadic template
    class EventCallback
    {
    public:
        template<typename ClassName>
        void Bind(Weak<Object> a_object, void (ClassName::*a_function)(Arguments...))
        {
            std::function<bool(Arguments...)> callbackFunction = [a_object, a_function](Arguments... args)->bool
            {
                if (!a_object.expired())
                {
                    (static_cast<ClassName*>(a_object.lock().get())->*a_function)(args...);
                    return true;
                }
                return false;
            };
            m_functions.push_back(callbackFunction);
        }

        void Broadcast(Arguments... args)
        {
            for (auto i = m_functions.begin(); i != m_functions.end();)
            {
                if ((*i)(args...))
                {
                    ++i;
                }
                else
                {
                    i = m_functions.erase(i);
                }
            }
        }
    private:
        List<std::function<bool(Arguments...)>> m_functions;
    };
}




#endif //DELEGATE_H
