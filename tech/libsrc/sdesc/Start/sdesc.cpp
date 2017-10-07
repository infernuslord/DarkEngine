//Empty file

#include <windows.h>
#include <lg.h>
#include <comtools.h>

#include "sdesbase.h"
#include "sdestype.h"
#include "sdestool.h"
//#include "sdestul_.h"
#include <mprintf.h>

#include <math.h>

#include <dbg.h>


char *true_names[6];
char *false_names[6];
const char *commastr;
char *delim;
char *elipsis;

sFieldDesc *StructDescFindField(sStructDesc *desc, const char *name)
{
    sFieldDesc *result;
    int which;

    for(which = 0; which < desc->nfields && _strnicmp(name, desc->fields[which].name, 0x20u); ++which)
    {
        ;
    }
        
    if(which < desc->nfields)
    {
        result = &desc->fields[which];
    }
    else
    {
#ifdef DBG_ON
        DbgReportWarning("StructFieldToString: Field %s not found in struct %s\n");
#else
        Warning("StructFieldToString: Field %s not found in struct %s\n")
#endif
        result = 0;
    }
    return result;
}


int sd_cast_to_long(void *val, unsigned int size, int is_signed)
{
    int result;
    unsigned int sz;

    sz = size;
    if(is_signed)
    {
        sz = size + 4;
    }
        
    switch(sz)
    {
    case 1u:
        result = (int)val;
        break;
    case 2u:
        result = (int)val;
        break;
    case 4u:
        result = (int)val;
        break;
    case 5u:
        result = (int)val;
        break;
    case 6u:
        result = (int)val;
        break;
    case 8u:
        result = (int)val;
        break;
    default:
#ifdef DBG_ON
        DbgReportWarning("Invalid size for integer %d\n");
#else
        Warning("Invalid size for integer %d\n")
#endif
        result = 0;
        break;
    }
    return result;
}

void sd_stuff_from_long(int *val, int in, unsigned int size)
{
    memcpy(val, &in, size);
}



void parse_int(sFieldDesc *desc, void *val, char *in)
{
    __int32 v3;
    int radix;

    radix = 10;
    if(desc->flags & 0x40)
        radix = 16;
    v3 = strtol(in, 0, radix);
    sd_stuff_from_long((int *)val, v3, desc->size);
}




void unparse_int(sFieldDesc *desc, void *val, char *out)
{
    int radix;
    __int32 ival;

    ival = sd_cast_to_long(val, desc->size, (desc->flags & 0x20) == 0);
    radix = 10;
    if(desc->flags & 0x40)
        radix = 16;
    _ltoa(ival, out, radix);
}




void parse_bool(sFieldDesc *desc, void *val, char *in)
{
    size_t v3;
    size_t v4;
    char **name;
    char **namea;

    for(name = true_names; *name; ++name)
    {
        v3 = strlen(*name);
        if(!_strnicmp(in, *name, v3))
        {
            sd_stuff_from_long((int *)val, 1, desc->size);
            return;
        }
    }
    for(namea = false_names; *namea; ++namea)
    {
        v4 = strlen(*namea);
        if(!_strnicmp(in, *namea, v4))
        {
            sd_stuff_from_long((int *)val, 0, desc->size);
            return;
        }
    }
    parse_int(desc, val, in);
}


void unparse_bool(sFieldDesc *desc, void *val, char *out)
{
    int v3;

    if(sd_cast_to_long(val, desc->size, 0))
        v3 = (int)"TRUE";
    else
        v3 = (int)"FALSE";
    sprintf(out, "%s", v3);
}


