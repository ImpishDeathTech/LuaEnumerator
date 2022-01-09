# LuaEnumerator
### A (kind of) efficient enumeration facility for lua 5.4 written in C++
I didn't need to write this in C++, but it was nice practice, and it really works nicely

Can enumerate from one or any other integer, depending on how you call `enum.erate()`, and will always enumerate from 1 if no value is given

```lua
enum = require('enum')

e = enum.erate('A','B','C','D')     -- outputs: { A = 1, B = 2, C = 3, D = 4, COUNT = 4 }
e = enum.erate('A','B','C','D', 0)  -- outputs: { A = 0, B = 1, C = 2, D = 3, COUNT = 4 }
e = enum.erate('A','B','C','D', -3) -- outputs: { A = -3, B = -2, C = -1, D = 0, COUNT = 4 }
e = enum.erate('A','B','C','D', 8)  -- outputs: { A = 8, B = 9, C = 10, D = 11, COUNT = 4 }
```
There are two more enumeration functions that can be used, though one's starting point is constant while the other is the oppesite. One starts at 0 and enumerate's negatively, aptly named `enum.neg()`, and the the other enumerates in reverse down to one from however many values you decide to put in, called `enum.rev()`. I'm unsure of a limit yet, at this point. Their useage is as follows:

```lua
enum = require "enum"
e = enum.rev('A','B','C','D') -- outputs: { A = 4, B = 3, C = 2, D = 1, COUNT = 4 }
e = enum.neg('A','B','C','D') -- outputs: { A = 0, B = -1, C = -2, D = -3, COUNT = 4 }
```

It's a simple single c++ file, so with any C compiler, turn that into a .dll/.so:

`c++ enum.cxx -c -llua -fPIC && c++ enum.o -shared -o enum.so`
