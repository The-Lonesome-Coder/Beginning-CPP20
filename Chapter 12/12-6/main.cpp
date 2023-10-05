import box.random;
import truckload;
import <iostream>;


SharedBox findLargestBox(const Truckload &truckload);
SharedBox findSmallestBox(const Truckload &truckload);


int main()
{
    Truckload load1;

    const size_t boxCount {12};

    for (size_t i = 0; i < boxCount; ++i)
    { load1.addBox(randomSharedBox()); }

    std::cout << "The first list:\n";
    load1.listBoxes();


    Truckload copy = load1;
    std::cout << "The copied truckload:\n";
    copy.listBoxes();


    const auto largestBox = findLargestBox(load1);

    std::cout << "\nThe largest box in the first list is ";
    largestBox->listBox();
    std::cout << std::endl;
    load1.removeBox(largestBox);
    std::cout << "\nAfter deleting the largest box, the list contains:\n";
    load1.listBoxes();

    const size_t nBoxes {20};
    std::vector<SharedBox> boxes;

    for (size_t i = 0; i < nBoxes; ++i)
    { boxes.push_back(randomSharedBox()); }

    Truckload load2 = boxes;
    std::cout << "\nThe second list:\n";
    load2.listBoxes();

    const auto smallestBox {findSmallestBox(load2)};

    std::cout << "\nThe smallest box in the second list is ";
    smallestBox->listBox();
    std::cout << std::endl;
}


SharedBox findLargestBox(const Truckload &truckload)
{
    auto iterator {truckload.getIterator()};

    SharedBox largestBox {iterator.getFirstBox()};

    SharedBox nextBox {iterator.getNextBox()};

    while (nextBox)
    {
        if (nextBox->compare(*largestBox) > 0)
        { largestBox = nextBox; }

        nextBox = iterator.getNextBox();
    }

    return largestBox;
}


SharedBox findSmallestBox(const Truckload &truckload)
{
    auto iterator {truckload.getIterator()};

    SharedBox smallestBox {iterator.getFirstBox()};

    SharedBox nextBox {iterator.getNextBox()};

    while (nextBox)
    {
        if (nextBox->compare(*smallestBox) < 0)
        { smallestBox = nextBox; }

        nextBox = iterator.getNextBox();
    }

    return smallestBox;
}