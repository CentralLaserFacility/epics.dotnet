/*************************************************************************\
Copyright (c) 2010-2015 Helmholtz-Zentrum Berlin f. Materialien
                        und Energie GmbH, Germany (HZB)
This file is distributed subject to a Software License Agreement found
in the file LICENSE that is included with this distribution.
\*************************************************************************/
/* Driver template for the LEMON parser generator.
** The author disclaims copyright to this source code.
*/
/* First off, code is included that follows the "include" declaration
** in the input grammar file. */
#include <stdio.h>
#include <assert.h>
#line 10 "../snl.lem"

#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "node.h"
#include "var_types.h"
#include "main.h"
#include "parser.h"

#define NIL (Node *)0
#line 27 "./snl.c"
/* Next is all token values, in a form suitable for use by makeheaders.
** This section will be null unless lemon is run with the -m switch.
*/
/* 
** These constants (all generated automatically by the parser generator)
** specify the various kinds of tokens (terminals) that the parser
** understands. 
**
** Each symbol here is a terminal symbol in the grammar.
*/
/* Make sure the INTERFACE macro is defined.
*/
#ifndef INTERFACE
# define INTERFACE 1
#endif
/* The next thing included is series of defines which control
** various aspects of the generated parser.
**    YYCODETYPE         is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 terminals
**                       and nonterminals.  "int" is used otherwise.
**    YYNOCODE           is a number of type YYCODETYPE which corresponds
**                       to no legal terminal or nonterminal number.  This
**                       number is used to fill in empty slots of the hash 
**                       table.
**    YYFALLBACK         If defined, this indicates that one or more tokens
**                       have fall-back values which should be used if the
**                       original value of the token will not parse.
**    YYACTIONTYPE       is the data type used for storing terminal
**                       and nonterminal numbers.  "unsigned char" is
**                       used if there are fewer than 250 rules and
**                       states combined.  "int" is used otherwise.
**    snlParserTOKENTYPE     is the data type used for minor tokens given 
**                       directly to the parser from the tokenizer.
**    YYMINORTYPE        is the data type used for all minor tokens.
**                       This is typically a union of many types, one of
**                       which is snlParserTOKENTYPE.  The entry in the union
**                       for base tokens is called "yy0".
**    YYSTACKDEPTH       is the maximum depth of the parser's stack.  If
**                       zero the stack is dynamically sized using realloc()
**    snlParserARG_SDECL     A static variable declaration for the %extra_argument
**    snlParserARG_PDECL     A parameter declaration for the %extra_argument
**    snlParserARG_STORE     Code to store %extra_argument into yypParser
**    snlParserARG_FETCH     Code to extract %extra_argument from yypParser
**    YYNSTATE           the combined number of states.
**    YYNRULE            the number of rules in the grammar
**    YYERRORSYMBOL      is the code number of the error symbol.  If not
**                       defined, then do no error processing.
*/
#define YYCODETYPE unsigned char
#define YYNOCODE 160
#define YYACTIONTYPE unsigned short int
#define snlParserTOKENTYPE  Token 
typedef union {
  int yyinit;
  snlParserTOKENTYPE yy0;
  enum prim_type_tag yy6;
  Type* yy149;
  Node* yy255;
  Token yy270;
  int yy319;
} YYMINORTYPE;
#ifndef YYSTACKDEPTH
#define YYSTACKDEPTH 0
#endif
#define snlParserARG_SDECL  Node **presult ;
#define snlParserARG_PDECL , Node **presult 
#define snlParserARG_FETCH  Node **presult  = yypParser->presult 
#define snlParserARG_STORE yypParser->presult  = presult 
#define YYNSTATE 402
#define YYNRULE 224
#define YYERRORSYMBOL 95
#define YYERRSYMDT yy319
#define YY_NO_ACTION      (YYNSTATE+YYNRULE+2)
#define YY_ACCEPT_ACTION  (YYNSTATE+YYNRULE+1)
#define YY_ERROR_ACTION   (YYNSTATE+YYNRULE)

/* The yyzerominor constant is used to initialize instances of
** YYMINORTYPE objects to zero. */
static const YYMINORTYPE yyzerominor = { 0 };

/* Define the yytestcase() macro to be a no-op if is not already defined
** otherwise.
**
** Applications can choose to define yytestcase() in the %include section
** to a macro that can assist in verifying code coverage.  For production
** code the yytestcase() macro should be turned off.  But it is useful
** for testing.
*/
#ifndef yytestcase
# define yytestcase(X)
#endif