void parse_bits(sFieldDesc *desc, void *val, char *in)
{
    unsigned int i;
    char tmp;
    char *p;
    void *strings;
    int *s;
    __int32 ival;

    ival = 0;
    if(desc->datasize)
    {
        strings = desc->data;
        for(s = (int *)in; isspace(*s); s = (int *)((char *)s + 1))
        {
            ;
        }

        while(*s)
        {
            p = strchr((char *)s, 44);
            if(!p)
                p = (char *)s + strlen((const char *)s) + 1;
            tmp = *p;
            *p = 0;

            for(i = 0; i < desc->datasize; ++i)
            {
                if(!strcmp((const char *)s, *((const char **)strings + i)))
                {
                    ival |= 1 << (LOBYTE(desc->min) + i);
                    break;
                }
            }
            *p = tmp;
            if(!*p)
                break;

            for(s = (int *)(p + 1); isspace(*s); s = (int *)((char *)s + 1))
            {
                ;
            }
        }
    }
    else
    {
        ival = strtol(in, 0, 2);
    }
    sd_stuff_from_long((int *)val, ival, desc->size);
}



void unparse_bits(sFieldDesc *desc, void *val, char *out)
{
    __int32 Val;
    signed int comma;
    unsigned int i;
    int ival;
    void *strings;
    char *s;

    if(desc->flags & 0x40)
    {
        unparse_int(desc, val, out);
    }
    else
    {
        if(desc->datasize)
        {
            ival = sd_cast_to_long(val, desc->size, 0);
            comma = 0;
            s = out;
            strings = desc->data;
            *out = 0;
            for(i = 0; i < desc->datasize; ++i)
            {
                if((1 << (LOBYTE(desc->min) + i)) & ival)
                {
                    if(comma)
                    {
                        strcpy(s, commastr);
                        s += strlen(s);
                    }
                    strcpy(s, *((const char **)strings + i));
                    s += strlen(s);
                    comma = 1;
                }
            }
            if(!comma)
                strcpy(out, "[None]");
        }
        else
        {
            Val = sd_cast_to_long(val, desc->size, 0);
            if(desc->max)
                Val &= (1 << desc->max) - 1;
            _ltoa(Val, out, 2);
        }
    }
}



void parse_enum(sFieldDesc *desc, void *val, char *in)
{
    int v3;
    int v4;
    int v5;
    signed int found;
    int i;
    int ia;
    void *vec;

    vec = desc->data;
    found = 0;
    for(i = 0; i < desc->datasize; ++i)
    {
        if(!_strcmpi(in, *((const char **)vec + i)))
        {
            found = 1;
            i += desc->min;
            break;
        }
    }
    if(!found)
    {
        parse_int(desc, val, in);
        ia = sd_cast_to_long(val, desc->size, 1);
        if(ia >= desc->max)
            v5 = desc->max;
        else
            v5 = ia;
        if(desc->min <= v5)
        {
            if(ia >= desc->max)
                v3 = desc->max;
            else
                v3 = ia;
            v4 = v3;
        }
        else
        {
            v4 = desc->min;
        }
        i = v4;
    }
    sd_stuff_from_long((int *)val, i, desc->size);
}



void unparse_enum(sFieldDesc *desc, void *val, char *out)
{
    int v3;
    int v4;
    int v5;
    int ival;

    ival = sd_cast_to_long(val, desc->size, (desc->flags & 0x20) == 0);
    if(ival >= desc->max)
        v5 = desc->max;
    else
        v5 = ival;
    if(desc->min <= v5)
    {
        if(ival >= desc->max)
            v3 = desc->max;
        else
            v3 = ival;
        v4 = v3;
    }
    else
    {
        v4 = desc->min;
    }

    if(v4 - desc->min <= desc->datasize)
        strcpy(out, *((const char **)desc->data + v4 - desc->min));
    else
        unparse_int(desc, val, out);
}


void parse_string(sFieldDesc *desc, void *val, char *in)
{
    strncpy((char *)val, in, desc->size);
    //XXX
    //check
    *((BYTE *)val + desc->size - 1) = 0;
}

void unparse_string(sFieldDesc *desc, void *val, char *out)
{
    strncpy(out, (const char *)val, desc->size);
}

void parse_stringptr(sFieldDesc *desc, void *val, char *in)
{
    strcpy(*(char **)val, in);
}

void unparse_stringptr(sFieldDesc *desc, void *val, char *out)
{
    strcpy(out, *(const char **)val);
}

void parse_voidptr(sFieldDesc *desc, void *val, char *in)
{
    sscanf(in, "%p", val);
}

