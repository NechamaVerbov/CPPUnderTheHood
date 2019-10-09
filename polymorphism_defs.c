#include "polymorphism_defs.h"


next_id = 0;


ptrFuncVirtualTable textFormatterVirtualTable = {_d_TextFormatterpTextFormatter};

ptrFuncVirtualTable defaultTextFormatterVirtualTable = {_d_DefaultTextFormatterpDefaultTextFormatter,
                                                        _printpDefaultTextFormatters};

ptrFuncVirtualTable MultiplierVirtualTable = {_d_MultiplierpMultiplier,
                                              _printpMultipliers};

ptrFuncVirtualTable PrePostFixerVirtualTable = {_d_PrePostFixerpPrePostFixer, _printpPrePostFixers,
                                                _printpPrePostFixerlc, _getDefaultSymbolpPrePostFixer};

ptrFuncVirtualTable PrePostDollarFixerVirtualTable = {_d_PrePostDollarFixerpPrePostDollarFixer, _printpPrePostFixers,
                                               _printpPrePostDollarFixerlc, _getDefaultSymbolpPrePostDollarFixer};

ptrFuncVirtualTable PrePostHashFixerVirtualTable = {_d_PrePostHashFixerpPrePostHashFixer, _printpPrePostFixers,
                                                    (_printpPrePostHashFixerlc), _getDefaultSymbolpPrePostHashFixer};

ptrFuncVirtualTable PrePostFloatDollarFixerVirtualTable = {_d_PrePostFloatDollarFixerpPrePostFloatDollarFixer, _printpPrePostFixers,
                                                      _printpPrePostDollarFixerlc, _getDefaultSymbolpPrePostFloatDollarFixer};

ptrFuncVirtualTable PrePostCheckerVirtualTable = {_d_PrePostCheckerpPrePostChecker, _printpPrePostFixers,
                                                           _printpPrePostDollarFixerlc, _getDefaultSymbolpPrePostFloatDollarFixer};



void _d_TextFormatterpTextFormatter(TextFormatter * const this) {}


void _DefaultTextFormatterpDefaultTextFormatter(DefaultTextFormatter * const this)
{
    this->textFormatter.textFormatterVirtualTable = defaultTextFormatterVirtualTable;

    this->id = next_id++;

    printf("--- DefaultTextFormatter Default CTOR\n########## C %d ##########\n", this->id);
}

void _DefaultTextFormatterpDefaultTextFormatterpDefaultTextFormatter
        (DefaultTextFormatter * const this, const DefaultTextFormatter * other)
{
    this->textFormatter.textFormatterVirtualTable = textFormatterVirtualTable;

    this->textFormatter.textFormatterVirtualTable = other->textFormatter.textFormatterVirtualTable;
    this->id = other->id;

    this->textFormatter.textFormatterVirtualTable = defaultTextFormatterVirtualTable; // ???
    this->id = next_id++;

    printf("--- DefaultTextFormatter Copy CTOR, from id: %d\n########## C %d ##########\n", other->id, this->id);

}

DefaultTextFormatter *const _assignpDefaultTextFormatterpDefaultTextFormatter
        (DefaultTextFormatter * const this, const DefaultTextFormatter* const other)
{
    printf("--- DefaultTextFormatter operator=(), from id: %d to id: %d\n", other->id, this->id);
    return this;

}

void _d_DefaultTextFormatterpDefaultTextFormatter(DefaultTextFormatter * this)
{
    printf("--- DefaultTextFormatter DTOR\n########## D %d ##########\n", this->id);

    this->textFormatter.textFormatterVirtualTable = textFormatterVirtualTable;

    _d_TextFormatterpTextFormatter(&this->textFormatter);
}

void _printpDefaultTextFormatters(const DefaultTextFormatter * const this, const char* text)
{
    printf("%-60s | ", "[DefaultTextFormatter::print(const char*)]");
    printf("%s\n", text);
}

DefaultTextFormatter* generateFormatterArray()
{
    DefaultTextFormatter* dtf = malloc(sizeof(DefaultTextFormatter) * 3);
    return dtf;
}


void _PrePostFixerpPrePostFixerss(PrePostFixer * const this, const char* prefix, const char* postfix)
{
    _DefaultTextFormatterpDefaultTextFormatter(&this->defaultTextFormatter);

    this->defaultTextFormatter.textFormatter.textFormatterVirtualTable = PrePostFixerVirtualTable;

    this->pre = prefix;
    this->post = postfix;

    printf("--- PrePostFixer CTOR: \"%s\"...\"%s\"\n", this->pre, this->post);
}