/* Next are the tables used to determine what action to take based on the
** current state and lookahead token.  These tables are used to implement
** functions that take a state number and lookahead value and return an
** action integer.  
**
** Suppose the action integer is N.  Then the action is determined as
** follows
**
**   0 <= N < YYNSTATE                  Shift N.  That is, push the lookahead
**                                      token onto the stack and goto state N.
**
**   YYNSTATE <= N < YYNSTATE+YYNRULE   Reduce by rule N-YYNSTATE.
**
**   N == YYNSTATE+YYNRULE              A syntax error has occurred.
**
**   N == YYNSTATE+YYNRULE+1            The parser accepts its input.
**
**   N == YYNSTATE+YYNRULE+2            No such action.  Denotes unused
**                                      slots in the yy_action[] table.
**
** The action table is constructed as a single large table named yy_action[].
** Given state S and lookahead X, the action is computed as
**
**      yy_action[ yy_shift_ofst[S] + X ]
**
** If the index value yy_shift_ofst[S]+X is out of range or if the value
** yy_lookahead[yy_shift_ofst[S]+X] is not equal to X or if yy_shift_ofst[S]
** is equal to YY_SHIFT_USE_DFLT, it means that the action is not in the table
** and that yy_default[S] should be used instead.  
**
** The formula above is for computing the action when the lookahead is
** a terminal symbol.  If the lookahead is a non-terminal (as occurs after
** a reduce action) then the yy_reduce_ofst[] array is used in place of
** the yy_shift_ofst[] array and YY_REDUCE_USE_DFLT is used in place of
** YY_SHIFT_USE_DFLT.
**
** The following are the tables generated in this section:
**
**  yy_action[]        A single table containing all actions.
**  yy_lookahead[]     A table containing the lookahead for each entry in
**                     yy_action.  Used to detect hash collisions.
**  yy_shift_ofst[]    For each state, the offset into yy_action for
**                     shifting terminals.
**  yy_reduce_ofst[]   For each state, the offset into yy_action for
**                     shifting non-terminals after a reduce.
**  yy_default[]       Default action for each state.
*/
#define YY_ACTTAB_COUNT (1387)
static const YYACTIONTYPE yy_action[] = {
 /*     0 */    61,   60,   59,   58,   57,   56,   55,   54,   53,   52,
 /*    10 */    51,   63,  213,   71,   70,   67,   66,   65,   75,   74,
 /*    20 */    77,   76,   73,   72,   69,   68,   80,   81,   79,   78,
 /*    30 */    64,  246,   19,  338,  337,  246,   19,   82,   33,  139,
 /*    40 */   140,   79,   78,   64,  356,  352,  338,  337,  366,   85,
 /*    50 */    82,   33,  139,  140,   27,  342,  286,   61,   60,   59,
 /*    60 */    58,   57,   56,   55,   54,   53,   52,   51,   63,   62,
 /*    70 */    71,   70,   67,   66,   65,   75,   74,   77,   76,   73,
 /*    80 */    72,   69,   68,   80,   81,   79,   78,   64,  330,  142,
 /*    90 */   338,  337,  138,  377,   82,   33,  139,  140,   61,   60,
 /*   100 */    59,   58,   57,   56,   55,   54,   53,   52,   51,   63,
 /*   110 */   104,   71,   70,   67,   66,   65,   75,   74,   77,   76,
 /*   120 */    73,   72,   69,   68,   80,   81,   79,   78,   64,  376,
 /*   130 */    45,  338,  337,   88,  293,   82,   33,  139,  140,   48,
 /*   140 */    47,   46,  246,   13,   44,   43,   42,   41,   49,  141,
 /*   150 */   369,   11,  359,  246,   18,  335,  370,   36,  246,   19,
 /*   160 */   109,   87,  206,  362,  360,  364,  217,  347,  380,  108,
 /*   170 */   375,  397,  396,  395,  394,  195,  389,  388,  387,  386,
 /*   180 */   385,  384,  383,  382,  381,  379,  378,  252,  249,  248,
 /*   190 */   247,  374,  338,  337,  137,  243,   82,   33,  139,  140,
 /*   200 */   133,  131,  127,  373,  346,  335,  105,  397,  396,  395,
 /*   210 */   394,  195,  389,  388,  387,  386,  385,  384,  383,  382,
 /*   220 */   381,  379,  378,  252,  251,  248,  247,  112,  245,   36,
 /*   230 */   122,  137,   29,  146,  208,  362,  360,  133,  131,  127,
 /*   240 */   380,   39,  354,  105,  397,  396,  395,  394,  195,  389,
 /*   250 */   388,  387,  386,  385,  384,  383,  382,  381,  379,  378,
 /*   260 */   252,  249,  248,  247,  112,  137,  369,  122,  310,  246,
 /*   270 */    19,  133,  131,  127,  205,  331,  107,  105,  397,  396,
 /*   280 */   395,  394,  195,  389,  388,  387,  386,  385,  384,  383,
 /*   290 */   382,  381,  379,  378,  252,  249,  248,  247,   32,   63,
 /*   300 */   217,   71,   70,   67,   66,   65,   75,   74,   77,   76,
 /*   310 */    73,   72,   69,   68,   80,   81,   79,   78,   64,  368,
 /*   320 */    35,  338,  337,  124,  212,   82,   33,  139,  140,  246,
 /*   330 */     5,   36,  246,   18,  361,  370,  207,  362,  360,  357,
 /*   340 */    27,  358,  380,  393,  392,  391,  390,   27,   34,   84,
 /*   350 */   397,  396,  395,  394,  195,  389,  388,  387,  386,  385,
 /*   360 */   384,  383,  382,  381,  379,  378,  252,  249,  248,  247,
 /*   370 */    45,   36,  349,  359,   28,  290,  289,  365,  360,   48,
 /*   380 */    47,   46,  380,   88,   44,   43,   42,   41,   49,  369,
 /*   390 */   115,   11,  246,   13,  246,   19,  370,  205,  331,   86,
 /*   400 */   145,  327,  439,  343,  145,  304,  348,  347,   28,   83,
 /*   410 */   295,   87,   99,  397,  396,  395,  394,  195,  389,  388,
 /*   420 */   387,  386,  385,  384,  383,  382,  381,  379,  378,  252,
 /*   430 */   249,  248,  247,  236,  223,  243,  136,  240,  239,   25,
 /*   440 */   234,   45,  232,  230,  346,  335,  354,  336,  265,   40,
 /*   450 */    48,   47,   46,   50,   35,   44,   43,   42,   41,   49,
 /*   460 */   114,  135,   11,  246,    5,  246,  369,  370,  210,  370,
 /*   470 */   284,  145,  235,  372,  303,  351,  107,  304,  347,  300,
 /*   480 */   367,  132,   34,  397,  396,  395,  394,  195,  389,  388,
 /*   490 */   387,  386,  385,  384,  383,  382,  381,  379,  378,  252,
 /*   500 */   249,  248,  247,  300,  236,  130,  243,  311,  240,  239,
 /*   510 */    25,  234,  325,  232,  230,  346,  335,  354,  354,  402,
 /*   520 */    70,   67,   66,   65,   75,   74,   77,   76,   73,   72,
 /*   530 */    69,   68,   80,   81,   79,   78,   64,  126,   98,  338,
 /*   540 */   337,  281,  218,   82,   33,  139,  140,   67,   66,   65,
 /*   550 */    75,   74,   77,   76,   73,   72,   69,   68,   80,   81,
 /*   560 */    79,   78,   64,  324,  323,  338,  337,  334,    9,   82,
 /*   570 */    33,  139,  140,   50,   83,  300,   83,   95,  397,  396,
 /*   580 */   395,  394,  195,  389,  388,  387,  386,  385,  384,  383,
 /*   590 */   382,  381,  379,  378,  252,  251,  248,  247,   80,   81,
 /*   600 */    79,   78,   64,   31,  226,  338,  337,  124,  322,   82,
 /*   610 */    33,  139,  140,  354,  105,  397,  396,  395,  394,  195,
 /*   620 */   389,  388,  387,  386,  385,  384,  383,  382,  381,  379,
 /*   630 */   378,  252,  249,  248,  247,   66,   65,   75,   74,   77,
 /*   640 */    76,   73,   72,   69,   68,   80,   81,   79,   78,   64,
 /*   650 */   354,  328,  338,  337,  306,    7,   82,   33,  139,  140,
 /*   660 */   369,   83,  369,    8,   30,   24,  199,  316,   23,  196,
 /*   670 */   110,   22,  109,  397,  396,  395,  394,  195,  389,  388,
 /*   680 */   387,  386,  385,  384,  383,  382,  381,  379,  378,  252,
 /*   690 */   249,  248,  247,   65,   75,   74,   77,   76,   73,   72,
 /*   700 */    69,   68,   80,   81,   79,   78,   64,    6,  354,  338,
 /*   710 */   337,  225,  144,   82,   33,  139,  140,  397,  396,  395,
 /*   720 */   394,  195,  389,  388,  387,  386,  385,  384,  383,  382,
 /*   730 */   381,  379,  378,  252,  249,  248,  247,   75,   74,   77,
 /*   740 */    76,   73,   72,   69,   68,   80,   81,   79,   78,   64,
 /*   750 */   309,  308,  338,  337,  359,  305,   82,   33,  139,  140,
 /*   760 */    77,   76,   73,   72,   69,   68,   80,   81,   79,   78,
 /*   770 */    64,  116,   45,  338,  337,  369,  216,   82,   33,  139,
 /*   780 */   140,   48,   47,   46,  301,  119,   44,   43,   42,   41,
 /*   790 */    49,  369,  345,   11,  298,  296,   45,  294,  370,  359,
 /*   800 */   143,  118,   21,  214,  344,   48,   47,   46,  291,  347,
 /*   810 */    44,   43,   42,   41,   49,  333,  117,   12,  359,  345,
 /*   820 */   204,  165,  370,   36,  288,   16,   20,  123,  206,  362,
 /*   830 */   360,  344,  285,  347,  380,  108,  254,  243,   89,    1,
 /*   840 */    15,   45,  355,   14,  369,  244,  346,  335,  150,  380,
 /*   850 */    48,   47,   46,   94,   97,   44,   43,   42,   41,   49,
 /*   860 */    29,  243,   11,    3,  380,   45,    2,  370,  202,  147,
 /*   870 */   346,  335,  345,  121,   48,   47,   46,   92,  347,   44,
 /*   880 */    43,   42,   41,   49,  344,   17,   10,   93,   26,  353,
 /*   890 */   250,  370,  370,  307,  329,  333,  340,  246,   19,  341,
 /*   900 */   203,  165,  347,  335,  339,   91,  243,  145,   69,   68,
 /*   910 */    80,   81,   79,   78,   64,  346,  335,  338,  337,  370,
 /*   920 */    96,   82,   33,  139,  140,  134,  304,  222,  103,  302,
 /*   930 */   243,  221,  102,  297,  129,  128,  220,  106,  299,  346,
 /*   940 */   335,  101,  264,  263,  262,  261,  260,  259,  258,  257,
 /*   950 */   256,  255,  345,  345,   44,   43,   42,   41,   49,  125,
 /*   960 */    37,   11,  295,  219,  344,  344,  370,  400,  399,  398,
 /*   970 */   401,  380,   89,  287,  145,  111,  273,  347,   90,  241,
 /*   980 */   345,  152,  150,  380,  271,  270,  269,  268,  267,  380,
 /*   990 */   209,  367,  344,  224,  292,  363,  215,  283,  246,   89,
 /*  1000 */   226,   38,  202,  200,  627,  243,  242,  212,  253,  150,
 /*  1010 */   380,  369,  380,  359,  346,  335,  100,  113,  272,  266,
 /*  1020 */   628,  120,  279,  278,  277,  276,  275,  274,  345,  202,
 /*  1030 */   115,  628,  628,  369,  628,  359,  321,  628,  628,   38,
 /*  1040 */   344,  345,  628,  119,  345,  628,  628,  628,  628,  321,
 /*  1050 */   380,  345,  116,  344,  628,  345,  344,  150,  628,  321,
 /*  1060 */   280,  628,  628,  344,  628,  628,  628,  344,  628,  320,
 /*  1070 */   150,  628,  231,  150,  628,  345,  233,  237,  317,  628,
 /*  1080 */   150,  628,  320,  321,  152,  231,  345,  344,  238,  319,
 /*  1090 */   237,  317,  320,  237,  628,  231,  355,  628,  344,  318,
 /*  1100 */   237,  317,  628,  628,  150,  345,  201,   94,  628,  345,
 /*  1110 */   628,  628,  628,  321,  628,  150,  320,  344,  380,  231,
 /*  1120 */   313,  344,  312,  315,  237,  317,  628,  345,  345,  211,
 /*  1130 */   282,  628,  628,   38,  150,  237,  628,  628,  150,  344,
 /*  1140 */   344,  628,  628,  371,  380,  628,  320,  628,  628,  231,
 /*  1150 */   628,  628,  628,  326,  237,  317,  150,  150,  198,  628,
 /*  1160 */     4,  314,  628,  345,  628,  628,  628,  345,  369,  628,
 /*  1170 */   359,  229,  228,  345,  345,  344,  237,  237,  118,  344,
 /*  1180 */   628,  345,  345,  628,  628,  344,  344,  117,  345,  345,
 /*  1190 */   628,  628,  150,  344,  344,  628,  150,  350,  628,  628,
 /*  1200 */   344,  344,  191,  165,  332,  628,  628,  227,  345,  345,
 /*  1210 */   165,  164,  237,  345,  628,  628,  197,  149,  181,  345,
 /*  1220 */   344,  344,  345,  345,  345,  344,  628,  345,  345,  345,
 /*  1230 */   628,  344,  345,  345,  344,  344,  344,  180,  194,  344,
 /*  1240 */   344,  344,  193,  345,  344,  344,  628,  345,  177,  628,
 /*  1250 */   628,  176,  173,  172,  628,  344,  175,  174,  167,  344,
 /*  1260 */   628,  168,  179,  628,  628,  345,  628,  345,  628,  628,
 /*  1270 */   628,  345,  178,  628,  345,  345,  169,  344,  345,  344,
 /*  1280 */   345,  345,  628,  344,  628,  345,  344,  344,  628,  345,
 /*  1290 */   344,  628,  344,  344,  170,  628,  171,  344,  628,  628,
 /*  1300 */   192,  344,  628,  148,  166,  345,  628,  163,  345,  162,
 /*  1310 */   161,  345,  345,  345,  160,  345,  345,  344,  159,  628,
 /*  1320 */   344,  345,  628,  344,  344,  344,  345,  344,  344,  628,
 /*  1330 */   628,  345,  628,  344,  158,  345,  345,  157,  344,  345,
 /*  1340 */   156,  155,  154,  344,  153,  151,  345,  344,  344,  345,
 /*  1350 */   182,  344,  628,  628,  628,  190,  628,  345,  344,  628,
 /*  1360 */   189,  344,  628,  628,  188,  187,  628,  628,  186,  344,
 /*  1370 */   628,  628,  628,  628,  628,  185,  628,  628,  184,  628,
 /*  1380 */   628,  628,  628,  628,  628,  628,  183,
};
static const YYCODETYPE yy_lookahead[] = {
 /*     0 */     1,    2,    3,    4,    5,    6,    7,    8,    9,   10,
 /*    10 */    11,   12,  101,   14,   15,   16,   17,   18,   19,   20,
 /*    20 */    21,   22,   23,   24,   25,   26,   27,   28,   29,   30,
 /*    30 */    31,   38,   39,   34,   35,   38,   39,   38,   39,   40,
 /*    40 */    41,   29,   30,   31,   47,   47,   34,   35,   45,   51,
 /*    50 */    38,   39,   40,   41,   51,   56,  145,    1,    2,    3,
 /*    60 */     4,    5,    6,    7,    8,    9,   10,   11,   12,   13,
 /*    70 */    14,   15,   16,   17,   18,   19,   20,   21,   22,   23,
 /*    80 */    24,   25,   26,   27,   28,   29,   30,   31,   47,   44,
 /*    90 */    34,   35,   51,   44,   38,   39,   40,   41,    1,    2,
 /*   100 */     3,    4,    5,    6,    7,    8,    9,   10,   11,   12,
 /*   110 */    48,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   120 */    23,   24,   25,   26,   27,   28,   29,   30,   31,   47,
 /*   130 */    18,   34,   35,   29,   49,   38,   39,   40,   41,   27,
 /*   140 */    28,   29,   38,   39,   32,   33,   34,   35,   36,   44,
 /*   150 */   115,   39,  117,   38,   39,   93,   44,  122,   38,   39,
 /*   160 */   125,   57,  127,  128,  129,   45,   81,   55,  133,  134,
 /*   170 */    44,   59,   60,   61,   62,   63,   64,   65,   66,   67,
 /*   180 */    68,   69,   70,   71,   72,   73,   74,   75,   76,   77,
 /*   190 */    78,   44,   34,   35,   46,   83,   38,   39,   40,   41,
 /*   200 */    52,   53,   54,   44,   92,   93,   58,   59,   60,   61,
 /*   210 */    62,   63,   64,   65,   66,   67,   68,   69,   70,   71,
 /*   220 */    72,   73,   74,   75,   76,   77,   78,   79,   55,  122,
 /*   230 */    82,   46,    1,  101,  127,  128,  129,   52,   53,   54,
 /*   240 */   133,   45,   94,   58,   59,   60,   61,   62,   63,   64,
 /*   250 */    65,   66,   67,   68,   69,   70,   71,   72,   73,   74,
 /*   260 */    75,   76,   77,   78,   79,   46,  115,   82,  136,   38,
 /*   270 */    39,   52,   53,   54,  123,  124,  125,   58,   59,   60,
 /*   280 */    61,   62,   63,   64,   65,   66,   67,   68,   69,   70,
 /*   290 */    71,   72,   73,   74,   75,   76,   77,   78,   39,   12,
 /*   300 */    81,   14,   15,   16,   17,   18,   19,   20,   21,   22,
 /*   310 */    23,   24,   25,   26,   27,   28,   29,   30,   31,   56,
 /*   320 */    29,   34,   35,   83,   84,   38,   39,   40,   41,   38,
 /*   330 */    39,  122,   38,   39,   45,   44,  127,  128,  129,   45,
 /*   340 */    51,   45,  133,   59,   60,   61,   62,   51,   57,   45,
 /*   350 */    59,   60,   61,   62,   63,   64,   65,   66,   67,   68,
 /*   360 */    69,   70,   71,   72,   73,   74,   75,   76,   77,   78,
 /*   370 */    18,  122,   49,  117,   51,   27,   28,  128,  129,   27,
 /*   380 */    28,   29,  133,   29,   32,   33,   34,   35,   36,  115,
 /*   390 */   134,   39,   38,   39,   38,   39,   44,  123,  124,  125,
 /*   400 */    48,   49,   47,   45,   48,   50,   49,   55,   51,   51,
 /*   410 */    55,   57,  100,   59,   60,   61,   62,   63,   64,   65,
 /*   420 */    66,   67,   68,   69,   70,   71,   72,   73,   74,   75,
 /*   430 */    76,   77,   78,   81,   49,   83,   51,   85,   86,   87,
 /*   440 */    88,   18,   90,   91,   92,   93,   94,   45,  136,   45,
 /*   450 */    27,   28,   29,   51,   29,   32,   33,   34,   35,   36,
 /*   460 */   116,  117,   39,   38,   39,   38,  115,   44,   81,   44,
 /*   470 */    83,   48,   44,   49,   47,  124,  125,   50,   55,  117,
 /*   480 */   117,  119,   57,   59,   60,   61,   62,   63,   64,   65,
 /*   490 */    66,   67,   68,   69,   70,   71,   72,   73,   74,   75,
 /*   500 */    76,   77,   78,  117,   81,  119,   83,  144,   85,   86,
 /*   510 */    87,   88,   47,   90,   91,   92,   93,   94,   94,    0,
 /*   520 */    15,   16,   17,   18,   19,   20,   21,   22,   23,   24,
 /*   530 */    25,   26,   27,   28,   29,   30,   31,  116,  142,   34,
 /*   540 */    35,  145,  121,   38,   39,   40,   41,   16,   17,   18,
 /*   550 */    19,   20,   21,   22,   23,   24,   25,   26,   27,   28,
 /*   560 */    29,   30,   31,   47,   47,   34,   35,   45,   45,   38,
 /*   570 */    39,   40,   41,   51,   51,  117,   51,  119,   59,   60,
 /*   580 */    61,   62,   63,   64,   65,   66,   67,   68,   69,   70,
 /*   590 */    71,   72,   73,   74,   75,   76,   77,   78,   27,   28,
 /*   600 */    29,   30,   31,   39,   80,   34,   35,   83,   47,   38,
 /*   610 */    39,   40,   41,   94,   58,   59,   60,   61,   62,   63,
 /*   620 */    64,   65,   66,   67,   68,   69,   70,   71,   72,   73,
 /*   630 */    74,   75,   76,   77,   78,   17,   18,   19,   20,   21,
 /*   640 */    22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
 /*   650 */    94,  115,   34,   35,  103,   45,   38,   39,   40,   41,
 /*   660 */   115,   51,  115,   89,   39,   39,  130,   47,   47,  118,
 /*   670 */   125,   47,  125,   59,   60,   61,   62,   63,   64,   65,
 /*   680 */    66,   67,   68,   69,   70,   71,   72,   73,   74,   75,
 /*   690 */    76,   77,   78,   18,   19,   20,   21,   22,   23,   24,
 /*   700 */    25,   26,   27,   28,   29,   30,   31,   45,   94,   34,
 /*   710 */    35,   44,   48,   38,   39,   40,   41,   59,   60,   61,
 /*   720 */    62,   63,   64,   65,   66,   67,   68,   69,   70,   71,
 /*   730 */    72,   73,   74,   75,   76,   77,   78,   19,   20,   21,
 /*   740 */    22,   23,   24,   25,   26,   27,   28,   29,   30,   31,
 /*   750 */    47,   47,   34,   35,  117,   47,   38,   39,   40,   41,
 /*   760 */    21,   22,   23,   24,   25,   26,   27,   28,   29,   30,
 /*   770 */    31,  134,   18,   34,   35,  115,   44,   38,   39,   40,
 /*   780 */    41,   27,   28,   29,   47,  125,   32,   33,   34,   35,
 /*   790 */    36,  115,  103,   39,   47,   47,   18,   47,   44,  117,
 /*   800 */    48,  125,   48,   44,  115,   27,   28,   29,   47,   55,
 /*   810 */    32,   33,   34,   35,   36,  126,  134,   39,  117,  103,
 /*   820 */   131,  132,   44,  122,   49,   39,   48,   45,  127,  128,
 /*   830 */   129,  115,   44,   55,  133,  134,   45,   83,  122,   98,
 /*   840 */   102,   18,  111,  148,  115,  129,   92,   93,  132,  133,
 /*   850 */    27,   28,   29,  122,  125,   32,   33,   34,   35,   36,
 /*   860 */     1,   83,   39,  137,  133,   18,  141,   44,  152,   97,
 /*   870 */    92,   93,  103,   39,   27,   28,   29,   29,   55,   32,
 /*   880 */    33,   34,   35,   36,  115,   48,   39,   39,  157,  158,
 /*   890 */   156,   44,   44,  103,  115,  126,   44,   38,   39,  155,
 /*   900 */   131,  132,   55,   93,  155,   57,   83,   48,   25,   26,
 /*   910 */    27,   28,   29,   30,   31,   92,   93,   34,   35,   44,
 /*   920 */   115,   38,   39,   40,   41,  116,   50,  103,  115,   47,
 /*   930 */    83,   95,  115,   44,  116,  120,   95,   99,   47,   92,
 /*   940 */    93,  115,  104,  105,  106,  107,  108,  109,  110,  111,
 /*   950 */   112,  113,  103,  103,   32,   33,   34,   35,   36,  120,
 /*   960 */   122,   39,   55,  121,  115,  115,   44,  111,  112,  113,
 /*   970 */   114,  133,  122,  144,   48,  144,  144,   55,  122,  129,
 /*   980 */   103,  132,  132,  133,  105,  106,  107,  108,  109,  133,
 /*   990 */   103,  117,  115,  103,  140,  117,  135,   95,   38,  122,
 /*  1000 */    80,  122,  152,  154,   96,   83,  129,   84,   43,  132,
 /*  1010 */   133,  115,  133,  117,   92,   93,   99,  138,  139,  140,
 /*  1020 */   159,  125,  105,  106,  107,  108,  109,  110,  103,  152,
 /*  1030 */   134,  159,  159,  115,  159,  117,  111,  159,  159,  122,
 /*  1040 */   115,  103,  159,  125,  103,  159,  159,  159,  159,  111,
 /*  1050 */   133,  103,  134,  115,  159,  103,  115,  132,  159,  111,
 /*  1060 */   143,  159,  159,  115,  159,  159,  159,  115,  159,  144,
 /*  1070 */   132,  159,  147,  132,  159,  103,  151,  152,  153,  159,
 /*  1080 */   132,  159,  144,  111,  132,  147,  103,  115,  147,  151,
 /*  1090 */   152,  153,  144,  152,  159,  147,  111,  159,  115,  151,
 /*  1100 */   152,  153,  159,  159,  132,  103,  154,  122,  159,  103,
 /*  1110 */   159,  159,  159,  111,  159,  132,  144,  115,  133,  147,
 /*  1120 */   109,  115,  111,  151,  152,  153,  159,  103,  103,  146,
 /*  1130 */   147,  159,  159,  122,  132,  152,  159,  159,  132,  115,
 /*  1140 */   115,  159,  159,  158,  133,  159,  144,  159,  159,  147,
 /*  1150 */   159,  159,  159,  151,  152,  153,  132,  132,  152,  159,
 /*  1160 */   149,  150,  159,  103,  159,  159,  159,  103,  115,  159,
 /*  1170 */   117,  147,  147,  103,  103,  115,  152,  152,  125,  115,
 /*  1180 */   159,  103,  103,  159,  159,  115,  115,  134,  103,  103,
 /*  1190 */   159,  159,  132,  115,  115,  159,  132,  126,  159,  159,
 /*  1200 */   115,  115,  132,  132,  126,  159,  159,  147,  103,  103,
 /*  1210 */   132,  132,  152,  103,  159,  159,  152,  132,  132,  103,
 /*  1220 */   115,  115,  103,  103,  103,  115,  159,  103,  103,  103,
 /*  1230 */   159,  115,  103,  103,  115,  115,  115,  132,  132,  115,
 /*  1240 */   115,  115,  132,  103,  115,  115,  159,  103,  132,  159,
 /*  1250 */   159,  132,  132,  132,  159,  115,  132,  132,  132,  115,
 /*  1260 */   159,  132,  132,  159,  159,  103,  159,  103,  159,  159,
 /*  1270 */   159,  103,  132,  159,  103,  103,  132,  115,  103,  115,
 /*  1280 */   103,  103,  159,  115,  159,  103,  115,  115,  159,  103,
 /*  1290 */   115,  159,  115,  115,  132,  159,  132,  115,  159,  159,
 /*  1300 */   132,  115,  159,  132,  132,  103,  159,  132,  103,  132,
 /*  1310 */   132,  103,  103,  103,  132,  103,  103,  115,  132,  159,
 /*  1320 */   115,  103,  159,  115,  115,  115,  103,  115,  115,  159,
 /*  1330 */   159,  103,  159,  115,  132,  103,  103,  132,  115,  103,
 /*  1340 */   132,  132,  132,  115,  132,  132,  103,  115,  115,  103,
 /*  1350 */   132,  115,  159,  159,  159,  132,  159,  103,  115,  159,
 /*  1360 */   132,  115,  159,  159,  132,  132,  159,  159,  132,  115,
 /*  1370 */   159,  159,  159,  159,  159,  132,  159,  159,  132,  159,
 /*  1380 */   159,  159,  159,  159,  159,  159,  132,
};
#define YY_SHIFT_USE_DFLT (-8)
#define YY_SHIFT_COUNT (253)
#define YY_SHIFT_MIN   (-7)
#define YY_SHIFT_MAX   (965)
static const short yy_shift_ofst[] = {
 /*     0 */   965,  148,  185,  219,  352,  291,  423,  423,  423,  423,
 /*    10 */   112,  112,  112,  354,  556,  519,  823,  614,  658,  658,
 /*    20 */   778,  778,  823,  823,  823,  823,  424,  658,  778,  778,
 /*    30 */   823,  823,  823,  823,  425,  425,  425,  848,  848,  754,
 /*    40 */   823,  823,  823,  823,  823,  823,  823,  823,  823,  847,
 /*    50 */   823,  823,  823,  823,  823,  823,  823,  823,  823,  823,
 /*    60 */   823,  823,  823,  823,  823,  823,  823,  823,  823,  823,
 /*    70 */   823,  823,  823,  823,  823,  823,  823,  823,  823,  823,
 /*    80 */   823,  823,  823,  823,  922,  848,  859,  104,  104,  104,
 /*    90 */   848,  848,  848,  848,  848,  355,  427,  356,  240,  524,
 /*   100 */   923,  960,  960,  960,  810,  875,  920,  231,  294,  120,
 /*   110 */    -3,  387,  348,   85,   62,  115,  115,  115,   -7,   -7,
 /*   120 */    -7,  810,  926,  926,  926,  907,  889,  875,  891,  889,
 /*   130 */   876,  875,  882,  875,  810,  876,  810,  875,  875,  852,
 /*   140 */   852,  837,  834,   -8,   -8,   -8,   -8,   -8,   56,   -1,
 /*   150 */    97,   97,   97,   97,   97,   97,   97,   97,   97,   97,
 /*   160 */    97,   97,   97,   97,   97,   97,  287,  505,  531,  618,
 /*   170 */   675,  718,  739,  739,  883,  883,  883,  883,  571,  571,
 /*   180 */    12,   12,  158,  158,  158,  158,  158,  158,  158,  158,
 /*   190 */   158,  158,  158,  158,  158,  284,  385,  610,  523,   41,
 /*   200 */   522,  402,  358,  357,  323,   -2,  296,  289,    3,  791,
 /*   210 */   788,  782,  786,  775,  761,  759,  752,  732,  750,  748,
 /*   220 */   747,  737,  708,  704,  703,  664,  667,  662,  624,  621,
 /*   230 */   626,  620,  625,  574,  564,  561,  428,  525,  517,  516,
 /*   240 */   465,  404,  304,  259,  196,  263,  173,  159,  147,  126,
 /*   250 */    82,  105,   49,   45,
};
#define YY_REDUCE_USE_DFLT (-90)
#define YY_REDUCE_COUNT (147)
#define YY_REDUCE_MIN   (-89)
#define YY_REDUCE_MAX   (1254)
static const short yy_reduce_ofst[] = {
 /*     0 */   908,  838,  917,  879, 1002,   35,  972,  948,  938,  925,
 /*    10 */   877,  850,  716,  701, 1011,  856,  983,  731,  209,  107,
 /*    20 */   769,  689, 1060, 1025, 1024,  941,  985,  249, 1078, 1071,
 /*    30 */  1064, 1006,  952,  849, 1053,  918,  896,  274,  151, 1070,
 /*    40 */  1070, 1254, 1246, 1243, 1236, 1233, 1232, 1228, 1223, 1218,
 /*    50 */  1213, 1212, 1210, 1209, 1208, 1205, 1202, 1186, 1182, 1178,
 /*    60 */  1177, 1175, 1172, 1171, 1168, 1164, 1162, 1144, 1140, 1130,
 /*    70 */  1129, 1126, 1125, 1124, 1121, 1120, 1119, 1116, 1110, 1106,
 /*    80 */  1105, 1086, 1085, 1079, 1070,  351,  363,  682,  637,  256,
 /*    90 */   729,  676,  660,  547,  545,  421,  344,  363,  -89,  132,
 /*   100 */   396,  458,  386,  362,  551,  536,  312,  874,  878,  874,
 /*   110 */   874,  902,  861,  854,  890,  878,  878,  878,  874,  874,
 /*   120 */   874,  887,  832,  831,  829,  842,  839,  826,  841,  815,
 /*   130 */   818,  817,  836,  813,  824,  809,  790,  805,  779,  749,
 /*   140 */   744,  734,  772,  725,  726,  695,  738,  741,
};
static const YYACTIONTYPE yy_default[] = {
 /*     0 */   626,  528,  528,  626,  612,  454,  612,  612,  612,  612,
 /*    10 */   626,  626,  626,  454,  543,  626,  612,  626,  454,  454,
 /*    20 */   467,  467,  612,  612,  612,  612,  626,  626,  626,  626,
 /*    30 */   626,  626,  615,  615,  497,  495,  492,  626,  626,  626,
 /*    40 */   626,  626,  626,  626,  626,  626,  626,  626,  626,  626,
 /*    50 */   626,  626,  626,  626,  626,  626,  626,  626,  626,  626,
 /*    60 */   626,  626,  626,  626,  626,  626,  626,  626,  626,  626,
 /*    70 */   626,  626,  626,  626,  626,  626,  626,  626,  626,  626,
 /*    80 */   626,  626,  626,  626,  563,  626,  446,  497,  495,  492,
 /*    90 */   626,  626,  626,  626,  626,  426,  426,  626,  530,  530,
 /*   100 */   626,  441,  441,  441,  429,  626,  626,  446,  626,  626,
 /*   110 */   626,  626,  626,  626,  626,  493,  496,  498,  453,  452,
 /*   120 */   457,  626,  626,  626,  626,  439,  626,  626,  626,  626,
 /*   130 */   426,  626,  626,  626,  626,  426,  626,  626,  626,  626,
 /*   140 */   626,  489,  404,  520,  510,  539,  417,  406,  626,  626,
 /*   150 */   610,  613,  614,  608,  607,  606,  605,  604,  603,  602,
 /*   160 */   601,  600,  599,  598,  609,  464,  597,  589,  590,  593,
 /*   170 */   594,  595,  586,  585,  588,  587,  584,  583,  592,  591,
 /*   180 */   580,  579,  577,  576,  575,  574,  573,  572,  571,  570,
 /*   190 */   569,  578,  596,  582,  581,  626,  626,  626,  626,  626,
 /*   200 */   626,  626,  626,  626,  626,  626,  626,  626,  626,  626,
 /*   210 */   626,  626,  626,  626,  626,  626,  626,  626,  626,  626,
 /*   220 */   626,  626,  626,  626,  626,  626,  626,  626,  626,  626,
 /*   230 */   626,  626,  626,  550,  626,  626,  626,  611,  626,  626,
 /*   240 */   626,  626,  626,  626,  626,  626,  626,  626,  626,  626,
 /*   250 */   626,  626,  626,  626,  403,  415,  414,  413,  412,  411,
 /*   260 */   410,  409,  408,  407,  405,  507,  517,  515,  514,  513,
 /*   270 */   512,  511,  509,  527,  526,  525,  524,  523,  522,  521,
 /*   280 */   519,  532,  536,  535,  534,  533,  531,  529,  518,  505,
 /*   290 */   504,  503,  516,  508,  435,  438,  434,  436,  433,  432,
 /*   300 */   440,  431,  430,  424,  425,  422,  428,  427,  423,  421,
 /*   310 */   506,  618,  541,  540,  538,  555,  554,  553,  552,  551,
 /*   320 */   549,  548,  547,  546,  545,  544,  542,  537,  460,  461,
 /*   330 */   459,  444,  465,  466,  561,  616,  562,  568,  567,  566,
 /*   340 */   617,  565,  564,  560,  559,  558,  557,  556,  463,  462,
 /*   350 */   447,  445,  443,  621,  625,  624,  623,  494,  501,  499,
 /*   360 */   458,  502,  455,  500,  451,  456,  450,  449,  442,  448,
 /*   370 */   437,  622,  620,  491,  490,  489,  619,  488,  487,  486,
 /*   380 */   485,  484,  483,  482,  481,  480,  479,  478,  477,  476,
 /*   390 */   475,  474,  473,  472,  471,  470,  469,  468,  420,  419,
 /*   400 */   418,  416,
};

