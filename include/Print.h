#include <iostream>
#include <string_view>

namespace PySTL
{

// TODO [dshvetsov] : Make more efficient.
// TODO [dshvetsov] : Add support to write in any ostream.
// TODO [dshvetsov] : Add support of output specification
//                    (such set_precision, set_base, etc).

namespace detail {

template <typename Head, typename... Args>
class print_impl
{
public:
    print_impl(const Head& head, const Args&... tail)
        : m_head(head), m_tail(tail...)
    { }

    print_impl(const Head& head)
        : m_head(head), m_tail()
    { }

    void flush(std::ostream& out, const std::string_view& sep)
    {
        out << m_head << sep;
        m_tail.flush(out, sep);
    }

private:
    const Head& m_head;
    print_impl<Args...> m_tail;
};

template <typename Head>
class print_impl<Head>
{
public:
    print_impl(const Head& head)
        : m_head(head)
    { }

    void flush(std::ostream& out, const std::string_view&) {
        out << m_head;
    }
private:
    const Head& m_head;
};

struct Unit; // empty class

template<>
class print_impl<Unit>
{
public:
    print_impl()
    { }

    void flush(std::ostream& out, const std::string_view&) {
        // do nothing
    }
};

template <typename... Args>
class print_holder {
public:

    print_holder& end(std::string_view e)
    {
        m_end = e;
        return *this;
    }

    print_holder& sep(std::string_view s)
    {
        m_sep = s;
        return *this;
    }

    print_holder& file(std::ostream& out)
    {
        m_out = &out;
        return *this;
    }

    print_holder& flush(bool value)
    {
        need_flush = value;
    }

    print_holder(const Args&... args)
        : m_data(args...)
    { }

    ~print_holder() noexcept
    {
        m_data.flush(*m_out, m_sep);
        *m_out << m_end;
        if (need_flush) {
            m_out->flush();
        }
    }

    // Cannot be copied or moved
    print_holder(const print_holder&) = delete;
    print_holder(print_holder&&) = delete;

private:
    std::ostream* m_out = &std::cout; // Cannot use refernce
                                     // becouse it may be replaced
    std::string_view m_sep = " ";
    std::string_view m_end = "\n";
    bool need_flush = false;
    print_impl<Args..., Unit> m_data;
};


} // namespace deatail

template <typename... Args>
detail::print_holder<Args...> print(const Args&... args)
{
    return detail::print_holder<Args...>(args...);
}

} // namespace PySTL
