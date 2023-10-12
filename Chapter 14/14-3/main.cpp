import <iostream>;

import aardvark;
import lion;


int main()
{
    Aardvark aardvark { "Algernon", 50 };
    Lion lion { "Leo", 400 };

    aardvark.who();
    lion.who();

    return 0;
}