/* The next table maps tokens into fallback tokens.  If a construct
** like the following:
** 
**      %fallback ID X Y Z.
**
** appears in the grammar, then ID becomes a fallback token for X, Y,
** and Z.  Whenever one of the tokens X, Y, or Z is input to the parser
** but it does not parse, the type of the token is changed to ID and
** the parse is retried before an error is thrown.
*/
#ifdef YYFALLBACK
static const YYCODETYPE yyFallback[] = {
};
#endif /* YYFALLBACK */

/* The following structure represents a single element of the
** parser's stack.  Information stored includes:
**
**   +  The state number for the parser at this level of the stack.
**
**   +  The value of the token stored at this level of the stack.
**      (In other words, the "major" token.)
**
**   +  The semantic value stored at this level of the stack.  This is
**      the information used by the action routines in the grammar.
**      It is sometimes called the "minor" token.
*/
struct yyStackEntry {
  YYACTIONTYPE stateno;  /* The state-number */
  YYCODETYPE major;      /* The major token value.  This is the code
                         ** number for the token at this stack level */
  YYMINORTYPE minor;     /* The user-supplied minor token value.  This
                         ** is the value of the token  */
};
typedef struct yyStackEntry yyStackEntry;

/* The state of the parser is completely contained in an instance of
** the following structure */
struct yyParser {
  int yyidx;                    /* Index of top element in stack */
#ifdef YYTRACKMAXSTACKDEPTH
  int yyidxMax;                 /* Maximum value of yyidx */
#endif
  int yyerrcnt;                 /* Shifts left before out of the error */
  snlParserARG_SDECL                /* A place to hold %extra_argument */
#if YYSTACKDEPTH<=0
  int yystksz;                  /* Current side of the stack */
  yyStackEntry *yystack;        /* The parser's stack */
#else
  yyStackEntry yystack[YYSTACKDEPTH];  /* The parser's stack */
#endif
};
typedef struct yyParser yyParser;

#ifndef NDEBUG
#include <stdio.h>
static FILE *yyTraceFILE = 0;
static char *yyTracePrompt = 0;
#endif /* NDEBUG */

#ifndef NDEBUG
/* 
** Turn parser tracing on by giving a stream to which to write the trace
** and a prompt to preface each trace message.  Tracing is turned off
** by making either argument NULL 
**
** Inputs:
** <ul>
** <li> A FILE* to which trace output should be written.
**      If NULL, then tracing is turned off.
** <li> A prefix string written at the beginning of every
**      line of trace output.  If NULL, then tracing is
**      turned off.
** </ul>
**
** Outputs:
** None.
*/
void snlParserTrace(FILE *TraceFILE, char *zTracePrompt){
  yyTraceFILE = TraceFILE;
  yyTracePrompt = zTracePrompt;
  if( yyTraceFILE==0 ) yyTracePrompt = 0;
  else if( yyTracePrompt==0 ) yyTraceFILE = 0;
}
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing shifts, the names of all terminals and nonterminals
** are required.  The following table supplies these names */
static const char *const yyTokenName[] = { 
  "$",             "EQUAL",         "ADDEQ",         "SUBEQ",       
  "ANDEQ",         "OREQ",          "DIVEQ",         "MULEQ",       
  "MODEQ",         "LSHEQ",         "RSHEQ",         "XOREQ",       
  "QUESTION",      "COLON",         "OROR",          "ANDAND",      
  "VBAR",          "CARET",         "AMPERSAND",     "EQ",          
  "NE",            "GT",            "GE",            "LE",          
  "LT",            "LSHIFT",        "RSHIFT",        "ADD",         
  "SUB",           "ASTERISK",      "SLASH",         "MOD",         
  "NOT",           "TILDE",         "INCR",          "DECR",        
  "SIZEOF",        "PRE",           "LBRACKET",      "LPAREN",      
  "POINTER",       "PERIOD",        "POST",          "PROGRAM",     
  "NAME",          "RPAREN",        "ASSIGN",        "SEMICOLON",   
  "LBRACE",        "RBRACE",        "TO",            "COMMA",       
  "MONITOR",       "SYNC",          "SYNCQ",         "INTCON",      
  "RBRACKET",      "CONST",         "FOREIGN",       "CHAR",        
  "SHORT",         "INT",           "LONG",          "UNSIGNED",    
  "INT8T",         "UINT8T",        "INT16T",        "UINT16T",     
  "INT32T",        "UINT32T",       "FLOAT",         "DOUBLE",      
  "STRING",        "EVFLAG",        "VOID",          "ENUM",        
  "STRUCT",        "UNION",         "TYPENAME",      "OPTION",      
  "SS",            "STATE",         "ENTRY",         "EXIT",        
  "WHEN",          "BREAK",         "CONTINUE",      "RETURN",      
  "IF",            "ELSE",          "WHILE",         "FOR",         
  "FPCON",         "STRCON",        "CCODE",         "error",       
  "program",       "program_param",  "initial_defns",  "entry",       
  "state_sets",    "exit",          "final_defns",   "string",      
  "initial_defn",  "assign",        "monitor",       "sync",        
  "syncq",         "declaration",   "option",        "c_code",      
  "funcdef",       "structdef",     "final_defn",    "variable",    
  "to",            "subscript",     "strings",       "opt_subscript",
  "event_flag",    "syncq_size",    "basetype",      "init_declarators",
  "init_declarator",  "declarator",    "init_expr",     "param_decls", 
  "param_decl",    "type_expr",     "variables",     "init_exprs",  
  "expr",          "prim_type",     "abs_decl",      "option_value",
  "state_set",     "ss_defns",      "states",        "ss_defn",     
  "state",         "state_defns",   "transitions",   "state_defn",  
  "block",         "transition",    "condition",     "opt_expr",    
  "block_defns",   "statements",    "block_defn",    "statement",   
  "comma_expr",    "for_statement",  "args",          "member",      
  "members",       "member_decls",  "member_decl", 
};
#endif /* NDEBUG */

