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
        void Bind(Weak<Object> a_object, void (ClassName::*a_function)(Arguments...)) // bind a function to a class
        {
            std::function<bool(Arguments...)> callbackFunction = [a_object, a_function](Arguments... args)->bool // lambda function that returns a bool
            {
                if (!a_object.expired()) // if the object is not expired
                {
                    (static_cast<ClassName*>(a_object.lock().get())->*a_function)(args...); // call the function
                    return true; // return true
                }
                return false; // return false
            };
            m_functions.push_back(callbackFunction); // push the function to the list
        }

        void Broadcast(Arguments... args) // broadcast the function
        {
            for (auto i = m_functions.begin(); i != m_functions.end();) // iterate through the list
            {
                if ((*i)(args...)) // if the function returns true
                {
                    ++i; // increment the iterator
                }
                else
                {
                    i = m_functions.erase(i); // erase the function
                }
            }
        }
    private:
        List<std::function<bool(Arguments...)>> m_functions; // list of functions
    };
}




#endif //DELEGATE_H