void _d_PrePostFixerpPrePostFixer(PrePostFixer * this)
{
    printf("--- PrePostFixer DTOR: \"%s\"...\"%s\"\n",  this->pre, this->post);

    this->defaultTextFormatter.textFormatter.textFormatterVirtualTable = defaultTextFormatterVirtualTable;

    _d_DefaultTextFormatterpDefaultTextFormatter(&this->defaultTextFormatter);
}

void _printpPrePostFixers(const PrePostFixer * const this, const char* text)
{
    printf("%-60s | ", "[PrePostFixer::print(const char*)]");
    printf("%s%s%s\n", this->pre, text, this->post);

}

void _printpPrePostFixerlc(const PrePostFixer * const this, long num, char symbol /*= '\0'*/)
{
    printf("%-60s | ", "[PrePostFixer::print(long, char)]");
    printf("-->\n");

    if (symbol)
    {
        printf("%-60s | ", "[PrePostFixer::print_num(long, char)]");
           printf("%s%c%ld%s\n", this->pre, symbol, num, this->post);
    }
    else
    {
        printf("%-60s | ", "[PrePostFixer::print_num(long)]");
        printf("%s%ld%s\n", this->pre, num, this->post);
    }
}

char _getDefaultSymbolpPrePostFixer(const PrePostFixer * const this)
{
    return '\0';
}

void PrePostDollarFixerpPrePostDollarFixerss(PrePostDollarFixer *const this, const char* prefix, const char* postfix)
{
    _PrePostFixerpPrePostFixerss(&this->prePostFixer, prefix, postfix);

    this->prePostFixer.defaultTextFormatter.textFormatter.textFormatterVirtualTable = PrePostDollarFixerVirtualTable;

    printf("--- PrePostDollarFixer CTOR: \"%s\"...\"%s\"\n", this->prePostFixer.pre, this->prePostFixer.post);
}

void PrePostDollarFixerpPrePostDollarFixerpPrePostDollarFixer
            (PrePostDollarFixer *const this, const PrePostDollarFixer *const other)
{
    _DefaultTextFormatterpDefaultTextFormatterpDefaultTextFormatter
                 (&this->prePostFixer.defaultTextFormatter, &other->prePostFixer.defaultTextFormatter);

    this->prePostFixer.defaultTextFormatter.textFormatter.textFormatterVirtualTable = PrePostDollarFixerVirtualTable;

    this->prePostFixer.pre = other->prePostFixer.pre;
    this->prePostFixer.post = other->prePostFixer.post;

    printf("--- PrePostDollarFixer Copy CTOR: \"%s\"...\"%s\"\n", this->prePostFixer.pre, this->prePostFixer.post);
}

void _d_PrePostDollarFixerpPrePostDollarFixer(PrePostDollarFixer * this)
{
    printf("--- PrePostDollarFixer DTOR: \"%s\"...\"%s\"\n", this->prePostFixer.pre, this->prePostFixer.post);

    this->prePostFixer.defaultTextFormatter.textFormatter.textFormatterVirtualTable = PrePostFixerVirtualTable;

    _d_PrePostFixerpPrePostFixer(&this->prePostFixer);
}

void _printpPrePostDollarFixerlc(const PrePostDollarFixer *const this, long num, char symbol)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(long, char)]");
    printf("-->\n");

    _printpPrePostFixerlc(&this->prePostFixer, num, symbol);

}
char _getDefaultSymbolpPrePostDollarFixer(const PrePostDollarFixer *const this)
{
    return PrePostDollarFixer_DEFAULT_SYMBOL;
}

void _printpPrePostDollarFixeric(const PrePostDollarFixer *const this, int num, char symbol)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(int, char)]");
    printf("-->\n");

    ((*(this->prePostFixer.defaultTextFormatter.textFormatter.textFormatterVirtualTable))[2])(this, (long)num, symbol);
}

void _printpPrePostDollarFixerdc(const PrePostDollarFixer *const this, double num, char symbol)
{
    printf("%-60s | ", "[PrePostDollarFixer::print(double, char)]");
    printf("%s%c%f%s\n", this->prePostFixer.pre, symbol, num, this->prePostFixer.post);
}