void unparse_voidptr(sFieldDesc *desc, void *val, char *out)
{
    sprintf(out, "%p", val);
}


void parse_point(sFieldDesc *desc, void *val, char *in)
{
    char *comma;
    sFieldDesc idesc;

    memcpy(&idesc, desc, sizeof(idesc));
    idesc.size >>= 1;
    parse_int(&idesc, val, in);
    comma = strchr(in, 44);
    if(comma)
        parse_int(&idesc, (char *)val + idesc.size, comma + 1);
}


void unparse_point(sFieldDesc *desc, void *val, char *out)
{
    size_t v3;
    sFieldDesc idesc;

    memcpy(&idesc, desc, sizeof(idesc));
    idesc.size >>= 1;
    unparse_int(&idesc, val, out);
    strcat(out, ", ");
    v3 = strlen(out);
    unparse_int(&idesc, (char *)val + idesc.size, &out[v3]);
}


void parse_vector(sFieldDesc *desc, void *val, char *in)
{
    sscanf(in, "%f, %f, %f", val, (char *)val + 4, (char *)val + 8);
}

void unparse_vector(sFieldDesc *desc, void *val, char *out)
{
    sprintf(out, "%0.2f, %0.2f, %0.2f", *(float *)val, *((float *)val + 1), *((float *)val + 2));
}

void parse_rgba(sFieldDesc *desc, void *val, char *in)
{
    sscanf(in, "%d, %d, %d", (char *)val + 1, (char *)val + 2, (char *)val + 3);
}

void unparse_rgba(sFieldDesc *desc, void *val, char *out)
{
    sprintf(out, "%d, %d, %d", *((BYTE *)val + 1), *((BYTE *)val + 2), *((BYTE *)val + 3));
}

void parse_double_vec(sFieldDesc *desc, void *val, char *in)
{
    sscanf(in, "%lf, %lf %lf", val, (char *)val + 8, (char *)val + 16);
}

void unparse_double_vec(sFieldDesc *desc, void *val, char *out)
{
    sprintf(out, "%0.4lf, %0.4lf, %0.4lf", *(DWORD *)val, *((DWORD *)val + 1), *((DWORD *)val + 2), *((DWORD *)val + 3), *((DWORD *)val + 4), *((DWORD *)val + 5));
}

void parse_ang(sFieldDesc *desc, void *val, char *in)
{
    double v3;
    __int16 v4;

    v3 = atof(in);
    //XXX
    //val = (signed __int64)floor(v4, v3 * 32768.0 / 180.0 + 0.5);
    *((signed __int64 *)val) = (signed __int64)floor(v3 * 32768.0 / 180.0 + 0.5);
}


void unparse_ang(sFieldDesc *desc, void *val, char *out)
{
    sprintf(out, "%0.2f", (double)*(WORD *)val * 180.0 / 32768.0);
}


void parse_ang_vec(sFieldDesc *desc, void *val, char *in)
{
    __int16 v3;
    __int16 v4;
    signed __int64 v5;
    __int16 v6;
    float bank;
    float pitch;
    void *vec;
    float heading;

    vec = val;
    sscanf(in, "%lf, %lf %lf", &heading, &pitch, &bank);
    *((WORD *)vec + 2) = (signed __int64)floor(heading * 32768.0 / 180.0 + 0.5);
    v5 = (signed __int64)floor(pitch * 32768.0 / 180.0 + 0.5);
    v6 = (signed __int16)vec;
    *((WORD *)vec + 1) = v5;
    *(WORD *)vec = (signed __int64)floor(bank * 32768.0 / 180.0 + 0.5);
}

//----- (008CF124) --------------------------------------------------------
void unparse_ang_vec(sFieldDesc *desc, void *val, char *out)
{
    sprintf(out, "%0.2lf, %0.2lf, %0.2lf",
        (double)*((WORD *)val + 2) * 180.0 / 32768.0,
        (double)*((WORD *)val + 1) * 180.0 / 32768.0,
        (double)*(WORD *)val * 180.0 / 32768.0);
}



void parse_float(sFieldDesc *desc, void *val, char *in)
{
    sscanf(in, "%f", val);
}

