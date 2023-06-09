/*
@Copyright Looking Glass Studios, Inc.
1996,1997,1998,1999,2000 Unpublished Work.
*/

/* n:\bin\lex -l -o r:\prj\cam\src\win32\linklex.c r:\prj\cam\src\linklex.lex */
#define YYNEWLINE 10
#define INITIAL 0
#define yy_endst 37
#define yy_nxtmax 247
#define YY_LA_SIZE 5

static unsigned short yy_la_act[] = {
 1, 0, 1, 2, 3, 4, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8,
 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 6, 8, 6, 8, 8, 8,
 8, 8, 8, 8, 8, 8, 5, 8, 5, 8,
};

static unsigned char yy_look[] = {
 0
};

static short yy_final[] = {
 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
 16, 18, 19, 20, 21, 22, 23, 24, 25, 26, 28, 30, 31, 32, 33, 34,
 35, 36, 37, 38, 40, 42
};
#ifndef yy_state_t
#define yy_state_t unsigned char
#endif

static yy_state_t yy_begin[] = {
 0, 0, 0
};

static yy_state_t yy_next[] = {
 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 1, 37, 37, 37, 37, 37,
 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37, 37,
 1, 37, 37, 37, 37, 37, 37, 37, 37, 37, 4, 37, 37, 37, 37, 37,
 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 37, 3, 37, 37, 37, 37,
 37, 11, 11, 11, 6, 11, 8, 11, 11, 11, 11, 11, 11, 11, 11, 11,
 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 37, 37, 37, 37, 37,
 37, 11, 11, 11, 7, 11, 9, 11, 11, 11, 11, 11, 11, 11, 11, 11,
 11, 10, 11, 11, 11, 11, 11, 11, 11, 11, 11, 13, 14, 15, 5, 12,
 12, 12, 12, 12, 12, 12, 12, 12, 12, 16, 17, 19, 21, 23, 25, 25,
 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 18, 20, 22, 24, 26, 26,
 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 12,
 12, 12, 12, 12, 12, 12, 12, 12, 12, 12, 23, 21, 19, 17, 27, 29,
 31, 33, 35, 35, 33, 31, 29, 27, 2, 2, 2, 2, 2, 2, 2, 2,
 2, 2, 37, 37, 37, 37, 37, 37, 37, 37, 24, 22, 20, 18, 28, 30,
 32, 34, 36, 36, 34, 32, 30, 28,
};

static yy_state_t yy_check[] = {
 ~0, ~0, ~0, ~0, ~0, ~0, ~0, ~0, ~0, ~0, 0, ~0, ~0, ~0, ~0, ~0,
 ~0, ~0, ~0, ~0, ~0, ~0, ~0, ~0, ~0, ~0, ~0, ~0, ~0, ~0, ~0, ~0,
 0, ~0, ~0, ~0, ~0, ~0, ~0, ~0, ~0, ~0, 0, ~0, ~0, ~0, ~0, ~0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ~0, 0, ~0, ~0, ~0, ~0,
 ~0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, ~0, ~0, ~0, ~0, ~0,
 ~0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 10, 13, 14, 0, 11,
 11, 11, 11, 11, 11, 11, 11, 11, 11, 15, 9, 18, 20, 22, 24, 23,
 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 9, 18, 20, 22, 24, 23,
 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 21, 19, 17, 8, 7, 28,
 30, 32, 34, 33, 31, 29, 27, 6, 2, 2, 2, 2, 2, 2, 2, 2,
 2, 2, ~0, ~0, ~0, ~0, ~0, ~0, ~0, ~0, 21, 19, 17, 8, 7, 28,
 30, 32, 34, 33, 31, 29, 27, 6,
};

static yy_state_t yy_default[] = {
 37, 37, 37, 37, 37, 37, 11, 11, 11, 11, 11, 37, 11, 11, 11, 11,
 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11, 11,
 11, 11, 11, 11, 11,
};

static short yy_base[] = {
 0, 248, 168, 248, 248, 248, 146, 137, 129, 62, 6, 79, 248, 23, 11, 16,
 248, 139, 74, 117, 54, 123, 62, 61, 60, 248, 248, 138, 131, 144, 139, 128,
 125, 142, 141, 248, 248, 248
};


/*
 * Copyright 1988, 1990 by Mortice Kern Systems Inc.  All rights reserved.
 * All rights reserved.
 */
#include <stdlib.h>
#include <stdio.h>
/*
 * Define gettext() to an appropriate function for internationalized messages
 * or custom processing.
 */
#if	__STDC__
#define YY_ARGS(args)	args
#else
#define YY_ARGS(args)	()
#endif

