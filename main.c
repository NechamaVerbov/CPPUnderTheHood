#include <stdio.h>
#include "polymorphism_defs.h"


void doPrePostFixer()
{
    PrePostFixer angleBrackets;

    printf("\n--- start doPrePostFixer() ---\n\n");

    _PrePostFixerpPrePostFixerss(&angleBrackets, "<<< ", " >>>");
    _printpPrePostFixers(&angleBrackets, "Hello World!");
    _printpPrePostFixerlc(&angleBrackets, -777, '\0');
    _printpPrePostFixerlc(&angleBrackets,350, '#');
    _printpPrePostFixerlc(&angleBrackets, 3, '\0');

    printf("\n--- end doPrePostFixer() ---\n\n");

    _d_PrePostFixerpPrePostFixer(&angleBrackets);
}

void doPrePostDollarFixer()
{
    PrePostDollarFixer asterisks;

    printf("\n--- start doPrePostDollarFixer() ---\n\n");

    PrePostDollarFixerpPrePostDollarFixerss(&asterisks,"***** ", " *****");
    _printpPrePostDollarFixeric(&asterisks, -777, '$');
    _printpPrePostDollarFixeric(&asterisks, 350, '#');
    _printpPrePostDollarFixerdc(&asterisks, 3.14f, '$');

    printf("\n--- end doPrePostDollarFixer() ---\n\n");

    _d_PrePostDollarFixerpPrePostDollarFixer(&asterisks);
}
/*
void doPrePostChecker()
{
    printf("\n--- start doPrePostChecker() ---\n\n");

    PrePostChecker check;
    check.printThisSymbolUsingFunc();
    check.printThisSymbolDirectly();
    check.printDollarSymbolByCastDirectly();
    check.printDollarSymbolByScopeDirectly();
    check.printDollarSymbolByCastUsingFunc();
    check.printDollarSymbolByScopeUsingFunc();

    printf("\n--- end doPrePostChecker() ---\n\n");
}

void doPrePostFloatDollarFixer()
{
    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");

    PrePostFloatDollarFixer hashes("### ", " ###");
    hashes.print(-777);
    hashes.print(350, '#');
    hashes.print(3.14f);

    PrePostDollarFixer hashes2(hashes);
    hashes2.print(7.5);
    hashes2.print(100);

    printf("\n--- start doPrePostFloatDollarFixer() ---\n\n");
}
*/
void runAsPrePostFixerRef(const PrePostFixer* const pp)
{
    printf("\n--- start runAsPrePostFixerRef() ---\n\n");

    ( (*(pp->defaultTextFormatter.textFormatter.textFormatterVirtualTable))[2])(pp, 123, '\0');

    printf("\n--- end runAsPrePostFixerRef() ---\n\n");
}
/*
void runAsPrePostDollarFixerRef(const PrePostDollarFixer& pp)
{
printf("\n--- start runAsPrePostDollarFixerRef() ---\n\n");

pp.print(123);

printf("\n--- end runAsPrePostDollarFixerRef() ---\n\n");
}

void runAsPrePostDollarFixerObj(const PrePostDollarFixer pp)
{
    printf("\n--- start runAsPrePostDollarFixerObj() ---\n\n");

    pp.print(123);

    printf("\n--- end runAsPrePostDollarFixerObj() ---\n\n");
}

void runAsPrePostHashFixerRef(const PrePostHashFixer& pp)
{
printf("\n--- start runAsPrePostHashFixerRef() ---\n\n");

pp.print(123);

printf("\n--- end runAsPrePostHashFixerRef() ---\n\n");
}

void doMultiplier()
{
    printf("\n--- start doMultiplier() ---\n\n");

    Multiplier m1(3);
    Multiplier m2 = 5;
    Multiplier m3 = m1;
    Multiplier m4(m2);

    m1.print("abc ");
    m2.print("abc ");
    m3.print("abc ");
    m4.print("abc ");

    printf("\n--- start doMultiplier() ---\n\n");
}

void doFormatterArray()
{
    printf("\n--- start doFormatterArray() ---\n\n");

    DefaultTextFormatter formatters[] =
            {
                    PrePostDollarFixer("!!! ", " !!!"),
                    Multiplier(4),
                    PrePostChecker()
            };

    for (int i = 0; i < 3; ++i)
        formatters[i].print("Hello World!");

    printf("\n--- end doFormatterArray() ---\n\n");
}

void doFormatterPtrs()
{
    printf("\n--- start doFormatterPtrs() ---\n\n");

    DefaultTextFormatter* pfmt[] =
            {
                    new PrePostDollarFixer("!!! ", " !!!"),
            new Multiplier(4),
            new PrePostChecker()
            };

    for (int i = 0; i < 3; ++i)
        pfmt[i]->print("Hello World!");

    for (int i = 2; i >= 0; --i)
        delete pfmt[i];

    printf("\n--- end doFormatterPtrs() ---\n\n");
}

void doFormatterDynamicArray()
{
    printf("\n--- start doFormatterDynamicArray() ---\n\n");

    DefaultTextFormatter* formatters = generateFormatterArray();

    for (int i = 0; i < 3; ++i)
        formatters[i].print("Hello World!");

    delete[] formatters;

    printf("\n--- start doFormatterDynamicArray() ---\n\n");
}
*/
int main()
{
    printf("\n--- Start main() ---\n\n");


    /*doPrePostFixer();
     doPrePostDollarFixer();
      doPrePostFloatDollarFixer();
      doPrePostChecker();
*/
      PrePostHashFixer hfix;
    _PrePostHashFixerpPrePostHashFixeri(&hfix, 4);
    runAsPrePostFixerRef(&hfix);
    /*  runAsPrePostDollarFixerRef(hfix);
      runAsPrePostDollarFixerObj(hfix);
      runAsPrePostHashFixerRef(hfix);

      doMultiplier();

      doFormatterArray();
      doFormatterPtrs();
      doFormatterDynamicArray();*/

    printf("\n--- End main() ---\n\n");

    _d_PrePostHashFixerpPrePostHashFixer(&hfix);
    return 0;
}






