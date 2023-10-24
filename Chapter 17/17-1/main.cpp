import myArray;
import <iostream>;

int main()
{
	const unsigned numElements { 100 };

	MyArray<unsigned int> squares;       // default construction

	for (unsigned i {}; i < numElements; ++i)
	{
		squares.push_back(i * i);    // push_back()
	}


	std::cout << squares.getSize() << " squares were added." << std::endl;
	std::cout << "For instance: 13 squared equals " << squares[13] << std::endl;
}