HPy supports creating extension functions with 4 types of interfaces:

```c
HPyDef_METH(f, "f", HPyFunc_NOARGS)
            static HPy f_impl(HPyContext *ctx, HPy self)

HPyDef_METH(g, "g", HPyFunc_O)
            static HPy g_impl(HPyContext *ctx, HPy self, HPy arg)

HPyDef_METH(h, "h", HPyFunc_VARARGS)
            static HPy h_impl(HPyContext *ctx, HPy self, const HPy *args, size_t nargs)

HPyDef_METH(i, "i", HPyFunc_KEYWORDS)
            static HPy i_impl(HPyContext *ctx, HPy self, const HPy *args, size_t nargs, HPy kwnames)
```

Both positional and keyword arguments are passed as C array `args`. Argument `nargs` specifies the number of positional arguments. Argument `kwnames` is a tuple containing the names of the keyword arguments. The keyword argument values are appended to positional arguments and start at `args[nargs]` (if there are any).

## Using bools

In Python, booleans can have the value True or False, however also other
types can be used where booleans would be expected. These are known as
truthy values.

As a result in HPy, to do boolean comparison we use `HPy_IsTrue(ctx,h)` to
check if `h` evaluates True or False. The function returns an int 0 for false and 1 for true,