/*#include <stdio.h>
#include "inheritance_defs.h"

void doMaterials()
{
    Materials mat;
    Material_t mat1;
    Material_t mat2;
    struct MatTest { Materials mat; Material_t mat_t; };

    printf("\n--- Start doMaterials() ---\n\n");


    printf("Size of Materials: %lu\n", sizeof(Materials) + 1);
    printf("Size of mat: %lu\n", sizeof(mat) + 1);
    printf("Size of Materials::Types: %lu\n", sizeof(Types));
    printf("Size of Material_t: %lu\n", sizeof(Material_t));

    printf("Size of Materials + Material_t: %lu\n", sizeof(struct MatTest) + 4);

    mat1.material = OTHER;
    printf("Material created, set to %s\n", "Other");

    mat2.material = METAL;
    printf("Material created, set to %s\n", "Metal");

    printf("\n--- End doMaterials() ---\n\n");
}

void doPhysicalBox()
{
    PhysicalBox pb1;
    PhysicalBox pb2;
    PhysicalBox pb3;
    PhysicalBox pb4;

    printf("\n--- Start doPhysicalBox() ---\n\n");

    _PhysicalBoxpPHYSICALBOXdddTYPES(&pb1, 8, 6, 4, PLASTIC);
    _PhysicalBoxpPHYSICALBOXTYPES(&pb2, WOOD);
    _PhysicalBoxpPHYSICALBOXddd(&pb3, 7, 7, 7);

    printf("\npb4 is copy-constructed from pb1\n");
    pb4 = pb1;
    _printppPHYSICALBOX(&pb4);
    _printppPHYSICALBOX(&pb1);
    printf("pb4 %s pb1\n", true ? "equals" : "does not equal");

    printf("\npb4 is copy-assigned from pb3\n");
    pb4 = pb3;
    _printppPHYSICALBOX(&pb4);
    _printppPHYSICALBOX(&pb3);
    printf("pb4 %s pb3\n", true ? "equals" : "does not equal");

    printf("\n--- End doPhysicalBox() ---\n\n");

    d_PhysicalBoxpPHYSICALBOX(&pb4);
    d_PhysicalBoxpPHYSICALBOX(&pb3);
    d_PhysicalBoxpPHYSICALBOX(&pb2);
    d_PhysicalBoxpPHYSICALBOX(&pb1);
}

void doWeightBox()
{
    WeightBox pw1;
    WeightBox pw2;
    WeightBox pw3;
    WeightBox pw4;

    printf("\n--- Start doWeightBox() ---\n\n");

    _WeightBoxpWEIGHTBOXdddd(&pw1, 8, 6, 4, 25);
    _WeightBoxpWEIGHTBOXdddd(&pw2, 1, 2, 3, 0.0);
    _WeightBoxpWEIGHTBOXdddd(&pw3, 10, 20, 30, 15);

    printf("\npw4 is copy-constructed from pw1\n");
    _copy_WeightBoxpWEIGHTBOX(&pw4, &pw1);
    _printwpWEIGHTBOX(&pw4);
    _printwpWEIGHTBOX(&pw1);
    printf("pw4 %s pw1\n",
            ((pw4.box.height == pw1.box.height && pw4.box.width == pw1.box.width && pw4.box.length == pw1.box.length)
            && pw4.weight == pw1.weight) ? "equals" : "does not equal");

    printf("\npw4 is copy-assigned from pw3\n");
    _assignpWEIGHTBOXdddd(&pw4, &pw3);
    _printwpWEIGHTBOX(&pw4);
    _printwpWEIGHTBOX(&pw3);
    printf("pw4 %s pw3\n",
           ((pw4.box.height == pw3.box.height && pw4.box.width == pw3.box.width && pw4.box.length == pw3.box.length)
            && pw4.weight == pw3.weight) ? "equals" : "does not equal");

    printf("\n--- End doWeightBox() ---\n\n");

    _d_WeightBoxpWEIGHTBOX(&pw4);
    _d_WeightBoxpWEIGHTBOX(&pw3);
    _d_WeightBoxpWEIGHTBOX(&pw2);
    _d_WeightBoxpWEIGHTBOX(&pw1);
}


int main()
{
    printf("\n--- Start main() ---\n\n");

    doMaterials();

    doPhysicalBox();

    doWeightBox();

    printf("\n--- End main() ---\n\n");

}
 */

/*#include <stdio.h>
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

    b3 = b2;
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
    message = "This is the total volume on the shelf:";
    _printpSHELF(&aShelf);
    message = "Shelf's volume:";
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
}*/