#ifndef I18N
#define gettext(s)	(s)
#endif
/*
 * Include string.h to get definition of memmove() and size_t.
 * If you do not have string.h or it does not declare memmove
 * or size_t, you will have to declare them here.
 */
#include <string.h>
/* Uncomment next line if memmove() is not declared in string.h */
/*extern char * memmove();*/
/* Uncomment next line if size_t is not available in stdio.h or string.h */
/*typedef unsigned size_t;*/
/* Drop this when LATTICE provides memmove */
#ifdef LATTICE
#define memmove	memcopy
#endif

/*
 * YY_STATIC determines the scope of variables and functions
 * declared by the lex scanner. It must be set with a -DYY_STATIC
 * option to the compiler (it cannot be defined in the lex program).
 */
#ifdef	YY_STATIC
/* define all variables as static to allow more than one lex scanner */
#define	YY_DECL	static
#else
/* define all variables as global to allow other modules to access them */
#define	YY_DECL	
#endif

/*
 * You can redefine yygetc. For YACC Tracing, compile this code
 * with -DYYTRACE to get input from yt_getc
 */
#ifdef YYTRACE
extern int	yt_getc YY_ARGS((void));
#define yygetc()	yt_getc()
#else
#define	yygetc()	getc(yyin) 	/* yylex input source */
#endif

/*
 * the following can be redefined by the user.
 */
#define	ECHO		fputs(yytext, yyout)
#define	output(c)	putc((c), yyout) /* yylex sink for unmatched chars */
#define	YY_FATAL(msg)	{ fprintf(stderr, "yylex: %s\n", msg); exit(1); }
#define	YY_INTERACTIVE	1		/* save micro-seconds if 0 */
#define	YYLMAX		100		/* token and pushback buffer size */

/*
 * the following must not be redefined.
 */
#define	yy_tbuf	yytext		/* token string */

#define	BEGIN		yy_start =
#define	REJECT		goto yy_reject
#define	NLSTATE		(yy_lastc = YYNEWLINE)
#define	YY_INIT \
	(yy_start = yyleng = yy_end = 0, yy_lastc = YYNEWLINE)
#define	yymore()	goto yy_more
#define	yyless(n)	if ((n) < 0 || (n) > yy_end) ; \
			else { YY_SCANNER; yyleng = (n); YY_USER; }

YY_DECL	void	yy_reset YY_ARGS((void));
YY_DECL	int	input	YY_ARGS((void));
YY_DECL	int	unput	YY_ARGS((int c));

/* functions defined in libl.lib */
extern	int	yywrap	YY_ARGS((void));
extern	void	yyerror	YY_ARGS((char *fmt, ...));
extern	void	yycomment	YY_ARGS((char *term));
extern	int	yymapch	YY_ARGS((int delim, int escape));


#include <lg.h>
#include <stdlib.h>
#include <string.h>
#include <linktok.h>
#include <memall.h>
#include <dbmem.h>   // must be last header! 
char identbuffer[2048];
char* nextident = identbuffer;



#ifdef	YY_DEBUG
#undef	YY_DEBUG
#define	YY_DEBUG(fmt, a1, a2)	fprintf(stderr, fmt, a1, a2)
#else
#define	YY_DEBUG(fmt, a1, a2)
#endif

/*
 * The declaration for the lex scanner can be changed by
 * redefining YYLEX or YYDECL. This must be done if you have
 * more than one scanner in a program.
 */
#ifndef	YYLEX
#define	YYLEX yylex			/* name of lex scanner */
#endif

#ifndef YYDECL
#define	YYDECL	int YYLEX YY_ARGS((void))	/* declaration for lex scanner */
#endif

/* stdin and stdout may not neccessarily be constants */
YY_DECL	FILE   *yyin = stdin;
YY_DECL	FILE   *yyout = stdout;
YY_DECL	int	yylineno = 1;		/* line number */

/*
 * yy_tbuf is an alias for yytext.
 * yy_sbuf[0:yyleng-1] contains the states corresponding to yy_tbuf.
 * yy_tbuf[0:yyleng-1] contains the current token.
 * yy_tbuf[yyleng:yy_end-1] contains pushed-back characters.
 * When the user action routine is active,
 * yy_save contains yy_tbuf[yyleng], which is set to '\0'.
 * Things are different when YY_PRESERVE is defined. 
 */

YY_DECL	char yy_tbuf [YYLMAX+1]; /* text buffer (really yytext) */
static	yy_state_t yy_sbuf [YYLMAX+1];	/* state buffer */

static	int	yy_end = 0;		/* end of pushback */
static	int	yy_start = 0;		/* start state */
static	int	yy_lastc = YYNEWLINE;	/* previous char */
YY_DECL	int	yyleng = 0;		/* yytext token length */