void unparse_float(sFieldDesc *desc, void *val, char *out)
{
    sprintf(out, "%0.2f", *(float *)val);
}

void parse_fix(sFieldDesc *desc, void *val, char *in)
{
    float v3;
    float num;

    num = v3;
    sscanf(in, "%f", &num);
    *(DWORD *)val = (signed __int64)(num * 65536.0);
}

void unparse_fix(sFieldDesc *desc, void *val, char *out)
{
    sprintf(out, "%0.2f", (double)*(signed int *)val / 65536.0);
}



void parse_fixvec(sFieldDesc *desc, void *val, char *in)
{
    float vec[3];

    sscanf(in, "%f %f %f", vec, &vec[1], &vec[2]);
    *(DWORD *)val = (signed __int64)(vec[0] * 65536.0);
    *((DWORD *)val + 1) = (signed __int64)(vec[1] * 65536.0);
    *((DWORD *)val + 2) = (signed __int64)(vec[2] * 65536.0);
}

void unparse_fixvec(sFieldDesc *desc, void *val, char *out)
{
    sprintf(out, "%0.2f %0.2f %0.2f",
        (double)*(signed int *)val / 65536.0,
        (double)*((signed int *)val + 1) / 65536.0,
        (double)*((signed int *)val + 2) / 65536.0);
}

void parse_double(sFieldDesc *desc, void *val, char *in)
{
    sscanf(in, "%lf", val);
}

void unparse_double(sFieldDesc *desc, void *val, char *out)
{
    sprintf(out, "%0.8lf", *(DWORD *)val, *((DWORD *)val + 1));
}


