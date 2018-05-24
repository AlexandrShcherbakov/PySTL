#include <iostream>

namespace PySTL
{

// TODO [dshvetsov] : Make more efficient.
// TODO [dshvetsov] : Add support to write in any ostream.
// TODO [dshvetsov] : Add support of output specification
//                    (such set_precision, set_base, etc).

namespace detail {

template <typename Head, typename... Args>
class __print_impl
{
public:
    __print_impl(const Head& head, const Args&... tail)
        : m_head(head), m_tail(tail...)
    { }

    void flush(std::ostream& out)
    {
        out << m_head << " ";
        m_tail.flush(out);
    }

private:
    const Head& m_head;
    __print_impl<Args...> m_tail;
};

template <typename Head>
class __print_impl<Head>
{
public:
    __print_impl(const Head& head)
        : m_head(head)
    { }

    void flush(std::ostream& out) {
        out << m_head;
    }
private:
    const Head& m_head;
};

template <typename... Args>
class __print_holder {
public:
    __print_holder(const Args&... args)
        : m_data(args...)
    { }

    ~__print_holder() noexcept
    {
        m_data.flush(m_out);
    }

    // Cannot be copied or moved
    __print_holder(const __print_holder&) = delete;
    __print_holder(__print_holder&&) = delete;

private:
    __print_impl<Args...> m_data;
    std::ostream& m_out = std::cout;
//    std::string delim = " ";
//    std::string endline = "\n";
};


} // namespace deatail

template <typename... Args>
detail::__print_holder<Args...> print(const Args&... args)
{
    return detail::__print_holder<Args...>(args...);
}

} // namespace PySTL
