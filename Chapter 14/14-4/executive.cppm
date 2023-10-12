export module executive;

import employee;


export class Executive : public Employee
{
    public:
        using Employee::Employee;

        void who() const;
};