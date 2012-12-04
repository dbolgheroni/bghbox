"""Test Class"""

class Test:
    def __init__(self):
        self.__var = 42
        self.__squab = 0

    @property
    def var(self):
        return self.__var * 2

    @var.setter
    def var(self, v):
        self.__var = v * 3

    @property
    def squab(self):
        return self.__squab

    @squab.setter
    def squab(self, v):
        self.__squab = v + 1
