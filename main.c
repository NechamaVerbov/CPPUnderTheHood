#include <stdio.h>
#include "encapsulation_defs.h"

static Box largeBox;
static Box box88;
static Box box99;

static bool flagLargeBox = true;
static bool flag99 = true;
static bool flag88 = true;

void init_largeBox()
{
    if(flagLargeBox)
    {
        flagLargeBox = false;
        _BoxpBOXddd(&largeBox, 10,20,30);
    }
}


void thisFunc()
{
    printf("\n--- thisFunc() ---\n\n");

    if(flag99)
    {
        flag99 = false;
        _BoxpBOXddd(&box99, 99,99,99);
    }

    _multAssignpBOXd(&box99, 10);
}

void thatFunc()
{
    printf("\n--- thatFunc() ---\n\n");

    if(flag88)
    {
        flag88 = false;
        _BoxpBOXddd(&box88, 88,88,88);
    }

    _multAssignpBOXd(&box88, 10);
}

void doBoxes()
{
    Box b1;
    Box b2;
    Box b3;
    Box b4;

    printf("\n--- Start doBoxes() ---\n\n");

    _BoxpBOXd(&b1, 3);

    _BoxpBOXddd(&b2, 4, 5, 6);

    printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
    printf("b2 volume: %f\n", b2.width * b2.length * b2.height);

    _multAssignpBOXd(&b1, 1.5);
    _multAssignpBOXd(&b2, 0.5);

    printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
    printf("b2 volume: %f\n", b2.width * b2.length * b2.height);

    _copy_BoxpBOXpBOX(&b3, &b2);
    b4 = _multpBOXd(&b2, 3);
    printf("b3 %s b4\n", (b3.width == b4.width && b3.height == b4.height && b3.length == b4.length)
                             ? "equals" : "does not equal");

    _multAssignpBOXd(&b3, 1.5);
    _multAssignpBOXd(&b4, 0.5);
    printf("Now, b3 %s b4\n", (b3.width == b4.width && b3.height == b4.height && b3.length == b4.length)
                             ? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");

    _d_BoxpBOX(&b4);
    _d_BoxpBOX(&b3);
    _d_BoxpBOX(&b2);
    _d_BoxpBOX(&b1);

}

void doShelves()
{
    Box aBox;
    Box temp1;
    Box temp2;

    Shelf aShelf;

    printf("\n--- start doShelves() ---\n\n");

    _BoxpBOXd(&aBox,5);

    _ShelfpSHELF(&aShelf);

    _printpSHELF(&aShelf);
    _setBoxpSHELFipBOX(&aShelf, 1, &largeBox);
    _setBoxpSHELFipBOX(&aShelf, 0, &aBox);

    _printpSHELF(&aShelf);
     _setMessagepC("This is the total volume on the shelf:");
    _printpSHELF(&aShelf);
     _setMessagepC("Shelf's volume:");
    _printpSHELF(&aShelf);

    _BoxpBOXddd(&temp1,2,4,6);
    _setBoxpSHELFipBOX(&aShelf, 1, &temp1);
    _d_BoxpBOX(&temp1);

    _BoxpBOXd(&temp2,2);
    _setBoxpSHELFipBOX(&aShelf, 2, &temp2);
    _d_BoxpBOX(&temp2);
    _printpSHELF(&aShelf);

    printf("\n--- end doShelves() ---\n\n");

    _d_ShelfpSHELF(&aShelf);
    _d_BoxpBOX(&aBox);
}

int main()
{
    init_largeBox();

    printf("\n--- Start main() ---\n\n");

    doBoxes();

    thisFunc();
    thisFunc();
    thisFunc();

    doShelves();

    printf("\n--- End main() ---\n\n");

    _d_BoxpBOX(&box99);
    _d_BoxpBOX(&largeBox);

    return 0;
}
