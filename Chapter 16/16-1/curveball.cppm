export module curveball;

import <exception>;
import <string>;
import <string_view>;


export class Curveball : std::exception
{
    public:
        // Constructor
        Curveball(std::string_view message = "25% random Exception detected.");

        // Destructor
        ~Curveball() = default;

        // Return message
        virtual const char* what() const noexcept override;


    private:
        std::string m_message;
};