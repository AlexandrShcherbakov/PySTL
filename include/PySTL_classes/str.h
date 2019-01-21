//
// Created by alex on 07.07.2018.
//

#ifndef PYSTL_STR_H
#define PYSTL_STR_H

#include <string>
#include <vector>

namespace PySTL {

    class str {

        std::string container;
    public:
        str() = default;
        str(std::string value) : container(std::move(value)) {}
        str(const char* value) : container(value) {}
//    __repr__: <slot wrapper '__repr__' of 'str' objects>
//    __hash__: <slot wrapper '__hash__' of 'str' objects>
//    __str__: <slot wrapper '__str__' of 'str' objects>
//    __getattribute__: <slot wrapper '__getattribute__' of 'str' objects>
//    __lt__: <slot wrapper '__lt__' of 'str' objects>
//    __le__: <slot wrapper '__le__' of 'str' objects>
//    __eq__: <slot wrapper '__eq__' of 'str' objects>
        bool operator==(const str& another) const {
            return container == another.container;
        }
//    __ne__: <slot wrapper '__ne__' of 'str' objects>
//    __gt__: <slot wrapper '__gt__' of 'str' objects>
//    __ge__: <slot wrapper '__ge__' of 'str' objects>
//    __iter__: <slot wrapper '__iter__' of 'str' objects>
//    __mod__: <slot wrapper '__mod__' of 'str' objects>
//    __rmod__: <slot wrapper '__rmod__' of 'str' objects>
//    __len__: <slot wrapper '__len__' of 'str' objects>
//    __getitem__: <slot wrapper '__getitem__' of 'str' objects>
//    __add__: <slot wrapper '__add__' of 'str' objects>
//    __mul__: <slot wrapper '__mul__' of 'str' objects>
//    __rmul__: <slot wrapper '__rmul__' of 'str' objects>
//    __contains__: <slot wrapper '__contains__' of 'str' objects>
//    __new__: <built-in method __new__ of type object at 0x7fa7e5c71540>
//    encode: <method 'encode' of 'str' objects>
//    replace: <method 'replace' of 'str' objects>
        std::vector<str> split(const int maxsplit = -1) const {
            const str sep = " ";
            std::vector<str> result;
            size_t begin, end;
            for (begin = 0, end = container.find(sep.container);
                    end != std::string::npos && result.size() != maxsplit;
                    begin = end + 1, end = container.find(sep.container, begin)) {
                if (begin == end) {
                    continue;
                }
                result.emplace_back(container.substr(begin, end - begin));
            }
            result.emplace_back(container.substr(begin));
            return result;
        }

        std::vector<str> split(const str& sep, const int maxsplit = -1) const {
            std::vector<str> result;
            size_t begin, end;
            for (begin = 0, end = container.find(sep.container);
                    end != std::string::npos && result.size() != maxsplit;
                    begin = end + 1, end = container.find(sep.container, begin)) {
                result.emplace_back(container.substr(begin, end - begin));
            }
            result.emplace_back(container.substr(begin));
            return result;
        }

//    split: <method 'split' of 'str' objects>
//    rsplit: <method 'rsplit' of 'str' objects>
//    join: <method 'join' of 'str' objects>
//    capitalize: <method 'capitalize' of 'str' objects>
//    casefold: <method 'casefold' of 'str' objects>
//    title: <method 'title' of 'str' objects>
//    center: <method 'center' of 'str' objects>
//    count: <method 'count' of 'str' objects>
//    expandtabs: <method 'expandtabs' of 'str' objects>
//    find: <method 'find' of 'str' objects>
//    partition: <method 'partition' of 'str' objects>
//    index: <method 'index' of 'str' objects>
//    ljust: <method 'ljust' of 'str' objects>
//    lower: <method 'lower' of 'str' objects>
//    lstrip: <method 'lstrip' of 'str' objects>
//    rfind: <method 'rfind' of 'str' objects>
//    rindex: <method 'rindex' of 'str' objects>
//    rjust: <method 'rjust' of 'str' objects>
//    rstrip: <method 'rstrip' of 'str' objects>
//    rpartition: <method 'rpartition' of 'str' objects>
//    splitlines: <method 'splitlines' of 'str' objects>
//    strip: <method 'strip' of 'str' objects>
//    swapcase: <method 'swapcase' of 'str' objects>
//    translate: <method 'translate' of 'str' objects>
//    upper: <method 'upper' of 'str' objects>
//    startswith: <method 'startswith' of 'str' objects>
//    endswith: <method 'endswith' of 'str' objects>
//    islower: <method 'islower' of 'str' objects>
//    isupper: <method 'isupper' of 'str' objects>
//    istitle: <method 'istitle' of 'str' objects>
//    isspace: <method 'isspace' of 'str' objects>
//    isdecimal: <method 'isdecimal' of 'str' objects>
//    isdigit: <method 'isdigit' of 'str' objects>
//    isnumeric: <method 'isnumeric' of 'str' objects>
//    isalpha: <method 'isalpha' of 'str' objects>
//    isalnum: <method 'isalnum' of 'str' objects>
//    isidentifier: <method 'isidentifier' of 'str' objects>
//    isprintable: <method 'isprintable' of 'str' objects>
//    zfill: <method 'zfill' of 'str' objects>
//    format: <method 'format' of 'str' objects>
//    format_map: <method 'format_map' of 'str' objects>
//    __format__: <method '__format__' of 'str' objects>
//    maketrans: <staticmethod object at 0x7fa7e5d28940>
//    __sizeof__: <method '__sizeof__' of 'str' objects>
//    __getnewargs__: <method '__getnewargs__' of 'str' objects>
//    __doc__: str(object='') -> str
//    str(bytes_or_buffer[, encoding[, errors]]) -> str
//
//            Create a new string object from the given object. If encoding or
//    errors is specified, then the object must expose a data buffer
//    that will be decoded using the given encoding and error handler.
//    Otherwise, returns the result of object.__str__() (if defined)
//    or repr(object).
//    encoding defaults to sys.getdefaultencoding().
//    errors defaults to 'strict'.

    };

}
#endif //PYSTL_STR_H
