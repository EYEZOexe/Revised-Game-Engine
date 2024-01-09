//
// Created by Tomas Tzorta on 07/12/2023.
//

#ifndef CORE_H
#define CORE_H

#include <stdio.h>
#include <memory>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

namespace labyrinth_engine
{
    template<typename T>
    using Unique = std::unique_ptr<T>; //Unique pointer is a smart pointer that owns and manages another object through a pointer and disposes of that object when the unique_ptr goes out of scope.

    template<typename T>
    using Shared = std::shared_ptr<T>; // Shared pointer is a smart pointer that retains shared ownership of an object through a pointer. Several shared_ptr objects may own the same object.

    template<typename T>
    using Weak = std::weak_ptr<T>; // Weak pointer is a smart pointer that holds a non-owning ("weak") reference to an object that is managed by std::shared_ptr.

    template<typename T>
    using List = std::vector<T>; // a list is slower but it's ordered.

    template<typename a_keyType, typename a_valueType, typename a_predicate = std::less<a_keyType>>
    using Map = std::map<a_keyType, a_valueType, a_predicate>; // a map is slower but it's ordered.

    template<typename a_keyType, typename a_valueType, typename a_hasher = std::hash<a_keyType>>
    using Dictionary = std::unordered_map<a_keyType, a_valueType, a_hasher>; // a hash map or dictionary is faster than a map but it's unordered.

    template<typename T>
    using Set = std::unordered_set<T>; // a hash set is faster than a set but it's unordered.

    using uint8 = unsigned char; // 1 byte


#define LE_LOG(x, ...) printf(x "\n", ##__VA_ARGS__), fflush(stdout) // This is a macro, the 2 ## are for when there are no arguments, it will still compile.
}




#endif //CORE_H
