export module point;


export class Point final
{
    public:
        // Constructor
        Point(const double xPosition, const double yPosition);

        // Getter
        double getX() const;
        double getY() const;

        // Setter
        void setX(const double& newX);
        void setY(const double& newY);


    private:
        double m_xPosition;
        double m_yPosition;
};