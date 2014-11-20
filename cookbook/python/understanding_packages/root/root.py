#!/usr/local/bin/python3.4

# Python radically changed 

# From https://docs.python.org/3/reference/import.html:
# Changed in version 3.3: The import system has been updated to fully
# implement the second phase of PEP 302. There is no longer any implicit
# import machinery - the full import system is exposed through
# sys.meta_path. In addition, native namespace package support has been
# implemented (see PEP 420).

# From https://docs.python.org/3/tutorial/modules.html#packages:
# Note that when using from package import item, the item can be either
# a submodule (or subpackage) of the package, or some other name defined
# in the package, like a function, class or variable. The import
# statement first tests whether the item is defined in the package; if
# not, it assumes it is a module and attempts to load it. If it fails to
# find it, an ImportError exception is raised.
#
# Contrarily, when using syntax like import item.subitem.subsubitem,
# each item except for the last must be a package; the last item can be
# a module or a package but can’t be a class or function or variable
# defined in the previous item.
#
# Note that relative imports are based on the name of the current
# module. Since the name of the main module is always "__main__",
# modules intended for use as the main module of a Python application
# must always use absolute imports.

# from <module, package> import <something inside or a module>
# import <module, package>
from module1 import func1
from dir2.module2 import func2
from package3 import str33
from package3.file33 import str333
import package3.package33

func1()
func2()
print(str33)
print(str333)