int StructFieldToString(const void *struc, sStructDesc *desc, sFieldDesc *field, char *dest)
{
    int result;

    if(field && desc && struc && dest)
    {
        unparse_funcs[field->type](field, (char *)struc + field->offset, dest);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

int StructStringToField(void *struc, sStructDesc *desc, sFieldDesc *field, char *src)
{
    int result;

    if(field && desc && struc && src)
    {
        parse_funcs[field->type](field, (char *)struc + field->offset, src);
        result = 1;
    }
    else
    {
        result = 0;
    }
    return result;
}

int StructSetField(void *struc, sStructDesc *desc, sFieldDesc *field, const void *val)
{
    int result;

    if(desc && struc && val && field)
    {
        set_field(struc, (void *)val, field);
        result = 1;
    }
    else
    {
#ifdef DBG_ON
        DbgReportWarning("StructSetField: Failed because of NULL pointer parameter\n");
#else
        Warning("StructSetField: Failed because of NULL pointer parameter\n")
#endif
        result = 0;
    }
    return result;
}


void set_field(void *struc, void *newdata, sFieldDesc *desc)
{
    memcpy((char *)struc + desc->offset, newdata, desc->size);
}

int StructGetField(const void *struc, sStructDesc *desc, sFieldDesc *field, void *val)
{
    int result;

    if(desc && struc && val && field)
    {
        get_field(struc, val, field);
        result = 1;
    }
    else
    {
#ifdef DBG_ON
        DbgReportWarning("StructGetField: Failed because of NULL pointer parameter\n");
#else
        Warning("StructGetField: Failed because of NULL pointer parameter\n")
#endif
        result = 0;
    }
    return result;
}

void get_field(const void *struc, void *newdata, sFieldDesc *desc)
{
    memcpy(newdata, (char *)struc + desc->offset, desc->size);
}

void __cdecl StructDumpStruct(const void *struc, sStructDesc *desc)
{
    int i;
    char str[256];

    if(desc && struc)
    {
        mprintf("Struct %s, size %d, flags %x, nfields %d\n");
        for(i = 0; i < desc->nfields; ++i)
        {
            StructFieldToString(struc, desc, &desc->fields[i], str);
            mprintf("  ->%s (type %s, size %d) = %s\n");
        }
    }
}


int StructDescIsSimple(sStructDesc *desc)
{
    return desc->nfields <= 1;
}

int __cdecl StructToSimpleString(const void *struc, sStructDesc *desc, char *out)
{
    int result;
    int v4;

    v4 = desc->nfields;
    if(v4)
    {
        if(v4 == 1)
        {
            unparse_funcs[desc->fields->type](desc->fields, (char *)struc + desc->fields->offset, out);
            result = 1;
        }
        else
        {
            strcpy(out, "...");
            result = 0;
        }
    }
    else
    {
        strcpy(out, "-");
        result = 1;
    }
    return result;
}


int StructFromSimpleString(const void *struc, sStructDesc *desc, char *in)
{
    int result;
    int v4;

    v4 = desc->nfields;
    if(v4)
    {
        if(v4 == 1)
        {
            parse_funcs[desc->fields->type](desc->fields, (char *)struc + desc->fields->offset, in);
            result = 1;
        }
        else
        {
            result = 0;
        }
    }
    else
    {
        result = 1;
    }
    return result;
}

int StructToFullString(const void *struc, sStructDesc *desc, char *out, int len)
{
    size_t v4;
    char *v5;
    size_t v6;
    signed int bufsiz;
    int i;
    void *buf;
    signed int too_long;
    char *p;

    too_long = 0;
    if(desc->nfields)
    {
        bufsiz = 256;
        buf = MallocSpew(0x100u, "x:\\prj\\tech\\libsrc\\sdesc\\sdesc.cpp", 717);
        p = out;
        if(desc->nfields > 1)
        {
            strcpy(out, "{ ");
            p = &out[strlen(out)];
        }
        for(i = 0; i < desc->nfields; ++i)
        {
            if(desc->fields[i].size > bufsiz)
            {
                while(bufsiz < desc->fields[i].size)
                    bufsiz *= 2;
                buf = ReallocSpew(buf, bufsiz, "x:\\prj\\tech\\libsrc\\sdesc\\sdesc.cpp", 735);
            }
            if(i)
            {
                if(&p[strlen(delim) + 1] > &out[len])
                {
                    too_long = 1;
                    break;
                }
                strcpy(p, delim);
                p += strlen(delim);
            }
            unparse_funcs[desc->fields[i].type](&desc->fields[i], (char *)struc + desc->fields[i].offset, (char *)buf);
            strncpy(p, (const char *)buf, &out[len] - p);
            if(&p[strlen((const char *)buf) + 1] > &out[len])
            {
                too_long = 1;
                break;
            }
            p += strlen((const char *)buf);
        }
        FreeSpew(buf, "x:\\prj\\tech\\libsrc\\sdesc\\sdesc.cpp", 766);
        if(desc->nfields > 1 && !too_long)
        {
            if(p + 2 <= &out[len])
                strcat(out, "}");
            else
                too_long = 1;
        }
        if(too_long)
        {
            v4 = strlen(elipsis) + 1;
            v5 = elipsis;
            v6 = strlen(elipsis);
            strncpy(&out[len - 1] - v6, v5, v4);
        }
    }
    else
    {
        strncpy(out, "-", len);
    }
    return 1;
}


int StructFromFullString(const void *struc, sStructDesc *desc, const char *in)
{
    unsigned int v3;
    char v4;
    int i;
    char *p;
    int *pa;

    if(desc->nfields == 1)
    {
        parse_funcs[desc->fields->type](desc->fields, (char *)struc + desc->fields->offset, (char *)in);
    }
    else
    {
        if(desc->nfields > 1)
        {
            i = 0;
            p = strchr(in, 123);
            while(p && i < desc->nfields)
            {
                for(pa = (int *)(p + 1); isspace(*(BYTE *)pa); pa = (int *)((char *)pa + 1))
                {
                    ;
                }
                    
                v3 = (unsigned int)((char *)pa + strcspn((const char *)pa, ";}"));
                v4 = *(BYTE *)v3;
                *(BYTE *)v3 = 0;
                parse_funcs[desc->fields[i].type](&desc->fields[i], (char *)struc + desc->fields[i].offset, (char *)pa);
                *(BYTE *)v3 = v4;
                p = (char *)v3;
                ++i;
            }
        }
    }
    return 1;
}