#ifndef NDEBUG
/* For tracing reduce actions, the names of all rules are required.
*/
static const char *const yyRuleName[] = {
 /*   0 */ "program ::= PROGRAM NAME program_param initial_defns entry state_sets exit final_defns",
 /*   1 */ "program_param ::= LPAREN string RPAREN",
 /*   2 */ "program_param ::=",
 /*   3 */ "initial_defns ::= initial_defns initial_defn",
 /*   4 */ "initial_defns ::=",
 /*   5 */ "initial_defn ::= assign",
 /*   6 */ "initial_defn ::= monitor",
 /*   7 */ "initial_defn ::= sync",
 /*   8 */ "initial_defn ::= syncq",
 /*   9 */ "initial_defn ::= declaration",
 /*  10 */ "initial_defn ::= option",
 /*  11 */ "initial_defn ::= c_code",
 /*  12 */ "initial_defn ::= funcdef",
 /*  13 */ "initial_defn ::= structdef",
 /*  14 */ "final_defns ::= final_defns final_defn",
 /*  15 */ "final_defns ::=",
 /*  16 */ "final_defn ::= c_code",
 /*  17 */ "final_defn ::= funcdef",
 /*  18 */ "final_defn ::= structdef",
 /*  19 */ "assign ::= ASSIGN variable to string SEMICOLON",
 /*  20 */ "assign ::= ASSIGN variable subscript to string SEMICOLON",
 /*  21 */ "assign ::= ASSIGN variable to LBRACE strings RBRACE SEMICOLON",
 /*  22 */ "assign ::= ASSIGN variable SEMICOLON",
 /*  23 */ "to ::= TO",
 /*  24 */ "to ::=",
 /*  25 */ "strings ::= strings COMMA string",
 /*  26 */ "strings ::= string",
 /*  27 */ "strings ::=",
 /*  28 */ "monitor ::= MONITOR variable opt_subscript SEMICOLON",
 /*  29 */ "monitor ::= MONITOR variable opt_subscript error SEMICOLON",
 /*  30 */ "sync ::= SYNC variable opt_subscript to event_flag SEMICOLON",
 /*  31 */ "sync ::= SYNC variable opt_subscript to event_flag error SEMICOLON",
 /*  32 */ "syncq ::= SYNCQ variable opt_subscript to event_flag syncq_size SEMICOLON",
 /*  33 */ "syncq ::= SYNCQ variable opt_subscript syncq_size SEMICOLON",
 /*  34 */ "event_flag ::= NAME",
 /*  35 */ "variable ::= NAME",
 /*  36 */ "syncq_size ::= INTCON",
 /*  37 */ "syncq_size ::=",
 /*  38 */ "opt_subscript ::= subscript",
 /*  39 */ "opt_subscript ::=",
 /*  40 */ "subscript ::= LBRACKET INTCON RBRACKET",
 /*  41 */ "declaration ::= basetype init_declarators SEMICOLON",
 /*  42 */ "init_declarators ::= init_declarator",
 /*  43 */ "init_declarators ::= init_declarators COMMA init_declarator",
 /*  44 */ "init_declarator ::= declarator",
 /*  45 */ "init_declarator ::= declarator EQUAL init_expr",
 /*  46 */ "declarator ::= variable",
 /*  47 */ "declarator ::= declarator subscript",
 /*  48 */ "declarator ::= declarator LPAREN param_decls RPAREN",
 /*  49 */ "declarator ::= LPAREN declarator RPAREN",
 /*  50 */ "declarator ::= ASTERISK declarator",
 /*  51 */ "declarator ::= CONST declarator",
 /*  52 */ "param_decls ::=",
 /*  53 */ "param_decls ::= param_decl",
 /*  54 */ "param_decls ::= param_decls COMMA param_decl",
 /*  55 */ "param_decl ::= basetype declarator",
 /*  56 */ "param_decl ::= type_expr",
 /*  57 */ "declaration ::= FOREIGN variables SEMICOLON",
 /*  58 */ "variables ::= variable",
 /*  59 */ "variables ::= variables COMMA variable",
 /*  60 */ "init_expr ::= LPAREN type_expr RPAREN LBRACE init_exprs RBRACE",
 /*  61 */ "init_expr ::= LBRACE init_exprs RBRACE",
 /*  62 */ "init_expr ::= expr",
 /*  63 */ "init_exprs ::= init_exprs COMMA init_expr",
 /*  64 */ "init_exprs ::= init_expr",
 /*  65 */ "init_exprs ::=",
 /*  66 */ "prim_type ::= CHAR",
 /*  67 */ "prim_type ::= SHORT",
 /*  68 */ "prim_type ::= INT",
 /*  69 */ "prim_type ::= LONG",
 /*  70 */ "prim_type ::= UNSIGNED CHAR",
 /*  71 */ "prim_type ::= UNSIGNED SHORT",
 /*  72 */ "prim_type ::= UNSIGNED INT",
 /*  73 */ "prim_type ::= UNSIGNED LONG",
 /*  74 */ "prim_type ::= INT8T",
 /*  75 */ "prim_type ::= UINT8T",
 /*  76 */ "prim_type ::= INT16T",
 /*  77 */ "prim_type ::= UINT16T",
 /*  78 */ "prim_type ::= INT32T",
 /*  79 */ "prim_type ::= UINT32T",
 /*  80 */ "prim_type ::= FLOAT",
 /*  81 */ "prim_type ::= DOUBLE",
 /*  82 */ "prim_type ::= STRING",
 /*  83 */ "basetype ::= prim_type",
 /*  84 */ "basetype ::= EVFLAG",
 /*  85 */ "basetype ::= VOID",
 /*  86 */ "basetype ::= ENUM NAME",
 /*  87 */ "basetype ::= STRUCT NAME",
 /*  88 */ "basetype ::= UNION NAME",
 /*  89 */ "basetype ::= TYPENAME NAME",
 /*  90 */ "type_expr ::= basetype",
 /*  91 */ "type_expr ::= basetype abs_decl",
 /*  92 */ "abs_decl ::= LPAREN abs_decl RPAREN",
 /*  93 */ "abs_decl ::= ASTERISK",
 /*  94 */ "abs_decl ::= ASTERISK abs_decl",
 /*  95 */ "abs_decl ::= CONST",
 /*  96 */ "abs_decl ::= CONST abs_decl",
 /*  97 */ "abs_decl ::= subscript",
 /*  98 */ "abs_decl ::= abs_decl subscript",
 /*  99 */ "abs_decl ::= LPAREN param_decls RPAREN",
 /* 100 */ "abs_decl ::= abs_decl LPAREN param_decls RPAREN",
 /* 101 */ "option ::= OPTION option_value NAME SEMICOLON",
 /* 102 */ "option_value ::= ADD",
 /* 103 */ "option_value ::= SUB",
 /* 104 */ "state_sets ::= state_sets state_set",
 /* 105 */ "state_sets ::= state_set",
 /* 106 */ "state_set ::= SS NAME LBRACE ss_defns states RBRACE",
 /* 107 */ "ss_defns ::= ss_defns ss_defn",
 /* 108 */ "ss_defns ::=",
 /* 109 */ "ss_defn ::= assign",
 /* 110 */ "ss_defn ::= monitor",
 /* 111 */ "ss_defn ::= sync",
 /* 112 */ "ss_defn ::= syncq",
 /* 113 */ "ss_defn ::= declaration",
 /* 114 */ "states ::= states state",
 /* 115 */ "states ::= state",
 /* 116 */ "state ::= STATE NAME LBRACE state_defns entry transitions exit RBRACE",
 /* 117 */ "state_defns ::= state_defns state_defn",
 /* 118 */ "state_defns ::=",
 /* 119 */ "state_defn ::= assign",
 /* 120 */ "state_defn ::= monitor",
 /* 121 */ "state_defn ::= sync",
 /* 122 */ "state_defn ::= syncq",
 /* 123 */ "state_defn ::= declaration",
 /* 124 */ "state_defn ::= option",
 /* 125 */ "entry ::= ENTRY block",
 /* 126 */ "entry ::=",
 /* 127 */ "exit ::= EXIT block",
 /* 128 */ "exit ::=",
 /* 129 */ "transitions ::= transitions transition",
 /* 130 */ "transitions ::= transition",
 /* 131 */ "transition ::= WHEN LPAREN condition RPAREN block STATE NAME",
 /* 132 */ "transition ::= WHEN LPAREN condition RPAREN block EXIT",
 /* 133 */ "transition ::= WHEN LPAREN condition RPAREN block error",
 /* 134 */ "condition ::= opt_expr",
 /* 135 */ "block ::= LBRACE block_defns statements RBRACE",
 /* 136 */ "block_defns ::= block_defns block_defn",
 /* 137 */ "block_defns ::=",
 /* 138 */ "block_defn ::= declaration",
 /* 139 */ "block_defn ::= c_code",
 /* 140 */ "statements ::= statements statement",
 /* 141 */ "statements ::=",
 /* 142 */ "statement ::= BREAK SEMICOLON",
 /* 143 */ "statement ::= CONTINUE SEMICOLON",
 /* 144 */ "statement ::= RETURN opt_expr SEMICOLON",
 /* 145 */ "statement ::= STATE NAME SEMICOLON",
 /* 146 */ "statement ::= c_code",
 /* 147 */ "statement ::= block",
 /* 148 */ "statement ::= IF LPAREN comma_expr RPAREN statement",
 /* 149 */ "statement ::= IF LPAREN comma_expr RPAREN statement ELSE statement",
 /* 150 */ "statement ::= WHILE LPAREN comma_expr RPAREN statement",
 /* 151 */ "statement ::= for_statement",
 /* 152 */ "statement ::= opt_expr SEMICOLON",
 /* 153 */ "for_statement ::= FOR LPAREN opt_expr SEMICOLON opt_expr SEMICOLON opt_expr RPAREN statement",
 /* 154 */ "expr ::= INTCON",
 /* 155 */ "expr ::= FPCON",
 /* 156 */ "expr ::= string",
 /* 157 */ "expr ::= variable",
 /* 158 */ "expr ::= LPAREN comma_expr RPAREN",
 /* 159 */ "expr ::= expr LPAREN args RPAREN",
 /* 160 */ "expr ::= EXIT LPAREN args RPAREN",
 /* 161 */ "expr ::= SIZEOF LPAREN type_expr RPAREN",
 /* 162 */ "expr ::= expr LBRACKET expr RBRACKET",
 /* 163 */ "expr ::= expr PERIOD member",
 /* 164 */ "expr ::= expr POINTER member",
 /* 165 */ "expr ::= expr INCR",
 /* 166 */ "expr ::= expr DECR",
 /* 167 */ "expr ::= ADD expr",
 /* 168 */ "expr ::= SUB expr",
 /* 169 */ "expr ::= ASTERISK expr",
 /* 170 */ "expr ::= AMPERSAND expr",
 /* 171 */ "expr ::= NOT expr",
 /* 172 */ "expr ::= TILDE expr",
 /* 173 */ "expr ::= INCR expr",
 /* 174 */ "expr ::= DECR expr",
 /* 175 */ "expr ::= SIZEOF expr",
 /* 176 */ "expr ::= LPAREN type_expr RPAREN expr",
 /* 177 */ "expr ::= expr SUB expr",
 /* 178 */ "expr ::= expr ADD expr",
 /* 179 */ "expr ::= expr ASTERISK expr",
 /* 180 */ "expr ::= expr SLASH expr",
 /* 181 */ "expr ::= expr GT expr",
 /* 182 */ "expr ::= expr GE expr",
 /* 183 */ "expr ::= expr EQ expr",
 /* 184 */ "expr ::= expr NE expr",
 /* 185 */ "expr ::= expr LE expr",
 /* 186 */ "expr ::= expr LT expr",
 /* 187 */ "expr ::= expr OROR expr",
 /* 188 */ "expr ::= expr ANDAND expr",
 /* 189 */ "expr ::= expr LSHIFT expr",
 /* 190 */ "expr ::= expr RSHIFT expr",
 /* 191 */ "expr ::= expr VBAR expr",
 /* 192 */ "expr ::= expr CARET expr",
 /* 193 */ "expr ::= expr AMPERSAND expr",
 /* 194 */ "expr ::= expr MOD expr",
 /* 195 */ "expr ::= expr QUESTION expr COLON expr",
 /* 196 */ "expr ::= expr EQUAL expr",
 /* 197 */ "expr ::= expr ADDEQ expr",
 /* 198 */ "expr ::= expr SUBEQ expr",
 /* 199 */ "expr ::= expr ANDEQ expr",
 /* 200 */ "expr ::= expr OREQ expr",
 /* 201 */ "expr ::= expr DIVEQ expr",
 /* 202 */ "expr ::= expr MULEQ expr",
 /* 203 */ "expr ::= expr MODEQ expr",
 /* 204 */ "expr ::= expr LSHEQ expr",
 /* 205 */ "expr ::= expr RSHEQ expr",
 /* 206 */ "expr ::= expr XOREQ expr",
 /* 207 */ "comma_expr ::= comma_expr COMMA expr",
 /* 208 */ "comma_expr ::= expr",
 /* 209 */ "opt_expr ::= comma_expr",
 /* 210 */ "opt_expr ::=",
 /* 211 */ "args ::= args COMMA expr",
 /* 212 */ "args ::= expr",
 /* 213 */ "args ::=",
 /* 214 */ "string ::= STRCON",
 /* 215 */ "member ::= NAME",
 /* 216 */ "funcdef ::= basetype declarator block",
 /* 217 */ "structdef ::= STRUCT NAME members SEMICOLON",
 /* 218 */ "members ::= LBRACE member_decls RBRACE",
 /* 219 */ "member_decls ::= member_decl",
 /* 220 */ "member_decls ::= member_decls member_decl",
 /* 221 */ "member_decl ::= basetype declarator SEMICOLON",
 /* 222 */ "member_decl ::= c_code",
 /* 223 */ "c_code ::= CCODE",
};
#endif /* NDEBUG */


#if YYSTACKDEPTH<=0
/*
** Try to increase the size of the parser stack.
*/
static void yyGrowStack(yyParser *p){
  int newSize;
  yyStackEntry *pNew;

  newSize = p->yystksz*2 + 100;
  assert(newSize > 0);
  pNew = realloc(p->yystack, (unsigned)newSize*sizeof(pNew[0]));
  if( pNew ){
    p->yystack = pNew;
    p->yystksz = newSize;
#ifndef NDEBUG
    if( yyTraceFILE ){
      fprintf(yyTraceFILE,"%sStack grows to %d entries!\n",
              yyTracePrompt, p->yystksz);
    }
#endif
  }
}
#endif

