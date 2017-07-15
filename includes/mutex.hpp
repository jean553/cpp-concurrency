/**
 * @brief example of std::mutex usage
 */

#include <string>
#include <map>

namespace std
{
class mutex;
}

/**
 * @brief get a result after three seconds and store it into a map
 *
 * @param key the key to add into the map
 * @param data the data to insert into the map at the given key
 * @param container the shared map to modify
 */
void saveContent(
    const std::string& key,
    const unsigned short& data,
    std::mutex& mutex,
    std::map<std::string, unsigned short>& container
);

/**
 * @brief trigger a concurrent access to the same resource
 */
void functionThatNeedsMutex();