#ifndef YY_PRESERVE	/* the efficient default push-back scheme */

static	char yy_save;	/* saved yytext[yyleng] */

#define	YY_USER	{ /* set up yytext for user */ \
		yy_save = yytext[yyleng]; \
		yytext[yyleng] = 0; \
	}
#define	YY_SCANNER { /* set up yytext for scanner */ \
		yytext[yyleng] = yy_save; \
	}

#else		/* not-so efficient push-back for yytext mungers */

static	char yy_save [YYLMAX];
static	char *yy_push = yy_save+YYLMAX;

#define	YY_USER { \
		size_t n = yy_end - yyleng; \
		yy_push = yy_save+YYLMAX - n; \
		if (n > 0) \
			memmove(yy_push, yytext+yyleng, n); \
		yytext[yyleng] = 0; \
	}
#define	YY_SCANNER { \
		size_t n = yy_save+YYLMAX - yy_push; \
		if (n > 0) \
			memmove(yytext+yyleng, yy_push, n); \
		yy_end = yyleng + n; \
	}

#endif

/*
 * The actual lex scanner (usually yylex(void)).
 * NOTE: you should invoke yy_init() if you are calling yylex()
 * with new input; otherwise old lookaside will get in your way
 * and yylex() will die horribly.
 */
YYDECL {
	register int c, i, yyst, yybase;
	int yyfmin, yyfmax;	/* yy_la_act indices of final states */
	int yyoldi, yyoleng;	/* base i, yyleng before look-ahead */
	int yyeof;		/* 1 if eof has already been read */



	yyeof = 0;
	i = yyleng;
	YY_SCANNER;

  yy_again:
	yyleng = i;
	/* determine previous char. */
	if (i > 0)
		yy_lastc = yytext[i-1];
	/* scan previously accepted token adjusting yylineno */
	while (i > 0)
		if (yytext[--i] == YYNEWLINE)
			yylineno++;
	/* adjust pushback */
	yy_end -= yyleng;
	memmove(yytext, yytext+yyleng, (size_t) yy_end);
	i = 0;

  yy_contin:
	yyoldi = i;

	/* run the state machine until it jams */
	yy_sbuf[i] = yyst = yy_begin[yy_start + (yy_lastc == YYNEWLINE)];
	do {
		YY_DEBUG(gettext("<state %d, i = %d>\n"), yyst, i);
		if (i >= YYLMAX)
			YY_FATAL(gettext("Token buffer overflow"));

		/* get input char */
		if (i < yy_end)
			c = yy_tbuf[i];		/* get pushback char */
		else if (!yyeof && (c = yygetc()) != EOF) {
			yy_end = i+1;
			yy_tbuf[i] = c;
		} else /* c == EOF */ {
			c = EOF;		/* just to make sure... */
			if (i == yyoldi) {	/* no token */
				yyeof = 0;
				if (yywrap())
					return 0;
				else
					goto yy_again;
			} else {
				yyeof = 1;	/* don't re-read EOF */
				break;
			}
		}
		YY_DEBUG(gettext("<input %d = 0x%02x>\n"), c, c);

		/* look up next state */
		while ((yybase = yy_base[yyst]+c) > yy_nxtmax || yy_check[yybase] != yyst) {
			if (yyst == yy_endst)
				goto yy_jammed;
			yyst = yy_default[yyst];
		}
		yyst = yy_next[yybase];
	  yy_jammed: ;
	  yy_sbuf[++i] = yyst;
	} while (!(yyst == yy_endst || YY_INTERACTIVE && yy_base[yyst] > yy_nxtmax && yy_default[yyst] == yy_endst));
	YY_DEBUG(gettext("<stopped %d, i = %d>\n"), yyst, i);
	if (yyst != yy_endst)
		++i;

  yy_search:
	/* search backward for a final state */
	while (--i > yyoldi) {
		yyst = yy_sbuf[i];
		if ((yyfmin = yy_final[yyst]) < (yyfmax = yy_final[yyst+1]))
			goto yy_found;	/* found final state(s) */
	}
	/* no match, default action */
	i = yyoldi + 1;
	output(yy_tbuf[yyoldi]);
	goto yy_again;

  yy_found:
	YY_DEBUG(gettext("<final state %d, i = %d>\n"), yyst, i);
	yyoleng = i;		/* save length for REJECT */
	
	/* pushback look-ahead RHS */
	if ((c = (int)(yy_la_act[yyfmin]>>9) - 1) >= 0) { /* trailing context? */
		unsigned char *bv = yy_look + c*YY_LA_SIZE;
		static unsigned char bits [8] = {
			1<<0, 1<<1, 1<<2, 1<<3, 1<<4, 1<<5, 1<<6, 1<<7
		};
		while (1) {
			if (--i < yyoldi) {	/* no / */
				i = yyoleng;
				break;
			}
			yyst = yy_sbuf[i];
			if (bv[(unsigned)yyst/8] & bits[(unsigned)yyst%8])
				break;
		}
	}

	/* perform action */
	yyleng = i;
	YY_USER;
	switch (yy_la_act[yyfmin] & 0777) {
	case 0:
	{}
	break;
	case 1:
	{ yylval = atoi(yytext); return(INTLIT);} 
	break;
	case 2:
	{  nextident = identbuffer;  return(SEMI); }        
	break;
	case 3:
	{ return(STAR); }
	break;
	case 4:
	{ return(NOT); }
	break;
	case 5:
	{ return(DELETE);}
	break;
	case 6:
	{return(FLAVOR);}
	break;
	case 7:
	{return(QUERY); } 
	break;
	case 8:
	{ 
                         strcpy(nextident,yytext);
                         yylval = (int)nextident;
                         nextident += strlen(nextident)+1;
                         return(IDENT); 
                       } 
	break;


	}
	YY_SCANNER;
	i = yyleng;
	goto yy_again;			/* action fell though */

  yy_reject:
	YY_SCANNER;
	i = yyoleng;			/* restore original yytext */
	if (++yyfmin < yyfmax)
		goto yy_found;		/* another final state, same length */
	else
		goto yy_search;		/* try shorter yytext */

  yy_more:
	YY_SCANNER;
	i = yyleng;
	if (i > 0)
		yy_lastc = yytext[i-1];
	goto yy_contin;
}
/*
 * Safely switch input stream underneath LEX
 */