void _PrePostHashFixerpPrePostHashFixeri(PrePostHashFixer * const this, int prc/* = 4*/)
{
    PrePostDollarFixerpPrePostDollarFixerss(&this->postDollarFixer,"===> ", " <===");

    this->postDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.textFormatterVirtualTable
                = PrePostHashFixerVirtualTable;

    this->precision = prc;

    printf("--- PrePostHashFixer CTOR: \"%s\"...\"%s\", precision: %d\n",
            this->postDollarFixer.prePostFixer.pre, this->postDollarFixer.prePostFixer.post, this->precision);

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", this->postDollarFixer.prePostFixer.pre, PrePostHashFixer_DEFAULT_SYMBOL,
            this->precision, 9999.9999, this->postDollarFixer.prePostFixer.post);

}

void _d_PrePostHashFixerpPrePostHashFixer(PrePostHashFixer * this)
{
    printf("--- PrePostHashFixer DTOR: \"%s\"...\"%s\"\n",
           this->postDollarFixer.prePostFixer.pre, this->postDollarFixer.prePostFixer.post);

    this->postDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.textFormatterVirtualTable
    = PrePostDollarFixerVirtualTable;

    _d_PrePostDollarFixerpPrePostDollarFixer(&this->postDollarFixer);

}
void _printpPrePostHashFixerlc(PrePostHashFixer * const this, long num, char symbol)
{
    printf("%-60s | ", "[PrePostHashFixer::print(long, char)]");
    printf("-->\n");

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", this->postDollarFixer.prePostFixer.pre, symbol,
           this->precision, (float)num, this->postDollarFixer.prePostFixer.post);
}

char _getDefaultSymbolpPrePostHashFixer(const PrePostHashFixer * const this)
{
    return PrePostHashFixer_DEFAULT_SYMBOL;
}

void _printpPrePostHashFixeric(const PrePostHashFixer * const this, int num, char symbol)
{
    printf("%-60s | ", "[PrePostHashFixer::print(int, char)]");
    printf("-->\n");

    printf("%-60s | ", "[PrePostHashFixer::print(double, char)]");

    printf("%s[%c%.*f]%s\n", this->postDollarFixer.prePostFixer.pre, symbol, this->precision, (float)num, this->postDollarFixer.prePostFixer.post);
}

void _PrePostFloatDollarFixerpPrePostFloatDollarFixerss(PrePostFloatDollarFixer *const this, const char* prefix, const char* postfix)
{
    PrePostDollarFixerpPrePostDollarFixerss(&this->prePostDollarFixer, prefix, postfix);

    this->prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.textFormatterVirtualTable = PrePostFloatDollarFixerVirtualTable;

    printf("--- PrePostFloatDollarFixer CTOR: \"%s\"...\"%s\"\n",
            this->prePostDollarFixer.prePostFixer.pre,  this->prePostDollarFixer.prePostFixer.post);
}

void _d_PrePostFloatDollarFixerpPrePostFloatDollarFixer(PrePostFloatDollarFixer * this)
{
    printf("--- PrePostFloatDollarFixer DTOR: \"%s\"...\"%s\"\n",
            this->prePostDollarFixer.prePostFixer.pre,  this->prePostDollarFixer.prePostFixer.post);

    this->prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.textFormatterVirtualTable = PrePostDollarFixerVirtualTable;

    _d_PrePostDollarFixerpPrePostDollarFixer(&this->prePostDollarFixer);
}

char _getDefaultSymbolpPrePostFloatDollarFixer(const PrePostFloatDollarFixer *const this)
{
    return PrePostFloatDollarFixer_DEFAULT_SYMBOL;
}

void _printpPrePostFloatDollarFixerf(const PrePostFloatDollarFixer *const this, float num)
{
    printf("%-60s | ", "[PrePostFloatDollarFixer::print(float)]");
    printf("-->\n");

    printpPrePostFloatDollarFixerfc(this, num, PrePostFloatDollarFixer_DEFAULT_SYMBOL);
}

void printpPrePostFloatDollarFixerfc(const PrePostFloatDollarFixer *const this, float num, char symbol)
{

    printf("%-60s | ", "[PrePostFloatDollarFixer::print(float, char)]");

    printf("%s%c%.2f%s\n",
            this->prePostDollarFixer.prePostFixer.pre, symbol, num, this->prePostDollarFixer.prePostFixer.post);

}

