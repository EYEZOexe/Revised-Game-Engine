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
    using Unique = std::unique_ptr<T>;

    template<typename T>
    using Shared = std::shared_ptr<T>;

    template<typename T>
    using Weak = std::weak_ptr<T>;

    template<typename T>
    using List = std::vector<T>;

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
