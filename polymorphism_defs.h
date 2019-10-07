#ifndef EX8__CFRONT_POLYMORPHISM_DEFS_H
#define EX8__CFRONT_POLYMORPHISM_DEFS_H

#define PrePostDollarFixer_DEFAULT_SYMBOL '$'
#define postDollarFixer_DEFAULT_SYMBOL '#'

#include <stdio.h>

int next_id;

typedef void* (*ptrFuncVirtualTable[]) (void*, ...);

//typedef ptrFuncVirtualTable virtualTable;


extern ptrFuncVirtualTable textFormatterVirtualTable;

extern ptrFuncVirtualTable defaultTextFormatterVirtualTable;

extern ptrFuncVirtualTable PrePostFixerVirtualTable;

extern ptrFuncVirtualTable PrePostDollarFixerVirtualTable;

extern ptrFuncVirtualTable PrePostHashFixerVirtualTable;

typedef struct
{
    ptrFuncVirtualTable* textFormatterVirtualTable;
}TextFormatter;


typedef struct
{
    TextFormatter textFormatter;
    int id;

    struct Ider
    {
        // inline static int getId() { return next_id++; }
    };
} DefaultTextFormatter;


typedef struct
{
    DefaultTextFormatter defaultTextFormatter;
    const char* pre;
    const char* post;

} PrePostFixer;

typedef struct
{
    PrePostFixer prePostFixer;

} PrePostDollarFixer;

typedef struct
{
    PrePostDollarFixer postDollarFixer;
    int precision;

}  PrePostHashFixer;
/*
typedef struct
{
    PrePostDollarFixer prePostDollarFixer;
                protected:
                static const char DEFAULT_SYMBOL = '@';

                public:
                PrePostFloatDollarFixer(const char* prefix, const char* postfix);
                ~PrePostFloatDollarFixer();
                void print(float num) const;
                void print(float num, char symbol) const;
                char getDefaultSymbol() const;
} PrePostFloatDollarFixer;
*/

/*TextFormatter defs*/
void _d_TextFormatterpTextFormatter(TextFormatter * this);


/*DefaultTextFormatter defs*/
void _DefaultTextFormatterpDefaultTextFormatter(DefaultTextFormatter * const this);

void _DefaultTextFormatterpDefaultTextFormatterpDefaultTextFormatter
                    (DefaultTextFormatter * const this, const DefaultTextFormatter *);

DefaultTextFormatter *const _assignpDefaultTextFormatterpDefaultTextFormatter
                    (DefaultTextFormatter * const this, const DefaultTextFormatter* const);

void _d_DefaultTextFormatterpDefaultTextFormatter(DefaultTextFormatter * this);

void _printpDefaultTextFormatters(const DefaultTextFormatter * const this, const char* text);

/* global defs*/
DefaultTextFormatter* generateFormatterArray();

/* PrePostFixer defs*/
void _PrePostFixerpPrePostFixerss(PrePostFixer * const this, const char* prefix, const char* postfix);
void _d_PrePostFixerpPrePostFixer(PrePostFixer * this);
void _printpPrePostFixers(const PrePostFixer * const this, const char* text);
void _printpPrePostFixerlc(const PrePostFixer * const this, long num, char symbol /*= '\0'*/);
char _getDefaultSymbolpPrePostFixer(const PrePostFixer * const this);
/*
const char* _getPrefixpPrePostFixer(const PrePostFixer * const this);
const char* _getPostfixpPrePostFixer(const PrePostFixer * const this);
void _print_numpPrePostFixerl(const PrePostFixer * const this, long num);
void _print_numpPrePostFixerlc(const PrePostFixer * const this, long num, char symbol);
 */

/*PrePostDollarFixer defs*/
void PrePostDollarFixerpPrePostDollarFixerss(PrePostDollarFixer *const this, const char* prefix, const char* postfix);
void PrePostDollarFixerpPrePostDollarFixerpPrePostDollarFixer(PrePostDollarFixer *const this, const PrePostDollarFixer *const other);
void _d_PrePostDollarFixerpPrePostDollarFixer(PrePostDollarFixer * this);
void _printpPrePostDollarFixerlc(const PrePostDollarFixer *const this, long num, char symbol);
char _getDefaultSymbolpPrePostDollarFixer(const PrePostDollarFixer *const this);
void _printpPrePostDollarFixeric(const PrePostDollarFixer *const this, int num, char symbol);
void _printpPrePostDollarFixerdc(const PrePostDollarFixer *const this, double num, char symbol);


/*PrePostHashFixer defs*/
void _PrePostHashFixerpPrePostHashFixeri(PrePostHashFixer * const this, int prc/* = 4*/);
void _d_PrePostHashFixerpPrePostHashFixer(PrePostHashFixer * this);
void _printpPrePostHashFixerlc(PrePostHashFixer * const this, long num, char symbol);
char _getDefaultSymbolpPrePostHashFixer(const PrePostHashFixer * const this);
void _printpPrePostHashFixeric(const PrePostHashFixer * const this, int num, char symbol);


#endif /*EX8__CFRONT_POLYMORPHISM_DEFS_H*/
