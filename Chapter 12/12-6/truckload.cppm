export module truckload;

import box;

import <memory>;
import <vector>;

export using SharedBox = std::shared_ptr<Box>;


export class Truckload
{
    public:
        Truckload() = default;

        Truckload(SharedBox box);
        Truckload(const std::vector<SharedBox> &boxes);
        Truckload(const Truckload &src);

        ~Truckload();

        class Iterator;

        Iterator getIterator() const;

        SharedBox getFirstBox();
        SharedBox getNextBox();

        void addBox(SharedBox box);
        bool removeBox(SharedBox box);

        void listBoxes() const;

    private:
        class Package;

        Package *m_head;
        Package *m_tail;
        Package *m_current;
};


class Truckload::Iterator
{
    public:
        SharedBox getFirstBox();
        SharedBox getNextBox();

    private:
        Package *m_head;
        Package *m_current;

        friend class Truckload;

        explicit Iterator(Package *head)
            : m_head {head}, m_current {nullptr} {};
};


class Truckload::Package
{
    public:
        SharedBox m_box;
        Package *m_next;

        Package(SharedBox box) : m_box {box}, m_next {nullptr} {}
        ~Package() { delete m_next; }
};