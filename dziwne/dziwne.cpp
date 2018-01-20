#include <ruby.h>
#include <stdio.h>

typedef VALUE (ruby_method)(...);

struct moje
{
 char x;
};

void t_free(struct moje *m)
{
 free(m);
}

static VALUE t_allocate(VALUE obj)
{
struct moje *m = (struct moje*)malloc(sizeof(struct moje));
 if( m == NULL )
   rb_raise(rb_eNoMemError, "Brakuje pamięci (%ld bajty)", sizeof(struct moje));

 m->x = 42;

return Data_Wrap_Struct(obj,NULL,t_free,m);
}

extern "C" VALUE t_cosik()
{
 VALUE str = rb_str_new2( "Dziwne" );
/* VALUE str = rb_str_new2( "Żółty" );
what I can return "żółte" string */

return str;
}

/* How check the type of 'i' is "Dziwne" or not */
extern "C" VALUE t_ustaw(VALUE obj, VALUE i)
{
struct moje *m;

 switch (TYPE(i))
  {
  case T_FIXNUM: /* set variable and return it */
   Data_Get_Struct(obj, struct moje, m);
   m->x = (int)NUM2INT(i);
   return INT2NUM(m->x);
   break;
  case T_NIL: /* only return x */
   Data_Get_Struct(obj, struct moje, m);
   return INT2NUM(m->x);
   break;
  /* case T_DZIWNE:
   Data_Get_Struct(obj, struct moje, m);
   VALUE a = rb_ary_new();
   return rb_ary_push(a, <new empty object class "Dziwne"> );
   break; */
  default:
   rb_raise(rb_eStandardError, "Nie działa");
   break;
  }

return Qnil;
}


VALUE cDziwne;

extern "C"
{
	VALUE dziwne_new()
	{
	VALUE aaa;
		return t_allocate(aaa);
	}

	VALUE dziwne_test()
	{
		VALUE obj = dziwne_new();
		t_ustaw(obj, LONG2FIX(1));
		return obj;
	}
}

extern "C" void Init_Dziwne()
{
 cDziwne = rb_define_class("Dziwne", rb_cObject);
 rb_define_alloc_func(cDziwne,t_allocate);
/* rb_define_method(cDziwne, "żółte", (ruby_method*) &t_cosik, 0); */
 rb_define_method(cDziwne, "cosik", (ruby_method*) &t_cosik, 0);
 rb_define_method(cDziwne, "ustaw", (ruby_method*) &t_ustaw, 1);
 rb_define_method(cDziwne, "test", (ruby_method*)&dziwne_test, 0);
}
