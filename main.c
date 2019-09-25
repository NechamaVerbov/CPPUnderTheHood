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
        _BoxpBddd(&largeBox, 10,20,30);
    }
}


void thisFunc()
{
    printf("\n--- thisFunc() ---\n\n");

    if(flag99)
    {
        flag99 = false;
        _BoxpBddd(&box99, 99,99,99);
    }

    _multAssignpBd(&box99, 10);
}

void thatFunc()
{
    printf("\n--- thatFunc() ---\n\n");

    if(flag88)
    {
        flag88 = false;
        _BoxpBddd(&box88, 88,88,88);
    }

    _multAssignpBd(&box88, 10);
}

void doBoxes()
{
    Box b1;
    Box b2;
    Box b3;
    Box b4;

    printf("\n--- Start doBoxes() ---\n\n");

    _BoxpBd(&b1, 3);

    _BoxpBddd(&b2, 4, 5, 6);

    printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
    printf("b2 volume: %f\n", b2.width * b2.length * b2.height);

    _multAssignpBd(&b1, 1.5);
    _multAssignpBd(&b2, 0.5);

    printf("b1 volume: %f\n", b1.width * b1.length * b1.height);
    printf("b2 volume: %f\n", b2.width * b2.length * b2.height);

    b3 = b2;
    b4 = _multpBd(&b2, 3);
    printf("b3 %s b4\n", (b3.width == b4.width && b3.height == b4.height && b3.length == b4.length)
                             ? "equals" : "does not equal");

    _multAssignpBd(&b3, 1.5);
    _multAssignpBd(&b4, 0.5);
    printf("Now, b3 %s b4\n", (b3.width == b4.width && b3.height == b4.height && b3.length == b4.length)
                             ? "equals" : "does not equal");

    printf("\n--- End doBoxes() ---\n\n");

    _d_BoxpB(&b4);
    _d_BoxpB(&b3);
    _d_BoxpB(&b2);
    _d_BoxpB(&b1);

}

void doShelves()
{
    Box aBox;
    Box temp1;
    Box temp2;

    Shelf aShelf;

    printf("\n--- start doShelves() ---\n\n");

    _BoxpBd(&aBox,5);

    _ShelfpS(&aShelf);

    _printpS(&aShelf);
    _setBoxpSipB(&aShelf, 1, &largeBox);
    _setBoxpSipB(&aShelf, 0, &aBox);

    _printpS(&aShelf);
     _setMessagepC("This is the total volume on the shelf:");
    _printpS(&aShelf);
     _setMessagepC("Shelf's volume:");
    _printpS(&aShelf);

    _BoxpBddd(&temp1,2,4,6);
    _setBoxpSipB(&aShelf, 1, &temp1);
    _d_BoxpB(&temp1);

    _BoxpBd(&temp2,2);
    _setBoxpSipB(&aShelf, 2, &temp2);
    _d_BoxpB(&temp2);
    _printpS(&aShelf);

    printf("\n--- end doShelves() ---\n\n");

    _d_ShelfpS(&aShelf);
    _d_BoxpB(&aBox);
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

    _d_BoxpB(&box99);
    _d_BoxpB(&largeBox);

    return 0;
}