void _PrePostCheckerpPrePostChecker(PrePostChecker * const this)
{
    _PrePostFloatDollarFixerpPrePostFloatDollarFixerss(&this->postFloatDollarFixer, "[[[[ ", " ]]]]");

    this->postFloatDollarFixer.prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.textFormatterVirtualTable
                = PrePostCheckerVirtualTable;

    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n", "[[[[ ", " ]]]]");
}
void _d_PrePostCheckerpPrePostChecker(PrePostChecker * this)
{
    printf("--- PrePostChecker CTOR: \"%s\"...\"%s\"\n",
            this->postFloatDollarFixer.prePostDollarFixer.prePostFixer.pre,
            this->postFloatDollarFixer.prePostDollarFixer.prePostFixer.post);

    this->postFloatDollarFixer.prePostDollarFixer.prePostFixer.defaultTextFormatter.textFormatter.textFormatterVirtualTable
            = PrePostFloatDollarFixerVirtualTable;

    _d_PrePostFloatDollarFixerpPrePostFloatDollarFixer(&this->postFloatDollarFixer);
}

void _printThisSymbolUsingFuncpPrePostChecker(const PrePostChecker * const this)
{
    printf("%-60s | ", "[PrePostChecker::printThisSymbolUsingFunc()]");

    printf("Default symbol is %c\n", (*(this->postFloatDollarFixer.prePostDollarFixer
    .prePostFixer.defaultTextFormatter.textFormatter.textFormatterVirtualTable))[3](&this));
}

void _printThisSymbolDirectlypPrePostChecker(const PrePostChecker * const this)
{
    printf("%-60s | ", "[PrePostChecker::printThisSymbolDirectly()]");

    printf("Default symbol is %c\n", (*(this->postFloatDollarFixer.prePostDollarFixer
            .prePostFixer.defaultTextFormatter.textFormatter.textFormatterVirtualTable))[3](&this));
}

void _printDollarSymbolByCastUsingFuncpPrePostChecker(const PrePostChecker * const this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastUsingFunc()]");


    printf("Default symbol is %c\n", (*(this->postFloatDollarFixer.prePostDollarFixer
            .prePostFixer.defaultTextFormatter.textFormatter.textFormatterVirtualTable))[3]((PrePostDollarFixer*)(this)));
}

void _printDollarSymbolByScopeUsingFuncpPrePostChecker(const PrePostChecker * const this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeUsingFunc()]");

    printf("Default symbol is %c\n", _getDefaultSymbolpPrePostDollarFixer(&this->postFloatDollarFixer));

}

void _printDollarSymbolByCastDirectlypPrePostChecker(const PrePostChecker * const this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByCastDirectly()]");

    printf("Default symbol is %c\n", PrePostDollarFixer_DEFAULT_SYMBOL);

}

void _printDollarSymbolByScopeDirectlypPrePostChecker(const PrePostChecker * const this)
{
    printf("%-60s | ", "[PrePostChecker::printDollarSymbolByScopeDirectly()]");

    printf("Default symbol is %c\n", PrePostDollarFixer_DEFAULT_SYMBOL);

}

void _MultiplierpMultiplieri(Multiplier *const this, int t)
{
    _DefaultTextFormatterpDefaultTextFormatter(&this->defaultTextFormatter);

    this->defaultTextFormatter.textFormatter.textFormatterVirtualTable = MultiplierVirtualTable;

    this->times = t;

    printf("--- Multiplier CTOR: times = %d\n", this->times);
}

void _MultiplierpMultiplierpMultiplier(Multiplier *const this, Multiplier *const that)
{
    _DefaultTextFormatterpDefaultTextFormatterpDefaultTextFormatter(this, that);
    this->defaultTextFormatter.textFormatter.textFormatterVirtualTable = defaultTextFormatterVirtualTable;

    this->times = that->times;
}

void _d_MultiplierpMultiplier(Multiplier *const this)
{
    printf("--- Multiplier DTOR: times = %d\n", this->times);

    this->defaultTextFormatter.textFormatter.textFormatterVirtualTable = defaultTextFormatterVirtualTable;

    _d_DefaultTextFormatterpDefaultTextFormatter(&this->defaultTextFormatter);
}

void _printpMultipliers(Multiplier *const this, const char* text)
{
    int i;
    printf("%-60s | ", "[Multiplier::print(const char*)]");

    for (i = 0; i < this->times; ++i)
        printf("%s", text);
    printf("\n");
}