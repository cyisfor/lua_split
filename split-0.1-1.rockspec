package="split"
version="0.1-1"
source = {
   url = "git://github.com/cyisfor/lua_split.git",
   dir='lua_split'
}
description = {
   summary = "Gimme a dang string.split already",
   detailed = [[
       What it says on the cover.
   ]],
   homepage = "http://github.com/cyisfor/lua_split/",
   license = "lol"
}
dependencies = {
   "lua >= 5.1"
}

build = {
   type="builtin",
   modules = {
       split = {
           sources = {
               "split.c"
           },
       }
   }
}
