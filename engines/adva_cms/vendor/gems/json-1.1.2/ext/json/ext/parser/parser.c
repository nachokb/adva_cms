#line 1 "parser.rl"
/* vim: set cin et sw=4 ts=4: */

#include "ruby.h"
#include "re.h"
#include "st.h"
#include "unicode.h"

#define EVIL 0x666

static VALUE mJSON, mExt, cParser, eParserError, eNestingError;
static VALUE CNaN, CInfinity, CMinusInfinity;

static ID i_json_creatable_p, i_json_create, i_create_id, i_create_additions,
          i_chr, i_max_nesting, i_allow_nan; 

#define MinusInfinity "-Infinity"

typedef struct JSON_ParserStruct {
    VALUE Vsource;
    char *source;
    long len;
    char *memo;
    VALUE create_id;
    int max_nesting;
    int current_nesting;
    int allow_nan;
} JSON_Parser;

static char *JSON_parse_object(JSON_Parser *json, char *p, char *pe, VALUE *result);
static char *JSON_parse_array(JSON_Parser *json, char *p, char *pe, VALUE *result);
static char *JSON_parse_value(JSON_Parser *json, char *p, char *pe, VALUE *result);
static char *JSON_parse_string(JSON_Parser *json, char *p, char *pe, VALUE *result);
static char *JSON_parse_integer(JSON_Parser *json, char *p, char *pe, VALUE *result);
static char *JSON_parse_float(JSON_Parser *json, char *p, char *pe, VALUE *result);

#define GET_STRUCT                          \
    JSON_Parser *json;                      \
    Data_Get_Struct(self, JSON_Parser, json);

#line 66 "parser.rl"



#line 46 "parser.c"
static const int JSON_object_start = 1;
static const int JSON_object_first_final = 27;
static const int JSON_object_error = 0;

static const int JSON_object_en_main = 1;

#line 99 "parser.rl"


