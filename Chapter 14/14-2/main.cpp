import <iostream>;

import aardvark;
import lion;


int main()
{
    Aardvark aardvark { "Algernon", 50 };
    Lion lion { "Leo", 400 };

    Lion copyLion = lion;

    aardvark.who();
    copyLion.who();
}