/* 
** This function allocates a new parser.
** The only argument is a pointer to a function which works like
** malloc.
**
** Inputs:
** A pointer to the function used to allocate memory.
**
** Outputs:
** A pointer to a parser.  This pointer is used in subsequent calls
** to snlParser and snlParserFree.
*/
void *snlParserAlloc(void *(*mallocProc)(size_t)){
  yyParser *pParser;
  pParser = (yyParser*)(*mallocProc)( (size_t)sizeof(yyParser) );
  if( pParser ){
    pParser->yyidx = -1;
#ifdef YYTRACKMAXSTACKDEPTH
    pParser->yyidxMax = 0;
#endif
#if YYSTACKDEPTH<=0
    pParser->yystack = NULL;
    pParser->yystksz = 0;
    yyGrowStack(pParser);
#endif
  }
  return pParser;
}

/* The following function deletes the value associated with a
** symbol.  The symbol can be either a terminal or nonterminal.
** "yymajor" is the symbol code, and "yypminor" is a pointer to
** the value.
*/
static void yy_destructor(
  yyParser *yypParser,    /* The parser */
  YYCODETYPE yymajor,     /* Type code for object to destroy */
  YYMINORTYPE *yypminor   /* The object to be destroyed */
){
  snlParserARG_FETCH;
  switch( yymajor ){
    /* Here is inserted the actions which take place when a
    ** terminal or non-terminal is destroyed.  This can happen
    ** when the symbol is popped from the stack during a
    ** reduce or during error processing or when a parser is 
    ** being destroyed before it is finished parsing.
    **
    ** Note: during a reduce, the only symbols destroyed are those
    ** which appear on the RHS of the rule, but which are not used
    ** inside the C code.
    */
    default:  break;   /* If no destructor action specified: do nothing */
  }
  snlParserARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** Pop the parser's stack once.
**
** If there is a destructor routine associated with the token which
** is popped from the stack, then call it.
**
** Return the major token number for the symbol popped.
*/
static int yy_pop_parser_stack(yyParser *pParser){
  YYCODETYPE yymajor;
  yyStackEntry *yytos = &pParser->yystack[pParser->yyidx];

  if( pParser->yyidx<0 ) return 0;
#ifndef NDEBUG
  if( yyTraceFILE && pParser->yyidx>=0 ){
    fprintf(yyTraceFILE,"%sPopping %s\n",
      yyTracePrompt,
      yyTokenName[yytos->major]);
  }
#endif
  yymajor = yytos->major;
  yy_destructor(pParser, yymajor, &yytos->minor);
  pParser->yyidx--;
  return yymajor;
}

/* 
** Deallocate and destroy a parser.  Destructors are all called for
** all stack elements before shutting the parser down.
**
** Inputs:
** <ul>
** <li>  A pointer to the parser.  This should be a pointer
**       obtained from snlParserAlloc.
** <li>  A pointer to a function used to reclaim memory obtained
**       from malloc.
** </ul>
*/
void snlParserFree(
  void *p,                    /* The parser to be deleted */
  void (*freeProc)(void*)     /* Function used to reclaim memory */
){
  yyParser *pParser = (yyParser*)p;
  if( pParser==0 ) return;
  while( pParser->yyidx>=0 ) yy_pop_parser_stack(pParser);
#if YYSTACKDEPTH<=0
  free(pParser->yystack);
#endif
  (*freeProc)((void*)pParser);
}

/*
** Return the peak depth of the stack for a parser.
*/
#ifdef YYTRACKMAXSTACKDEPTH
int snlParserStackPeak(void *p){
  yyParser *pParser = (yyParser*)p;
  return pParser->yyidxMax;
}
#endif

/*
** Find the appropriate action for a parser given the terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_shift_action(
  yyParser *pParser,        /* The parser */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
  int stateno = pParser->yystack[pParser->yyidx].stateno;
 
  if( stateno>YY_SHIFT_COUNT
   || (i = yy_shift_ofst[stateno])==YY_SHIFT_USE_DFLT ){
    return yy_default[stateno];
  }
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
  if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
    if( iLookAhead>0 ){
#ifdef YYFALLBACK
      YYCODETYPE iFallback;            /* Fallback token */
      if( iLookAhead<sizeof(yyFallback)/sizeof(yyFallback[0])
             && (iFallback = yyFallback[iLookAhead])!=0 ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE, "%sFALLBACK %s => %s\n",
             yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[iFallback]);
        }
#endif
        return yy_find_shift_action(pParser, iFallback);
      }
#endif
#ifdef YYWILDCARD
      {
        int j = i - iLookAhead + YYWILDCARD;
        if( 
#if YY_SHIFT_MIN+YYWILDCARD<0
          j>=0 &&
#endif
#if YY_SHIFT_MAX+YYWILDCARD>=YY_ACTTAB_COUNT
          j<YY_ACTTAB_COUNT &&
#endif
          yy_lookahead[j]==YYWILDCARD
        ){
#ifndef NDEBUG
          if( yyTraceFILE ){
            fprintf(yyTraceFILE, "%sWILDCARD %s => %s\n",
               yyTracePrompt, yyTokenName[iLookAhead], yyTokenName[YYWILDCARD]);
          }
#endif /* NDEBUG */
          return yy_action[j];
        }
      }
#endif /* YYWILDCARD */
    }
    return yy_default[stateno];
  }else{
    return yy_action[i];
  }
}

/*
** Find the appropriate action for a parser given the non-terminal
** look-ahead token iLookAhead.
**
** If the look-ahead token is YYNOCODE, then check to see if the action is
** independent of the look-ahead.  If it is, return the action, otherwise
** return YY_NO_ACTION.
*/
static int yy_find_reduce_action(
  int stateno,              /* Current state number */
  YYCODETYPE iLookAhead     /* The look-ahead token */
){
  int i;
#ifdef YYERRORSYMBOL
  if( stateno>YY_REDUCE_COUNT ){
    return yy_default[stateno];
  }
#else
  assert( stateno<=YY_REDUCE_COUNT );
#endif
  i = yy_reduce_ofst[stateno];
  assert( i!=YY_REDUCE_USE_DFLT );
  assert( iLookAhead!=YYNOCODE );
  i += iLookAhead;
#ifdef YYERRORSYMBOL
  if( i<0 || i>=YY_ACTTAB_COUNT || yy_lookahead[i]!=iLookAhead ){
    return yy_default[stateno];
  }
#else
  assert( i>=0 && i<YY_ACTTAB_COUNT );
  assert( yy_lookahead[i]==iLookAhead );
#endif
  return yy_action[i];
}

/*
** The following routine is called if the stack overflows.
*/
static void yyStackOverflow(yyParser *yypParser, YYMINORTYPE *yypMinor){
   snlParserARG_FETCH;
   yypParser->yyidx--;
#ifndef NDEBUG
   if( yyTraceFILE ){
     fprintf(yyTraceFILE,"%sStack Overflow!\n",yyTracePrompt);
   }
#endif
   while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
   /* Here code is inserted which will execute if the parser
   ** stack every overflows */
   snlParserARG_STORE; /* Suppress warning about unused %extra_argument var */
}

/*
** Perform a shift action.
*/
static void yy_shift(
  yyParser *yypParser,          /* The parser to be shifted */
  int yyNewState,               /* The new state to shift in */
  int yyMajor,                  /* The major token to shift in */
  YYMINORTYPE *yypMinor         /* Pointer to the minor token to shift in */
){
  yyStackEntry *yytos;
  yypParser->yyidx++;
#ifdef YYTRACKMAXSTACKDEPTH
  if( yypParser->yyidx>yypParser->yyidxMax ){
    yypParser->yyidxMax = yypParser->yyidx;
  }
#endif
#if YYSTACKDEPTH>0 
  if( yypParser->yyidx>=YYSTACKDEPTH ){
    yyStackOverflow(yypParser, yypMinor);
    return;
  }
#else
  if( yypParser->yyidx>=yypParser->yystksz ){
    yyGrowStack(yypParser);
    if( yypParser->yyidx>=yypParser->yystksz ){
      yyStackOverflow(yypParser, yypMinor);
      return;
    }
  }
#endif
  yytos = &yypParser->yystack[yypParser->yyidx];
  yytos->stateno = (YYACTIONTYPE)yyNewState;
  yytos->major = (YYCODETYPE)yyMajor;
  yytos->minor = *yypMinor;
#ifndef NDEBUG
  if( yyTraceFILE && yypParser->yyidx>0 ){
    int i;
    fprintf(yyTraceFILE,"%sShift %d\n",yyTracePrompt,yyNewState);
    fprintf(yyTraceFILE,"%sStack:",yyTracePrompt);
    for(i=1; i<=yypParser->yyidx; i++)
      fprintf(yyTraceFILE," %s",yyTokenName[yypParser->yystack[i].major]);
    fprintf(yyTraceFILE,"\n");
  }
#endif
}

/* The following table contains information about every rule that
** is used during the reduce.
*/
static const struct {
  YYCODETYPE lhs;         /* Symbol on the left-hand side of the rule */
  unsigned char nrhs;     /* Number of right-hand side symbols in the rule */
} yyRuleInfo[] = {
  { 96, 8 },
  { 97, 3 },
  { 97, 0 },
  { 98, 2 },
  { 98, 0 },
  { 104, 1 },
  { 104, 1 },
  { 104, 1 },
  { 104, 1 },
  { 104, 1 },
  { 104, 1 },
  { 104, 1 },
  { 104, 1 },
  { 104, 1 },
  { 102, 2 },
  { 102, 0 },
  { 114, 1 },
  { 114, 1 },
  { 114, 1 },
  { 105, 5 },
  { 105, 6 },
  { 105, 7 },
  { 105, 3 },
  { 116, 1 },
  { 116, 0 },
  { 118, 3 },
  { 118, 1 },
  { 118, 0 },
  { 106, 4 },
  { 106, 5 },
  { 107, 6 },
  { 107, 7 },
  { 108, 7 },
  { 108, 5 },
  { 120, 1 },
  { 115, 1 },
  { 121, 1 },
  { 121, 0 },
  { 119, 1 },
  { 119, 0 },
  { 117, 3 },
  { 109, 3 },
  { 123, 1 },
  { 123, 3 },
  { 124, 1 },
  { 124, 3 },
  { 125, 1 },
  { 125, 2 },
  { 125, 4 },
  { 125, 3 },
  { 125, 2 },
  { 125, 2 },
  { 127, 0 },
  { 127, 1 },
  { 127, 3 },
  { 128, 2 },
  { 128, 1 },
  { 109, 3 },
  { 130, 1 },
  { 130, 3 },
  { 126, 6 },
  { 126, 3 },
  { 126, 1 },
  { 131, 3 },
  { 131, 1 },
  { 131, 0 },
  { 133, 1 },
  { 133, 1 },
  { 133, 1 },
  { 133, 1 },
  { 133, 2 },
  { 133, 2 },
  { 133, 2 },
  { 133, 2 },
  { 133, 1 },
  { 133, 1 },
  { 133, 1 },
  { 133, 1 },
  { 133, 1 },
  { 133, 1 },
  { 133, 1 },
  { 133, 1 },
  { 133, 1 },
  { 122, 1 },
  { 122, 1 },
  { 122, 1 },
  { 122, 2 },
  { 122, 2 },
  { 122, 2 },
  { 122, 2 },
  { 129, 1 },
  { 129, 2 },
  { 134, 3 },
  { 134, 1 },
  { 134, 2 },
  { 134, 1 },
  { 134, 2 },
  { 134, 1 },
  { 134, 2 },
  { 134, 3 },
  { 134, 4 },
  { 110, 4 },
  { 135, 1 },
  { 135, 1 },
  { 100, 2 },
  { 100, 1 },
  { 136, 6 },
  { 137, 2 },
  { 137, 0 },
  { 139, 1 },
  { 139, 1 },
  { 139, 1 },
  { 139, 1 },
  { 139, 1 },
  { 138, 2 },
  { 138, 1 },
  { 140, 8 },
  { 141, 2 },
  { 141, 0 },
  { 143, 1 },
  { 143, 1 },
  { 143, 1 },
  { 143, 1 },
  { 143, 1 },
  { 143, 1 },
  { 99, 2 },
  { 99, 0 },
  { 101, 2 },
  { 101, 0 },
  { 142, 2 },
  { 142, 1 },
  { 145, 7 },
  { 145, 6 },
  { 145, 6 },
  { 146, 1 },
  { 144, 4 },
  { 148, 2 },
  { 148, 0 },
  { 150, 1 },
  { 150, 1 },
  { 149, 2 },
  { 149, 0 },
  { 151, 2 },
  { 151, 2 },
  { 151, 3 },
  { 151, 3 },
  { 151, 1 },
  { 151, 1 },
  { 151, 5 },
  { 151, 7 },
  { 151, 5 },
  { 151, 1 },
  { 151, 2 },
  { 153, 9 },
  { 132, 1 },
  { 132, 1 },
  { 132, 1 },
  { 132, 1 },
  { 132, 3 },
  { 132, 4 },
  { 132, 4 },
  { 132, 4 },
  { 132, 4 },
  { 132, 3 },
  { 132, 3 },
  { 132, 2 },
  { 132, 2 },
  { 132, 2 },
  { 132, 2 },
  { 132, 2 },
  { 132, 2 },
  { 132, 2 },
  { 132, 2 },
  { 132, 2 },
  { 132, 2 },
  { 132, 2 },
  { 132, 4 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 5 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 132, 3 },
  { 152, 3 },
  { 152, 1 },
  { 147, 1 },
  { 147, 0 },
  { 154, 3 },
  { 154, 1 },
  { 154, 0 },
  { 103, 1 },
  { 155, 1 },
  { 112, 3 },
  { 113, 4 },
  { 156, 3 },
  { 157, 1 },
  { 157, 2 },
  { 158, 3 },
  { 158, 1 },
  { 111, 1 },
};

static void yy_accept(yyParser*);  /* Forward Declaration */

