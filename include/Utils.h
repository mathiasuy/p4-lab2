#ifndef UTILS_H
#define UTILS_H
#include <string>


class Utils
{
    private:
        Utils();
        virtual ~Utils();

    public:
        static std::string aString (int arg);
        static std::string aString (float arg);

};

#endif // UTILS_H
