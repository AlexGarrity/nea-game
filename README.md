# Computer Science A-Level Project
This is my Computer Science A-Level project, for which I decided on the task of creating an MMORPG engine and basic gameplay demo.
It's safe to say that when you've only just started using C++ properly, this is not a wise idea.

The project itself is less than ideal, with a lot of statics and other terrible design choices.
Regardless, this was my first ever assessment written in C++ and it taught me to manage expectations.

The project itself was originally written using Code::Blocks, which is why you can see some `cbp` files if you explore the
commit history.  This has been removed the sake of archiving, and reworked to use CMake.  
It is important to note that I *did not* understand CMake when I had just started using C++.

I've left the previous README description for posterity.

<br>

# MMORPG

Computing A-Level project.
I may be a little bit in way over my head here.
*Everything is fine...*

Using C++11, LLVM compiler.  The '-pthread' linker option will likely be required.
Requires SFML 2.4.x to build.

Only tried building on Linux so far, but Windows should work just as well.