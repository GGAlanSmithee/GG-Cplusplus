#include "Utility/Utility.h"

namespace GGUtility
{
    std::vector<std::string> Split(const std::string& s, char delim)
    {
        std::vector<std::string> elems;

        std::stringstream ss(s);
        std::string item;

        while (std::getline(ss, item, delim))
        {
            elems.push_back(item);
        }

        return elems;
    }

    std::vector<int> ToInts(const std::string& s)
    {
        auto partStrings = Split(s, ' ');

        std::vector<int> ints;

        for (auto ps : partStrings)
        {
            ints.push_back(std::stoi(ps));
        }

        return ints;
    }

    std::vector<float> ToFloats(const std::string& s)
    {
        auto partStrings = Split(s, ' ');

        std::vector<float> floats;

        for (auto ps : partStrings)
        {
            floats.push_back(std::stof(ps));
        }

        return floats;
    }

    const bool EndsWith(const std::string& fullString, const std::string& ending)
    {
        if (fullString.length() >= ending.length())
        {
            return fullString.compare(fullString.length() - ending.length(), ending.length(), ending) == 0;
        }

        return false;
    }
}
