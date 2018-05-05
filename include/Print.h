#include <iostream>

namespace PySTL
{

// TODO [dshvetsov] : Make more efficient.
// TODO [dshvetsov] : Add support to write in any ostream.
// TODO [dshvetsov] : Add support of output specification
//                    (such set_precision, set_base, etc).

template <typename Head>
void print(Head&& h)
{
    std::cout << std::forward<Head>(h) << std::endl;
}

template <typename Head, typename... Args>
void print(Head&& h, Args&&... args)
{
    std::cout << std::forward<Head>(h) << " " ;
    print(std::forward<Args>(args)...)...;
}

} // namespace PySTL