/*
** Perform a reduce action and the shift that must immediately
** follow the reduce.
*/
static void yy_reduce(
  yyParser *yypParser,         /* The parser */
  int yyruleno                 /* Number of the rule by which to reduce */
){
  int yygoto;                     /* The next state */
  int yyact;                      /* The next action */
  YYMINORTYPE yygotominor;        /* The LHS of the rule reduced */
  yyStackEntry *yymsp;            /* The top of the parser's stack */
  int yysize;                     /* Amount to pop the stack */
  snlParserARG_FETCH;
  yymsp = &yypParser->yystack[yypParser->yyidx];
#ifndef NDEBUG
  if( yyTraceFILE && yyruleno>=0 
        && yyruleno<(int)(sizeof(yyRuleName)/sizeof(yyRuleName[0])) ){
    fprintf(yyTraceFILE, "%sReduce [%s].\n", yyTracePrompt,
      yyRuleName[yyruleno]);
  }
#endif /* NDEBUG */

  /* Silence complaints from purify about yygotominor being uninitialized
  ** in some cases when it is copied into the stack after the following
  ** switch.  yygotominor is uninitialized when a rule reduces that does
  ** not set the value of its left-hand side nonterminal.  Leaving the
  ** value of the nonterminal uninitialized is utterly harmless as long
  ** as the value is never used.  So really the only thing this code
  ** accomplishes is to quieten purify.  
  **
  ** 2007-01-16:  The wireshark project (www.wireshark.org) reports that
  ** without this code, their parser segfaults.  I'm not sure what there
  ** parser is doing to make this happen.  This is the second bug report
  ** from wireshark this week.  Clearly they are stressing Lemon in ways
  ** that it has not been previously stressed...  (SQLite ticket #2172)
  */
  /*memset(&yygotominor, 0, sizeof(yygotominor));*/
  yygotominor = yyzerominor;


  switch( yyruleno ){
  /* Beginning here are the reduction cases.  A typical example
  ** follows:
  **   case 0:
  **  #line <lineno> <grammarfile>
  **     { ... }           // User supplied code
  **  #line <lineno> <thisfile>
  **     break;
  */
      case 0: /* program ::= PROGRAM NAME program_param initial_defns entry state_sets exit final_defns */
#line 101 "../snl.lem"
{
	*presult =  node(D_PROG, yymsp[-6].minor.yy0, yymsp[-5].minor.yy255, yymsp[-4].minor.yy255, yymsp[-3].minor.yy255, yymsp[-2].minor.yy255, yymsp[-1].minor.yy255, yymsp[0].minor.yy255);
}
#line 1508 "./snl.c"
        break;
      case 1: /* program_param ::= LPAREN string RPAREN */
      case 49: /* declarator ::= LPAREN declarator RPAREN */ yytestcase(yyruleno==49);
      case 92: /* abs_decl ::= LPAREN abs_decl RPAREN */ yytestcase(yyruleno==92);
      case 218: /* members ::= LBRACE member_decls RBRACE */ yytestcase(yyruleno==218);
#line 105 "../snl.lem"
{ yygotominor.yy255 = yymsp[-1].minor.yy255; }
#line 1516 "./snl.c"
        break;
      case 2: /* program_param ::= */
      case 4: /* initial_defns ::= */ yytestcase(yyruleno==4);
      case 15: /* final_defns ::= */ yytestcase(yyruleno==15);
      case 27: /* strings ::= */ yytestcase(yyruleno==27);
      case 37: /* syncq_size ::= */ yytestcase(yyruleno==37);
      case 39: /* opt_subscript ::= */ yytestcase(yyruleno==39);
      case 52: /* param_decls ::= */ yytestcase(yyruleno==52);
      case 65: /* init_exprs ::= */ yytestcase(yyruleno==65);
      case 108: /* ss_defns ::= */ yytestcase(yyruleno==108);
      case 118: /* state_defns ::= */ yytestcase(yyruleno==118);
      case 126: /* entry ::= */ yytestcase(yyruleno==126);
      case 128: /* exit ::= */ yytestcase(yyruleno==128);
      case 137: /* block_defns ::= */ yytestcase(yyruleno==137);
      case 141: /* statements ::= */ yytestcase(yyruleno==141);
      case 210: /* opt_expr ::= */ yytestcase(yyruleno==210);
      case 213: /* args ::= */ yytestcase(yyruleno==213);
#line 106 "../snl.lem"
{ yygotominor.yy255 = 0; }
#line 1536 "./snl.c"
        break;
      case 3: /* initial_defns ::= initial_defns initial_defn */
      case 14: /* final_defns ::= final_defns final_defn */ yytestcase(yyruleno==14);
      case 117: /* state_defns ::= state_defns state_defn */ yytestcase(yyruleno==117);
      case 136: /* block_defns ::= block_defns block_defn */ yytestcase(yyruleno==136);
#line 110 "../snl.lem"
{
	yygotominor.yy255 = link_node(yymsp[-1].minor.yy255, yymsp[0].minor.yy255);
}
#line 1546 "./snl.c"
        break;
      case 5: /* initial_defn ::= assign */
      case 6: /* initial_defn ::= monitor */ yytestcase(yyruleno==6);
      case 7: /* initial_defn ::= sync */ yytestcase(yyruleno==7);
      case 8: /* initial_defn ::= syncq */ yytestcase(yyruleno==8);
      case 9: /* initial_defn ::= declaration */ yytestcase(yyruleno==9);
      case 10: /* initial_defn ::= option */ yytestcase(yyruleno==10);
      case 11: /* initial_defn ::= c_code */ yytestcase(yyruleno==11);
      case 12: /* initial_defn ::= funcdef */ yytestcase(yyruleno==12);
      case 13: /* initial_defn ::= structdef */ yytestcase(yyruleno==13);
      case 16: /* final_defn ::= c_code */ yytestcase(yyruleno==16);
      case 17: /* final_defn ::= funcdef */ yytestcase(yyruleno==17);
      case 18: /* final_defn ::= structdef */ yytestcase(yyruleno==18);
      case 26: /* strings ::= string */ yytestcase(yyruleno==26);
      case 42: /* init_declarators ::= init_declarator */ yytestcase(yyruleno==42);
      case 44: /* init_declarator ::= declarator */ yytestcase(yyruleno==44);
      case 53: /* param_decls ::= param_decl */ yytestcase(yyruleno==53);
      case 56: /* param_decl ::= type_expr */ yytestcase(yyruleno==56);
      case 62: /* init_expr ::= expr */ yytestcase(yyruleno==62);
      case 64: /* init_exprs ::= init_expr */ yytestcase(yyruleno==64);
      case 105: /* state_sets ::= state_set */ yytestcase(yyruleno==105);
      case 109: /* ss_defn ::= assign */ yytestcase(yyruleno==109);
      case 110: /* ss_defn ::= monitor */ yytestcase(yyruleno==110);
      case 111: /* ss_defn ::= sync */ yytestcase(yyruleno==111);
      case 112: /* ss_defn ::= syncq */ yytestcase(yyruleno==112);
      case 113: /* ss_defn ::= declaration */ yytestcase(yyruleno==113);
      case 115: /* states ::= state */ yytestcase(yyruleno==115);
      case 119: /* state_defn ::= assign */ yytestcase(yyruleno==119);
      case 120: /* state_defn ::= monitor */ yytestcase(yyruleno==120);
      case 121: /* state_defn ::= sync */ yytestcase(yyruleno==121);
      case 122: /* state_defn ::= syncq */ yytestcase(yyruleno==122);
      case 123: /* state_defn ::= declaration */ yytestcase(yyruleno==123);
      case 124: /* state_defn ::= option */ yytestcase(yyruleno==124);
      case 130: /* transitions ::= transition */ yytestcase(yyruleno==130);
      case 134: /* condition ::= opt_expr */ yytestcase(yyruleno==134);
      case 138: /* block_defn ::= declaration */ yytestcase(yyruleno==138);
      case 139: /* block_defn ::= c_code */ yytestcase(yyruleno==139);
      case 146: /* statement ::= c_code */ yytestcase(yyruleno==146);
      case 147: /* statement ::= block */ yytestcase(yyruleno==147);
      case 151: /* statement ::= for_statement */ yytestcase(yyruleno==151);
      case 156: /* expr ::= string */ yytestcase(yyruleno==156);
      case 208: /* comma_expr ::= expr */ yytestcase(yyruleno==208);
      case 209: /* opt_expr ::= comma_expr */ yytestcase(yyruleno==209);
      case 212: /* args ::= expr */ yytestcase(yyruleno==212);
      case 219: /* member_decls ::= member_decl */ yytestcase(yyruleno==219);
      case 222: /* member_decl ::= c_code */ yytestcase(yyruleno==222);
#line 115 "../snl.lem"
{ yygotominor.yy255 = yymsp[0].minor.yy255; }
#line 1595 "./snl.c"
        break;
      case 19: /* assign ::= ASSIGN variable to string SEMICOLON */
#line 134 "../snl.lem"
{
	yygotominor.yy255 = node(D_ASSIGN, yymsp[-3].minor.yy270, NIL, yymsp[-1].minor.yy255);
}
#line 1602 "./snl.c"
        break;
      case 20: /* assign ::= ASSIGN variable subscript to string SEMICOLON */
#line 137 "../snl.lem"
{
	yygotominor.yy255 = node(D_ASSIGN, yymsp[-4].minor.yy270, node(E_CONST, yymsp[-3].minor.yy270), yymsp[-1].minor.yy255);
}
#line 1609 "./snl.c"
        break;
      case 21: /* assign ::= ASSIGN variable to LBRACE strings RBRACE SEMICOLON */
#line 140 "../snl.lem"
{
	yygotominor.yy255 = node(D_ASSIGN, yymsp[-5].minor.yy270, NIL, node(E_INIT, yymsp[-3].minor.yy0, yymsp[-2].minor.yy255));
}
#line 1616 "./snl.c"
        break;
      case 22: /* assign ::= ASSIGN variable SEMICOLON */
#line 143 "../snl.lem"
{
	yygotominor.yy255 = node(D_ASSIGN, yymsp[-1].minor.yy270, NIL, NIL);
}
#line 1623 "./snl.c"
        break;
      case 25: /* strings ::= strings COMMA string */
      case 43: /* init_declarators ::= init_declarators COMMA init_declarator */ yytestcase(yyruleno==43);
      case 54: /* param_decls ::= param_decls COMMA param_decl */ yytestcase(yyruleno==54);
      case 63: /* init_exprs ::= init_exprs COMMA init_expr */ yytestcase(yyruleno==63);
      case 211: /* args ::= args COMMA expr */ yytestcase(yyruleno==211);
#line 150 "../snl.lem"
{ yygotominor.yy255 = link_node(yymsp[-2].minor.yy255, yymsp[0].minor.yy255); }
#line 1632 "./snl.c"
        break;
      case 28: /* monitor ::= MONITOR variable opt_subscript SEMICOLON */
#line 154 "../snl.lem"
{
	yygotominor.yy255 = node(D_MONITOR, yymsp[-2].minor.yy270, yymsp[-1].minor.yy255);
}
#line 1639 "./snl.c"
        break;
      case 29: /* monitor ::= MONITOR variable opt_subscript error SEMICOLON */
#line 157 "../snl.lem"
{
	yygotominor.yy255 = node(D_MONITOR, yymsp[-3].minor.yy270, yymsp[-2].minor.yy255);
	report("expected %s';'\n", yymsp[-2].minor.yy255 ? "subscript or " : "");
}
#line 1647 "./snl.c"
        break;
      case 30: /* sync ::= SYNC variable opt_subscript to event_flag SEMICOLON */
#line 162 "../snl.lem"
{
	yygotominor.yy255 = node(D_SYNC, yymsp[-4].minor.yy270, yymsp[-3].minor.yy255, node(E_VAR, yymsp[-1].minor.yy270), NIL);
}
#line 1654 "./snl.c"
        break;
      case 31: /* sync ::= SYNC variable opt_subscript to event_flag error SEMICOLON */
#line 165 "../snl.lem"
{
	yygotominor.yy255 = node(D_SYNC, yymsp[-5].minor.yy270, yymsp[-4].minor.yy255, node(E_VAR, yymsp[-2].minor.yy270), NIL);
	report("expected ';'\n");
}
#line 1662 "./snl.c"
        break;
      case 32: /* syncq ::= SYNCQ variable opt_subscript to event_flag syncq_size SEMICOLON */
#line 170 "../snl.lem"
{
	yygotominor.yy255 = node(D_SYNCQ, yymsp[-5].minor.yy270, yymsp[-4].minor.yy255, node(E_VAR, yymsp[-2].minor.yy270), yymsp[-1].minor.yy255);
}
#line 1669 "./snl.c"
        break;
      case 33: /* syncq ::= SYNCQ variable opt_subscript syncq_size SEMICOLON */
#line 173 "../snl.lem"
{
	yygotominor.yy255 = node(D_SYNCQ, yymsp[-3].minor.yy270, yymsp[-2].minor.yy255, NIL, yymsp[-1].minor.yy255);
}
#line 1676 "./snl.c"
        break;
      case 34: /* event_flag ::= NAME */
      case 35: /* variable ::= NAME */ yytestcase(yyruleno==35);
      case 102: /* option_value ::= ADD */ yytestcase(yyruleno==102);
      case 103: /* option_value ::= SUB */ yytestcase(yyruleno==103);
#line 178 "../snl.lem"
{ yygotominor.yy270 = yymsp[0].minor.yy0; }
#line 1684 "./snl.c"
        break;
      case 36: /* syncq_size ::= INTCON */
      case 154: /* expr ::= INTCON */ yytestcase(yyruleno==154);
      case 155: /* expr ::= FPCON */ yytestcase(yyruleno==155);
#line 182 "../snl.lem"
{ yygotominor.yy255 = node(E_CONST, yymsp[0].minor.yy0); }
#line 1691 "./snl.c"
        break;
      case 38: /* opt_subscript ::= subscript */
#line 185 "../snl.lem"
{ yygotominor.yy255 = node(E_CONST, yymsp[0].minor.yy270); }
#line 1696 "./snl.c"
        break;
      case 40: /* subscript ::= LBRACKET INTCON RBRACKET */
#line 189 "../snl.lem"
{ yygotominor.yy270 = yymsp[-1].minor.yy0; }
#line 1701 "./snl.c"
        break;
      case 41: /* declaration ::= basetype init_declarators SEMICOLON */
#line 194 "../snl.lem"
{ yygotominor.yy255 = mk_decls(yymsp[-1].minor.yy255, yymsp[-2].minor.yy149); }
#line 1706 "./snl.c"
        break;
      case 45: /* init_declarator ::= declarator EQUAL init_expr */
      case 177: /* expr ::= expr SUB expr */ yytestcase(yyruleno==177);
      case 178: /* expr ::= expr ADD expr */ yytestcase(yyruleno==178);
      case 179: /* expr ::= expr ASTERISK expr */ yytestcase(yyruleno==179);
      case 180: /* expr ::= expr SLASH expr */ yytestcase(yyruleno==180);
      case 181: /* expr ::= expr GT expr */ yytestcase(yyruleno==181);
      case 182: /* expr ::= expr GE expr */ yytestcase(yyruleno==182);
      case 183: /* expr ::= expr EQ expr */ yytestcase(yyruleno==183);
      case 184: /* expr ::= expr NE expr */ yytestcase(yyruleno==184);
      case 185: /* expr ::= expr LE expr */ yytestcase(yyruleno==185);
      case 186: /* expr ::= expr LT expr */ yytestcase(yyruleno==186);
      case 187: /* expr ::= expr OROR expr */ yytestcase(yyruleno==187);
      case 188: /* expr ::= expr ANDAND expr */ yytestcase(yyruleno==188);
      case 189: /* expr ::= expr LSHIFT expr */ yytestcase(yyruleno==189);
      case 190: /* expr ::= expr RSHIFT expr */ yytestcase(yyruleno==190);
      case 191: /* expr ::= expr VBAR expr */ yytestcase(yyruleno==191);
      case 192: /* expr ::= expr CARET expr */ yytestcase(yyruleno==192);
      case 193: /* expr ::= expr AMPERSAND expr */ yytestcase(yyruleno==193);
      case 194: /* expr ::= expr MOD expr */ yytestcase(yyruleno==194);
      case 196: /* expr ::= expr EQUAL expr */ yytestcase(yyruleno==196);
      case 197: /* expr ::= expr ADDEQ expr */ yytestcase(yyruleno==197);
      case 198: /* expr ::= expr SUBEQ expr */ yytestcase(yyruleno==198);
      case 199: /* expr ::= expr ANDEQ expr */ yytestcase(yyruleno==199);
      case 200: /* expr ::= expr OREQ expr */ yytestcase(yyruleno==200);
      case 201: /* expr ::= expr DIVEQ expr */ yytestcase(yyruleno==201);
      case 202: /* expr ::= expr MULEQ expr */ yytestcase(yyruleno==202);
      case 203: /* expr ::= expr MODEQ expr */ yytestcase(yyruleno==203);
      case 204: /* expr ::= expr LSHEQ expr */ yytestcase(yyruleno==204);
      case 205: /* expr ::= expr RSHEQ expr */ yytestcase(yyruleno==205);
      case 206: /* expr ::= expr XOREQ expr */ yytestcase(yyruleno==206);
      case 207: /* comma_expr ::= comma_expr COMMA expr */ yytestcase(yyruleno==207);
#line 202 "../snl.lem"
{ yygotominor.yy255 = node(E_BINOP, yymsp[-1].minor.yy0, yymsp[-2].minor.yy255, yymsp[0].minor.yy255); }
#line 1741 "./snl.c"
        break;
      case 46: /* declarator ::= variable */
      case 58: /* variables ::= variable */ yytestcase(yyruleno==58);
      case 157: /* expr ::= variable */ yytestcase(yyruleno==157);
#line 204 "../snl.lem"
{ yygotominor.yy255 = node(E_VAR, yymsp[0].minor.yy270); }
#line 1748 "./snl.c"
        break;
      case 47: /* declarator ::= declarator subscript */
      case 98: /* abs_decl ::= abs_decl subscript */ yytestcase(yyruleno==98);
#line 205 "../snl.lem"
{ yygotominor.yy255 = node(E_SUBSCR, yymsp[0].minor.yy270, yymsp[-1].minor.yy255, node(E_CONST, yymsp[0].minor.yy270)); }
#line 1754 "./snl.c"
        break;
      case 48: /* declarator ::= declarator LPAREN param_decls RPAREN */
      case 100: /* abs_decl ::= abs_decl LPAREN param_decls RPAREN */ yytestcase(yyruleno==100);
#line 207 "../snl.lem"
{ yygotominor.yy255 = node(E_FUNC, yymsp[-2].minor.yy0, yymsp[-3].minor.yy255, yymsp[-1].minor.yy255); }
#line 1760 "./snl.c"
        break;
      case 50: /* declarator ::= ASTERISK declarator */
      case 51: /* declarator ::= CONST declarator */ yytestcase(yyruleno==51);
      case 94: /* abs_decl ::= ASTERISK abs_decl */ yytestcase(yyruleno==94);
      case 96: /* abs_decl ::= CONST abs_decl */ yytestcase(yyruleno==96);
      case 167: /* expr ::= ADD expr */ yytestcase(yyruleno==167);
      case 168: /* expr ::= SUB expr */ yytestcase(yyruleno==168);
      case 169: /* expr ::= ASTERISK expr */ yytestcase(yyruleno==169);
      case 170: /* expr ::= AMPERSAND expr */ yytestcase(yyruleno==170);
      case 171: /* expr ::= NOT expr */ yytestcase(yyruleno==171);
      case 172: /* expr ::= TILDE expr */ yytestcase(yyruleno==172);
      case 173: /* expr ::= INCR expr */ yytestcase(yyruleno==173);
      case 174: /* expr ::= DECR expr */ yytestcase(yyruleno==174);
#line 209 "../snl.lem"
{ yygotominor.yy255 = node(E_PRE, yymsp[-1].minor.yy0, yymsp[0].minor.yy255); }
#line 1776 "./snl.c"
        break;
      case 55: /* param_decl ::= basetype declarator */
      case 91: /* type_expr ::= basetype abs_decl */ yytestcase(yyruleno==91);
#line 217 "../snl.lem"
{ yygotominor.yy255 = mk_decl(yymsp[0].minor.yy255, yymsp[-1].minor.yy149); }
#line 1782 "./snl.c"
        break;
      case 57: /* declaration ::= FOREIGN variables SEMICOLON */
#line 221 "../snl.lem"
{ yygotominor.yy255 = mk_decls(yymsp[-1].minor.yy255, mk_no_type()); }
#line 1787 "./snl.c"
        break;
      case 59: /* variables ::= variables COMMA variable */
#line 224 "../snl.lem"
{ yygotominor.yy255 = link_node(yymsp[-2].minor.yy255, node(E_VAR, yymsp[0].minor.yy270)); }
#line 1792 "./snl.c"
        break;
      case 60: /* init_expr ::= LPAREN type_expr RPAREN LBRACE init_exprs RBRACE */
#line 229 "../snl.lem"
{ yygotominor.yy255 = node(E_CAST, yymsp[-5].minor.yy0, yymsp[-4].minor.yy255, node(E_INIT, yymsp[-2].minor.yy0, yymsp[-1].minor.yy255)); }
#line 1797 "./snl.c"
        break;
      case 61: /* init_expr ::= LBRACE init_exprs RBRACE */
#line 230 "../snl.lem"
{ yygotominor.yy255 = node(E_INIT, yymsp[-2].minor.yy0, yymsp[-1].minor.yy255); }
#line 1802 "./snl.c"
        break;
      case 66: /* prim_type ::= CHAR */
#line 241 "../snl.lem"
{ yygotominor.yy6 = P_CHAR; }
#line 1807 "./snl.c"
        break;
      case 67: /* prim_type ::= SHORT */
#line 242 "../snl.lem"
{ yygotominor.yy6 = P_SHORT; }
#line 1812 "./snl.c"
        break;
      case 68: /* prim_type ::= INT */
#line 243 "../snl.lem"
{ yygotominor.yy6 = P_INT; }
#line 1817 "./snl.c"
        break;
      case 69: /* prim_type ::= LONG */
#line 244 "../snl.lem"
{ yygotominor.yy6 = P_LONG; }
#line 1822 "./snl.c"
        break;
      case 70: /* prim_type ::= UNSIGNED CHAR */
#line 245 "../snl.lem"
{ yygotominor.yy6 = P_UCHAR; }
#line 1827 "./snl.c"
        break;
      case 71: /* prim_type ::= UNSIGNED SHORT */
#line 246 "../snl.lem"
{ yygotominor.yy6 = P_USHORT; }
#line 1832 "./snl.c"
        break;
      case 72: /* prim_type ::= UNSIGNED INT */
#line 247 "../snl.lem"
{ yygotominor.yy6 = P_UINT; }
#line 1837 "./snl.c"
        break;
      case 73: /* prim_type ::= UNSIGNED LONG */
#line 248 "../snl.lem"
{ yygotominor.yy6 = P_ULONG; }
#line 1842 "./snl.c"
        break;
      case 74: /* prim_type ::= INT8T */
#line 249 "../snl.lem"
{ yygotominor.yy6 = P_INT8T; }
#line 1847 "./snl.c"
        break;
      case 75: /* prim_type ::= UINT8T */
#line 250 "../snl.lem"
{ yygotominor.yy6 = P_UINT8T; }
#line 1852 "./snl.c"
        break;
      case 76: /* prim_type ::= INT16T */
#line 251 "../snl.lem"
{ yygotominor.yy6 = P_INT16T; }
#line 1857 "./snl.c"
        break;
      case 77: /* prim_type ::= UINT16T */
#line 252 "../snl.lem"
{ yygotominor.yy6 = P_UINT16T; }
#line 1862 "./snl.c"
        break;
      case 78: /* prim_type ::= INT32T */
#line 253 "../snl.lem"
{ yygotominor.yy6 = P_INT32T; }
#line 1867 "./snl.c"
        break;
      case 79: /* prim_type ::= UINT32T */
#line 254 "../snl.lem"
{ yygotominor.yy6 = P_UINT32T; }
#line 1872 "./snl.c"
        break;
      case 80: /* prim_type ::= FLOAT */
#line 255 "../snl.lem"
{ yygotominor.yy6 = P_FLOAT; }
#line 1877 "./snl.c"
        break;
      case 81: /* prim_type ::= DOUBLE */
#line 256 "../snl.lem"
{ yygotominor.yy6 = P_DOUBLE; }
#line 1882 "./snl.c"
        break;
      case 82: /* prim_type ::= STRING */
#line 257 "../snl.lem"
{ yygotominor.yy6 = P_STRING; }
#line 1887 "./snl.c"
        break;
      case 83: /* basetype ::= prim_type */
#line 260 "../snl.lem"
{ yygotominor.yy149 = mk_prim_type(yymsp[0].minor.yy6); }
#line 1892 "./snl.c"
        break;
      case 84: /* basetype ::= EVFLAG */
#line 261 "../snl.lem"
{ yygotominor.yy149 = mk_ef_type(); }
#line 1897 "./snl.c"
        break;
      case 85: /* basetype ::= VOID */
#line 262 "../snl.lem"
{ yygotominor.yy149 = mk_void_type(); }
#line 1902 "./snl.c"
        break;
      case 86: /* basetype ::= ENUM NAME */
#line 263 "../snl.lem"
{ yygotominor.yy149 = mk_foreign_type(F_ENUM, yymsp[0].minor.yy0.str); }
#line 1907 "./snl.c"
        break;
      case 87: /* basetype ::= STRUCT NAME */
#line 264 "../snl.lem"
{ yygotominor.yy149 = mk_foreign_type(F_STRUCT, yymsp[0].minor.yy0.str); }
#line 1912 "./snl.c"
        break;
      case 88: /* basetype ::= UNION NAME */
#line 265 "../snl.lem"
{ yygotominor.yy149 = mk_foreign_type(F_UNION, yymsp[0].minor.yy0.str); }
#line 1917 "./snl.c"
        break;
      case 89: /* basetype ::= TYPENAME NAME */
#line 266 "../snl.lem"
{ yygotominor.yy149 = mk_foreign_type(F_TYPENAME, yymsp[0].minor.yy0.str); }
#line 1922 "./snl.c"
        break;
      case 90: /* type_expr ::= basetype */
#line 268 "../snl.lem"
{ yygotominor.yy255 = mk_decl(0, yymsp[0].minor.yy149); }
#line 1927 "./snl.c"
        break;
      case 93: /* abs_decl ::= ASTERISK */
      case 95: /* abs_decl ::= CONST */ yytestcase(yyruleno==95);
#line 273 "../snl.lem"
{ yygotominor.yy255 = node(E_PRE, yymsp[0].minor.yy0, NIL); }
#line 1933 "./snl.c"
        break;
      case 97: /* abs_decl ::= subscript */
#line 277 "../snl.lem"
{ yygotominor.yy255 = node(E_SUBSCR, yymsp[0].minor.yy270, NIL, node(E_CONST, yymsp[0].minor.yy270)); }
#line 1938 "./snl.c"
        break;
      case 99: /* abs_decl ::= LPAREN param_decls RPAREN */
#line 280 "../snl.lem"
{ yygotominor.yy255 = node(E_FUNC, yymsp[-2].minor.yy0, NIL, yymsp[-1].minor.yy255); }
#line 1943 "./snl.c"
        break;
      case 101: /* option ::= OPTION option_value NAME SEMICOLON */
#line 293 "../snl.lem"
{ yygotominor.yy255 = opt_defn(yymsp[-1].minor.yy0, yymsp[-2].minor.yy270); }
#line 1948 "./snl.c"
        break;
      case 104: /* state_sets ::= state_sets state_set */
      case 107: /* ss_defns ::= ss_defns ss_defn */ yytestcase(yyruleno==107);
      case 114: /* states ::= states state */ yytestcase(yyruleno==114);
      case 129: /* transitions ::= transitions transition */ yytestcase(yyruleno==129);
      case 140: /* statements ::= statements statement */ yytestcase(yyruleno==140);
      case 220: /* member_decls ::= member_decls member_decl */ yytestcase(yyruleno==220);
#line 301 "../snl.lem"
{ yygotominor.yy255 = link_node(yymsp[-1].minor.yy255, yymsp[0].minor.yy255); }
#line 1958 "./snl.c"
        break;
      case 106: /* state_set ::= SS NAME LBRACE ss_defns states RBRACE */
#line 305 "../snl.lem"
{ yygotominor.yy255 = node(D_SS, yymsp[-4].minor.yy0, yymsp[-2].minor.yy255, yymsp[-1].minor.yy255); }
#line 1963 "./snl.c"
        break;
      case 116: /* state ::= STATE NAME LBRACE state_defns entry transitions exit RBRACE */
#line 322 "../snl.lem"
{
	yygotominor.yy255 = node(D_STATE, yymsp[-6].minor.yy0, yymsp[-4].minor.yy255, yymsp[-3].minor.yy255, yymsp[-2].minor.yy255, yymsp[-1].minor.yy255);
}
#line 1970 "./snl.c"
        break;
      case 125: /* entry ::= ENTRY block */
      case 127: /* exit ::= EXIT block */ yytestcase(yyruleno==127);
#line 338 "../snl.lem"
{ yygotominor.yy255 = node(D_ENTEX, yymsp[-1].minor.yy0, yymsp[0].minor.yy255); }
#line 1976 "./snl.c"
        break;
      case 131: /* transition ::= WHEN LPAREN condition RPAREN block STATE NAME */
#line 347 "../snl.lem"
{
	yymsp[-6].minor.yy0.str = yymsp[0].minor.yy0.str;
	yygotominor.yy255 = node(D_WHEN, yymsp[-6].minor.yy0, yymsp[-4].minor.yy255, yymsp[-2].minor.yy255);
}
#line 1984 "./snl.c"
        break;
      case 132: /* transition ::= WHEN LPAREN condition RPAREN block EXIT */
#line 351 "../snl.lem"
{
	yymsp[-5].minor.yy0.str = 0;
	yygotominor.yy255 = node(D_WHEN, yymsp[-5].minor.yy0, yymsp[-3].minor.yy255, yymsp[-1].minor.yy255);
}
#line 1992 "./snl.c"
        break;
      case 133: /* transition ::= WHEN LPAREN condition RPAREN block error */
#line 355 "../snl.lem"
{
	yymsp[-5].minor.yy0.str = 0;
	yygotominor.yy255 = node(D_WHEN, yymsp[-5].minor.yy0, yymsp[-3].minor.yy255, yymsp[-1].minor.yy255);
	report("expected 'state' or 'exit'\n");
}
#line 2001 "./snl.c"
        break;
      case 135: /* block ::= LBRACE block_defns statements RBRACE */
#line 363 "../snl.lem"
{
	yygotominor.yy255 = node(S_CMPND, yymsp[-3].minor.yy0, yymsp[-2].minor.yy255, yymsp[-1].minor.yy255);
}
#line 2008 "./snl.c"
        break;
      case 142: /* statement ::= BREAK SEMICOLON */
      case 143: /* statement ::= CONTINUE SEMICOLON */ yytestcase(yyruleno==143);
#line 380 "../snl.lem"
{ yygotominor.yy255 = node(S_JUMP, yymsp[-1].minor.yy0); }
#line 2014 "./snl.c"
        break;
      case 144: /* statement ::= RETURN opt_expr SEMICOLON */
#line 383 "../snl.lem"
{ yygotominor.yy255 = node(S_RETURN, yymsp[-2].minor.yy0, yymsp[-1].minor.yy255); }
#line 2019 "./snl.c"
        break;
      case 145: /* statement ::= STATE NAME SEMICOLON */
#line 384 "../snl.lem"
{ yygotominor.yy255 = node(S_CHANGE, yymsp[-1].minor.yy0); }
#line 2024 "./snl.c"
        break;
      case 148: /* statement ::= IF LPAREN comma_expr RPAREN statement */
#line 388 "../snl.lem"
{ yygotominor.yy255 = node(S_IF, yymsp[-4].minor.yy0, yymsp[-2].minor.yy255, yymsp[0].minor.yy255, NIL); }
#line 2029 "./snl.c"
        break;
      case 149: /* statement ::= IF LPAREN comma_expr RPAREN statement ELSE statement */
#line 390 "../snl.lem"
{ yygotominor.yy255 = node(S_IF, yymsp[-6].minor.yy0, yymsp[-4].minor.yy255, yymsp[-2].minor.yy255, yymsp[0].minor.yy255); }
#line 2034 "./snl.c"
        break;
      case 150: /* statement ::= WHILE LPAREN comma_expr RPAREN statement */
#line 392 "../snl.lem"
{ yygotominor.yy255 = node(S_WHILE, yymsp[-4].minor.yy0, yymsp[-2].minor.yy255, yymsp[0].minor.yy255); }
#line 2039 "./snl.c"
        break;
      case 152: /* statement ::= opt_expr SEMICOLON */
#line 394 "../snl.lem"
{ yygotominor.yy255 = node(S_STMT, yymsp[0].minor.yy0, yymsp[-1].minor.yy255); }
#line 2044 "./snl.c"
        break;
      case 153: /* for_statement ::= FOR LPAREN opt_expr SEMICOLON opt_expr SEMICOLON opt_expr RPAREN statement */
#line 400 "../snl.lem"
{ yygotominor.yy255 = node(S_FOR, yymsp[-8].minor.yy0, yymsp[-6].minor.yy255, yymsp[-4].minor.yy255, yymsp[-2].minor.yy255, yymsp[0].minor.yy255); }
#line 2049 "./snl.c"
        break;
      case 158: /* expr ::= LPAREN comma_expr RPAREN */
#line 415 "../snl.lem"
{ yygotominor.yy255 = node(E_PAREN,  yymsp[-2].minor.yy0, yymsp[-1].minor.yy255); }
#line 2054 "./snl.c"
        break;
      case 159: /* expr ::= expr LPAREN args RPAREN */
#line 416 "../snl.lem"
{ yygotominor.yy255 = node(E_FUNC,   yymsp[-2].minor.yy0, yymsp[-3].minor.yy255, yymsp[-1].minor.yy255); }
#line 2059 "./snl.c"
        break;
      case 160: /* expr ::= EXIT LPAREN args RPAREN */
      case 161: /* expr ::= SIZEOF LPAREN type_expr RPAREN */ yytestcase(yyruleno==161);
#line 417 "../snl.lem"
{ yygotominor.yy255 = node(E_FUNC,   yymsp[-2].minor.yy0, node(E_VAR, yymsp[-3].minor.yy0), yymsp[-1].minor.yy255); }
#line 2065 "./snl.c"
        break;
      case 162: /* expr ::= expr LBRACKET expr RBRACKET */
#line 419 "../snl.lem"
{ yygotominor.yy255 = node(E_SUBSCR, yymsp[-2].minor.yy0, yymsp[-3].minor.yy255, yymsp[-1].minor.yy255); }
#line 2070 "./snl.c"
        break;
      case 163: /* expr ::= expr PERIOD member */
      case 164: /* expr ::= expr POINTER member */ yytestcase(yyruleno==164);
#line 420 "../snl.lem"
{ yygotominor.yy255 = node(E_SELECT, yymsp[-1].minor.yy0, yymsp[-2].minor.yy255, yymsp[0].minor.yy255); }
#line 2076 "./snl.c"
        break;
      case 165: /* expr ::= expr INCR */
      case 166: /* expr ::= expr DECR */ yytestcase(yyruleno==166);
#line 422 "../snl.lem"
{ yygotominor.yy255 = node(E_POST,   yymsp[0].minor.yy0, yymsp[-1].minor.yy255); }
#line 2082 "./snl.c"
        break;
      case 175: /* expr ::= SIZEOF expr */
#line 434 "../snl.lem"
{ yygotominor.yy255 = node(E_FUNC, yymsp[-1].minor.yy0, node(E_VAR, yymsp[-1].minor.yy0), yymsp[0].minor.yy255); }
#line 2087 "./snl.c"
        break;
      case 176: /* expr ::= LPAREN type_expr RPAREN expr */
#line 437 "../snl.lem"
{ yygotominor.yy255 = node(E_CAST, yymsp[-3].minor.yy0, yymsp[-2].minor.yy255, yymsp[0].minor.yy255); }
#line 2092 "./snl.c"
        break;
      case 195: /* expr ::= expr QUESTION expr COLON expr */
#line 461 "../snl.lem"
{ yygotominor.yy255 = node(E_TERNOP, yymsp[-3].minor.yy0, yymsp[-4].minor.yy255, yymsp[-2].minor.yy255, yymsp[0].minor.yy255); }
#line 2097 "./snl.c"
        break;
      case 214: /* string ::= STRCON */
#line 489 "../snl.lem"
{ yygotominor.yy255 = node(E_STRING, yymsp[0].minor.yy0); }
#line 2102 "./snl.c"
        break;
      case 215: /* member ::= NAME */
#line 491 "../snl.lem"
{ yygotominor.yy255 = node(E_MEMBER, yymsp[0].minor.yy0); }
#line 2107 "./snl.c"
        break;
      case 216: /* funcdef ::= basetype declarator block */
#line 495 "../snl.lem"
{
	yygotominor.yy255 = node(D_FUNCDEF, yymsp[-1].minor.yy255->token, mk_decl(yymsp[-1].minor.yy255, yymsp[-2].minor.yy149), yymsp[0].minor.yy255);
}
#line 2114 "./snl.c"
        break;
      case 217: /* structdef ::= STRUCT NAME members SEMICOLON */
#line 501 "../snl.lem"
{ yygotominor.yy255 = node(D_STRUCTDEF, yymsp[-2].minor.yy0, yymsp[-1].minor.yy255); }
#line 2119 "./snl.c"
        break;
      case 221: /* member_decl ::= basetype declarator SEMICOLON */
#line 508 "../snl.lem"
{ yygotominor.yy255 = mk_decl(yymsp[-1].minor.yy255, yymsp[-2].minor.yy149); }
#line 2124 "./snl.c"
        break;
      case 223: /* c_code ::= CCODE */
#line 513 "../snl.lem"
{ yygotominor.yy255 = node(T_TEXT, yymsp[0].minor.yy0); }
#line 2129 "./snl.c"
        break;
      default:
      /* (23) to ::= TO */ yytestcase(yyruleno==23);
      /* (24) to ::= */ yytestcase(yyruleno==24);
        break;
  };
  yygoto = yyRuleInfo[yyruleno].lhs;
  yysize = yyRuleInfo[yyruleno].nrhs;
  yypParser->yyidx -= yysize;
  yyact = yy_find_reduce_action(yymsp[-yysize].stateno,(YYCODETYPE)yygoto);
  if( yyact < YYNSTATE ){
#ifdef NDEBUG
    /* If we are not debugging and the reduce action popped at least
    ** one element off the stack, then we can push the new element back
    ** onto the stack here, and skip the stack overflow test in yy_shift().
    ** That gives a significant speed improvement. */
    if( yysize ){
      yypParser->yyidx++;
      yymsp -= yysize-1;
      yymsp->stateno = (YYACTIONTYPE)yyact;
      yymsp->major = (YYCODETYPE)yygoto;
      yymsp->minor = yygotominor;
    }else
#endif
    {
      yy_shift(yypParser,yyact,yygoto,&yygotominor);
    }
  }else{
    assert( yyact == YYNSTATE + YYNRULE + 1 );
    yy_accept(yypParser);
  }
}

