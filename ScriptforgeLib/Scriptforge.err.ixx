export module Scriptforge.err;
import std;

namespace Scriptforge::Err {
    //建议用E0100~E9999,E0001~E0099留给库内容
    export class Error {
    public:
        Error() = default;
        Error(std::string_view error);
        Error(std::string_view code, std::string_view error);

        std::string_view what() const;
        std::string_view code() const;

        friend std::ostream& operator<<(std::ostream& os, const Error& err);

    private:
        std::string m_code{ "No Code" };
        std::string m_error{ "Unknown Error" };
    };
}