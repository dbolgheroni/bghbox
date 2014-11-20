def func1():
    print("func1() call")

    def func11():
        print("func11() call")

    # only visible inside func1()
    func11()
