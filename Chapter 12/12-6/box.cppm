export module box;


export class Box
{
    public:
        Box() = default;
        Box(double length, double width, double height);


        double volume() const;

        int compare(const Box &box) const;

        void listBox() const;

    private:
        double m_length {1.0};
        double m_width {1.0};
        double m_height {1.0};
};


Box::Box(double length, double width, double height)
    :m_length {length}, m_width {width}, m_height {height}
{};