/*
** The following code executes when the parse fails
*/
#ifndef YYNOERRORRECOVERY
static void yy_parse_failed(
  yyParser *yypParser           /* The parser */
){
  snlParserARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sFail!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser fails */
#line 29 "../snl.lem"

	report("parser giving up\n");
	exit(1);
#line 2183 "./snl.c"
  snlParserARG_STORE; /* Suppress warning about unused %extra_argument variable */
}
#endif /* YYNOERRORRECOVERY */

/*
** The following code executes when a syntax error first occurs.
*/
static void yy_syntax_error(
  yyParser *yypParser,           /* The parser */
  int yymajor,                   /* The major type of the error token */
  YYMINORTYPE yyminor            /* The minor type of the error token */
){
  snlParserARG_FETCH;
#define TOKEN (yyminor.yy0)
#line 34 "../snl.lem"

	error_at(TOKEN.file, TOKEN.line,
		"syntax error near token '%s'\n", TOKEN.str);
	report_loc(TOKEN.file, TOKEN.line);
#line 2203 "./snl.c"
  snlParserARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/*
** The following is executed when the parser accepts
*/
static void yy_accept(
  yyParser *yypParser           /* The parser */
){
  snlParserARG_FETCH;
#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sAccept!\n",yyTracePrompt);
  }
#endif
  while( yypParser->yyidx>=0 ) yy_pop_parser_stack(yypParser);
  /* Here code is inserted which will be executed whenever the
  ** parser accepts */
  snlParserARG_STORE; /* Suppress warning about unused %extra_argument variable */
}