typedef struct yy_save_block_tag {
	FILE	* oldfp;
	int	oldline;
	int	oldend;
	int	oldstart;
	int	oldlastc;
	int	oldleng;
	char	savetext[YYLMAX+1];
	yy_state_t	savestate[YYLMAX+1];
} YY_SAVED;

YY_SAVED *
yySaveScan(fp)
FILE * fp;
{
	YY_SAVED * p;

	if ((p = (YY_SAVED *) malloc(sizeof(*p))) == NULL)
		return p;

	p->oldfp = yyin;
	p->oldline = yylineno;
	p->oldend = yy_end;
	p->oldstart = yy_start;
	p->oldlastc = yy_lastc;
	p->oldleng = yyleng;
	(void) memcpy(p->savetext, yytext, sizeof yytext);
	(void) memcpy((char *) p->savestate, (char *) yy_sbuf,
		sizeof yy_sbuf);

	yyin = fp;
	yylineno = 1;
	YY_INIT;

	return p;
}
/*f
 * Restore previous LEX state
 */
void
yyRestoreScan(p)
YY_SAVED * p;
{
	if (p == NULL)
		return;
	yyin = p->oldfp;
	yylineno = p->oldline;
	yy_end = p->oldend;
	yy_start = p->oldstart;
	yy_lastc = p->oldlastc;
	yyleng = p->oldleng;

	(void) memcpy(yytext, p->savetext, sizeof yytext);
	(void) memcpy((char *) yy_sbuf, (char *) p->savestate,
		sizeof yy_sbuf);
	free(p);
}
/*
 * User-callable re-initialization of yylex()
 */
void
yy_reset()
{
	YY_INIT;
	yylineno = 1;		/* line number */
}
/* get input char with pushback */
YY_DECL int
input()
{
	int c;
#ifndef YY_PRESERVE
	if (yy_end > yyleng) {
		yy_end--;
		memmove(yytext+yyleng, yytext+yyleng+1,
			(size_t) (yy_end-yyleng));
		c = yy_save;
		YY_USER;
#else
	if (yy_push < yy_save+YYLMAX) {
		c = *yy_push++;
#endif
	} else
		c = yygetc();
	yy_lastc = c;
	if (c == YYNEWLINE)
		yylineno++;
	return c;
}

/*f
 * pushback char
 */
YY_DECL int
unput(c)
	int c;
{
#ifndef YY_PRESERVE
	if (yy_end >= YYLMAX)
		YY_FATAL(gettext("Push-back buffer overflow"));
	if (yy_end > yyleng) {
		yytext[yyleng] = yy_save;
		memmove(yytext+yyleng+1, yytext+yyleng,
			(size_t) (yy_end-yyleng));
		yytext[yyleng] = 0;
	}
	yy_end++;
	yy_save = c;
#else
	if (yy_push <= yy_save)
		YY_FATAL(gettext("Push-back buffer overflow"));
	*--yy_push = c;
#endif
	if (c == YYNEWLINE)
		yylineno--;
	return c;
}


int yywrap(void) { return 1;} 

