module Scriptforge.err;
import std;

namespace Scriptforge::Err {
    Error::Error(std::string_view error) : m_error{ error }{}
    Error::Error(std::string_view code, std::string_view error) :m_code{ code }, m_error{ error }{}

    std::string_view Error::what() const { return m_error; }
    std::string_view Error::code() const { return m_code; }

    std::ostream& operator<<(std::ostream& os, const Error& err) {
        os << '[' << err.code() << "] " << err.what();
        return os;
    }
}