/* The main parser program.
** The first argument is a pointer to a structure obtained from
** "snlParserAlloc" which describes the current state of the parser.
** The second argument is the major token number.  The third is
** the minor token.  The fourth optional argument is whatever the
** user wants (and specified in the grammar) and is available for
** use by the action routines.
**
** Inputs:
** <ul>
** <li> A pointer to the parser (an opaque structure.)
** <li> The major token number.
** <li> The minor token number.
** <li> An option argument of a grammar-specified type.
** </ul>
**
** Outputs:
** None.
*/
void snlParser(
  void *yyp,                   /* The parser */
  int yymajor,                 /* The major token code number */
  snlParserTOKENTYPE yyminor       /* The value for the token */
  snlParserARG_PDECL               /* Optional %extra_argument parameter */
){
  YYMINORTYPE yyminorunion;
  int yyact;            /* The parser action. */
  int yyendofinput;     /* True if we are at the end of input */
#ifdef YYERRORSYMBOL
  int yyerrorhit = 0;   /* True if yymajor has invoked an error */
#endif
  yyParser *yypParser;  /* The parser */

  /* (re)initialize the parser, if necessary */
  yypParser = (yyParser*)yyp;
  if( yypParser->yyidx<0 ){
#if YYSTACKDEPTH<=0
    if( yypParser->yystksz <=0 ){
      /*memset(&yyminorunion, 0, sizeof(yyminorunion));*/
      yyminorunion = yyzerominor;
      yyStackOverflow(yypParser, &yyminorunion);
      return;
    }
#endif
    yypParser->yyidx = 0;
    yypParser->yyerrcnt = -1;
    yypParser->yystack[0].stateno = 0;
    yypParser->yystack[0].major = 0;
  }
  yyminorunion.yy0 = yyminor;
  yyendofinput = (yymajor==0);
  snlParserARG_STORE;

#ifndef NDEBUG
  if( yyTraceFILE ){
    fprintf(yyTraceFILE,"%sInput %s\n",yyTracePrompt,yyTokenName[yymajor]);
  }
#endif

  do{
    yyact = yy_find_shift_action(yypParser,(YYCODETYPE)yymajor);
    if( yyact<YYNSTATE ){
      assert( !yyendofinput );  /* Impossible to shift the $ token */
      yy_shift(yypParser,yyact,yymajor,&yyminorunion);
      yypParser->yyerrcnt--;
      yymajor = YYNOCODE;
    }else if( yyact < YYNSTATE + YYNRULE ){
      yy_reduce(yypParser,yyact-YYNSTATE);
    }else{
#ifdef YYERRORSYMBOL
      int yymx;
#endif
      assert( yyact == YY_ERROR_ACTION );
#ifndef NDEBUG
      if( yyTraceFILE ){
        fprintf(yyTraceFILE,"%sSyntax Error!\n",yyTracePrompt);
      }
#endif
#ifdef YYERRORSYMBOL
      /* A syntax error has occurred.
      ** The response to an error depends upon whether or not the
      ** grammar defines an error token "ERROR".  
      **
      ** This is what we do if the grammar does define ERROR:
      **
      **  * Call the %syntax_error function.
      **
      **  * Begin popping the stack until we enter a state where
      **    it is legal to shift the error symbol, then shift
      **    the error symbol.
      **
      **  * Set the error count to three.
      **
      **  * Begin accepting and shifting new tokens.  No new error
      **    processing will occur until three tokens have been
      **    shifted successfully.
      **
      */
      if( yypParser->yyerrcnt<0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yymx = yypParser->yystack[yypParser->yyidx].major;
      if( yymx==YYERRORSYMBOL || yyerrorhit ){
#ifndef NDEBUG
        if( yyTraceFILE ){
          fprintf(yyTraceFILE,"%sDiscard input token %s\n",
             yyTracePrompt,yyTokenName[yymajor]);
        }
#endif
        yy_destructor(yypParser, (YYCODETYPE)yymajor,&yyminorunion);
        yymajor = YYNOCODE;
      }else{
         while(
          yypParser->yyidx >= 0 &&
          yymx != YYERRORSYMBOL &&
          (yyact = yy_find_reduce_action(
                        yypParser->yystack[yypParser->yyidx].stateno,
                        YYERRORSYMBOL)) >= YYNSTATE
        ){
          yy_pop_parser_stack(yypParser);
        }
        if( yypParser->yyidx < 0 || yymajor==0 ){
          yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
          yy_parse_failed(yypParser);
          yymajor = YYNOCODE;
        }else if( yymx!=YYERRORSYMBOL ){
          YYMINORTYPE u2;
          u2.YYERRSYMDT = 0;
          yy_shift(yypParser,yyact,YYERRORSYMBOL,&u2);
        }
      }
      yypParser->yyerrcnt = 3;
      yyerrorhit = 1;
#elif defined(YYNOERRORRECOVERY)
      /* If the YYNOERRORRECOVERY macro is defined, then do not attempt to
      ** do any kind of error recovery.  Instead, simply invoke the syntax
      ** error routine and continue going as if nothing had happened.
      **
      ** Applications can set this macro (for example inside %include) if
      ** they intend to abandon the parse upon the first syntax error seen.
      */
      yy_syntax_error(yypParser,yymajor,yyminorunion);
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      yymajor = YYNOCODE;
      
#else  /* YYERRORSYMBOL is not defined */
      /* This is what we do if the grammar does not define ERROR:
      **
      **  * Report an error message, and throw away the input token.
      **
      **  * If the input token is $, then fail the parse.
      **
      ** As before, subsequent error messages are suppressed until
      ** three input tokens have been successfully shifted.
      */
      if( yypParser->yyerrcnt<=0 ){
        yy_syntax_error(yypParser,yymajor,yyminorunion);
      }
      yypParser->yyerrcnt = 3;
      yy_destructor(yypParser,(YYCODETYPE)yymajor,&yyminorunion);
      if( yyendofinput ){
        yy_parse_failed(yypParser);
      }
      yymajor = YYNOCODE;
#endif
    }
  }while( yymajor!=YYNOCODE && yypParser->yyidx>=0 );
  return;
}