static char *JSON_parse_object(JSON_Parser *json, char *p, char *pe, VALUE *result)
{
    int cs = EVIL;
    VALUE last_name = Qnil;

    if (json->max_nesting && json->current_nesting > json->max_nesting) {
        rb_raise(eNestingError, "nesting of %d is to deep", json->current_nesting);
    }

    *result = rb_hash_new();

    
#line 68 "parser.c"
	{
	cs = JSON_object_start;
	}
#line 113 "parser.rl"
    
#line 74 "parser.c"
	{
	if ( p == pe )
		goto _out;
	switch ( cs )
	{
case 1:
	if ( (*p) == 123 )
		goto st2;
	goto st0;
st0:
	goto _out0;
st2:
	if ( ++p == pe )
		goto _out2;
case 2:
	switch( (*p) ) {
		case 13: goto st2;
		case 32: goto st2;
		case 34: goto tr2;
		case 47: goto st23;
		case 125: goto tr4;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st2;
	goto st0;
tr2:
#line 85 "parser.rl"
	{
        char *np = JSON_parse_string(json, p, pe, &last_name);
        if (np == NULL) goto _out3; else {p = (( np))-1;}
    }
	goto st3;
st3:
	if ( ++p == pe )
		goto _out3;
case 3:
#line 111 "parser.c"
	switch( (*p) ) {
		case 13: goto st3;
		case 32: goto st3;
		case 47: goto st4;
		case 58: goto st8;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st3;
	goto st0;
st4:
	if ( ++p == pe )
		goto _out4;
case 4:
	switch( (*p) ) {
		case 42: goto st5;
		case 47: goto st7;
	}
	goto st0;
st5:
	if ( ++p == pe )
		goto _out5;
case 5:
	if ( (*p) == 42 )
		goto st6;
	goto st5;
st6:
	if ( ++p == pe )
		goto _out6;
case 6:
	switch( (*p) ) {
		case 42: goto st6;
		case 47: goto st3;
	}
	goto st5;
st7:
	if ( ++p == pe )
		goto _out7;
case 7:
	if ( (*p) == 10 )
		goto st3;
	goto st7;
st8:
	if ( ++p == pe )
		goto _out8;
case 8:
	switch( (*p) ) {
		case 13: goto st8;
		case 32: goto st8;
		case 34: goto tr11;
		case 45: goto tr11;
		case 47: goto st19;
		case 73: goto tr11;
		case 78: goto tr11;
		case 91: goto tr11;
		case 102: goto tr11;
		case 110: goto tr11;
		case 116: goto tr11;
		case 123: goto tr11;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr11;
	} else if ( (*p) >= 9 )
		goto st8;
	goto st0;
tr11:
#line 74 "parser.rl"
	{
        VALUE v = Qnil;
        char *np = JSON_parse_value(json, p, pe, &v); 
        if (np == NULL) {
            goto _out9;
        } else {
            rb_hash_aset(*result, last_name, v);
            {p = (( np))-1;}
        }
    }
	goto st9;
st9:
	if ( ++p == pe )
		goto _out9;
case 9:
#line 194 "parser.c"
	switch( (*p) ) {
		case 13: goto st9;
		case 32: goto st9;
		case 44: goto st10;
		case 47: goto st15;
		case 125: goto tr4;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st9;
	goto st0;
st10:
	if ( ++p == pe )
		goto _out10;
case 10:
	switch( (*p) ) {
		case 13: goto st10;
		case 32: goto st10;
		case 34: goto tr2;
		case 47: goto st11;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st10;
	goto st0;
st11:
	if ( ++p == pe )
		goto _out11;
case 11:
	switch( (*p) ) {
		case 42: goto st12;
		case 47: goto st14;
	}
	goto st0;
st12:
	if ( ++p == pe )
		goto _out12;
case 12:
	if ( (*p) == 42 )
		goto st13;
	goto st12;
st13:
	if ( ++p == pe )
		goto _out13;
case 13:
	switch( (*p) ) {
		case 42: goto st13;
		case 47: goto st10;
	}
	goto st12;
st14:
	if ( ++p == pe )
		goto _out14;
case 14:
	if ( (*p) == 10 )
		goto st10;
	goto st14;
st15:
	if ( ++p == pe )
		goto _out15;
case 15:
	switch( (*p) ) {
		case 42: goto st16;
		case 47: goto st18;
	}
	goto st0;
st16:
	if ( ++p == pe )
		goto _out16;
case 16:
	if ( (*p) == 42 )
		goto st17;
	goto st16;
st17:
	if ( ++p == pe )
		goto _out17;
case 17:
	switch( (*p) ) {
		case 42: goto st17;
		case 47: goto st9;
	}
	goto st16;
st18:
	if ( ++p == pe )
		goto _out18;
case 18:
	if ( (*p) == 10 )
		goto st9;
	goto st18;
tr4:
#line 90 "parser.rl"
	{ goto _out27; }
	goto st27;
st27:
	if ( ++p == pe )
		goto _out27;
case 27:
#line 290 "parser.c"
	goto st0;
st19:
	if ( ++p == pe )
		goto _out19;
case 19:
	switch( (*p) ) {
		case 42: goto st20;
		case 47: goto st22;
	}
	goto st0;
st20:
	if ( ++p == pe )
		goto _out20;
case 20:
	if ( (*p) == 42 )
		goto st21;
	goto st20;
st21:
	if ( ++p == pe )
		goto _out21;
case 21:
	switch( (*p) ) {
		case 42: goto st21;
		case 47: goto st8;
	}
	goto st20;
st22:
	if ( ++p == pe )
		goto _out22;
case 22:
	if ( (*p) == 10 )
		goto st8;
	goto st22;
st23:
	if ( ++p == pe )
		goto _out23;
case 23:
	switch( (*p) ) {
		case 42: goto st24;
		case 47: goto st26;
	}
	goto st0;
st24:
	if ( ++p == pe )
		goto _out24;
case 24:
	if ( (*p) == 42 )
		goto st25;
	goto st24;
st25:
	if ( ++p == pe )
		goto _out25;
case 25:
	switch( (*p) ) {
		case 42: goto st25;
		case 47: goto st2;
	}
	goto st24;
st26:
	if ( ++p == pe )
		goto _out26;
case 26:
	if ( (*p) == 10 )
		goto st2;
	goto st26;
	}
	_out0: cs = 0; goto _out; 
	_out2: cs = 2; goto _out; 
	_out3: cs = 3; goto _out; 
	_out4: cs = 4; goto _out; 
	_out5: cs = 5; goto _out; 
	_out6: cs = 6; goto _out; 
	_out7: cs = 7; goto _out; 
	_out8: cs = 8; goto _out; 
	_out9: cs = 9; goto _out; 
	_out10: cs = 10; goto _out; 
	_out11: cs = 11; goto _out; 
	_out12: cs = 12; goto _out; 
	_out13: cs = 13; goto _out; 
	_out14: cs = 14; goto _out; 
	_out15: cs = 15; goto _out; 
	_out16: cs = 16; goto _out; 
	_out17: cs = 17; goto _out; 
	_out18: cs = 18; goto _out; 
	_out27: cs = 27; goto _out; 
	_out19: cs = 19; goto _out; 
	_out20: cs = 20; goto _out; 
	_out21: cs = 21; goto _out; 
	_out22: cs = 22; goto _out; 
	_out23: cs = 23; goto _out; 
	_out24: cs = 24; goto _out; 
	_out25: cs = 25; goto _out; 
	_out26: cs = 26; goto _out; 

	_out: {}
	}
#line 114 "parser.rl"

    if (cs >= JSON_object_first_final) {
        if (RTEST(json->create_id)) {
            VALUE klassname = rb_hash_aref(*result, json->create_id);
            if (!NIL_P(klassname)) {
                VALUE klass = rb_path2class(StringValueCStr(klassname));
                if RTEST(rb_funcall(klass, i_json_creatable_p, 0)) {
                    *result = rb_funcall(klass, i_json_create, 1, *result);
                }
            }
        }
        return p + 1;
    } else {
        return NULL;
    }
}


#line 406 "parser.c"
static const int JSON_value_start = 1;
static const int JSON_value_first_final = 21;
static const int JSON_value_error = 0;

static const int JSON_value_en_main = 1;

#line 212 "parser.rl"


static char *JSON_parse_value(JSON_Parser *json, char *p, char *pe, VALUE *result)
{
    int cs = EVIL;

    
#line 421 "parser.c"
	{
	cs = JSON_value_start;
	}
#line 219 "parser.rl"
    
#line 427 "parser.c"
	{
	if ( p == pe )
		goto _out;
	switch ( cs )
	{
case 1:
	switch( (*p) ) {
		case 34: goto tr0;
		case 45: goto tr2;
		case 73: goto st2;
		case 78: goto st9;
		case 91: goto tr5;
		case 102: goto st11;
		case 110: goto st15;
		case 116: goto st18;
		case 123: goto tr9;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto tr2;
	goto st0;
st0:
	goto _out0;
tr0:
#line 160 "parser.rl"
	{
        char *np = JSON_parse_string(json, p, pe, result);
        if (np == NULL) goto _out21; else {p = (( np))-1;}
    }
	goto st21;
tr2:
#line 165 "parser.rl"
	{
        char *np;
        if(pe > p + 9 && !strncmp(MinusInfinity, p, 9)) {
            if (json->allow_nan) {
                *result = CMinusInfinity;
                {p = (( p + 10))-1;}
                goto _out21;
            } else {
                rb_raise(eParserError, "unexpected token at '%s'", p);
            }
        }
        np = JSON_parse_float(json, p, pe, result);
        if (np != NULL) {p = (( np))-1;}
        np = JSON_parse_integer(json, p, pe, result);
        if (np != NULL) {p = (( np))-1;}
        goto _out21;
    }
	goto st21;
tr5:
#line 183 "parser.rl"
	{ 
        char *np;
        json->current_nesting += 1;
        np = JSON_parse_array(json, p, pe, result);
        json->current_nesting -= 1;
        if (np == NULL) goto _out21; else {p = (( np))-1;}
    }
	goto st21;
tr9:
#line 191 "parser.rl"
	{ 
        char *np;
        json->current_nesting += 1;
        np =  JSON_parse_object(json, p, pe, result);
        json->current_nesting -= 1;
        if (np == NULL) goto _out21; else {p = (( np))-1;}
    }
	goto st21;
tr16:
#line 153 "parser.rl"
	{
        if (json->allow_nan) {
            *result = CInfinity;
        } else {
            rb_raise(eParserError, "unexpected token at '%s'", p - 8);
        }
    }
	goto st21;
tr18:
#line 146 "parser.rl"
	{
        if (json->allow_nan) {
            *result = CNaN;
        } else {
            rb_raise(eParserError, "unexpected token at '%s'", p - 2);
        }
    }
	goto st21;
tr22:
#line 140 "parser.rl"
	{
        *result = Qfalse;
    }
	goto st21;
tr25:
#line 137 "parser.rl"
	{
        *result = Qnil;
    }
	goto st21;
tr28:
#line 143 "parser.rl"
	{
        *result = Qtrue;
    }
	goto st21;
st21:
	if ( ++p == pe )
		goto _out21;
case 21:
#line 199 "parser.rl"
	{ goto _out21; }
#line 541 "parser.c"
	goto st0;
st2:
	if ( ++p == pe )
		goto _out2;
case 2:
	if ( (*p) == 110 )
		goto st3;
	goto st0;
st3:
	if ( ++p == pe )
		goto _out3;
case 3:
	if ( (*p) == 102 )
		goto st4;
	goto st0;
st4:
	if ( ++p == pe )
		goto _out4;
case 4:
	if ( (*p) == 105 )
		goto st5;
	goto st0;
st5:
	if ( ++p == pe )
		goto _out5;
case 5:
	if ( (*p) == 110 )
		goto st6;
	goto st0;
st6:
	if ( ++p == pe )
		goto _out6;
case 6:
	if ( (*p) == 105 )
		goto st7;
	goto st0;
st7:
	if ( ++p == pe )
		goto _out7;
case 7:
	if ( (*p) == 116 )
		goto st8;
	goto st0;
st8:
	if ( ++p == pe )
		goto _out8;
case 8:
	if ( (*p) == 121 )
		goto tr16;
	goto st0;
st9:
	if ( ++p == pe )
		goto _out9;
case 9:
	if ( (*p) == 97 )
		goto st10;
	goto st0;
st10:
	if ( ++p == pe )
		goto _out10;
case 10:
	if ( (*p) == 78 )
		goto tr18;
	goto st0;
st11:
	if ( ++p == pe )
		goto _out11;
case 11:
	if ( (*p) == 97 )
		goto st12;
	goto st0;
st12:
	if ( ++p == pe )
		goto _out12;
case 12:
	if ( (*p) == 108 )
		goto st13;
	goto st0;
st13:
	if ( ++p == pe )
		goto _out13;
case 13:
	if ( (*p) == 115 )
		goto st14;
	goto st0;
st14:
	if ( ++p == pe )
		goto _out14;
case 14:
	if ( (*p) == 101 )
		goto tr22;
	goto st0;
st15:
	if ( ++p == pe )
		goto _out15;
case 15:
	if ( (*p) == 117 )
		goto st16;
	goto st0;
st16:
	if ( ++p == pe )
		goto _out16;
case 16:
	if ( (*p) == 108 )
		goto st17;
	goto st0;
st17:
	if ( ++p == pe )
		goto _out17;
case 17:
	if ( (*p) == 108 )
		goto tr25;
	goto st0;
st18:
	if ( ++p == pe )
		goto _out18;
case 18:
	if ( (*p) == 114 )
		goto st19;
	goto st0;
st19:
	if ( ++p == pe )
		goto _out19;
case 19:
	if ( (*p) == 117 )
		goto st20;
	goto st0;
st20:
	if ( ++p == pe )
		goto _out20;
case 20:
	if ( (*p) == 101 )
		goto tr28;
	goto st0;
	}
	_out0: cs = 0; goto _out; 
	_out21: cs = 21; goto _out; 
	_out2: cs = 2; goto _out; 
	_out3: cs = 3; goto _out; 
	_out4: cs = 4; goto _out; 
	_out5: cs = 5; goto _out; 
	_out6: cs = 6; goto _out; 
	_out7: cs = 7; goto _out; 
	_out8: cs = 8; goto _out; 
	_out9: cs = 9; goto _out; 
	_out10: cs = 10; goto _out; 
	_out11: cs = 11; goto _out; 
	_out12: cs = 12; goto _out; 
	_out13: cs = 13; goto _out; 
	_out14: cs = 14; goto _out; 
	_out15: cs = 15; goto _out; 
	_out16: cs = 16; goto _out; 
	_out17: cs = 17; goto _out; 
	_out18: cs = 18; goto _out; 
	_out19: cs = 19; goto _out; 
	_out20: cs = 20; goto _out; 

	_out: {}
	}
#line 220 "parser.rl"

    if (cs >= JSON_value_first_final) {
        return p;
    } else {
        return NULL;
    }
}


#line 711 "parser.c"
static const int JSON_integer_start = 1;
static const int JSON_integer_first_final = 5;
static const int JSON_integer_error = 0;

static const int JSON_integer_en_main = 1;

#line 236 "parser.rl"


static char *JSON_parse_integer(JSON_Parser *json, char *p, char *pe, VALUE *result)
{
    int cs = EVIL;

    
#line 726 "parser.c"
	{
	cs = JSON_integer_start;
	}
#line 243 "parser.rl"
    json->memo = p;
    
#line 733 "parser.c"
	{
	if ( p == pe )
		goto _out;
	switch ( cs )
	{
case 1:
	switch( (*p) ) {
		case 45: goto st2;
		case 48: goto st3;
	}
	if ( 49 <= (*p) && (*p) <= 57 )
		goto st4;
	goto st0;
st0:
	goto _out0;
st2:
	if ( ++p == pe )
		goto _out2;
case 2:
	if ( (*p) == 48 )
		goto st3;
	if ( 49 <= (*p) && (*p) <= 57 )
		goto st4;
	goto st0;
st3:
	if ( ++p == pe )
		goto _out3;
case 3:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st0;
	goto tr4;
tr4:
#line 233 "parser.rl"
	{ goto _out5; }
	goto st5;
st5:
	if ( ++p == pe )
		goto _out5;
case 5:
#line 773 "parser.c"
	goto st0;
st4:
	if ( ++p == pe )
		goto _out4;
case 4:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st4;
	goto tr4;
	}
	_out0: cs = 0; goto _out; 
	_out2: cs = 2; goto _out; 
	_out3: cs = 3; goto _out; 
	_out5: cs = 5; goto _out; 
	_out4: cs = 4; goto _out; 

	_out: {}
	}
#line 245 "parser.rl"

    if (cs >= JSON_integer_first_final) {
        long len = p - json->memo;
        *result = rb_Integer(rb_str_new(json->memo, len));
        return p + 1;
    } else {
        return NULL;
    }
}


#line 803 "parser.c"
static const int JSON_float_start = 1;
static const int JSON_float_first_final = 10;
static const int JSON_float_error = 0;

static const int JSON_float_en_main = 1;

#line 267 "parser.rl"


static char *JSON_parse_float(JSON_Parser *json, char *p, char *pe, VALUE *result)
{
    int cs = EVIL;

    
#line 818 "parser.c"
	{
	cs = JSON_float_start;
	}
#line 274 "parser.rl"
    json->memo = p;
    
#line 825 "parser.c"
	{
	if ( p == pe )
		goto _out;
	switch ( cs )
	{
case 1:
	switch( (*p) ) {
		case 45: goto st2;
		case 48: goto st3;
	}
	if ( 49 <= (*p) && (*p) <= 57 )
		goto st9;
	goto st0;
st0:
	goto _out0;
st2:
	if ( ++p == pe )
		goto _out2;
case 2:
	if ( (*p) == 48 )
		goto st3;
	if ( 49 <= (*p) && (*p) <= 57 )
		goto st9;
	goto st0;
st3:
	if ( ++p == pe )
		goto _out3;
case 3:
	switch( (*p) ) {
		case 46: goto st4;
		case 69: goto st6;
		case 101: goto st6;
	}
	goto st0;
st4:
	if ( ++p == pe )
		goto _out4;
case 4:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st5;
	goto st0;
st5:
	if ( ++p == pe )
		goto _out5;
case 5:
	switch( (*p) ) {
		case 69: goto st6;
		case 101: goto st6;
	}
	if ( (*p) > 46 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st5;
	} else if ( (*p) >= 45 )
		goto st0;
	goto tr7;
tr7:
#line 261 "parser.rl"
	{ goto _out10; }
	goto st10;
st10:
	if ( ++p == pe )
		goto _out10;
case 10:
#line 889 "parser.c"
	goto st0;
st6:
	if ( ++p == pe )
		goto _out6;
case 6:
	switch( (*p) ) {
		case 43: goto st7;
		case 45: goto st7;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st8;
	goto st0;
st7:
	if ( ++p == pe )
		goto _out7;
case 7:
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st8;
	goto st0;
st8:
	if ( ++p == pe )
		goto _out8;
case 8:
	switch( (*p) ) {
		case 69: goto st0;
		case 101: goto st0;
	}
	if ( (*p) > 46 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st8;
	} else if ( (*p) >= 45 )
		goto st0;
	goto tr7;
st9:
	if ( ++p == pe )
		goto _out9;
case 9:
	switch( (*p) ) {
		case 46: goto st4;
		case 69: goto st6;
		case 101: goto st6;
	}
	if ( 48 <= (*p) && (*p) <= 57 )
		goto st9;
	goto st0;
	}
	_out0: cs = 0; goto _out; 
	_out2: cs = 2; goto _out; 
	_out3: cs = 3; goto _out; 
	_out4: cs = 4; goto _out; 
	_out5: cs = 5; goto _out; 
	_out10: cs = 10; goto _out; 
	_out6: cs = 6; goto _out; 
	_out7: cs = 7; goto _out; 
	_out8: cs = 8; goto _out; 
	_out9: cs = 9; goto _out; 

	_out: {}
	}
#line 276 "parser.rl"

    if (cs >= JSON_float_first_final) {
        long len = p - json->memo;
        *result = rb_Float(rb_str_new(json->memo, len));
        return p + 1;
    } else {
        return NULL;
    }
}



#line 962 "parser.c"
static const int JSON_array_start = 1;
static const int JSON_array_first_final = 17;
static const int JSON_array_error = 0;

static const int JSON_array_en_main = 1;

#line 312 "parser.rl"


static char *JSON_parse_array(JSON_Parser *json, char *p, char *pe, VALUE *result)
{
    int cs = EVIL;

    if (json->max_nesting && json->current_nesting > json->max_nesting) {
        rb_raise(eNestingError, "nesting of %d is to deep", json->current_nesting);
    }
    *result = rb_ary_new();

    
#line 982 "parser.c"
	{
	cs = JSON_array_start;
	}
#line 324 "parser.rl"
    
#line 988 "parser.c"
	{
	if ( p == pe )
		goto _out;
	switch ( cs )
	{
case 1:
	if ( (*p) == 91 )
		goto st2;
	goto st0;
st0:
	goto _out0;
st2:
	if ( ++p == pe )
		goto _out2;
case 2:
	switch( (*p) ) {
		case 13: goto st2;
		case 32: goto st2;
		case 34: goto tr2;
		case 45: goto tr2;
		case 47: goto st13;
		case 73: goto tr2;
		case 78: goto tr2;
		case 91: goto tr2;
		case 93: goto tr4;
		case 102: goto tr2;
		case 110: goto tr2;
		case 116: goto tr2;
		case 123: goto tr2;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2;
	} else if ( (*p) >= 9 )
		goto st2;
	goto st0;
tr2:
#line 293 "parser.rl"
	{
        VALUE v = Qnil;
        char *np = JSON_parse_value(json, p, pe, &v); 
        if (np == NULL) {
            goto _out3;
        } else {
            rb_ary_push(*result, v);
            {p = (( np))-1;}
        }
    }
	goto st3;
st3:
	if ( ++p == pe )
		goto _out3;
case 3:
#line 1042 "parser.c"
	switch( (*p) ) {
		case 13: goto st3;
		case 32: goto st3;
		case 44: goto st4;
		case 47: goto st9;
		case 93: goto tr4;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st3;
	goto st0;
st4:
	if ( ++p == pe )
		goto _out4;
case 4:
	switch( (*p) ) {
		case 13: goto st4;
		case 32: goto st4;
		case 34: goto tr2;
		case 45: goto tr2;
		case 47: goto st5;
		case 73: goto tr2;
		case 78: goto tr2;
		case 91: goto tr2;
		case 102: goto tr2;
		case 110: goto tr2;
		case 116: goto tr2;
		case 123: goto tr2;
	}
	if ( (*p) > 10 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto tr2;
	} else if ( (*p) >= 9 )
		goto st4;
	goto st0;
st5:
	if ( ++p == pe )
		goto _out5;
case 5:
	switch( (*p) ) {
		case 42: goto st6;
		case 47: goto st8;
	}
	goto st0;
st6:
	if ( ++p == pe )
		goto _out6;
case 6:
	if ( (*p) == 42 )
		goto st7;
	goto st6;
st7:
	if ( ++p == pe )
		goto _out7;
case 7:
	switch( (*p) ) {
		case 42: goto st7;
		case 47: goto st4;
	}
	goto st6;
st8:
	if ( ++p == pe )
		goto _out8;
case 8:
	if ( (*p) == 10 )
		goto st4;
	goto st8;
st9:
	if ( ++p == pe )
		goto _out9;
case 9:
	switch( (*p) ) {
		case 42: goto st10;
		case 47: goto st12;
	}
	goto st0;
st10:
	if ( ++p == pe )
		goto _out10;
case 10:
	if ( (*p) == 42 )
		goto st11;
	goto st10;
st11:
	if ( ++p == pe )
		goto _out11;
case 11:
	switch( (*p) ) {
		case 42: goto st11;
		case 47: goto st3;
	}
	goto st10;
st12:
	if ( ++p == pe )
		goto _out12;
case 12:
	if ( (*p) == 10 )
		goto st3;
	goto st12;
tr4:
#line 304 "parser.rl"
	{ goto _out17; }
	goto st17;
st17:
	if ( ++p == pe )
		goto _out17;
case 17:
#line 1149 "parser.c"
	goto st0;
st13:
	if ( ++p == pe )
		goto _out13;
case 13:
	switch( (*p) ) {
		case 42: goto st14;
		case 47: goto st16;
	}
	goto st0;
st14:
	if ( ++p == pe )
		goto _out14;
case 14:
	if ( (*p) == 42 )
		goto st15;
	goto st14;
st15:
	if ( ++p == pe )
		goto _out15;
case 15:
	switch( (*p) ) {
		case 42: goto st15;
		case 47: goto st2;
	}
	goto st14;
st16:
	if ( ++p == pe )
		goto _out16;
case 16:
	if ( (*p) == 10 )
		goto st2;
	goto st16;
	}
	_out0: cs = 0; goto _out; 
	_out2: cs = 2; goto _out; 
	_out3: cs = 3; goto _out; 
	_out4: cs = 4; goto _out; 
	_out5: cs = 5; goto _out; 
	_out6: cs = 6; goto _out; 
	_out7: cs = 7; goto _out; 
	_out8: cs = 8; goto _out; 
	_out9: cs = 9; goto _out; 
	_out10: cs = 10; goto _out; 
	_out11: cs = 11; goto _out; 
	_out12: cs = 12; goto _out; 
	_out17: cs = 17; goto _out; 
	_out13: cs = 13; goto _out; 
	_out14: cs = 14; goto _out; 
	_out15: cs = 15; goto _out; 
	_out16: cs = 16; goto _out; 

	_out: {}
	}
#line 325 "parser.rl"

    if(cs >= JSON_array_first_final) {
        return p + 1;
    } else {
        rb_raise(eParserError, "unexpected token at '%s'", p);
    }
}

static VALUE json_string_unescape(char *p, char *pe)
{
    VALUE result = rb_str_buf_new(pe - p + 1);

    while (p < pe) {
        if (*p == '\\') {
            p++;
            if (p >= pe) return Qnil; /* raise an exception later, \ at end */
            switch (*p) {
                case '"':
                case '\\':
                    rb_str_buf_cat(result, p, 1);
                    p++;
                    break;
                case 'b':
                    rb_str_buf_cat2(result, "\b");
                    p++;
                    break;
                case 'f':
                    rb_str_buf_cat2(result, "\f");
                    p++;
                    break;
                case 'n':
                    rb_str_buf_cat2(result, "\n");
                    p++;
                    break;
                case 'r':
                    rb_str_buf_cat2(result, "\r");
                    p++;
                    break;
                case 't':
                    rb_str_buf_cat2(result, "\t");
                    p++;
                    break;
                case 'u':
                    if (p > pe - 4) { 
                        return Qnil;
                    } else {
                        p = JSON_convert_UTF16_to_UTF8(result, p, pe, strictConversion);
                    }
                    break;
                default:
                    rb_str_buf_cat(result, p, 1);
                    p++;
                    break;
            }
        } else {
            char *q = p;
            while (*q != '\\' && q < pe) q++;
            rb_str_buf_cat(result, p, q - p);
            p = q;
        }
    }
    return result;
}


#line 1270 "parser.c"
static const int JSON_string_start = 1;
static const int JSON_string_first_final = 8;
static const int JSON_string_error = 0;

static const int JSON_string_en_main = 1;

#line 403 "parser.rl"


static char *JSON_parse_string(JSON_Parser *json, char *p, char *pe, VALUE *result)
{
    int cs = EVIL;

    *result = rb_str_new("", 0);
    
#line 1286 "parser.c"
	{
	cs = JSON_string_start;
	}
#line 411 "parser.rl"
    json->memo = p;
    
#line 1293 "parser.c"
	{
	if ( p == pe )
		goto _out;
	switch ( cs )
	{
case 1:
	if ( (*p) == 34 )
		goto st2;
	goto st0;
st0:
	goto _out0;
st2:
	if ( ++p == pe )
		goto _out2;
case 2:
	switch( (*p) ) {
		case 34: goto tr2;
		case 92: goto st3;
	}
	if ( 0 <= (*p) && (*p) <= 31 )
		goto st0;
	goto st2;
tr2:
#line 395 "parser.rl"
	{
        *result = json_string_unescape(json->memo + 1, p);
        if (NIL_P(*result)) goto _out8; else {p = (( p + 1))-1;}
    }
#line 400 "parser.rl"
	{ goto _out8; }
	goto st8;
st8:
	if ( ++p == pe )
		goto _out8;
case 8:
#line 1329 "parser.c"
	goto st0;
st3:
	if ( ++p == pe )
		goto _out3;
case 3:
	if ( (*p) == 117 )
		goto st4;
	if ( 0 <= (*p) && (*p) <= 31 )
		goto st0;
	goto st2;
st4:
	if ( ++p == pe )
		goto _out4;
case 4:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st5;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st5;
	} else
		goto st5;
	goto st0;
st5:
	if ( ++p == pe )
		goto _out5;
case 5:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st6;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st6;
	} else
		goto st6;
	goto st0;
st6:
	if ( ++p == pe )
		goto _out6;
case 6:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st7;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st7;
	} else
		goto st7;
	goto st0;
st7:
	if ( ++p == pe )
		goto _out7;
case 7:
	if ( (*p) < 65 ) {
		if ( 48 <= (*p) && (*p) <= 57 )
			goto st2;
	} else if ( (*p) > 70 ) {
		if ( 97 <= (*p) && (*p) <= 102 )
			goto st2;
	} else
		goto st2;
	goto st0;
	}
	_out0: cs = 0; goto _out; 
	_out2: cs = 2; goto _out; 
	_out8: cs = 8; goto _out; 
	_out3: cs = 3; goto _out; 
	_out4: cs = 4; goto _out; 
	_out5: cs = 5; goto _out; 
	_out6: cs = 6; goto _out; 
	_out7: cs = 7; goto _out; 

	_out: {}
	}
#line 413 "parser.rl"

    if (cs >= JSON_string_first_final) {
        return p + 1;
    } else {
        return NULL;
    }
}



#line 1415 "parser.c"
static const int JSON_start = 1;
static const int JSON_first_final = 10;
static const int JSON_error = 0;

static const int JSON_en_main = 1;

#line 447 "parser.rl"


/* 
 * Document-class: JSON::Ext::Parser
 *
 * This is the JSON parser implemented as a C extension. It can be configured
 * to be used by setting
 *
 *  JSON.parser = JSON::Ext::Parser
 *
 * with the method parser= in JSON.
 *
 */

/*
 * call-seq: new(source, opts => {})
 *
 * Creates a new JSON::Ext::Parser instance for the string _source_.
 *
 * Creates a new JSON::Ext::Parser instance for the string _source_.
 *
 * It will be configured by the _opts_ hash. _opts_ can have the following
 * keys:
 *
 * _opts_ can have the following keys:
 * * *max_nesting*: The maximum depth of nesting allowed in the parsed data
 *   structures. Disable depth checking with :max_nesting => false|nil|0, it
 *   defaults to 19.
 * * *allow_nan*: If set to true, allow NaN, Infinity and -Infinity in
 *   defiance of RFC 4627 to be parsed by the Parser. This option defaults to
 *   false.
 * * *create_additions*: If set to false, the Parser doesn't create
 *   additions even if a matchin class and create_id was found. This option
 *   defaults to true.
 */
static VALUE cParser_initialize(int argc, VALUE *argv, VALUE self)
{
    char *ptr;
    long len;
    VALUE source, opts;
    GET_STRUCT;
    rb_scan_args(argc, argv, "11", &source, &opts);
    source = StringValue(source);
    ptr = RSTRING_PTR(source);
    len = RSTRING_LEN(source);
    if (len < 2) {
        rb_raise(eParserError, "A JSON text must at least contain two octets!");
    }
    if (!NIL_P(opts)) {
        opts = rb_convert_type(opts, T_HASH, "Hash", "to_hash");
        if (NIL_P(opts)) {
            rb_raise(rb_eArgError, "opts needs to be like a hash");
        } else {
            VALUE tmp = ID2SYM(i_max_nesting);
            if (st_lookup(RHASH(opts)->tbl, tmp, 0)) {
                VALUE max_nesting = rb_hash_aref(opts, tmp);
                if (RTEST(max_nesting)) {
                    Check_Type(max_nesting, T_FIXNUM);
                    json->max_nesting = FIX2INT(max_nesting);
                } else {
                    json->max_nesting = 0;
                }
            } else {
                json->max_nesting = 19;
            }
            tmp = ID2SYM(i_allow_nan);
            if (st_lookup(RHASH(opts)->tbl, tmp, 0)) {
                VALUE allow_nan = rb_hash_aref(opts, tmp);
                json->allow_nan = RTEST(allow_nan) ? 1 : 0;
            } else {
                json->allow_nan = 0;
            }
            tmp = ID2SYM(i_create_additions);
            if (st_lookup(RHASH(opts)->tbl, tmp, 0)) {
                VALUE create_additions = rb_hash_aref(opts, tmp);
                if (RTEST(create_additions)) {
                    json->create_id = rb_funcall(mJSON, i_create_id, 0);
                } else {
                    json->create_id = Qnil;
                }
            } else {
                json->create_id = rb_funcall(mJSON, i_create_id, 0);
            }
        }
    } else {
        json->max_nesting = 19;
        json->allow_nan = 0;
        json->create_id = rb_funcall(mJSON, i_create_id, 0);
    }
    json->current_nesting = 0;
    /*
       Convert these?
    if (len >= 4 &&  ptr[0] == 0 && ptr[1] == 0 && ptr[2] == 0) {
        rb_raise(eParserError, "Only UTF8 octet streams are supported atm!");
    } else if (len >= 4 && ptr[0] == 0 && ptr[2] == 0) {
        rb_raise(eParserError, "Only UTF8 octet streams are supported atm!");
    } else if (len >= 4 && ptr[1] == 0 && ptr[2] == 0 && ptr[3] == 0) {
        rb_raise(eParserError, "Only UTF8 octet streams are supported atm!");
    } else if (len >= 4 && ptr[1] == 0 && ptr[3] == 0) {
        rb_raise(eParserError, "Only UTF8 octet streams are supported atm!");
    }
    */
    json->len = len;
    json->source = ptr;
    json->Vsource = source;
    return self;
}

/*
 * call-seq: parse()
 *
 *  Parses the current JSON text _source_ and returns the complete data
 *  structure as a result.
 */
static VALUE cParser_parse(VALUE self)
{
    char *p, *pe;
    int cs = EVIL;
    VALUE result = Qnil;
    GET_STRUCT;

    
#line 1545 "parser.c"
	{
	cs = JSON_start;
	}
#line 569 "parser.rl"
    p = json->source;
    pe = p + json->len;
    
#line 1553 "parser.c"
	{
	if ( p == pe )
		goto _out;
	switch ( cs )
	{
st1:
	if ( ++p == pe )
		goto _out1;
case 1:
	switch( (*p) ) {
		case 13: goto st1;
		case 32: goto st1;
		case 47: goto st2;
		case 91: goto tr3;
		case 123: goto tr4;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st1;
	goto st0;
st0:
	goto _out0;
st2:
	if ( ++p == pe )
		goto _out2;
case 2:
	switch( (*p) ) {
		case 42: goto st3;
		case 47: goto st5;
	}
	goto st0;
st3:
	if ( ++p == pe )
		goto _out3;
case 3:
	if ( (*p) == 42 )
		goto st4;
	goto st3;
st4:
	if ( ++p == pe )
		goto _out4;
case 4:
	switch( (*p) ) {
		case 42: goto st4;
		case 47: goto st1;
	}
	goto st3;
st5:
	if ( ++p == pe )
		goto _out5;
case 5:
	if ( (*p) == 10 )
		goto st1;
	goto st5;
tr3:
#line 436 "parser.rl"
	{
        char *np;
        json->current_nesting = 1;
        np = JSON_parse_array(json, p, pe, &result);
        if (np == NULL) goto _out10; else {p = (( np))-1;}
    }
	goto st10;
tr4:
#line 429 "parser.rl"
	{
        char *np;
        json->current_nesting = 1;
        np = JSON_parse_object(json, p, pe, &result);
        if (np == NULL) goto _out10; else {p = (( np))-1;}
    }
	goto st10;
st10:
	if ( ++p == pe )
		goto _out10;
case 10:
#line 1629 "parser.c"
	switch( (*p) ) {
		case 13: goto st10;
		case 32: goto st10;
		case 47: goto st6;
	}
	if ( 9 <= (*p) && (*p) <= 10 )
		goto st10;
	goto st0;
st6:
	if ( ++p == pe )
		goto _out6;
case 6:
	switch( (*p) ) {
		case 42: goto st7;
		case 47: goto st9;
	}
	goto st0;
st7:
	if ( ++p == pe )
		goto _out7;
case 7:
	if ( (*p) == 42 )
		goto st8;
	goto st7;
st8:
	if ( ++p == pe )
		goto _out8;
case 8:
	switch( (*p) ) {
		case 42: goto st8;
		case 47: goto st10;
	}
	goto st7;
st9:
	if ( ++p == pe )
		goto _out9;
case 9:
	if ( (*p) == 10 )
		goto st10;
	goto st9;
	}
	_out1: cs = 1; goto _out; 
	_out0: cs = 0; goto _out; 
	_out2: cs = 2; goto _out; 
	_out3: cs = 3; goto _out; 
	_out4: cs = 4; goto _out; 
	_out5: cs = 5; goto _out; 
	_out10: cs = 10; goto _out; 
	_out6: cs = 6; goto _out; 
	_out7: cs = 7; goto _out; 
	_out8: cs = 8; goto _out; 
	_out9: cs = 9; goto _out; 

	_out: {}
	}
#line 572 "parser.rl"

    if (cs >= JSON_first_final && p == pe) {
        return result;
    } else {
        rb_raise(eParserError, "unexpected token at '%s'", p);
    }
}

inline static JSON_Parser *JSON_allocate()
{
    JSON_Parser *json = ALLOC(JSON_Parser);
    MEMZERO(json, JSON_Parser, 1);
    return json;
}

static void JSON_mark(JSON_Parser *json)
{
    rb_gc_mark_maybe(json->Vsource);
    rb_gc_mark_maybe(json->create_id);
}

static void JSON_free(JSON_Parser *json)
{
    free(json);
}

static VALUE cJSON_parser_s_allocate(VALUE klass)
{
    JSON_Parser *json = JSON_allocate();
    return Data_Wrap_Struct(klass, JSON_mark, JSON_free, json);
}

/*
 * call-seq: source()
 *
 * Returns a copy of the current _source_ string, that was used to construct
 * this Parser.
 */
static VALUE cParser_source(VALUE self)
{
    GET_STRUCT;
    return rb_str_dup(json->Vsource);
}

void Init_parser()
{
    mJSON = rb_define_module("JSON");
    mExt = rb_define_module_under(mJSON, "Ext");
    cParser = rb_define_class_under(mExt, "Parser", rb_cObject);
    eParserError = rb_path2class("JSON::ParserError");
    eNestingError = rb_path2class("JSON::NestingError");
    rb_define_alloc_func(cParser, cJSON_parser_s_allocate);
    rb_define_method(cParser, "initialize", cParser_initialize, -1);
    rb_define_method(cParser, "parse", cParser_parse, 0);
    rb_define_method(cParser, "source", cParser_source, 0);

    CNaN = rb_const_get(mJSON, rb_intern("NaN"));
    CInfinity = rb_const_get(mJSON, rb_intern("Infinity"));
    CMinusInfinity = rb_const_get(mJSON, rb_intern("MinusInfinity"));

    i_json_creatable_p = rb_intern("json_creatable?");
    i_json_create = rb_intern("json_create");
    i_create_id = rb_intern("create_id");
    i_create_additions = rb_intern("create_additions");
    i_chr = rb_intern("chr");
    i_max_nesting = rb_intern("max_nesting");
    i_allow_nan = rb_intern("allow_nan");
}
