module curveball;


Curveball::Curveball(std::string_view message)
    : m_message { message } {};


const char* Curveball::what() const noexcept
{
    return m_message.c_str();
}