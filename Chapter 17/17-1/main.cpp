import myArray;
import <iostream>;

int main()
{
	const unsigned numElements { 10 };

	MyArray<unsigned int> squares;       // default construction

	for (unsigned int i { 1 }; i < numElements; ++i)
	{
		squares.push_back(i * i);    // push_back()
	}


	std::cout << squares.getSize() << " squares were added." << std::endl;
	std::cout << "For instance: 5 squared equals " << squares[5] << std::endl;
}