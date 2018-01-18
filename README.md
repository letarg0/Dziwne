1. How create rb_dziwne_new() function to create object "dziwne"

for example:

{

VALUE a = rb_ary_new();

 rb_ary_push(a, _<new empty object class "Dziwne">_ );

 return a
 
}

return array with 'Dziwne' object

_[ #<Dziwne:0x000056344f52a428> ]_


2. How check type of my object inside my object.

VALUE t_foo(VALUE obj, VALUE i)

{

 Check_Type(i, _<type of my class "dziwne">_); or similar function


3. How create a function with utf8 name?

void Init_Dziwne()

{

[...]

 rb_define_method(cDziwne, "żółte", (ruby_method*) &t_zolte, 0);


4. How defining utf8 string form C extension

 str = rb_str_new ? ( "żółte" );


5. How using find_library in extconf.rb

unless find_library('for example png', '?what I can put here')
  abort "Biblioteka jest konieczna"
end

I need check the library in many system. Search in many places.
/include and /lib
